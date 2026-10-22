#!/usr/bin/env node
'use strict';

// Read-only analysis of CIFF data using the existing workspace cipher.
// Re-encryption is a reversibility check, not an independent native oracle.
const fs = require('node:fs');
const path = require('node:path');
const crypto = require('node:crypto');
const vm = require('node:vm');

const PROJECT_ROOT = path.resolve(__dirname, '..');
const ENCRYPTION_PATH = path.join(PROJECT_ROOT, 'public/modules/clst/encryption.js');
const COMPATIBILITY_PATH = path.join(PROJECT_ROOT, 'public/modules/01-ciff-compatibility.js');
const ALPHABET = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!_';
const FINAL_KEY = 'TpyRcNeyeK';
const TAG_DATA_KEY = 'TagData';
const ENCRYPTION_SOURCE = fs.readFileSync(ENCRYPTION_PATH, 'utf8');
const cipherContext = vm.createContext({});
vm.runInContext(ENCRYPTION_SOURCE, cipherContext, { filename: ENCRYPTION_PATH, timeout: 1000 });
const CEncryption = vm.runInContext('CEncryption', cipherContext);

function sha256(value) {
  return crypto.createHash('sha256').update(value).digest('hex');
}

function decryptClStText(encoded, key) {
  if (encoded.length % 3 !== 0) throw new Error('Encoded length must be divisible by 3.');
  const cipher = new CEncryption(key);
  let result = '';
  for (let offset = 0; offset < encoded.length; offset += 3) {
    const a = ALPHABET.indexOf(encoded[offset]);
    const b = ALPHABET.indexOf(encoded[offset + 1]);
    const c = ALPHABET.indexOf(encoded[offset + 2]);
    if (a < 0 || a > 31 || b < 0 || c < 0 || c > 31) {
      throw new Error(`Invalid encoded UTF-16 triple at offset ${offset}.`);
    }
    const encodedWord = (a << 11) | (b << 5) | c;
    const plainWord = (encodedWord ^ cipher.currentState) & 0xffff;
    result += String.fromCharCode(plainWord);
    cipher.updateState(plainWord);
  }
  return result;
}

function decodeEntities(text) {
  return text.replace(/&(?:#x([0-9a-f]+)|#([0-9]+)|(amp|lt|gt|quot|apos));/gi, (entity, hex, dec, named) => {
    if (hex || dec) return String.fromCodePoint(parseInt(hex || dec, hex ? 16 : 10));
    return { amp: '&', lt: '<', gt: '>', quot: '"', apos: "'" }[named.toLowerCase()];
  });
}

// A small balanced-element scanner, sufficient for CIFF without a DTD.
// It respects quoted attributes, CDATA and comments; it does not resolve entities.
function scanXmlElements(xml) {
  if (/<!DOCTYPE\b/i.test(xml)) throw new Error('DTD-bearing XML is not supported by this inspector.');
  const stack = [];
  const roots = [];
  const lexemes = /<!\[CDATA\[[\s\S]*?\]\]>|<!--[\s\S]*?-->|<\?[\s\S]*?\?>|<(?:[^>"']|"[^"]*"|'[^']*')*>/g;
  for (const match of xml.matchAll(lexemes)) {
    const token = match[0];
    if (/^<(?:!|\?)/.test(token)) continue;
    const closing = /^<\/\s*([^\s>]+)\s*>$/.exec(token);
    if (closing) {
      const node = stack.pop();
      if (!node || node.name !== closing[1]) throw new Error(`Unbalanced XML at ${closing[1]}.`);
      node.closeStart = match.index;
      node.end = match.index + token.length;
      continue;
    }
    const opening = /^<\s*([^\s/>]+)/.exec(token);
    if (!opening) throw new Error('Unsupported XML lexeme.');
    const node = {
      name: opening[1], start: match.index, openEnd: match.index + token.length,
      closeStart: match.index + token.length, end: match.index + token.length,
      openingTag: token, children: [],
    };
    const parent = stack[stack.length - 1];
    (parent ? parent.children : roots).push(node);
    if (!/\/\s*>$/.test(token)) stack.push(node);
  }
  if (stack.length) throw new Error('XML has unclosed elements.');
  return roots;
}

function readXmlText(xml, node) {
  if (!node) return null;
  if (node.children.length) throw new Error(`Nested markup in ${node.name} is not plain text.`);
  const inner = xml.slice(node.openEnd, node.closeStart);
  const chunks = inner.split(/(<!\[CDATA\[[\s\S]*?\]\]>|<!--[\s\S]*?-->)/g);
  return chunks.map((chunk) => {
    if (chunk.startsWith('<![CDATA[')) return chunk.slice(9, -3);
    if (chunk.startsWith('<!--')) return '';
    if (chunk.includes('<')) throw new Error(`Unsupported markup in ${node.name}.`);
    return decodeEntities(chunk);
  }).join('');
}

function getAttribute(openingTag, name) {
  const match = new RegExp(`\\s${name}\\s*=\\s*(["'])([\\s\\S]*?)\\1`).exec(openingTag);
  return match ? decodeEntities(match[2]) : null;
}

function collectSourceEvidence(xml) {
  const roots = scanXmlElements(xml);
  const root = roots.find((node) => node.name === 'ImageDesign');
  if (!root) throw new Error('ImageDesign root is missing.');
  const headers = root.children.filter((node) => node.name === 'Header');
  if (headers.length !== 1) throw new Error('Expected one direct ImageDesign/Header.');
  const header = headers[0];
  const tokenNodes = header.children.filter((node) => node.name === 'ClStVersionInfo');
  if (tokenNodes.length > 1) throw new Error('Duplicate direct Header/ClStVersionInfo.');
  const subImages = root.children.filter((node) => node.name === 'SubImage');
  const fields = subImages.flatMap((node) => node.children.filter((child) => child.name === 'Field'));
  const fieldSnapshots = fields.map((field, index) => ({
    index,
    name: getAttribute(field.openingTag, 'Name'),
    fieldType: readXmlText(xml, field.children.find((child) => child.name === 'FldType')),
    calcData: readXmlText(xml, field.children.find((child) => child.name === 'CalcData')),
  }));
  const counts = {
    dateOffsetCount: header.children.filter((node) => node.name === 'DateOffset').length,
    subImageCount: subImages.length,
    fieldCount: fields.length,
  };
  const structureKey = Object.values(counts).map((count) => String(Math.min(count, 99)).padStart(2, '0')).join('');
  return {
    token: readXmlText(xml, tokenNodes[0]),
    designedFor: getAttribute(header.openingTag, 'DesignedFor'),
    counts,
    structureKey,
    fieldSnapshots,
  };
}

function inspectCoreLayout(core, evidence) {
  const result = { consistent: false, headerEncoded: core.slice(0, 24) };
  try {
    if (core.length < 24) throw new Error('Core is shorter than the 24-character mask block.');
    result.maskHex = decryptClStText(result.headerEncoded, evidence.structureKey);
    if (!/^[0-9A-F]{8}$/.test(result.maskHex)) throw new Error('Mask is not 8 uppercase hexadecimal characters.');
    result.mask = parseInt(result.maskHex, 16) >>> 0;
    result.tagDataEncoded = core.slice(24);
    if (result.tagDataEncoded.length > 60) throw new Error('Selected-data block exceeds 20 UTF-16 code units.');
    result.tagData = decryptClStText(result.tagDataEncoded, TAG_DATA_KEY);
    result.selectedFieldIndices = Array.from({ length: 32 }, (_, index) => index)
      .filter((index) => ((result.mask >>> index) & 1) !== 0);
    result.selectedFieldSnapshots = result.selectedFieldIndices.map((index) => (
      evidence.fieldSnapshots[index] || { index, missing: true }
    ));
    const snapshots = result.selectedFieldSnapshots;
    const available = snapshots.every((field) => !field.missing && field.calcData != null);
    result.selectedCalcDataPrefix = available ? snapshots.map((field) => field.calcData).join('').slice(0, 20) : null;
    result.matchesSelectedCalcData = available ? result.selectedCalcDataPrefix === result.tagData : null;
    result.consistent = true;
  } catch (error) {
    result.reason = error.message;
  }
  return result;
}

function inspectOptionalLayout(outerDecoded, evidence) {
  const result = {
    plausible: false,
    fileDecodeKeyAssumption: 'TagData; matches the selected-data transform slot in the supplied pseudocode.',
  };
  try {
    if (outerDecoded.length < 48) throw new Error('Optional layout needs a length block plus a core mask block.');
    result.lengthHeaderEncoded = outerDecoded.slice(0, 24);
    result.fileLengthHex = decryptClStText(result.lengthHeaderEncoded, evidence.structureKey);
    if (!/^[0-9a-f]{8}$/.test(result.fileLengthHex)) throw new Error('Length is not 8 lowercase hexadecimal characters.');
    result.fileBlockEncodedLength = parseInt(result.fileLengthHex, 16);
    if (result.fileBlockEncodedLength % 3 !== 0) throw new Error('File block length is not divisible by 3.');
    const coreStart = 24 + result.fileBlockEncodedLength;
    if (coreStart + 24 > outerDecoded.length) throw new Error('File block length exceeds the available outer data.');
    result.fileBlockEncoded = outerDecoded.slice(24, coreStart);
    result.fileDataWithAssumedKey = decryptClStText(result.fileBlockEncoded, TAG_DATA_KEY);
    result.core = inspectCoreLayout(outerDecoded.slice(coreStart), evidence);
    if (!result.core.consistent) throw new Error(`Optional core: ${result.core.reason}`);
    result.plausible = true;
  } catch (error) {
    result.reason = error.message;
  }
  return result;
}

function readCiffXml(bytes) {
  if (bytes[0] === 0xff && bytes[1] === 0xfe) return { encoding: 'UTF-16LE BOM', xml: bytes.subarray(2).toString('utf16le') };
  if (bytes[0] === 0xfe && bytes[1] === 0xff) {
    if ((bytes.length - 2) % 2) throw new Error('Odd UTF-16BE byte length.');
    const swapped = Buffer.from(bytes.subarray(2));
    swapped.swap16();
    return { encoding: 'UTF-16BE BOM', xml: swapped.toString('utf16le') };
  }
  if (bytes[0] === 0x3c && bytes[1] === 0) return { encoding: 'UTF-16LE without BOM', xml: bytes.toString('utf16le') };
  return { encoding: 'UTF-8', xml: bytes.toString('utf8').replace(/^\uFEFF/, '') };
}

function inspectFile(filename, constantToken) {
  const bytes = fs.readFileSync(filename);
  const item = { file: path.relative(PROJECT_ROOT, filename).replace(/\\/g, '/'), sha256: sha256(bytes) };
  try {
    const { encoding, xml } = readCiffXml(bytes);
    item.encoding = encoding;
    const evidence = collectSourceEvidence(xml);
    item.sourceEvidence = { designedFor: evidence.designedFor, counts: evidence.counts, structureKey: evidence.structureKey };
    if (evidence.token == null) {
      item.status = 'missing-token';
      return item;
    }
    item.token = evidence.token;
    item.tokenLength = evidence.token.length;
    item.tokenSha256Utf16LE = sha256(Buffer.from(evidence.token, 'utf16le'));
    item.matchesEmptyTemplateConstant = evidence.token === constantToken;
    item.outerDecoded = decryptClStText(evidence.token, FINAL_KEY);
    item.outerDecodedLength = item.outerDecoded.length;
    item.outerContainsOnlyEncodedAlphabet = /^[0-9A-Za-z!_]*$/.test(item.outerDecoded);
    item.reencryptExact = new CEncryption(FINAL_KEY).encrypt(item.outerDecoded) === evidence.token;
    item.mainLayout = inspectCoreLayout(item.outerDecoded, evidence);
    item.optionalLayout = inspectOptionalLayout(item.outerDecoded, evidence);
    item.branchAssessment = item.mainLayout.consistent
      ? (item.optionalLayout.plausible ? 'ambiguous-main-or-optional' : 'consistent-with-main-layout')
      : (item.optionalLayout.plausible ? 'plausible-optional-layout' : 'unrecognized-layout');
    item.status = 'decoded-with-workspace-cipher';
  } catch (error) {
    item.status = 'error';
    item.error = error.message;
  }
  return item;
}

function collectInputs(inputs) {
  const files = [];
  function visit(filename) {
    const stat = fs.statSync(filename);
    if (stat.isDirectory()) {
      for (const entry of fs.readdirSync(filename).sort()) visit(path.join(filename, entry));
    } else if (/\.(?:ciff|xml)$/i.test(filename)) files.push(path.resolve(filename));
  }
  for (const input of inputs) visit(path.resolve(input));
  return [...new Set(files)].sort();
}

function buildReport(inputs) {
  const compatibilitySource = fs.readFileSync(COMPATIBILITY_PATH, 'utf8');
  const constantMatch = /const CLST_6330_53_CONTINUOUS\s*=\s*"([^"]*)"/.exec(compatibilitySource);
  const constantToken = constantMatch?.[1] || null;
  const files = collectInputs(inputs).map((filename) => inspectFile(filename, constantToken));
  return {
    schemaVersion: 1,
    provenance: {
      cipherSource: path.relative(PROJECT_ROOT, ENCRYPTION_PATH).replace(/\\/g, '/'),
      cipherSourceSha256Utf8: sha256(ENCRYPTION_SOURCE),
      cipherParameters: { seed: '0x26E20115', useKeyInputs: false, finalKey: FINAL_KEY, tagDataKey: TAG_DATA_KEY },
      validationScope: 'Workspace implementation plus independent stored XML payload observations; no native DLL execution is performed.',
      limitations: [
        'Decrypt then re-encrypt is a reversibility check and does not independently prove equivalence with ClariSoft.',
        'A layout match is a structural interpretation; optional branches are tested as candidates rather than assumed absent.',
        'CalcData comparison uses the stored XML value. Date/time/counter values can differ from their native runtime values.',
        'This false-key-input path depends on key length, not key contents; decoded masks cannot validate the DDSSFF counter values.',
        'A token matching the constant named EMPTY_TEMPLATE_CLST_VERSION_INFO does not prove that it came from an empty template.',
      ],
    },
    summary: {
      files: files.length,
      decoded: files.filter((item) => item.status === 'decoded-with-workspace-cipher').length,
      mainLayoutConsistent: files.filter((item) => item.mainLayout?.consistent).length,
      optionalLayoutPlausible: files.filter((item) => item.optionalLayout?.plausible).length,
      selectedStoredCalcDataMatches: files.filter((item) => item.mainLayout?.matchesSelectedCalcData === true).length,
      selectedStoredCalcDataMismatches: files.filter((item) => item.mainLayout?.matchesSelectedCalcData === false).length,
      missingTokens: files.filter((item) => item.status === 'missing-token').length,
      errors: files.filter((item) => item.status === 'error').length,
    },
    emptyTemplateConstantEvidence: files.filter((item) => item.matchesEmptyTemplateConstant).map((item) => ({
      file: item.file,
      sourceFieldCount: item.sourceEvidence.counts.fieldCount,
      maskHex: item.mainLayout?.maskHex,
      tagData: item.mainLayout?.tagData,
      matchesSelectedStoredCalcData: item.mainLayout?.matchesSelectedCalcData,
      conclusion: item.mainLayout?.mask !== 0 || item.mainLayout?.tagData?.length
        ? 'The decoded constant carries a nonzero selection mask or selected payload; its name does not establish an empty-template branch.'
        : 'No nonempty-selection conclusion can be drawn from this candidate.',
    })),
    files,
  };
}

function main(args) {
  const json = args.includes('--json');
  const inputs = args.filter((arg) => arg !== '--json');
  if (!inputs.length || inputs.includes('--help')) {
    process.stdout.write('Usage: node scripts/inspect-clst.cjs [--json] <CIFF/XML file or directory> [...paths]\n');
    return;
  }
  const report = buildReport(inputs);
  if (json) {
    process.stdout.write(`${JSON.stringify(report, null, 2)}\n`);
  } else {
    process.stdout.write('Decoded using the workspace cipher. Re-encryption checks reversibility, not native equivalence.\n');
    for (const item of report.files) {
      process.stdout.write(`\n${item.file}: ${item.status}\n`);
      if (!item.outerDecoded) {
        if (item.error) process.stdout.write(`  ${item.error}\n`);
        continue;
      }
      process.stdout.write(`  outer ${item.tokenLength} -> ${item.outerDecodedLength}: ${JSON.stringify(item.outerDecoded)}\n`);
      process.stdout.write(`  header[24]: ${JSON.stringify(item.mainLayout.headerEncoded)}\n`);
      process.stdout.write(`  mask: ${JSON.stringify(item.mainLayout.maskHex)}; TagData: ${JSON.stringify(item.mainLayout.tagData)}\n`);
      process.stdout.write(`  selected CalcData match: ${item.mainLayout.matchesSelectedCalcData}; ${item.branchAssessment}\n`);
      process.stdout.write(`  optional: ${item.optionalLayout.plausible ? 'plausible' : item.optionalLayout.reason}\n`);
    }
    process.stdout.write(`\n${JSON.stringify(report.summary)}\n`);
  }
  if (report.summary.errors) process.exitCode = 1;
}

if (require.main === module) main(process.argv.slice(2));
module.exports = { decryptClStText, collectSourceEvidence, inspectCoreLayout, inspectOptionalLayout, buildReport };

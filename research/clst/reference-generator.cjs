#!/usr/bin/env node
'use strict';

// A research reference for the recovered CiffMgr.dll pipeline.
// Inputs are actual COM TagData strings in SubImage/Field collection order.
// This deliberately does not guess TagData from arbitrary CIFF field types.
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const encryptionPath = path.resolve(__dirname, '../../public/modules/clst/encryption.js');
const context = vm.createContext({});
vm.runInContext(fs.readFileSync(encryptionPath, 'utf8'), context, { filename: encryptionPath });
const CEncryption = vm.runInContext('CEncryption', context);

function encrypt(text, key) {
  // Native 68117DE2 uses a NUL-terminated key and copies at most 14 WCHARs.
  const nativeKey = String(key).split('\0', 1)[0].slice(0, 14);
  return new CEncryption(nativeKey, 0x26E20115, false).encrypt(String(text));
}

function checkedCount(value, name) {
  if (!Number.isSafeInteger(value) || value < 0) throw new Error(`${name} must be a nonnegative integer.`);
  return value;
}

function structureKey(dateOffsetCount, subImageCount, fieldCount) {
  return [dateOffsetCount, subImageCount, fieldCount]
    .map((value) => String(Math.min(value, 99)).padStart(2, '0')).join('');
}

// Native 68118E73 reseeds MSVCRT rand() on EVERY call using GetTickCount().
// This PRNG differs from the Boolean network's 0x41C64E6D/0x3039 generator.
function randomIndexFromTick(tick, maxExclusive) {
  if (!Number.isInteger(maxExclusive) || maxExclusive <= 0) throw new Error('Random bound must be positive.');
  const state = (Math.imul(Number(tick) >>> 0, 0x343FD) + 0x269EC3) >>> 0;
  return ((state >>> 16) & 0x7FFF) % maxExclusive;
}

function createSelectionMask(fieldCount, nextMod) {
  if (fieldCount === 0) return { mask: 0, attempts: 0 };
  if (typeof nextMod !== 'function') throw new Error('Provide a mask, tickCounts, or nextMod for a nonempty template.');
  const draw = (bound) => {
    const result = nextMod(bound);
    if (!Number.isInteger(result) || result < 0 || result >= bound) throw new Error('nextMod returned an invalid index.');
    return result;
  };
  const attempts = 1 + draw(Math.min(fieldCount, 3));
  let mask = 0;
  for (let i = 0; i < attempts; i += 1) mask = (mask | (1 << draw(Math.min(fieldCount, 32)))) >>> 0;
  return { mask, attempts };
}

function collectTagData(fieldValues, mask) {
  let result = '';
  for (let index = 0; index < Math.min(fieldValues.length, 32); index += 1) {
    if (((mask >>> index) & 1) === 0) continue;
    if (typeof fieldValues[index] !== 'string') throw new Error(`Selected Field ${index} requires its actual TagData string.`);
    result += fieldValues[index];
  }
  return result.slice(0, 20);
}

function metadataName(sourcePath) {
  // _wsplitpath_s drops drive/directory and separates at the last dot.
  let source = String(sourcePath).split('\0', 1)[0];
  if (source[1] === ':') source = source.slice(2);
  const leaf = source.split(/[\\/]/).pop();
  const split = (value) => {
    const dot = value.lastIndexOf('.');
    const parts = dot < 0 ? [value, ''] : [value.slice(0, dot), value.slice(dot)];
    if (parts.some((part) => part.length > 255)) {
      throw new Error('Name exceeds the native _wsplitpath_s buffer; its failure path is not reproduced.');
    }
    return parts;
  };
  let [name, extension] = split(leaf);
  if (extension === '.new') [name, extension] = split(name);
  return name.slice(0, 100) + extension;
}

function generateClStReference(input) {
  if (!input || !Array.isArray(input.fieldValues)) throw new Error('fieldValues must be an array in native collection order.');
  const fieldCount = input.fieldValues.length;
  const dateOffsetCount = checkedCount(input.dateOffsetCount ?? 0, 'dateOffsetCount');
  const subImageCount = checkedCount(input.subImageCount ?? 1, 'subImageCount');
  const counts6 = structureKey(dateOffsetCount, subImageCount, fieldCount);
  let selection;
  if (input.mask != null) {
    if (typeof input.mask === 'string' && !/^[0-9a-fA-F]{1,8}$/.test(input.mask)) {
      throw new Error('Mask must contain one to eight hexadecimal digits.');
    }
    const mask = typeof input.mask === 'string' ? parseInt(input.mask, 16) : Number(input.mask);
    if (!Number.isInteger(mask) || mask < 0 || mask > 0xFFFFFFFF ||
        (fieldCount < 32 && mask >= 2 ** fieldCount)) throw new Error('Mask selects fields outside the first 32 entries.');
    if (fieldCount > 0 && (mask === 0 || mask.toString(2).replace(/0/g, '').length > 3)) {
      throw new Error('Native nonempty selection produces one to three set bits.');
    }
    selection = { mask: mask >>> 0, attempts: null };
  } else {
    let tickIndex = 0;
    const nextMod = input.nextMod ?? (Array.isArray(input.tickCounts) ? (bound) => {
      if (tickIndex >= input.tickCounts.length) throw new Error('tickCounts does not contain enough native RNG calls.');
      return randomIndexFromTick(input.tickCounts[tickIndex++], bound);
    } : null);
    selection = createSelectionMask(fieldCount, nextMod);
  }
  const maskHex = selection.mask.toString(16).toUpperCase().padStart(8, '0');
  const tagData = collectTagData(input.fieldValues, selection.mask);
  const maskFragment = encrypt(maskHex, counts6);
  const tagFragment = fieldCount > 0 ? encrypt(tagData, 'TagData') : '';
  const normalIntermediate = maskFragment + tagFragment;
  let intermediate = normalIntermediate;
  let fileMetadata = null;
  let metadataFragment = '';
  let metadataLengthFragment = '';
  if (input.includeFileMetadata === true) {
    if (input.sourcePath == null) throw new Error('sourcePath is required for the optional metadata branch.');
    fileMetadata = metadataName(input.sourcePath);
    metadataFragment = encrypt(fileMetadata, 'TagData');
    const lengthHex = metadataFragment.length.toString(16).padStart(8, '0');
    // The second eight-digit block is a character length in lowercase hex.
    metadataLengthFragment = encrypt(lengthHex, counts6);
    intermediate = metadataLengthFragment + metadataFragment + normalIntermediate;
  }
  return {
    dateOffsetCount, subImageCount, fieldCount, counts6,
    ...selection, maskHex, tagData, maskFragment, tagFragment,
    fileMetadata, metadataFragment, metadataLengthFragment,
    normalIntermediate, intermediate,
    clStVersionInfo: encrypt(intermediate, 'TpyRcNeyeK'),
  };
}

module.exports = { encrypt, structureKey, randomIndexFromTick, createSelectionMask, collectTagData, metadataName, generateClStReference };

if (require.main === module) {
  if (process.argv.length !== 3) {
    process.stderr.write('Usage: node research/clst/reference-generator.cjs input.json\n');
    process.exitCode = 1;
  } else {
    try {
      const input = JSON.parse(fs.readFileSync(path.resolve(process.argv[2]), 'utf8'));
      process.stdout.write(`${JSON.stringify(generateClStReference(input), null, 2)}\n`);
    } catch (error) {
      process.stderr.write(`${error.message}\n`);
      process.exitCode = 1;
    }
  }
}

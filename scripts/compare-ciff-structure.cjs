#!/usr/bin/env node

const crypto = require('node:crypto');
const fs = require('node:fs');
const path = require('node:path');

const CONFUSABLE_TO_LATIN = new Map(Object.entries({
  '\u0410': 'A', '\u0412': 'B', '\u0421': 'C', '\u0415': 'E', '\u041d': 'H', '\u041a': 'K',
  '\u041c': 'M', '\u041e': 'O', '\u0420': 'P', '\u0422': 'T', '\u0425': 'X', '\u0423': 'Y',
  '\u0430': 'a', '\u0441': 'c', '\u0435': 'e', '\u043e': 'o', '\u0440': 'p', '\u0445': 'x', '\u0443': 'y',
}));

const IDENTITY_ATTRIBUTES = new Map([
  ['Field', ['Name']],
  ['DateOffset', ['Name']],
  ['Map', ['SubIMageRef', 'SubImageRef']],
  ['SrcField', ['SrcFieldName']],
  ['OffsetDate', ['SrcOffset']],
  ['Object', ['Index']],
  ['SubImage', ['ImageReference']],
]);

function sha256(bytes) {
  return crypto.createHash('sha256').update(bytes).digest('hex').toUpperCase();
}

function codePoints(value) {
  return [...String(value ?? '')].map((character) => (
    `U+${character.codePointAt(0).toString(16).toUpperCase().padStart(4, '0')}`
  ));
}

function confusableSkeleton(value) {
  return [...String(value ?? '').normalize('NFC')]
    .map((character) => CONFUSABLE_TO_LATIN.get(character) || character)
    .join('');
}

function decodeXmlEntities(value) {
  return String(value)
    .replace(/&#x([0-9a-f]+);/gi, (_, hex) => String.fromCodePoint(Number.parseInt(hex, 16)))
    .replace(/&#([0-9]+);/g, (_, decimal) => String.fromCodePoint(Number.parseInt(decimal, 10)))
    .replace(/&quot;/g, '"')
    .replace(/&apos;/g, "'")
    .replace(/&lt;/g, '<')
    .replace(/&gt;/g, '>')
    .replace(/&amp;/g, '&');
}

function findMarkupEnd(xml, start) {
  let quote = null;
  for (let index = start; index < xml.length; index += 1) {
    const character = xml[index];
    if (quote) {
      if (character === quote) quote = null;
      continue;
    }
    if (character === '"' || character === "'") {
      quote = character;
      continue;
    }
    if (character === '>') return index;
  }
  throw new Error(`Unterminated XML markup at character ${start}`);
}

function parseOpeningTag(source) {
  let index = 0;
  while (/\s/.test(source[index] || '')) index += 1;
  const nameStart = index;
  while (index < source.length && !/[\s/>]/.test(source[index])) index += 1;
  const name = source.slice(nameStart, index);
  if (!name) throw new Error(`Missing XML element name in <${source}>`);

  const attributes = [];
  while (index < source.length) {
    while (/\s/.test(source[index] || '')) index += 1;
    if (index >= source.length || source[index] === '/') break;
    const attributeStart = index;
    while (index < source.length && !/[\s=/>]/.test(source[index])) index += 1;
    const attributeName = source.slice(attributeStart, index);
    while (/\s/.test(source[index] || '')) index += 1;
    if (source[index] !== '=') throw new Error(`Missing '=' after attribute ${attributeName}`);
    index += 1;
    while (/\s/.test(source[index] || '')) index += 1;
    const quote = source[index];
    if (quote !== '"' && quote !== "'") throw new Error(`Unquoted attribute ${attributeName}`);
    index += 1;
    const valueStart = index;
    while (index < source.length && source[index] !== quote) index += 1;
    if (index >= source.length) throw new Error(`Unterminated attribute ${attributeName}`);
    attributes.push({ name: attributeName, value: decodeXmlEntities(source.slice(valueStart, index)) });
    index += 1;
  }
  return { name, attributes };
}

function parseXml(xml) {
  const documentNode = { type: 'document', children: [] };
  const stack = [documentNode];
  let index = 0;

  while (index < xml.length) {
    if (xml[index] !== '<') {
      const next = xml.indexOf('<', index);
      const end = next < 0 ? xml.length : next;
      const forbiddenCdataEnd = xml.indexOf(']]>', index);
      if (forbiddenCdataEnd >= 0 && forbiddenCdataEnd < end) {
        throw new Error(`CDATA terminator outside CDATA at character ${forbiddenCdataEnd}`);
      }
      const value = decodeXmlEntities(xml.slice(index, end));
      if (value) stack.at(-1).children.push({ type: 'text', value });
      index = end;
      continue;
    }
    if (xml.startsWith('<!--', index)) {
      const end = xml.indexOf('-->', index + 4);
      if (end < 0) throw new Error(`Unterminated XML comment at character ${index}`);
      stack.at(-1).children.push({ type: 'comment', value: xml.slice(index + 4, end) });
      index = end + 3;
      continue;
    }
    if (xml.startsWith('<![CDATA[', index)) {
      const end = xml.indexOf(']]>', index + 9);
      if (end < 0) throw new Error(`Unterminated CDATA at character ${index}`);
      stack.at(-1).children.push({ type: 'cdata', value: xml.slice(index + 9, end) });
      index = end + 3;
      continue;
    }
    if (xml.startsWith('<?', index)) {
      const end = xml.indexOf('?>', index + 2);
      if (end < 0) throw new Error(`Unterminated processing instruction at character ${index}`);
      stack.at(-1).children.push({ type: 'processing-instruction', value: xml.slice(index + 2, end) });
      index = end + 2;
      continue;
    }
    if (xml.startsWith('</', index)) {
      const end = findMarkupEnd(xml, index + 2);
      const name = xml.slice(index + 2, end).trim();
      const current = stack.pop();
      if (!current || current.type !== 'element' || current.name !== name) {
        throw new Error(`Mismatched closing tag </${name}> at character ${index}`);
      }
      index = end + 1;
      continue;
    }
    if (xml.startsWith('<!', index)) {
      const end = findMarkupEnd(xml, index + 2);
      stack.at(-1).children.push({ type: 'declaration', value: xml.slice(index + 2, end) });
      index = end + 1;
      continue;
    }

    const end = findMarkupEnd(xml, index + 1);
    const source = xml.slice(index + 1, end);
    const selfClosing = /\/\s*$/.test(source);
    const parsed = parseOpeningTag(source);
    const node = { type: 'element', name: parsed.name, attributes: parsed.attributes, children: [] };
    stack.at(-1).children.push(node);
    if (!selfClosing) stack.push(node);
    index = end + 1;
  }

  if (stack.length !== 1) throw new Error(`Unclosed XML element <${stack.at(-1).name}>`);
  const roots = documentNode.children.filter((node) => node.type === 'element');
  if (roots.length !== 1) throw new Error(`Expected one XML root element, found ${roots.length}`);
  return roots[0];
}

function decodeUtf16Be(bytes) {
  const swapped = Buffer.alloc(bytes.length - (bytes.length % 2));
  for (let index = 0; index < swapped.length; index += 2) {
    swapped[index] = bytes[index + 1];
    swapped[index + 1] = bytes[index];
  }
  return swapped.toString('utf16le');
}

function analyzeCiffBuffer(bytes, source = '<buffer>') {
  let bom = 'none';
  let encoding = 'unknown';
  let body = bytes;
  if (bytes[0] === 0xff && bytes[1] === 0xfe) {
    bom = 'FF FE';
    encoding = 'UTF-16LE';
    body = bytes.subarray(2);
  } else if (bytes[0] === 0xfe && bytes[1] === 0xff) {
    bom = 'FE FF';
    encoding = 'UTF-16BE';
    body = bytes.subarray(2);
  } else if (bytes[0] === 0xef && bytes[1] === 0xbb && bytes[2] === 0xbf) {
    bom = 'EF BB BF';
    encoding = 'UTF-8';
    body = bytes.subarray(3);
  }

  let text;
  if (encoding === 'UTF-16LE') text = body.toString('utf16le');
  else if (encoding === 'UTF-16BE') text = decodeUtf16Be(body);
  else text = body.toString('utf8');

  const crlfCount = (text.match(/\r\n/g) || []).length;
  const loneLfCount = (text.match(/(?<!\r)\n/g) || []).length;
  const loneCrCount = (text.match(/\r(?!\n)/g) || []).length;
  const lines = text.split(/\r\n|\n|\r/);
  const declaration = lines[0] || '';
  const declarationEncoding = declaration.match(/\bencoding\s*=\s*(["'])(.*?)\1/i)?.[2] || null;
  const finalCrLf = text.endsWith('\r\n');
  const nonEmptyLineCount = lines.filter((line) => line.length > 0).length;
  const twoLineLayout = crlfCount === 2 && loneLfCount === 0 && loneCrCount === 0 &&
    nonEmptyLineCount === 2 && lines.length === 3 && lines[2] === '';
  const xmlText = declaration.startsWith('<?xml') ? text.slice(text.indexOf('?>') + 2).replace(/^(?:\r\n|\n|\r)/, '').replace(/(?:\r\n|\n|\r)$/, '') : text.trim();

  return {
    source,
    bytes,
    sha256: sha256(bytes),
    byteLength: bytes.length,
    bom,
    encoding,
    declaration,
    declarationEncoding,
    crlfCount,
    loneLfCount,
    loneCrCount,
    nonEmptyLineCount,
    twoLineLayout,
    finalCrLf,
    text,
    xmlText,
    root: parseXml(xmlText),
  };
}

function analyzeCiffFile(filePath) {
  return analyzeCiffBuffer(fs.readFileSync(filePath), path.resolve(filePath));
}

function attribute(node, name) {
  return node?.attributes?.find((item) => item.name === name)?.value ?? null;
}

function elementChildren(node) {
  return node?.children?.filter((child) => child.type === 'element') || [];
}

function directValueTokens(node) {
  return (node?.children || [])
    .filter((child) => child.type === 'text' || child.type === 'cdata')
    .filter((child) => child.value !== '')
    .map((child) => ({ type: child.type, value: child.value }));
}

function walkElements(node, visitor, ancestors = []) {
  visitor(node, ancestors);
  elementChildren(node).forEach((child) => walkElements(child, visitor, [...ancestors, node]));
}

function findElements(root, name) {
  const result = [];
  walkElements(root, (node) => {
    if (node.name === name) result.push(node);
  });
  return result;
}

function findDirectElement(node, name) {
  return elementChildren(node).find((child) => child.name === name) || null;
}

function orderedElementSignature(node) {
  return node ? elementChildren(node).map((child) => child.name) : [];
}

function collectFieldStructuralSignature(fieldNode) {
  const data = findDirectElement(fieldNode, 'Data');
  const objects = data ? elementChildren(data).filter((child) => child.name === 'Object') : [];
  const text = findDirectElement(fieldNode, 'Text');
  const font = text ? findDirectElement(text, 'Font') : null;
  const barcode = findDirectElement(fieldNode, 'Barcode');
  const dataMatrix = barcode ? findDirectElement(barcode, 'DataMatrix') : null;

  return {
    fieldChildren: orderedElementSignature(fieldNode),
    dataChildren: orderedElementSignature(data),
    objects: objects.map((object) => ({
      attributes: object.attributes.map((item) => item.name),
      children: orderedElementSignature(object),
      varTextChildren: orderedElementSignature(findDirectElement(object, 'VarText')),
      counterChildren: orderedElementSignature(findDirectElement(object, 'CounterText')),
    })),
    textChildren: orderedElementSignature(text),
    fontChildren: orderedElementSignature(font),
    barcodeChildren: orderedElementSignature(barcode),
    dataMatrixChildren: orderedElementSignature(dataMatrix),
  };
}

function nodeIdentityBase(node) {
  if (node.name === 'Field') {
    const fieldType = elementChildren(node)
      .find((child) => child.name === 'FldType');
    const fieldTypeValue = fieldType
      ? directValueTokens(fieldType).map((token) => token.value).join('')
      : '';
    if (fieldTypeValue === 'Barcode' && findElements(node, 'DataMatrix').length > 0) {
      return 'Field[Role="DataMatrix"]';
    }
    const name = attribute(node, 'Name') || '';
    return `Field[NameSkeleton=${JSON.stringify(confusableSkeleton(name))}]`;
  }
  // References and names are values to compare, not node identity. Matching
  // them by value would hide an attribute/reference change behind a
  // misleading missing+extra pair. Object/Index is the one stable positional
  // identity used by the CIFF Data object list.
  const candidates = node.name === 'Object' ? ['Index'] : [];
  for (const candidate of candidates) {
    const value = attribute(node, candidate);
    if (value != null) return `${node.name}[${candidate}=${JSON.stringify(value)}]`;
  }
  return node.name;
}

function displayNode(node) {
  const candidates = IDENTITY_ATTRIBUTES.get(node.name) || [];
  for (const candidate of candidates) {
    const value = attribute(node, candidate);
    if (value != null) return `${node.name}[${candidate}=${JSON.stringify(value)}]`;
  }
  return node.name;
}

function indexedChildren(node) {
  const counts = new Map();
  const totals = new Map();
  const children = elementChildren(node);
  children.forEach((child) => {
    const base = nodeIdentityBase(child);
    totals.set(base, (totals.get(base) || 0) + 1);
  });
  return children.map((child) => {
    const base = nodeIdentityBase(child);
    const occurrence = (counts.get(base) || 0) + 1;
    counts.set(base, occurrence);
    const key = `${base}#${occurrence}`;
    const segment = totals.get(base) > 1 ? `${displayNode(child)}[${occurrence}]` : displayNode(child);
    return { node: child, key, segment };
  });
}

function addDiff(diffs, category, pathValue, kind, expected, actual, details = undefined) {
  diffs.push({ category, path: pathValue, kind, expected, actual, ...(details ? { details } : {}) });
}

function compareAttributes(expected, actual, currentPath, diffs) {
  const expectedNames = expected.attributes.map((item) => item.name);
  const actualNames = actual.attributes.map((item) => item.name);
  const expectedMap = new Map(expected.attributes.map((item) => [item.name, item.value]));
  const actualMap = new Map(actual.attributes.map((item) => [item.name, item.value]));
  const commonExpectedOrder = expectedNames.filter((name) => actualMap.has(name));
  const commonActualOrder = actualNames.filter((name) => expectedMap.has(name));
  if (JSON.stringify(commonExpectedOrder) !== JSON.stringify(commonActualOrder)) {
    addDiff(diffs, 'order', `${currentPath}/@*`, 'attribute-order', commonExpectedOrder, commonActualOrder);
  }
  for (const item of expected.attributes) {
    if (!actualMap.has(item.name)) {
      addDiff(diffs, 'attribute', `${currentPath}/@${item.name}`, 'missing-attribute', item.value, null);
      continue;
    }
    const actualValue = actualMap.get(item.name);
    if (item.value !== actualValue) {
      addDiff(diffs, 'attribute', `${currentPath}/@${item.name}`, 'attribute-value', item.value, actualValue);
      if (confusableSkeleton(item.value) === confusableSkeleton(actualValue) && item.value !== actualValue) {
        addDiff(diffs, 'unicode', `${currentPath}/@${item.name}`, 'confusable-code-points', item.value, actualValue, {
          expectedCodePoints: codePoints(item.value),
          actualCodePoints: codePoints(actualValue),
        });
      }
    }
  }
  for (const item of actual.attributes) {
    if (!expectedMap.has(item.name)) {
      addDiff(diffs, 'attribute', `${currentPath}/@${item.name}`, 'extra-attribute', null, item.value);
    }
  }
}

function compareElement(expected, actual, currentPath, diffs) {
  if (expected.name !== actual.name) {
    addDiff(diffs, 'value', currentPath, 'element-name', expected.name, actual.name);
    return;
  }
  compareAttributes(expected, actual, currentPath, diffs);

  const expectedValues = directValueTokens(expected);
  const actualValues = directValueTokens(actual);
  if (JSON.stringify(expectedValues) !== JSON.stringify(actualValues)) {
    addDiff(diffs, 'value', currentPath, 'direct-content', expectedValues, actualValues);
  }

  const expectedChildren = indexedChildren(expected);
  const actualChildren = indexedChildren(actual);
  const expectedMap = new Map(expectedChildren.map((entry) => [entry.key, entry]));
  const actualMap = new Map(actualChildren.map((entry) => [entry.key, entry]));
  const expectedCommon = expectedChildren.filter((entry) => actualMap.has(entry.key)).map((entry) => entry.key);
  const actualCommon = actualChildren.filter((entry) => expectedMap.has(entry.key)).map((entry) => entry.key);
  if (JSON.stringify(expectedCommon) !== JSON.stringify(actualCommon)) {
    addDiff(diffs, 'order', `${currentPath}/*`, 'element-child-order',
      expectedCommon.map((key) => expectedMap.get(key).segment),
      actualCommon.map((key) => actualMap.get(key).segment));
  }

  expectedChildren.forEach((entry) => {
    const actualEntry = actualMap.get(entry.key);
    const childPath = `${currentPath}/${entry.segment}`;
    if (!actualEntry) {
      addDiff(diffs, 'missing', childPath, 'element', displayNode(entry.node), null);
      return;
    }
    compareElement(entry.node, actualEntry.node, childPath, diffs);
  });
  actualChildren.forEach((entry) => {
    if (expectedMap.has(entry.key)) return;
    addDiff(diffs, 'extra', `${currentPath}/${entry.segment}`, 'element', null, displayNode(entry.node));
  });
}

function collectFields(root) {
  return findElements(root, 'Field').map((node, index) => {
    const name = attribute(node, 'Name') || '';
    return {
      index,
      name,
      codePoints: codePoints(name),
      skeleton: confusableSkeleton(name),
      signature: collectFieldStructuralSignature(node),
    };
  });
}

function collectReferences(root) {
  const fields = new Set(collectFields(root).map((field) => field.name));
  const dateOffsets = new Set(findElements(root, 'DateOffset').map((node) => attribute(node, 'Name')).filter(Boolean));
  const imageReferences = new Set(findElements(root, 'SubImage').map((node) => attribute(node, 'ImageReference')).filter(Boolean));
  const edges = [];

  findElements(root, 'Map').forEach((node, index) => {
    const target = attribute(node, 'SubIMageRef') ?? attribute(node, 'SubImageRef');
    const value = directValueTokens(node).map((token) => token.value).join('');
    edges.push({ key: `image-map-attribute#${index + 1}`, kind: 'image-map', target, valid: target != null && imageReferences.has(target) });
    edges.push({ key: `image-map-value#${index + 1}`, kind: 'image-map-value', target: value, valid: imageReferences.has(value) });
  });
  findElements(root, 'SrcField').forEach((node, index) => {
    const target = attribute(node, 'SrcFieldName');
    edges.push({ key: `field-reference#${index + 1}`, kind: 'field-reference', target, valid: target != null && fields.has(target) });
  });
  findElements(root, 'OffsetDate').forEach((node, index) => {
    const target = attribute(node, 'SrcOffset');
    edges.push({ key: `date-offset-reference#${index + 1}`, kind: 'date-offset-reference', target, valid: target != null && dateOffsets.has(target) });
  });
  return { fields, dateOffsets, imageReferences, edges };
}

function compareReferences(expectedRoot, actualRoot, diffs) {
  const expected = collectReferences(expectedRoot);
  const actual = collectReferences(actualRoot);
  const expectedEdges = new Map(expected.edges.map((edge) => [edge.key, edge]));
  const actualEdges = new Map(actual.edges.map((edge) => [edge.key, edge]));

  expected.edges.forEach((edge) => {
    const actualEdge = actualEdges.get(edge.key);
    if (!actualEdge) {
      addDiff(diffs, 'reference', `/references/${edge.key}`, 'missing-reference', edge.target, null);
    } else if (edge.target !== actualEdge.target) {
      addDiff(diffs, 'reference', `/references/${edge.key}`, 'reference-target', edge.target, actualEdge.target, {
        expectedCodePoints: codePoints(edge.target),
        actualCodePoints: codePoints(actualEdge.target),
      });
    }
  });
  actual.edges.forEach((edge) => {
    if (!expectedEdges.has(edge.key)) {
      addDiff(diffs, 'reference', `/references/${edge.key}`, 'extra-reference', null, edge.target);
    }
    if (!edge.valid) {
      addDiff(diffs, 'reference', `/references/${edge.key}`, 'dangling-reference', null, edge.target);
    }
  });
}

function compareByteEnvelope(expected, actual, diffs) {
  const properties = [
    'byteLength', 'sha256', 'bom', 'encoding', 'declaration', 'declarationEncoding',
    'crlfCount', 'loneLfCount', 'loneCrCount', 'nonEmptyLineCount', 'twoLineLayout', 'finalCrLf',
  ];
  properties.forEach((property) => {
    if (expected[property] !== actual[property]) {
      addDiff(diffs, 'value', `/bytes/${property}`, 'byte-envelope', expected[property], actual[property]);
    }
  });
}

function summarizeDiffs(diffs) {
  return diffs.reduce((summary, diff) => {
    summary[diff.category] = (summary[diff.category] || 0) + 1;
    return summary;
  }, {});
}

function compareCiffAnalyses(expected, actual) {
  const diffs = [];
  compareByteEnvelope(expected, actual, diffs);
  compareElement(expected.root, actual.root, `/${displayNode(expected.root)}`, diffs);
  compareReferences(expected.root, actual.root, diffs);
  return {
    expected: {
      source: expected.source,
      sha256: expected.sha256,
      byteLength: expected.byteLength,
      bom: expected.bom,
      encoding: expected.encoding,
      crlfCount: expected.crlfCount,
      loneLfCount: expected.loneLfCount,
      loneCrCount: expected.loneCrCount,
      nonEmptyLineCount: expected.nonEmptyLineCount,
      twoLineLayout: expected.twoLineLayout,
      finalCrLf: expected.finalCrLf,
    },
    actual: {
      source: actual.source,
      sha256: actual.sha256,
      byteLength: actual.byteLength,
      bom: actual.bom,
      encoding: actual.encoding,
      crlfCount: actual.crlfCount,
      loneLfCount: actual.loneLfCount,
      loneCrCount: actual.loneCrCount,
      nonEmptyLineCount: actual.nonEmptyLineCount,
      twoLineLayout: actual.twoLineLayout,
      finalCrLf: actual.finalCrLf,
    },
    fields: {
      expected: collectFields(expected.root),
      actual: collectFields(actual.root),
    },
    summary: summarizeDiffs(diffs),
    diffs,
  };
}

function compareCiffBuffers(expectedBytes, actualBytes, sources = {}) {
  return compareCiffAnalyses(
    analyzeCiffBuffer(expectedBytes, sources.expected || '<expected-buffer>'),
    analyzeCiffBuffer(actualBytes, sources.actual || '<actual-buffer>'),
  );
}

function compareCiffFiles(expectedPath, actualPath) {
  return compareCiffAnalyses(analyzeCiffFile(expectedPath), analyzeCiffFile(actualPath));
}

function formatScalar(value) {
  if (value == null || typeof value !== 'object') return JSON.stringify(value);
  return JSON.stringify(value);
}

function formatReport(report) {
  const lines = [];
  lines.push('CIFF ORDERED STRUCTURAL COMPARISON');
  lines.push(`Expected: ${report.expected.source}`);
  lines.push(`Actual:   ${report.actual.source}`);
  lines.push('');
  lines.push('BYTE ENVELOPE');
  ['expected', 'actual'].forEach((side) => {
    const item = report[side];
    lines.push(`${side}: bytes=${item.byteLength}; sha256=${item.sha256}; BOM=${item.bom}; encoding=${item.encoding}; CRLF=${item.crlfCount}; loneLF=${item.loneLfCount}; loneCR=${item.loneCrCount}; nonEmptyLines=${item.nonEmptyLineCount}; twoLine=${item.twoLineLayout}; finalCRLF=${item.finalCrLf}`);
  });
  lines.push('');
  lines.push('FIELD NAME INVENTORY (ordered; exact Unicode code points)');
  ['expected', 'actual'].forEach((side) => {
    lines.push(`${side}:`);
    report.fields[side].forEach((field) => {
      lines.push(`  [${field.index}] ${JSON.stringify(field.name)} = ${field.codePoints.join(' ')}`);
      lines.push(`      signature: ${JSON.stringify(field.signature)}`);
    });
  });
  lines.push('');
  lines.push(`SUMMARY: total=${report.diffs.length}; ${Object.entries(report.summary).sort(([a], [b]) => a.localeCompare(b)).map(([category, count]) => `${category}=${count}`).join('; ')}`);
  lines.push('');
  lines.push('ORDERED STRUCTURAL DIFF');
  report.diffs.forEach((diff, index) => {
    lines.push(`[${String(index + 1).padStart(3, '0')}] ${diff.category.toUpperCase()} ${diff.kind} ${diff.path}`);
    lines.push(`      expected: ${formatScalar(diff.expected)}`);
    lines.push(`      actual:   ${formatScalar(diff.actual)}`);
    if (diff.details) lines.push(`      details:  ${JSON.stringify(diff.details)}`);
  });
  return `${lines.join('\n')}\n`;
}

function printUsage() {
  process.stderr.write('Usage: node scripts/compare-ciff-structure.cjs <expected.ciff> <actual.ciff> [--json] [--fail-on-diff]\n');
}

if (require.main === module) {
  const args = process.argv.slice(2);
  const json = args.includes('--json');
  const failOnDiff = args.includes('--fail-on-diff');
  const paths = args.filter((argument) => !argument.startsWith('--'));
  if (paths.length !== 2) {
    printUsage();
    process.exitCode = 2;
  } else {
    try {
      const report = compareCiffFiles(paths[0], paths[1]);
      process.stdout.write(json ? `${JSON.stringify(report, null, 2)}\n` : formatReport(report));
      if (failOnDiff && report.diffs.length) process.exitCode = 1;
    } catch (error) {
      process.stderr.write(`${error.stack || error.message}\n`);
      process.exitCode = 2;
    }
  }
}

module.exports = {
  analyzeCiffBuffer,
  analyzeCiffFile,
  codePoints,
  compareCiffAnalyses,
  compareCiffBuffers,
  compareCiffFiles,
  confusableSkeleton,
  formatReport,
  parseXml,
};

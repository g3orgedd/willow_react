const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');

const { parseXml } = require('../scripts/compare-ciff-structure.cjs');
const {
  createProductionCiffRuntime,
  decodeCiffBytes,
} = require('./helpers/ciff-production-harness.cjs');

const FIXTURE_DIR = path.join(__dirname, 'fixtures', 'conservative');
const FIXTURES = [
  'constant-text.ciff',
  'external-text.ciff',
  'date.ciff',
  'offset-date.ciff',
  'field-order.ciff',
];

function fixture(name) {
  return fs.readFileSync(path.join(FIXTURE_DIR, name));
}

function elements(node, name) {
  return (node?.children ?? []).filter((child) => (
    child.type === 'element' && (name == null || child.name === name)
  ));
}

function child(node, name) {
  return elements(node, name)[0] ?? null;
}

function text(node) {
  return (node?.children ?? []).map((item) => (
    item.type === 'element' ? text(item) : (item.value ?? '')
  )).join('');
}

function attr(node, name) {
  return node?.attributes.find((item) => item.name === name)?.value ?? null;
}

// Compare ordered XML semantics, including attribute presence and CDATA. The
// parser's start/end offsets and quote spelling are intentionally not compared.
function semantic(node) {
  if (!node) return null;
  if (node.type !== 'element') return { type: node.type, value: node.value };
  return {
    name: node.name,
    attributes: node.attributes.map(({ name, value }) => ({ name, value })),
    children: node.children.map(semantic),
  };
}

function rootOf(bytes) {
  return parseXml(decodeCiffBytes(bytes));
}

function fieldsOf(root) {
  return elements(child(root, 'SubImage'), 'Field');
}

function objectOf(field) {
  return child(child(field, 'Data'), 'Object');
}

function fieldState(field) {
  const object = objectOf(field);
  return {
    name: attr(field, 'Name'),
    fldType: text(child(field, 'FldType')),
    dataType: text(child(object, 'DataType')),
    ln: child(field, 'Ln') ? text(child(field, 'Ln')) : null,
    staticAttr: attr(object, 'Static'),
    parseAttr: attr(object, 'Parse'),
    reference: attr(object, 'Reference'),
    fixedLen: child(object, 'FixedLen') !== null,
    srcData: semantic(child(object, 'SrcData')),
    offsetRef: attr(child(object, 'OffsetDate'), 'SrcOffset'),
    hasOffsetDate: child(object, 'OffsetDate') !== null,
    defaultValue: text(child(object, 'Default')),
    calcData: text(child(field, 'CalcData')),
  };
}

function save(runtime) {
  const saved = runtime.save();
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  return saved;
}

function encodeXml(xml) {
  return Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(xml, 'utf16le')]);
}

test('counter edits leave shadow counter and display properties in vendor extensions untouched', () => {
  const shadow = '<VendorShadow><Displayed>0</Displayed><CounterText><SubCnt Significance="9">' +
    '<NoOfChars>9</NoOfChars><StartVal>shadow</StartVal><StepSize>99</StepSize></SubCnt></CounterText></VendorShadow>';
  const counter = '<CounterText><SubCnt Significance="0"><NoOfChars>4</NoOfChars>' +
    '<StartVal><![CDATA[1]]></StartVal><EndVal><![CDATA[9999]]></EndVal><StepSize>1</StepSize>' +
    '<ClrStCntType></ClrStCntType></SubCnt></CounterText>';
  const xml = decodeCiffBytes(fixture('constant-text.ciff'))
    .replace('<FldType>FixedText</FldType>', '<FldType>CounterText</FldType>')
    .replace(/<Data\b[^>]*>[\s\S]*?<\/Data>/, '<Data><Object Static="0" Reference="">' + shadow +
      '<DataType>4</DataType><Default><![CDATA[0001]]></Default>' + counter + '</Object></Data>')
    .replace('<![CDATA[Use By]]>', '<![CDATA[0001]]>');
  const runtime = createProductionCiffRuntime(encodeXml(xml));
  assert.equal(runtime.state.fields[0].data.counter.noOfChars, 4);
  runtime.state.fields[0].geom.x += 1;
  const saved = save(runtime);
  const output = decodeCiffBytes(saved.bytes);
  assert.ok(output.includes(shadow), output);
  assert.ok(output.includes(counter));
  assert.equal(createProductionCiffRuntime(saved.bytes).state.fields[0].printed, true);
});

for (const name of FIXTURES) {
  test(`${name}: no-op import/model/export preserves all ordered field XML semantics`, () => {
    const bytes = fixture(name);
    const sourceRoot = rootOf(bytes);
    const runtime = createProductionCiffRuntime(bytes);
    const saved = save(runtime);
    const outputRoot = rootOf(saved.bytes);

    assert.deepEqual(fieldsOf(outputRoot).map(semantic), fieldsOf(sourceRoot).map(semantic));
    assert.deepEqual(
      fieldsOf(outputRoot).map(fieldState),
      fieldsOf(sourceRoot).map(fieldState),
    );
    const sourceHeader = child(child(sourceRoot, 'SubImage'), 'SubHeader');
    const outputHeader = child(child(outputRoot, 'SubImage'), 'SubHeader');
    for (const dimension of ['ImageWidth', 'ImageHeight', 'MaxImageWidth', 'MaxImageHeight']) {
      assert.equal(text(child(outputHeader, dimension)), text(child(sourceHeader, dimension)), dimension);
    }
    const reopened = createProductionCiffRuntime(saved.bytes);
    assert.deepEqual(save(reopened).bytes, saved.bytes, 'save/reopen/save must be stable');
  });

  test(`${name}: editing X preserves names, optional properties, unknown nodes and sibling order`, () => {
    const bytes = fixture(name);
    const sourceRoot = rootOf(bytes);
    const runtime = createProductionCiffRuntime(bytes);
    const edited = runtime.state.fields[0];
    const oldX = edited.geom.x;
    edited.geom.x += 17;
    runtime.state.subImage.usedSizeDirty = true;
    const saved = save(runtime);
    const outputRoot = rootOf(saved.bytes);

    const expectedFields = fieldsOf(sourceRoot).map(semantic);
    expectedFields[0].children.find((item) => item.name === 'X').children = [
      { type: 'text', value: String(oldX + 17) },
    ];
    assert.deepEqual(fieldsOf(outputRoot).map(semantic), expectedFields);

    const sourceSub = child(sourceRoot, 'SubImage');
    const outputSub = child(outputRoot, 'SubImage');
    const outputHeader = child(outputSub, 'SubHeader');
    assert.equal(Number(text(child(outputHeader, 'ImageWidth'))), Math.max(
      ...runtime.state.fields.map((field) => field.geom.x + field.geom.w),
    ));
    assert.equal(Number(text(child(outputHeader, 'ImageHeight'))), Math.max(
      ...runtime.state.fields.map((field) => field.geom.y + field.geom.h),
    ));
    for (const maximum of ['MaxImageWidth', 'MaxImageHeight']) {
      assert.equal(text(child(outputHeader, maximum)), text(child(child(sourceSub, 'SubHeader'), maximum)));
    }
    assert.deepEqual(outputSub.attributes, sourceSub.attributes);
    assert.deepEqual(
      elements(outputSub).map((node) => [node.name, attr(node, 'Name'), attr(node, 'Marker')]),
      elements(sourceSub).map((node) => [node.name, attr(node, 'Name'), attr(node, 'Marker')]),
    );
    assert.deepEqual(
      elements(outputSub).filter((node) => !['SubHeader', 'Field'].includes(node.name)).map(semantic),
      elements(sourceSub).filter((node) => !['SubHeader', 'Field'].includes(node.name)).map(semantic),
    );
    // ClStVersionInfo remains controlled by the existing production policy.
    const withoutClSt = (root) => elements(child(root, 'Header'))
      .filter((node) => node.name !== 'ClStVersionInfo').map(semantic);
    assert.deepEqual(withoutClSt(outputRoot), withoutClSt(sourceRoot));
    assert.deepEqual(child(outputRoot, 'Header').attributes, child(sourceRoot, 'Header').attributes);
    assert.deepEqual(semantic(child(outputRoot, 'GenericSettings')), semantic(child(sourceRoot, 'GenericSettings')));

    const reopened = createProductionCiffRuntime(saved.bytes);
    assert.equal(reopened.state.fields[0].geom.x, oldX + 17);
    assert.deepEqual(
      Array.from(reopened.state.fields, (field) => [field.name, field.sourceName]),
      fieldsOf(sourceRoot).map((field) => [attr(field, 'Name'), attr(field, 'Name')]),
    );
  });
}

test('constant FixedText / 0 keeps absent optional Object attributes and nodes', () => {
  const runtime = createProductionCiffRuntime(fixture('constant-text.ciff'));
  const field = fieldsOf(rootOf(save(runtime).bytes))[0];
  assert.deepEqual(fieldState(field), {
    name: 'Field00', fldType: 'FixedText', dataType: '0', ln: null,
    staticAttr: null, parseAttr: null, reference: '', fixedLen: false,
    srcData: null, offsetRef: null, hasOffsetDate: false,
    defaultValue: 'Use By', calcData: 'Use By',
  });
});

test('explicit optional model edits distinguish zero-valued attributes from absence', () => {
  const runtime = createProductionCiffRuntime(fixture('constant-text.ciff'));
  const added = runtime.state.fields[0];
  added.ln = 4;
  added.data.staticAttr = '0';
  added.data.parseAttr = '0';
  added.data.fixedLen = true;
  const first = fieldsOf(rootOf(save(runtime).bytes))[0];
  assert.equal(text(child(first, 'Ln')), '4');
  assert.equal(attr(objectOf(first), 'Static'), '0');
  assert.equal(attr(objectOf(first), 'Parse'), '0');
  assert.notEqual(child(objectOf(first), 'FixedLen'), null);
  assert.equal(child(objectOf(first), 'SrcData'), null);
  assert.equal(child(objectOf(first), 'OffsetDate'), null);
  const childOrder = elements(first).map((node) => node.name);
  assert.ok(childOrder.indexOf('H') < childOrder.indexOf('Ln'));
  assert.ok(childOrder.indexOf('Ln') < childOrder.indexOf('CalcData'));

  const removed = runtime.state.fields[0];
  removed.data.staticAttr = null;
  removed.data.parseAttr = null;
  removed.data.fixedLen = false;
  const second = fieldsOf(rootOf(save(runtime).bytes))[0];
  assert.equal(text(child(second, 'Ln')), '4');
  assert.equal(attr(objectOf(second), 'Static'), null);
  assert.equal(attr(objectOf(second), 'Parse'), null);
  assert.equal(child(objectOf(second), 'FixedLen'), null);
});

for (const metadataState of ['absent', 'empty']) {
  test(`imported ${metadataState} optional metadata and missing ImageMapping survive no-op and coordinate saves`, () => {
    let xml = decodeCiffBytes(fixture('constant-text.ciff'))
      .replace(/<GenericSettings>[\s\S]*?<\/GenericSettings>/, '');
    for (const attribute of ['ImageReference', 'FormatName', 'PrinterFormatName', 'Reference']) {
      const pattern = new RegExp(` ${attribute}="[^"]*"`);
      xml = xml.replace(pattern, metadataState === 'empty' ? ` ${attribute}=""` : '');
    }
    // These are also optional loaded values; the model's empty string must
    // not recreate absent nodes during an unrelated edit.
    xml = xml.replace(/<CalcData>[\s\S]*?<\/CalcData>/, '')
      .replace(/<Default>[\s\S]*?<\/Default>/, '');
    const input = encodeXml(xml);
    for (const xDelta of [0, 7]) {
      const runtime = createProductionCiffRuntime(input);
      runtime.state.fields[0].geom.x += xDelta;
      const output = rootOf(save(runtime).bytes);
      assert.equal(child(output, 'GenericSettings'), null);
      const expected = semantic(child(rootOf(input), 'SubImage'));
      const field = expected.children.find((node) => node.name === 'Field');
      field.children.find((node) => node.name === 'X').children = [
        { type: 'text', value: String(2683 + xDelta) },
      ];
      expected.children.find((node) => node.name === 'SubHeader')
        .children.find((node) => node.name === 'ImageWidth').children = [
          { type: 'text', value: String(3666 + xDelta) },
        ];
      assert.deepEqual(semantic(child(output, 'SubImage')), expected);
    }
  });
}

test('external FixedText / 6 preserves Static, FixedLen, source CDATA and SQL verbatim', () => {
  const source = fieldsOf(rootOf(fixture('external-text.ciff')))[0];
  const runtime = createProductionCiffRuntime(fixture('external-text.ciff'));
  const output = fieldsOf(rootOf(save(runtime).bytes))[0];
  const actual = fieldState(output);
  assert.equal(actual.dataType, '6');
  assert.equal(actual.staticAttr, '0');
  assert.equal(actual.parseAttr, null);
  assert.equal(actual.fixedLen, true);
  assert.equal(actual.hasOffsetDate, false);
  assert.deepEqual(actual.srcData, fieldState(source).srcData);
  assert.notEqual(actual.defaultValue, actual.calcData, 'preview must not replace external configuration');
  const sourceData = child(objectOf(output), 'SrcData');
  assert.equal(child(sourceData, 'ConnStr').children[0].type, 'cdata');
  assert.equal(child(sourceData, 'SrcSQL').children[0].type, 'cdata');
  assert.match(text(child(sourceData, 'SrcSQL')), /##PRODUCTCODE##/);
});

test('editing a self-closing SrcData adds configured children and preserves source attributes', () => {
  const xml = decodeCiffBytes(fixture('external-text.ciff'))
    .replace(/<SrcData\b[^>]*>[\s\S]*?<\/SrcData>/, '<SrcData Vendor="keep"/>');
  const runtime = createProductionCiffRuntime(encodeXml(xml));
  runtime.state.fields[0].data.srcData = { connStr: 'db', srcSQL: 'SELECT value' };
  const saved = save(runtime);
  const sourceData = child(objectOf(fieldsOf(rootOf(saved.bytes))[0]), 'SrcData');
  assert.deepEqual(semantic(sourceData), {
    name: 'SrcData',
    attributes: [{ name: 'Vendor', value: 'keep' }],
    children: [
      { name: 'ConnStr', attributes: [], children: [{ type: 'cdata', value: 'db' }] },
      { name: 'SrcSQL', attributes: [], children: [{ type: 'cdata', value: 'SELECT value' }] },
    ],
  });
  const reopened = createProductionCiffRuntime(saved.bytes);
  assert.equal(reopened.state.fields[0].data.srcData.connStr, 'db');
  assert.equal(reopened.state.fields[0].data.srcData.srcSQL, 'SELECT value');
});

test('null source SQL becomes a native empty SrcSQL while undefined preserves loaded SQL', () => {
  const xml = decodeCiffBytes(fixture('external-text.ciff'))
    .replace('<VendorSource Token="preserve"/>', '<VendorSource Token="preserve"><SrcSQL><![CDATA[opaque nested SQL]]></SrcSQL></VendorSource>');
  const bytes = encodeXml(xml);
  const originalSource = child(objectOf(fieldsOf(rootOf(bytes))[0]), 'SrcData');
  const original = semantic(originalSource);

  for (const srcSQL of [undefined, null]) {
    const runtime = createProductionCiffRuntime(bytes);
    runtime.state.fields[0].data.srcData.srcSQL = srcSQL;
    const output = child(objectOf(fieldsOf(rootOf(save(runtime).bytes))[0]), 'SrcData');
    const expected = JSON.parse(JSON.stringify(original));
    if (srcSQL === null) expected.children.find((node) => node.name === 'SrcSQL').children = [{ type: 'cdata', value: '' }];
    assert.deepEqual(semantic(output), expected);
    assert.equal(text(child(child(output, 'VendorSource'), 'SrcSQL')), 'opaque nested SQL');
    assert.equal(text(child(output, 'ConnStr')), text(child(originalSource, 'ConnStr')));
  }
});

test('DateText / 2 retains its format separately from preview and has no offset/source/fixed length', () => {
  const runtime = createProductionCiffRuntime(fixture('date.ciff'));
  const parsed = runtime.state.fields[0];
  assert.equal(parsed.data.defaultValue, "cl:jj''");
  assert.equal(parsed.calcData, '109');
  const actual = fieldState(fieldsOf(rootOf(save(runtime).bytes))[0]);
  assert.equal(actual.fldType, 'DateText');
  assert.equal(actual.dataType, '2');
  assert.equal(actual.staticAttr, '0');
  assert.equal(actual.parseAttr, '1');
  assert.equal(actual.hasOffsetDate, false);
  assert.equal(actual.srcData, null);
  assert.equal(actual.fixedLen, false);
  assert.equal(actual.defaultValue, "cl:jj''");
});

test('OffsetDateText / 3 resolves SellBy by name regardless of Header order', () => {
  const bytes = fixture('offset-date.ciff');
  const originalText = decodeCiffBytes(bytes);
  const offsetBlocks = originalText.match(/<DateOffset\b[^>]*>[\s\S]*?<\/DateOffset>/g);
  assert.equal(offsetBlocks.length, 2);
  const reversedText = originalText.replace(offsetBlocks[0], '__FIRST_OFFSET__')
    .replace(offsetBlocks[1], offsetBlocks[0]).replace('__FIRST_OFFSET__', offsetBlocks[1]);

  for (const input of [bytes, encodeXml(reversedText)]) {
    const runtime = createProductionCiffRuntime(input);
    assert.equal(runtime.state.fields[0].data.offsetRef, 'SellBy');
    const sellBy = runtime.state.dateOffsets.find((offset) => offset.name === runtime.state.fields[0].data.offsetRef);
    assert.equal(sellBy.default.d, 7);
    runtime.state.fields[0].geom.y += 10;
    const output = rootOf(save(runtime).bytes);
    const actual = fieldState(fieldsOf(output)[0]);
    assert.equal(actual.fldType, 'OffsetDateText');
    assert.equal(actual.dataType, '3');
    assert.equal(actual.staticAttr, '0');
    assert.equal(actual.parseAttr, '1');
    assert.equal(actual.offsetRef, 'SellBy');
    assert.equal(actual.fixedLen, false);
    assert.equal(actual.srcData, null);
    assert.equal(actual.defaultValue, "dd' 'cl:MMM");
    assert.equal(actual.ln, '2');
    assert.deepEqual(
      elements(child(output, 'Header'), 'DateOffset').map((offset) => attr(offset, 'Name')),
      elements(child(rootOf(input), 'Header'), 'DateOffset').map((offset) => attr(offset, 'Name')),
    );
  }
});

test('clean and dirty offset saves preserve Header extensions with nested DateOffset nodes', () => {
  const future = '<Future Keep="exact"><DateOffset Name="SellBy"><UnknownOffsetRule/></DateOffset>' +
    '<OffsetDate SrcOffset="FutureOnly"/></Future>';
  const xml = decodeCiffBytes(fixture('offset-date.ciff'))
    .replace('<VendorBetweenOffsets/>', `${future}<VendorBetweenOffsets/>`);
  const runtime = createProductionCiffRuntime(encodeXml(xml));
  assert.deepEqual(Array.from(runtime.state.dateOffsets, (offset) => offset.name), ['UseBy', 'SellBy']);
  const clean = save(runtime);
  assert.ok(decodeCiffBytes(clean.bytes).includes(future));
  const sourceHeader = child(rootOf(clean.bytes), 'Header');

  const sellBy = runtime.state.dateOffsets.find((offset) => offset.name === 'SellBy');
  sellBy.default.d = 9;
  runtime.state.dateOffsetsDirty = true;
  const edited = save(runtime);
  const output = decodeCiffBytes(edited.bytes);
  const header = child(rootOf(edited.bytes), 'Header');
  assert.ok(output.includes(future));
  assert.deepEqual(elements(header).map((node) => node.name), elements(sourceHeader).map((node) => node.name));
  assert.deepEqual(semantic(child(header, 'Future')), semantic(child(sourceHeader, 'Future')));
  assert.deepEqual(elements(header, 'DateOffset').map((offset) => attr(offset, 'Name')), ['UseBy', 'SellBy']);
  const savedSellBy = elements(header, 'DateOffset').find((offset) => attr(offset, 'Name') === 'SellBy');
  assert.equal(text(child(child(savedSellBy, 'DefaultOffset'), 'Day')), '9');
  assert.equal(fieldState(fieldsOf(rootOf(edited.bytes))[0]).offsetRef, 'SellBy');
});

test('SrcSQL tag-like text and nested source references survive clean and dirty named offset edits', () => {
  const offsets = decodeCiffBytes(fixture('offset-date.ciff'))
    .match(/<DateOffset\b[^>]*>[\s\S]*?<\/DateOffset>/g).join('');
  const sql = 'SELECT \'<DateOffset Name="SqlOnly"><Rule/></DateOffset>\' AS SourceXml\n' +
    'WHERE value = \'<OffsetDate SrcOffset="SqlOnly"/>\'';
  const extension = '<FutureSource><OffsetDate SrcOffset="NestedOnly"/></FutureSource>';
  const xml = decodeCiffBytes(fixture('external-text.ciff'))
    .replace('</Header>', `${offsets}</Header>`)
    .replace(/<SrcSQL>[\s\S]*?<\/SrcSQL>/, `<SrcSQL><![CDATA[${sql}]]></SrcSQL>`)
    .replace('</SrcData>', `${extension}</SrcData>`);
  const runtime = createProductionCiffRuntime(encodeXml(xml));
  assert.equal(runtime.state.fields[0].data.srcData.srcSQL, sql);
  const clean = save(runtime);
  const expectedSource = semantic(child(objectOf(fieldsOf(rootOf(clean.bytes))[0]), 'SrcData'));

  runtime.state.dateOffsets.find((offset) => offset.name === 'SellBy').default.d = 10;
  runtime.state.dateOffsetsDirty = true;
  const edited = save(runtime);
  const output = rootOf(edited.bytes);
  assert.deepEqual(semantic(child(objectOf(fieldsOf(output)[0]), 'SrcData')), expectedSource);
  assert.ok(decodeCiffBytes(edited.bytes).includes(extension));
  assert.equal(createProductionCiffRuntime(edited.bytes).state.fields[0].data.srcData.srcSQL, sql);
});

test('a nested extension DateOffset cannot satisfy a real field offset reference', () => {
  const future = '<Future><DateOffset Name="FutureOnly"><DefaultOffset><Day>1</Day></DefaultOffset>' +
    '<CurrentOffset><Year>2026</Year><Month>9</Month><Day>13</Day></CurrentOffset></DateOffset></Future>';
  const xml = decodeCiffBytes(fixture('offset-date.ciff'))
    .replace('<VendorBetweenOffsets/>', `${future}<VendorBetweenOffsets/>`)
    .replace('SrcOffset="SellBy"', 'SrcOffset="FutureOnly"');
  const runtime = createProductionCiffRuntime(encodeXml(xml));
  const saved = runtime.save();
  assert.equal(saved.prepared.validation.ok, false);
  assert.ok(saved.prepared.validation.structuralErrors.includes('Missing DateOffset target: FutureOnly.'));
  assert.ok(decodeCiffBytes(saved.bytes).includes(future));
});

test('editing Field11 keeps non-numeric XML order, names and explicit zero attributes', () => {
  const runtime = createProductionCiffRuntime(fixture('field-order.ciff'));
  const names = ['Field00', 'Field02', 'Field11', 'Field03'];
  assert.deepEqual(Array.from(runtime.state.fields, (field) => field.name), names);
  runtime.state.fieldByName.get('Field11').geom.x = 450;
  const fields = fieldsOf(rootOf(save(runtime).bytes));
  assert.deepEqual(fields.map((field) => attr(field, 'Name')), names);
  assert.equal(text(child(fields[2], 'X')), '450');
  assert.equal(attr(objectOf(fields[1]), 'Static'), '0');
  assert.equal(attr(objectOf(fields[1]), 'Parse'), '0');
  assert.deepEqual(fields.map((field) => fieldState(field).ln), [null, '1', null, '3']);
});

test('new fields append in insertion order without renumbering loaded fields', () => {
  const runtime = createProductionCiffRuntime(fixture('field-order.ciff'));
  for (const name of ['Field12', 'Field07']) {
    const added = JSON.parse(JSON.stringify(runtime.state.fields[0]));
    added.name = name;
    added.sourceName = null;
    runtime.state.fields.push(added);
    runtime.state.fieldByName.set(name, added);
  }
  const expectedNames = ['Field00', 'Field02', 'Field11', 'Field03', 'Field12', 'Field07'];
  const saved = save(runtime);
  assert.deepEqual(fieldsOf(rootOf(saved.bytes)).map((field) => attr(field, 'Name')), expectedNames);
  const reopened = createProductionCiffRuntime(saved.bytes);
  assert.deepEqual(Array.from(reopened.state.fields, (field) => field.name), expectedNames);
});

test('overlapping explicit field renames preserve each original XML block and its position', () => {
  const bytes = fixture('field-order.ciff');
  const runtime = createProductionCiffRuntime(bytes);
  const renames = new Map([['Field00', 'Field02'], ['Field02', 'Field11'], ['Field11', 'Field00']]);
  runtime.state.fields.forEach((field) => { field.name = renames.get(field.name) ?? field.name; });
  runtime.state.fieldByName = new Map(runtime.state.fields.map((field) => [field.name, field]));
  const expectedFields = fieldsOf(rootOf(bytes)).map(semantic);
  expectedFields.forEach((field) => {
    const name = field.attributes.find((attribute) => attribute.name === 'Name');
    name.value = renames.get(name.value) ?? name.value;
  });
  const saved = save(runtime);
  assert.deepEqual(fieldsOf(rootOf(saved.bytes)).map(semantic), expectedFields);
  assert.deepEqual(fieldsOf(rootOf(save(runtime).bytes)).map(semantic), expectedFields);
});

test('unknown nested X/Ln/Default/Pitch do not shadow the actual field configuration', () => {
  const unknown = '<VendorShadow><X>9999</X><Ln>9</Ln><CalcData><![CDATA[shadow preview]]></CalcData>' +
    '<Data><Object Static="1"><DataType>6</DataType><Default><![CDATA[shadow default]]></Default>' +
    '<FixedLen/></Object></Data><Text><Font><Pitch>40</Pitch></Font></Text></VendorShadow>';
  const input = encodeXml(decodeCiffBytes(fixture('constant-text.ciff'))
    .replace('<FldType>FixedText</FldType>', `${unknown}<FldType>FixedText</FldType>`));
  const runtime = createProductionCiffRuntime(input);
  const field = runtime.state.fields[0];
  assert.equal(field.geom.x, 2683);
  assert.equal(field.data.defaultValue, 'Use By');
  assert.equal(field.data.dataType, 0);
  assert.equal(field.data.staticAttr, null);
  assert.equal(field.data.fixedLen, false);
  assert.equal(field.calcData, 'Use By');
  assert.equal(field.text.pitch, 8);
  field.geom.x += 1;
  const output = fieldsOf(rootOf(save(runtime).bytes))[0];
  const expected = semantic(fieldsOf(rootOf(input))[0]);
  expected.children.find((node) => node.name === 'X').children = [{ type: 'text', value: '2684' }];
  assert.deepEqual(semantic(output), expected);
  assert.equal(child(output, 'Ln'), null);
});

for (const action of ['rename', 'delete']) {
  test(`Undo/Redo after a saved field ${action} retains raw XML, source order and unknown properties`, () => {
    const bytes = fixture('field-order.ciff');
    const sourceSub = semantic(child(rootOf(bytes), 'SubImage'));
    const runtime = createProductionCiffRuntime(bytes);
    // UI rendering is outside this harness; exercise production history/model
    // operations and the full save pipeline, replacing only UI effects.
    runtime.context.renderAll = () => {};
    runtime.context.updateUndoRedoButtons = () => {};
    runtime.context.pushHistory(true);
    runtime.context.pushHistory();
    const edited = runtime.state.fieldByName.get('Field11');
    if (action === 'rename') {
      edited.name = 'Field21';
      runtime.state.fieldByName.delete('Field11');
      runtime.state.fieldByName.set('Field21', edited);
    } else {
      runtime.state.fields = runtime.state.fields.filter((field) => field !== edited);
      runtime.state.fieldByName.delete('Field11');
    }
    const editedSave = save(runtime);
    const editedSub = semantic(child(rootOf(editedSave.bytes), 'SubImage'));

    runtime.context.undo();
    const restoredSave = save(runtime);
    const reopened = createProductionCiffRuntime(restoredSave.bytes);
    assert.deepEqual(semantic(child(rootOf(restoredSave.bytes), 'SubImage')), sourceSub);
    assert.deepEqual(
      Array.from(reopened.state.fields, (field) => field.name),
      ['Field00', 'Field02', 'Field11', 'Field03'],
    );
    assert.deepEqual(semantic(child(rootOf(save(reopened).bytes), 'SubImage')), sourceSub);

    runtime.context.redo();
    assert.deepEqual(semantic(child(rootOf(save(runtime).bytes), 'SubImage')), editedSub);
  });
}

for (const name of FIXTURES.slice(0, 4)) {
  test(`${name}: the imported semantic model can serialize a new field without inventing optional properties`, () => {
    const runtime = createProductionCiffRuntime(fixture(name));
    const sourceField = fieldsOf(rootOf(fixture(name)))[0];
    const newField = JSON.parse(JSON.stringify(runtime.state.fields[0]));
    newField.sourceName = null;
    newField.name = 'NewField';
    const outputField = parseXml(runtime.context.buildFieldXmlOneLine(newField));
    const expected = fieldState(sourceField);
    expected.name = 'NewField';
    // Future source-only attributes are tested by the lossless path above;
    // canonical generation must retain the understood source values.
    const sourceDataContent = (state) => state.srcData?.children
      .filter((node) => ['ConnStr', 'SrcSQL'].includes(node.name))
      .map((node) => ({ name: node.name, children: node.children })) ?? null;
    const actual = fieldState(outputField);
    actual.srcData = sourceDataContent(actual);
    expected.srcData = sourceDataContent(expected);
    assert.deepEqual(actual, expected);
  });
}

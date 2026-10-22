const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const { parseXml } = require('../scripts/compare-ciff-structure.cjs');
const { createProductionCiffRuntime, decodeCiffBytes } = require('./helpers/ciff-production-harness.cjs');

const fixture = fs.readFileSync(path.join(__dirname, 'fixtures/conservative/constant-text.ciff'));
const original = decodeCiffBytes(fixture);
const encode = xml => Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(xml, 'utf16le')]);
const children = (node, name) => (node?.children || []).filter(item => item.type === 'element' && (!name || item.name === name));
const child = (node, name) => children(node, name)[0] || null;
const text = node => (node?.children || []).map(item => item.type === 'element' ? text(item) : (item.value || '')).join('');
const attr = (node, name) => node.attributes.find(item => item.name === name)?.value ?? null;
const fieldOf = xml => child(child(parseXml(xml), 'SubImage'), 'Field');
const objectOf = xml => child(child(fieldOf(xml), 'Data'), 'Object');

function save(runtime) {
  const result = runtime.save(new Date(2026, 9, 22, 12, 34, 56));
  assert.equal(result.prepared.validation.ok, true, JSON.stringify(result.prepared.validation));
  return { ...result, xml: decodeCiffBytes(result.bytes) };
}

function newFieldRuntime(overrides = {}) {
  const runtime = createProductionCiffRuntime(fixture);
  const field = runtime.state.fields[0];
  Object.assign(field, { sourceName: null, name: 'NewField', ln: 0, calcData: '', ...overrides });
  field.data = {
    ...field.data, dataType: 0, defaultValue: '', maxChars: 0, fixedLen: false,
    staticAttr: '1', parseAttr: '0', referenceAttr: '', srcData: null,
    textEntryMode: 'fixed', hasVarText: false, userEnterData: '', mask: '',
    locale: 'EN-GB', calendar: 'CAL_GREGORIAN', encryption: '',
  };
  field.text = { face: 'Arial', family: 32, pitch: 13, pitchResolution: 1,
    xMag: 100, yMag: 100, ttSize: 1, txtDir: 0, charSpace: 0 };
  runtime.state.fieldByName = new Map([[field.name, field]]);
  return runtime;
}

test('new empty text matches native omission defaults without losing required geometry or Font', () => {
  const runtime = newFieldRuntime();
  const result = save(runtime);
  const field = fieldOf(result.xml);
  assert.deepEqual(children(field).map(item => item.name), ['FldType', 'X', 'Y', 'W', 'H', 'Data', 'Text']);
  assert.deepEqual(objectOf(result.xml).attributes, [{ name: 'Reference', value: '' }]);
  assert.deepEqual(children(objectOf(result.xml)).map(item => item.name), ['DataType']);
  assert.ok(child(child(field, 'Text'), 'Font'));
  assert.equal(children(child(child(field, 'Text'), 'Font')).length, 0);
  assert.equal(createProductionCiffRuntime(result.bytes).state.fields[0].text.defaultPitch, 13);
});

test('explicit empty LoggedField is distinct from the omitted Not Logged default; imports retain either state', () => {
  for (const value of [undefined, 'Not Logged', '', null, 'AuditValue']) {
    const runtime = newFieldRuntime();
    runtime.state.fields[0].loggedField = value;
    const first = save(runtime);
    const logged = child(fieldOf(first.xml), 'LoggedField');
    if (value === undefined || value === 'Not Logged') assert.equal(logged, null);
    else assert.equal(text(logged), value ?? '');
    const second = save(createProductionCiffRuntime(first.bytes));
    assert.deepEqual(child(fieldOf(second.xml), 'LoggedField')?.children ?? null, logged?.children ?? null);
  }
});

test('FixedLen and empty VarText stay meaningful while default padding and empty UserEnterData are omitted', () => {
  const runtime = newFieldRuntime();
  Object.assign(runtime.state.fields[0].data, {
    textEntryMode: 'user', hasVarText: true, fixedLen: true, maxChars: 6,
    padChar: ' ', padMode: 'Left', staticAttr: '0',
  });
  const first = save(runtime);
  const object = objectOf(first.xml);
  assert.ok(child(object, 'FixedLen'));
  assert.ok(child(object, 'VarText'));
  assert.equal(children(child(object, 'FixedLen')).length, 0);
  assert.equal(children(child(object, 'VarText')).length, 0);
  assert.equal(child(object, 'Default'), null);
  assert.equal(text(child(fieldOf(first.xml), 'CalcData')), ' '.repeat(6));
  const reopened = createProductionCiffRuntime(first.bytes);
  assert.equal(reopened.state.fields[0].data.fixedLen, true);
  assert.equal(reopened.state.fields[0].data.hasVarText, true);
  assert.ok(child(objectOf(save(reopened).xml), 'VarText'));
});

test('new nondefault font, padding and partial source selection are retained', () => {
  const runtime = newFieldRuntime();
  const field = runtime.state.fields[0];
  field.text.pitch = 10;
  field.text.xMag = 125;
  Object.assign(field.data, { defaultValue: 'ABC', maxChars: 7, fixedLen: true, padChar: '0', padMode: 1 });
  const xml = runtime.context.buildFieldXmlOneLine(field);
  assert.match(xml, /<Pitch>10<\/Pitch><XMag>125<\/XMag>/);
  assert.match(xml, /<FixedLen><PadChar><!\[CDATA\[0\]\]><\/PadChar><PadMode>Right<\/PadMode><\/FixedLen>/);
  assert.equal(runtime.context.buildCiffSrcFieldXml({ srcField: 'SRC', startChar: 0, noOfChars: 0, selectMode: 0 }), '<SrcField SrcFieldName="SRC"/>');
  assert.equal(runtime.context.buildCiffSrcFieldXml({ srcField: 'SRC', startChar: 2, noOfChars: 3, selectMode: 1 }),
    '<SrcField SrcFieldName="SRC"><StartChar>2</StartChar><NoOfChars>3</NoOfChars><SelectMode>1</SelectMode></SrcField>');
});

test('a new external source always has SrcSQL, and omits an empty ConnStr', () => {
  for (const source of [{}, { connStr: '', srcSQL: null }, { connStr: null, srcSQL: '' }]) {
    const runtime = newFieldRuntime();
    Object.assign(runtime.state.fields[0].data, { dataType: 6, srcData: source });
    const xml = runtime.context.buildFieldXmlOneLine(runtime.state.fields[0]);
    assert.match(xml, /<SrcData><SrcSQL><!\[CDATA\[\]\]><\/SrcSQL><\/SrcData>/);
    assert.doesNotMatch(xml, /<ConnStr>/);
  }
});

test('editing only ConnStr inserts mandatory empty SrcSQL without canonicalizing untouched imported source blocks', () => {
  for (const source of ['<SrcData Vendor="keep"/>', '<SrcData Vendor="keep"><VendorSource/></SrcData>',
    '<SrcData Vendor="keep"><ConnStr><![CDATA[db-before]]></ConnStr><VendorSource/></SrcData>']) {
    const xml = original.replace('<DataType>0</DataType>', '<DataType>6</DataType>')
      .replace('</Object>', source + '</Object>');
    const runtime = createProductionCiffRuntime(encode(xml));
    assert.equal(runtime.state.fields[0].data.srcData.srcSQL, null);
    const clean = save(runtime);
    assert.ok(clean.xml.includes(source), 'no-op import must retain the original source block');
    runtime.state.fields[0].data.srcData.connStr = 'db-after';
    const edited = child(objectOf(save(runtime).xml), 'SrcData');
    assert.equal(attr(edited, 'Vendor'), 'keep');
    assert.equal(text(child(edited, 'ConnStr')), 'db-after');
    assert.ok(child(edited, 'SrcSQL'), 'an edited source must include empty SrcSQL');
    assert.equal(text(child(edited, 'SrcSQL')), '');
    assert.equal(!!child(edited, 'VendorSource'), source.includes('<VendorSource/>'));
  }
});

test('native Locale/Calendar/Encryption serialize conditionally and survive save/reopen without guessing UI locale', () => {
  const runtime = newFieldRuntime();
  Object.assign(runtime.state.fields[0].data, { defaultValue: 'ABC', locale: 'FR-FR', calendar: 'CAL_HIJRI', encryption: 'Custom' });
  let result = save(runtime);
  assert.deepEqual(children(objectOf(result.xml)).map(item => item.name), ['DataType', 'Locale', 'Calendar', 'Encryption', 'Default']);
  const reopened = createProductionCiffRuntime(result.bytes);
  assert.equal(reopened.state.fields[0].data.encryption, 'Custom');
  Object.assign(reopened.state.fields[0].data, { locale: 'EN-GB', calendar: 'CAL_GREGORIAN', encryption: '', dateLocale: 'ru' });
  result = save(reopened);
  for (const tag of ['Locale', 'Calendar', 'Encryption']) assert.equal(child(objectOf(result.xml), tag), null, tag);
  assert.equal(createProductionCiffRuntime(result.bytes).state.fields[0].data.locale, null);
});

test('imported explicit default metadata remains verbatim until its native model value is edited', () => {
  const xml = original.replace('<DataType>0</DataType>', '<DataType>0</DataType><Locale>EN-GB</Locale><Calendar>CAL_GREGORIAN</Calendar><Encryption/>');
  const first = save(createProductionCiffRuntime(encode(xml)));
  assert.equal(first.xml.match(/<Field\b[\s\S]*?<\/Field>/)[0], xml.match(/<Field\b[\s\S]*?<\/Field>/)[0]);
  const runtime = createProductionCiffRuntime(first.bytes);
  runtime.state.fields[0].data.locale = 'FR-FR';
  assert.equal(text(child(objectOf(save(runtime).xml), 'Locale')), 'FR-FR');
});

test('CounterText omits default scalar values but retains empty ClrStCntType', () => {
  const runtime = newFieldRuntime({ fldType: 'CounterText' });
  Object.assign(runtime.state.fields[0].data, { dataType: 4, counter: {
    noOfChars: 4, startVal: '0', endVal: '9999', stepSize: 1, significance: 0, clrStCntType: '',
  } });
  const xml = runtime.context.buildFieldXmlOneLine(runtime.state.fields[0]);
  const object = objectOf(xml.includes('<ImageDesign') ? xml : `<ImageDesign><SubImage>${xml}</SubImage></ImageDesign>`);
  const sub = child(child(object, 'CounterText'), 'SubCnt');
  assert.deepEqual(children(sub).map(item => item.name), ['NoOfChars', 'ClrStCntType']);
});

function dataMatrixXml() {
  const object = (index, value) => `<Object${index ? ` Index="${index}"` : ''} Reference="ref-${value}" Static="1" Parse="0" EqRef="7" Vendor="${value}">` +
    `<DataType>0</DataType><Locale>EN-GB</Locale><MaxNoOfChars>11</MaxNoOfChars><Default><![CDATA[${value}]]></Default>` +
    `<VendorBefore><Default>opaque-${value}</Default></VendorBefore></Object>`;
  const field = '<Field Name="DM"><FldType>Barcode</FldType><CLSID>{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}</CLSID>' +
    '<X>0</X><Y>0</Y><W>1100</W><H>1100</H><CalcData><![CDATA[AABB]]></CalcData><Data VendorData="kept">' +
    object(0, 'AA') + '<VendorDataSibling Flag="kept"/>' + object(1, 'BB') + '</Data><Barcode><BcH>1100</BcH><HR><HRFont/></HR>' +
    '<QuietMargin>0</QuietMargin><DataMatrix><ModuleSize>50</ModuleSize><SymbolSize>22X22</SymbolSize></DataMatrix></Barcode></Field>';
  return original.replace(/<Field\b[\s\S]*?<\/Field>/, field);
}

test('DM structural reorder/add/remove retains original Object metadata and opaque Data siblings across repeated saves', () => {
  const runtime = createProductionCiffRuntime(encode(dataMatrixXml()));
  const dm = runtime.state.fields[0].barcode.dataMatrix;
  assert.deepEqual(Array.from(dm.segments, segment => segment.sourceObjectIndex), [0, 1]);
  dm.segments = [dm.segments[1], dm.segments[0], { dataType: 0, defaultValue: 'CC', srcField: null, sourceObjectIndex: null }];
  dm.structureDirty = true;
  let result = save(runtime);
  let data = child(fieldOf(result.xml), 'Data');
  let objects = children(data, 'Object');
  assert.equal(attr(data, 'VendorData'), 'kept');
  assert.ok(child(data, 'VendorDataSibling'));
  assert.deepEqual(objects.map(item => attr(item, 'Vendor')), ['BB', 'AA', null]);
  assert.equal(attr(objects[0], 'Reference'), 'ref-BB');
  assert.equal(attr(objects[0], 'Static'), '1', 'unchanged imported explicit defaults stay intact');
  assert.equal(attr(objects[0], 'Parse'), '0');
  assert.equal(attr(objects[0], 'EqRef'), '7');
  assert.equal(text(child(objects[0], 'MaxNoOfChars')), '11');
  assert.equal(text(child(objects[0], 'VendorBefore')), 'opaque-BB');
  assert.deepEqual(Array.from(runtime.state.fields[0].barcode.dataMatrix.segments, segment => segment.sourceObjectIndex), [0, 1, 2]);
  const again = save(runtime);
  assert.deepEqual(children(child(fieldOf(again.xml), 'Data')), children(data));
  const current = runtime.state.fields[0].barcode.dataMatrix;
  current.segments = [current.segments[1]];
  current.structureDirty = true;
  result = save(runtime);
  objects = children(child(fieldOf(result.xml), 'Data'), 'Object');
  assert.equal(objects.length, 1);
  assert.equal(attr(objects[0], 'Vendor'), 'AA');
  assert.equal(attr(objects[0], 'Index'), null);
  assert.equal(text(child(objects[0], 'VendorBefore')), 'opaque-AA');
  assert.equal(text(child(fieldOf(result.xml), 'CalcData')), 'AA');
});

test('zero Image/Max dimensions stay independent and YRes edits serialize and validate separately', () => {
  const xml = original.replace(/<Field\b[\s\S]*?<\/Field>/, '')
    .replace(/<ImageWidth>[^<]*<\/ImageWidth>/, '<ImageWidth>0</ImageWidth>')
    .replace(/<ImageHeight>[^<]*<\/ImageHeight>/, '<ImageHeight>0</ImageHeight>')
    .replace(/<MaxImageWidth>[^<]*<\/MaxImageWidth>/, '<MaxImageWidth>0</MaxImageWidth>');
  const runtime = createProductionCiffRuntime(encode(xml));
  runtime.state.subImage.yRes = 0.08;
  const result = save(runtime);
  const sub = child(child(parseXml(result.xml), 'SubImage'), 'SubHeader');
  assert.equal(text(child(sub, 'ImageWidth')), '0');
  assert.equal(text(child(sub, 'ImageHeight')), '0');
  assert.equal(text(child(sub, 'MaxImageWidth')), '0');
  assert.equal(text(child(sub, 'MaxImageHeight')), text(child(child(parseXml(xml), 'SubImage'), 'SubHeader')?.children.find(item => item.name === 'MaxImageHeight')));
  assert.equal(text(child(sub, 'YRes')), '0.080000');
  assert.equal(createProductionCiffRuntime(result.bytes).state.subImage.yRes, 0.08);
  runtime.state.subImage.yRes = -1;
  assert.equal(runtime.save().prepared.validation.ok, false);
});

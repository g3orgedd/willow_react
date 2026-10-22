'use strict';

const assert = require('node:assert/strict');
const test = require('node:test');
const { createProductionCiffRuntime, decodeCiffBytes } = require('./helpers/ciff-production-harness.cjs');

const frozenNow = new Date(2026, 9, 21, 12, 34, 56);
const cdata = (value) => `<![CDATA[${value}]]>`;

function textField(name, type, value, object) {
  return `<Field Name="${name}"><FldType>${type}</FldType><X>0</X><Y>0</Y><W>100</W><H>100</H>` +
    `<CalcData>${cdata(value)}</CalcData><Data>${object}</Data><Text><Font><Pitch>8</Pitch></Font></Text></Field>`;
}

function matrixField(name, value, objects) {
  return `<Field Name="${name}"><FldType>Barcode</FldType><CLSID>{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}</CLSID>` +
    `<X>100</X><Y>100</Y><W>924</W><H>924</H><CalcData>${cdata(value)}</CalcData><Data>${objects}</Data>` +
    '<Barcode><BcH>924</BcH><HR><HRFont/></HR><QuietMargin>0</QuietMargin>' +
    '<DataMatrix><ModuleSize>42</ModuleSize><SymbolSize>22X22</SymbolSize></DataMatrix></Barcode></Field>';
}

function subImage(fields, reference = '1') {
  return `<SubImage ImageReference="${reference}"><SubHeader><ImageWidth>1600</ImageWidth><ImageHeight>1600</ImageHeight>` +
    '<MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>1600</MaxImageHeight><XRes>0.120000</XRes></SubHeader>' +
    fields + '</SubImage>';
}

function runtimeFor(images) {
  const text = '<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    '<ImageDesign Version="23" xml:space="default"><Header DesignedFor="DataFlex 6330(53mm) - Continuous"/>' +
    images + '<GenericSettings/></ImageDesign>';
  return createProductionCiffRuntime(Buffer.concat([Buffer.from([0xFF, 0xFE]), Buffer.from(text, 'utf16le')]));
}

function readSaved(runtime, result) {
  const xml = decodeCiffBytes(result.bytes);
  const doc = new runtime.context.DOMParser().parseFromString(xml, 'text/xml');
  const fields = new Map(doc.querySelectorAll('SubImage > Field').map((field) => [field.getAttribute('Name'), field]));
  const token = doc.querySelector('Header > ClStVersionInfo').textContent;
  const decoded = runtime.context.decodeClStVersionInfo(token, { fieldCount: fields.size });
  return { xml, fields, decoded };
}

function assertValid(result) {
  assert.equal(result.prepared.validation.ok, true, JSON.stringify(result.prepared.validation));
}

test('subsequent SubImage CalculatedData follows native normalization of literal and character-reference CR', () => {
  const first = textField('FIRST', 'FixedText', 'first', '<Object><DataType>0</DataType><Default>first</Default></Object>');
  for (const [xmlValue, expected] of [['<![CDATA[A\r\nB\rC]]>', 'A\nB\nC'], ['A&#13;B', 'A\nB']]) {
    const second = textField('SECOND', 'StaticGraphic', 'replace', '<Object><DataType>0</DataType><Default/></Object>')
      .replace('<![CDATA[replace]]>', xmlValue);
    const runtime = runtimeFor(subImage(first) + subImage(second, '2'));
    const saved = runtime.save(frozenNow, { clstOptions: { mask: 2 } });
    assertValid(saved);
    assert.equal(readSaved(runtime, saved).decoded.tagData, expected);
  }
});

test('primary imported CalcData, Default and UserEnterData normalize character-reference CR like original XML loader', () => {
  const cases = [
    { object: '<Object><DataType>0</DataType><Default>ignored</Default></Object>', calc: 'A&#13;B', value: 'A\nB' },
    { object: '<Object Static="0"><DataType>0</DataType><Default>D&#13;E</Default></Object>', calc: 'stale', value: 'D\nE' },
    { object: '<Object Static="0"><DataType>0</DataType><Default>ignored</Default><VarText><UserEnterData>U&#13;V</UserEnterData></VarText></Object>', calc: 'stale', value: 'U\nV' }
  ];
  for (const { object, calc, value } of cases) {
    const field = textField('RAW', 'FixedText', 'replace', object).replace('<![CDATA[replace]]>', calc);
    const runtime = runtimeFor(subImage(field));
    const result = runtime.save(frozenNow, { clstOptions: { mask: 1 } });
    assertValid(result);
    const saved = readSaved(runtime, result);
    assert.equal(saved.fields.get('RAW').querySelector(':scope > CalcData').textContent.replace(/\r\n?/g, '\n'), value);
    assert.equal(saved.decoded.tagData, value);
  }
});

test('production save uses partial SrcField and padded segment values in both XML and ClSt', () => {
  const source = textField('SOURCE', 'FixedText', 'ABCDE', '<Object><DataType>0</DataType><Default>ABCDE</Default></Object>');
  const objects = '<Object Static="0"><DataType>5</DataType><Default>old</Default><SrcField SrcFieldName="SOURCE">' +
    '<StartChar>1</StartChar><NoOfChars>3</NoOfChars></SrcField></Object>' +
    '<Object Index="1" Static="0"><DataType>0</DataType><MaxNoOfChars>5</MaxNoOfChars><Default>AB</Default>' +
    '<FixedLen><PadChar>0</PadChar><PadMode>Right</PadMode></FixedLen></Object>';
  const runtime = runtimeFor(subImage(source + matrixField('DM', 'old', objects)));
  const result = runtime.save(frozenNow, { clstOptions: { mask: 2 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(saved.fields.get('DM').querySelector(':scope > CalcData').textContent, 'BCD000AB');
  assert.equal(saved.decoded.tagData, 'BCD000AB');
  const data = saved.fields.get('DM').querySelectorAll(':scope > Data > Object');
  assert.equal(data[0].querySelector(':scope > Default').textContent, 'BCD');
  assert.equal(data[1].querySelector(':scope > Default').textContent, 'AB');
  assert.equal(data[0].querySelector(':scope > SrcField > StartChar').textContent, '1');
});

test('production save freezes the dynamic formatter once for field, DataMatrix and ClSt', () => {
  const source = textField('CLOCK', 'TimeText', 'stale', '<Object Static="0" Parse="1"><DataType>1</DataType><Default>HH:mm</Default></Object>');
  const matrix = matrixField('DM', 'stale', '<Object><DataType>5</DataType><Default>stale</Default><SrcField SrcFieldName="CLOCK"/></Object>');
  const runtime = runtimeFor(subImage(source + matrix));
  let calls = 0;
  const callSites = [];
  runtime.context.getDynamicFieldValue = (field) => {
    if (field.fldType !== 'TimeText') return null;
    calls += 1;
    callSites.push(new Error('formatter').stack);
    return '12:34';
  };
  const result = runtime.save(frozenNow, { clstOptions: { mask: 2 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(calls, 1, callSites.join('\n'));
  assert.equal(saved.fields.get('CLOCK').querySelector(':scope > CalcData').textContent, '12:34');
  assert.equal(saved.fields.get('DM').querySelector(':scope > CalcData').textContent, '12:34');
  assert.equal(saved.decoded.tagData, '12:34');
});

test('production save retains pre-XML-filter raw control characters in ClSt', () => {
  const runtime = runtimeFor(subImage(textField('RAW', 'StaticGraphic', 'old', '<Object><DataType>0</DataType><Default/></Object>')));
  runtime.state.fields[0].calcData = 'A\u0001B\u001DC';
  const result = runtime.save(frozenNow, { clstOptions: { mask: 1 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(saved.fields.get('RAW').querySelector(':scope > CalcData').textContent, 'ABC');
  assert.equal(saved.decoded.tagData, 'A\u0001B\u001DC');
});

test('production save selects actual stored data from a subsequent SubImage', () => {
  const first = textField('FIRST', 'FixedText', 'FIRST', '<Object><DataType>0</DataType><Default>FIRST</Default></Object>');
  const second = textField('SECOND', 'FixedText', 'SECOND-IMAGE', '<Object><DataType>0</DataType><Default>SECOND-IMAGE</Default></Object>');
  const runtime = runtimeFor(subImage(first) + subImage(second, '2'));
  const result = runtime.save(frozenNow, { clstOptions: { mask: 2 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(saved.decoded.maskHex, '00000002');
  assert.equal(saved.decoded.tagData, 'SECOND-IMAGE');
  assert.equal(saved.fields.get('SECOND').querySelector(':scope > CalcData').textContent, 'SECOND-IMAGE');
});

test('programmatically edited NUL values follow native CalculatedData setter semantics', () => {
  const runtime = runtimeFor(subImage(textField('RAW', 'StaticGraphic', 'old', '<Object><DataType>0</DataType><Default/></Object>')));
  runtime.state.fields[0].calcData = 'AB\0CD';
  const result = runtime.save(frozenNow, { clstOptions: { mask: 1 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(saved.fields.get('RAW').querySelector(':scope > CalcData').textContent, 'AB');
  assert.equal(saved.decoded.tagData, 'AB');
});

test('empty PadChar from native XML remains character zero rather than the absent space default', () => {
  const field = textField('PAD', 'FixedText', 'AB', '<Object Static="0"><DataType>0</DataType>' +
    '<MaxNoOfChars>5</MaxNoOfChars><Default>AB</Default><FixedLen><PadChar/></FixedLen></Object>');
  const runtime = runtimeFor(subImage(field));
  const result = runtime.save(frozenNow, { clstOptions: { mask: 1 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(saved.fields.get('PAD').querySelector(':scope > CalcData').textContent, 'AB');
  assert.equal(saved.decoded.tagData, 'AB');
});

test('direct dynamic DataMatrix objects share one frozen calculation with validation', () => {
  const field = matrixField('DM', 'stale', '<Object Static="0" Parse="1"><DataType>1</DataType><Default>HH:mm</Default></Object>');
  const runtime = runtimeFor(subImage(field));
  let calls = 0;
  runtime.context.getDynamicFieldValue = () => { calls += 1; return '12:34'; };
  const result = runtime.save(frozenNow, { clstOptions: { mask: 1 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(calls, 1);
  assert.equal(saved.fields.get('DM').querySelector(':scope > CalcData').textContent, '12:34');
  assert.equal(saved.decoded.tagData, '12:34');
});

test('unsupported direct DataMatrix calendar format preserves stored CalcData and its token input', () => {
  const field = matrixField('DM', '109', '<Object Static="0" Parse="1"><DataType>2</DataType><Default>cl:jj</Default></Object>');
  const runtime = runtimeFor(subImage(field));
  runtime.context.getDynamicFieldValue = () => { throw new Error('Unsupported calendar formatter'); };
  const result = runtime.save(frozenNow, { clstOptions: { mask: 1 } });
  assertValid(result);
  const saved = readSaved(runtime, result);
  assert.equal(saved.fields.get('DM').querySelector(':scope > CalcData').textContent, '109');
  assert.equal(saved.fields.get('DM').querySelector(':scope > Data > Object > Default').textContent, 'cl:jj');
  assert.equal(saved.decoded.tagData, '109');
});

'use strict';

const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const { createProductionCiffRuntime } = require('./helpers/ciff-production-harness.cjs');
const { createFontRendererService } = require('../electron/fonts.cjs');

const now = new Date(2026, 9, 22, 12, 34, 56);
const nativeModule = path.join(__dirname, '../public/modules/04-native-text-preview.js');
function encode(xml) { return Buffer.concat([Buffer.from([255, 254]), Buffer.from(xml, 'utf16le')]); }
function fieldXml({ name = 'SN', value = '0000000000', max = 12, padding = '', staticValue = '0', variable = true } = {}) {
  return `<Field Name="${name}"><FldType>FixedText</FldType><Displayed>0</Displayed><X>2100</X><Y>100</Y>` +
    '<W>1917</W><H>392</H><CalcData><![CDATA[' + value + ']]></CalcData>' +
    `<Data><Object Static="${staticValue}" Reference=""><DataType>0</DataType><MaxNoOfChars>${max}</MaxNoOfChars>` +
    `<Default><![CDATA[${value}]]></Default><FixedLen>${padding}</FixedLen>` +
    (variable ? `<VarText><UserEnterData><![CDATA[${value}]]></UserEnterData></VarText>` : '') +
    '</Object></Data><Text><Font><Pitch>10</Pitch><XMag>100</XMag></Font></Text></Field>';
}
function runtimeFor(fields = fieldXml()) {
  const xml = '<?xml version="1.0" encoding="UTF-16"?>\r\n<ImageDesign Version="23" xml:space="default">' +
    '<Header DesignedFor="DataFlex 6330(53mm) - Continuous"/><SubImage ImageReference="1"><SubHeader FormatName="Default">' +
    '<ImageWidth>1600</ImageWidth><ImageHeight>2000</ImageHeight><MaxImageWidth>2000</MaxImageWidth><MaxImageHeight>3000</MaxImageHeight>' +
    '<XRes>0.120000</XRes></SubHeader>' + fields + '</SubImage><GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>';
  return createProductionCiffRuntime(encode(xml));
}
function installNative(runtime, render = async (request) => ({ width: request.text.length * 12, height: 47, outlinePath: '' })) {
  const requests = [];
  runtime.context.glyphFonts = { render: (request) => { requests.push(request); return render(request); } };
  runtime.context.requestAnimationFrame = () => {};
  vm.runInContext(fs.readFileSync(nativeModule, 'utf8'), runtime.context, { filename: nativeModule });
  return requests;
}

test('the parsed SN preview and native geometry use padded CalcData while inputs and saved defaults stay raw', async () => {
  const runtime = runtimeFor();
  const { context, state } = runtime;
  const field = state.fieldByName.get('SN');
  const input = '0000000000';
  const expected = input + '  ';
  assert.equal(context.getFieldDisplayValue(field, now), input);
  assert.equal(context.getFieldDisplayValue(field, now).length, 10, 'the inspector character count remains the input length');
  assert.equal(context.makePreviewText(field, now), expected);
  const prepared = context.prepareCiffCalculatedData(state.fields, now, { fieldByName: state.fieldByName });
  assert.equal(context.makePreviewText(field, now), prepared.get(field));
  const requests = installNative(runtime);
  field._nativeTextGeometryDirty = true;
  await context.ensureNativeTextGeometry(state.fields, now);
  assert.equal(requests.at(-1).text, expected);
  assert.equal(field.geom.w, 1200);
  assert.equal(field.printed, false);
  assert.deepEqual(JSON.parse(JSON.stringify(context.calculateImageBounds(state.fields))), { width: 0, height: 0 });
  const saved = runtime.save(now);
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  const reopened = createProductionCiffRuntime(saved.bytes);
  const sn = reopened.state.fieldByName.get('SN');
  assert.equal(sn.data.defaultValue, input);
  assert.equal(sn.data.userEnterData, input);
  assert.equal(sn.data.maxChars, 12);
  assert.equal(sn.calcData, expected);
  assert.equal(sn.geom.w, 1200);
});

test('native text preview follows the shared space/zero/left/right padding and static-ignore rules', async () => {
  const cases = [
    { name: 'spaces', expected: 'AB    ' },
    { name: 'zero-right', padding: '<PadChar>0</PadChar><PadMode>Right</PadMode>', expected: '0000AB' },
    { name: 'zero-left', padding: '<PadChar>0</PadChar><PadMode>Left</PadMode>', expected: 'AB0000' },
    { name: 'static-no-padding', staticValue: '1', variable: false, expected: 'AB' },
  ];
  for (const item of cases) {
    const runtime = runtimeFor(fieldXml({ ...item, value: 'AB', max: 6 }));
    const field = runtime.state.fields[0];
    const requests = installNative(runtime);
    field._nativeTextGeometryDirty = true;
    assert.equal(runtime.context.makePreviewText(field, now), item.expected, item.name);
    await runtime.context.ensureNativeTextGeometry(runtime.state.fields, now);
    assert.equal(requests.at(-1).text, item.expected, item.name);
    assert.equal(field.data.defaultValue, 'AB');
    const values = runtime.context.prepareCiffCalculatedData(runtime.state.fields, now);
    assert.equal(requests.at(-1).text, values.get(field));
  }
});

test('partial SrcField text and DataMatrix select from the padded source used by native preview and XML', () => {
  const selected = '<Field Name="PART"><FldType>FixedText</FldType><Displayed>0</Displayed><X>0</X><Y>0</Y><W>400</W><H>392</H>' +
    '<Data><Object Static="0"><DataType>5</DataType><Default>old</Default><SrcField SrcFieldName="SN"><StartChar>8</StartChar><NoOfChars>4</NoOfChars></SrcField></Object></Data><Text><Font><Pitch>10</Pitch></Font></Text></Field>';
  const matrix = '<Field Name="DM"><FldType>Barcode</FldType><CLSID>{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}</CLSID><X>0</X><Y>0</Y><W>1100</W><H>1100</H><Data>' +
    '<Object><DataType>5</DataType><Default>old</Default><SrcField SrcFieldName="SN"><StartChar>8</StartChar><NoOfChars>4</NoOfChars></SrcField></Object>' +
    '<Object Index="1"><DataType>5</DataType><Default>old</Default><SrcField SrcFieldName="SN"><StartChar>0</StartChar><NoOfChars>2</NoOfChars><SelectMode>Right</SelectMode></SrcField></Object>' +
    '</Data><Barcode><BcH>1100</BcH><QuietMargin>0</QuietMargin><DataMatrix><ModuleSize>50</ModuleSize><SymbolSize>22X22</SymbolSize></DataMatrix></Barcode></Field>';
  const runtime = runtimeFor(fieldXml() + selected + matrix);
  const { context, state } = runtime;
  const part = state.fieldByName.get('PART');
  const dm = state.fieldByName.get('DM');
  const expected = '00    ';
  const values = context.prepareCiffCalculatedData(state.fields, now);
  assert.equal(context.makePreviewText(part, now), '00  ');
  assert.equal(values.get(part), '00  ');
  assert.equal(values.get(dm), expected);
  const tokens = context.getDataMatrixValueTokens(dm, now);
  assert.equal(Array.from(tokens, token => String.fromCharCode(token.value)).join(''), expected);
  const saved = runtime.save(now);
  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  const reopened = createProductionCiffRuntime(saved.bytes);
  assert.equal(reopened.state.fieldByName.get('SN').calcData, '0000000000  ');
  assert.equal(reopened.state.fieldByName.get('PART').calcData, '00  ');
  assert.equal(reopened.state.fieldByName.get('DM').calcData, expected);
});

test('Windows native measurement includes the two trailing spaces in the SN cell', { skip: process.platform !== 'win32' }, async () => {
  const runtime = runtimeFor();
  const renderer = createFontRendererService();
  try {
    const requests = installNative(runtime, request => renderer.render(request));
    const field = runtime.state.fields[0];
    field._nativeTextGeometryDirty = true;
    await runtime.context.ensureNativeTextGeometry(runtime.state.fields, now);
    assert.equal(requests.at(-1).text, '0000000000  ');
    const result = await renderer.render(requests.at(-1));
    assert.deepEqual([result.width, result.height], [254, 47]);
    assert.deepEqual([field.geom.w, field.geom.h], [2117, 392]);
    assert.deepEqual([field.geom.x, field.geom.y], [2100, 100]);
  } finally { renderer.dispose(); }
});

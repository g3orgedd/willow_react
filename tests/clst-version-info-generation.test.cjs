const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const {
  createProductionCiffRuntime,
} = require('./helpers/ciff-production-harness.cjs');

const PROJECT_ROOT = path.join(__dirname, '..');
const LONG_INTERMEDIATE = 'MWNDu5BBD5YND7UFBSMsIQv26nHTELGTVEh47lGLjGRv9KoKQVOMgH7sB';
const LONG_EXPECTED = 'PyOA!LMe37jF5gGD_OEeQJPAIR3Et2HVCOk4RKDB93Hl9AjBVgIOzL2x64vRUW8LPDPLLM!BMqKMGOFnVSVSNLLLnTAS2NyCJtJUD3VGHDbN6K76iHU!QGk8UrNGi8Uz9Tc9QVCIr2TyL6eAUTMUCVHm8EcI0yABuRMv7N4LVz1';
const TIME_EXPECTED = 'PyOA!LMe37jF5gGD_OEeQJPAIR3Et2HVCOk4RKDB93Hl9AjBVgIOzL2x64vRUW8LPDPLLM!BMqKMGPFo91NG7lLLSELsTMvM2jQA_3K2CTVVIeRTpAJ6L';

function storedTextValue(field) {
  if (field?.data?.textEntryMode === 'user') {
    return field.data.userEnterData || field.data.defaultValue || field.calcData || '';
  }
  return field?.calcData || field?.data?.defaultValue || field?.data?.userEnterData || '';
}

function timeTextValue(field, now) {
  const format = String(field?.data?.defaultValue || "HH':'mm").replace(/'/g, '');
  return format
    .replace(/HH/g, String(now.getHours()).padStart(2, '0'))
    .replace(/mm/g, String(now.getMinutes()).padStart(2, '0'));
}

function loadClStApi() {
  const context = {
    console,
    glyphSystemTickCount: () => 0,
    state: { fieldByName: new Map(), dateOffsets: [] },
    getStoredTextFieldValue: storedTextValue,
    getTimeTextValue: timeTextValue,
    getDateTextValue: (field) => (field?.fldType === 'OffsetDateText' ? 'offset-date' : 'date'),
    getFieldDisplayValue: (field, now) => (
      field?.fldType === 'TimeText' ? timeTextValue(field, now) : storedTextValue(field)
    ),
  };
  context.globalThis = context;
  vm.createContext(context);
  for (const relativePath of [
    'public/modules/clst/encryption.js',
    'public/modules/clst/tag-data.js',
    'public/modules/clst/version-info.js',
  ]) {
    const filename = path.join(PROJECT_ROOT, relativePath);
    vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  }
  const api = vm.runInContext(`({
    CEncryption,
    encryptClStText,
    buildClStStructureKey,
    createClStMaskForSelectedIndex,
    formatClStMaskHex,
    createClStSelectionMask,
    buildClStTagData,
    getDataMatrixRuntimeSegmentValues,
    getDataMatrixLogicalValue,
    resolveClstTagData,
    buildClStVersionInfoDebugInfo,
    generateClStVersionInfo,
    decodeClStVersionInfo,
    isValidClStVersionInfoSyntax
  })`, context);
  return { api, context };
}

function encodeCiff(text) {
  return Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(String(text), 'utf16le')]);
}

function getClStVersionInfo(text) {
  return String(text).match(/<ClStVersionInfo(?:\s[^>]*)?>([\s\S]*?)<\/ClStVersionInfo>/)?.[1] ?? null;
}

function oneTimeTextCiff() {
  return '<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    '<ImageDesign Version="23" xml:space="default">' +
    '<Header DesignedFor="DataFlex 6330(53mm) - Continuous"><ClStVersionInfo>LOADED_VALUE</ClStVersionInfo></Header>' +
    '<SubImage ImageReference="1"><SubHeader FormatName="Default" PrinterFormatName="Default">' +
    '<ImageWidth>1000</ImageWidth><ImageHeight>1000</ImageHeight><MaxImageWidth>5333</MaxImageWidth>' +
    '<MaxImageHeight>7500</MaxImageHeight><XRes>0.120000</XRes><CurrentOrientation>0</CurrentOrientation>' +
    '</SubHeader><Field Name="TIME"><FldType>TimeText</FldType><X>100</X><Y>100</Y><W>708</W><H>325</H>' +
    '<Ln>1</Ln><CalcData><![CDATA[00:00]]></CalcData><Data><Object Static="0" Parse="1" Reference="">' +
    '<DataType>1</DataType><Default><![CDATA[HH\':\'mm]]></Default></Object></Data>' +
    '<Text><Font><Pitch>8</Pitch></Font></Text></Field></SubImage>' +
    '<GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>\r\n';
}

function multiSubImageCiff() {
  const timeField = '<Field Name="TIME"><FldType>TimeText</FldType><X>100</X><Y>100</Y><W>708</W><H>325</H>' +
    '<Ln>1</Ln><CalcData><![CDATA[00:00]]></CalcData><Data><Object Static="0" Parse="1" Reference="">' +
    '<DataType>1</DataType><Default><![CDATA[HH\':\'mm]]></Default></Object></Data>' +
    '<Text><Font><Pitch>8</Pitch></Font></Text></Field>';
  const fixedField = '<Field Name="SECOND"><FldType>FixedText</FldType><X>10</X><Y>10</Y><W>100</W><H>100</H>' +
    '<Ln>1</Ln><CalcData><![CDATA[value]]></CalcData><Data><Object><DataType>0</DataType>' +
    '<Default><![CDATA[value]]></Default></Object></Data><Text><Font><Pitch>8</Pitch></Font></Text></Field>';
  const directOffset = '<DateOffset Name="direct"><DefaultOffset><Day>1</Day></DefaultOffset>' +
    '<CurrentOffset><Day>30</Day><Month>8</Month><Year>2026</Year></CurrentOffset></DateOffset>';
  const nestedOffset = '<Vendor><DateOffset Name="nested"><DefaultOffset><Day>2</Day></DefaultOffset>' +
    '<CurrentOffset><Day>31</Day><Month>8</Month><Year>2026</Year></CurrentOffset></DateOffset></Vendor>';
  const subHeader = '<SubHeader FormatName="Default" PrinterFormatName="Default"><ImageWidth>1000</ImageWidth>' +
    '<ImageHeight>1000</ImageHeight><MaxImageWidth>5333</MaxImageWidth><MaxImageHeight>7500</MaxImageHeight>' +
    '<XRes>0.120000</XRes><CurrentOrientation>0</CurrentOrientation></SubHeader>';
  return '<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    '<ImageDesign Version="23" xml:space="default"><Header DesignedFor="DataFlex 6330(53mm) - Continuous">' +
    `<ClStVersionInfo>LOADED_VALUE</ClStVersionInfo>${directOffset}${nestedOffset}</Header>` +
    `<SubImage ImageReference="1">${subHeader}${timeField}</SubImage>` +
    `<SubImage ImageReference="2">${subHeader}${fixedField}</SubImage>` +
    '<GenericSettings><ImageMapping><Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>\r\n';
}

test('CEncryption matches all confirmed vectors character-for-character', () => {
  const { api } = loadClStApi();

  assert.equal(api.encryptClStText(LONG_INTERMEDIATE, 'TpyRcNeyeK'), LONG_EXPECTED);
  assert.equal(api.encryptClStText('00000001', '000101'), 'MWNDu5BBD5YND7UFBSMsIQv2');
  assert.equal(api.encryptClStText('21:22', 'TagData'), '6o7UEV2GF5uKVqU');
  assert.equal(api.encryptClStText(LONG_INTERMEDIATE, 'TpyRcNeyeK').length, LONG_INTERMEDIATE.length * 3);
});

test('structure key uses DDSSFF and clamps each counter to 99', () => {
  const { api } = loadClStApi();

  assert.equal(api.buildClStStructureKey(0, 1, 1), '000101');
  assert.equal(api.buildClStStructureKey(1, 1, 15), '010115');
  assert.equal(api.buildClStStructureKey(12, 3, 7), '120307');
  assert.equal(api.buildClStStructureKey(120, 103, 107), '999999');
});

test('selection masks preserve unsigned bit 31 and fixed-width uppercase hex', () => {
  const { api } = loadClStApi();

  assert.equal(api.formatClStMaskHex(api.createClStMaskForSelectedIndex(0)), '00000001');
  assert.equal(api.formatClStMaskHex(api.createClStMaskForSelectedIndex(3)), '00000008');
  assert.equal(api.createClStMaskForSelectedIndex(31), 0x80000000);
  assert.equal(api.formatClStMaskHex(api.createClStMaskForSelectedIndex(31)), '80000000');

  const fields = Array.from({ length: 32 }, (_, index) => ({ value: index === 31 ? 'selected' : null }));
  const selection = api.createClStSelectionMask(fields, new Date(), {
    nextMod: (bound) => bound === 3 ? 0 : 31,
  });
  assert.equal(selection.selectedFieldIndex, 31);
  assert.equal(selection.maskHex, '80000000');
});

test('TagData truncates to exactly 20 UTF-16 code units', () => {
  const { api } = loadClStApi();
  const value = `${'A'.repeat(19)}😀Z`;
  const tagData = api.buildClStTagData([{ value }], 1, new Date(), {
    resolveTagData: (field) => field.value,
  });

  assert.equal(tagData, value.slice(0, 20));
  assert.equal(tagData.length, 20);
  assert.equal(tagData.charCodeAt(19), value.charCodeAt(19));
});

test('DataMatrix logical value follows Index order and keeps raw ~ source syntax', () => {
  const { api } = loadClStApi();
  const source = { name: 'TIME', fldType: 'TimeText', data: { defaultValue: "HH':'mm" } };
  const field = {
    fldType: 'Barcode',
    barcode: {
      dataMatrix: {
        segments: [
          { index: 2, defaultValue: 'END' },
          { index: 0, srcField: 'TIME', defaultValue: '00:00' },
          { index: 1, defaultValue: '~d02993' },
        ],
      },
    },
  };
  const fieldByName = new Map([['TIME', source]]);
  const value = api.resolveClstTagData(field, new Date(2026, 7, 29, 21, 22), { fieldByName });

  assert.equal(value, '21:22~d02993END');
});

test('runtime TagData dispatch covers user text, date, offset date and counter values', () => {
  const { api } = loadClStApi();
  const now = new Date(2026, 7, 29, 21, 22);
  const userText = {
    fldType: 'FixedText',
    calcData: 'calc',
    data: { textEntryMode: 'user', userEnterData: 'operator', defaultValue: 'default' },
  };
  const counter = {
    fldType: 'CounterText',
    calcData: '0042',
    data: { defaultValue: '0001' },
  };

  assert.equal(api.resolveClstTagData(userText, now), 'operator');
  assert.equal(api.resolveClstTagData({ fldType: 'DateText', data: {} }, now), 'date');
  assert.equal(api.resolveClstTagData({ fldType: 'OffsetDateText', data: {} }, now), 'offset-date');
  assert.equal(api.resolveClstTagData(counter, now), '0042');
});

test('full one-TimeText template produces the confirmed 117-character value', () => {
  const runtime = createProductionCiffRuntime(encodeCiff(oneTimeTextCiff()));
  const saveNow = new Date(2026, 7, 29, 21, 22, 37, 500);
  runtime.context.__clstSeenNow = [];
  vm.runInContext(`
    const __originalResolveClstTagData = resolveClstTagData;
    resolveClstTagData = function(field, now, options) {
      globalThis.__clstSeenNow.push(now);
      return __originalResolveClstTagData(field, now, options);
    };
  `, runtime.context);

  const saved = runtime.save(saveNow);
  const text = saved.bytes.subarray(2).toString('utf16le');

  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  assert.equal(saved.prepared.now, saveNow);
  assert.ok(runtime.context.__clstSeenNow.length >= 1);
  assert.ok(runtime.context.__clstSeenNow.every((value) => value === saveNow));
  assert.equal(getClStVersionInfo(text), TIME_EXPECTED);
  assert.equal(getClStVersionInfo(text).length, 117);
  assert.equal(runtime.state.docMeta.clStVersionInfo, TIME_EXPECTED);
});

test('save adapter counts only direct DateOffsets and all direct SubImage Fields', () => {
  const runtime = createProductionCiffRuntime(encodeCiff(multiSubImageCiff()));
  const info = vm.runInContext(`(() => {
    const template = buildClStTemplateForSave(state.line2);
    return buildClStVersionInfoDebugInfo(template, new Date(2026, 7, 29, 21, 22), {
      fieldByName: state.fieldByName, mask: 1
    });
  })()`, runtime.context);

  assert.equal(info.dateOffsetCount, 1);
  assert.equal(info.subImageCount, 2);
  assert.equal(info.fieldCount, 2);
  assert.equal(info.structureKey, '010202');
  assert.equal(info.selectedFieldIndex, 0);
  // This direct adapter call has no prepared runtime snapshot; it takes the
  // original field CalculatedData rather than silently recalculating a clock.
  assert.equal(info.tagData, '00:00');
});

test('empty external templates generate the ordinary 72-character native path', () => {
  const source = oneTimeTextCiff()
    .replace('DataFlex 6330(53mm) - Continuous', 'DataFlex 6530(53mm) - Continuous')
    .replace(/<ClStVersionInfo>[\s\S]*?<\/ClStVersionInfo>/, '')
    .replace(/<Field\b[\s\S]*?<\/Field>/, '');
  const runtime = createProductionCiffRuntime(encodeCiff(source));
  const saved = runtime.save(new Date(2026, 7, 29, 21, 22));
  const value = getClStVersionInfo(saved.bytes.subarray(2).toString('utf16le'));

  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  assert.equal(value.length, 72);
  assert.equal(runtime.state.docMeta.clStVersionInfo, value);
});

test('fixed selection is deterministic and changing selected data or mask changes ClSt', () => {
  const { api } = loadClStApi();
  const now = new Date(2026, 7, 29, 21, 22);
  const firstField = {
    name: 'A',
    fldType: 'FixedText',
    calcData: 'alpha',
    data: { defaultValue: 'alpha', textEntryMode: 'fixed' },
  };
  const template = { dateOffsets: [], subImages: [{ fields: [firstField] }] };

  const first = api.buildClStVersionInfoDebugInfo(template, now, { mask: 1 });
  const repeated = api.buildClStVersionInfoDebugInfo(template, now, { mask: 1 });
  assert.equal(first.clStVersionInfo, repeated.clStVersionInfo);

  firstField.calcData = 'beta';
  const changedValue = api.buildClStVersionInfoDebugInfo(template, now, { mask: 1 });
  assert.notEqual(changedValue.clStVersionInfo, first.clStVersionInfo);

  firstField.calcData = 'alpha';
  template.subImages[0].fields.unshift({ fldType: 'UnsupportedVendorField' });
  const changedCount = api.buildClStVersionInfoDebugInfo(template, now, { mask: 2 });
  assert.equal(first.structureKey, '000101');
  assert.equal(changedCount.structureKey, '000102');
  assert.equal(changedCount.selectedFieldIndex, 1);
  assert.notEqual(changedCount.clStVersionInfo, first.clStVersionInfo);
});

test('unsupported non-empty templates do not emit a fictitious token', () => {
  const { api } = loadClStApi();
  const debug = api.buildClStVersionInfoDebugInfo({
    dateOffsets: [],
    subImages: [{ fields: [{ fldType: 'UnsupportedVendorField' }] }],
  }, new Date(2026, 7, 29, 21, 22));

  assert.equal(debug.fieldCount, 1);
  assert.equal(debug.selectedFieldIndex, 0);
  assert.deepEqual(Array.from(debug.unresolvedSelectedFieldIndices), [0]);
  assert.equal(debug.clStVersionInfo, null);
  assert.equal(api.generateClStVersionInfo({
    dateOffsets: [],
    subImages: [{ fields: [{ fldType: 'UnsupportedVendorField' }] }],
  }, new Date(2026, 7, 29, 21, 22)), null);
});

test('save regenerates an unknown field type from its explicit prepared value', () => {
  const source = oneTimeTextCiff().replace('<FldType>TimeText</FldType>', '<FldType>VendorText</FldType>');
  const runtime = createProductionCiffRuntime(encodeCiff(source));
  const warnings = [];
  runtime.context.console = {
    ...console,
    warn: (...args) => warnings.push(args),
  };
  const saved = runtime.save(new Date(2026, 7, 29, 21, 22));
  const value = getClStVersionInfo(saved.bytes.subarray(2).toString('utf16le'));

  assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
  const { api } = loadClStApi();
  assert.equal(api.isValidClStVersionInfoSyntax(value), true);
  assert.equal(api.decodeClStVersionInfo(value).tagData, '00:00');
  assert.equal(runtime.state.docMeta.clStVersionInfo, value);
  assert.equal(warnings.length, 0);
});

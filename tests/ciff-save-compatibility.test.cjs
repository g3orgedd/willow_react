const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const XML_DECLARATION = '<?xml version="1.0" encoding="UTF-16"?>';

function findDirectChildTagContentRange(inner, tag) {
  const expression = new RegExp(`<${tag}(?:\\s[^>]*)?>([\\s\\S]*?)<\\/${tag}>`);
  const match = expression.exec(inner);
  if (!match) return null;
  const openLength = match[0].indexOf('>') + 1;
  return {
    start: match.index + openLength,
    end: match.index + openLength + match[1].length,
  };
}

function makeState(overrides = {}) {
  return {
    xmlDoc: {},
    line1: XML_DECLARATION,
    line2: validXmlLine(),
    docMeta: {
      version: '23',
      designedFor: 'DataFlex 6330(53mm) - Continuous',
      clStVersionInfo: 'opaque',
      printerModel: 'DataFlex 6330(53mm)',
      printMode: 'Continuous',
    },
    subImage: {
      imageReference: '1',
      width: 2000,
      height: 2000,
      maxWidth: 2000,
      maxHeight: 2000,
      xRes: 0.12,
      orientation: 0,
      usedSizeDirty: false,
    },
    dateOffsets: [],
    dateOffsetsLoaded: false,
    dateOffsetsDirty: false,
    fields: [],
    fieldByName: new Map(),
    validation: {
      invalidPrintableFieldNames: [],
      invalidHardwareFieldNames: [],
      structuralErrors: [],
    },
    ...overrides,
  };
}

function validXmlLine(options = {}) {
  const imageReference = options.imageReference ?? '1';
  const width = options.width ?? 2000;
  const height = options.height ?? 2000;
  const maxWidth = options.maxWidth ?? 5333;
  const maxHeight = options.maxHeight ?? 7500;
  const xRes = options.xRes ?? '0.120000';
  const headerExtra = options.headerExtra ?? '';
  const subImageExtra = options.subImageExtra ?? '';
  const mappingReference = options.mappingReference ?? imageReference;
  return `<ImageDesign Version="23" xml:space="default"><Header DesignedFor="DataFlex 6330(53mm) - Continuous"><ClStVersionInfo>opaque</ClStVersionInfo>${headerExtra}</Header><SubImage ImageReference="${imageReference}"><SubHeader FormatName="Default" PrinterFormatName="Default"><ImageWidth>${width}</ImageWidth><ImageHeight>${height}</ImageHeight><MaxImageWidth>${maxWidth}</MaxImageWidth><MaxImageHeight>${maxHeight}</MaxImageHeight><XRes>${xRes}</XRes><CurrentOrientation>0</CurrentOrientation></SubHeader>${subImageExtra}</SubImage><GenericSettings><ImageMapping><Map SubIMageRef="${mappingReference}">${mappingReference}</Map></ImageMapping></GenericSettings></ImageDesign>`;
}

function loadSaveApi(stateOverrides = {}) {
  const notifications = [];
  const computedAt = [];
  const context = {
    console,
    glyphSystemTickCount: () => 0,
    state: makeState(stateOverrides),
    history: { undo: [], redo: [] },
    GRID_SIZE_OPTIONS: [1, 3, 5, 10],
    ALLOWED_ORIENTATIONS: [0, 90, 180, 270],
    PRINTER_CAPABILITIES: {
      'DataFlex 6330(53mm)': {
        maxImageWidth: 5333,
        maxImageHeight: 7500,
        xRes: 0.12,
        xResText: '0.120000',
      },
    },
    normalizePrinterModel: (value) => String(value ?? '').trim(),
    buildDesignedForLabel: (model, mode) => `${model} - ${mode}`,
    findDirectChildTagContentRange,
    syncUsedImageSizeFromPrintableFields: () => {},
    validatePrintableFieldsInsideArea: () => ({
      invalidPrintableFieldNames: context.invalidPrintableFieldNames || [],
    }),
    validateHardwareFieldsInsideArea: () => ({
      invalidHardwareFieldNames: context.invalidHardwareFieldNames || [],
    }),
    getSelectedNames: () => [],
    setSelectedNames: () => {},
    normalizeCounterField: () => {},
    appLogger: {
      file: () => {},
      state: () => {},
      log: () => {},
    },
    t: (key) => key,
    openNotificationModal: (message, title) => notifications.push({ message, title }),
    document: {
      createElement: () => ({ click: () => {}, remove: () => {} }),
      body: { appendChild: () => {} },
    },
    URL: {
      createObjectURL: () => 'blob:test',
      revokeObjectURL: () => {},
    },
    Blob,
    setTimeout: (callback) => callback(),
  };
  context.globalThis = context;
  vm.createContext(context);

  const compatibilityFilename = path.join(__dirname, '..', 'public', 'modules', '01-ciff-compatibility.js');
  vm.runInContext(fs.readFileSync(compatibilityFilename, 'utf8'), context, { filename: compatibilityFilename });
  for (const relativePath of [
    'public/modules/clst/encryption.js',
    'public/modules/clst/tag-data.js',
    'public/modules/clst/calculated-data.js',
    'public/modules/clst/version-info.js',
  ]) {
    const clstFilename = path.join(__dirname, '..', relativePath);
    vm.runInContext(fs.readFileSync(clstFilename, 'utf8'), context, { filename: clstFilename });
  }

  const renderingFilename = path.join(__dirname, '..', 'public', 'modules', '30-rendering.js');
  const renderingSource = fs.readFileSync(renderingFilename, 'utf8');
  const dateStart = renderingSource.indexOf('function applyDateOffsetDelta');
  const dateEnd = renderingSource.indexOf('function inferDateLocale', dateStart);
  vm.runInContext(
    `${renderingSource.slice(dateStart, dateEnd)}\nglobalThis.__computedDateOffset = getComputedDateOffsetCurrent;`,
    context,
    { filename: renderingFilename },
  );
  context.getComputedDateOffsetCurrent = (offset, now) => {
    computedAt.push(now.getTime());
    return context.__computedDateOffset(offset, now);
  };

  const filename = path.join(__dirname, '..', 'public', 'modules', '60-history-save.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  const api = vm.runInContext(`({
    prepareCiffForSave,
    patchXmlLosslessV2Preview,
    validateCiffCompatibility,
    synchronizeDirtyDateOffsetCurrents,
    isValidCalendarDateParts,
    getComputedDateOffsetCurrent,
    buildCiffOutputText,
    encodeUtf16leWithBom,
    commitPreparedCiffToState,
    downloadCiff
  })`, context);
  return { api, context, notifications, computedAt };
}

function plain(value) {
  return JSON.parse(JSON.stringify(value));
}

test('dirty DateOffsets share one frozen clock and commit only after validation', () => {
  const { api, context, computedAt } = loadSaveApi({
    line2: validXmlLine({
      headerExtra: '<DateOffset Name="old"><DefaultOffset><Day>270</Day></DefaultOffset><CurrentOffset><Day>270</Day></CurrentOffset></DateOffset>',
    }),
    dateOffsets: [
      { name: '270days', default: { y: 0, m: 0, d: 270 }, current: { y: 0, m: 0, d: 270 } },
      { name: 'oneMonth', default: { y: 0, m: 1, d: 0 }, current: null },
    ],
    dateOffsetsLoaded: true,
    dateOffsetsDirty: true,
  });
  const now = new Date(2026, 7, 17, 12, 0, 0, 0);
  const result = api.prepareCiffForSave(now);

  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.deepEqual(plain(context.state.dateOffsets[0].current), { y: 0, m: 0, d: 270 });
  assert.equal(context.state.dateOffsets[1].current, null);
  api.commitPreparedCiffToState(result);
  assert.deepEqual(plain(context.state.dateOffsets[0].current), { y: 2027, m: 5, d: 14 });
  assert.deepEqual(plain(context.state.dateOffsets[1].current), { y: 2026, m: 9, d: 17 });
  assert.deepEqual(computedAt, [now.getTime(), now.getTime()]);
  assert.match(result.line2, /<DefaultOffset><Day>270<\/Day><\/DefaultOffset><CurrentOffset><Day>14<\/Day><Month>5<\/Month><Year>2027<\/Year><\/CurrentOffset>/);
  assert.equal((result.outputText.match(/\r\n/g) || []).length, 2);
  assert.ok(result.outputText.endsWith('\r\n'));
});

test('dirty DateOffsets patch matching source blocks losslessly, remove deleted entries and append new entries canonically', () => {
  const keptOffset = '<DateOffset Name="keep" StaticDate="1" Type="Hidden" VendorAttr="keep-offset"><VendorBefore>keep-before</VendorBefore><DefaultOffset VendorDefault="keep-default"><Day VendorDay="keep-day">1</Day><VendorDefaultChild>keep-default-child</VendorDefaultChild></DefaultOffset><VendorBetween>keep-between</VendorBetween><CurrentOffset VendorCurrent="keep-current"><Day VendorCurrentDay="keep-current-day">18</Day><VendorCurrentChild>keep-current-child</VendorCurrentChild></CurrentOffset><CalcAtCoder>0</CalcAtCoder></DateOffset>';
  const deletedOffset = '<DateOffset Name="deleted" VendorAttr="remove-me"><DefaultOffset><Day>5</Day></DefaultOffset><CurrentOffset><Day>22</Day><Month>8</Month><Year>2026</Year></CurrentOffset></DateOffset>';
  const untouchedOffset = '<DateOffset Name="untouched" VendorAttr="keep-verbatim"><DefaultOffset><Day>003</Day></DefaultOffset><VendorData>keep-verbatim</VendorData><CurrentOffset><Day>020</Day><Month>08</Month><Year>2026</Year></CurrentOffset></DateOffset>';
  const { api } = loadSaveApi({
    line2: validXmlLine({ headerExtra: keptOffset + deletedOffset + untouchedOffset }),
    dateOffsets: [
      { name: 'keep', default: { y: 0, m: 1, d: 0 }, current: null },
      { name: 'untouched', default: { y: 0, m: 0, d: 3 }, current: { y: 2026, m: 8, d: 20 } },
      { name: 'new', default: { y: 0, m: 0, d: 2 }, current: null },
    ],
    dateOffsetsLoaded: true,
    dateOffsetsDirty: true,
  });
  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));

  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.doesNotMatch(result.line2, /DateOffset Name="deleted"/);
  const savedKeep = result.line2.match(/<DateOffset Name="keep"[\s\S]*?<\/DateOffset>/)?.[0] || '';
  assert.match(savedKeep, /^<DateOffset Name="keep" StaticDate="1" Type="Hidden" VendorAttr="keep-offset">/);
  assert.ok(savedKeep.includes('<DefaultOffset VendorDefault="keep-default"><Day VendorDay="keep-day">0</Day><VendorDefaultChild>keep-default-child</VendorDefaultChild><Month>1</Month></DefaultOffset>'));
  assert.ok(savedKeep.includes('<CurrentOffset VendorCurrent="keep-current"><Day VendorCurrentDay="keep-current-day">17</Day><VendorCurrentChild>keep-current-child</VendorCurrentChild><Month>9</Month><Year>2026</Year></CurrentOffset>'));
  assert.ok(savedKeep.indexOf('<VendorBefore>') < savedKeep.indexOf('<DefaultOffset'));
  assert.ok(savedKeep.indexOf('</DefaultOffset>') < savedKeep.indexOf('<VendorBetween>'));
  assert.ok(savedKeep.indexOf('</VendorBetween>') < savedKeep.indexOf('<CurrentOffset'));
  assert.ok(savedKeep.indexOf('</CurrentOffset>') < savedKeep.indexOf('<CalcAtCoder>'));
  assert.ok(result.line2.includes(untouchedOffset));
  assert.match(
    result.line2,
    /<DateOffset Name="new"><DefaultOffset><Day>2<\/Day><\/DefaultOffset><CurrentOffset><Day>19<\/Day><Month>8<\/Month><Year>2026<\/Year><\/CurrentOffset><\/DateOffset>/
  );
  assert.equal((result.line2.match(/<DateOffset\b/g) || []).length, 3);
});

test('renaming an imported DateOffset preserves opaque source XML and commits its new identity', () => {
  const sourceOffset = "<DateOffset Name='legacy' VendorAttr='keep'><VendorBefore>opaque</VendorBefore><DefaultOffset><Day>1</Day></DefaultOffset><CurrentOffset><Day>18</Day><Month>8</Month><Year>2026</Year></CurrentOffset><VendorAfter>opaque</VendorAfter></DateOffset>";
  const { api, context } = loadSaveApi({
    line2: validXmlLine({ headerExtra: sourceOffset }),
    dateOffsets: [{
      sourceName: 'legacy',
      name: "renamed'offset",
      default: { y: 0, m: 0, d: 1 },
      current: { y: 2026, m: 8, d: 18 }
    }],
    dateOffsetsLoaded: true,
    dateOffsetsDirty: true,
  });

  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));
  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.match(result.line2, /<DateOffset Name='renamed&apos;offset' VendorAttr='keep'>/);
  assert.match(result.line2, /<VendorBefore>opaque<\/VendorBefore>/);
  assert.match(result.line2, /<VendorAfter>opaque<\/VendorAfter>/);

  api.commitPreparedCiffToState(result);
  assert.equal(context.state.dateOffsets[0].sourceName, "renamed'offset");
});

test('date rollover follows the same JavaScript calendar semantics used by preview', () => {
  const { api } = loadSaveApi();
  assert.deepEqual(
    plain(api.getComputedDateOffsetCurrent({ default: { y: 0, m: 0, d: 1 } }, new Date(2024, 1, 28, 12))),
    { y: 2024, m: 2, d: 29 },
  );
  assert.deepEqual(
    plain(api.getComputedDateOffsetCurrent({ default: { y: 0, m: 0, d: 1 } }, new Date(2023, 1, 28, 12))),
    { y: 2023, m: 3, d: 1 },
  );
  assert.deepEqual(
    plain(api.getComputedDateOffsetCurrent({ default: { y: 0, m: 1, d: 0 } }, new Date(2024, 0, 31, 12))),
    { y: 2024, m: 3, d: 2 },
  );
  assert.deepEqual(
    plain(api.getComputedDateOffsetCurrent({ default: { y: 1, m: 0, d: 0 } }, new Date(2024, 1, 29, 12))),
    { y: 2025, m: 3, d: 1 },
  );
});

test('optional metadata remains absent while required numeric metadata and opaque XML stay lossless', () => {
  const brokenLine = '<ImageDesign Version="23" xml:space="default"><Header DesignedFor="DataFlex 6330(53mm) - Continuous"><ClStVersionInfo>opaque</ClStVersionInfo><LastDownloaded>keep-me</LastDownloaded></Header><SubImage><SubHeader PrinterFormatName="Default"><ImageWidth>2000</ImageWidth><ImageHeight>2000</ImageHeight><MaxImageWidth>2000</MaxImageWidth><MaxImageHeight>2000</MaxImageHeight><CurrentOrientation>0</CurrentOrientation><VendorExtension>keep-me</VendorExtension></SubHeader></SubImage><GenericSettings><ImageMapping><Map SubIMageRef="9">9</Map></ImageMapping></GenericSettings><RootExtension>keep-me</RootExtension></ImageDesign>';
  const { api } = loadSaveApi({ line2: brokenLine });
  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));

  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.match(result.line2, /<SubImage>/);
  assert.match(result.line2, /<SubHeader PrinterFormatName="Default">/);
  assert.match(result.line2, /<MaxImageWidth>2000<\/MaxImageWidth>/);
  assert.match(result.line2, /<MaxImageHeight>2000<\/MaxImageHeight>/);
  assert.match(result.line2, /<XRes>0\.120000<\/XRes><CurrentOrientation>/);
  assert.match(result.line2, /<Map SubIMageRef="9">9<\/Map>/);
  assert.doesNotMatch(result.line2, /<Map SubIMageRef="1">/);
  assert.match(result.line2, /<LastDownloaded>keep-me<\/LastDownloaded>/);
  assert.match(result.line2, /<VendorExtension>keep-me<\/VendorExtension>/);
  assert.match(result.line2, /<RootExtension>keep-me<\/RootExtension>/);
});

test('an explicit ImageReference edit adds its mapping without rewriting foreign maps', () => {
  const foreignMaps = '<Map SubIMageRef="1" VendorAttr="keep-a">1</Map><Map SubIMageRef="2">2</Map>';
  const line2 = validXmlLine({ imageReference: '1', mappingReference: '1' })
    .replace('<Map SubIMageRef="1">1</Map>', foreignMaps);
  const { api } = loadSaveApi({
    line2,
    subImage: {
      imageReference: '3', width: 2000, height: 2000,
      maxWidth: 5333, maxHeight: 7500, xRes: 0.12, orientation: 0, usedSizeDirty: false,
    },
  });
  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));

  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.ok(result.line2.includes('<Map SubIMageRef="1" VendorAttr="keep-a">1</Map>'));
  assert.ok(result.line2.includes('<Map SubIMageRef="2">2</Map>'));
  assert.ok(result.line2.includes('<Map SubIMageRef="3">3</Map>'));
  assert.equal((result.line2.match(/<Map\b/g) || []).length, 3);
});

test('unknown printer targets retain source hardware values instead of guessing a profile', () => {
  const { api } = loadSaveApi({
    line2: validXmlLine({ maxWidth: 4321, maxHeight: 6543, xRes: '0.250000' }),
    docMeta: {
      version: '23',
      designedFor: 'Vendor Printer - Continuous',
      printerModel: 'Vendor Printer',
      printMode: 'Continuous',
    },
    subImage: {
      imageReference: '1', width: 2000, height: 2000,
      maxWidth: 4321, maxHeight: 6543, xRes: 0.25, orientation: 0, usedSizeDirty: false,
    },
  });
  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));

  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.match(result.line2, /<MaxImageWidth>4321<\/MaxImageWidth>/);
  assert.match(result.line2, /<MaxImageHeight>6543<\/MaxImageHeight>/);
  assert.match(result.line2, /<XRes>0\.250000<\/XRes>/);
});

test('saving after a printer change patches DesignedFor without changing physical or used dimensions', () => {
  const sourceLine = validXmlLine({ width: 2000, height: 3000, maxWidth: 2000, maxHeight: 3000 })
    .replaceAll('DataFlex 6330(53mm) - Continuous', 'DataFlex 6330(32mm) - Continuous');
  const { api } = loadSaveApi({
    line2: sourceLine,
    docMeta: {
      version: '23',
      designedFor: 'DataFlex 6330(53mm) - Continuous',
      clStVersionInfo: 'opaque',
      printerModel: 'DataFlex 6330(53mm)',
      printMode: 'Continuous',
    },
    subImage: {
      imageReference: '1',
      width: 2000,
      height: 3000,
      maxWidth: 2000,
      maxHeight: 3000,
      workspaceWidth: 2000,
      workspaceHeight: 3000,
      xRes: 0.12,
      orientation: 0,
      usedSizeDirty: false,
    },
  });

  const result = api.prepareCiffForSave(new Date(2026, 7, 26, 12));

  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.match(result.line2, /<Header DesignedFor="DataFlex 6330\(53mm\) - Continuous">/);
  assert.match(result.line2, /<ImageWidth>2000<\/ImageWidth>/);
  assert.match(result.line2, /<ImageHeight>3000<\/ImageHeight>/);
  assert.match(result.line2, /<MaxImageWidth>2000<\/MaxImageWidth>/);
  assert.match(result.line2, /<MaxImageHeight>3000<\/MaxImageHeight>/);
});

test('compatibility validator reports physical bounds, invalid dates and broken references together', () => {
  const headerExtra = '<DateOffset Name="270days"><DefaultOffset><Day>270</Day></DefaultOffset><CurrentOffset><Day>270</Day></CurrentOffset></DateOffset>';
  const fields = '<Field Name="DM"><FldType>Barcode</FldType><Data><Object><SrcField SrcFieldName="MISSING"/></Object></Data></Field><Field Name="EXP"><FldType>OffsetDateText</FldType><Data><Object><OffsetDate SrcOffset="missingOffset"/></Object></Data></Field>';
  const line2 = validXmlLine({ width: 6000, maxWidth: 5000, headerExtra, subImageExtra: fields });
  const { api, context } = loadSaveApi();
  context.invalidPrintableFieldNames = ['DM'];
  context.invalidHardwareFieldNames = ['hidden'];
  const result = api.validateCiffCompatibility({ line1: XML_DECLARATION, line2 }, { now: new Date(2026, 7, 17, 12) });

  assert.equal(result.ok, false);
  assert.deepEqual(plain(result.invalidPrintableFieldNames), ['DM']);
  assert.deepEqual(plain(result.invalidHardwareFieldNames), ['hidden']);
  assert.equal(result.structuralErrors.some((message) => message.includes('ImageWidth must not exceed')), false);
  assert.ok(result.structuralErrors.some((message) => message.includes('invalid CurrentOffset')));
  assert.ok(result.structuralErrors.some((message) => message.includes('Missing DateOffset target')));
  assert.ok(result.structuralErrors.some((message) => message.includes('Missing DataMatrix SrcField target')));
  assert.equal(result.structuralErrors.some((message) => message.includes('selected printer profile')), false);
});

test('a failed prepared save leaves live derived state unchanged', () => {
  const { api, context } = loadSaveApi({
    subImage: {
      imageReference: '1', width: 2000, height: 2000,
      maxWidth: 0, maxHeight: 0, xRes: 0, orientation: 0, usedSizeDirty: false,
    },
  });
  context.invalidHardwareFieldNames = ['blocked'];

  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));
  assert.equal(result.validation.ok, false);
  assert.deepEqual(plain(result.validation.invalidHardwareFieldNames), ['blocked']);
  assert.match(result.line2, /<MaxImageWidth>0<\/MaxImageWidth>/);
  assert.match(result.line2, /<MaxImageHeight>0<\/MaxImageHeight>/);
  assert.equal(context.state.subImage.maxWidth, 0);
  assert.equal(context.state.subImage.maxHeight, 0);
  assert.equal(context.state.subImage.xRes, 0);
});

test('clean imported invalid CurrentOffset is repaired while valid clean offsets stay lossless', () => {
  const invalidOffset = '<DateOffset Name="270days" VendorAttr="keep-offset"><DefaultOffset VendorDefault="keep-default"><Day>270</Day><VendorDefaultChild>keep-default-child</VendorDefaultChild></DefaultOffset><VendorBetween>keep-between</VendorBetween><CurrentOffset VendorCurrent="keep-current"><Day>270</Day><VendorCurrentChild>keep-current-child</VendorCurrentChild></CurrentOffset><CalcAtCoder>0</CalcAtCoder></DateOffset>';
  const { api } = loadSaveApi({
    line2: validXmlLine({ headerExtra: invalidOffset }),
    dateOffsets: [{ name: '270days', default: { y: 0, m: 0, d: 270 }, current: { y: 0, m: 0, d: 270 } }],
    dateOffsetsLoaded: true,
    dateOffsetsDirty: false,
  });
  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));

  assert.equal(result.validation.ok, true, plain(result.validation));
  const savedOffset = result.line2.match(/<DateOffset Name="270days"[\s\S]*?<\/DateOffset>/)?.[0] || '';
  assert.match(savedOffset, /^<DateOffset Name="270days" VendorAttr="keep-offset">/);
  assert.ok(savedOffset.includes('<DefaultOffset VendorDefault="keep-default"><Day>270</Day><VendorDefaultChild>keep-default-child</VendorDefaultChild></DefaultOffset>'));
  assert.ok(savedOffset.includes('<CurrentOffset VendorCurrent="keep-current"><Day>14</Day><VendorCurrentChild>keep-current-child</VendorCurrentChild><Month>5</Month><Year>2027</Year></CurrentOffset>'));
  assert.ok(savedOffset.indexOf('</DefaultOffset>') < savedOffset.indexOf('<VendorBetween>'));
  assert.ok(savedOffset.indexOf('</VendorBetween>') < savedOffset.indexOf('<CurrentOffset'));
  assert.ok(savedOffset.indexOf('</CurrentOffset>') < savedOffset.indexOf('<CalcAtCoder>'));
});

test('a valid clean imported DateOffset is preserved byte-for-byte inside Header', () => {
  const validOffset = '<DateOffset Name="270days"><DefaultOffset><Day>270</Day></DefaultOffset><VendorOffsetData>keep-me</VendorOffsetData><CurrentOffset><Day>14</Day><Month>5</Month><Year>2027</Year></CurrentOffset></DateOffset>';
  const { api } = loadSaveApi({
    line2: validXmlLine({ headerExtra: validOffset }),
    dateOffsets: [{ name: '270days', default: { y: 0, m: 0, d: 270 }, current: { y: 2027, m: 5, d: 14 } }],
    dateOffsetsLoaded: true,
    dateOffsetsDirty: false,
  });
  const result = api.prepareCiffForSave(new Date(2026, 7, 17, 12));

  assert.equal(result.validation.ok, true, plain(result.validation));
  assert.ok(result.line2.includes(validOffset));
});

test('UTF-16LE encoder keeps BOM, declaration, two CRLFs and the final CRLF', () => {
  const { api } = loadSaveApi();
  const output = api.buildCiffOutputText({ line1: XML_DECLARATION, line2: validXmlLine() });
  const bytes = Buffer.from(new Uint8Array(api.encodeUtf16leWithBom(output)));

  assert.equal(bytes[0], 0xff);
  assert.equal(bytes[1], 0xfe);
  const decoded = bytes.subarray(2).toString('utf16le');
  assert.equal(decoded, output);
  assert.equal((decoded.match(/\r\n/g) || []).length, 2);
  assert.equal((decoded.match(/(?<!\r)\n|\r(?!\n)/g) || []).length, 0);
  assert.ok(decoded.endsWith('\r\n'));
});

test('download failure is caught and shown through the notification modal', () => {
  const { api, context, notifications } = loadSaveApi({
    line2: '<ImageDesign Version="23"></ImageDesign>',
  });
  context.alert = () => { throw new Error('alert must not be used'); };

  assert.equal(api.downloadCiff('broken.ciff'), false);
  assert.equal(notifications.length, 1);
  assert.match(notifications[0].message, /Header not found/);
});

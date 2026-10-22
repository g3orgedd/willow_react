const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

const {
  createEquivalentGlyphExport,
  DEFAULT_REFERENCE_TEXT,
  REFERENCE_SHA256,
  encodeReferenceText,
  readImageSize,
} = require('../scripts/generate-glyph-clarisoft-fix6.cjs');
const {
  createProductionCiffRuntime,
  sha256,
} = require('./helpers/ciff-production-harness.cjs');

function referenceBytes() {
  return encodeReferenceText(fs.readFileSync(DEFAULT_REFERENCE_TEXT, 'utf8'));
}

function plain(value) {
  return JSON.parse(JSON.stringify(value));
}

function syntheticGeometryRuntime(fields, { width = 2000, height = 2000, imageRotation = 0 } = {}) {
  const fieldXml = fields.map(({ name, x, y, w, h, orientation = 0 }) => (
    `<Field Name="${name}"><FldType>FixedText</FldType>` +
    `<X>${x}</X><Y>${y}</Y><W>${w}</W><H>${h}</H><Orientation>${orientation}</Orientation>` +
    '<CalcData><![CDATA[A]]></CalcData><Data><Object Reference=""><DataType>0</DataType>' +
    '<Default><![CDATA[A]]></Default></Object></Data><Text><Font><Pitch>8</Pitch></Font></Text></Field>'
  )).join('');
  // This fixture encodes the requested geometry contract, not a new ClariSoft oracle.
  const xml = '<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    '<ImageDesign Version="23" xml:space="default"><Header DesignedFor="DataFlex 6330(53mm) - Continuous"/>' +
    '<SubImage ImageReference="1"><SubHeader FormatName="Default" PrinterFormatName="Default">' +
    `<ImageWidth>${width}</ImageWidth><ImageHeight>${height}</ImageHeight>` +
    '<MaxImageWidth>5333</MaxImageWidth><MaxImageHeight>7500</MaxImageHeight>' +
    `<ImageRotation>${imageRotation}</ImageRotation><XRes>0.120000</XRes><CurrentOrientation>0</CurrentOrientation>` +
    `</SubHeader>${fieldXml}</SubImage><GenericSettings><ImageMapping>` +
    '<Map SubIMageRef="1">1</Map></ImageMapping></GenericSettings></ImageDesign>\r\n';
  return createProductionCiffRuntime(encodeReferenceText(xml));
}

test('requested ImageWidth and ImageHeight examples export extents measured from coordinate zero', () => {
  const runtime = syntheticGeometryRuntime([
    { name: 'A', x: 100, y: 200, w: 500, h: 325 },
    { name: 'B', x: 1199, y: 824, w: 300, h: 325 },
  ]);
  const field = runtime.state.fieldByName.get('B');
  field.geom.x = 1200;
  field.geom.y = 825;
  // Saving the changed model must recompute bounds even without the UI dirty flag.
  assert.equal(runtime.state.subImage.usedSizeDirty, false);

  const saved = runtime.save();
  assert.equal(saved.prepared.validation.ok, true);
  assert.deepEqual(readImageSize(saved.prepared.line2), {
    width: 1500,
    height: 1150,
    maxWidth: 5333,
    maxHeight: 7500,
  });
  const reparsed = createProductionCiffRuntime(saved.bytes);
  assert.deepEqual(plain(reparsed.state.fieldByName.get('B').geom), { x: 1200, y: 825, w: 300, h: 325 });
  assert.match(saved.prepared.line2, /<ImageRotation>0<\/ImageRotation>/);
});

test('requested 2683 + 983 example preserves exact integer CIFF units through import edit and save', () => {
  const runtime = syntheticGeometryRuntime([
    { name: 'Field00', x: 2682, y: 825, w: 983, h: 325 },
  ]);
  runtime.state.fieldByName.get('Field00').geom.x = 2683;
  runtime.state.subImage.usedSizeDirty = true;

  const saved = runtime.save();
  assert.equal(saved.prepared.validation.ok, true);
  assert.deepEqual(readImageSize(saved.prepared.line2), {
    width: 3666,
    height: 1150,
    maxWidth: 5333,
    maxHeight: 7500,
  });
});

test('quarter-turn field edits retain the existing CIFF geometry rule for every supported orientation', () => {
  for (const orientation of [0, 90, 180, 270]) {
    const runtime = syntheticGeometryRuntime([
      { name: 'Field00', x: 100, y: 200, w: 500, h: 325, orientation },
    ]);
    runtime.state.fieldByName.get('Field00').geom.x = 101;
    runtime.state.subImage.usedSizeDirty = true;
    const saved = runtime.save();
    const sideways = orientation === 90 || orientation === 270;

    assert.equal(saved.prepared.validation.ok, true);
    assert.deepEqual(readImageSize(saved.prepared.line2), {
      width: sideways ? 426 : 601,
      height: sideways ? 700 : 525,
      maxWidth: 5333,
      maxHeight: 7500,
    }, `field Orientation=${orientation}`);
    assert.equal(createProductionCiffRuntime(saved.bytes).state.fieldByName.get('Field00').orientation, orientation);
  }
});

test('an empty native aggregate is zero while an untouched configured image keeps its initial dimensions', () => {
  const runtime = syntheticGeometryRuntime([], { width: 1800, height: 2300 });
  const bounds = vm.runInContext(
    'calculateImageBounds(state.fields, state.subImage.width, state.subImage.height)',
    runtime.context,
  );
  assert.deepEqual(plain(bounds), { width: 0, height: 0 });
  const saved = runtime.save();
  assert.equal(saved.prepared.validation.ok, true);
  assert.deepEqual(readImageSize(saved.prepared.line2), {
    width: 1800,
    height: 2300,
    maxWidth: 5333,
    maxHeight: 7500,
  });
});

test('source ImageRotation metadata and source dimensions survive an untouched save', () => {
  for (const imageRotation of [90, 180, 270]) {
    const runtime = syntheticGeometryRuntime([
      { name: 'Field00', x: 100, y: 200, w: 500, h: 325 },
    ], { width: 1800, height: 2300, imageRotation });
    const saved = runtime.save();

    assert.equal(saved.prepared.validation.ok, true);
    assert.match(saved.prepared.line2, new RegExp(`<ImageRotation>${imageRotation}</ImageRotation>`));
    assert.deepEqual(readImageSize(saved.prepared.line2), {
      width: 1800,
      height: 2300,
      maxWidth: 5333,
      maxHeight: 7500,
    });
  }
});

test('clarisoft_fix6 decoded fixture reconstructs the supplied immutable CIFF', () => {
  const bytes = referenceBytes();

  assert.equal(bytes.length, 9430);
  assert.equal(sha256(bytes), REFERENCE_SHA256);
});

test('production parser derives clarisoft_fix6 bounds from visible X/Y/W/H only', () => {
  const runtime = createProductionCiffRuntime(referenceBytes());
  const result = vm.runInContext('calculateImageBounds(state.fields)', runtime.context);

  assert.deepEqual(plain(result), { width: 2516, height: 2558 });
  assert.deepEqual(
    Array.from(runtime.state.fields.filter((field) => field.printed), (field) => ({
      name: field.name,
      ...plain(field.geom),
    })),
    [
      { name: 'Field00', x: 0, y: 0, w: 1100, h: 1100 },
      { name: 'Field02', x: 2483, y: 2425, w: 33, h: 133 },
    ],
  );
  assert.equal(runtime.state.fieldByName.get('GTIN').printed, false);
  assert.equal(runtime.state.fieldByName.get('GTIN').geom.x + runtime.state.fieldByName.get('GTIN').geom.w, 3783);
});

test('production save repairs stale 1100 Image bounds and preserves printer limits', () => {
  const runtime = createProductionCiffRuntime(referenceBytes());
  runtime.state.subImage.width = 1100;
  runtime.state.subImage.height = 1100;
  runtime.state.subImage.usedSizeDirty = true;

  const saved = runtime.save();
  const size = readImageSize(saved.prepared.line2);
  const reparsed = createProductionCiffRuntime(saved.bytes);

  assert.deepEqual(size, {
    width: 2516,
    height: 2558,
    maxWidth: 3200,
    maxHeight: 7500,
  });
  assert.deepEqual(plain(reparsed.state.subImage), {
    imageReference: '1',
    width: 2516,
    height: 2558,
    maxWidth: 3200,
    maxHeight: 7500,
    xRes: 0.12,
    yRes: null,
    printerType: 'DataFlex 6320(32mm)',
    orientation: 0,
    usedSizeDirty: false,
  });
});

test('changing visibility automatically changes the exported image bounds', () => {
  const runtime = createProductionCiffRuntime(referenceBytes());
  const edge = runtime.state.fieldByName.get('Field02');

  edge.printed = false;
  runtime.state.subImage.usedSizeDirty = true;
  const hiddenSave = runtime.save();
  assert.deepEqual(readImageSize(hiddenSave.prepared.line2), {
    width: 1100,
    height: 1100,
    maxWidth: 3200,
    maxHeight: 7500,
  });

  runtime.state.fieldByName.get('Field02').printed = true;
  runtime.state.subImage.usedSizeDirty = true;
  const visibleSave = runtime.save();
  assert.deepEqual(readImageSize(visibleSave.prepared.line2), {
    width: 2516,
    height: 2558,
    maxWidth: 3200,
    maxHeight: 7500,
  });
});

test('untouched clarisoft_fix6 import keeps its correct source image dimensions', () => {
  const runtime = createProductionCiffRuntime(referenceBytes());
  const saved = runtime.save();

  assert.deepEqual(readImageSize(saved.prepared.line2), {
    width: 2516,
    height: 2558,
    maxWidth: 3200,
    maxHeight: 7500,
  });
});

test('non-geometry edits preserve source ClariSoft Image padding when history marks bounds dirty', () => {
  const paddedText = fs.readFileSync(DEFAULT_REFERENCE_TEXT, 'utf8')
    .replace('<ImageWidth>2516</ImageWidth>', '<ImageWidth>2600</ImageWidth>')
    .replace('<ImageHeight>2558</ImageHeight>', '<ImageHeight>2700</ImageHeight>');
  const runtime = createProductionCiffRuntime(encodeReferenceText(paddedText));
  const field = runtime.state.fieldByName.get('Field02');

  field.text.pitch = 11;
  runtime.state.subImage.usedSizeDirty = true;
  const diff = vm.runInContext('getPrintableGeometrySourceDiff(state.fields)', runtime.context);
  assert.equal(diff.changed, false);

  const saved = runtime.save();
  assert.deepEqual(readImageSize(saved.prepared.line2), {
    width: 2600,
    height: 2700,
    maxWidth: 3200,
    maxHeight: 7500,
  });
});

test('a real printed geometry edit replaces source Image padding with recalculated bounds', () => {
  const paddedText = fs.readFileSync(DEFAULT_REFERENCE_TEXT, 'utf8')
    .replace('<ImageWidth>2516</ImageWidth>', '<ImageWidth>2600</ImageWidth>')
    .replace('<ImageHeight>2558</ImageHeight>', '<ImageHeight>2700</ImageHeight>');
  const runtime = createProductionCiffRuntime(encodeReferenceText(paddedText));
  const field = runtime.state.fieldByName.get('Field02');

  field.geom.x += 100;
  runtime.state.subImage.usedSizeDirty = true;
  const diff = vm.runInContext('getPrintableGeometrySourceDiff(state.fields)', runtime.context);
  assert.equal(diff.changed, true);
  assert.deepEqual(Array.from(diff.reasons), ['geometry:Field02']);

  const saved = runtime.save();
  assert.deepEqual(readImageSize(saved.prepared.line2), {
    width: 2616,
    height: 2558,
    maxWidth: 3200,
    maxHeight: 7500,
  });
});

test('a printed orientation edit invalidates source Image padding', () => {
  const paddedText = fs.readFileSync(DEFAULT_REFERENCE_TEXT, 'utf8')
    .replace('<ImageWidth>2516</ImageWidth>', '<ImageWidth>2600</ImageWidth>')
    .replace('<ImageHeight>2558</ImageHeight>', '<ImageHeight>2700</ImageHeight>');
  const runtime = createProductionCiffRuntime(encodeReferenceText(paddedText));
  const field = runtime.state.fieldByName.get('Field02');

  field.orientation = 90;
  runtime.state.subImage.usedSizeDirty = true;
  const diff = vm.runInContext('getPrintableGeometrySourceDiff(state.fields)', runtime.context);
  assert.equal(diff.changed, true);
  assert.deepEqual(Array.from(diff.reasons), ['orientation:Field02']);

  const saved = runtime.save();
  assert.deepEqual(readImageSize(saved.prepared.line2), {
    width: 2616,
    height: 2458,
    maxWidth: 3200,
    maxHeight: 7500,
  });
});

test('programmatically created Glyph equivalent exports the same geometry and bounds', () => {
  const generated = createEquivalentGlyphExport({ write: false });
  const text = generated.generatedBytes.subarray(2).toString('utf16le');
  const reparsed = createProductionCiffRuntime(generated.generatedBytes);
  const recalculated = vm.runInContext('calculateImageBounds(state.fields)', reparsed.context);

  assert.equal(generated.referenceSha256, REFERENCE_SHA256);
  assert.equal(generated.sameGeometry, true);
  assert.deepEqual(generated.referenceSize, {
    width: 2516,
    height: 2558,
    maxWidth: 3200,
    maxHeight: 7500,
  });
  assert.deepEqual(generated.generatedSize, generated.referenceSize);
  assert.deepEqual(plain(recalculated), { width: 2516, height: 2558 });
  assert.match(text, /<Field Name="C1">/);
  assert.match(text, /<Field Name="C2">/);
  assert.match(text, /<Field Name="C3">/);
  assert.doesNotMatch(text, /<Field Name="\u0421[123]">/u);

  assert.deepEqual(
    generated.relevantDifferences
      // Newly created fields now use native logging omission; the reference
      // explicitly contains empty LoggedField nodes. That is independent of bounds.
      .filter((difference) => !difference.path.endsWith('/LoggedField'))
      .map((difference) => difference.path),
    [
      '/ImageDesign/SubImage[ImageReference="1"]/Field[Name="Field00"]/Barcode/BcH',
    ],
  );
  assert.ok(generated.relevantDifferences.every((difference) => !/Image(?:Width|Height)/.test(difference.path)));
});

test('reference text fixture stays in the expected repository location', () => {
  assert.equal(
    path.relative(path.join(__dirname, '..'), DEFAULT_REFERENCE_TEXT).replaceAll('\\', '/'),
    'tests/fixtures/clarisoft/clarisoft_fix6.reference.xml',
  );
});

test('removing or hiding the last printable field saves zero Image without changing Max', () => {
  for (const operation of ['remove', 'hide']) {
    const runtime = syntheticGeometryRuntime([{ name: 'A', x: 100, y: 200, w: 500, h: 325 }]);
    if (operation === 'remove') {
      runtime.state.fields = [];
      runtime.state.fieldByName.clear();
    } else {
      runtime.state.fields[0].printed = false;
    }
    const saved = runtime.save();
    assert.equal(saved.prepared.validation.ok, true, JSON.stringify(saved.prepared.validation));
    assert.deepEqual(readImageSize(saved.prepared.line2), {
      width: 0, height: 0, maxWidth: 5333, maxHeight: 7500,
    });
    const reopened = createProductionCiffRuntime(saved.bytes);
    assert.equal(reopened.state.subImage.width, 0);
    assert.equal(reopened.state.subImage.height, 0);
    assert.equal(reopened.save().prepared.validation.ok, true);
  }
});

test('native zero seed has no artificial minimum for nonempty or all-hidden geometry', () => {
  const runtime = syntheticGeometryRuntime([]);
  runtime.context.probeFields = [
    { printed: true, geom: { x: -100, y: -100, w: 100, h: 0 } },
    { printed: false, geom: { x: 9000, y: 9000, w: 100, h: 100 } },
  ];
  assert.deepEqual(plain(vm.runInContext('calculateImageBounds(probeFields, 9999, 9999)', runtime.context)), { width: 0, height: 0 });
  runtime.context.probeFields = [{ printed: true, geom: { x: -1000, y: -1000, w: 20, h: 30 } }];
  assert.deepEqual(plain(vm.runInContext('calculateImageBounds(probeFields)', runtime.context)), { width: 0, height: 0 });
});

test('only identified native RSS10..14 receive the 1000-unit height allowance before rotation', () => {
  for (const [tag, nativeType] of [['RSS14', 10], ['RSS14Truncated', 11], ['RSS14Stacked', 12], ['RSS14StackedOmni', 13], ['RSSLimited', 14]]) {
    for (const orientation of [0, 90, 180, 270]) {
      const source = syntheticGeometryRuntime([{ name: 'RSS', x: 100, y: 200, w: 500, h: 325, orientation }]);
      const xml = source.sourceText.replace('<FldType>FixedText</FldType>', '<FldType>Barcode</FldType>')
        .replace('<Text><Font><Pitch>8</Pitch></Font></Text>', `<Barcode><${tag}/></Barcode>`);
      const runtime = createProductionCiffRuntime(encodeReferenceText(xml));
      assert.equal(runtime.state.fields[0].barcode.nativeType, nativeType);
      const bounds = plain(vm.runInContext('calculateImageBounds(state.fields)', runtime.context));
      assert.deepEqual(bounds, orientation === 90 || orientation === 270
        ? { width: 1425, height: 700 } : { width: 600, height: 1525 }, `${tag}, ${orientation}`);
    }
  }
  const runtime = createProductionCiffRuntime(referenceBytes());
  assert.equal(runtime.state.fields[0].barcode.nativeType, 15);
  assert.deepEqual(plain(vm.runInContext('calculateImageBounds([state.fields[0]])', runtime.context)), { width: 1100, height: 1100 });
});

test('only the exact Line printer type expands MaxWidth after a printable geometry edit', () => {
  for (const printerType of ['Line', 'DataFlex 6330(53mm)']) {
    const runtime = syntheticGeometryRuntime([{ name: 'A', x: 100, y: 200, w: 500, h: 325 }]);
    runtime.state.subImage.printerType = printerType;
    runtime.state.subImage.maxWidth = 500;
    runtime.state.subImage.workspaceWidth = 500;
    runtime.state.fields[0].geom.x += 1;
    const size = plain(vm.runInContext('syncUsedImageSizeFromPrintableFields()', runtime.context));
    assert.deepEqual(size, { width: 601, height: 525 });
    assert.equal(runtime.state.subImage.maxWidth, printerType === 'Line' ? 601 : 500);
    assert.equal(runtime.state.subImage.maxHeight, 7500);
  }
});

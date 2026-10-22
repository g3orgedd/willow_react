const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');

function loadGeometryApi() {
  const context = {
    console,
    state: {
      xmlDoc: {},
      fields: [],
      subImage: {
        width: 3200,
        height: 1200,
        maxWidth: 5333,
        maxHeight: 7500,
        workspaceWidth: 3200,
        workspaceHeight: 1200,
      },
      validation: { invalidPrintableFieldNames: [], invalidHardwareFieldNames: [], structuralErrors: [] }
    },
    normalizeOrientation: (value) => [0, 90, 180, 270].includes(Number(value)) ? Number(value) : 0,
    getCanvasInternalWidth: () => context.state.subImage.workspaceWidth || context.state.subImage.maxWidth || context.state.subImage.width,
    getCanvasInternalHeight: () => context.state.subImage.workspaceHeight || context.state.subImage.maxHeight || context.state.subImage.height,
    getKnownPrinterCapabilities: () => ({ maxImageWidth: 5333, maxImageHeight: 7500 }),
    renderPrintableValidationWarning: () => {},
    mmToInternal: (value) => Math.round(Number(value) * 100),
    internalToMm: (value) => Number(value) / 100,
    mmToPx: (value) => Number(value) * 12,
    pxToMm: (value) => Number(value) / 12,
  };
  context.globalThis = context;
  vm.createContext(context);
  const filename = path.join(__dirname, '..', 'public', 'modules', '30-rendering.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  return context;
}

function loadCanvasRotationApi() {
  const context = {
    console,
    window: { Konva: {} },
    ALLOWED_ORIENTATIONS: [0, 90, 180, 270],
    INTERNAL_PER_MM: 100,
    MM_TO_PX_BASE: 10,
    zoomPct: 100,
    normalizeOrientation: (value) => {
      const normalized = ((Number(value) % 360) + 360) % 360;
      return [0, 90, 180, 270].includes(normalized) ? normalized : 0;
    },
    mmToInternal: (value) => Math.round(Number(value) * 100),
    internalToMm: (value) => Number(value) / 100,
    mmToPx: (value) => Number(value) * 10,
    pxToMm: (value) => Number(value) / 10,
  };
  context.globalThis = context;
  vm.createContext(context);
  const filename = path.join(__dirname, '..', 'public', 'modules', '10-canvas-ui.js');
  vm.runInContext(fs.readFileSync(filename, 'utf8'), context, { filename });
  return context;
}

function dataMatrixField(name, geom, printed = true, orientation = 0) {
  return {
    name,
    fldType: 'Barcode',
    barcode: { bcH: 2540, dataMatrix: { moduleSize: 0.42 } },
    printed,
    orientation,
    geom: { ...geom },
    _konva: null,
  };
}

function textFieldWithSelection(name, geom, selection, printed = true, orientation = 0) {
  return {
    name,
    fldType: 'FixedText',
    barcode: null,
    printed,
    orientation,
    geom: { ...geom },
    _konva: {
      findOne: (selector) => selector === '.SelectionBounds'
        ? {
            x: () => selection.x,
            y: () => selection.y,
            width: () => selection.w,
            height: () => selection.h,
          }
        : null,
    },
  };
}

test('orientation transforms the same local bounds used by the canvas selection', () => {
  const api = loadGeometryApi();
  const local = { x: 10, y: 20, w: 30, h: 40 };

  assert.deepEqual(JSON.parse(JSON.stringify(api.transformLocalBoundsForOrientationInternal(local, 120, 80, 0))), { x: 10, y: 20, w: 30, h: 40 });
  assert.deepEqual(JSON.parse(JSON.stringify(api.transformLocalBoundsForOrientationInternal(local, 120, 80, 90))), { x: 20, y: 10, w: 40, h: 30 });
  assert.deepEqual(JSON.parse(JSON.stringify(api.transformLocalBoundsForOrientationInternal(local, 120, 80, 180))), { x: 80, y: 20, w: 30, h: 40 });
  assert.deepEqual(JSON.parse(JSON.stringify(api.transformLocalBoundsForOrientationInternal(local, 120, 80, 270))), { x: 20, y: 80, w: 40, h: 30 });
});

test('mouse rotation snaps every pointer angle to a supported quarter turn', () => {
  const api = loadCanvasRotationApi();

  assert.equal(api.snapCanvasRotationDegrees(0), 0);
  assert.equal(api.snapCanvasRotationDegrees(44.9), 0);
  assert.equal(api.snapCanvasRotationDegrees(45.1), 90);
  assert.equal(api.snapCanvasRotationDegrees(136), 180);
  assert.equal(api.snapCanvasRotationDegrees(226), 270);
  assert.equal(api.snapCanvasRotationDegrees(316), 0);
  assert.equal(api.snapCanvasRotationDegrees(-91), 270);
  assert.equal(api.snapCanvasRotationDegrees(450), 90);
});

test('canvas rotation preserves the transformed visual top-left and advances field orientation', () => {
  const api = loadCanvasRotationApi();
  const field = dataMatrixField('rotated', { x: 100, y: 200, w: 400, h: 200 }, true, 90);
  const group = {
    rotation: () => 90,
    getTransform: () => ({
      point: ({ x, y }) => ({ x: 50 - y, y: 30 + x })
    })
  };

  assert.deepEqual(JSON.parse(JSON.stringify(api.getCanvasRotatedFieldResult(field, group))), {
    orientation: 180,
    x: 100,
    y: 300,
    deltaRotation: 90,
  });

  field.orientation = 270;
  group.rotation = () => 270;
  assert.equal(api.getCanvasRotatedFieldResult(field, group).orientation, 180);
});

test('snapped no-op DataMatrix resize preserves imported BcH outside history', () => {
  const api = loadCanvasRotationApi();
  const originalGeometry = { x: 100, y: 200, w: 924, h: 924 };
  const field = dataMatrixField('FieldDM', originalGeometry);
  const resizeMetrics = { moduleSize: 0.42, bcH: 924 };

  assert.equal(api.applyDataMatrixResizeMetricsAfterGeometryChange(field, resizeMetrics, originalGeometry), false);
  assert.equal(field.barcode.bcH, 2540);

  field.geom.x += 1;
  assert.equal(api.applyDataMatrixResizeMetricsAfterGeometryChange(field, resizeMetrics, originalGeometry), false);
  assert.equal(field.barcode.bcH, 2540);

  field.geom.w = 1100;
  field.geom.h = 1100;
  assert.equal(api.applyDataMatrixResizeMetricsAfterGeometryChange(field, { moduleSize: 0.50, bcH: 1100 }, originalGeometry), true);
  assert.equal(field.barcode.bcH, 1100);
  assert.equal(field.barcode.dataMatrix.moduleSize, 0.50);
});

test('logged R_NUM scenario validates the visible text bounds, not its empty saved width', () => {
  const api = loadGeometryApi();
  const field = textFieldWithSelection(
    'R_NUM',
    { x: 2160, y: 790, w: 1200, h: 400 },
    { x: 5.04, y: 3.6, w: 117, h: 39.6 }
  );
  api.state.fields = [field];

  assert.deepEqual(JSON.parse(JSON.stringify(api.getFieldRenderedBoundsInternal(field))), {
    x: 2202,
    y: 820,
    w: 975,
    h: 330,
  });
  assert.deepEqual(JSON.parse(JSON.stringify(api.validatePrintableFieldsInsideArea())).invalidPrintableFieldNames, []);

  field.geom.x = 2250;
  assert.deepEqual(JSON.parse(JSON.stringify(api.validatePrintableFieldsInsideArea())).invalidPrintableFieldNames, ['R_NUM']);
  assert.deepEqual(JSON.parse(JSON.stringify(api.constrainFieldPositionInternal(field, 2250, 790))), { x: 2183, y: 790 });
});

test('DataMatrix movement remains constrained by its full logical rectangle', () => {
  const api = loadGeometryApi();
  const field = dataMatrixField('FieldDM', { x: 2000, y: 800, w: 1200, h: 400 });

  assert.deepEqual(JSON.parse(JSON.stringify(api.constrainFieldPositionInternal(field, 2160, 900))), { x: 2000, y: 800 });
  api.setFieldPositionInternal(field, 2160, 900);
  assert.deepEqual(field.geom, { x: 2000, y: 800, w: 1200, h: 400 });
});

test('oversized fields are anchored at the template origin and remain invalid', () => {
  const api = loadGeometryApi();
  const field = dataMatrixField('too-large', { x: 800, y: 500, w: 1200, h: 900 });
  const area = { x: 0, y: 0, w: 1000, h: 800 };

  assert.deepEqual(
    JSON.parse(JSON.stringify(api.constrainFieldPositionInternal(field, 800, 500, area))),
    { x: 0, y: 0 }
  );
  field.geom.x = 0;
  field.geom.y = 0;
  api.state.subImage.width = area.w;
  api.state.subImage.height = area.h;
  api.state.subImage.workspaceWidth = area.w;
  api.state.subImage.workspaceHeight = area.h;
  api.state.fields = [field];
  assert.deepEqual(JSON.parse(JSON.stringify(api.validatePrintableFieldsInsideArea())).invalidPrintableFieldNames, ['too-large']);
});

test('text constraint never writes negative CIFF coordinates', () => {
  const api = loadGeometryApi();
  const field = textFieldWithSelection(
    'text',
    { x: 0, y: 0, w: 1200, h: 400 },
    { x: 5.04, y: 3.6, w: 117, h: 39.6 }
  );

  assert.deepEqual(
    JSON.parse(JSON.stringify(api.constrainFieldPositionInternal(field, -100, -100))),
    { x: 0, y: 0 }
  );
});

test('resize constraint can remeasure text instead of using stale selection bounds', () => {
  const api = loadGeometryApi();
  const field = textFieldWithSelection(
    'resized',
    { x: 1000, y: 900, w: 1200, h: 600 },
    { x: 0, y: 0, w: 12, h: 12 }
  );
  api.makePreviewNode = () => ({
    x: () => 0,
    y: () => 24,
    scaleX: () => 1,
    scaleY: () => 1,
    destroy: () => {},
    _ciffPreviewTextStyle: {
      measuredTextBounds: { x: 0, y: 0, width: 12, height: 24 },
      fontSize: 24
    }
  });

  const stale = api.constrainCurrentFieldPositionsInternal([field]);
  assert.deepEqual(JSON.parse(JSON.stringify(stale)), { x: 0, y: 0 });

  const fresh = api.constrainCurrentFieldPositionsInternal([field], { forceFreshTextBounds: true });
  assert.deepEqual(JSON.parse(JSON.stringify(fresh)), { x: 0, y: -100 });
  assert.equal(field.geom.y, 800);
});

test('group movement preserves spacing and stops at the furthest printed edge', () => {
  const api = loadGeometryApi();
  const left = dataMatrixField('left', { x: 100, y: 100, w: 500, h: 300 });
  const right = dataMatrixField('right', { x: 2600, y: 700, w: 600, h: 400 });
  const hidden = dataMatrixField('hidden', { x: 8000, y: 8000, w: 500, h: 300 }, false);

  assert.deepEqual(
    JSON.parse(JSON.stringify(api.constrainFieldsMovementDeltaInternal([left, right, hidden], 250, 300))),
    { x: 0, y: 100 }
  );
  assert.deepEqual(
    JSON.parse(JSON.stringify(api.constrainFieldsMovementDeltaInternal([hidden], 250, 300))),
    { x: 250, y: 300 }
  );
});

test('used content size updates Image dimensions without changing the workspace', () => {
  const api = loadGeometryApi();
  const fields = [
    dataMatrixField('Field00', { x: 83, y: 67, w: 917, h: 917 }),
    dataMatrixField('TEAM', { x: 2683, y: 125, w: 158, h: 358 }),
    dataMatrixField('Field02', { x: 2483, y: 2425, w: 33, h: 133 }),
    dataMatrixField('hidden', { x: 5000, y: 6500, w: 1000, h: 300 }, false),
  ];

  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateUsedImageSizeInternal(fields))), { width: 2841, height: 2558 });
  fields.splice(2, 1);
  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateUsedImageSizeInternal(fields))), { width: 2841, height: 984 });
  fields.push(dataMatrixField('R_NUM', { x: 2000, y: 800, w: 1200, h: 400 }));
  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateUsedImageSizeInternal(fields))), { width: 3200, height: 1200 });

  api.state.fields = fields;
  assert.deepEqual(JSON.parse(JSON.stringify(api.syncUsedImageSizeFromPrintableFields())), { width: 3200, height: 1200 });
  assert.equal(api.state.subImage.width, 3200);
  assert.equal(api.state.subImage.height, 1200);
  fields.pop();
  assert.deepEqual(JSON.parse(JSON.stringify(api.syncUsedImageSizeFromPrintableFields())), { width: 2841, height: 984 });
  assert.equal(api.state.subImage.width, 2841);
  assert.equal(api.state.subImage.height, 984);
});

test('calculateImageBounds uses raw CIFF geometry instead of browser text metrics', () => {
  const api = loadGeometryApi();
  const field = textFieldWithSelection(
    'R_NUM',
    { x: 2183, y: 790, w: 1200, h: 400 },
    { x: 5.04, y: 3.6, w: 117, h: 39.6 }
  );

  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds([field]))), {
    width: 3383,
    height: 1190,
  });
});

test('calculateImageBounds matches the ClariSoft TEXT_ROTATIONS oracle for 90 and 270 degrees', () => {
  const api = loadGeometryApi();
  const fields = [
    dataMatrixField('Field00', { x: 1342, y: 1192, w: 1767, h: 392 }, true, 0),
    dataMatrixField('Field01', { x: 975, y: 2742, w: 1766, h: 392 }, true, 270),
    dataMatrixField('Field02', { x: 3708, y: 1117, w: 1766, h: 392 }, true, 90),
    dataMatrixField('Field03', { x: 2308, y: 4575, w: 1767, h: 392 }, true, 180),
  ];

  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds(fields))), {
    width: 4100,
    height: 4967,
  });
});

test('calculateImageBounds handles one origin object', () => {
  const api = loadGeometryApi();
  const fields = [dataMatrixField('A', { x: 0, y: 0, w: 1100, h: 1100 })];

  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds(fields))), {
    width: 1100,
    height: 1100,
  });
});

test('calculateImageBounds includes field offsets', () => {
  const api = loadGeometryApi();
  const fields = [dataMatrixField('A', { x: 100, y: 200, w: 500, h: 300 })];

  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds(fields))), {
    width: 600,
    height: 500,
  });
});

test('millimetre geometry is converted to integer CIFF units before calculating the image edge', () => {
  const canvasApi = loadCanvasRotationApi();
  const api = loadGeometryApi();
  // Adding these decimal millimetres first introduces a floating-point tail;
  // the bounds must use exactly the integer values that are written to CIFF.
  const geom = { x: 10.06, y: 8.25, w: 20.17, h: 3.25 };
  const internal = Object.fromEntries(Object.entries(geom).map(([key, value]) => [key, canvasApi.mmToInternal(value)]));
  assert.deepEqual(internal, { x: 1006, y: 825, w: 2017, h: 325 });
  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds([
    { fldType: 'FixedText', printed: true, orientation: 0, geom: internal },
  ]))), { width: 3023, height: 1150 });
});

test('calculateImageBounds takes the furthest edge across multiple fields', () => {
  const api = loadGeometryApi();
  const fields = [
    dataMatrixField('A', { x: 0, y: 0, w: 1100, h: 1100 }),
    dataMatrixField('B', { x: 2000, y: 2300, w: 300, h: 200 }),
  ];

  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds(fields))), {
    width: 2300,
    height: 2500,
  });
});

test('calculateImageBounds shrinks after deleting the furthest field', () => {
  const api = loadGeometryApi();
  const fields = [
    dataMatrixField('A', { x: 0, y: 0, w: 1100, h: 1100 }),
    dataMatrixField('edge', { x: 2000, y: 2300, w: 300, h: 200 }),
  ];
  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds(fields))), {
    width: 2300,
    height: 2500,
  });

  fields.pop();
  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds(fields))), {
    width: 1100,
    height: 1100,
  });
});

test('clarisoft_fix6 visible fields produce 2516 x 2558 and hidden helpers do not expand it', () => {
  const api = loadGeometryApi();
  const fields = [
    dataMatrixField('Field00', { x: 0, y: 0, w: 1100, h: 1100 }),
    dataMatrixField('C1', { x: 1100, y: 0, w: 642, h: 325 }, false),
    dataMatrixField('GTIN', { x: 1100, y: 400, w: 2683, h: 392 }, false),
    dataMatrixField('SN', { x: 1100, y: 1200, w: 1150, h: 392 }, false),
    dataMatrixField('KRIPTO', { x: 1100, y: 2000, w: 767, h: 392 }, false),
    dataMatrixField('C2', { x: 1100, y: 800, w: 317, h: 325 }, false),
    dataMatrixField('C3', { x: 1100, y: 1600, w: 1108, h: 325 }, false),
    dataMatrixField('Field02', { x: 2483, y: 2425, w: 33, h: 133 }),
  ];

  assert.deepEqual(JSON.parse(JSON.stringify(api.calculateImageBounds(fields))), {
    width: 2516,
    height: 2558,
  });
});

test('only hidden fields from the previous automatic column are restacked after resize', () => {
  const api = loadGeometryApi();
  const hiddenA = dataMatrixField('A', { x: 3050, y: 100, w: 1000, h: 300 }, false);
  const hiddenB = dataMatrixField('B', { x: 3050, y: 500, w: 1000, h: 400 }, false, 90);
  const manual = dataMatrixField('manual', { x: 5000, y: 700, w: 1000, h: 300 }, false);

  assert.equal(api.stackHiddenFieldsOutsideTemplate([hiddenA, hiddenB, manual], 3200, {
    previousCanvasWidthInternal: 2900,
    autoColumnOnly: true,
  }), 2);
  const hardware = api.getHardwareAreaBoundsInternal();
  assert.equal(api.isBoundsInsideArea(api.getFieldRenderedBoundsInternal(hiddenA), hardware), true);
  assert.equal(api.isBoundsInsideArea(api.getFieldRenderedBoundsInternal(hiddenB), hardware), true);
  assert.equal(api.boundsOverlapWithGapInternal(
    api.getFieldRenderedBoundsInternal(hiddenA),
    api.getFieldRenderedBoundsInternal(hiddenB)
  ), false);
  assert.deepEqual(manual.geom, { x: 5000, y: 700, w: 1000, h: 300 });
});

test('hidden allocator falls back below the image and keeps every field inside hardware bounds', () => {
  const api = loadGeometryApi();
  api.state.subImage = { width: 2967, height: 1160, maxWidth: 5333, maxHeight: 7500 };
  const printed = dataMatrixField('FieldDM', { x: 1867, y: 33, w: 1100, h: 1100 });
  const gtin = dataMatrixField('GTIN', { x: 8000, y: 2000, w: 2683, h: 392 }, false);
  const rotated = dataMatrixField('SN', { x: 7000, y: 2500, w: 1150, h: 392 }, false, 90);
  const fields = [printed, gtin, rotated];

  const result = api.repackHiddenFieldsWithinHardwareBounds(fields, { forceAll: true });
  assert.deepEqual(Array.from(result.failedFieldNames), []);
  assert.equal(result.placedCount, 2);

  const hardware = api.getHardwareAreaBoundsInternal();
  const gtinBounds = api.getFieldRenderedBoundsInternal(gtin);
  const rotatedBounds = api.getFieldRenderedBoundsInternal(rotated);
  assert.equal(api.isBoundsInsideArea(gtinBounds, hardware), true);
  assert.equal(api.isBoundsInsideArea(rotatedBounds, hardware), true);
  assert.ok(gtinBounds.y >= 1310, 'GTIN is wider than the right corridor and must use the lower region');
  assert.equal(api.boundsOverlapWithGapInternal(gtinBounds, rotatedBounds), false);
});

test('DataMatrix service text fields form a vertical editing column outside a full-size template', () => {
  const api = loadGeometryApi();
  api.state.subImage = {
    width: 5300,
    height: 7500,
    maxWidth: 5333,
    maxHeight: 7500,
    workspaceWidth: 5300,
    workspaceHeight: 7500,
  };
  api.makePreviewNode = () => ({ _ciffPreviewTextStyle: {}, destroy: () => {} });
  api.getTextPreviewSelectionRect = () => ({
    x: api.mmToPx(0.49),
    y: api.mmToPx(0.5),
    width: api.mmToPx(5),
    height: api.mmToPx(2.5),
  });
  const fields = ['С1', 'GTIN', 'С2', 'SN', 'С3', 'KRIPTO'].map((name) => ({
    name,
    fldType: 'FixedText',
    printed: false,
    orientation: 0,
    geom: { x: 0, y: 0, w: 1000, h: 300 },
    calcData: name,
    data: { defaultValue: name, userEnterData: '', textEntryMode: 'fixed' },
    text: { pitch: 8, xMag: 100 },
    barcode: null,
    _konva: null,
  }));

  assert.equal(api.stackHiddenFieldsOutsideTemplate(fields, 5333), fields.length);
  fields.forEach((field, index) => {
    assert.equal(field.geom.x, 5483);
    assert.ok(field.geom.x > 5333, `${field.name} must stay outside the printer workspace`);
    if (index === 0) return;
    const previousBounds = api.getFieldRenderedBoundsInternal(fields[index - 1], new Date(), { forceFresh: true });
    const bounds = api.getFieldRenderedBoundsInternal(field, new Date(), { forceFresh: true });
    assert.ok(bounds.y >= previousBounds.y + previousBounds.h + 100);
  });
});

test('hardware validation ignores the hidden editing column and still validates printed fields', () => {
  const api = loadGeometryApi();
  api.state.subImage = {
    width: 2000,
    height: 2000,
    maxWidth: 5333,
    maxHeight: 7500,
    workspaceWidth: 2000,
    workspaceHeight: 2000,
  };
  const printedOutsideImage = dataMatrixField('printed', { x: 1900, y: 100, w: 300, h: 300 });
  const hiddenInsideHardware = dataMatrixField('hidden-ok', { x: 3000, y: 3000, w: 1000, h: 300 }, false);
  const hiddenOutsideHardware = dataMatrixField('hidden-editor', { x: 5483, y: 7000, w: 600, h: 300 }, false, 90);
  const printedOutsideHardware = dataMatrixField('printed-hardware-bad', { x: 5200, y: 7000, w: 600, h: 300 }, true, 90);
  api.state.fields = [printedOutsideImage, hiddenInsideHardware, hiddenOutsideHardware, printedOutsideHardware];

  const printable = api.validatePrintableFieldsInsideArea();
  assert.deepEqual(Array.from(printable.invalidPrintableFieldNames), ['printed', 'printed-hardware-bad']);
  const hardware = api.validateHardwareFieldsInsideArea();
  assert.deepEqual(Array.from(hardware.invalidHardwareFieldNames), ['printed-hardware-bad']);
});

test('known printer hardware validation uses capabilities without rewriting imported MaxImage values', () => {
  const api = loadGeometryApi();
  api.getKnownPrinterCapabilities = (model) => model === 'DataFlex 6330(53mm)'
    ? { maxImageWidth: 5333, maxImageHeight: 7500, xRes: 0.12 }
    : null;
  api.state.docMeta = { printerModel: 'DataFlex 6330(53mm)' };
  api.state.subImage = {
    width: 2500,
    height: 1200,
    maxWidth: 3200,
    maxHeight: 1200,
    workspaceWidth: 5333,
    workspaceHeight: 7500,
  };
  api.state.fields = [dataMatrixField('inside-known-hardware', { x: 4000, y: 6000, w: 1000, h: 1000 })];

  assert.deepEqual(JSON.parse(JSON.stringify(api.getHardwareAreaBoundsInternal())), {
    x: 0,
    y: 0,
    w: 5333,
    h: 7500,
  });
  assert.deepEqual(Array.from(api.validateHardwareFieldsInsideArea().invalidHardwareFieldNames), []);
  assert.equal(api.state.subImage.maxWidth, 3200);
  assert.equal(api.state.subImage.maxHeight, 1200);
});

test('hidden allocator reports a field that cannot physically fit in the printer workspace', () => {
  const api = loadGeometryApi();
  api.getKnownPrinterCapabilities = () => ({ maxImageWidth: 3200, maxImageHeight: 3000 });
  api.state.subImage = { width: 2000, height: 2000, maxWidth: 3200, maxHeight: 3000 };
  const impossible = dataMatrixField('too-wide', { x: 9000, y: 0, w: 4000, h: 300 }, false);
  const result = api.repackHiddenFieldsWithinHardwareBounds([impossible], { forceAll: true });
  assert.deepEqual(Array.from(result.failedFieldNames), ['too-wide']);
  assert.equal(result.placedCount, 0);
});

test('save refreshes used Image dimensions separately from printer capabilities', () => {
  const api = loadGeometryApi();
  api.ALLOWED_ORIENTATIONS = [0, 90, 180, 270];
  api.toInt = (value, fallback = 0) => {
    const parsed = Number.parseInt(String(value), 10);
    return Number.isFinite(parsed) ? parsed : fallback;
  };
  api.state.fields = [
    dataMatrixField('FieldDM', { x: 83, y: 67, w: 917, h: 917 }),
    dataMatrixField('R_NUM', { x: 2000, y: 800, w: 1200, h: 400 }),
    dataMatrixField('hidden', { x: 5000, y: 6500, w: 1000, h: 300 }, false),
  ];
  api.state.subImage = { imageReference: '1', width: 2841, height: 2558, maxWidth: 5333, maxHeight: 7500, xRes: 0.12, orientation: 0, usedSizeDirty: true };

  const loadFilename = path.join(__dirname, '..', 'public', 'modules', '20-xml-load.js');
  vm.runInContext(fs.readFileSync(loadFilename, 'utf8'), api, { filename: loadFilename });
  const saveFilename = path.join(__dirname, '..', 'public', 'modules', '60-history-save.js');
  vm.runInContext(fs.readFileSync(saveFilename, 'utf8'), api, { filename: saveFilename });
  const source = '<SubImage><SubHeader><ImageWidth>2800</ImageWidth><ImageHeight>2500</ImageHeight><MaxImageWidth>2900</MaxImageWidth><MaxImageHeight>1200</MaxImageHeight></SubHeader></SubImage>';
  const patched = api.patchSubHeaderLossless(source);

  assert.match(patched, /<ImageWidth>3200<\/ImageWidth>/);
  assert.match(patched, /<ImageHeight>1200<\/ImageHeight>/);
  assert.match(patched, /<MaxImageWidth>5333<\/MaxImageWidth>/);
  assert.match(patched, /<MaxImageHeight>7500<\/MaxImageHeight>/);
});

test('saving an untouched file preserves its source used dimensions', () => {
  const api = loadGeometryApi();
  api.ALLOWED_ORIENTATIONS = [0, 90, 180, 270];
  api.toInt = (value, fallback = 0) => {
    const parsed = Number.parseInt(String(value), 10);
    return Number.isFinite(parsed) ? parsed : fallback;
  };
  api.state.fields = [
    textFieldWithSelection(
      'TEAM',
      { x: 2683, y: 125, w: 158, h: 358 },
      { x: 5.04, y: 3.6, w: 12, h: 39.6 }
    ),
  ];
  api.state.subImage = {
    width: 2841,
    height: 2558,
    maxWidth: 2900,
    maxHeight: 1200,
    usedSizeDirty: false,
  };

  const loadFilename = path.join(__dirname, '..', 'public', 'modules', '20-xml-load.js');
  vm.runInContext(fs.readFileSync(loadFilename, 'utf8'), api, { filename: loadFilename });
  const saveFilename = path.join(__dirname, '..', 'public', 'modules', '60-history-save.js');
  vm.runInContext(fs.readFileSync(saveFilename, 'utf8'), api, { filename: saveFilename });
  const source = '<SubImage><SubHeader><ImageWidth>2841</ImageWidth><ImageHeight>2558</ImageHeight><MaxImageWidth>2900</MaxImageWidth><MaxImageHeight>1200</MaxImageHeight></SubHeader></SubImage>';
  const patched = api.patchSubHeaderLossless(source);

  assert.match(patched, /<ImageWidth>2841<\/ImageWidth>/);
  assert.match(patched, /<ImageHeight>2558<\/ImageHeight>/);
});

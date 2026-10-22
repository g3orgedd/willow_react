// Cache native font metrics and vector outlines independently of zoom/position.
// The printer bitmap remains available for verification and unsupported fonts.
const nativeTextPreviewCache = new Map();
const nativeTextPreviewPending = new Map();
const nativeTextPreviewFailures = new Map();
const NATIVE_TEXT_PREVIEW_CACHE_LIMIT = 256;
let nativeTextRefreshScheduled = false;

function getNativeTextRenderResolution() {
  // ClariSoft's editor passes its selected coder/format capabilities to
  // CalculateSize and Draw. SubHeader XRes/YRes remain source metadata; they
  // do not replace those capabilities for native font rendering. Supported
  // DataFlex formats have no resolution overrides in the installed table.
  const capabilities = typeof getKnownPrinterCapabilities === 'function'
    ? getKnownPrinterCapabilities(state.docMeta?.printerModel)
    : null;
  const capabilityX = Number(capabilities?.xRes);
  const capabilityY = Number(capabilities?.yRes ?? capabilities?.xRes);
  if (Number.isFinite(capabilityX) && capabilityX > 0 && Number.isFinite(capabilityY) && capabilityY > 0) {
    return { xRes: capabilityX, yRes: capabilityY, source: 'printer-capabilities' };
  }
  // Keep an explicit fallback for documents whose printer is not represented
  // in our capability registry; do not claim a native target binding for it.
  const sourceX = Number(state.subImage?.xRes);
  const sourceY = Number(state.subImage?.yRes);
  const xRes = Number.isFinite(sourceX) && sourceX > 0 ? sourceX : 0.12;
  return { xRes, yRes: Number.isFinite(sourceY) && sourceY > 0 ? sourceY : xRes, source: 'file-resolution-fallback' };
}

function getNativeTextRequest(field, value) {
  const resolution = getNativeTextRenderResolution();
  const rawXResolution = resolution.xRes;
  const rawYResolution = resolution.yRes;
  const xResolution = rawXResolution > 0 ? Math.round(rawXResolution * 10000) : 1200;
  const yResolution = rawYResolution > 0 ? Math.round(rawYResolution * 10000) : xResolution;
  return {
    text: String(value ?? ''),
    face: getEffectiveTextFontFamily(field),
    pitch: getEffectiveTextPitch(field, 13),
    pitchResolution: Number(field.text?.pitchResolution) || 1,
    bold: Boolean(field.text?.bold),
    italic: Boolean(field.text?.italic),
    xMag: Number(field.text?.xMag) || 100,
    yMag: Number(field.text?.yMag) || 100,
    charSpace: Number(field.text?.charSpace) || 0,
    xRes: xResolution,
    yRes: yResolution,
  };
}

function getNativeTextCacheKey(field, value) {
  return JSON.stringify(getNativeTextRequest(field, value));
}

function scheduleNativeTextPreviewRefresh() {
  if (nativeTextRefreshScheduled) return;
  nativeTextRefreshScheduled = true;
  requestAnimationFrame(() => {
    nativeTextRefreshScheduled = false;
    // Only the current document is repainted; results for another tab stay cached.
    if (typeof renderObjects === 'function' && state.xmlDoc) {
      renderObjects();
      renderUI();
      refreshNativeTextInspectorGeometry();
    }
  });
}

function refreshNativeTextInspectorGeometry() {
  if (typeof getSelectedFields !== 'function' || typeof elPropsPanel === 'undefined' || !elPropsPanel) return;
  const selected = getSelectedFields();
  if (selected.length !== 1) return;
  const field = selected[0];
  const labels = { [t('field.width')]: field.geom.w, [t('field.height')]: field.geom.h };
  elPropsPanel.querySelectorAll('input').forEach((input) => {
    const value = labels[input.getAttribute('aria-label')];
    if (value != null && document.activeElement !== input) input.value = String(internalToMm(value));
  });
  if (typeof updateStatusSelection === 'function') updateStatusSelection(field);
}

function syncNativeTextGeometry(field, entry) {
  if (!field?._nativeTextGeometryDirty || !entry || !field.geom) return false;
  field.geom.w = Math.max(1, Math.round(entry.width * 10000 / entry.request.xRes));
  field.geom.h = Math.max(1, Math.round(entry.height * 10000 / entry.request.yRes));
  if (field._nativeTextFontDirty) {
    const families = { 0: 'DontCare', 16: 'Roman', 32: 'Swiss', 48: 'Modern', 64: 'Script', 80: 'Decorative' };
    const family = families[entry.fontFamily];
    if (family && (family !== 'Swiss' || field.text.family != null)) field.text.family = family;
    if (entry.trueType && field.text.ttSize != null) field.text.ttSize = 1;
    delete field._nativeTextFontDirty;
  }
  delete field._nativeTextGeometryDirty;
  if (state.subImage) state.subImage.usedSizeDirty = true;
  return true;
}

function requestNativeTextPreview(field, value) {
  if (!globalThis.glyphFonts?.render || field.fldType === 'Barcode') return null;
  const request = getNativeTextRequest(field, value);
  const key = JSON.stringify(request);
  const cached = nativeTextPreviewCache.get(key);
  if (cached) {
    nativeTextPreviewCache.delete(key);
    nativeTextPreviewCache.set(key, cached);
    syncNativeTextGeometry(field, cached);
    return cached;
  }
  if ((nativeTextPreviewFailures.get(key) || 0) > Date.now()) return null;
  if (!nativeTextPreviewPending.has(key)) {
    const pending = (async () => {
      const result = await globalThis.glyphFonts.render(request);
      if (!result || !Number.isFinite(result.width) || !Number.isFinite(result.height)) throw new Error('Invalid native text dimensions.');
      let bitmap;
      if (typeof result.outlinePath !== 'string') {
        bitmap = new Image();
        bitmap.src = result.dataUrl;
        await bitmap.decode();
      }
      const entry = { ...result, image: bitmap, request };
      nativeTextPreviewCache.set(key, entry);
      while (nativeTextPreviewCache.size > NATIVE_TEXT_PREVIEW_CACHE_LIMIT) {
        nativeTextPreviewCache.delete(nativeTextPreviewCache.keys().next().value);
      }
      // Re-evaluate keys to reject old results after editing, undo or switching tabs.
      for (const current of state.fields) {
        if (current.fldType !== 'Barcode' && getNativeTextCacheKey(current, makePreviewText(current)) === key) {
          syncNativeTextGeometry(current, entry);
        }
      }
      scheduleNativeTextPreviewRefresh();
    })().catch((error) => {
      nativeTextPreviewFailures.set(key, Date.now() + 10000);
      while (nativeTextPreviewFailures.size > NATIVE_TEXT_PREVIEW_CACHE_LIMIT) {
        nativeTextPreviewFailures.delete(nativeTextPreviewFailures.keys().next().value);
      }
      console.warn('Native text preview unavailable:', error);
    }).finally(() => nativeTextPreviewPending.delete(key));
    nativeTextPreviewPending.set(key, pending);
  }
  return null;
}

async function ensureNativeTextGeometry(fields, now = new Date()) {
  if (!globalThis.glyphFonts?.render) return;
  const prepareValues = () => typeof prepareCiffCalculatedData === 'function'
    ? prepareCiffCalculatedData(fields, now, { fieldByName: state.fieldByName })
    : undefined;
  let calculatedData = prepareValues();
  for (const field of fields) {
    for (let attempt = 0; field._nativeTextGeometryDirty && attempt < 3; attempt++) {
      const value = makePreviewText(field, now, { calculatedData });
      const key = getNativeTextCacheKey(field, value);
      if (attempt === 0) nativeTextPreviewFailures.delete(key);
      if (requestNativeTextPreview(field, value)) break;
      await nativeTextPreviewPending.get(key);
      // A source/user value may change during the asynchronous font request.
      // Reuse the save resolver, and reject a result for the previous payload.
      calculatedData = prepareValues();
      if (getNativeTextCacheKey(field, makePreviewText(field, now, { calculatedData })) !== key) continue;
      syncNativeTextGeometry(field, nativeTextPreviewCache.get(key));
      if (field._nativeTextGeometryDirty) break;
    }
    if (field._nativeTextGeometryDirty) throw new Error('The selected font could not be measured. Please try saving again.');
  }
}

function getNativeTextPositionDot(coordinate, resolution) {
  // ClariSoft uses single-precision MULSS, +/-0.5 and CVTTSS2SI.
  const scaled = Math.fround(Math.fround(Number(coordinate) || 0) * Math.fround(resolution / 10000));
  return Math.trunc(Math.fround(scaled + (scaled < 0 ? -0.5 : 0.5)));
}

function getNativeTextPreviewOffset(field, entry, width, height, fieldWidth, fieldHeight) {
  const x = Number(field.geom?.x) || 0;
  const y = Number(field.geom?.y) || 0;
  const dx = mmToPx(getNativeTextPositionDot(x, entry.request.xRes) * 100 / entry.request.xRes - x / 100);
  const dy = mmToPx(getNativeTextPositionDot(y, entry.request.yRes) * 100 / entry.request.yRes - y / 100);
  // Parent PreviewContent rotates around the rounded CIFF W/H. Account for
  // the native cell's exact dimensions so its rotated corner stays on that dot.
  const nominalWidth = fieldWidth ?? mmToPx((Number(field.geom?.w) || 0) / 100);
  const nominalHeight = fieldHeight ?? mmToPx((Number(field.geom?.h) || 0) / 100);
  if (field.orientation === 90) return { x: dy, y: nominalHeight - height - dx };
  if (field.orientation === 180) return { x: nominalWidth - width - dx, y: nominalHeight - height - dy };
  if (field.orientation === 270) return { x: nominalWidth - width - dy, y: dx };
  return { x: dx, y: dy };
}

function makeNativeTextPreviewNode(field, value, fieldWidth, fieldHeight) {
  const entry = requestNativeTextPreview(field, value);
  if (!entry) return null;
  // Original Draw rotates the dot bitmap before converting each axis to CIFF
  // units. PreviewContent supplies the rotation, so quarter turns must exchange
  // the local scales to preserve that order with unequal target resolutions.
  const quarterTurn = field.orientation === 90 || field.orientation === 270;
  const width = mmToPx(entry.width * 100 / (quarterTurn ? entry.request.yRes : entry.request.xRes));
  const height = mmToPx(entry.height * 100 / (quarterTurn ? entry.request.xRes : entry.request.yRes));
  const offset = getNativeTextPreviewOffset(field, entry, width, height, fieldWidth, fieldHeight);
  const vector = typeof entry.outlinePath === 'string';
  const scaleX = vector ? width / entry.width : 1;
  const scaleY = vector ? height / entry.height : 1;
  const node = vector
    ? new Konva.Path({
      name: 'PreviewValue', data: entry.outlinePath, fill: '#000',
      x: offset.x, y: offset.y, scaleX, scaleY,
      listening: false, perfectDrawEnabled: false,
    })
    : new Konva.Image({
      name: 'PreviewValue', image: entry.image,
      x: offset.x, y: offset.y, width, height,
      listening: false, perfectDrawEnabled: false,
    });
  if (vector) {
    // Selection and rotation use the ClariSoft cell, not individual ink bounds.
    // Canvas draws the outline again at each zoom, without enlarging a bitmap.
    node.getSelfRect = () => ({ x: 0, y: 0, width: entry.width, height: entry.height });
  }
  node._ciffPreviewTextStyle = {
    native: true,
    vector,
    fontFamily: entry.request.face,
    measuredTextBounds: { x: 0, y: 0, width: vector ? entry.width : width, height: vector ? entry.height : height },
    fontSize: vector ? entry.height : height,
    scaleX, scaleY,
  };
  return node;
}

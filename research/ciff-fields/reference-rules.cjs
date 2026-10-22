'use strict';

// Individually recovered rules, not a claim to reimplement every printer renderer.
function sanitizeCalculatedData(value) {
  return String(value ?? '').replace(/[\u0000-\u0008\u000B\u000C\u000E-\u001F]/g, '');
}

function normalizeMsxmlLineEndings(value) {
  return String(value).replace(/\r\n|\r|\n/g, '\r\n');
}

function nativeRound(value) {
  const f = Math.fround(value);
  return Math.trunc(Math.fround(f + (f < 0 ? -0.5 : 0.5)));
}

function resizeDataMatrix({ width, height, columns, rows, xRes, yRes = xRes, quietMargins = false, units = 0 }) {
  const xr = Math.fround(xRes), yr = Math.fround(yRes);
  if (xr <= 0 || yr <= 0 || columns <= 0 || rows <= 0) throw new Error('Positive symbol dimensions and resolution are required.');
  let requestedWidth = width, requestedHeight = height;
  if (units === 1) {
    requestedWidth /= nativeRound(Math.fround(xr * 100)) / 100;
    requestedHeight /= nativeRound(Math.fround(yr * 100)) / 100;
  }
  const fittingColumns = columns + (quietMargins ? 2 : 0);
  const fittingRows = rows + (quietMargins ? 2 : 0);
  let moduleSize = Math.min(Math.trunc(requestedWidth / fittingColumns), Math.trunc(requestedHeight / fittingRows), 500);
  const moduleDots = Math.max(1, Math.trunc(Math.fround(Math.fround(moduleSize) * xr)));
  moduleSize = nativeRound(Math.fround(moduleDots / xr));
  // Original 4204A286 adds a second 2-module margin after the fit calculation.
  // This behavior is specific to that resize path and was executed from the DLL.
  const resultWidth = moduleSize * (fittingColumns + (quietMargins ? 2 : 0));
  const resultHeight = moduleSize * (fittingRows + (quietMargins ? 2 : 0));
  return { moduleSize, width: resultWidth, height: resultHeight, bcH: resultHeight };
}

module.exports = { sanitizeCalculatedData, normalizeMsxmlLineEndings, nativeRound, resizeDataMatrix };

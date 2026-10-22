const test = require('node:test');
const assert = require('node:assert/strict');
const crypto = require('node:crypto');
const fs = require('node:fs');
const path = require('node:path');

const FIXTURE_DIR = path.join(__dirname, 'fixtures', 'ciff');

function readCiff(name) {
  const bytes = fs.readFileSync(path.join(FIXTURE_DIR, name));
  assert.deepEqual(Array.from(bytes.subarray(0, 2)), [0xff, 0xfe]);
  const text = bytes.subarray(2).toString('utf16le');
  const lines = text.split('\r\n');
  assert.equal(lines.length, 3);
  assert.equal(lines[2], '');
  assert.equal((text.match(/(?<!\r)\n|\r(?!\n)/g) || []).length, 0);
  assert.match(lines[0], /^<\?xml\b[^?]*encoding="UTF-16"[^?]*\?>$/i);
  return {
    bytes,
    text,
    line1: lines[0],
    line2: lines[1],
    sha256: crypto.createHash('sha256').update(bytes).digest('hex').toUpperCase(),
  };
}

function firstBlock(xml, tag) {
  return xml.match(new RegExp(`<${tag}\\b[^>]*>[\\s\\S]*?<\\/${tag}>`))?.[0] || '';
}

function firstOpenTag(xml, tag) {
  return xml.match(new RegExp(`<${tag}\\b[^>]*>`))?.[0] || '';
}

function attribute(openTag, name) {
  return openTag.match(new RegExp(`\\s${name}\\s*=\\s*(["'])([\\s\\S]*?)\\1`, 'i'))?.[2] || '';
}

function firstTagText(xml, tag) {
  return xml.match(new RegExp(`<${tag}(?:\\s[^>]*)?>([\\s\\S]*?)<\\/${tag}>`))?.[1]?.trim() ?? null;
}

function numberTag(xml, tag) {
  return Number(firstTagText(xml, tag));
}

function readFields(line2) {
  return (line2.match(/<Field\b[^>]*>[\s\S]*?<\/Field>/g) || []).map((block) => {
    const orientation = Number(firstTagText(block, 'Orientation') || 0);
    const w = numberTag(block, 'W');
    const h = numberTag(block, 'H');
    return {
      name: attribute(firstOpenTag(block, 'Field'), 'Name'),
      hidden: firstTagText(block, 'Displayed') === '0',
      x: numberTag(block, 'X'),
      y: numberTag(block, 'Y'),
      w: orientation === 90 || orientation === 270 ? h : w,
      h: orientation === 90 || orientation === 270 ? w : h,
    };
  });
}

function outside(fields, width, height) {
  return fields.filter((field) => (
    field.x < 0 || field.y < 0 ||
    field.x + field.w > width || field.y + field.h > height
  )).map((field) => field.name);
}

function overlaps(a, b) {
  return a.x < b.x + b.w && a.x + a.w > b.x &&
    a.y < b.y + b.h && a.y + a.h > b.y;
}

function readMetadata(ciff) {
  const header = firstOpenTag(ciff.line2, 'Header');
  const subImageBlock = firstBlock(ciff.line2, 'SubImage');
  const subImage = firstOpenTag(subImageBlock, 'SubImage');
  const subHeaderBlock = firstBlock(subImageBlock, 'SubHeader');
  const subHeader = firstOpenTag(subHeaderBlock, 'SubHeader');
  const mapBlock = firstBlock(ciff.line2, 'Map');
  const map = firstOpenTag(mapBlock, 'Map');
  return {
    designedFor: attribute(header, 'DesignedFor'),
    imageReference: attribute(subImage, 'ImageReference'),
    formatName: attribute(subHeader, 'FormatName'),
    printerFormatName: attribute(subHeader, 'PrinterFormatName'),
    imageWidth: numberTag(subHeaderBlock, 'ImageWidth'),
    imageHeight: numberTag(subHeaderBlock, 'ImageHeight'),
    maxImageWidth: numberTag(subHeaderBlock, 'MaxImageWidth'),
    maxImageHeight: numberTag(subHeaderBlock, 'MaxImageHeight'),
    xRes: firstTagText(subHeaderBlock, 'XRes'),
    orientation: numberTag(subHeaderBlock, 'CurrentOrientation'),
    mappingReference: attribute(map, 'SubIMageRef'),
    mappingValue: firstTagText(mapBlock, 'Map'),
  };
}

test('source regression fixtures remain byte-identical to the analyzed inputs', () => {
  const reference = readCiff('22x22_reference_270days.ciff');
  const broken = readCiff('22x22_1_broken.ciff');
  const zdrava = readCiff('ZDRAVA2.ciff');
  assert.equal(reference.sha256, 'F3D8A3C250D770E9C3DB1B78A6D2A88AF34BC901C02C0D064EC87492BE6D0C82');
  assert.equal(broken.sha256, '4854B2597104A2C0B17BA15846B9CDA21AC95037644FD60D7CD03EDB033BAB12');
  assert.equal(zdrava.sha256, '62C7DB475B5C4B5AF7B779CBACE0CB3372D05AE6FF7025FA62A536ED5E9AB42C');
});

test('ZDRAVA2 separates the used image extent from the ClariSoft printer workspace', () => {
  const zdrava = readCiff('ZDRAVA2.ciff');
  const metadata = readMetadata(zdrava);
  assert.deepEqual(
    [metadata.imageWidth, metadata.imageHeight, metadata.maxImageWidth, metadata.maxImageHeight],
    [2516, 2558, 5333, 7500],
  );

  const fields = readFields(zdrava.line2);
  const printed = fields.filter((field) => !field.hidden);
  assert.equal(Math.max(...printed.map((field) => field.x + field.w)), metadata.imageWidth);
  assert.equal(Math.max(...printed.map((field) => field.y + field.h)), metadata.imageHeight);
  assert.deepEqual(outside(fields, metadata.maxImageWidth, metadata.maxImageHeight), []);
  assert.ok(fields.some((field) => field.hidden && field.y > metadata.imageHeight));
});

test('broken fixture reproduces the printer-profile, metadata, date and hidden-bounds defects', () => {
  const broken = readCiff('22x22_1_broken.ciff');
  const metadata = readMetadata(broken);
  assert.equal(metadata.designedFor, 'DataFlex 6330(53mm) - Continuous');
  assert.equal(metadata.imageReference, '');
  assert.equal(metadata.formatName, '');
  assert.equal(metadata.xRes, null);
  assert.deepEqual(
    [metadata.imageWidth, metadata.imageHeight, metadata.maxImageWidth, metadata.maxImageHeight],
    [2967, 1160, 3200, 1200],
  );
  const fields = readFields(broken.line2);
  assert.deepEqual(
    outside(fields.filter((field) => field.hidden), 5333, 7500),
    ['Field04', 'Field0100', 'C3', 'KRIPTO', 'GTIN', 'SN', 'C1', 'C2', 'PARTY', 'R_NUM', 'Field01'],
  );
  const current = firstBlock(firstBlock(broken.line2, 'DateOffset'), 'CurrentOffset');
  assert.deepEqual(
    [firstTagText(current, 'Day'), firstTagText(current, 'Month'), firstTagText(current, 'Year')],
    ['270', null, null],
  );
});

test('fixed fixture keeps the real image size and passes structural and hardware checks', () => {
  const broken = readCiff('22x22_1_broken.ciff');
  const fixed = readCiff('22x22_1_fixed.ciff');
  const metadata = readMetadata(fixed);
  assert.deepEqual(metadata, {
    designedFor: 'DataFlex 6330(53mm) - Continuous',
    imageReference: '1',
    formatName: 'Default',
    printerFormatName: 'Default',
    imageWidth: 2967,
    imageHeight: 1160,
    maxImageWidth: 5333,
    maxImageHeight: 7500,
    xRes: '0.120000',
    orientation: 0,
    mappingReference: '1',
    mappingValue: '1',
  });

  const fields = readFields(fixed.line2);
  assert.deepEqual(outside(fields, metadata.maxImageWidth, metadata.maxImageHeight), []);
  const hidden = fields.filter((field) => field.hidden);
  for (let index = 0; index < hidden.length; index += 1) {
    for (let otherIndex = index + 1; otherIndex < hidden.length; otherIndex += 1) {
      assert.equal(overlaps(hidden[index], hidden[otherIndex]), false, `${hidden[index].name}/${hidden[otherIndex].name}`);
    }
  }
  const gtin = hidden.find((field) => field.name === 'GTIN');
  assert.ok(gtin.y > metadata.imageHeight, 'wide GTIN helper uses the fallback area below the image');

  const current = firstBlock(firstBlock(fixed.line2, 'DateOffset'), 'CurrentOffset');
  const date = {
    day: Number(firstTagText(current, 'Day')),
    month: Number(firstTagText(current, 'Month')),
    year: Number(firstTagText(current, 'Year')),
  };
  const probe = new Date(Date.UTC(date.year, date.month - 1, date.day));
  assert.equal(probe.getUTCFullYear(), date.year);
  assert.equal(probe.getUTCMonth() + 1, date.month);
  assert.equal(probe.getUTCDate(), date.day);
  assert.notEqual(date.day, 270);

  assert.equal(
    firstTagText(fixed.line2, 'ClStVersionInfo'),
    firstTagText(broken.line2, 'ClStVersionInfo'),
  );
});

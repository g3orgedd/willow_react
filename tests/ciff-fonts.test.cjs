const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const { createProductionCiffRuntime, decodeCiffBytes } = require('./helpers/ciff-production-harness.cjs');

const reference = decodeCiffBytes(fs.readFileSync(path.join(__dirname, 'fixtures', 'conservative', 'constant-text.ciff')));
function encode(xml) {
  return Buffer.concat([Buffer.from([0xff, 0xfe]), Buffer.from(xml, 'utf16le')]);
}
function withText(text, fldType = 'FixedText') {
  let xml = reference.replace(/<Text>[\s\S]*?<\/Text>/, text)
    .replace('<FldType>FixedText</FldType>', `<FldType>${fldType}</FldType>`);
  if (fldType === 'CounterText') {
    xml = xml.replace('<DataType>0</DataType>', '<DataType>4</DataType>')
      .replaceAll('<![CDATA[Use By]]>', '<![CDATA[0001]]>');
  }
  return xml;
}
function fieldXml(xml) {
  return xml.match(/<Field\b[\s\S]*?<\/Field>/)[0];
}
function save(runtime) {
  const result = runtime.save();
  assert.equal(result.prepared.validation.ok, true, JSON.stringify(result.prepared.validation));
  return result.bytes;
}

test('font import keeps Face separate from the native family classification and preserves no-op XML', () => {
  const source = withText('<Text Vendor="text"><Font VendorFont="kept">' +
    '<Face><![CDATA[Times New Roman]]></Face><Family>Roman</Family><Pitch>8</Pitch>' +
    '<PitchResolution>1</PitchResolution><XMag>125</XMag><YMag>80</YMag><TTSize>1</TTSize>' +
    '<TxtDir>LeftToRight</TxtDir><CharSpace>2</CharSpace>' +
    '<VendorMetric><Face>shadow</Face><Pitch>99</Pitch></VendorMetric></Font>' +
    '<Bold Weight="1">1</Bold><Italic>1</Italic><VendorStyle Flag="yes"/></Text>');
  const runtime = createProductionCiffRuntime(encode(source));
  assert.deepEqual(JSON.parse(JSON.stringify(runtime.state.fields[0].text)), {
    face: 'Times New Roman', family: 'Roman', pitch: 8, defaultPitch: 13,
    pitchResolution: 1, xMag: 125, yMag: 80, ttSize: 1, txtDir: 'LeftToRight',
    charSpace: 2, bold: 1, boldWeight: '1', italic: 1,
  });
  assert.equal(fieldXml(decodeCiffBytes(save(runtime))), fieldXml(source));
});

for (const type of ['FixedText', 'DateText', 'OffsetDateText', 'TimeText', 'CounterText']) {
  test(`${type}: selecting a font inserts only Face and survives save/reopen`, () => {
    const source = withText('<Text><Font Vendor="kept"><Pitch>8</Pitch>' +
      '<VendorMetric><Face>shadow</Face></VendorMetric></Font><VendorStyle/></Text>', type);
    const runtime = createProductionCiffRuntime(encode(source));
    runtime.state.fields[0].text.face = 'Courier New';
    const saved = save(runtime);
    const output = fieldXml(decodeCiffBytes(saved));
    assert.equal(output, fieldXml(source).replace('<Pitch>8</Pitch>', '<Face><![CDATA[Courier New]]></Face><Pitch>8</Pitch>'));
    const reopened = createProductionCiffRuntime(saved);
    assert.equal(reopened.state.fields[0].text.face, 'Courier New');
    assert.equal(fieldXml(decodeCiffBytes(save(reopened))), output);
  });
}

for (const text of ['<Text><Font/></Text>', '<Text Vendor="kept"/>', '']) {
  test(`a selected face expands an empty or absent font container (${text || 'no Text'})`, () => {
    const source = withText(text);
    const runtime = createProductionCiffRuntime(encode(source));
    assert.equal(runtime.state.fields[0].text.pitch, null);
    assert.equal(runtime.state.fields[0].text.defaultPitch, 13);
    assert.equal(runtime.context.getEffectiveTextPitch(runtime.state.fields[0]), 13);
    assert.equal(fieldXml(decodeCiffBytes(save(runtime))), fieldXml(source));
    runtime.state.fields[0].text.face = 'Arial Black';
    const output = decodeCiffBytes(save(runtime));
    assert.ok(output.includes('<Font><Face><![CDATA[Arial Black]]></Face></Font>'), output);
    assert.ok(!output.includes('<Pitch>'), output);
    if (text.includes('Vendor=')) assert.ok(output.includes('<Text Vendor="kept">'));
  });
}

test('a changed font safely round-trips CDATA terminators and style changes retain opaque children', () => {
  const runtime = createProductionCiffRuntime(encode(withText('<Text><Font/><Bold Weight="2">1</Bold>' +
    '<Italic>1</Italic><VendorStyle><Face>shadow</Face></VendorStyle></Text>')));
  const field = runtime.state.fields[0];
  field.text.face = 'Vendor ]]> & "Font"';
  field.text.bold = false;
  field.text.italic = false;
  const saved = save(runtime);
  const output = decodeCiffBytes(saved);
  assert.ok(output.includes('<Bold Weight="2">0</Bold><Italic>0</Italic>'), output);
  assert.ok(output.includes('<VendorStyle><Face>shadow</Face></VendorStyle>'));
  assert.equal(createProductionCiffRuntime(saved).state.fields[0].text.face, field.text.face);
});

test('preview measurement and drawing use the same face, style and YMag for every text type', () => {
  const runtime = createProductionCiffRuntime(encode(reference));
  const measured = [];
  class TextNode {
    constructor(options) { this.options = options; measured.push(options); }
    getClientRect() { return { x: 0, y: 0, width: this.options.text.length * 12, height: this.options.fontSize }; }
    x(value) { if (value != null) this.options.x = value; return this.options.x; }
    y(value) { if (value != null) this.options.y = value; return this.options.y; }
  }
  runtime.context.Konva = { Text: TextNode };
  for (const fldType of ['FixedText', 'DateText', 'OffsetDateText', 'TimeText', 'CounterText']) {
    const field = { fldType, geom: { w: 1000, h: 400 }, data: { defaultValue: 'AB' },
      text: { face: 'Courier New', pitch: 10, xMag: 130, yMag: 150, bold: true, italic: true } };
    const style = runtime.context.getPreviewTextStyle(field, 120, 48, 'AB');
    assert.equal(style.fontFamily, '"Courier New", sans-serif');
    assert.equal(style.fontStyle, 'italic bold');
    assert.equal(style.scaleY, 1.5);
    assert.equal(measured.at(-1).fontFamily, style.fontFamily);
    assert.equal(measured.at(-1).fontStyle, style.fontStyle);
    const node = runtime.context.makePreviewNode(field, 120, 48);
    assert.equal(node.options.fontFamily, style.fontFamily);
    assert.equal(node.options.fontStyle, style.fontStyle);
    assert.equal(node.options.scaleY, style.scaleY);
  }
});

test('canvas font CSS quotes the complete face rather than interpreting a font name as CSS', () => {
  const context = {};
  vm.createContext(context);
  vm.runInContext(fs.readFileSync(path.join(__dirname, '..', 'public', 'modules', '02-fonts.js'), 'utf8'), context);
  assert.equal(context.getTextCanvasFontFamily({ text: { face: 'A, "B"' } }), '"A, \\"B\\"", sans-serif');
  assert.equal(context.getEffectiveTextFontFamily({ text: {} }), 'Arial');
});

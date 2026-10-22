const test = require('node:test');
const assert = require('node:assert/strict');
const { createProductionCiffRuntime } = require('./helpers/ciff-production-harness.cjs');

function importXml(fields, header = '') {
  const xml = '<?xml version="1.0" encoding="UTF-16"?>\r\n' +
    '<ImageDesign Version="23"><Header DesignedFor="DataFlex 6330(53mm) - Continuous">' +
    header + '</Header><SubImage><SubHeader><ImageWidth>1500</ImageWidth>' +
    '<ImageHeight>1150</ImageHeight><MaxImageWidth>5333</MaxImageWidth>' +
    '<MaxImageHeight>7500</MaxImageHeight><XRes>0.120000</XRes></SubHeader>' +
    fields + '</SubImage></ImageDesign>\r\n';
  return createProductionCiffRuntime(Buffer.concat([
    Buffer.from([0xff, 0xfe]), Buffer.from(xml, 'utf16le'),
  ]));
}

function field(name, data, extra = '', type = 'FixedText') {
  return `<Field Name="${name}"><FldType>${type}</FldType><X>100</X><Y>200</Y>` +
    '<W>500</W><H>325</H>' + extra + `<Data>${data}</Data></Field>`;
}

function plain(value) {
  return JSON.parse(JSON.stringify(value));
}

test('CIFF import distinguishes absent Ln and Object attributes from explicit zero and empty values', () => {
  const runtime = importXml(
    field('Field00', '<Object><DataType>0</DataType><Default>Use By</Default></Object>') +
    field('Field02', '<Object Static="0" Parse="0" Reference=""><DataType>0</DataType></Object>', '<Ln>0</Ln>') +
    field('Field11', '<Object Static="1" Parse="1" Reference="Ref"><DataType>6</DataType><FixedLen/></Object>', '<Ln>1</Ln>'),
  );
  assert.deepEqual(Array.from(runtime.state.fields, (f) => ({
    ln: f.ln, staticAttr: f.data.staticAttr, parseAttr: f.data.parseAttr,
    referenceAttr: f.data.referenceAttr, fixedLen: f.data.fixedLen,
  })), [
    { ln: null, staticAttr: null, parseAttr: null, referenceAttr: null, fixedLen: false },
    { ln: 0, staticAttr: '0', parseAttr: '0', referenceAttr: '', fixedLen: false },
    { ln: 1, staticAttr: '1', parseAttr: '1', referenceAttr: 'Ref', fixedLen: true },
  ]);
});

test('CIFF import retains external SrcData text independently of Default and CalcData', () => {
  const sql = '\n  SELECT [Description]\n  FROM [JOBS]\n  WHERE [Code] = ##PRODUCTCODE##\n';
  const source = '<SrcData Future="retained"><ConnStr><![CDATA[ Table & Index ]]></ConnStr>' +
    `<SrcSQL><![CDATA[${sql}]]></SrcSQL><FutureSource/></SrcData>`;
  const runtime = importXml(field('Field02', '<Object Static="0" Reference=""><DataType>6</DataType>' +
    '<Default><![CDATA[Description??????????????]]></Default><FixedLen/>' + source + '</Object>',
    '<CalcData><![CDATA[Calculated description]]></CalcData>'));
  const f = runtime.state.fields[0];
  assert.equal(f.fldType, 'FixedText');
  assert.equal(f.data.dataType, 6);
  assert.equal(f.data.textEntryMode, 'fixed');
  assert.deepEqual(plain(f.data.srcData), { connStr: ' Table & Index ', srcSQL: sql });
  assert.equal(f.data.defaultValue, 'Description??????????????');
  assert.equal(f.calcData, 'Calculated description');
  assert.equal(runtime.state.line2.includes(source), true);
});

test('CIFF import retains SrcData child absence separately from an explicitly empty child', () => {
  const { state } = importXml(
    field('Missing', '<Object><DataType>6</DataType></Object>') +
    field('EmptySource', '<Object><DataType>6</DataType><SrcData/></Object>') +
    field('EmptyConnection', '<Object><DataType>6</DataType><SrcData><ConnStr/></SrcData></Object>'),
  );
  assert.deepEqual(plain(state.fields.map((f) => f.data.srcData)), [
    null, { connStr: null, srcSQL: null }, { connStr: '', srcSQL: null },
  ]);
});

test('CIFF import ignores unknown nested elements that reuse known field and data tag names', () => {
  const xml = '<Field Name="Field11"><Future><FldType>DateText</FldType><X>9999</X><Ln>9</Ln>' +
    '<CalcData>Wrong preview</CalcData><Data><Object><DataType>2</DataType></Object></Data>' +
    '<Text><Font><Pitch>99</Pitch></Font></Text></Future><FldType>FixedText</FldType>' +
    '<X>100</X><Y>200</Y><W>500</W><H>325</H><CalcData>Actual preview</CalcData>' +
    '<Data><Object Reference=""><Future><DataType>6</DataType><Default>Wrong default</Default>' +
    '<FixedLen/><VarText/><OffsetDate SrcOffset="Wrong"/><SrcData/></Future>' +
    '<DataType>0</DataType><Default>Actual default</Default></Object></Data>' +
    '<Text><Font><Pitch>8</Pitch></Font></Text></Field>';
  const { state } = importXml(xml);
  const f = state.fields[0];
  assert.equal(f.fldType, 'FixedText');
  assert.equal(f.geom.x, 100);
  assert.equal(f.ln, null);
  assert.equal(f.calcData, 'Actual preview');
  assert.equal(f.data.dataType, 0);
  assert.equal(f.data.defaultValue, 'Actual default');
  assert.equal(f.data.fixedLen, false);
  assert.equal(f.data.hasVarText, false);
  assert.equal(f.data.offsetRef, null);
  assert.equal(f.data.srcData, null);
  assert.equal(f.text.pitch, 8);
});

test('CIFF import resolves offset configuration by source name regardless of Header order', () => {
  const useBy = '<DateOffset Name="UseBy"><DefaultOffset><Day>30</Day></DefaultOffset></DateOffset>';
  const sellBy = '<DateOffset Name="SellBy"><DefaultOffset><Day>7</Day></DefaultOffset></DateOffset>';
  const hidden = '<Future><DateOffset Name="Wrong"><DefaultOffset><Day>999</Day></DefaultOffset></DateOffset></Future>';
  const xml = field('Field05', '<Object Static="0" Parse="1" Reference=""><DataType>3</DataType>' +
    '<Default><![CDATA[dd\' \'cl:MMM]]></Default><OffsetDate SrcOffset="SellBy"/></Object>',
    '<CalcData>19 APR</CalcData>', 'OffsetDateText');
  for (const header of [useBy + sellBy, sellBy + useBy]) {
    const { state } = importXml(xml, hidden + header);
    assert.equal(state.dateOffsets.length, 2);
    assert.equal(state.fields[0].data.offsetRef, 'SellBy');
    assert.equal(state.dateOffsets.find((offset) => offset.name === state.fields[0].data.offsetRef).default.d, 7);
    assert.equal(state.fields[0].data.defaultValue, "dd' 'cl:MMM");
    assert.equal(state.fields[0].calcData, '19 APR');
  }
});

test('CIFF source field identifiers, insertion order, nullable values and external configuration survive a snapshot', () => {
  const object = '<Object Static="0"><DataType>6</DataType><SrcData>' +
    '<ConnStr>Connection</ConnStr><SrcSQL>SELECT [Description]</SrcSQL></SrcData></Object>';
  const runtime = importXml(['Field00', 'Field02', 'Field11', 'Field03'].map((name) => field(name, object)).join(''));
  const snapshot = runtime.context.snapshotState();
  runtime.state.fields[2].name = 'Edited';
  runtime.state.fields[2].data.srcData.srcSQL = 'Changed';
  runtime.context.restoreFromSnapshot(snapshot, { render: false });
  assert.deepEqual(Array.from(runtime.state.fields, (f) => f.name), ['Field00', 'Field02', 'Field11', 'Field03']);
  assert.equal(runtime.state.fields[2].sourceName, 'Field11');
  assert.equal(runtime.state.fields[2].ln, null);
  assert.equal(runtime.state.fields[2].data.referenceAttr, null);
  assert.equal(runtime.state.fields[2].data.srcData.srcSQL, 'SELECT [Description]');
});

// Read-only audit: real production parsers/serializers and geometry functions,
// through existing Node harnesses; no native UI, GDI or browser screenshots.
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const crypto = require('node:crypto');
const { createRequire } = require('node:module');
const root = path.resolve(__dirname, '../../..');
const output = __dirname;
const read = relative => fs.readFileSync(path.join(root, relative), 'utf8');
const writeJson = (name, value) => fs.writeFileSync(path.join(output, name), JSON.stringify(value, null, 2));
const hash = bytes => crypto.createHash('sha256').update(bytes).digest('hex');
function exposeTestHelper(relative, exports) {
  const filename = path.join(root, relative);
  const source = fs.readFileSync(filename, 'utf8');
  const stop = source.indexOf('\ntest(');
  if (stop < 0) throw new Error('Missing first test marker: ' + relative);
  const context = vm.createContext({ require: createRequire(filename), __dirname:path.dirname(filename), console, Buffer });
  vm.runInContext(source.slice(0, stop) + '\nglobalThis.auditApi = {' + exports + '};', context, { filename });
  return context.auditApi;
}
const { loadRuntime, syntheticXml } = exposeTestHelper('tests/ciff-template-dimensions.test.cjs', 'loadRuntime,syntheticXml');
const { loadCanonicalCiffApi } = exposeTestHelper('tests/ciff-canonical-generation.test.cjs', 'loadCanonicalCiffApi');
const simpleField = ({name='A',x=100,y=200,w=500,h=400,printed=true,orientation=0}={}) =>
 `<Field Name="${name}"><FldType>FixedText</FldType>${printed?'':'<Displayed>0</Displayed>'}<X>${x}</X><Y>${y}</Y><W>${w}</W><H>${h}</H>${orientation?`<Orientation>${orientation}</Orientation>`:''}<CalcData><![CDATA[A]]></CalcData><Data><Object Reference=""><DataType>0</DataType><Default><![CDATA[A]]></Default></Object></Data><Text><Font><Pitch>10</Pitch></Font></Text></Field>`;
const scalar = (xml, name) => xml.match(new RegExp('<'+name+'>([^<]*)</'+name+'>'))?.[1] ?? null;
function collect(runtime) {
  return JSON.parse(JSON.stringify({
    subImage:runtime.state.subImage,
    canvas:[runtime.context.getCanvasInternalWidth(), runtime.context.getCanvasInternalHeight()],
    imageTags:Object.fromEntries(['ImageWidth','ImageHeight','MaxImageWidth','MaxImageHeight','ImageRotation','AutoSize','CurrentOrientation'].map(name=>[name,scalar(runtime.state.line2,name)])),
    bounds:runtime.context.calculateImageBounds(runtime.state.fields, runtime.state.subImage.width, runtime.state.subImage.height),
    grid:runtime.grid[0]?.attrs,
    fields:runtime.state.fields.map(f=>({name:f.name,printed:f.printed,geom:f.geom,orientation:f.orientation})),
  }));
}
const cases = [
  {name:'Image_small_Max_large_noop', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField()}},
  {name:'printed_outside_Max_unchanged', options:{imageWidth:2500,imageHeight:2600,width:1600,height:1600,fields:simpleField({x:2400,y:2500,w:100,h:100})}},
  {name:'printed_outside_Max_edited', options:{imageWidth:2500,imageHeight:2600,width:1600,height:1600,fields:simpleField({x:2400,y:2500,w:100,h:100})}, edit:r=>r.state.fields[0].geom.x++},
  {name:'printed_inside_move_recomputes_Image_only', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField()}, edit:r=>r.state.fields[0].geom.x+=100},
  {name:'hidden_outlier_edited_does_not_change_Image', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField()+simpleField({name:'HIDDEN',x:9000,y:10000,w:500,h:400,printed:false})}, edit:r=>r.state.fields[1].geom.x++},
  {name:'last_printed_removed_retains_Image_fallback', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField()+simpleField({name:'HIDDEN',printed:false})}, edit:r=>{r.state.fields=r.state.fields.filter(f=>!f.printed);r.state.fieldByName=new Map(r.state.fields.map(f=>[f.name,f]));r.state.subImage.usedSizeDirty=true;}},
  {name:'field_rotation90_extents', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField({orientation:90})}, edit:r=>r.state.fields[0].geom.x++},
  {name:'missing_Max_falls_back_to_Image', options:{imageWidth:2100,imageHeight:3100,width:null,height:null}},
  {name:'missing_all_sizes_profile_workspace_but_save_rejects_Image0', options:{imageWidth:null,imageHeight:null,width:null,height:null}},
  {name:'orientation90_metadata_does_not_rotate_workspace', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,orientation:90,fields:simpleField()}},
  {name:'AutoSize1_preserved_but_not_used_for_workspace', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField()}, modifyXml:xml=>xml.replace('<CurrentOrientation>', '<AutoSize>1</AutoSize><CurrentOrientation>')},
  {name:'negative_coordinate_edited_rejected', options:{imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField({x:-100,w:50})}, edit:r=>r.state.fields[0].geom.x--},
];
const results=[];
for (const entry of cases) {
  let xml=syntheticXml(entry.options); if(entry.modifyXml)xml=entry.modifyXml(xml);
  const runtime=loadRuntime(xml);runtime.context.renderGrid();
  const loaded=collect(runtime); if(entry.edit)entry.edit(runtime);
  const saved=runtime.save(new Date(2026,9,21,12,0,0));
  fs.writeFileSync(path.join(output,entry.name+'.input.ciff'),Buffer.concat([Buffer.from([255,254]),Buffer.from(xml,'utf16le')]));
  fs.writeFileSync(path.join(output,entry.name+'.output.ciff'),saved.bytes);
  results.push({name:entry.name,loaded,afterSave:collect(runtime),preparedTags:Object.fromEntries(['ImageWidth','ImageHeight','MaxImageWidth','MaxImageHeight','ImageRotation','AutoSize','CurrentOrientation'].map(name=>[name,scalar(saved.prepared.line2,name)])),validation:saved.prepared.validation,outputSha256:hash(saved.bytes)});
}
writeJson('dimension-probes.json',{date:'2026-10-21',scope:'Production parser/save/geometry, synthetic XML. Existing harness replaces unrelated DOM/Konva; text bounds fall back to stored nominal geometry. This is not a screenshot or native font run.',cases:results});
const api=loadCanonicalCiffApi();
const newFields=[
 ['emptyFixed',api.createFixedTextField({name:'Empty',value:''})],
 ['fixed',api.createFixedTextField({name:'Fixed',value:'A'})],
 ['userFixed3',api.createServerVariableField({name:'User',value:'A',maxChars:3})],
 ['explicitMax0',api.createFixedTextField({name:'Max0',value:'A',maxChars:0})],
 ['explicitLn0',api.createFixedTextField({name:'Ln0',value:'A',ln:0})],
 ['fontNativeDefaults',api.createFixedTextField({name:'FontDefaults',value:'A',pitch:13,xMag:100})],
 ['currentDate',api.createCurrentDateField({name:'Date'})],
 ['currentTime',api.createCurrentTimeField({name:'Time'})],
 ['counter',api.createBaseField({name:'Counter',fldType:'CounterText',value:'0001'})],
];
writeJson('new-field-probes.json',{date:'2026-10-21',scope:'Actual new-field factories and buildFieldXmlOneLine. New XML only, no original COM execution.',cases:newFields.map(([name,field])=>({name,model:field,xml:api.buildFieldXmlOneLine(field)}))});
const metadataInput=syntheticXml({imageWidth:600,imageHeight:700,width:2000,height:3000,fields:simpleField()})
 .replace('Version="23"','Version="24"')
 .replace(' - Continuous"/>',' - Continuous" Units="Millimetres" DesignedWith="native-test" OverrideAll="1"><UnmodeledHeader>KEEP</UnmodeledHeader></Header>')
 .replace('PrinterFormatName="Default"','PrinterFormatName="Default" PrinterType="Other Printer"')
 .replace('<CurrentOrientation>','<YRes>0.240000</YRes><AutoSize>1</AutoSize><ImageMirror>1</ImageMirror><ImageInverse>1</ImageInverse><LastUpdated>21/10/2026</LastUpdated><CurrentOrientation>');
const metadataResults=[];
for(const changeTarget of [false,true]) {
 const runtime=loadRuntime(metadataInput);
 if(changeTarget)runtime.context.updateTemplateTarget('DataFlex 6320(32mm)','Intermittent');
 const saved=runtime.save(new Date(2026,9,21,12,0,0));
 const name=changeTarget?'metadata_target_changed':'metadata_import_noop';
 fs.writeFileSync(path.join(output,name+'.input.ciff'),Buffer.concat([Buffer.from([255,254]),Buffer.from(metadataInput,'utf16le')]));
 fs.writeFileSync(path.join(output,name+'.output.ciff'),saved.bytes);
 metadataResults.push({name,model:JSON.parse(JSON.stringify({docMeta:runtime.state.docMeta,subImage:runtime.state.subImage})),validation:saved.prepared.validation,xml:saved.prepared.line2});
}
writeJson('metadata-probes.json',{date:'2026-10-21',scope:'Production import/save, unknown header/SubHeader properties and target change; no native GUI.',cases:metadataResults});
writeJson('source-manifest.json',{date:'2026-10-21',version:JSON.parse(read('package.json')).version,files:['package.json','public/modules/00-core.js','public/modules/01-ciff-compatibility.js','public/modules/04-native-text-preview.js','public/modules/10-canvas-ui.js','public/modules/20-xml-load.js','public/modules/30-rendering.js','public/modules/40-editor.js','public/modules/45-template-preset.js','public/modules/60-history-save.js','public/modules/70-template-tabs.js','public/modules/clst/encryption.js','public/modules/clst/tag-data.js','public/modules/clst/calculated-data.js','public/modules/clst/version-info.js','electron/fonts.cjs','electron/font-renderer.ps1'].map(file=>({file,sha256:hash(fs.readFileSync(path.join(root,file)))}))});
console.log(JSON.stringify({dimensionCases:results.length,fieldCases:newFields.length,output}));

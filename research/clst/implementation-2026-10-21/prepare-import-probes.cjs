const fs=require('node:fs'),path=require('node:path'),vm=require('node:vm');
const root=path.resolve(__dirname,'../../..');
const {collectSourceEvidence}=require(path.join(root,'scripts/inspect-clst.cjs'));
const context=vm.createContext({});
for(const file of ['encryption','tag-data','version-info'])vm.runInContext(fs.readFileSync(path.join(root,`public/modules/clst/${file}.js`),'utf8'),context);
const build=vm.runInContext('buildClStVersionInfoDebugInfo',context);
const names=['first-subimage-charref-cr','first-default-charref-cr','first-user-charref-cr','second-subimage-literal-crlf','second-subimage-charref-cr'];
const rows=[];
for(const name of names){
 const xml=fs.readFileSync(path.join(__dirname,`source-${name}.ciff`)).subarray(2).toString('utf16le');
 const evidence=collectSourceEvidence(xml);
 const values=evidence.fieldSnapshots.map(field=>({calculatedData:field.calcData??''}));
 const token=build({dateOffsets:[],subImages:[{fields:values}]},new Date(),{mask:values.length===2?'2':'1'}).clStVersionInfo;
 const output=xml.replace(/<Header([^>]*)\/>/,`<Header$1><ClStVersionInfo>${token}</ClStVersionInfo></Header>`);
 const file=path.join(__dirname,`import-probe-${name}.ciff`);
 fs.writeFileSync(file,Buffer.concat([Buffer.from([255,254]),Buffer.from(output,'utf16le')]));
 rows.push({name,file});
}
fs.writeFileSync(path.join(__dirname,'native-import-inputs.json'),JSON.stringify(rows,null,2)+'\n');

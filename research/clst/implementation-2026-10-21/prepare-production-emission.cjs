'use strict';
const fs=require('node:fs'),path=require('node:path'),vm=require('node:vm');
const root=path.resolve(__dirname,'../../..');
const ctx=vm.createContext({});
for(const file of ['encryption','tag-data','version-info'])vm.runInContext(fs.readFileSync(path.join(root,`public/modules/clst/${file}.js`),'utf8'),ctx);
const build=vm.runInContext('buildClStVersionInfoDebugInfo',ctx),decode=vm.runInContext('decodeClStVersionInfo',ctx);
const units=row=>String.fromCharCode(...(row.calculatedDataUnits??[]));
const report=JSON.parse(fs.readFileSync(path.join(__dirname,'native-com-results.json'),'utf8'));
const emitted=[],comparisons=[];
for(const row of report.cases){
 if(row.status!=='ok')throw new Error(row.name+': native oracle failed');
 const groups=[];
 for(const f of row.before){while(groups.length<f.subImageIndex)groups.push({fields:[]});groups[f.subImageIndex-1].fields.push({name:f.name,calculatedData:units(f)});}
 const input=JSON.parse(fs.readFileSync(path.join(__dirname,'native-inputs.json'),'utf8')).find(x=>x.name===row.name);
 while(groups.length<input.subImages.length)groups.push({fields:[]});
 const template={dateOffsets:[],subImages:groups};
 const decoded=decode(row.nativeToken,{fieldCount:row.before.length});
 const actual=build(template,new Date('2026-10-21T00:00:00Z'),{mask:decoded.maskHex});
 comparisons.push({name:row.name,mask:decoded.maskHex,fieldCount:row.before.length,exactMatch:actual.clStVersionInfo===row.nativeToken,tagDataUnits:Array.from({length:actual.tagData.length},(_,i)=>actual.tagData.charCodeAt(i)),nativeToken:row.nativeToken,productionToken:actual.clStVersionInfo});
 const source=fs.readFileSync(path.join(__dirname,row.file)).subarray(2).toString('utf16le');
 for(const kind of ['native-mask','drawn-mask','optional','corrupt']){
  const file=path.join(__dirname,`emitted-${row.name}-${kind}.ciff`);
  const options=kind==='native-mask'?{mask:decoded.maskHex}:kind==='optional'?{mask:decoded.maskHex,includeFileMetadata:true,sourcePath:file}:{nextMod:bound=>(bound-1)};
  const token=kind==='corrupt'?'invalid-token':build(template,new Date('2026-10-21T00:00:00Z'),options).clStVersionInfo;
  const xml=source.replace(/<ClStVersionInfo>[\s\S]*?<\/ClStVersionInfo>/,`<ClStVersionInfo>${token}</ClStVersionInfo>`);
  fs.writeFileSync(file,Buffer.concat([Buffer.from([255,254]),Buffer.from(xml,'utf16le')]));
  emitted.push({name:row.name,kind,file,token,expectedValidation:kind==='corrupt'?'80040241':'00000000',expectedFields:row.before});
 }
}
fs.writeFileSync(path.join(__dirname,'production-comparison.json'),JSON.stringify({method:'Production core compared to actual COM generator using exact native CalculatedData snapshot and selected mask',cases:comparisons},null,2)+'\n');
fs.writeFileSync(path.join(__dirname,'production-emitted-inputs.json'),JSON.stringify(emitted,null,2)+'\n');
console.log(JSON.stringify({nativeGeneratedCases:comparisons.length,exactMatched:comparisons.filter(x=>x.exactMatch).length,emitted:emitted.length}));
if(comparisons.some(x=>!x.exactMatch))process.exitCode=1;

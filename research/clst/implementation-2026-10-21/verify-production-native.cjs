'use strict';
const fs=require('node:fs'),path=require('node:path'),vm=require('node:vm'),assert=require('node:assert/strict');
const root=path.resolve(__dirname,'../../..');
const ctx=vm.createContext({});
for(const file of ['encryption','tag-data','version-info'])vm.runInContext(fs.readFileSync(path.join(root,`public/modules/clst/${file}.js`),'utf8'),ctx);
const build=vm.runInContext('buildClStVersionInfoDebugInfo',ctx),decode=vm.runInContext('decodeClStVersionInfo',ctx);
const input=JSON.parse(fs.readFileSync(path.join(__dirname,'production-emitted-inputs.json'),'utf8'));
const source=JSON.parse(fs.readFileSync(path.join(__dirname,'production-native-validation.json'),'utf8'));
const fieldValue=row=>String.fromCharCode(...(row.calculatedDataUnits??[]));
const results=[];
for(const row of source.cases){
 const original=input.find(x=>x.file===row.file);
 assert.ok(original,row.file);
 if(row.kind==='corrupt'){
  assert.equal(row.status,'rejected');assert.equal(row.loadHresult,'80040241');
  results.push({name:row.name,kind:row.kind,originalComLoadRejected:true});continue;
 }
 assert.equal(row.status,'ok',row.error);
 assert.equal(row.validate,'00000000');assert.equal(row.validate2,'00000000');
 assert.equal(row.loadedToken,original.token);
 assert.equal(row.sourceSha256,row.sourceSha256After);
 assert.equal(row.loadedFields.length,original.expectedFields.length);
 let controlFiltering=false;
 for(let i=0;i<row.loadedFields.length;i++){
  const actual=row.loadedFields[i],expected=original.expectedFields[i];
  assert.equal(actual.name,expected.name);assert.equal(actual.subImageIndex,expected.subImageIndex);
  const nativeBefore=fieldValue(expected),loaded=fieldValue(actual);
  if(loaded!==nativeBefore){
   const xmlRoundtrip=Array.from(nativeBefore).filter(x=>x.charCodeAt(0)>31||'\t\r\n'.includes(x)).join('').replace(/\r\n?/g,'\n');
   assert.equal(loaded,xmlRoundtrip,row.name+': unexpected CalcData alteration');controlFiltering=true;
  }
 }
 const groups=[];
 for(const f of row.loadedFields){while(groups.length<f.subImageIndex)groups.push({fields:[]});groups[f.subImageIndex-1].fields.push({name:f.name,calculatedData:fieldValue(f)});}
 // All fixture sources contain at least the first SubImage, including n=0.
 if(!groups.length)groups.push({fields:[]});
 const decoded=decode(row.regeneratedToken,{fieldCount:row.loadedFields.length,sourcePath:row.file});
 const actual=build({dateOffsets:[],subImages:groups},new Date('2026-10-21T00:00:00Z'),{mask:decoded.maskHex,includeFileMetadata:decoded.includeFileMetadata,sourcePath:row.file});
 assert.equal(actual.clStVersionInfo,row.regeneratedToken,row.name+': original GetXml recomposition differs');
 results.push({name:row.name,kind:row.kind,originalLoadAndBothValidatorsAccepted:true,originalGetXmlRecomposedByProduction:true,mask:decoded.maskHex,optional:decoded.includeFileMetadata,controlFiltering,sourceHashUnchanged:true});
}
const report={method:'Original COM load, both validators and GetXml regeneration tested against production core with actual loaded fields',accepted:results.filter(x=>x.originalLoadAndBothValidatorsAccepted).length,negativeControlsRejected:results.filter(x=>x.originalComLoadRejected).length,cases:results};
fs.writeFileSync(path.join(__dirname,'production-native-verification.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({accepted:report.accepted,negativeControlsRejected:report.negativeControlsRejected,allOriginalRegenerationsRecomposed:true}));

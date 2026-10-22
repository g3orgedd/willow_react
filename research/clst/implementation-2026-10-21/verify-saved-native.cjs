'use strict';
const fs=require('node:fs'),path=require('node:path'),vm=require('node:vm'),assert=require('node:assert/strict');
const root=path.resolve(__dirname,'../../..');
const {collectSourceEvidence}=require(path.join(root,'scripts/inspect-clst.cjs'));
const {ComparatorDomParser}=require(path.join(root,'tests/helpers/ciff-production-harness.cjs'));
const ctx=vm.createContext({});
for(const file of ['encryption','tag-data','version-info'])vm.runInContext(fs.readFileSync(path.join(root,`public/modules/clst/${file}.js`),'utf8'),ctx);
const build=vm.runInContext('buildClStVersionInfoDebugInfo',ctx),decode=vm.runInContext('decodeClStVersionInfo',ctx);
const saved=JSON.parse(fs.readFileSync(path.join(__dirname,'save-pipeline-results.json'),'utf8'));
const loaded=JSON.parse(fs.readFileSync(path.join(__dirname,'saved-native-validation.json'),'utf8'));
const fromUnits=value=>String.fromCharCode(...(value??[]));
const normalizeXml=value=>value.replace(/\r\n?/g,'\n');
const results=[];
for(const row of loaded.cases){
 assert.equal(row.status,'ok',row.name+': '+row.error);assert.equal(row.validate,'00000000');assert.equal(row.validate2,'00000000');
 assert.equal(row.sourceSha256,row.sourceSha256After);
 const source=saved.cases.find(x=>x.file===row.file);
 assert.equal(source.token,row.loadedToken);
 const xml=fs.readFileSync(row.file).subarray(2).toString('utf16le');
 // XML normalizes literal line endings before resolving numeric references.
 const parsedXml=normalizeXml(xml);
 const evidence=collectSourceEvidence(parsedXml);
 assert.equal(row.loadedFields.length,evidence.fieldSnapshots.length);
 for(let index=0;index<row.loadedFields.length;index++){
  assert.equal(row.loadedFields[index].name,evidence.fieldSnapshots[index].name);
  assert.equal(fromUnits(row.loadedFields[index].calculatedDataUnits),normalizeXml(evidence.fieldSnapshots[index].calcData??''),`${row.name} field ${index}: original load changed CalcData`);
 }
 if(row.afterNativeResolve){
  for(let index=0;index<row.loadedFields.length;index++)assert.equal(fromUnits(row.afterNativeResolve[index].calculatedDataUnits),fromUnits(row.loadedFields[index].calculatedDataUnits),row.name+': original ResolveField changed the production calculated data');
 }
 const rawFirst=new Map(source.rawCalculatedData.map(x=>[x.name,fromUnits(x.units)]));
 const dom=new ComparatorDomParser().parseFromString(parsedXml);
 const rawGroups=dom.querySelectorAll('ImageDesign > SubImage').map((si,index)=>({fields:si.querySelectorAll(':scope > Field').map(field=>{
  const name=field.getAttribute('Name');
  return {name,calculatedData:index===0&&rawFirst.has(name)?rawFirst.get(name):normalizeXml(field.querySelector(':scope > CalcData')?.textContent??'')};
 })}));
 const emittedDecoded=decode(row.loadedToken,{fieldCount:row.loadedFields.length,sourcePath:row.file});
 const expected=build({dateOffsets:Array(evidence.counts.dateOffsetCount).fill({}),subImages:rawGroups},new Date('2026-10-21T00:00:00Z'),{mask:emittedDecoded.maskHex,includeFileMetadata:emittedDecoded.includeFileMetadata,sourcePath:row.file});
 assert.equal(expected.clStVersionInfo,row.loadedToken,row.name+': saved token is not from prepared raw snapshot');
 const loadedGroups=rawGroups.map(()=>({fields:[]}));
 for(const field of row.loadedFields)loadedGroups[field.subImageIndex-1].fields.push({name:field.name,calculatedData:fromUnits(field.calculatedDataUnits)});
 const regeneratedDecoded=decode(row.regeneratedToken,{fieldCount:row.loadedFields.length,sourcePath:row.file});
 const regenerated=build({dateOffsets:Array(evidence.counts.dateOffsetCount).fill({}),subImages:loadedGroups},new Date('2026-10-21T00:00:00Z'),{mask:regeneratedDecoded.maskHex,includeFileMetadata:regeneratedDecoded.includeFileMetadata,sourcePath:row.file});
 assert.equal(regenerated.clStVersionInfo,row.regeneratedToken,row.name+': native GetXml failed production recomposition');
 results.push({name:row.name,originalLoadAndBothValidatorsAccepted:true,calculatedDataUnchangedOnNativeLoad:true,originalResolveFieldAlsoMatched:row.afterNativeResolve?true:null,emittedTokenMatchesPreparedRawSnapshot:true,nativeRegenerationRecomposed:true,fieldCount:row.loadedFields.length,mask:emittedDecoded.maskHex,optional:emittedDecoded.includeFileMetadata,sourceHashUnchanged:true});
}
const report={method:'Complete production prepare/save UTF16LE files loaded by original manager, original properties unchanged, both validators and native regeneration checked',accepted:results.length,cases:results};
fs.writeFileSync(path.join(__dirname,'saved-native-verification.json'),JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify({accepted:results.length,calculatedDataUnchanged:true,preparedRawSnapshotsAndOriginalRegenerationsMatch:true}));

'use strict';
const fs=require('node:fs'),path=require('node:path'),vm=require('node:vm');
const root=path.resolve(__dirname,'../../..');
const {createProductionCiffRuntime}=require(path.join(root,'tests/helpers/ciff-production-harness.cjs'));
const original=JSON.parse(fs.readFileSync(path.join(__dirname,'native-com-results.json'),'utf8'));
const textField=(name,type,value,object)=>`<Field Name="${name}"><FldType>${type}</FldType><X>0</X><Y>0</Y><W>100</W><H>100</H><CalcData><![CDATA[${value}]]></CalcData><Data>${object}</Data><Text><Font><Pitch>8</Pitch></Font></Text></Field>`;
const matrixField=(value,objects)=>'<Field Name="DM"><FldType>Barcode</FldType><CLSID>{7A4AA4CF-F5CD-11D4-8DAE-0050DAFE8A9F}</CLSID><X>100</X><Y>100</Y><W>924</W><H>924</H>'+`<CalcData><![CDATA[${value}]]></CalcData><Data>${objects}</Data>`+'<Barcode><BcH>924</BcH><HR><HRFont/></HR><QuietMargin>0</QuietMargin><DataMatrix><ModuleSize>42</ModuleSize><SymbolSize>22X22</SymbolSize></DataMatrix></Barcode></Field>';
function customSource(name,fields){
 const text='<?xml version="1.0" encoding="UTF-16"?>\r\n<ImageDesign Version="23" xml:space="default"><Header DesignedFor="DataFlex 6330(53mm) - Continuous"/><SubImage ImageReference="1"><SubHeader><ImageWidth>1600</ImageWidth><ImageHeight>1600</ImageHeight><MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>1600</MaxImageHeight><XRes>0.120000</XRes></SubHeader>'+fields+'</SubImage><GenericSettings/></ImageDesign>';
 const file=path.join(__dirname,`source-${name}.ciff`);fs.writeFileSync(file,Buffer.concat([Buffer.from([255,254]),Buffer.from(text,'utf16le')]));return file;
}
function customMultiSource(name,secondField){
 const file=customSource(name,textField('FIRST','FixedText','FIRST','<Object><DataType>0</DataType><Default>FIRST</Default></Object>'));
 const source=fs.readFileSync(file).subarray(2).toString('utf16le');
 const second='<SubImage ImageReference="2"><SubHeader><ImageWidth>1600</ImageWidth><ImageHeight>1600</ImageHeight><MaxImageWidth>1600</MaxImageWidth><MaxImageHeight>1600</MaxImageHeight><XRes>0.120000</XRes></SubHeader>'+secondField+'</SubImage>';
 fs.writeFileSync(file,Buffer.concat([Buffer.from([255,254]),Buffer.from(source.replace('<GenericSettings/>',second+'<GenericSettings/>'),'utf16le')]));return file;
}
const jobs=original.cases.map(row=>({name:row.name,source:path.join(__dirname,row.file),mask:row.name==='native-multiple-subimages'?'4':row.name==='native-hidden-graphic'?'2':row.before.length>=32?'80000001':row.before.length>=3?'7':row.before.length===2?'3':row.before.length===1?'1':'0'}));
for(const name of ['constant-text','date','offset-date','external-text','field-order'])jobs.push({name:'conservative-'+name,source:path.join(root,`tests/fixtures/conservative/${name}.ciff`),mask:'1'});
for(const name of ['runtime-counter','runtime-time','runtime-date','runtime-user','runtime-source-field'])jobs.push({name:'runtime-'+name,source:path.join(root,`research/ciff-fields/oracle/${name}.ciff`),mask:'1'});
for(const name of ['partial-source','dynamic-pad-mode0','dynamic-pad-mode1','dynamic-pad-defaults','dynamic-pad-nul','static-no-padding','dynamic-no-truncation','user-empty-override','user-value-override','user-pad-default'])jobs.push({name:'resolved-'+name,source:path.join(__dirname,`resolved-${name}.ciff`),mask:name==='partial-source'?'6':'1'});
jobs.push({name:'optional-saveas',source:path.join(__dirname,'emitted-native-1-fields-optional.ciff'),mask:'1'});
jobs.push({name:'changed-control-data',source:path.join(__dirname,'native-1-fields.ciff'),mask:'1',control:true});
jobs.push({name:'edited-nul-data',source:customSource('edited-nul-data',textField('RAW','StaticGraphic','old','<Object><DataType>0</DataType><Default/></Object>')),mask:'1',nul:true});
const partialObjects='<Object Static="0"><DataType>5</DataType><Default>old</Default><SrcField SrcFieldName="SOURCE"><StartChar>1</StartChar><NoOfChars>3</NoOfChars></SrcField></Object>'+'<Object Index="1" Static="0"><DataType>0</DataType><MaxNoOfChars>5</MaxNoOfChars><Default>AB</Default><FixedLen><PadChar>0</PadChar><PadMode>Right</PadMode></FixedLen></Object>';
jobs.push({name:'dm-partial-pad',source:customSource('dm-partial-pad',textField('SOURCE','FixedText','ABCDE','<Object><DataType>0</DataType><Default>ABCDE</Default></Object>')+matrixField('old',partialObjects)),mask:'2',verifyNativeResolve:true});
jobs.push({name:'dm-direct-time',source:customSource('dm-direct-time',matrixField('stale','<Object Static="0" Parse="1"><DataType>1</DataType><Default>HH:mm</Default></Object>')),mask:'1',liveNow:true,verifyNativeResolve:true});
jobs.push({name:'second-subimage-literal-crlf',source:customMultiSource('second-subimage-literal-crlf',textField('SECOND','FixedText','A\r\nB','<Object><DataType>0</DataType><Default>unused</Default></Object>')),mask:'2'});
const referenceField=textField('SECOND','FixedText','ignored','<Object><DataType>0</DataType><Default>unused</Default></Object>').replace('<![CDATA[ignored]]>','A&#13;B');
jobs.push({name:'second-subimage-charref-cr',source:customMultiSource('second-subimage-charref-cr',referenceField),mask:'2'});
jobs.push({name:'first-subimage-charref-cr',source:customSource('first-subimage-charref-cr',textField('FIRST','FixedText','ignored','<Object><DataType>0</DataType><Default>unused</Default></Object>').replace('<![CDATA[ignored]]>','A&#13;B')),mask:'1'});
jobs.push({name:'first-default-charref-cr',source:customSource('first-default-charref-cr',textField('FIRST','FixedText','stale','<Object Static="0"><DataType>0</DataType><Default>D&#13;E</Default></Object>')),mask:'1',verifyNativeResolve:true});
jobs.push({name:'first-user-charref-cr',source:customSource('first-user-charref-cr',textField('FIRST','FixedText','stale','<Object Static="0"><DataType>0</DataType><Default>DEFAULT</Default><VarText><UserEnterData>U&#13;V</UserEnterData></VarText></Object>')),mask:'1',verifyNativeResolve:true});
const emitted=[],results=[];
for(const job of jobs){
 const file=path.join(__dirname,`saved-${job.name}.ciff`);
 try{
  const runtime=createProductionCiffRuntime(fs.readFileSync(job.source),{sourcePath:job.source,getTickCount:()=>0});
  // Raw COM research fixtures intentionally omit printer metadata. Supply an
  // explicit printer via editor state so the normal save validator can run.
  const suppliedPrinter=!runtime.state.docMeta.designedFor;
  if(suppliedPrinter){
   runtime.state.docMeta.designedFor='DataFlex 6320(53mm) - Continuous';
   runtime.state.docMeta.printerModel='DataFlex 6320(53mm)';
   runtime.state.docMeta.printMode='Continuous';
  }
  if(job.control){
   runtime.state.fields[0].data.defaultValue='ab\u0001cd\u001def\tgh\r\nij';
   runtime.state.fields[0].calcData='ab\u0001cd\u001def\tgh\r\nij';
  }
  if(job.nul)runtime.state.fields[0].calcData='AB\0CD';
  const now=job.liveNow?new Date():new Date('2026-10-21T12:34:56+03:00');
  const output=runtime.save(now,{sourcePath:file,clstOptions:{mask:job.mask}});
  if(!output.prepared.validation.ok)throw new Error(JSON.stringify(output.prepared.validation));
  fs.writeFileSync(file,output.bytes);
  const token=output.bytes.subarray(2).toString('utf16le').match(/<ClStVersionInfo>([\s\S]*?)<\/ClStVersionInfo>/)?.[1];
  emitted.push({name:job.name,kind:'actual-production-save',file,token,expectedValidation:'00000000',verifyNativeResolve:!!job.verifyNativeResolve});
  const rawCalculatedData=Array.from(output.prepared.calculatedData.entries(),([field,value])=>({name:field.name,units:value==null?null:Array.from({length:value.length},(_,i)=>value.charCodeAt(i))}));
  results.push({name:job.name,source:job.source,file,status:'ok',suppliedPrinter,now:now.toISOString(),sha256:output.sha256,token,mask:job.mask,fieldCount:runtime.state.fields.length,rawCalculatedData,verifyNativeResolve:!!job.verifyNativeResolve,validation:output.prepared.validation});
 }catch(error){results.push({name:job.name,source:job.source,file,status:'error',error:error.stack});}
}
fs.writeFileSync(path.join(__dirname,'save-pipeline-results.json'),JSON.stringify({method:'createProductionCiffRuntime original parser/rendering/calculated-data/save functions, no custom mock resolver; includes final UTF16LE bytes',cases:results},null,2)+'\n');
fs.writeFileSync(path.join(__dirname,'saved-production-inputs.json'),JSON.stringify(emitted,null,2)+'\n');
console.log(JSON.stringify({cases:results.length,saved:emitted.length,failures:results.filter(x=>x.status!=='ok').map(x=>({name:x.name,error:x.error.split('\n')[0]}))}));
if(emitted.length!==jobs.length)process.exitCode=1;

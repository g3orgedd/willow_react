'use strict';
const fs=require('node:fs'),path=require('node:path');
const fixed=(name,value,properties={},staticValue=false,type=0)=>({name,type:0,objects:[{type,index:0,static:staticValue,parse:false,properties:{ClearStyleDataType:0,DefaultData:value,...properties}}]});
const source=(name,start,count,mode)=>({name,type:0,objects:[{type:1,index:0,static:false,parse:false,properties:{ClearStyleDataType:5,SourceFieldName:'SOURCE',StartCharacter:start,NumberOfCharacters:count,SelectMode:mode}}]});
const pad={MaximumCharacters:5,FixedLength:1,FixedLengthPadCharacter:48};
const cases=[
 {name:'partial-source',fields:[fixed('SOURCE','ABCDE',{},true),source('BCD',1,3,0),source('CD',1,2,1),source('BCDE',1,0,0),source('zero-count-back',1,0,1),source('suffix',0,2,1)]},
 ...[0,1].map(mode=>({name:`dynamic-pad-mode${mode}`,fields:[fixed('PAD','AB',{...pad,FixedLengthPadMode:mode})]})),
 {name:'dynamic-pad-defaults',fields:[fixed('PAD','AB',{MaximumCharacters:5,FixedLength:1})]},
 {name:'dynamic-pad-nul',fields:[fixed('PAD','AB',{...pad,FixedLengthPadCharacter:0})]},
 {name:'static-no-padding',fields:[fixed('PAD','AB',{...pad,FixedLengthPadMode:1},true)]},
 {name:'dynamic-no-truncation',fields:[fixed('PAD','ABCDE',{...pad,MaximumCharacters:2})]},
 {name:'user-empty-override',fields:[fixed('USER','DEFAULT',{VariableTextUserEnteredData:''},false,3)]},
 {name:'user-value-override',fields:[fixed('USER','DEFAULT',{VariableTextUserEnteredData:'OPERATOR'},false,3)]},
 {name:'user-pad-default',fields:[fixed('USER','DEFAULT',{VariableTextUserEnteredData:'AB',MaximumCharacters:5,FixedLength:1},false,3)]},
];
fs.writeFileSync(path.join(__dirname,'native-resolved-inputs.json'),JSON.stringify(cases,null,2)+'\n');

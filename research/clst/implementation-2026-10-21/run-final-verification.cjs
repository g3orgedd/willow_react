'use strict';
const fs=require('node:fs'),path=require('node:path'),cp=require('node:child_process'),crypto=require('node:crypto');
const root=path.resolve(__dirname,'../../..');
const folder='research/clst/implementation-2026-10-21';
const ps=path.join(process.env.WINDIR??'C:\\Windows','SysWOW64/WindowsPowerShell/v1.0/powershell.exe');
const psArgs=file=>['-NoProfile','-ExecutionPolicy','Bypass','-File',`${folder}/${file}`];
const steps=[
 ['node',[`${folder}/make-native-inputs.cjs`]],
 [ps,psArgs('native-com-oracle.ps1')],
 ['node',[`${folder}/make-resolved-inputs.cjs`]],
 [ps,psArgs('native-resolved-oracle.ps1')],
 [ps,psArgs('native-resolved-reload.ps1')],
 ['python',[`${folder}/verify-native-machine.py`]],
 ['node',[`${folder}/prepare-production-emission.cjs`]],
 [ps,psArgs('validate-production-files.ps1')],
 ['node',[`${folder}/verify-production-native.cjs`]],
 ['node',[`${folder}/save-through-production.cjs`]],
 [ps,[...psArgs('validate-production-files.ps1'),'-InputFile',`${folder}/saved-production-inputs.json`,'-OutputFile',`${folder}/saved-native-validation.json`]],
 ['node',[`${folder}/verify-saved-native.cjs`]],
 ['node',[`${folder}/prepare-import-probes.cjs`]],
 [ps,psArgs('native-import-probes.ps1')],
 ['node',['--test','tests/clst-dll-equivalence.test.cjs']],
];
const hash=file=>crypto.createHash('sha256').update(fs.readFileSync(file)).digest('hex');
function productionHashes(){
 const scope=['public','src','electron','index.html','vite.config.ts','package.json','package-lock.json'];
 const tracked=cp.execFileSync('git',['diff','--name-only','-z','--',...scope],{cwd:root,stdio:['ignore','pipe','pipe'],maxBuffer:8*1024*1024}).toString('utf8').split('\0');
 const untracked=cp.execFileSync('git',['ls-files','--others','--exclude-standard','-z','--',...scope],{cwd:root,stdio:['ignore','pipe','pipe'],maxBuffer:8*1024*1024}).toString('utf8').split('\0');
 const explicit=['public/modules/clst/encryption.js','public/modules/clst/tag-data.js','public/modules/clst/calculated-data.js','public/modules/clst/version-info.js','tests/helpers/ciff-production-harness.cjs','tests/clst-dll-equivalence.test.cjs'];
 const files=[...new Set([...tracked,...untracked].filter(file=>/^(public|src|electron)\//.test(file)&&/\.(?:js|cjs|ts|tsx|html|ps1|css)$/.test(file)||['index.html','vite.config.ts','package.json','package-lock.json'].includes(file)).concat(explicit))].sort();
 return Object.fromEntries(files.filter(file=>fs.existsSync(path.join(root,file))).map(file=>[file,hash(path.join(root,file))]));
}
const before=productionHashes();
const runs=[];
for(const [command,args] of steps){
 const started=new Date().toISOString();
 const result=cp.spawnSync(command,args,{cwd:root,encoding:'utf8',maxBuffer:8*1024*1024,windowsHide:true});
 const item={command,args,startedUtc:started,finishedUtc:new Date().toISOString(),exitCode:result.status,stdout:result.stdout??'',stderr:result.stderr??''};
 runs.push(item);
 process.stdout.write(`${path.basename(command)} ${args.find(x=>/\.(cjs|ps1|py)$/.test(x))??args.join(' ')}: ${item.exitCode}\n`);
 fs.writeFileSync(path.join(__dirname,'final-run-results.json'),JSON.stringify({runs},null,2)+'\n');
 if(item.exitCode!==0){process.stderr.write(item.stdout+item.stderr);process.exitCode=1;break;}
}
const after=productionHashes();
const read=file=>JSON.parse(fs.readFileSync(path.join(__dirname,file),'utf8'));
const dll='C:\\Program Files (x86)\\CLARICOM\\Data\\CiffMgr.dll';
const manifest={date:'2026-10-21',sourceDll:{path:dll,version:'4.5.0.0',byteLength:fs.statSync(dll).size,sha256:hash(dll)},
 command:'node research/clst/implementation-2026-10-21/run-final-verification.cjs',
 steps:runs.map(({command,args,exitCode})=>({command,args,exitCode})),
 productionSourceHashesBefore:before,productionSourceHashesAfter:after,productionSourcesUnchangedDuringRun:JSON.stringify(before)===JSON.stringify(after),
 actualResults:{nativeMachine:read('native-machine-report.json'),nativeCoreCases:read('production-comparison.json').cases.length,
 emittedEnvelopeCases:read('production-native-verification.json').accepted,corruptRejected:read('production-native-verification.json').negativeControlsRejected,
 completeProductionSaves:read('saved-native-verification.json').accepted,resolveCases:read('native-resolved-reloaded.json').cases.length,
 partialAndDynamicDmNativeResolveMatched:read('saved-native-verification.json').cases.filter(x=>x.originalResolveFieldAlsoMatched).map(x=>x.name),nativeImportPropertyCases:read('native-import-results.json').cases.length,unitTests:6},
 limitations:['Original COM load and validators are software compatibility evidence, not physical Videojet firmware acceptance.','Complete production save uses the project parser/save runtime harness; no GUI save or screenshot is implied.','The harness supplies ComparatorDomParser and replaces printable/hardware geometry validation and used-image-bounds updates with stubs. It executes the original calculated-data, ClSt, parser and XML save functions, but does not establish full application/geometry/printing compatibility.','GetTickCount/CRT thread-data source and OLE/CRT memory helpers are controlled for Unicorn; randomIndex and cipher arithmetic execute installed machine code.','Direct dynamic DataMatrix Time was frozen at the actual run time and compared immediately with original ResolveField.']};
fs.writeFileSync(path.join(__dirname,'final-manifest.json'),JSON.stringify(manifest,null,2)+'\n');
if(!manifest.productionSourcesUnchangedDuringRun){process.stderr.write('Production changed during verification.\n');process.exitCode=1;}
process.stdout.write(JSON.stringify({allCommandsSucceeded:runs.length===steps.length&&runs.every(x=>x.exitCode===0),productionSourcesUnchanged:manifest.productionSourcesUnchangedDuringRun,completeProductionSaves:manifest.actualResults.completeProductionSaves})+'\n');

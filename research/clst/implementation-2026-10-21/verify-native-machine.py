"""Execute installed x86 transform and randomIndex instructions; no GUI or DLL load."""
from pathlib import Path
import hashlib
import json
import random
import subprocess
import sys

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
sys.path.insert(0,str(HERE.parent/'native'))
from native_oracle import NativeOracle,DLL,HEAP,STUB

oracle=NativeOracle()
rng=random.Random(0x20261021)
cases=[]
for index in range(200):
    key=''.join(chr(rng.randrange(1,0x10000)) for _ in range(rng.randrange(1,22)))
    text=''.join(chr(rng.randrange(0,0x10000)) for _ in range(rng.randrange(0,70)))
    cases.append(dict(input=text,key=key,native=oracle.encrypt(text,key)['output']))
for text,key in [('A\0B','TagData'),('\U0001f600','TagData'),('a'*19+'\ud83d','TagData'),
                 ('audit','abc\0def'),('audit','12345678901234567890'),('', 'TagData')]:
    cases.append(dict(input=text,key=key,native=oracle.encrypt(text,key)['output']))

# CRT thread data and Windows uptime are controlled environmental inputs.
# srand, rand, reseeding, signed division and modulus execute original PE bytes.
thread_data=HEAP+0x3f0000
oracle.uc.mem_write(thread_data,bytes(0x100))
oracle.hooks[0x68136fe6]=lambda:oracle.ret(thread_data)
tick_state={'value':0}
tick_stub=STUB+0x500
oracle.write32(0x68147054,tick_stub)
oracle.hooks[tick_stub]=lambda:oracle.ret(tick_state['value'])
ticks=[0,1,2,65535,65536,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]+[rng.randrange(0,2**32) for _ in range(64)]
random_cases=[]
for tick in ticks:
    for bound in [1,2,3,31,32,33]:
        tick_state['value']=tick
        actual=oracle.call(0x68118e73,[bound])
        expected=((((tick*0x343fd+0x269ec3)&0xffffffff)>>16)&0x7fff)%bound
        assert actual==expected
        random_cases.append(dict(tick=tick,bound=bound,native=actual))
data=dict(cipher=cases,randomIndex=random_cases)
data_path=HERE/'native-machine-cases.json'
data_path.write_text(json.dumps(data,ensure_ascii=True,indent=2),encoding='utf8')
js=r'''
const fs=require('node:fs'),vm=require('node:vm'),crypto=require('node:crypto');
const context=vm.createContext({});
for(const file of ['encryption','tag-data'])vm.runInContext(fs.readFileSync(`public/modules/clst/${file}.js`,'utf8'),context);
const encrypt=vm.runInContext('encryptClStText',context),randomIndex=vm.runInContext('randomClStIndexFromTick',context);
const data=JSON.parse(fs.readFileSync(process.argv[1],'utf8'));
const cipherFailures=[],rngFailures=[];
data.cipher.forEach((c,index)=>{if(encrypt(c.input,c.key)!==c.native)cipherFailures.push(index)});
data.randomIndex.forEach((c,index)=>{if(randomIndex(c.tick,c.bound)!==c.native)rngFailures.push(index)});
const files=['public/modules/clst/encryption.js','public/modules/clst/tag-data.js'];
const report={cipher:{total:data.cipher.length,matched:data.cipher.length-cipherFailures.length,failures:cipherFailures},randomIndex:{total:data.randomIndex.length,matched:data.randomIndex.length-rngFailures.length,failures:rngFailures},sourceHashes:Object.fromEntries(files.map(file=>[file,crypto.createHash('sha256').update(fs.readFileSync(file)).digest('hex')]))};
fs.writeFileSync(process.argv[2],JSON.stringify(report,null,2)+'\n');console.log(JSON.stringify(report));
if(cipherFailures.length||rngFailures.length)process.exitCode=1;
'''
result=subprocess.run(['node','-e',js,str(data_path),str(HERE/'native-machine-report.json')],cwd=ROOT,capture_output=True,text=True)
print(result.stdout.strip())
if result.stderr:print(result.stderr.strip(),file=sys.stderr)
manifest=dict(sourceDll=str(DLL),sha256=hashlib.sha256(DLL.read_bytes()).hexdigest(),byteLength=DLL.stat().st_size,
              method='Original installed x86 E(68117D03), randomIndex(68118E73), srand(68134DBA), rand(68134D99) in Unicorn',
              controlledHelpers=['OLE BSTR allocation/free/length','CRT wchar copy/length','BSTR copy','GetTickCount return value','CRT __getptd address'],
              command='python research/clst/implementation-2026-10-21/verify-native-machine.py',exitCode=result.returncode)
(HERE/'native-machine-manifest.json').write_text(json.dumps(manifest,indent=2),encoding='utf8')
raise SystemExit(result.returncode)

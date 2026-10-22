"""Compare native CiffMgr code against the current production JS transform."""
import json
from pathlib import Path
import random
import subprocess
from native_oracle import NativeOracle, HERE

ROOT = HERE.parents[2]
rng = random.Random(0x26e20115)
oracle = NativeOracle()
cases = []
for index in range(200):
    key = ''.join(chr(rng.randrange(1, 0xD800)) for _ in range(rng.randrange(1, 15)))
    text = ''.join(chr(rng.randrange(0, 0xD800)) for _ in range(rng.randrange(0, 60)))
    cases.append({'kind': 'supported key length and no embedded NUL', 'input': text, 'key': key,
                  'native': oracle.encrypt(text, key)['output']})
for text, key in [('emoji \U0001f600', 'TagData'), ('binary\0text', 'TagData'),
                  ('audit', '12345678901234567890'), ('audit', 'abc\0def')]:
    cases.append({'kind': 'edge', 'input': text, 'key': key,
                  'native': oracle.encrypt(text, key)['output']})

cases_file = HERE / 'oracle-comparison-cases.json'
cases_file.write_text(json.dumps(cases, ensure_ascii=True), encoding='utf8')
js = r'''
const fs=require('fs'),vm=require('vm');
const context={}; context.globalThis=context; vm.createContext(context);
vm.runInContext(fs.readFileSync('public/modules/clst/encryption.js','utf8'),context);
const cases=JSON.parse(fs.readFileSync('research/clst/native/oracle-comparison-cases.json','utf8'));
let supportedMatched=0, supportedCount=0; const differences=[];
for(let index=0;index<cases.length;index++) {
  const c=cases[index]; context.oracleInput=c.input; context.oracleKey=c.key;
  const actual=vm.runInContext('encryptClStText(oracleInput,oracleKey)',context);
  if(c.kind!=='edge') {supportedCount++; if(actual===c.native) supportedMatched++;}
  if(actual!==c.native) differences.push({index,...c,js:actual});
}
fs.writeFileSync('research/clst/native/oracle-comparison-report.json',JSON.stringify({supportedCount,supportedMatched,total:cases.length,differences},null,2));
console.log(JSON.stringify({supportedCount,supportedMatched,total:cases.length,differenceCount:differences.length}));
'''
result = subprocess.run(['node', '-e', js], cwd=ROOT, check=True, capture_output=True, text=True)
print(result.stdout.strip())

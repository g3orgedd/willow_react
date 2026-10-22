"""Fresh installed-DLL checks; preserves all earlier research outputs."""
from pathlib import Path
import hashlib
import json
import random
import subprocess
import sys

HERE = Path(__file__).resolve().parent
CLST = HERE.parent
ROOT = CLST.parents[1]
sys.path.insert(0, str(CLST / 'native'))
sys.path.insert(0, str(CLST / 'optional'))
from native_oracle import NativeOracle, DLL, utf16
from compose_reference import make_cases
from native_splitpath import generation_filename, split_native


def clip(text, limit):
    return utf16(text)[:limit * 2].decode('utf-16-le', 'surrogatepass')


def compose(oracle, data):
    fields = data['fieldValues']
    mask = int(data['mask'], 16) if isinstance(data['mask'], str) else data['mask']
    counts = ''.join(f'{min(number, 99):02d}' for number in
                     [data.get('dateOffsetCount', 0), data.get('subImageCount', 1), len(fields)])
    payload = clip(''.join(value for i, value in enumerate(fields[:32]) if (mask >> i) & 1), 20)
    mask_fragment = oracle.encrypt(f'{mask:08X}', counts)['output']
    tag_fragment = oracle.encrypt(payload, 'TagData')['output'] if fields else ''
    normal = mask_fragment + tag_fragment
    filename = None
    metadata = length = ''
    if data.get('includeFileMetadata'):
        filename = generation_filename(data['sourcePath'])
        metadata = oracle.encrypt(filename, 'TagData')['output']
        length = oracle.encrypt(f'{len(metadata):08x}', counts)['output']
    inner = length + metadata + normal
    return dict(maskHex=f'{mask:08X}', counts6=counts, tagData=payload,
                maskFragment=mask_fragment, tagFragment=tag_fragment,
                normalIntermediate=normal, fileMetadata=filename,
                metadataFragment=metadata, metadataLengthFragment=length,
                intermediate=inner, clStVersionInfo=oracle.encrypt(inner, 'TpyRcNeyeK')['output'])


def main():
    oracle = NativeOracle()
    rng = random.Random(0x20261020)
    direct = []
    for index in range(200):
        key = ''.join(chr(rng.randrange(1, 0xD800)) for _ in range(rng.randrange(1, 15)))
        text = ''.join(chr(rng.randrange(0, 0xD800)) for _ in range(rng.randrange(0, 60)))
        direct.append(dict(kind='supported', input=text, key=key, native=oracle.encrypt(text, key)))
    for text, key in [('emoji \U0001f600', 'TagData'), ('binary\0text', 'TagData'),
                      ('audit', '12345678901234567890'), ('audit', 'abc\0def')]:
        direct.append(dict(kind='edge', input=text, key=key, native=oracle.encrypt(text, key)))

    known = json.loads((CLST / 'native' / 'oracle-results.json').read_text('utf8'))['results'][:3]
    vectors = []
    for row in known:
        actual = oracle.encrypt(row['text'], row['key'])['output']
        vectors.append(dict(input=row['text'], key=row['key'], actual=actual,
                            expected=row['output'], matched=actual == row['output']))
    basic = [dict(description=name, input=data, native=compose(oracle, data))
             for name, data in make_cases()]
    optional_inputs = json.loads((CLST / 'optional' / 'optional-composition-results.json').read_text('utf8'))['cases']
    optional = [dict(input=row['input'], native=compose(oracle, row['input'])) for row in optional_inputs]
    path_inputs = [json.loads(line)['sourcePath'] for line in
                   (CLST / 'optional' / 'splitpath-cases.jsonl').read_text('utf8').splitlines() if line.strip()]
    paths = [dict(sourcePath=source, nativeName=split_native(source)[0],
                  nativeExtension=split_native(source)[1], native=generation_filename(source)) for source in path_inputs]
    data = dict(direct=direct, knownVectors=vectors, basic=basic, optional=optional, paths=paths)
    data_path = HERE / 'native-cases.json'
    data_path.write_text(json.dumps(data, ensure_ascii=True, indent=2), encoding='utf8')
    js = r'''
const fs=require('node:fs'),vm=require('node:vm');
const {encrypt,generateClStReference,metadataName}=require('./research/clst/reference-generator.cjs');
const context=vm.createContext({});
vm.runInContext(fs.readFileSync('public/modules/clst/encryption.js','utf8'),context);
const production=vm.runInContext('encryptClStText',context);
const data=JSON.parse(fs.readFileSync(process.argv[1],'utf8'));
const report={direct:{supportedCount:0,supportedMatched:0,referenceMatched:0,total:data.direct.length,productionDifferences:[]},knownVectors:data.knownVectors.map(x=>({matched:x.matched})),basic:{total:data.basic.length,matched:0,differences:[]},optional:{total:data.optional.length,matched:0,differences:[]},paths:{total:data.paths.length,matched:0,differences:[]}};
data.direct.forEach((row,index)=>{
 const actual=production(row.input,row.key), ref=encrypt(row.input,row.key), expected=row.native.output;
 if(row.kind==='supported'){report.direct.supportedCount++;if(actual===expected)report.direct.supportedMatched++;}
 if(ref===expected)report.direct.referenceMatched++;
 if(actual!==expected)report.direct.productionDifferences.push({index,kind:row.kind,key:row.key,nativeKeyLength:row.native.effectiveKeyLength,reason:'production does not cap key at 14 UTF16 units or stop key at NUL'});
});
for(const kind of ['basic','optional'])for(const [index,row] of data[kind].entries()){
 const actual=generateClStReference(row.input);const differences=[];
 for(const key of Object.keys(row.native))if(actual[key]!==row.native[key])differences.push(key);
 if(differences.length)report[kind].differences.push({index,differences});else report[kind].matched++;
}
data.paths.forEach((row,index)=>{const actual=metadataName(row.sourcePath);if(actual===row.native)report.paths.matched++;else report.paths.differences.push({index,sourcePath:row.sourcePath,actual,native:row.native});});
fs.writeFileSync(process.argv[2],JSON.stringify(report,null,2)+'\n');
console.log(JSON.stringify(report));
if(report.direct.supportedMatched!==200||report.direct.referenceMatched!==204||report.knownVectors.some(x=>!x.matched)||report.basic.matched!==report.basic.total||report.optional.matched!==report.optional.total||report.paths.matched!==report.paths.total)process.exitCode=1;
'''
    check = subprocess.run(['node', '-e', js, str(data_path), str(HERE / 'native-report.json')],
                           cwd=ROOT, text=True, capture_output=True)
    print(check.stdout.strip())
    if check.stderr:
        print(check.stderr.strip(), file=sys.stderr)
    manifest = dict(sourceDll=str(DLL), byteLength=DLL.stat().st_size,
                    sha256=hashlib.sha256(DLL.read_bytes()).hexdigest(),
                    archivedCopySha256=hashlib.sha256((CLST / 'binaries' / 'CiffMgr.dll').read_bytes()).hexdigest(),
                    architecture='PE32 x86, original cipher and splitpath instructions in Unicorn',
                    freshRandomSeed='0x20261020', python=sys.version, command='python research/clst/comparison-2026-10-20/native-verify.py',
                    emulatedHelpers=['OLE BSTR allocate/free/length', 'CRT wchar copy/length', 'BSTR copy 681026D0'],
                    limitations=['Composition does not execute full COM generator', 'No GUI create/save', 'No physical printer acceptance'],
                    exitCode=check.returncode)
    (HERE / 'native-manifest.json').write_text(json.dumps(manifest, ensure_ascii=True, indent=2), encoding='utf8')
    raise SystemExit(check.returncode)


if __name__ == '__main__':
    main()

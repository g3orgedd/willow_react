"""Produce an evidence index of native XML writers, constants, and dispatch tables."""
from pathlib import Path
import json, re, struct, sys
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent/'clst/tools'))
import pefile
from inventory import DATA
pe=pefile.PE(str(DATA/'CiffMgr.dll'))
base=pe.OPTIONAL_HEADER.ImageBase
memory=pe.get_memory_mapped_image()
def u32(address): return struct.unpack_from('<I',memory,address-base)[0]
def wide(address):
    if not base<=address<base+len(memory): return None
    end=address-base
    while end+1<len(memory) and memory[end:end+2]!=b'\0\0': end+=2
    return memory[address-base:end].decode('utf-16-le','surrogatepass')
def tag(pointer):
    try: return wide(u32(pointer))
    except Exception: return None
tags=[{'index':(address-0x6815fc38)//4,'pointerAddress':f'{address:08x}', 'value':tag(address)} for address in range(0x6815fc38,0x6816010c,4)]
types=json.loads((HERE/'metadata/CiffMgr.dll.typelib.json').read_text(encoding='utf8'))['types']
enums={t['name']:{item['value']:item['name'] for item in t['variables']} for t in types if t['kind']==0}
routes=[]
for i in range(27):
    index=u32(0x6814b8e8+i*8)
    routes.append({'value':i,'enum':enums['EFieldSubTypeBarcode'].get(i),'xmlTag':tag(0x6815fc38+index*4),'tagIndex':index,'featureMask':f'0x{u32(0x6814b8ec+i*8):08X}'})
helpers={'681021f5':'attribute','6810226e':'CDATA element','681023dc':'text element with returned node','6810248f':'text element','68124179':'child container'}
def arguments(text,start):
    opening=text.index('(',start)
    depth=1; end=opening+1; quoted=False; escaped=False
    while end<len(text) and depth:
        c=text[end]
        if quoted:
            if c=='"' and not escaped: quoted=False
            escaped=c=='\\' and not escaped
        elif c=='"': quoted=True
        elif c=='(': depth+=1
        elif c==')': depth-=1
        end+=1
    return re.sub(r'\s+',' ',text[start:end]).strip()
writers=[]
for filename in sorted((HERE/'decompiled/CiffMgr.dll').glob('*.c')):
    source=filename.read_text(encoding='utf8')
    writes=[]
    for match in re.finditer(r'FUN_('+'|'.join(helpers)+r')\s*\(',source):
        if match.start()<source.index('{'): continue
        call=arguments(source,match.start())
        tokens=re.findall(r'PTR_(?:u_[A-Za-z0-9_]+|DAT)_([0-9a-f]{8})',call)
        node=next((tag(int(token,16)) for token in tokens if tag(int(token,16)) is not None),None)
        writes.append({'line':source.count('\n',0,match.start())+1,'operation':helpers[match.group(1)],'node':node,'call':call})
    if writes:
        writers.append({'function':filename.stem[4:],'source':str(filename.relative_to(HERE)).replace('\\','/'),'writes':writes})
result={'sourceDllSha256':json.loads((HERE/'metadata/CiffMgr.dll.json').read_text())['sha256'],
        'note':'Evidence index, not an executable rule engine. Conditions and error propagation remain in the cited C and assembly.',
        'tags':tags,'barcodeRoutes':routes,'writers':writers}
(HERE/'serialization-map.json').write_text(json.dumps(result,ensure_ascii=True,indent=2),encoding='utf8')
lines=['# Native XML writer index','',result['note'],'','## Barcode routes','','| ID | Enum | XML node | Feature mask |','|---|---|---|---|']
lines += [f"| {r['value']} | {r['enum']} | {r['xmlTag']} | `{r['featureMask']}` |" for r in routes]
for writer in writers:
    lines+=['',f"## {writer['function']}",'',f"[C source]({writer['source']})",'','| Line | Operation | Node |','|---|---|---|']
    lines += [f"| {w['line']} | {w['operation']} | {w['node'] or '(dynamic table)'} |" for w in writer['writes']]
(HERE/'SERIALIZATION_MAP.md').write_text('\n'.join(lines)+'\n',encoding='utf8')
print(json.dumps({'tagConstants':len(tags),'writers':len(writers),'writeSites':sum(len(w['writes']) for w in writers),'barcodeRoutes':len(routes)}))

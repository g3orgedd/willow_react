from pathlib import Path
import json, struct, sys
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent/'clst/tools'))
import pefile
p=pefile.PE(r'C:/Program Files (x86)/CLARICOM/CLARiSOFT/CLARiSOFT.exe')
data=p.get_memory_mapped_image()
functions=[json.loads(line) for line in (HERE.parent/'ciff-fields/decompiled/CLARiSOFT.exe/functions.jsonl').read_text().splitlines()]
needle=b'\xff\x15'+struct.pack('<I',0xefc094)
at=data.find(needle)
while at>=0:
    address=p.OPTIONAL_HEADER.ImageBase+at
    f=max((f for f in functions if int(f['address'],16)<=address),key=lambda f:int(f['address'],16))
    print(hex(address),f['address'],f['name'])
    at=data.find(needle,at+1)

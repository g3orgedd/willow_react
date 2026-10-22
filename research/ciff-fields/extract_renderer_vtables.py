"""Recover native renderer/helper vtables through MSVC x86 RTTI."""
from pathlib import Path
import json, re, struct, sys
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent/'clst/tools'))
import pefile
from inventory import DATA

def inspect(name):
    pe=pefile.PE(str(DATA/name)); base=pe.OPTIONAL_HEADER.ImageBase
    memory=pe.get_memory_mapped_image()
    def u32(offset): return struct.unpack_from('<I',memory,offset)[0]
    def code(address):
        return any(s.Characteristics & 0x20000000 and base+s.VirtualAddress<=address<base+s.VirtualAddress+max(s.Misc_VirtualSize,s.SizeOfRawData) for s in pe.sections)
    classes=[]
    for match in re.finditer(rb'\.\?AVC[^\x00]{2,100}@@\x00',memory):
        className=match.group()[:-1].decode('ascii','replace')
        if not re.search(r'BarcodeObjHelper|SmallBarcodeObjHelper|BarcodeRender|CTextField@@|CAllBarcodeRoot@@|CBarcode@@',className): continue
        descriptor=base+match.start()-8
        locators=[]
        for offset in range(0,len(memory)-20,4):
            if u32(offset)==0 and u32(offset+12)==descriptor and u32(offset+4)<0x10000:
                locators.append(base+offset)
        for locator in locators:
            for offset in range(0,len(memory)-8,4):
                if u32(offset)!=locator or not code(u32(offset+4)): continue
                functions=[]
                index=1
                while offset+index*4+4<=len(memory) and code(u32(offset+index*4)) and index<=40:
                    functions.append(f'{u32(offset+index*4):08x}'); index+=1
                classes.append({'class':className,'typeDescriptor':f'{descriptor:08x}','locator':f'{locator:08x}',
                                'vtable':f'{base+offset+4:08x}','functions':functions})
    output=HERE/'metadata'/f'{name}.renderer-vtables.json'
    output.write_text(json.dumps(classes,indent=2),encoding='utf8')
    roots=HERE/'metadata'/f'{name}.roots.txt'
    addresses=set(roots.read_text().splitlines())
    for c in classes: addresses.update(c['functions'])
    roots.write_text('\n'.join(sorted(addresses)),encoding='ascii')
    return {'module':name,'classes':len(classes),'rootFunctions':len(addresses)}

if __name__=='__main__':
    print(json.dumps([inspect(name) for name in ['CLCSBarcodeField.dll','CLCSSmallBarcode.dll','CLCSTextBasedField.dll']],indent=2))

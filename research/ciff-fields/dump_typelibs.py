"""Read embedded COM type libraries. Does not instantiate application classes."""
from pathlib import Path
import ctypes, json, sys, uuid
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / 'clst/tools'))
from comtypes.typeinfo import LoadTypeLibEx
from inventory import NAMES, DATA
import pefile

def type_desc(info, td, depth=0):
    vt = int(td.vt)
    if depth > 8: return {'vt': vt}
    result = {'vt': vt}
    if vt in (26, 27): result['target'] = type_desc(info, td._.lptdesc[0], depth + 1)
    elif vt == 29:
        ref = info.GetRefTypeInfo(td._.hreftype)
        result['name'] = ref.GetDocumentation(-1)[0]
    return result

def library(filename):
    lib = LoadTypeLibEx(str(filename))
    pe = pefile.PE(str(filename))
    data = filename.read_bytes()
    types = []
    for index in range(lib.GetTypeInfoCount()):
        info = lib.GetTypeInfo(index)
        attr = info.GetTypeAttr()
        documentation = info.GetDocumentation(-1)
        guid = str(attr.guid)
        needle = uuid.UUID(guid.strip('{}')).bytes_le
        offsets, at = [], data.find(needle) if any(needle) else -1
        while at >= 0:
            try: offsets.append(f'{pe.OPTIONAL_HEADER.ImageBase + pe.get_rva_from_offset(at):08x}')
            except Exception: pass
            at = data.find(needle, at + 1)
        item = {'index': index, 'name': documentation[0], 'documentation': documentation[1],
                'guid': guid, 'guidLocations': offsets, 'kind': int(attr.typekind), 'functions': [], 'variables': [], 'implements': []}
        for j in range(attr.cImplTypes):
            ref = info.GetRefTypeInfo(info.GetRefTypeOfImplType(j))
            item['implements'].append({'name': ref.GetDocumentation(-1)[0], 'guid': str(ref.GetTypeAttr().guid)})
        for j in range(attr.cFuncs):
            f = info.GetFuncDesc(j)
            names = info.GetNames(f.memid, max(f.cParams + 2, 32))
            method = {'name': names[0], 'names': names, 'memid': f.memid,
                      'invkind': f.invkind, 'vtableOffset32': (f.oVft // ctypes.sizeof(ctypes.c_void_p)) * 4,
                      'documentation': info.GetDocumentation(f.memid)[1],
                      'returnType': type_desc(info, f.elemdescFunc.tdesc), 'parameters': []}
            for k in range(f.cParams):
                p = f.lprgelemdescParam[k]
                method['parameters'].append({'type': type_desc(info, p.tdesc), 'flags': p._.paramdesc.wParamFlags})
            item['functions'].append(method)
        for j in range(attr.cVars):
            v = info.GetVarDesc(j)
            value = v._.lpvarValue[0].value if v.varkind == 2 else None
            item['variables'].append({'name': info.GetDocumentation(v.memid)[0], 'value': value})
        types.append(item)
    result = {'file': filename.name, 'name': lib.GetDocumentation(-1)[0], 'types': types}
    (HERE / 'metadata' / (filename.name + '.typelib.json')).write_text(json.dumps(result, ensure_ascii=True, indent=2), encoding='utf8')
    print(json.dumps({'file': filename.name, 'typeCount': len(types), 'interfaces': [t['name'] for t in types if t['kind'] in (3,4)]}))

if __name__ == '__main__':
    for name in sys.argv[1:] or NAMES:
        try: library(DATA / name)
        except Exception as error: print(json.dumps({'file': name, 'error': str(error)}))

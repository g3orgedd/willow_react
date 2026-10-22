"""Extract the installed CLZipherBCP2 XMLFILE/203 resource and index Videojet profiles."""
from pathlib import Path
from collections import defaultdict
import hashlib, json, sys, xml.etree.ElementTree as ET

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent/'clst/tools'))
import pefile

def flatten(element, prefix=''):
    out = {}
    counts = defaultdict(int)
    for child in element:
        counts[child.tag] += 1
        key = prefix + '/' + child.tag + '[' + str(counts[child.tag]) + ']'
        for k,v in child.attrib.items(): out[key+'/@'+k] = v
        if len(child): out.update(flatten(child,key))
        else: out[key] = (child.text or '').strip()
    return out

def main():
    source = Path(r'C:\Program Files (x86)\CLARICOM\Data\CLZipherBCP2.dll')
    pe = pefile.PE(str(source))
    resource = next(t for t in pe.DIRECTORY_ENTRY_RESOURCE.entries if str(t.name)=='XMLFILE')
    entry = next(e for e in resource.directory.entries if e.id == 203).directory.entries[0]
    data = pe.get_data(entry.data.struct.OffsetToData, entry.data.struct.Size)
    root = ET.fromstring(data)
    output = HERE/'printer-oracle'
    output.mkdir(exist_ok=True)
    (output/'embedded-capabilities.xml').write_bytes(data)
    mappings = [dict(m.attrib) for x in root.findall('./Configurations/Mappings')
                if x.get('CAPI')=='Videojet (CLARiTY)' for m in x]
    coders = {c.get('CoderName'): c for c in root.findall('CoderCapabilities')}
    profiles = []
    for m in mappings:
        c = coders[m['CoderName']]
        scalar = {e.tag: (e.text or '').strip() for e in c if not len(e) and e.tag != 'AKA'}
        profiles.append(m | {'scalars':scalar, 'flattened':flatten(c),
                            'aliases':[e.text for e in c.findall('AKA')],
                            'childOrder':[e.tag for e in c]})
    pairs = []
    targets = ['Zodiac Continuous','Zodiac Intermittent','Zodiac(32mm) Continuous','Zodiac(32mm) Intermittent',
               'Forrester Continuous','Forrester Intermittent','Nimitz Continuous','Nimitz Intermittent']
    for name in targets[1:]:
        left,right = flatten(coders[targets[0]]),flatten(coders[name])
        diff = [{'path': k, 'left':left.get(k), 'right':right.get(k)} for k in sorted(left.keys()|right.keys())
                if left.get(k)!=right.get(k) and '/AKA[' not in k]
        pairs.append({'left':targets[0],'right':name,'differences':diff})
    result={'source':str(source),'dllSha256':hashlib.sha256(source.read_bytes()).hexdigest(),
            'resource':{'type':'XMLFILE','id':203,'language':entry.id,'rva':hex(entry.data.struct.OffsetToData),
                        'size':len(data),'sha256':hashlib.sha256(data).hexdigest()},
            'mappings':mappings,'profiles':profiles,'comparisons':pairs}
    (HERE/'native-printer-capabilities.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf8')
    (output/'profile-mappings.json').write_text(json.dumps(mappings,ensure_ascii=False,indent=2),encoding='utf8')
    for p in profiles:
        if p['DisplayName'].startswith('DataFlex'):
            print(json.dumps({k:p[k] for k in ['DisplayName','CoderName']} | {'geometry':{k:p['scalars'].get(k) for k in ['CoderUnits','XResolution','YResolution','MaximumImageWidth','MaximumImageHeight','DefaultImageHeight']}},ensure_ascii=False))
    for p in pairs:
        print(p['left'],'vs',p['right'],'differences',len(p['differences']))
        for d in p['differences'][:12]: print(d)

if __name__ == '__main__': main()

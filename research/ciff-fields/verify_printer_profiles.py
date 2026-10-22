"""Check independently parsed native printer probes and hashes of cited binaries."""
from pathlib import Path
import hashlib, json, xml.etree.ElementTree as ET

HERE=Path(__file__).resolve().parent
DATA=Path(r'C:\Program Files (x86)\CLARICOM\Data')
OUT=HERE/'printer-oracle'

def tree(node):
    return (node.tag,tuple(sorted(node.attrib.items())),node.text or '',tuple(tree(c) for c in node))

def fields(root, ignore_clock=False):
    nodes=root.findall('SubImage/Field')
    if ignore_clock:
        for f in nodes:
            if f.get('Name')=='TEXT_1': f.find('CalcData').text='(native clock)'
    return tuple(tree(f) for f in nodes)

def main():
    inventory=json.loads((HERE/'inventory.json').read_text())
    hashes=[]
    for item in inventory:
        path=DATA/item['name'] if item['name']!='CLARiSOFT.exe' else DATA.parent/'CLARiSOFT/CLARiSOFT.exe'
        actual=hashlib.sha256(path.read_bytes()).hexdigest()
        assert actual==item['sha256'],path
        hashes.append({'module':item['name'],'sha256':actual,'matchesPriorDecompilation':True})
    records=json.loads((OUT/'results.json').read_text())
    headers=json.loads((OUT/'header-only-results.json').read_text())
    retargets=json.loads((OUT/'retarget-metadata-results.json').read_text())
    assert len(records)==len(headers)==len(retargets)==18
    assert all(r['status']=='ok' for r in records+headers+retargets)
    roots={r['profile']:ET.parse(OUT/r['file']).getroot() for r in records}
    common=[r for r in records if abs(r['xRes']-.12)<1e-6]
    baseline=fields(roots[common[0]['profile']],True)
    for r in common: assert fields(roots[r['profile']],True)==baseline,r['profile']
    matrix=[]
    for r in records:
        root=roots[r['profile']]
        assert [f.get('Name') for f in root.findall('SubImage/Field')]==['TEXT_0','TEXT_1','TEXT_2','TEXT_3','DM']
        dm=root.find("SubImage/Field[@Name='DM']")
        actual={k:int(dm.findtext(path)) for k,path in [('W','W'),('H','H'),('BcH','Barcode/BcH'),('ModuleSize','Barcode/DataMatrix/ModuleSize')]}
        expected={'W':836,'H':836,'BcH':836,'ModuleSize':38} if '6230' in r['profile'] else {'W':924,'H':924,'BcH':924,'ModuleSize':42}
        assert actual==expected,(r['profile'],actual)
        matrix.append({'profile':r['profile'],'xRes':r['xRes'],'requestedHmm':1000,**actual})
    base=ET.parse(OUT/headers[0]['file']).getroot()
    base.find('Header').set('DesignedFor','(profile)')
    printer_type_overrides=[]
    for r in headers:
        root=ET.parse(OUT/r['file']).getroot()
        assert root.find('Header').get('DesignedFor')==r['profile']
        root.find('Header').set('DesignedFor','(profile)')
        subheader=root.find('SubImage/SubHeader')
        old=subheader.attrib.pop('PrinterType',None)
        if r['profile']!=headers[0]['profile']: assert old==headers[0]['profile'],r['profile']
        else: assert old is None
        printer_type_overrides.append({'newDesignedFor':r['profile'],'serializedPrinterType':old})
        assert tree(root)==tree(base),r['profile']
    for r in retargets:
        root=ET.parse(OUT/r['file']).getroot()
        assert root.find('SubImage/SubHeader').get('PrinterType') is None
        assert root.find('Header').get('DesignedFor')==r['profile']
        root.find('Header').set('DesignedFor','(profile)')
        assert tree(root)==tree(base),r['profile']
    caps=json.loads((HERE/'native-printer-capabilities.json').read_text())
    profiles={p['DisplayName']:p for p in caps['profiles']}
    for mode in ['Continuous','Intermittent']:
        assert profiles['DataFlex 6320(53mm) - '+mode]['CoderName']==profiles['DataFlex 6420(53mm) - '+mode]['CoderName']
    report={'binaryHashes':hashes,'successfulProfileProbes':len(records),'headerOnlyProbes':len(headers),'retargetMetadataProbes':len(retargets),
            'equalFieldsAt12DotsPerMm':len(common),'clockNormalization':'Only TEXT_1 CalcData; native wall clock is not deterministic.',
            'matrix':matrix,'printerTypeOverrides':printer_type_overrides,'limitations':['Text CreateField/UpdateData/CalculateSize exercised; application placement and W/H assignment not emulated.',
                'DM model was configured explicitly before public Resize; UI barcode selection dialog not used.',
                'No printer download, firmware or physical printing was exercised.']}
    (HERE/'printer-profile-verification.json').write_text(json.dumps(report,ensure_ascii=False,indent=2),encoding='utf8')
    print(json.dumps({k:v for k,v in report.items() if k not in ['binaryHashes','matrix','printerTypeOverrides']},ensure_ascii=False))

if __name__=='__main__': main()

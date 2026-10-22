"""Read-only CIFF corpus audit. Never treats filename/provenance as proof of origin."""
from pathlib import Path
from collections import Counter, defaultdict
import hashlib, json, xml.etree.ElementTree as ET

HERE = Path(__file__).resolve().parent
SOURCE = Path(r'C:\Users\GigaGeorge\Desktop\w_project\Templates VideoJet')

def inspect(path):
    raw = path.read_bytes()
    parse_warning = None
    try:
        root = ET.fromstring(raw)
    except ET.ParseError as exc:
        if raw[:2] not in [b'\xff\xfe',b'\xfe\xff']: raise
        root = ET.fromstring(raw.decode('utf-16'))
        parse_warning = str(exc)
    fields = []
    for si, image in enumerate(root.findall('SubImage')):
        for field in image.findall('Field'):
            fields.append({
                'image': si, 'name': field.get('Name'), 'type': field.findtext('FldType'),
                'clsid': field.findtext('CLSID'), 'order': [x.tag for x in field],
                'barcode': [x.tag for x in field.find('Barcode')] if field.find('Barcode') is not None else None,
                'objects': [{'attributes': dict(obj.attrib), 'order': [x.tag for x in obj],
                             'dataType': obj.findtext('DataType'),
                             'source': next((x.tag for x in obj if x.tag in ['SrcField','SrcData','VarText','OffsetDate','CounterText','CLARICOMSSCC']), None)}
                            for obj in field.findall('Data/Object')]
            })
    return {'file': str(path.relative_to(SOURCE)), 'sha256': hashlib.sha256(raw).hexdigest(),
            'bytes': len(raw), 'bom': raw[:2].hex(), 'version': root.get('Version'), 'parseWarning':parse_warning,
            'designedFor': root.find('Header').get('DesignedFor') if root.find('Header') is not None else None,
            'rootOrder': [x.tag for x in root], 'headerOrder': [x.tag for x in root.find('Header')] if root.find('Header') is not None else [],
            'subHeaders': [dict((x.tag, x.text) for x in h) for h in root.findall('SubImage/SubHeader')],
            'fields': fields}

def main():
    records, failures = [], []
    for path in sorted(SOURCE.rglob('*.ciff')):
        try: records.append(inspect(path))
        except Exception as exc: failures.append({'file': str(path.relative_to(SOURCE)), 'error': str(exc)})
    groups = defaultdict(list)
    for record in records: groups[record['designedFor'] or '(missing)'].append(record)
    summary = {'source': str(SOURCE), 'totalFiles':len(records)+len(failures), 'files': len(records), 'uniqueHashes': len(set(r['sha256'] for r in records)),
               'encodingWarnings':[{'file':r['file'],'warning':r['parseWarning']} for r in records if r['parseWarning']],
               'failures': failures, 'versions': dict(Counter(r['version'] for r in records)), 'profiles': []}
    for profile, items in sorted(groups.items()):
        fields = [f for r in items for f in r['fields']]
        dimensions = Counter(tuple(h.get(k) for k in ['MaxImageWidth','MaxImageHeight','XRes','CurrentOrientation']) for r in items for h in r['subHeaders'])
        summary['profiles'].append({'designedFor': profile, 'files': len(items), 'uniqueHashes': len(set(r['sha256'] for r in items)),
            'fieldTypes': dict(Counter(f['type'] or '(missing)' for f in fields)),
            'dimensions': [{'MaxImageWidth': k[0], 'MaxImageHeight': k[1], 'XRes': k[2], 'CurrentOrientation': k[3], 'count': v} for k,v in dimensions.most_common()],
            'fieldOrderSignatures': [{'order': list(k), 'count': v} for k,v in Counter(tuple(f['order']) for f in fields).most_common()],
            'examples': [r['file'] for r in items[:6]]})
    (HERE/'template-corpus.json').write_text(json.dumps({'summary':summary,'records':records}, ensure_ascii=False, indent=2), encoding='utf8')
    print(json.dumps({k:v for k,v in summary.items() if k != 'profiles'}, ensure_ascii=False))
    for p in summary['profiles']:
        print(json.dumps({k:p[k] for k in ['designedFor','files','uniqueHashes','fieldTypes','dimensions']}, ensure_ascii=False))

if __name__ == '__main__': main()

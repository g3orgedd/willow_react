"""Compose optional metadata using original native transform instructions.

This tests transform calls and native pathname splitting, not the document COM
model or the complete optional helper's Windows exception/formatting plumbing.
"""
from pathlib import Path
import sys
import json

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / 'native'))
from native_oracle import NativeOracle
from native_splitpath import generation_filename

oracle = NativeOracle()
examples = [
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': [], 'mask': '0',
     'sourcePath': r'C:\labels\Report.ciff'},
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': [], 'mask': '0',
     'sourcePath': r'C:\labels\Report.ciff.new'},
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': ['21:22'], 'mask': '1',
     'sourcePath': r'C:\labels\Report.ciff'},
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': ['21:22'], 'mask': '1',
     'sourcePath': r'D:\other\Report.ciff'},
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': ['21:22'], 'mask': '1',
     'sourcePath': 'Report.CIFF.NEW'},
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': ['21:22'], 'mask': '1',
     'sourcePath': 'Имя шаблона.ciff'},
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': ['21:22'], 'mask': '1',
     'sourcePath': 'a' * 99 + '😀' + '.ciff'},
    {'dateOffsetCount': 0, 'subImageCount': 1, 'fieldValues': ['21:22'], 'mask': '1',
     'sourcePath': 'C:/folder/a:b.ciff'},
]

results = []
for example in examples:
    example['includeFileMetadata'] = True
    counts = ''.join(f'{min(number, 99):02d}' for number in
                     [example['dateOffsetCount'], example['subImageCount'], len(example['fieldValues'])])
    mask = int(example['mask'], 16)
    payload = ''.join(value for index, value in enumerate(example['fieldValues'])
                      if (mask >> index) & 1)
    payload = payload.encode('utf-16-le', 'surrogatepass')[:40].decode('utf-16-le', 'surrogatepass')
    mask_fragment = oracle.encrypt(f'{mask:08X}', counts)['output']
    payload_fragment = oracle.encrypt(payload, 'TagData')['output'] if example['fieldValues'] else ''
    filename = generation_filename(example['sourcePath'])
    filename_fragment = oracle.encrypt(filename, 'TagData')['output']
    length_fragment = oracle.encrypt(f'{len(filename_fragment):08x}', counts)['output']
    inner = length_fragment + filename_fragment + mask_fragment + payload_fragment
    token = oracle.encrypt(inner, 'TpyRcNeyeK')['output']
    results.append({'input': example, 'counts6': counts, 'fileMetadata': filename,
                    'metadataFragment': filename_fragment,
                    'metadataLengthFragment': length_fragment,
                    'normalIntermediate': mask_fragment + payload_fragment,
                    'intermediate': inner, 'clStVersionInfo': token,
                    'length': len(token)})

assert results[0]['clStVersionInfo'] == results[1]['clStVersionInfo']
assert results[2]['clStVersionInfo'] == results[3]['clStVersionInfo']
report = {'method': 'manual pipeline composition; native CiffMgr.dll transform and filename splitting',
          'caseCount': len(results), 'cases': results}
(HERE / 'optional-composition-results.json').write_text(json.dumps(report, ensure_ascii=True, indent=2), encoding='utf8')
print(json.dumps({'caseCount': len(results), 'emptyReportLength': results[0]['length'],
                  'timeReportLength': results[2]['length'],
                  'report': str(HERE / 'optional-composition-results.json')}))

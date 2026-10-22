"""Compose the observed ClSt pipeline from original native transform calls.

This does not run the COM document generator itself. Each transform is actual
CiffMgr.dll code. Inputs are explicit known mask/counters/selected plaintext.
"""
import json
from native_oracle import HERE, NativeOracle, utf16


def clip_utf16(text, count):
    # Native SysAllocStringLen(..., 20) counts WCHARs, not Unicode codepoints.
    # Retain an isolated surrogate when truncation cuts a supplementary symbol.
    return utf16(text)[:count * 2].decode('utf-16-le', 'surrogatepass')


def make_cases():
    mask31_values = ['ignored'] * 32
    mask31_values[31] = 'last32'
    three_bit_values = ['ignored'] * 32
    three_bit_values[0], three_bit_values[1], three_bit_values[31] = 'alpha', 'beta', 'omega'
    capped_values = ['ignored'] * 105
    capped_values[31] = 'capped'
    return [
        ('empty document collections', dict(fieldValues=[], subImageCount=0, mask=0)),
        ('one SubImage with zero fields', dict(fieldValues=[], mask=0)),
        ('one field selected with empty payload', dict(fieldValues=[''], mask=1)),
        ('one fixed ASCII character', dict(fieldValues=['A'], mask=1)),
        ('one TimeText field from confirmed vector', dict(fieldValues=['21:22'], mask=1)),
        ('barcode logical payload clipped to 20 UTF16 units',
         dict(fieldValues=['~1010000000000000021000000~d029930000'] + ['ignored'] * 14, mask=1)),
        ('two-bit collection concatenation', dict(fieldValues=['left', 'right'], mask=3)),
        ('three-bit collection concatenation', dict(fieldValues=['ab', 'cd', 'ef'], mask=7)),
        ('three nonadjacent bits', dict(fieldValues=['ab', 'ignored', 'cd', 'ignored', 'ef'], mask=0x15)),
        ('ASCII clipping after concatenation', dict(fieldValues=['abcdefghijklmnopqr', 'STUVW'], mask=3)),
        ('Unicode clipping preserves a full surrogate pair', dict(fieldValues=['abc' * 6, '\U0001f600x'], mask=3)),
        ('Unicode clipping splits a surrogate pair', dict(fieldValues=['0123456789abcdefghi', '\U0001f600'], mask=3)),
        ('embedded NUL in selected BSTR', dict(fieldValues=['abc\0def'], mask=1)),
        ('high mask bit 31', dict(fieldValues=mask31_values, mask=0x80000000)),
        ('three bits including bit31', dict(fieldValues=three_bit_values, mask=0x80000003)),
        ('counter saturation at 99 with bit31',
         dict(fieldValues=capped_values, dateOffsetCount=120, subImageCount=100, mask=0x80000000)),
    ]


def main():
    oracle = NativeOracle()
    results = []
    for description, input_data in make_cases():
        fields = input_data['fieldValues']
        mask_value = input_data['mask']
        mask = f'{mask_value:08X}'
        counts = ''.join(f'{min(value, 99):02d}' for value in
                         [input_data.get('dateOffsetCount', 0), input_data.get('subImageCount', 1), len(fields)])
        source_payload = ''.join(value for index, value in enumerate(fields[:32]) if (mask_value >> index) & 1)
        selected_payload = clip_utf16(source_payload, 20)
        metadata_block = oracle.encrypt(mask, counts)['output']
        selected_block = oracle.encrypt(selected_payload, 'TagData')['output'] if fields else ''
        core = metadata_block + selected_block
        result = oracle.encrypt(core, 'TpyRcNeyeK')['output']
        results.append({'description': description, 'input': input_data,
                        'fieldValues': fields, 'dateOffsetCount': input_data.get('dateOffsetCount', 0),
                        'subImageCount': input_data.get('subImageCount', 1),
                        'maskHex': mask, 'counterKey': counts,
                        'sourcePayload': source_payload, 'sourcePayloadUtf16Length': len(utf16(source_payload)) // 2,
                        'selectedPayload': selected_payload, 'selectedPayloadUtf16Length': len(utf16(selected_payload)) // 2,
                        'metadataBlock': metadata_block, 'selectedBlock': selected_block, 'core': core,
                        'clStVersionInfo': result, 'length': len(result)})
    assert results[0]['clStVersionInfo'] == results[1]['clStVersionInfo']
    assert all(case['selectedPayloadUtf16Length'] <= 20 for case in results)
    report = {'method': 'manual composition using original native transform; excludes optional file metadata branch',
              'emptyFieldNativePathSupportedByGeneratorDisassembly': True, 'cases': results}
    (HERE / 'composition-results.json').write_text(json.dumps(report, ensure_ascii=True, indent=2), encoding='utf8')
    print(json.dumps({'caseCount': len(results), 'emptyTemplateOutput': results[1]['clStVersionInfo'],
                      'emptyTemplateLength': results[1]['length'], 'report': str(HERE / 'composition-results.json')}))


if __name__ == '__main__':
    main()

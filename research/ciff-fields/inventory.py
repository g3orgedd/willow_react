"""Read-only inventory of native CIFF components and readable string locations."""
from pathlib import Path
import hashlib, json, re, sys

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / 'clst/tools'))
import pefile

DATA = Path(r'C:\Program Files (x86)\CLARICOM\Data')
NAMES = ['CiffMgr.dll', 'CiffHelper.dll', 'CLCSTextBasedField.dll', 'CLCSBarcodeField.dll',
         'CLCSGraphicBasedField.dll', 'CLCSGraphicPrimitive.dll', 'CLCSBlockTextField.dll',
         'CLCSRichTextBlockField.dll', 'CLCSSmallBarcode.dll', 'CLCSBinaryFontComponent.dll',
         'CLZipherBCP2.dll', 'CiffDateFormats.dll', 'CLCiffConversion_Data.dll',
         'CLCiffConversion_Layout.dll', '../CLARiSOFT/CLARiSOFT.exe']

def string_items(data):
    for encoding, expression in [('ascii', rb'[\x20-\x7e]{4,}'), ('utf-16-le', rb'(?:[\x20-\x7e]\x00){4,}')]:
        for match in re.finditer(expression, data):
            yield match.start(), encoding, match.group().decode(encoding)

def inspect(name):
    filename = DATA / name
    name = filename.name
    data = filename.read_bytes()
    pe = pefile.PE(data=data)
    base = pe.OPTIONAL_HEADER.ImageBase
    def location(offset):
        try: return f'{base + pe.get_rva_from_offset(offset):08x}'
        except Exception: return None
    strings = [{'va': location(offset), 'fileOffset': offset, 'encoding': enc, 'text': text}
               for offset, enc, text in string_items(data)]
    exports = [{'name': item.name.decode('ascii', 'replace') if item.name else None,
                'ordinal': item.ordinal, 'va': f'{base + item.address:08x}'}
               for item in getattr(pe, 'DIRECTORY_ENTRY_EXPORT', type('Empty', (), {'symbols': []})).symbols]
    imports = [{'library': library.dll.decode('ascii', 'replace'),
                'names': [item.name.decode('ascii', 'replace') if item.name else item.ordinal for item in library.imports]}
               for library in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', [])]
    item = {'name': name, 'source': str(filename), 'size': len(data), 'sha256': hashlib.sha256(data).hexdigest(),
            'imageBase': f'{base:08x}', 'exports': exports, 'imports': imports,
            'interestingStrings': [s for s in strings if re.search(
                r'(Seriali|Ciff|FixedText|DateText|CounterText|OffsetDate|CalcData|FldType|SrcField|DataType|Object|SubImage|Font|Barcode|DataMatrix|ImageDesign|Default|Graphic)', s['text'], re.I)]}
    (HERE / 'metadata' / (name + '.strings.json')).write_text(json.dumps(strings, ensure_ascii=True, indent=2), encoding='utf8')
    (HERE / 'metadata' / (name + '.json')).write_text(json.dumps(item, ensure_ascii=True, indent=2), encoding='utf8')
    return {k: item[k] for k in ['name', 'size', 'sha256', 'imageBase']} | {'stringCount': len(strings)}

if __name__ == '__main__':
    result = [inspect(name) for name in (sys.argv[1:] or NAMES)]
    (HERE / 'inventory.json').write_text(json.dumps(result, indent=2), encoding='utf8')
    print(json.dumps(result, indent=2))

from pathlib import Path
import json, struct, sys, hashlib

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / "research/clst/tools"))
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

DEST = Path(__file__).resolve().parent
targets = [
    ("CLCSTextBasedField.dll", Path(r"C:\Program Files (x86)\CLARICOM\Data\CLCSTextBasedField.dll"), [0x42458960, 0x424264FB, 0x42458843]),
    ("CLARiSOFT.exe", Path(r"C:\Program Files (x86)\CLARICOM\CLARiSOFT\CLARiSOFT.exe"), [0x00E62F49]),
]
manifest = []
disassembler = Cs(CS_ARCH_X86, CS_MODE_32)
for module, source, functions in targets:
    pe = pefile.PE(str(source))
    image_base = pe.OPTIONAL_HEADER.ImageBase
    index_path = ROOT / "research/ciff-fields/decompiled" / module / "functions.jsonl"
    index = {int(item["address"], 16): item for item in map(json.loads, index_path.read_text(encoding="utf-8").splitlines())}
    record = {"module": module, "path": str(source), "sha256": hashlib.sha256(source.read_bytes()).hexdigest(), "functions": []}
    for address in functions:
        size = index[address]["size"]
        output = DEST / ("%s-%08x.asm" % (module, address))
        code = pe.get_data(address - image_base, size)
        output.write_text("\n".join("%08x  %-9s %s" % (ins.address, ins.mnemonic, ins.op_str) for ins in disassembler.disasm(code, address)) + "\n", encoding="utf-8")
        record["functions"].append({"va": "%08x" % address, "size": size, "asm": output.name})
    manifest.append(record)

constants = {}
for source, values in [
    (Path(r"C:\Program Files (x86)\CLARICOM\Data\CLCSTextBasedField.dll"), [(0x424983E0, "f"), (0x424983F4, "f"), (0x424983F0, "f")]),
    (Path(r"C:\Program Files (x86)\CLARICOM\Data\CLCiffConversion_Layout.dll"), [(0x45447A24, "f")]),
    (Path(r"C:\Program Files (x86)\CLARICOM\CLARiSOFT\CLARiSOFT.exe"), [(0x00EFE90C, "f"), (0x00F02E30, "d"), (0x00F017C8, "d")]),
]:
    pe = pefile.PE(str(source))
    for va, fmt in values:
        constants["%08x" % va] = struct.unpack("<" + fmt, pe.get_data(va-pe.OPTIONAL_HEADER.ImageBase, struct.calcsize(fmt)))[0]

(DEST / "asm-manifest.json").write_text(json.dumps({"sources": manifest, "constants": constants}, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
print(json.dumps({"sources": manifest, "constants": constants}, indent=2))

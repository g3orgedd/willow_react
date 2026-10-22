"""Read-only native evidence for the optional ClStVersionInfo metadata branch."""
from pathlib import Path
import sys
import struct

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

path = Path(r'C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll')
pe = pefile.PE(str(path))
base = pe.OPTIONAL_HEADER.ImageBase

def at(address, length):
    return pe.get_data(address - base, length)

for address in (0x6814872c, 0x6814873c, 0x6814b838, 0x6814b858, 0x6814b864, 0x6814b870, 0x6814b87c):
    raw = at(address, 100)
    string = raw.decode('utf-16-le').split('\0')[0]
    print(f'{address:08X} {string!r}')
print('6814BE48 DWORD', struct.unpack('<I', at(0x6814be48, 4))[0])
for address in (0x68148694, 0x681486a0, 0x68148728):
    print(f'{address:08X} table', ' '.join(f'{v:08X}' for v in struct.unpack('<12I', at(address, 48))))

targets = set((0x6810a9b5, 0x6811861c, 0x681182fa, 0x68118e73))
for section in pe.sections:
    if not section.Characteristics & 0x20000000:
        continue
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    instructions = list(md.disasm(section.get_data(), base + section.VirtualAddress))
    for index, instruction in enumerate(instructions):
        operand = instruction.op_str.lower()
        direct_target = None
        if instruction.mnemonic == 'call':
            try:
                direct_target = int(operand, 16)
            except ValueError:
                pass
        if (direct_target in targets or
            (instruction.mnemonic == 'mov' and operand.startswith('byte ptr [') and ' + 0xc]' in operand) or
            operand.endswith('0x68148728') or
            '0x6814be48' in operand):
            print('\nREFERENCE')
            for item in instructions[max(0, index - 8):index + 7]:
                print(f'{item.address:08X} {item.mnemonic:8} {item.op_str}')

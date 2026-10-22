from pathlib import Path
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

path = Path(r'C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll')
pe = pefile.PE(str(path))
base = pe.OPTIONAL_HEADER.ImageBase
md = Cs(CS_ARCH_X86, CS_MODE_32)
md.detail = True
start, end = (int(sys.argv[1], 16), int(sys.argv[2], 16)) if len(sys.argv) > 2 else (0x68117a00, 0x68118240)
for insn in md.disasm(pe.get_data(start-base, end-start), start):
    print(f'{insn.address:08X} {insn.bytes.hex():24s} {insn.mnemonic:8s} {insn.op_str}')

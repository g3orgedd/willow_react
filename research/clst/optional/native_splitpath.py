"""Execute CiffMgr's own _wsplitpath_s body in Unicorn without loading the DLL.

The bounded wide-copy CRT helper is replaced with a deterministic memory copy;
all filename/extension separation instructions come from the installed binary.
"""
from pathlib import Path
import sys
import struct
import json

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EAX, UC_X86_REG_EIP

DLL = Path(r'C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll')
PE = pefile.PE(str(DLL))
BASE = PE.OPTIONAL_HEADER.ImageBase
STACK = 0x10000000
HEAP = 0x20000000
STOP = STACK

def u32(value):
    return struct.pack('<I', value)

def split_native(path):
    machine = Uc(UC_ARCH_X86, UC_MODE_32)
    image = PE.get_memory_mapped_image()
    machine.mem_map(BASE, (len(image) + 4095) & ~4095)
    machine.mem_write(BASE, image)
    machine.mem_map(STACK, 0x10000)
    machine.mem_map(HEAP, 0x10000)
    encoded = path.encode('utf-16-le', 'surrogatepass') + b'\0\0'
    machine.mem_write(HEAP, encoded)
    name_pointer, extension_pointer = HEAP + 0x1000, HEAP + 0x2000
    args = [HEAP, 0, 0, 0, 0, name_pointer, 256, extension_pointer, 256]
    esp = STACK + 0xf000
    machine.mem_write(esp, b''.join(u32(value) for value in [STOP, *args]))
    machine.reg_write(UC_X86_REG_ESP, esp)

    def copy_hook(machine, address, size, context):
        if address != 0x681349da:
            return
        stack_pointer = machine.reg_read(UC_X86_REG_ESP)
        ret, destination, buffer_size, source, count = struct.unpack('<5I', machine.mem_read(stack_pointer, 20))
        assert count < buffer_size, 'copy helper would report range error'
        machine.mem_write(destination, bytes(machine.mem_read(source, count * 2)) + b'\0\0')
        machine.reg_write(UC_X86_REG_EAX, 0)
        machine.reg_write(UC_X86_REG_ESP, stack_pointer + 4)
        machine.reg_write(UC_X86_REG_EIP, ret)

    machine.hook_add(UC_HOOK_CODE, copy_hook)
    machine.emu_start(0x68134dca, STOP, count=100000)
    assert machine.reg_read(UC_X86_REG_EIP) == STOP
    assert machine.reg_read(UC_X86_REG_EAX) == 0

    def read_wide(pointer):
        raw = bytes(machine.mem_read(pointer, 512))
        return raw.decode('utf-16-le', 'surrogatepass').split('\0', 1)[0]

    return read_wide(name_pointer), read_wide(extension_pointer)

def generation_filename(path):
    name, extension = split_native(path)
    if extension == '.new':
        name, extension = split_native(name)
    # Truncation is wchar_t based; preserve lone surrogate if split at unit 100.
    raw = name.encode('utf-16-le', 'surrogatepass')[:200]
    return raw.decode('utf-16-le', 'surrogatepass') + extension

if __name__ == '__main__':
    examples = [
        r'C:\labels\Report.ciff', r'C:\labels\Report.ciff.new',
        r'D:\other\Report.ciff', 'Report.CIFF.NEW', 'Report.CIFF.new',
        'Report.new', 'Report', '.ciff', '.new', 'a.b.ciff',
        r'C:\dotted.folder\plain', r'C:\dotted.folder\Report.ciff',
        'dir/Report.ciff', 'C:Report.ciff', 'Имя шаблона.ciff',
        'Report.', '.', '..', 'a..', 'C:', 'C:/', 'C:/labels/',
        'C:Report', 'X:.ciff', ':Report.ciff', 'ab:ciff',
        '1:Report.ciff', 'C:/folder/a:b.ciff', 'C:/folder/1:Report.ciff',
        'x' * 101 + '.ciff', 'a' * 99 + '😀' + '.ciff',
    ]
    for path in examples:
        name, extension = split_native(path)
        print(json.dumps({'sourcePath': path, 'nativeName': name,
                          'nativeExtension': extension,
                          'metadataPlaintext': generation_filename(path)},
                         ensure_ascii=True))

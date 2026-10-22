"""Run original CiffMgr.dll x86 cipher code in Unicorn, without loading DLLs.

The Boolean network/cipher/encoding routines execute original machine code.
Only OLE BSTR memory management and CRT wchar copy/length are emulated.
No network, printer, file, or application state is accessed by the emulated DLL.
"""
from pathlib import Path
import hashlib
import json
import random
import struct
import sys

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / 'tools'))
import pefile
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_ECX, UC_X86_REG_ESP, UC_X86_REG_EIP

DLL = Path(r'C:\Program Files (x86)\CLARICOM\Data\CiffMgr.dll')
BASE = 0x68100000
HEAP = 0x10000000
STACK = 0x20000000
STOP = 0x30000000
STUB = STOP + 0x1000
SEED = 0x26E20115


def utf16(text):
    return text.encode('utf-16-le', 'surrogatepass')


class NativeOracle:
    def __init__(self):
        self.pe = pefile.PE(str(DLL))
        self.uc = Uc(UC_ARCH_X86, UC_MODE_32)
        mapped = self.pe.get_memory_mapped_image()
        self.uc.mem_map(BASE, (len(mapped) + 0xfff) & ~0xfff)
        self.uc.mem_write(BASE, mapped)
        self.uc.mem_map(HEAP, 0x400000)
        self.uc.mem_map(STACK, 0x100000)
        self.uc.mem_map(STOP, 0x10000)
        self.bump = HEAP
        self.hooks = {
            0x681349DA: self.copy_key,
            0x681344E8: self.wcslen,
            0x681026D0: self.copy_bstr,
        }
        for i, (iat, function) in enumerate([
            (0x6814718C, self.sys_string_len),
            (0x68147190, self.sys_free_string),
            (0x68147198, self.sys_alloc_string_len),
        ]):
            target = STUB + i * 0x100
            self.write32(iat, target)
            self.hooks[target] = function
        self.uc.hook_add(UC_HOOK_CODE, self.on_code)

    def alloc(self, size):
        result = self.bump
        self.bump = (result + size + 15) & ~15
        if self.bump >= HEAP + 0x400000:
            raise ValueError('oracle heap exhausted')
        self.uc.mem_write(result, bytes(size))
        return result

    def read32(self, address):
        return struct.unpack('<I', self.uc.mem_read(address, 4))[0]

    def write32(self, address, value):
        self.uc.mem_write(address, struct.pack('<I', value & 0xffffffff))

    def wchar_bytes(self, pointer):
        if not pointer:
            return b''
        data = bytearray()
        while True:
            word = bytes(self.uc.mem_read(pointer, 2))
            if word == b'\0\0':
                return bytes(data)
            data.extend(word)
            pointer += 2

    def bstr(self, data):
        address = self.alloc(len(data) + 6)
        self.write32(address, len(data))
        self.uc.mem_write(address + 4, data + b'\0\0')
        return address + 4

    def args(self, count):
        esp = self.uc.reg_read(UC_X86_REG_ESP)
        return [self.read32(esp + 4 + i * 4) for i in range(count)]

    def ret(self, result=0, consumed=0):
        esp = self.uc.reg_read(UC_X86_REG_ESP)
        self.uc.reg_write(UC_X86_REG_EAX, result)
        self.uc.reg_write(UC_X86_REG_ESP, esp + 4 + consumed)
        self.uc.reg_write(UC_X86_REG_EIP, self.read32(esp))

    def on_code(self, uc, address, size, data):
        if address in self.hooks:
            self.hooks[address]()

    def sys_string_len(self):
        pointer, = self.args(1)
        self.ret(self.read32(pointer - 4) // 2 if pointer else 0, 4)

    def sys_free_string(self):
        self.ret(0, 4)

    def sys_alloc_string_len(self):
        source, length = self.args(2)
        data = bytes(self.uc.mem_read(source, length * 2)) if source else bytes(length * 2)
        self.ret(self.bstr(data), 8)

    def copy_key(self):
        dest, capacity, source, max_chars = self.args(4)
        data = self.wchar_bytes(source)[:max_chars * 2]
        if len(data) >= capacity * 2:
            raise ValueError('unexpected key-copy capacity')
        self.uc.mem_write(dest, data + b'\0\0')
        self.ret(0)  # CRT cdecl: caller removes arguments

    def wcslen(self):
        source, = self.args(1)
        self.ret(len(self.wchar_bytes(source)) // 2)

    def copy_bstr(self):
        dest, = self.args(1)
        source_object = self.uc.reg_read(UC_X86_REG_ECX)
        source = self.read32(source_object)
        length = self.read32(source - 4) if source else 0
        data = bytes(self.uc.mem_read(source, length)) if source else b''
        self.write32(dest, self.bstr(data))
        self.ret(0, 4)

    def call(self, address, args=(), this=0):
        stack_top = STACK + 0xff000
        data = struct.pack('<' + 'I' * (1 + len(args)), STOP, *args)
        self.uc.mem_write(stack_top, data)
        self.uc.reg_write(UC_X86_REG_ESP, stack_top)
        self.uc.reg_write(UC_X86_REG_ECX, this)
        self.uc.emu_start(address, STOP, timeout=30_000_000, count=5_000_000)
        if self.uc.reg_read(UC_X86_REG_EIP) != STOP:
            raise ValueError(f'native call did not complete: {address:08x}')
        return self.uc.reg_read(UC_X86_REG_EAX)

    def encrypt(self, text, key, seed=SEED, use_key_inputs=False):
        if not key or key.startswith('\0'):
            raise ValueError('empty key leaves original native object uninitialized')
        self.bump = HEAP
        cipher = self.alloc(0xB20)
        self.call(0x6810A989, this=cipher)
        input_bstr = self.bstr(utf16(text))
        key_pointer = self.bstr(utf16(key))
        result_object = self.alloc(4)
        hresult = self.call(0x68117D03, [cipher, input_bstr, key_pointer, seed, int(use_key_inputs), result_object])
        result_pointer = self.read32(result_object)
        result = bytes(self.uc.mem_read(result_pointer, self.read32(result_pointer - 4)))
        return {
            'output': result.decode('utf-16-le', 'surrogatepass'),
            'hresult': hresult,
            'effectiveKeyLength': self.read32(cipher + 0xAE0),
            'networkDimensions': [self.read32(cipher + offset) for offset in (8, 12, 16, 20)],
        }


def main():
    oracle = NativeOracle()
    vectors = [
        ('00000001', '000101', 'MWNDu5BBD5YND7UFBSMsIQv2'),
        ('21:22', 'TagData', '6o7UEV2GF5uKVqU'),
        ('MWNDu5BBD5YND7UFBSMsIQv26nHTELGTVEh47lGLjGRv9KoKQVOMgH7sB', 'TpyRcNeyeK',
         'PyOA!LMe37jF5gGD_OEeQJPAIR3Et2HVCOk4RKDB93Hl9AjBVgIOzL2x64vRUW8LPDPLLM!BMqKMGOFnVSVSNLLLnTAS2NyCJtJUD3VGHDbN6K76iHU!QGk8UrNGi8Uz9Tc9QVCIr2TyL6eAUTMUCVHm8EcI0yABuRMv7N4LVz1'),
    ]
    results = []
    for text, key, expected in vectors:
        result = oracle.encrypt(text, key)
        assert result['output'] == expected, (text, result)
        results.append({'text': text, 'key': key, **result, 'matchesKnownVector': True})
    key_cases = ['000101', '999999', 'TpyRcNeyeK', 'abcdefghij', '12345678901234', '12345678901234567890', 'a\0bc']
    for key in key_cases:
        results.append({'text': 'audit 123', 'key': key, **oracle.encrypt('audit 123', key)})
    report = {
        'sourceDll': str(DLL),
        'sha256': hashlib.sha256(DLL.read_bytes()).hexdigest(),
        'architecture': 'x86 machine code executed in Unicorn',
        'nativeRoutines': ['6810A989', '68117D03', '68117DE2', '68117E37', '681180D7', '68117F62', '68117CE1', '68117B8E'],
        'emulatedHelpers': ['OLE BSTR allocation/length/free', 'CRT wchar copy/length', 'BSTR copy 681026D0'],
        'results': results,
    }
    (HERE / 'oracle-results.json').write_text(json.dumps(report, ensure_ascii=True, indent=2), encoding='utf-8')
    print(json.dumps({'vectors': len(vectors), 'allMatched': True, 'resultsFile': str(HERE / 'oracle-results.json')}))


if __name__ == '__main__':
    main()

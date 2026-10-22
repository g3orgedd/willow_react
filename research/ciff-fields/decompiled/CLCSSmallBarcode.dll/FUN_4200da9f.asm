4200da9f XOR EAX,EAX
4200daa1 CMP dword ptr [ECX + 0xc],EAX
4200daa4 JZ 0x4200daac
4200daa6 CMP dword ptr [ECX + 0x10],EAX
4200daa9 JZ 0x4200daac
4200daab INC EAX
4200daac RET

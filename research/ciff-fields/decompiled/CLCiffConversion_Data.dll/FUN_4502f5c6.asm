4502f5c6 PUSH EBP
4502f5c7 MOV ECX,dword ptr [ESP + 0x8]
4502f5cb MOV EBP,dword ptr [ECX]
4502f5cd PUSH dword ptr [ECX + 0x1c]
4502f5d0 PUSH dword ptr [ECX + 0x18]
4502f5d3 PUSH dword ptr [ECX + 0x28]
4502f5d6 CALL 0x4502f4f0
4502f5db ADD ESP,0xc
4502f5de POP EBP
4502f5df RET 0x4

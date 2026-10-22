4200ae4e PUSH EBP
4200ae4f MOV EBP,ESP
4200ae51 MOV EAX,dword ptr [EBP + 0xc]
4200ae54 PUSH ESI
4200ae55 MOV ESI,ECX
4200ae57 MOV dword ptr [ESI + 0x40],EAX
4200ae5a MOV EAX,dword ptr [EBP + 0x10]
4200ae5d MOV dword ptr [ESI + 0x44],EAX
4200ae60 MOV EAX,dword ptr [EBP + 0x14]
4200ae63 MOV dword ptr [ESI + 0x48],EAX
4200ae66 MOV EAX,dword ptr [EBP + 0x18]
4200ae69 MOV dword ptr [ESI + 0x4c],EAX
4200ae6c MOV EAX,dword ptr [EBP + 0x1c]
4200ae6f MOV dword ptr [ESI + 0x50],EAX
4200ae72 MOV EAX,dword ptr [EBP + 0x20]
4200ae75 MOV dword ptr [ESI + 0x54],EAX
4200ae78 MOV EAX,dword ptr [EBP + 0x24]
4200ae7b MOV dword ptr [ESI + 0x58],EAX
4200ae7e XOR EAX,EAX
4200ae80 MOV word ptr [ESI],AX
4200ae83 CMP dword ptr [EBP + 0x8],EAX
4200ae86 JZ 0x4200ae9e
4200ae88 PUSH 0x1f
4200ae8a PUSH dword ptr [EBP + 0x8]
4200ae8d PUSH 0x20
4200ae8f PUSH ESI
4200ae90 CALL 0x4206a09b
4200ae95 ADD ESP,0x10
4200ae98 XOR EAX,EAX
4200ae9a MOV word ptr [ESI + 0x3e],AX
4200ae9e MOV ECX,dword ptr [ESI + 0x54]
4200aea1 IMUL ECX,dword ptr [ESI + 0x48]
4200aea5 MOV EAX,dword ptr [ESI + 0x58]
4200aea8 CDQ
4200aea9 SUB EAX,EDX
4200aeab SAR EAX,0x1
4200aead ADD EAX,ECX
4200aeaf CDQ
4200aeb0 IDIV dword ptr [ESI + 0x58]
4200aeb3 MOV dword ptr [ESI + 0x48],EAX
4200aeb6 MOV EAX,ESI
4200aeb8 POP ESI
4200aeb9 POP EBP
4200aeba RET 0x20

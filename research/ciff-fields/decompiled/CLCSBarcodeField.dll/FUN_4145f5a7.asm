4145f5a7 PUSH EBP
4145f5a8 MOV EBP,ESP
4145f5aa MOV AL,byte ptr [EBP + 0x8]
4145f5ad MOV byte ptr [ECX + 0x8],AL
4145f5b0 MOV AL,byte ptr [EBP + 0xc]
4145f5b3 MOV byte ptr [ECX + 0x9],AL
4145f5b6 MOV EAX,dword ptr [EBP + 0x10]
4145f5b9 MOV dword ptr [ECX + 0xc],EAX
4145f5bc MOV EAX,dword ptr [EBP + 0x14]
4145f5bf MOV dword ptr [ECX + 0x10],EAX
4145f5c2 MOV EAX,dword ptr [EBP + 0x18]
4145f5c5 MOV dword ptr [ECX + 0x14],EAX
4145f5c8 MOV EAX,dword ptr [EBP + 0x1c]
4145f5cb MOV dword ptr [ECX + 0x18],EAX
4145f5ce MOV EAX,dword ptr [EBP + 0x20]
4145f5d1 MOV dword ptr [ECX + 0x1c],EAX
4145f5d4 XOR EAX,EAX
4145f5d6 MOV dword ptr [ECX + 0xacc],EAX
4145f5dc MOV dword ptr [ECX + 0x1214],EAX
4145f5e2 MOV dword ptr [ECX + 0x1218],0x1
4145f5ec MOV dword ptr [ECX + 0x30],EAX
4145f5ef POP EBP
4145f5f0 RET 0x1c

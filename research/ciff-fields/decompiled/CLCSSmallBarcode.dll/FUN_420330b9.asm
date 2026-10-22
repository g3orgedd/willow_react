420330b9 PUSH EBP
420330ba MOV EBP,ESP
420330bc MOV AL,byte ptr [EBP + 0x8]
420330bf MOV byte ptr [ECX + 0x8],AL
420330c2 MOV AL,byte ptr [EBP + 0xc]
420330c5 MOV byte ptr [ECX + 0x9],AL
420330c8 MOV EAX,dword ptr [EBP + 0x10]
420330cb MOV dword ptr [ECX + 0xc],EAX
420330ce MOV EAX,dword ptr [EBP + 0x14]
420330d1 MOV dword ptr [ECX + 0x10],EAX
420330d4 MOV EAX,dword ptr [EBP + 0x18]
420330d7 MOV dword ptr [ECX + 0x14],EAX
420330da MOV EAX,dword ptr [EBP + 0x1c]
420330dd MOV dword ptr [ECX + 0x18],EAX
420330e0 MOV EAX,dword ptr [EBP + 0x20]
420330e3 MOV dword ptr [ECX + 0x1c],EAX
420330e6 XOR EAX,EAX
420330e8 MOV dword ptr [ECX + 0xacc],EAX
420330ee MOV dword ptr [ECX + 0x1214],EAX
420330f4 MOV dword ptr [ECX + 0x1218],0x1
420330fe MOV dword ptr [ECX + 0x30],EAX
42033101 POP EBP
42033102 RET 0x1c

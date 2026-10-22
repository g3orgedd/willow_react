68108dc7 PUSH EBP
68108dc8 MOV EBP,ESP
68108dca PUSH dword ptr [EBP + 0x20]
68108dcd MOV EAX,dword ptr [EBP + 0x8]
68108dd0 PUSH 0x0
68108dd2 PUSH dword ptr [EBP + 0x1c]
68108dd5 PUSH dword ptr [EBP + 0x18]
68108dd8 MOV ECX,dword ptr [EAX]
68108dda PUSH dword ptr [EBP + 0x14]
68108ddd PUSH dword ptr [EBP + 0x10]
68108de0 PUSH dword ptr [EBP + 0xc]
68108de3 PUSH EAX
68108de4 CALL dword ptr [ECX + 0xc8]
68108dea POP EBP
68108deb RET 0x1c

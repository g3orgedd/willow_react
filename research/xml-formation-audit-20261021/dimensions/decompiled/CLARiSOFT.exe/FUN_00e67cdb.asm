00e67cdb PUSH EBP
00e67cdc MOV EBP,ESP
00e67cde PUSH ESI
00e67cdf PUSH dword ptr [EBP + 0x8]
00e67ce2 MOV ESI,ECX
00e67ce4 MOV EAX,dword ptr [ESI + 0x18]
00e67ce7 PUSH EAX
00e67ce8 MOV EDX,dword ptr [EAX]
00e67cea CALL dword ptr [EDX + 0x40]
00e67ced MOV EAX,dword ptr [ESI + 0x18]
00e67cf0 PUSH dword ptr [EBP + 0xc]
00e67cf3 PUSH EAX
00e67cf4 MOV ECX,dword ptr [EAX]
00e67cf6 CALL dword ptr [ECX + 0x48]
00e67cf9 POP ESI
00e67cfa POP EBP
00e67cfb RET 0x8

00e03fe0 TEST EAX,EAX
00e03fe2 JZ 0x00e03fff
00e03fe4 XOR ECX,ECX
00e03fe6 MOV dword ptr [EAX],0x1
00e03fec MOV word ptr [EAX + ESI*0x2 + 0xc],CX
00e03ff1 LEA ECX,[EAX + 0xc]
00e03ff4 MOV dword ptr [EAX + 0x4],ESI
00e03ff7 MOV dword ptr [EAX + 0x8],ESI
00e03ffa MOV dword ptr [EDI],ECX
00e03ffc XOR EAX,EAX
00e03ffe INC EAX
00e03fff CALL 0x00ec9e28
00e04004 RET 0x4

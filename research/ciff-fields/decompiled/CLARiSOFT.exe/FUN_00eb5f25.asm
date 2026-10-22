00eb5f25 PUSH 0x14
00eb5f27 MOV EAX,0xef8dd4
00eb5f2c CALL 0x00ec9e5a
00eb5f31 MOV EAX,dword ptr [EBP + 0x8]
00eb5f34 XOR ESI,ESI
00eb5f36 MOV dword ptr [EBP + -0x4],ESI
00eb5f39 TEST EAX,EAX
00eb5f3b JZ 0x00eb5f8e
00eb5f3d LEA ECX,[EBP + -0x20]
00eb5f40 CALL 0x00e03b51
00eb5f45 MOV EAX,dword ptr [EBP + 0x8]
00eb5f48 LEA EDX,[EBP + -0x20]
00eb5f4b PUSH EDX
00eb5f4c PUSH EAX
00eb5f4d MOV byte ptr [EBP + -0x4],0x1
00eb5f51 MOV ECX,dword ptr [EAX]
00eb5f53 CALL dword ptr [ECX + 0x470]
00eb5f59 TEST EAX,EAX
00eb5f5b JS 0x00eb5f81
00eb5f5d CMP word ptr [EBP + -0x20],0x9
00eb5f62 JNZ 0x00eb5f81
00eb5f64 CMP dword ptr [EBP + -0x18],ESI
00eb5f67 JZ 0x00eb5f81
00eb5f69 PUSH dword ptr [EBP + -0x18]
00eb5f6c LEA ECX,[EBP + -0x10]
00eb5f6f CALL 0x00e28196
00eb5f74 MOV ESI,dword ptr [EBP + -0x10]
00eb5f77 TEST ESI,ESI
00eb5f79 JZ 0x00eb5f81
00eb5f7b MOV EAX,dword ptr [ESI]
00eb5f7d PUSH ESI
00eb5f7e CALL dword ptr [EAX + 0x8]
00eb5f81 LEA EAX,[EBP + -0x20]
00eb5f84 PUSH EAX
00eb5f85 CALL dword ptr [0x00efc408]
00eb5f8b MOV EAX,dword ptr [EBP + 0x8]
00eb5f8e OR dword ptr [EBP + -0x4],0xffffffff
00eb5f92 TEST EAX,EAX
00eb5f94 JZ 0x00eb5f9c
00eb5f96 MOV ECX,dword ptr [EAX]
00eb5f98 PUSH EAX
00eb5f99 CALL dword ptr [ECX + 0x8]
00eb5f9c MOV EAX,ESI
00eb5f9e CALL 0x00ec9e28
00eb5fa3 RET 0x4

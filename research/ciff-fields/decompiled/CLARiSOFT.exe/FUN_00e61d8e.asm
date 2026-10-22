00e61d8e PUSH 0x1c
00e61d90 MOV EAX,0xef0e71
00e61d95 CALL 0x00ec9e5a
00e61d9a MOV EDI,ECX
00e61d9c MOV EAX,dword ptr [EDI + 0x4]
00e61d9f LEA EDX,[EBP + -0x20]
00e61da2 MOV ESI,dword ptr [EBP + 0x8]
00e61da5 XOR EBX,EBX
00e61da7 PUSH EDX
00e61da8 PUSH EAX
00e61da9 MOV ECX,dword ptr [EAX]
00e61dab MOV dword ptr [ESI],EBX
00e61dad MOV dword ptr [ESI + 0x4],EBX
00e61db0 MOV dword ptr [ESI + 0x8],EBX
00e61db3 MOV dword ptr [ESI + 0xc],EBX
00e61db6 CALL dword ptr [ECX + 0x2c]
00e61db9 MOV EAX,dword ptr [EDI + 0x4]
00e61dbc LEA EDX,[EBP + -0x24]
00e61dbf PUSH EDX
00e61dc0 PUSH EAX
00e61dc1 MOV ECX,dword ptr [EAX]
00e61dc3 CALL dword ptr [ECX + 0x34]
00e61dc6 MOV EAX,dword ptr [EDI + 0x4]
00e61dc9 LEA EDX,[EBP + -0x28]
00e61dcc PUSH EDX
00e61dcd PUSH EAX
00e61dce MOV ECX,dword ptr [EAX]
00e61dd0 CALL dword ptr [ECX + 0x3c]
00e61dd3 MOV EAX,dword ptr [EDI + 0x4]
00e61dd6 LEA EDX,[EBP + -0x14]
00e61dd9 PUSH EDX
00e61dda PUSH EAX
00e61ddb MOV ECX,dword ptr [EAX]
00e61ddd CALL dword ptr [ECX + 0x78]
00e61de0 MOV EAX,dword ptr [EDI + 0x4]
00e61de3 LEA EDX,[EBP + 0x8]
00e61de6 PUSH EDX
00e61de7 PUSH EAX
00e61de8 MOV ECX,dword ptr [EAX]
00e61dea CALL dword ptr [ECX + 0x80]
00e61df0 MOV EAX,dword ptr [EDI + 0x4]
00e61df3 LEA EDX,[EBP + -0x18]
00e61df6 PUSH EDX
00e61df7 PUSH EAX
00e61df8 MOV ECX,dword ptr [EAX]
00e61dfa CALL dword ptr [ECX + 0x64]
00e61dfd CMP dword ptr [EBP + -0x18],0x1
00e61e01 JNZ 0x00e61e4c
00e61e03 PUSH dword ptr [EDI + 0x4]
00e61e06 LEA ECX,[EBP + -0x10]
00e61e09 CALL 0x00e09774
00e61e0e MOV EAX,dword ptr [EBP + -0x10]
00e61e11 MOV dword ptr [EBP + -0x4],EBX
00e61e14 TEST EAX,EAX
00e61e16 JZ 0x00e61e3e
00e61e18 MOV ECX,dword ptr [EAX]
00e61e1a LEA EDX,[EBP + -0x1c]
00e61e1d PUSH EDX
00e61e1e PUSH EAX
00e61e1f CALL dword ptr [ECX + 0xa8]
00e61e25 TEST EAX,EAX
00e61e27 JS 0x00e61e3b
00e61e29 MOV EAX,dword ptr [EBP + -0x1c]
00e61e2c ADD EAX,-0xa
00e61e2f CMP EAX,0x4
00e61e32 JA 0x00e61e3b
00e61e34 ADD dword ptr [EBP + 0x8],0x3e8
00e61e3b MOV EAX,dword ptr [EBP + -0x10]
00e61e3e OR dword ptr [EBP + -0x4],0xffffffff
00e61e42 TEST EAX,EAX
00e61e44 JZ 0x00e61e4c
00e61e46 MOV ECX,dword ptr [EAX]
00e61e48 PUSH EAX
00e61e49 CALL dword ptr [ECX + 0x8]
00e61e4c MOV EAX,dword ptr [EBP + -0x28]
00e61e4f MOV EDX,dword ptr [EBP + -0x20]
00e61e52 MOV EDI,dword ptr [EBP + -0x24]
00e61e55 MOV dword ptr [ESI],EDX
00e61e57 MOV dword ptr [ESI + 0x4],EDI
00e61e5a SUB EAX,EBX
00e61e5c JZ 0x00e61e8c
00e61e5e SUB EAX,0x5a
00e61e61 JZ 0x00e61e7a
00e61e63 SUB EAX,0x5a
00e61e66 JZ 0x00e61e8c
00e61e68 SUB EAX,0x5a
00e61e6b JZ 0x00e61e7a
00e61e6d MOV EAX,dword ptr [EBP + -0x14]
00e61e70 ADD EAX,EDX
00e61e72 MOV dword ptr [ESI + 0x8],EAX
00e61e75 MOV EAX,dword ptr [EBP + 0x8]
00e61e78 JMP 0x00e61e85
00e61e7a MOV EAX,dword ptr [EBP + 0x8]
00e61e7d ADD EAX,EDX
00e61e7f MOV dword ptr [ESI + 0x8],EAX
00e61e82 MOV EAX,dword ptr [EBP + -0x14]
00e61e85 ADD EAX,EDI
00e61e87 MOV dword ptr [ESI + 0xc],EAX
00e61e8a JMP 0x00e61e9c
00e61e8c MOV ECX,dword ptr [EBP + -0x14]
00e61e8f ADD ECX,EDX
00e61e91 MOV dword ptr [ESI + 0x8],ECX
00e61e94 MOV ECX,dword ptr [EBP + 0x8]
00e61e97 ADD ECX,EDI
00e61e99 MOV dword ptr [ESI + 0xc],ECX
00e61e9c MOV EAX,ESI
00e61e9e CALL 0x00ec9e28
00e61ea3 RET 0x8

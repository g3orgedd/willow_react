4542ab84 PUSH EBP
4542ab85 MOV EBP,ESP
4542ab87 SUB ESP,0x38
4542ab8a PUSH EBX
4542ab8b CMP dword ptr [EBP + 0x8],0x123
4542ab92 JNZ 0x4542aba6
4542ab94 MOV EAX,0x4542ac2d
4542ab99 MOV ECX,dword ptr [EBP + 0xc]
4542ab9c MOV dword ptr [ECX],EAX
4542ab9e XOR EAX,EAX
4542aba0 INC EAX
4542aba1 JMP 0x4542ac56
4542aba6 AND dword ptr [EBP + -0x38],0x0
4542abaa MOV dword ptr [EBP + -0x34],0x4542aa7e
4542abb1 MOV EAX,[0x4545d9f0]
4542abb6 LEA ECX,[EBP + -0x38]
4542abb9 XOR EAX,ECX
4542abbb MOV dword ptr [EBP + -0x30],EAX
4542abbe MOV EAX,dword ptr [EBP + 0x18]
4542abc1 MOV dword ptr [EBP + -0x2c],EAX
4542abc4 MOV EAX,dword ptr [EBP + 0xc]
4542abc7 MOV dword ptr [EBP + -0x28],EAX
4542abca MOV EAX,dword ptr [EBP + 0x1c]
4542abcd MOV dword ptr [EBP + -0x24],EAX
4542abd0 MOV EAX,dword ptr [EBP + 0x20]
4542abd3 MOV dword ptr [EBP + -0x20],EAX
4542abd6 AND dword ptr [EBP + -0x1c],0x0
4542abda AND dword ptr [EBP + -0x18],0x0
4542abde AND dword ptr [EBP + -0x14],0x0
4542abe2 MOV dword ptr [EBP + -0x1c],ESP
4542abe5 MOV dword ptr [EBP + -0x18],EBP
4542abe8 MOV EAX,FS:[0x0]
4542abee MOV dword ptr [EBP + -0x38],EAX
4542abf1 LEA EAX,[EBP + -0x38]
4542abf4 MOV FS:[0x0],EAX
4542abfa MOV dword ptr [EBP + -0x4],0x1
4542ac01 MOV EAX,dword ptr [EBP + 0x8]
4542ac04 MOV dword ptr [EBP + -0x10],EAX
4542ac07 MOV EAX,dword ptr [EBP + 0x10]
4542ac0a MOV dword ptr [EBP + -0xc],EAX
4542ac0d CALL 0x454300d5
4542ac12 MOV EAX,dword ptr [EAX + 0x80]
4542ac18 MOV dword ptr [EBP + -0x8],EAX
4542ac1b LEA EAX,[EBP + -0x10]
4542ac1e PUSH EAX
4542ac1f MOV EAX,dword ptr [EBP + 0x8]
4542ac22 PUSH dword ptr [EAX]
4542ac24 CALL dword ptr [EBP + -0x8]
4542ac27 POP ECX
4542ac28 POP ECX
4542ac29 AND dword ptr [EBP + -0x4],0x0
4542ac2d CMP dword ptr [EBP + -0x14],0x0
4542ac31 JZ 0x4542ac4a
4542ac33 MOV EBX,dword ptr FS:[0x0]
4542ac3a MOV EAX,dword ptr [EBX]
4542ac3c MOV EBX,dword ptr [EBP + -0x38]
4542ac3f MOV dword ptr [EBX],EAX
4542ac41 MOV dword ptr FS:[0x0],EBX
4542ac48 JMP 0x4542ac53
4542ac4a MOV EAX,dword ptr [EBP + -0x38]
4542ac4d MOV FS:[0x0],EAX
4542ac53 MOV EAX,dword ptr [EBP + -0x4]
4542ac56 POP EBX
4542ac57 MOV ESP,EBP
4542ac59 POP EBP
4542ac5a RET

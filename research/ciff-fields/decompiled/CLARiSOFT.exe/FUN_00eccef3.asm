00eccef3 PUSH EBP
00eccef4 MOV EBP,ESP
00eccef6 SUB ESP,0x10
00eccef9 LEA ECX,[EBP + -0x10]
00eccefc PUSH EBX
00eccefd PUSH ESI
00eccefe PUSH dword ptr [EBP + 0x10]
00eccf01 CALL 0x00eca4fa
00eccf06 MOV EBX,dword ptr [EBP + 0x8]
00eccf09 TEST EBX,EBX
00eccf0b JZ 0x00eccf14
00eccf0d MOV ESI,dword ptr [EBP + 0xc]
00eccf10 TEST ESI,ESI
00eccf12 JNZ 0x00eccf2e
00eccf14 CALL 0x00ed1b43
00eccf19 MOV dword ptr [EAX],0x16
00eccf1f CALL 0x00ed2f39
00eccf24 MOV EDX,0x7fffffff
00eccf29 JMP 0x00eccfb9
00eccf2e MOV EAX,dword ptr [EBP + -0x10]
00eccf31 PUSH EDI
00eccf32 CMP dword ptr [EAX + 0xa8],0x0
00eccf39 JNZ 0x00eccf7d
00eccf3b PUSH 0x41
00eccf3d POP ECX
00eccf3e PUSH 0x5a
00eccf40 SUB EBX,ESI
00eccf42 POP EDX
00eccf43 MOVZX EAX,word ptr [EBX + ESI*0x1]
00eccf47 CMP AX,CX
00eccf4a JC 0x00eccf59
00eccf4c CMP AX,DX
00eccf4f JA 0x00eccf59
00eccf51 ADD EAX,0x20
00eccf54 MOVZX EDI,AX
00eccf57 JMP 0x00eccf5b
00eccf59 MOV EDI,EAX
00eccf5b MOVZX EAX,word ptr [ESI]
00eccf5e CMP AX,CX
00eccf61 JC 0x00eccf6e
00eccf63 CMP AX,DX
00eccf66 JA 0x00eccf6e
00eccf68 ADD EAX,0x20
00eccf6b MOVZX EAX,AX
00eccf6e ADD ESI,0x2
00eccf71 TEST DI,DI
00eccf74 JZ 0x00eccfb0
00eccf76 CMP DI,AX
00eccf79 JZ 0x00eccf43
00eccf7b JMP 0x00eccfb0
00eccf7d MOVZX EAX,word ptr [EBX]
00eccf80 LEA ECX,[EBP + -0x10]
00eccf83 PUSH ECX
00eccf84 PUSH EAX
00eccf85 CALL 0x00ecfdbf
00eccf8a LEA ECX,[EBP + -0x10]
00eccf8d MOVZX EDI,AX
00eccf90 MOVZX EAX,word ptr [ESI]
00eccf93 LEA EBX,[EBX + 0x2]
00eccf96 PUSH ECX
00eccf97 PUSH EAX
00eccf98 CALL 0x00ecfdbf
00eccf9d ADD ESP,0x10
00eccfa0 MOVZX EAX,AX
00eccfa3 LEA ESI,[ESI + 0x2]
00eccfa6 TEST DI,DI
00eccfa9 JZ 0x00eccfb0
00eccfab CMP DI,AX
00eccfae JZ 0x00eccf7d
00eccfb0 MOVZX EDX,DI
00eccfb3 MOVZX EAX,AX
00eccfb6 SUB EDX,EAX
00eccfb8 POP EDI
00eccfb9 CMP byte ptr [EBP + -0x4],0x0
00eccfbd POP ESI
00eccfbe POP EBX
00eccfbf JZ 0x00eccfc8
00eccfc1 MOV ECX,dword ptr [EBP + -0x8]
00eccfc4 AND dword ptr [ECX + 0x70],0xfffffffd
00eccfc8 MOV EAX,EDX
00eccfca MOV ESP,EBP
00eccfcc POP EBP
00eccfcd RET

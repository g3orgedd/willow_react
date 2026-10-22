00eccbcd PUSH EBX
00eccbce MOV EBX,ESP
00eccbd0 PUSH ECX
00eccbd1 PUSH ECX
00eccbd2 AND ESP,0xfffffff0
00eccbd5 ADD ESP,0x4
00eccbd8 PUSH EBP
00eccbd9 MOV EBP,dword ptr [EBX + 0x4]
00eccbdc MOV dword ptr [ESP + 0x4],EBP
00eccbe0 MOV EBP,ESP
00eccbe2 SUB ESP,0x28
00eccbe5 PUSH ESI
00eccbe6 PUSH EDI
00eccbe7 MOV EDI,dword ptr [EBX + 0xc]
00eccbea XOR EAX,EAX
00eccbec MOVZX ECX,word ptr [EDI]
00eccbef MOV dword ptr [EBP + -0x8],ECX
00eccbf2 CMP AX,CX
00eccbf5 JNZ 0x00eccbff
00eccbf7 MOV EAX,dword ptr [EBX + 0x8]
00eccbfa JMP 0x00ecce57
00eccbff MOV EAX,[0x00f44fb8]
00eccc04 CMP EAX,0x1
00eccc07 JLE 0x00eccd02
00eccc0d MOV EAX,EDI
00eccc0f AND EAX,0xfff
00eccc14 PUSH 0x2
00eccc16 POP ESI
00eccc17 CMP EAX,0xff0
00eccc1c JA 0x00eccc24
00eccc1e MOVDQU XMM0,xmmword ptr [EDI]
00eccc22 JMP 0x00eccc4d
00eccc24 PUSH 0x8
00eccc26 PXOR XMM0,XMM0
00eccc2a MOVZX ECX,CX
00eccc2d POP EDX
00eccc2e MOVZX EAX,CX
00eccc31 PSRLDQ XMM0,0x2
00eccc36 PINSRW XMM0,EAX,0x7
00eccc3b XOR EAX,EAX
00eccc3d CMP AX,CX
00eccc40 JZ 0x00eccc47
00eccc42 ADD EDI,ESI
00eccc44 MOVZX ECX,word ptr [EDI]
00eccc47 DEC EDX
00eccc48 JNZ 0x00eccc2e
00eccc4a MOV ECX,dword ptr [EBP + -0x8]
00eccc4d MOV EDX,dword ptr [EBX + 0x8]
00eccc50 MOV EAX,EDX
00eccc52 AND EAX,0xfff
00eccc57 CMP EAX,0xff0
00eccc5c JA 0x00ecccc2
00eccc5e MOVDQU XMM1,xmmword ptr [EDX]
00eccc62 PCMPISTRI XMM0,XMM1,0xd
00eccc68 JBE 0x00eccc72
00eccc6a ADD EDX,0x10
00eccc6d MOV ECX,dword ptr [EBP + -0x8]
00eccc70 JMP 0x00eccc50
00eccc72 JNC 0x00ecce55
00eccc78 PCMPISTRI XMM0,XMM1,0xd
00eccc7e LEA EDX,[EDX + ECX*0x2]
00eccc81 MOV ECX,dword ptr [EBX + 0xc]
00eccc84 MOV EDI,EDX
00eccc86 MOV EAX,EDI
00eccc88 MOV dword ptr [EBP + -0x4],ECX
00eccc8b AND EAX,0xfff
00eccc90 CMP EAX,0xff0
00eccc95 JA 0x00ecccdc
00eccc97 MOV EAX,ECX
00eccc99 AND EAX,0xfff
00eccc9e CMP EAX,0xff0
00eccca3 JA 0x00ecccdc
00eccca5 MOVDQU XMM1,xmmword ptr [EDI]
00eccca9 MOVDQU XMM2,xmmword ptr [ECX]
00ecccad PCMPISTRI XMM2,XMM1,0xd
00ecccb3 JNO 0x00ecccf4
00ecccb5 JS 0x00ecccfb
00ecccb7 MOV ECX,dword ptr [EBP + -0x4]
00ecccba ADD EDI,0x10
00ecccbd ADD ECX,0x10
00ecccc0 JMP 0x00eccc86
00ecccc2 MOVZX EAX,word ptr [EDX]
00ecccc5 XOR EDI,EDI
00ecccc7 CMP DI,AX
00ecccca JZ 0x00ecce55
00ecccd0 CMP AX,CX
00ecccd3 JZ 0x00eccc81
00ecccd5 ADD EDX,ESI
00ecccd7 JMP 0x00eccc50
00ecccdc MOVZX EAX,word ptr [ECX]
00ecccdf AND dword ptr [EBP + -0x4],0x0
00eccce3 CMP word ptr [EBP + -0x4],AX
00eccce7 JZ 0x00ecccfb
00eccce9 CMP word ptr [EDI],AX
00ecccec JNZ 0x00ecccf4
00ecccee ADD EDI,ESI
00ecccf0 ADD ECX,ESI
00ecccf2 JMP 0x00eccc86
00ecccf4 ADD EDX,ESI
00ecccf6 JMP 0x00eccc6d
00ecccfb MOV EAX,EDX
00ecccfd JMP 0x00ecce57
00eccd02 JNZ 0x00eccdf0
00eccd08 MOVZX EAX,CX
00eccd0b PXOR XMM3,XMM3
00eccd0f MOV ECX,dword ptr [EBX + 0x8]
00eccd12 PUSH 0x2
00eccd14 POP ESI
00eccd15 MOVD XMM0,EAX
00eccd19 PSHUFLW XMM0,XMM0,0x0
00eccd1e PSHUFD XMM4,XMM0,0x0
00eccd23 MOV EAX,ECX
00eccd25 AND EAX,0xfff
00eccd2a CMP EAX,0xff0
00eccd2f JA 0x00eccd5d
00eccd31 MOVDQU XMM1,xmmword ptr [ECX]
00eccd35 MOVDQA XMM0,XMM3
00eccd39 PCMPEQW XMM0,XMM1
00eccd3d PCMPEQW XMM1,XMM4
00eccd41 POR XMM0,XMM1
00eccd45 PMOVMSKB EAX,XMM0
00eccd49 TEST EAX,EAX
00eccd4b JNZ 0x00eccd52
00eccd4d ADD ECX,0x10
00eccd50 JMP 0x00eccd23
00eccd52 BSF EAX,EAX
00eccd55 MOV dword ptr [EBP + -0x8],EAX
00eccd58 SHR EAX,0x1
00eccd5a LEA ECX,[ECX + EAX*0x2]
00eccd5d MOVZX EAX,word ptr [ECX]
00eccd60 XOR EDX,EDX
00eccd62 CMP DX,AX
00eccd65 JZ 0x00ecce55
00eccd6b MOVZX EDX,word ptr [EDI]
00eccd6e CMP DX,AX
00eccd71 JNZ 0x00eccde5
00eccd73 MOV EDX,ECX
00eccd75 MOV EAX,EDI
00eccd77 AND EAX,0xfff
00eccd7c CMP EAX,0xff0
00eccd81 JA 0x00eccdca
00eccd83 MOV EAX,EDX
00eccd85 AND EAX,0xfff
00eccd8a CMP EAX,0xff0
00eccd8f JA 0x00eccdca
00eccd91 MOVDQU XMM2,xmmword ptr [EDI]
00eccd95 MOVDQU XMM1,xmmword ptr [EDX]
00eccd99 MOVDQA XMM0,XMM3
00eccd9d PCMPEQW XMM1,XMM2
00eccda1 PCMPEQW XMM0,XMM2
00eccda5 PCMPEQW XMM1,XMM3
00eccda9 POR XMM1,XMM0
00eccdad PMOVMSKB EAX,XMM1
00eccdb1 TEST EAX,EAX
00eccdb3 JNZ 0x00eccdbd
00eccdb5 ADD EDX,0x10
00eccdb8 ADD EDI,0x10
00eccdbb JMP 0x00eccd75
00eccdbd BSF EAX,EAX
00eccdc0 MOV dword ptr [EBP + -0x8],EAX
00eccdc3 AND EAX,0xfffffffe
00eccdc6 ADD EDX,EAX
00eccdc8 ADD EDI,EAX
00eccdca MOVZX EAX,word ptr [EDI]
00eccdcd AND dword ptr [EBP + -0x8],0x0
00eccdd1 CMP word ptr [EBP + -0x8],AX
00eccdd5 JZ 0x00eccdec
00eccdd7 CMP word ptr [EDX],AX
00eccdda JNZ 0x00eccde2
00eccddc ADD EDX,ESI
00eccdde ADD EDI,ESI
00eccde0 JMP 0x00eccd75
00eccde2 MOV EDI,dword ptr [EBX + 0xc]
00eccde5 ADD ECX,ESI
00eccde7 JMP 0x00eccd23
00eccdec MOV EAX,ECX
00eccdee JMP 0x00ecce57
00eccdf0 MOV EDX,dword ptr [EBX + 0x8]
00eccdf3 MOVZX EAX,word ptr [EDX]
00eccdf6 TEST AX,AX
00eccdf9 JZ 0x00ecce55
00eccdfb AND dword ptr [EBP + -0x8],0x0
00eccdff MOV ECX,EAX
00ecce01 MOV EAX,EDX
00ecce03 SUB EAX,EDI
00ecce05 MOV dword ptr [EBP + -0x4],EAX
00ecce08 PUSH 0x2
00ecce0a POP ESI
00ecce0b TEST CX,CX
00ecce0e JZ 0x00ecce37
00ecce10 MOVZX ECX,word ptr [EDI]
00ecce13 TEST CX,CX
00ecce16 JZ 0x00ecccfb
00ecce1c MOVZX ECX,word ptr [EAX + EDI*0x1]
00ecce20 MOVZX EAX,word ptr [EDI]
00ecce23 SUB ECX,EAX
00ecce25 MOV EAX,dword ptr [EBP + -0x4]
00ecce28 MOV ECX,dword ptr [EBP + -0x8]
00ecce2b JNZ 0x00ecce3a
00ecce2d ADD EDI,ESI
00ecce2f CMP word ptr [EAX + EDI*0x1],CX
00ecce33 JNZ 0x00ecce10
00ecce35 JMP 0x00ecce3a
00ecce37 MOV ECX,dword ptr [EBP + -0x8]
00ecce3a CMP word ptr [EDI],CX
00ecce3d JZ 0x00ecccfb
00ecce43 MOV EDI,dword ptr [EBX + 0xc]
00ecce46 ADD EDX,ESI
00ecce48 ADD EAX,ESI
00ecce4a MOV dword ptr [EBP + -0x4],EAX
00ecce4d MOVZX ECX,word ptr [EDX]
00ecce50 TEST CX,CX
00ecce53 JNZ 0x00ecce10
00ecce55 XOR EAX,EAX
00ecce57 POP EDI
00ecce58 POP ESI
00ecce59 MOV ESP,EBP
00ecce5b POP EBP
00ecce5c MOV ESP,EBX
00ecce5e POP EBX
00ecce5f RET

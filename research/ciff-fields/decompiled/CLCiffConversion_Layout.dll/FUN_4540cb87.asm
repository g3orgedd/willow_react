4540cb87 PUSH EBP
4540cb88 MOV EBP,ESP
4540cb8a SUB ESP,0x1c
4540cb8d PUSH EBX
4540cb8e MOV EBX,dword ptr [EBP + 0xc]
4540cb91 PUSH ESI
4540cb92 MOV ESI,ECX
4540cb94 MOV dword ptr [EBP + -0x8],ESI
4540cb97 MOV EAX,dword ptr [EBX]
4540cb99 MOV dword ptr [EBX + 0x4],EAX
4540cb9c CMP byte ptr [ESI + 0x128],0x0
4540cba3 JNZ 0x4540cbc4
4540cba5 PUSH 0x1
4540cba7 MOV ECX,EBX
4540cba9 CALL 0x4540d5f2
4540cbae MOV ECX,dword ptr [EBX]
4540cbb0 MOV EDX,dword ptr [EBP + 0x8]
4540cbb3 MOV EAX,dword ptr [EDX]
4540cbb5 MOV dword ptr [ECX],EAX
4540cbb7 MOV ECX,dword ptr [EBX]
4540cbb9 MOV EAX,dword ptr [EDX + 0x4]
4540cbbc MOV dword ptr [ECX + 0x4],EAX
4540cbbf JMP 0x4540ccf4
4540cbc4 MOV EAX,dword ptr [EBP + 0x8]
4540cbc7 MOV ECX,dword ptr [ESI + 0x124]
4540cbcd PUSH EDI
4540cbce PUSH 0xc
4540cbd0 MOV EAX,dword ptr [EAX]
4540cbd2 XOR EDI,EDI
4540cbd4 SUB EAX,dword ptr [ESI + 0x100]
4540cbda INC EDI
4540cbdb SAR EAX,0x1
4540cbdd MOV dword ptr [EBP + -0x10],EAX
4540cbe0 MOV EAX,dword ptr [ECX + 0x4]
4540cbe3 SUB EAX,dword ptr [ECX]
4540cbe5 POP ECX
4540cbe6 CDQ
4540cbe7 IDIV ECX
4540cbe9 MOV EDX,dword ptr [EBP + 0x10]
4540cbec XOR ECX,ECX
4540cbee MOV dword ptr [EBP + -0x4],EDI
4540cbf1 MOV dword ptr [EBP + -0xc],EAX
4540cbf4 MOV dword ptr [EDX],ECX
4540cbf6 TEST EAX,EAX
4540cbf8 JZ 0x4540cc34
4540cbfa MOV EBX,dword ptr [EBP + 0x8]
4540cbfd MOV EDX,ECX
4540cbff MOV EAX,dword ptr [ESI + 0x124]
4540cc05 LEA EDI,[EBP + -0x1c]
4540cc08 MOV ESI,dword ptr [EAX]
4540cc0a ADD ESI,EDX
4540cc0c MOVSD ES:EDI,ESI
4540cc0d MOVSD ES:EDI,ESI
4540cc0e MOVSD ES:EDI,ESI
4540cc0f MOV EAX,dword ptr [EBP + -0x1c]
4540cc12 SUB EAX,dword ptr [EBP + -0x10]
4540cc15 TEST EAX,EAX
4540cc17 JG 0x4540ccb9
4540cc1d MOV EAX,dword ptr [EBP + 0x10]
4540cc20 MOV dword ptr [EAX],ECX
4540cc22 MOV EDI,dword ptr [EBP + -0x4]
4540cc25 MOV ESI,dword ptr [EBP + -0x8]
4540cc28 INC ECX
4540cc29 ADD EDX,0xc
4540cc2c CMP ECX,dword ptr [EBP + -0xc]
4540cc2f JC 0x4540cbff
4540cc31 MOV EBX,dword ptr [EBP + 0xc]
4540cc34 PUSH EDI
4540cc35 MOV ECX,EBX
4540cc37 CALL 0x4540d5f2
4540cc3c MOV EAX,dword ptr [EBP + 0x8]
4540cc3f LEA EDI,[EDI*0x8 + 0xfffffff8]
4540cc46 MOV dword ptr [EBP + 0xc],EDI
4540cc49 MOV ECX,dword ptr [EAX + 0x4]
4540cc4c MOV EAX,dword ptr [EAX]
4540cc4e LEA EDX,[EAX + ECX*0x2]
4540cc51 MOV ECX,dword ptr [EBP + -0xc]
4540cc54 DEC ECX
4540cc55 IMUL EDI,ECX,0xc
4540cc58 MOV EAX,dword ptr [ESI + 0x124]
4540cc5e MOV dword ptr [EBP + -0x4],EDI
4540cc61 MOV dword ptr [EBP + -0xc],ECX
4540cc64 MOV ESI,dword ptr [EAX]
4540cc66 ADD ESI,EDI
4540cc68 LEA EDI,[EBP + -0x1c]
4540cc6b MOVSD ES:EDI,ESI
4540cc6c MOVSD ES:EDI,ESI
4540cc6d MOVSD ES:EDI,ESI
4540cc6e MOV EDI,dword ptr [EBP + -0x1c]
4540cc71 MOV EAX,EDI
4540cc73 SUB EAX,dword ptr [EBP + -0x10]
4540cc76 MOV ESI,dword ptr [EBP + 0x8]
4540cc79 TEST EAX,EAX
4540cc7b JLE 0x4540ccce
4540cc7d CMP EAX,dword ptr [ESI + 0x4]
4540cc80 JGE 0x4540ccce
4540cc82 MOV ESI,dword ptr [EBP + -0x8]
4540cc85 MOV EAX,dword ptr [ESI + 0x100]
4540cc8b LEA ECX,[EAX + EDI*0x2]
4540cc8e MOV EDI,dword ptr [EBP + 0xc]
4540cc91 MOV EAX,dword ptr [EBX]
4540cc93 MOV dword ptr [EDI + EAX*0x1],ECX
4540cc96 MOV EAX,EDX
4540cc98 MOV ECX,dword ptr [EBX]
4540cc9a SUB EAX,dword ptr [EDI + ECX*0x1]
4540cc9d SAR EAX,0x1
4540cc9f MOV dword ptr [EDI + ECX*0x1 + 0x4],EAX
4540cca3 MOV EAX,dword ptr [EBX]
4540cca5 MOV ECX,dword ptr [EBP + -0xc]
4540cca8 MOV EAX,dword ptr [EDI + EAX*0x1 + 0x4]
4540ccac NEG EAX
4540ccae SUB EDI,0x8
4540ccb1 MOV dword ptr [EBP + 0xc],EDI
4540ccb4 LEA EDX,[EDX + EAX*0x2]
4540ccb7 JMP 0x4540ccd8
4540ccb9 CMP EAX,dword ptr [EBX + 0x4]
4540ccbc JGE 0x4540cc22
4540ccc2 MOV EDI,dword ptr [EBP + -0x4]
4540ccc5 INC EDI
4540ccc6 MOV dword ptr [EBP + -0x4],EDI
4540ccc9 JMP 0x4540cc25
4540ccce MOV EAX,dword ptr [EBP + 0x10]
4540ccd1 CMP ECX,dword ptr [EAX]
4540ccd3 JZ 0x4540cce4
4540ccd5 MOV ESI,dword ptr [EBP + -0x8]
4540ccd8 MOV EDI,dword ptr [EBP + -0x4]
4540ccdb DEC ECX
4540ccdc SUB EDI,0xc
4540ccdf JMP 0x4540cc58
4540cce4 MOV ECX,dword ptr [EBX]
4540cce6 MOV EAX,dword ptr [ESI]
4540cce8 POP EDI
4540cce9 MOV dword ptr [ECX],EAX
4540cceb SUB EDX,dword ptr [ESI]
4540cced MOV EAX,dword ptr [EBX]
4540ccef SAR EDX,0x1
4540ccf1 MOV dword ptr [EAX + 0x4],EDX
4540ccf4 POP ESI
4540ccf5 POP EBX
4540ccf6 MOV ESP,EBP
4540ccf8 POP EBP
4540ccf9 RET 0xc

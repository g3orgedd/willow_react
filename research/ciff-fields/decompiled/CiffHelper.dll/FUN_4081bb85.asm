4081bb85 PUSH 0x24
4081bb87 MOV EAX,0x408471ac
4081bb8c CALL 0x4082d4e4
4081bb91 XOR EAX,EAX
4081bb93 MOV dword ptr [EBP + -0x20],EAX
4081bb96 MOV ESI,dword ptr [EBP + 0x8]
4081bb99 MOV dword ptr [EBP + -0x4],0x2
4081bba0 MOV dword ptr [ESI],EAX
4081bba2 MOV dword ptr [EBP + -0x1c],EAX
4081bba5 LEA EDX,[EBP + -0x1c]
4081bba8 MOV EAX,dword ptr [EBP + 0x10]
4081bbab PUSH EDX
4081bbac PUSH EAX
4081bbad MOV dword ptr [EBP + -0x20],0x1
4081bbb4 MOV ECX,dword ptr [EAX]
4081bbb6 CALL dword ptr [ECX + 0x1c]
4081bbb9 MOV EDI,dword ptr [0x4084a1f0]
4081bbbf XOR EAX,EAX
4081bbc1 MOV dword ptr [EBP + -0x18],EAX
4081bbc4 CMP dword ptr [EBP + -0x1c],EAX
4081bbc7 JLE 0x4081bc85
4081bbcd LEA ECX,[EBP + -0x30]
4081bbd0 CALL 0x40802e76
4081bbd5 MOV EAX,dword ptr [EBP + 0x10]
4081bbd8 LEA ESI,[EBP + -0x30]
4081bbdb MOV EDX,dword ptr [EBP + -0x18]
4081bbde INC EDX
4081bbdf MOV byte ptr [EBP + -0x4],0x3
4081bbe3 PUSH ESI
4081bbe4 MOV ECX,dword ptr [EAX]
4081bbe6 PUSH EDX
4081bbe7 PUSH EAX
4081bbe8 MOV dword ptr [EBP + -0x18],EDX
4081bbeb CALL dword ptr [ECX + 0x30]
4081bbee PUSH dword ptr [EBP + -0x28]
4081bbf1 LEA ECX,[EBP + -0x14]
4081bbf4 CALL 0x40803a5e
4081bbf9 AND dword ptr [EBP + -0x10],0x0
4081bbfd MOV EAX,dword ptr [EBP + -0x14]
4081bc00 LEA EDX,[EBP + -0x10]
4081bc03 PUSH EDX
4081bc04 PUSH EAX
4081bc05 MOV byte ptr [EBP + -0x4],0x5
4081bc09 MOV ECX,dword ptr [EAX]
4081bc0b CALL dword ptr [ECX + 0x1c]
4081bc0e PUSH 0x0
4081bc10 PUSH 0x400
4081bc15 PUSH dword ptr [EBP + 0xc]
4081bc18 PUSH dword ptr [EBP + -0x10]
4081bc1b CALL 0x4082c8e6
4081bc20 MOV ESI,dword ptr [EBP + 0x8]
4081bc23 CMP EAX,0x1
4081bc26 JZ 0x4081bc56
4081bc28 PUSH dword ptr [EBP + -0x10]
4081bc2b CALL EDI
4081bc2d MOV EAX,dword ptr [EBP + -0x14]
4081bc30 MOV byte ptr [EBP + -0x4],0x3
4081bc34 TEST EAX,EAX
4081bc36 JZ 0x4081bc3e
4081bc38 MOV ECX,dword ptr [EAX]
4081bc3a PUSH EAX
4081bc3b CALL dword ptr [ECX + 0x8]
4081bc3e LEA EAX,[EBP + -0x30]
4081bc41 PUSH EAX
4081bc42 CALL dword ptr [0x4084a1e4]
4081bc48 MOV EAX,dword ptr [EBP + -0x18]
4081bc4b CMP EAX,dword ptr [EBP + -0x1c]
4081bc4e JL 0x4081bbcd
4081bc54 JMP 0x4081bc85
4081bc56 MOV EAX,dword ptr [EBP + -0x14]
4081bc59 MOV dword ptr [ESI],EAX
4081bc5b TEST EAX,EAX
4081bc5d JZ 0x4081bc65
4081bc5f MOV ECX,dword ptr [EAX]
4081bc61 PUSH EAX
4081bc62 CALL dword ptr [ECX + 0x4]
4081bc65 PUSH dword ptr [EBP + -0x10]
4081bc68 CALL EDI
4081bc6a MOV EAX,dword ptr [EBP + -0x14]
4081bc6d MOV byte ptr [EBP + -0x4],0x3
4081bc71 TEST EAX,EAX
4081bc73 JZ 0x4081bc7b
4081bc75 MOV ECX,dword ptr [EAX]
4081bc77 PUSH EAX
4081bc78 CALL dword ptr [ECX + 0x8]
4081bc7b LEA EAX,[EBP + -0x30]
4081bc7e PUSH EAX
4081bc7f CALL dword ptr [0x4084a1e4]
4081bc85 PUSH dword ptr [EBP + 0xc]
4081bc88 CALL EDI
4081bc8a MOV ECX,dword ptr [EBP + 0x10]
4081bc8d MOV byte ptr [EBP + -0x4],0x0
4081bc91 TEST ECX,ECX
4081bc93 JZ 0x4081bc9b
4081bc95 MOV EDX,dword ptr [ECX]
4081bc97 PUSH ECX
4081bc98 CALL dword ptr [EDX + 0x8]
4081bc9b MOV EAX,ESI
4081bc9d CALL 0x4082d4b2
4081bca2 RET 0xc

4541cc0e PUSH 0x30
4541cc10 MOV EAX,0x45444f7b
4541cc15 CALL 0x4542a9a8
4541cc1a MOV EDI,dword ptr [EBP + 0x8]
4541cc1d XOR EBX,EBX
4541cc1f LEA ECX,[EBP + -0x28]
4541cc22 PUSH 0x4544a0b0
4541cc27 MOV dword ptr [EBP + -0x4],EBX
4541cc2a CALL 0x45401bb9
4541cc2f MOV EAX,dword ptr [EBP + 0xc]
4541cc32 PUSH EDI
4541cc33 PUSH EAX
4541cc34 MOV byte ptr [EBP + -0x4],0x1
4541cc38 MOV ECX,dword ptr [EAX]
4541cc3a CALL dword ptr [ECX + 0x2c]
4541cc3d MOV EAX,dword ptr [EBP + 0xc]
4541cc40 LEA ESI,[EDI + 0x4]
4541cc43 PUSH ESI
4541cc44 PUSH EAX
4541cc45 MOV ECX,dword ptr [EAX]
4541cc47 CALL dword ptr [ECX + 0x34]
4541cc4a MOV EAX,dword ptr [EBP + 0xc]
4541cc4d LEA EDX,[EBP + -0x38]
4541cc50 MOV dword ptr [EBP + -0x38],EBX
4541cc53 PUSH EDX
4541cc54 PUSH EAX
4541cc55 MOV ECX,dword ptr [EAX]
4541cc57 CALL dword ptr [ECX + 0x88]
4541cc5d MOV EAX,dword ptr [EBP + 0xc]
4541cc60 LEA EDX,[EBP + -0x34]
4541cc63 MOV dword ptr [EBP + -0x34],EBX
4541cc66 PUSH EDX
4541cc67 PUSH EAX
4541cc68 MOV ECX,dword ptr [EAX]
4541cc6a CALL dword ptr [ECX + 0x78]
4541cc6d MOV EAX,dword ptr [EDI]
4541cc6f LEA EDX,[EBP + -0x30]
4541cc72 ADD EAX,dword ptr [EBP + -0x34]
4541cc75 MOV dword ptr [EDI + 0x8],EAX
4541cc78 MOV EAX,dword ptr [EBP + 0xc]
4541cc7b MOV dword ptr [EBP + -0x30],EBX
4541cc7e PUSH EDX
4541cc7f PUSH EAX
4541cc80 MOV ECX,dword ptr [EAX]
4541cc82 CALL dword ptr [ECX + 0x80]
4541cc88 MOV EAX,dword ptr [ESI]
4541cc8a ADD EAX,dword ptr [EBP + -0x30]
4541cc8d MOV dword ptr [EDI + 0xc],EAX
4541cc90 MOV dword ptr [EBP + -0x2c],EBX
4541cc93 MOV EAX,dword ptr [EBP + 0xc]
4541cc96 LEA EDX,[EBP + -0x2c]
4541cc99 PUSH EDX
4541cc9a PUSH EAX
4541cc9b MOV byte ptr [EBP + -0x4],0x2
4541cc9f MOV ECX,dword ptr [EAX]
4541cca1 CALL dword ptr [ECX + 0x1c]
4541cca4 PUSH dword ptr [EBP + -0x2c]
4541cca7 LEA ECX,[EBP + -0x3c]
4541ccaa CALL 0x45402ac2
4541ccaf MOV ECX,EAX
4541ccb1 PUSH dword ptr [EBP + -0x38]
4541ccb4 CMP dword ptr [EBP + -0x14],0x10
4541ccb8 LEA EAX,[EBP + -0x28]
4541ccbb PUSH dword ptr [EDI + 0xc]
4541ccbe CMOVNC EAX,dword ptr [EBP + -0x28]
4541ccc2 PUSH dword ptr [ESI]
4541ccc4 MOV byte ptr [EBP + -0x4],0x3
4541ccc8 PUSH dword ptr [EDI + 0x8]
4541cccb PUSH dword ptr [EDI]
4541cccd PUSH dword ptr [ECX]
4541cccf PUSH EAX
4541ccd0 PUSH 0x4544a0d8
4541ccd5 CALL 0x4540303d
4541ccda ADD ESP,0x20
4541ccdd LEA ECX,[EBP + -0x3c]
4541cce0 CALL 0x45402c5d
4541cce5 PUSH dword ptr [EBP + -0x2c]
4541cce8 CALL dword ptr [0x4544725c]
4541ccee PUSH EBX
4541ccef PUSH 0x1
4541ccf1 LEA ECX,[EBP + -0x28]
4541ccf4 CALL 0x45402296
4541ccf9 OR dword ptr [EBP + -0x4],0xffffffff
4541ccfd MOV ECX,dword ptr [EBP + 0xc]
4541cd00 TEST ECX,ECX
4541cd02 JZ 0x4541cd0a
4541cd04 MOV EDX,dword ptr [ECX]
4541cd06 PUSH ECX
4541cd07 CALL dword ptr [EDX + 0x8]
4541cd0a MOV EAX,EDI
4541cd0c CALL 0x4542a957
4541cd11 RET 0x8

4280dcfd PUSH 0x20
4280dcff MOV EAX,0x4282a644
4280dd04 CALL 0x42813b12
4280dd09 PUSH dword ptr [EBP + 0x8]
4280dd0c LEA ECX,[EBP + 0x8]
4280dd0f CALL 0x4280d1d8
4280dd14 PUSH dword ptr [EBP + 0x14]
4280dd17 XOR EBX,EBX
4280dd19 LEA ECX,[EBP + -0x20]
4280dd1c MOV dword ptr [EBP + -0x4],EBX
4280dd1f CALL 0x4280d1af
4280dd24 PUSH dword ptr [EBP + 0x24]
4280dd27 LEA ECX,[EBP + -0x10]
4280dd2a CALL 0x4280d15d
4280dd2f MOV EAX,dword ptr [EBP + 0x8]
4280dd32 MOV ECX,dword ptr [EBP + -0x20]
4280dd35 MOV EDX,dword ptr [EBP + -0x10]
4280dd38 MOV byte ptr [EBP + -0x4],0x2
4280dd3c TEST EAX,EAX
4280dd3e JZ 0x4280de7a
4280dd44 TEST EDX,EDX
4280dd46 JZ 0x4280de7a
4280dd4c TEST ECX,ECX
4280dd4e JZ 0x4280de7a
4280dd54 MOV dword ptr [EBP + -0x18],EBX
4280dd57 LEA ECX,[EBP + -0x18]
4280dd5a MOV EAX,dword ptr [EDX]
4280dd5c PUSH ECX
4280dd5d PUSH EDX
4280dd5e CALL dword ptr [EAX + 0x37c]
4280dd64 MOV EAX,dword ptr [EBP + -0x10]
4280dd67 LEA EDX,[EBP + -0x14]
4280dd6a MOV dword ptr [EBP + -0x14],EBX
4280dd6d PUSH EDX
4280dd6e PUSH EAX
4280dd6f MOV ECX,dword ptr [EAX]
4280dd71 CALL dword ptr [ECX + 0x374]
4280dd77 MOV EAX,dword ptr [EBP + -0x10]
4280dd7a LEA EDX,[EBP + -0x1c]
4280dd7d MOV dword ptr [EBP + -0x1c],EBX
4280dd80 PUSH EDX
4280dd81 PUSH EAX
4280dd82 MOV ECX,dword ptr [EAX]
4280dd84 CALL dword ptr [ECX + 0x384]
4280dd8a MOV EAX,dword ptr [EBP + -0x20]
4280dd8d LEA EDX,[EBP + -0x24]
4280dd90 MOV dword ptr [EBP + -0x24],EBX
4280dd93 PUSH EDX
4280dd94 PUSH EAX
4280dd95 MOV ECX,dword ptr [EAX]
4280dd97 CALL dword ptr [ECX + 0x54]
4280dd9a CMP dword ptr [EBP + -0x24],EBX
4280dd9d JNZ 0x4280de19
4280dd9f LEA ECX,[EBP + -0x28]
4280dda2 CALL 0x4280fd96
4280dda7 MOV EAX,dword ptr [EBP + -0x10]
4280ddaa MOV byte ptr [EBP + -0x4],0x3
4280ddae PUSH ECX
4280ddaf MOV ECX,ESP
4280ddb1 MOV dword ptr [ECX],EAX
4280ddb3 TEST EAX,EAX
4280ddb5 JZ 0x4280ddbd
4280ddb7 MOV ECX,dword ptr [EAX]
4280ddb9 PUSH EAX
4280ddba CALL dword ptr [ECX + 0x4]
4280ddbd PUSH 0x1
4280ddbf PUSH dword ptr [EBP + -0x18]
4280ddc2 CALL 0x4280fdea
4280ddc7 ADD ESP,0x8
4280ddca MOV dword ptr [EBP + -0x18],EAX
4280ddcd MOV EAX,dword ptr [EBP + -0x10]
4280ddd0 MOV ECX,ESP
4280ddd2 MOV dword ptr [ECX],EAX
4280ddd4 TEST EAX,EAX
4280ddd6 JZ 0x4280ddde
4280ddd8 MOV ECX,dword ptr [EAX]
4280ddda PUSH EAX
4280dddb CALL dword ptr [ECX + 0x4]
4280ddde PUSH EBX
4280dddf PUSH dword ptr [EBP + -0x14]
4280dde2 CALL 0x4280fdea
4280dde7 ADD ESP,0x8
4280ddea MOV dword ptr [EBP + -0x14],EAX
4280dded MOV EAX,dword ptr [EBP + -0x10]
4280ddf0 MOV ECX,ESP
4280ddf2 MOV dword ptr [ECX],EAX
4280ddf4 TEST EAX,EAX
4280ddf6 JZ 0x4280ddfe
4280ddf8 MOV ECX,dword ptr [EAX]
4280ddfa PUSH EAX
4280ddfb CALL dword ptr [ECX + 0x4]
4280ddfe PUSH EBX
4280ddff PUSH dword ptr [EBP + -0x1c]
4280de02 CALL 0x4280fdea
4280de07 ADD ESP,0xc
4280de0a MOV dword ptr [EBP + -0x1c],EAX
4280de0d LEA ECX,[EBP + -0x28]
4280de10 MOV byte ptr [EBP + -0x4],0x2
4280de14 CALL 0x4280fd9f
4280de19 MOV EAX,dword ptr [EBP + 0x8]
4280de1c PUSH 0x1
4280de1e PUSH EAX
4280de1f MOV ECX,dword ptr [EAX]
4280de21 CALL dword ptr [ECX + 0xd0]
4280de27 MOV EAX,dword ptr [EBP + 0x8]
4280de2a PUSH dword ptr [EBP + -0x14]
4280de2d PUSH EAX
4280de2e MOV ECX,dword ptr [EAX]
4280de30 CALL dword ptr [ECX + 0x84]
4280de36 MOV EAX,dword ptr [EBP + 0x8]
4280de39 PUSH dword ptr [EBP + -0x18]
4280de3c PUSH EAX
4280de3d MOV ECX,dword ptr [EAX]
4280de3f CALL dword ptr [ECX + 0x7c]
4280de42 MOV EAX,dword ptr [EBP + 0x8]
4280de45 PUSH dword ptr [EBP + -0x14]
4280de48 PUSH EAX
4280de49 MOV ECX,dword ptr [EAX]
4280de4b CALL dword ptr [ECX + 0xb4]
4280de51 MOV EAX,dword ptr [EBP + 0x8]
4280de54 PUSH dword ptr [EBP + -0x18]
4280de57 PUSH EAX
4280de58 MOV ECX,dword ptr [EAX]
4280de5a CALL dword ptr [ECX + 0xac]
4280de60 MOV EAX,dword ptr [EBP + 0x8]
4280de63 PUSH dword ptr [EBP + -0x1c]
4280de66 PUSH EAX
4280de67 MOV ECX,dword ptr [EAX]
4280de69 CALL dword ptr [ECX + 0xd8]
4280de6f MOV EAX,dword ptr [EBP + 0x8]
4280de72 MOV BL,0x1
4280de74 MOV ECX,dword ptr [EBP + -0x20]
4280de77 MOV EDX,dword ptr [EBP + -0x10]
4280de7a MOV byte ptr [EBP + -0x4],0x1
4280de7e TEST EDX,EDX
4280de80 JZ 0x4280de8e
4280de82 MOV EAX,dword ptr [EDX]
4280de84 PUSH EDX
4280de85 CALL dword ptr [EAX + 0x8]
4280de88 MOV EAX,dword ptr [EBP + 0x8]
4280de8b MOV ECX,dword ptr [EBP + -0x20]
4280de8e MOV byte ptr [EBP + -0x4],0x0
4280de92 TEST ECX,ECX
4280de94 JZ 0x4280de9f
4280de96 MOV EAX,dword ptr [ECX]
4280de98 PUSH ECX
4280de99 CALL dword ptr [EAX + 0x8]
4280de9c MOV EAX,dword ptr [EBP + 0x8]
4280de9f OR dword ptr [EBP + -0x4],0xffffffff
4280dea3 TEST EAX,EAX
4280dea5 JZ 0x4280dead
4280dea7 MOV ECX,dword ptr [EAX]
4280dea9 PUSH EAX
4280deaa CALL dword ptr [ECX + 0x8]
4280dead MOV AL,BL
4280deaf CALL 0x42813ae0
4280deb4 RET 0x24

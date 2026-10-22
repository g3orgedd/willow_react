4501ac15 PUSH 0x8
4501ac17 MOV EAX,0x4503be5b
4501ac1c CALL 0x45022ed6
4501ac21 MOV ESI,ECX
4501ac23 MOV EAX,dword ptr [ESI + 0x4]
4501ac26 XOR EBX,EBX
4501ac28 MOV EAX,dword ptr [EAX + 0x4]
4501ac2b CMP byte ptr [EAX + ESI*0x1 + 0x100],BL
4501ac32 JNZ 0x4501ac3d
4501ac34 CMP dword ptr [EAX + ESI*0x1 + 0xcc],EBX
4501ac3b JZ 0x4501ac4a
4501ac3d CMP byte ptr [EAX + ESI*0x1 + 0x101],BL
4501ac44 JZ 0x4501ae6d
4501ac4a MOV EDI,dword ptr [EBP + 0x8]
4501ac4d LEA ECX,[EBP + 0x8]
4501ac50 MOV dword ptr [EBP + -0x10],EBX
4501ac53 PUSH dword ptr [EDI]
4501ac55 CALL 0x45019bdd
4501ac5a MOV EAX,dword ptr [EBP + 0x8]
4501ac5d MOV dword ptr [EBP + -0x4],EBX
4501ac60 TEST EAX,EAX
4501ac62 JZ 0x4501ae77
4501ac68 MOV ECX,dword ptr [EAX]
4501ac6a LEA EDX,[EBP + -0x10]
4501ac6d PUSH EDX
4501ac6e PUSH EAX
4501ac6f CALL dword ptr [ECX + 0x48]
4501ac72 MOV EAX,dword ptr [EBP + -0x10]
4501ac75 DEC EAX
4501ac76 JZ 0x4501add4
4501ac7c DEC EAX
4501ac7d JZ 0x4501ad79
4501ac83 DEC EAX
4501ac84 JZ 0x4501ad18
4501ac8a SUB EAX,0x3
4501ac8d JNZ 0x4501ae5c
4501ac93 MOV EAX,dword ptr [ESI + 0x4]
4501ac96 MOV EAX,dword ptr [EAX + 0x4]
4501ac99 CMP word ptr [EAX + ESI*0x1 + 0xb4],0x8
4501aca2 JNZ 0x4501ae5c
4501aca8 PUSH dword ptr [EAX + ESI*0x1 + 0xbc]
4501acaf CALL dword ptr [0x4503d218]
4501acb5 TEST EAX,EAX
4501acb7 JZ 0x4501ad04
4501acb9 MOV EAX,dword ptr [ESI + 0x4]
4501acbc MOV ECX,dword ptr [EDI]
4501acbe MOV EAX,dword ptr [EAX + 0x4]
4501acc1 MOV EDX,dword ptr [ECX]
4501acc3 PUSH dword ptr [EAX + ESI*0x1 + 0xbc]
4501acca PUSH ECX
4501accb CALL dword ptr [EDX + 0x64]
4501acce MOV EAX,dword ptr [ESI + 0x4]
4501acd1 MOV ECX,dword ptr [EDI]
4501acd3 MOV EAX,dword ptr [EAX + 0x4]
4501acd6 MOV EDX,dword ptr [ECX]
4501acd8 PUSH dword ptr [EAX + ESI*0x1 + 0xbc]
4501acdf PUSH ECX
4501ace0 CALL dword ptr [EDX + 0x5c]
4501ace3 MOV EAX,dword ptr [EBP + 0x8]
4501ace6 PUSH EBX
4501ace7 PUSH EAX
4501ace8 MOV ECX,dword ptr [EAX]
4501acea CALL dword ptr [ECX + 0x4c]
4501aced MOV EAX,dword ptr [EDI]
4501acef PUSH EBX
4501acf0 PUSH EAX
4501acf1 MOV ECX,dword ptr [EAX]
4501acf3 CALL dword ptr [ECX + 0x2c]
4501acf6 MOV EAX,dword ptr [EDI]
4501acf8 PUSH EBX
4501acf9 PUSH EAX
4501acfa MOV ECX,dword ptr [EAX]
4501acfc CALL dword ptr [ECX + 0x54]
4501acff JMP 0x4501ae33
4501ad04 LEA EAX,[EBP + -0x14]
4501ad07 MOV ECX,EDI
4501ad09 PUSH EAX
4501ad0a CALL 0x4500fe88
4501ad0f MOV byte ptr [EBP + -0x4],0x4
4501ad13 JMP 0x4501ae48
4501ad18 MOV EAX,dword ptr [ESI + 0x4]
4501ad1b MOV EAX,dword ptr [EAX + 0x4]
4501ad1e CMP word ptr [EAX + ESI*0x1 + 0xa4],0x8
4501ad27 JNZ 0x4501ae5c
4501ad2d PUSH dword ptr [EAX + ESI*0x1 + 0xac]
4501ad34 CALL dword ptr [0x4503d218]
4501ad3a TEST EAX,EAX
4501ad3c JZ 0x4501ad65
4501ad3e MOV EAX,dword ptr [ESI + 0x4]
4501ad41 MOV ECX,dword ptr [EDI]
4501ad43 MOV EAX,dword ptr [EAX + 0x4]
4501ad46 MOV EDX,dword ptr [ECX]
4501ad48 PUSH dword ptr [EAX + ESI*0x1 + 0xac]
4501ad4f PUSH ECX
4501ad50 CALL dword ptr [EDX + 0x64]
4501ad53 MOV EAX,dword ptr [ESI + 0x4]
4501ad56 MOV EAX,dword ptr [EAX + 0x4]
4501ad59 PUSH dword ptr [EAX + ESI*0x1 + 0xac]
4501ad60 JMP 0x4501ae18
4501ad65 LEA EAX,[EBP + -0x14]
4501ad68 MOV ECX,EDI
4501ad6a PUSH EAX
4501ad6b CALL 0x4500fe88
4501ad70 MOV byte ptr [EBP + -0x4],0x3
4501ad74 JMP 0x4501ae48
4501ad79 MOV EAX,dword ptr [ESI + 0x4]
4501ad7c MOV EAX,dword ptr [EAX + 0x4]
4501ad7f CMP word ptr [EAX + ESI*0x1 + 0x94],0x8
4501ad88 JNZ 0x4501ae5c
4501ad8e PUSH dword ptr [EAX + ESI*0x1 + 0x9c]
4501ad95 CALL dword ptr [0x4503d218]
4501ad9b TEST EAX,EAX
4501ad9d JZ 0x4501adc3
4501ad9f MOV EAX,dword ptr [ESI + 0x4]
4501ada2 MOV ECX,dword ptr [EDI]
4501ada4 MOV EAX,dword ptr [EAX + 0x4]
4501ada7 MOV EDX,dword ptr [ECX]
4501ada9 PUSH dword ptr [EAX + ESI*0x1 + 0x9c]
4501adb0 PUSH ECX
4501adb1 CALL dword ptr [EDX + 0x64]
4501adb4 MOV EAX,dword ptr [ESI + 0x4]
4501adb7 MOV EAX,dword ptr [EAX + 0x4]
4501adba PUSH dword ptr [EAX + ESI*0x1 + 0x9c]
4501adc1 JMP 0x4501ae18
4501adc3 LEA EAX,[EBP + -0x14]
4501adc6 MOV ECX,EDI
4501adc8 PUSH EAX
4501adc9 CALL 0x4500fe88
4501adce MOV byte ptr [EBP + -0x4],0x2
4501add2 JMP 0x4501ae48
4501add4 MOV EAX,dword ptr [ESI + 0x4]
4501add7 MOV EAX,dword ptr [EAX + 0x4]
4501adda CMP word ptr [EAX + ESI*0x1 + 0x84],0x8
4501ade3 JNZ 0x4501ae5c
4501ade5 PUSH dword ptr [EAX + ESI*0x1 + 0x8c]
4501adec CALL dword ptr [0x4503d218]
4501adf2 TEST EAX,EAX
4501adf4 JZ 0x4501ae39
4501adf6 MOV EAX,dword ptr [ESI + 0x4]
4501adf9 MOV ECX,dword ptr [EDI]
4501adfb MOV EAX,dword ptr [EAX + 0x4]
4501adfe MOV EDX,dword ptr [ECX]
4501ae00 PUSH dword ptr [EAX + ESI*0x1 + 0x8c]
4501ae07 PUSH ECX
4501ae08 CALL dword ptr [EDX + 0x64]
4501ae0b MOV EAX,dword ptr [ESI + 0x4]
4501ae0e MOV EAX,dword ptr [EAX + 0x4]
4501ae11 PUSH dword ptr [EAX + ESI*0x1 + 0x8c]
4501ae18 MOV ECX,dword ptr [EDI]
4501ae1a PUSH ECX
4501ae1b MOV EDX,dword ptr [ECX]
4501ae1d CALL dword ptr [EDX + 0x5c]
4501ae20 MOV EAX,dword ptr [EBP + 0x8]
4501ae23 PUSH EBX
4501ae24 PUSH EAX
4501ae25 MOV ECX,dword ptr [EAX]
4501ae27 CALL dword ptr [ECX + 0x4c]
4501ae2a MOV EAX,dword ptr [EDI]
4501ae2c PUSH EBX
4501ae2d PUSH EAX
4501ae2e MOV ECX,dword ptr [EAX]
4501ae30 CALL dword ptr [ECX + 0x2c]
4501ae33 MOV byte ptr [ESI + 0x8],0x1
4501ae37 JMP 0x4501ae5c
4501ae39 LEA EAX,[EBP + -0x14]
4501ae3c MOV ECX,EDI
4501ae3e PUSH EAX
4501ae3f CALL 0x4500fe88
4501ae44 MOV byte ptr [EBP + -0x4],0x1
4501ae48 MOV EAX,dword ptr [EDI]
4501ae4a PUSH dword ptr [EBP + -0x14]
4501ae4d PUSH EAX
4501ae4e MOV ECX,dword ptr [EAX]
4501ae50 CALL dword ptr [ECX + 0x64]
4501ae53 PUSH dword ptr [EBP + -0x14]
4501ae56 CALL dword ptr [0x4503d21c]
4501ae5c OR dword ptr [EBP + -0x4],0xffffffff
4501ae60 MOV EAX,dword ptr [EBP + 0x8]
4501ae63 TEST EAX,EAX
4501ae65 JZ 0x4501ae6d
4501ae67 MOV ECX,dword ptr [EAX]
4501ae69 PUSH EAX
4501ae6a CALL dword ptr [ECX + 0x8]
4501ae6d XOR EAX,EAX
4501ae6f CALL 0x45022ea4
4501ae74 RET 0x4
4501ae77 MOV EAX,0x80004005
4501ae7c JMP 0x4501ae6f

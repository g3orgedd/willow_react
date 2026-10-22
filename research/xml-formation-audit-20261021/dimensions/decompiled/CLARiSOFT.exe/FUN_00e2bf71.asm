00e2bf71 PUSH EBP
00e2bf72 MOV EBP,ESP
00e2bf74 PUSH ECX
00e2bf75 PUSH ECX
00e2bf76 PUSH ESI
00e2bf77 MOV ESI,dword ptr [EBP + 0x18]
00e2bf7a LEA EAX,[EBP + -0x8]
00e2bf7d PUSH EDI
00e2bf7e PUSH EAX
00e2bf7f LEA EAX,[EBP + -0x4]
00e2bf82 XOR EDX,EDX
00e2bf84 PUSH EAX
00e2bf85 PUSH dword ptr [EBP + 0x1c]
00e2bf88 MOV EDI,ECX
00e2bf8a MOV dword ptr [EBP + -0x4],EDX
00e2bf8d PUSH ESI
00e2bf8e PUSH dword ptr [EBP + 0x14]
00e2bf91 PUSH dword ptr [EBP + 0x10]
00e2bf94 MOV ECX,dword ptr [EDI + 0x8]
00e2bf97 PUSH EDX
00e2bf98 PUSH dword ptr [EBP + 0xc]
00e2bf9b PUSH dword ptr [EBP + 0x8]
00e2bf9e TEST ECX,ECX
00e2bfa0 JZ 0x00e2bfa9
00e2bfa2 CALL 0x00e34804
00e2bfa7 JMP 0x00e2bfaf
00e2bfa9 CALL dword ptr [0x00efc038]
00e2bfaf MOV ECX,EAX
00e2bfb1 TEST ECX,ECX
00e2bfb3 JNZ 0x00e2bfd8
00e2bfb5 MOV ECX,dword ptr [EBP + 0x20]
00e2bfb8 TEST ECX,ECX
00e2bfba JZ 0x00e2bfc1
00e2bfbc MOV EAX,dword ptr [EBP + -0x8]
00e2bfbf MOV dword ptr [ECX],EAX
00e2bfc1 MOV ECX,EDI
00e2bfc3 CALL 0x00e2b984
00e2bfc8 MOV ECX,EAX
00e2bfca AND ESI,0x300
00e2bfd0 MOV EAX,dword ptr [EBP + -0x4]
00e2bfd3 MOV dword ptr [EDI],EAX
00e2bfd5 MOV dword ptr [EDI + 0x4],ESI
00e2bfd8 POP EDI
00e2bfd9 MOV EAX,ECX
00e2bfdb POP ESI
00e2bfdc MOV ESP,EBP
00e2bfde POP EBP
00e2bfdf RET 0x1c

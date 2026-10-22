00eaeb3c PUSH 0x24
00eaeb3e MOV EAX,0xef7ed4
00eaeb43 CALL 0x00ec9e5a
00eaeb48 AND dword ptr [EBP + -0x4],0x0
00eaeb4c LEA ECX,[EBP + -0x30]
00eaeb4f CALL 0x00e03b51
00eaeb54 MOV EAX,dword ptr [EBP + 0x8]
00eaeb57 LEA EDX,[EBP + -0x30]
00eaeb5a PUSH EDX
00eaeb5b PUSH EAX
00eaeb5c MOV byte ptr [EBP + -0x4],0x2
00eaeb60 MOV ECX,dword ptr [EAX]
00eaeb62 CALL dword ptr [ECX + 0x474]
00eaeb68 PUSH dword ptr [EBP + -0x28]
00eaeb6b LEA ECX,[EBP + -0x10]
00eaeb6e CALL 0x00e28144
00eaeb73 LEA ECX,[EBP + -0x20]
00eaeb76 CALL 0x00e03b51
00eaeb7b MOV EAX,dword ptr [EBP + -0x10]
00eaeb7e LEA EDX,[EBP + -0x20]
00eaeb81 PUSH EDX
00eaeb82 PUSH dword ptr [EBP + 0xc]
00eaeb85 MOV byte ptr [EBP + -0x4],0x4
00eaeb89 MOV ECX,dword ptr [EAX]
00eaeb8b PUSH EAX
00eaeb8c CALL dword ptr [ECX + 0x30]
00eaeb8f CMP word ptr [EBP + -0x20],0x0
00eaeb94 LEA EAX,[EBP + -0x20]
00eaeb97 PUSH EAX
00eaeb98 SETNZ BL
00eaeb9b CALL dword ptr [0x00efc408]
00eaeba1 MOV EAX,dword ptr [EBP + -0x10]
00eaeba4 MOV byte ptr [EBP + -0x4],0x2
00eaeba8 TEST EAX,EAX
00eaebaa JZ 0x00eaebb2
00eaebac MOV ECX,dword ptr [EAX]
00eaebae PUSH EAX
00eaebaf CALL dword ptr [ECX + 0x8]
00eaebb2 LEA EAX,[EBP + -0x30]
00eaebb5 PUSH EAX
00eaebb6 CALL dword ptr [0x00efc408]
00eaebbc MOV ECX,dword ptr [EBP + 0x8]
00eaebbf MOV byte ptr [EBP + -0x4],0x0
00eaebc3 TEST ECX,ECX
00eaebc5 JZ 0x00eaebcd
00eaebc7 MOV EDX,dword ptr [ECX]
00eaebc9 PUSH ECX
00eaebca CALL dword ptr [EDX + 0x8]
00eaebcd PUSH dword ptr [EBP + 0xc]
00eaebd0 CALL dword ptr [0x00efc448]
00eaebd6 MOV AL,BL
00eaebd8 CALL 0x00ec9e28
00eaebdd RET 0x8

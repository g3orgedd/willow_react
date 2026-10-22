4542aa7e PUSH EBP
4542aa7f MOV EBP,ESP
4542aa81 PUSH ECX
4542aa82 PUSH EBX
4542aa83 CLD
4542aa84 MOV EAX,dword ptr [EBP + 0xc]
4542aa87 MOV ECX,dword ptr [EAX + 0x8]
4542aa8a XOR ECX,dword ptr [EBP + 0xc]
4542aa8d CALL 0x4542a8d1
4542aa92 MOV EAX,dword ptr [EBP + 0x8]
4542aa95 MOV EAX,dword ptr [EAX + 0x4]
4542aa98 AND EAX,0x66
4542aa9b JZ 0x4542aaae
4542aa9d MOV EAX,dword ptr [EBP + 0xc]
4542aaa0 MOV dword ptr [EAX + 0x24],0x1
4542aaa7 XOR EAX,EAX
4542aaa9 INC EAX
4542aaaa JMP 0x4542ab18
4542aaae PUSH 0x1
4542aab0 MOV EAX,dword ptr [EBP + 0xc]
4542aab3 PUSH dword ptr [EAX + 0x18]
4542aab6 MOV EAX,dword ptr [EBP + 0xc]
4542aab9 PUSH dword ptr [EAX + 0x14]
4542aabc MOV EAX,dword ptr [EBP + 0xc]
4542aabf PUSH dword ptr [EAX + 0xc]
4542aac2 PUSH 0x0
4542aac4 PUSH dword ptr [EBP + 0x10]
4542aac7 MOV EAX,dword ptr [EBP + 0xc]
4542aaca PUSH dword ptr [EAX + 0x10]
4542aacd PUSH dword ptr [EBP + 0x8]
4542aad0 CALL 0x4543100d
4542aad5 ADD ESP,0x20
4542aad8 MOV EAX,dword ptr [EBP + 0xc]
4542aadb CMP dword ptr [EAX + 0x24],0x0
4542aadf JNZ 0x4542aaec
4542aae1 PUSH dword ptr [EBP + 0x8]
4542aae4 PUSH dword ptr [EBP + 0xc]
4542aae7 CALL 0x4542ad0b
4542aaec PUSH 0x0
4542aaee PUSH 0x0
4542aaf0 PUSH 0x0
4542aaf2 PUSH 0x0
4542aaf4 PUSH 0x0
4542aaf6 LEA EAX,[EBP + -0x4]
4542aaf9 PUSH EAX
4542aafa PUSH 0x123
4542aaff CALL 0x4542ab84
4542ab04 ADD ESP,0x1c
4542ab07 MOV EAX,dword ptr [EBP + -0x4]
4542ab0a MOV EBX,dword ptr [EBP + 0xc]
4542ab0d MOV ESP,dword ptr [EBX + 0x1c]
4542ab10 MOV EBP,dword ptr [EBX + 0x20]
4542ab13 JMP EAX
4542ab18 POP EBX
4542ab19 MOV ESP,EBP
4542ab1b POP EBP
4542ab1c RET

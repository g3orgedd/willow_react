00ecce60 PUSH EBP
00ecce61 MOV EBP,ESP
00ecce63 CMP dword ptr [0x00f44fc0],0x0
00ecce6a JNZ 0x00eccee1
00ecce6c MOV EDX,dword ptr [EBP + 0x8]
00ecce6f TEST EDX,EDX
00ecce71 JNZ 0x00ecce8a
00ecce73 CALL 0x00ed1b43
00ecce78 MOV dword ptr [EAX],0x16
00ecce7e CALL 0x00ed2f39
00ecce83 MOV EAX,0x7fffffff
00ecce88 POP EBP
00ecce89 RET
00ecce8a MOV ECX,dword ptr [EBP + 0xc]
00ecce8d TEST ECX,ECX
00ecce8f JZ 0x00ecce73
00ecce91 PUSH EBX
00ecce92 PUSH ESI
00ecce93 PUSH EDI
00ecce94 PUSH 0x41
00ecce96 POP EDI
00ecce97 PUSH 0x5a
00ecce99 SUB EDX,ECX
00ecce9b POP EBX
00ecce9c MOVZX EAX,word ptr [EDX + ECX*0x1]
00eccea0 CMP AX,DI
00eccea3 JC 0x00ecceb2
00eccea5 CMP AX,BX
00eccea8 JA 0x00ecceb2
00ecceaa ADD EAX,0x20
00eccead MOVZX ESI,AX
00ecceb0 JMP 0x00ecceb4
00ecceb2 MOV ESI,EAX
00ecceb4 MOVZX EAX,word ptr [ECX]
00ecceb7 CMP AX,DI
00ecceba JC 0x00eccec7
00eccebc CMP AX,BX
00eccebf JA 0x00eccec7
00eccec1 ADD EAX,0x20
00eccec4 MOVZX EAX,AX
00eccec7 ADD ECX,0x2
00ecceca TEST SI,SI
00eccecd JZ 0x00ecced4
00eccecf CMP SI,AX
00ecced2 JZ 0x00ecce9c
00ecced4 MOVZX ECX,AX
00ecced7 POP EDI
00ecced8 MOVZX EAX,SI
00eccedb POP ESI
00eccedc SUB EAX,ECX
00eccede POP EBX
00eccedf POP EBP
00eccee0 RET
00eccee1 PUSH 0x0
00eccee3 PUSH dword ptr [EBP + 0xc]
00eccee6 PUSH dword ptr [EBP + 0x8]
00eccee9 CALL 0x00eccef3
00ecceee ADD ESP,0xc
00eccef1 POP EBP
00eccef2 RET

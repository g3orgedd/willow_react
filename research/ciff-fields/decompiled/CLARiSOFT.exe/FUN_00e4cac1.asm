00e4cac1 PUSH EBP
00e4cac2 MOV EBP,ESP
00e4cac4 PUSH ESI
00e4cac5 MOV ESI,dword ptr [ECX + 0x8]
00e4cac8 XOR EDX,EDX
00e4caca MOV ECX,dword ptr [ECX + 0x4]
00e4cacd PUSH EDI
00e4cace MOV ECX,dword ptr [ECX]
00e4cad0 TEST ESI,ESI
00e4cad2 JLE 0x00e4cae5
00e4cad4 MOV EDI,dword ptr [EBP + 0x8]
00e4cad7 MOV EAX,dword ptr [ECX + 0x8]
00e4cada MOV ECX,dword ptr [ECX]
00e4cadc CMP dword ptr [EAX],EDI
00e4cade JZ 0x00e4cae7
00e4cae0 INC EDX
00e4cae1 CMP EDX,ESI
00e4cae3 JL 0x00e4cad7
00e4cae5 XOR EAX,EAX
00e4cae7 POP EDI
00e4cae8 POP ESI
00e4cae9 POP EBP
00e4caea RET 0x4

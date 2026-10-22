4500febb PUSH EBP
4500febc MOV EBP,ESP
4500febe PUSH ECX
4500febf MOV EAX,dword ptr [ECX + 0x4]
4500fec2 LEA EDX,[EBP + -0x4]
4500fec5 AND dword ptr [EBP + -0x4],0x0
4500fec9 PUSH EDX
4500feca PUSH EAX
4500fecb MOV ECX,dword ptr [EAX]
4500fecd CALL dword ptr [ECX + 0x80]
4500fed3 MOV EAX,dword ptr [EBP + -0x4]
4500fed6 MOV ESP,EBP
4500fed8 POP EBP
4500fed9 RET

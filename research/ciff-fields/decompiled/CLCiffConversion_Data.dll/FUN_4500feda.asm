4500feda PUSH EBP
4500fedb MOV EBP,ESP
4500fedd PUSH ECX
4500fede MOV EAX,dword ptr [ECX + 0x4]
4500fee1 LEA EDX,[EBP + -0x4]
4500fee4 AND dword ptr [EBP + -0x4],0x0
4500fee8 PUSH EDX
4500fee9 PUSH EAX
4500feea MOV ECX,dword ptr [EAX]
4500feec CALL dword ptr [ECX + 0x78]
4500feef MOV EAX,dword ptr [EBP + -0x4]
4500fef2 MOV ESP,EBP
4500fef4 POP EBP
4500fef5 RET

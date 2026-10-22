4200ce72 PUSH EBP
4200ce73 MOV EBP,ESP
4200ce75 PUSH dword ptr [EBP + 0x1c]
4200ce78 MOV EAX,dword ptr [EBP + 0x10]
4200ce7b PUSH dword ptr [EBP + 0x18]
4200ce7e PUSH dword ptr [EBP + 0x14]
4200ce81 PUSH dword ptr [EBP + 0xc]
4200ce84 PUSH 0x4
4200ce86 PUSH dword ptr [EAX + 0x4]
4200ce89 PUSH dword ptr [EAX]
4200ce8b PUSH dword ptr [EBP + 0x8]
4200ce8e CALL dword ptr [0x42089084]
4200ce94 XOR EAX,EAX
4200ce96 POP EBP
4200ce97 RET 0x18

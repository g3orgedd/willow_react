6810db7e PUSH EBP
6810db7f MOV EBP,ESP
6810db81 MOV EAX,dword ptr [EBP + 0x8]
6810db84 PUSH dword ptr [EBP + 0x10]
6810db87 PUSH dword ptr [EBP + 0xc]
6810db8a MOV EAX,dword ptr [EAX + 0x4]
6810db8d PUSH EAX
6810db8e MOV ECX,dword ptr [EAX]
6810db90 CALL dword ptr [ECX]
6810db92 POP EBP
6810db93 RET 0xc

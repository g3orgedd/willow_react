4542cebb PUSH 0x10
4542cebd PUSH 0x4545ac70
4542cec2 CALL 0x45434100
4542cec7 XOR ESI,ESI
4542cec9 MOV dword ptr [EBP + -0x1c],ESI
4542cecc MOV dword ptr [EBP + -0x20],ESI
4542cecf MOV dword ptr [EBP + -0x4],ESI
4542ced2 CMP ESI,dword ptr [EBP + 0x10]
4542ced5 JGE 0x4542cee9
4542ced7 MOV ECX,dword ptr [EBP + 0x8]
4542ceda CALL dword ptr [EBP + 0x14]
4542cedd MOV EAX,dword ptr [EBP + 0xc]
4542cee0 ADD dword ptr [EBP + 0x8],EAX
4542cee3 INC ESI
4542cee4 MOV dword ptr [EBP + -0x1c],ESI
4542cee7 JMP 0x4542ced2
4542cee9 XOR EAX,EAX
4542ceeb INC EAX
4542ceec MOV dword ptr [EBP + -0x20],EAX
4542ceef MOV dword ptr [EBP + -0x4],0xfffffffe
4542cef6 CALL 0x4542cf09
4542cefb CALL 0x45434145
4542cf00 RET 0x14

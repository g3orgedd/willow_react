4542cf8c PUSH 0x14
4542cf8e PUSH 0x4545acb0
4542cf93 CALL 0x45434100
4542cf98 AND dword ptr [EBP + -0x4],0x0
4542cf9c DEC dword ptr [EBP + 0x10]
4542cf9f JS 0x4542cfdb
4542cfa1 MOV ECX,dword ptr [EBP + 0x8]
4542cfa4 SUB ECX,dword ptr [EBP + 0xc]
4542cfa7 MOV dword ptr [EBP + 0x8],ECX
4542cfaa CALL dword ptr [EBP + 0x14]
4542cfad JMP 0x4542cf9c
4542cfdb MOV dword ptr [EBP + -0x4],0xfffffffe
4542cfe2 CALL 0x45434145
4542cfe7 RET 0x10

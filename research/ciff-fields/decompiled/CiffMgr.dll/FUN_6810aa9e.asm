6810aa9e PUSH 0x4
6810aaa0 MOV EAX,0x681430cd
6810aaa5 CALL 0x681320f5
6810aaaa MOV ESI,ECX
6810aaac MOV dword ptr [EBP + -0x10],ESI
6810aaaf MOV dword ptr [ESI],0x68148dc4
6810aab5 AND dword ptr [EBP + -0x4],0x0
6810aab9 MOV dword ptr [ESI + 0x10],0xc0000001
6810aac0 MOV ECX,dword ptr [0x6816703c]
6810aac6 MOV EAX,dword ptr [ECX]
6810aac8 CALL dword ptr [EAX + 0x8]
6810aacb OR dword ptr [EBP + -0x4],0xffffffff
6810aacf MOV ECX,ESI
6810aad1 CALL 0x6810ac1d
6810aad6 CALL 0x681320c3
6810aadb RET

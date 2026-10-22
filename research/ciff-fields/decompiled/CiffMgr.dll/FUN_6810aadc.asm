6810aadc PUSH 0x4
6810aade MOV EAX,0x681430f0
6810aae3 CALL 0x681320f5
6810aae8 MOV ESI,ECX
6810aaea MOV dword ptr [EBP + -0x10],ESI
6810aaed MOV dword ptr [ESI],0x68148cb0
6810aaf3 AND dword ptr [EBP + -0x4],0x0
6810aaf7 MOV dword ptr [ESI + 0x10],0xc0000001
6810aafe MOV ECX,dword ptr [0x6816703c]
6810ab04 MOV EAX,dword ptr [ECX]
6810ab06 CALL dword ptr [EAX + 0x8]
6810ab09 OR dword ptr [EBP + -0x4],0xffffffff
6810ab0d MOV ECX,ESI
6810ab0f CALL 0x6810acbf
6810ab14 CALL 0x681320c3
6810ab19 RET

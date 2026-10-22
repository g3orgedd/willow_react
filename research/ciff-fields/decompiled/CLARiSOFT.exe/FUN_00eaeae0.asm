00eaeae0 PUSH 0x0
00eaeae2 MOV EAX,0xef7e91
00eaeae7 CALL 0x00ec9e5a
00eaeaec MOV EAX,dword ptr [EBP + 0x10]
00eaeaef LEA EDX,[EBP + 0xc]
00eaeaf2 AND dword ptr [EBP + -0x4],0x0
00eaeaf6 CMP dword ptr [EBP + 0xc],0x1
00eaeafa PUSH EDX
00eaeafb MOV ECX,dword ptr [EAX]
00eaeafd PUSH EAX
00eaeafe JNZ 0x00eaeb05
00eaeb00 CALL dword ptr [ECX + 0x2c]
00eaeb03 JMP 0x00eaeb08
00eaeb05 CALL dword ptr [ECX + 0x34]
00eaeb08 MOVD XMM0,dword ptr [EBP + 0x8]
00eaeb0d CVTDQ2PS XMM0,XMM0
00eaeb10 PUSH ECX
00eaeb11 MULSS XMM0,dword ptr [EBP + 0xc]
00eaeb16 MOVSS dword ptr [ESP],XMM0
00eaeb1b CALL 0x00e34198
00eaeb20 OR dword ptr [EBP + -0x4],0xffffffff
00eaeb24 MOV ESI,EAX
00eaeb26 POP ECX
00eaeb27 MOV ECX,dword ptr [EBP + 0x10]
00eaeb2a TEST ECX,ECX
00eaeb2c JZ 0x00eaeb34
00eaeb2e MOV EDX,dword ptr [ECX]
00eaeb30 PUSH ECX
00eaeb31 CALL dword ptr [EDX + 0x8]
00eaeb34 MOV EAX,ESI
00eaeb36 CALL 0x00ec9e28
00eaeb3b RET

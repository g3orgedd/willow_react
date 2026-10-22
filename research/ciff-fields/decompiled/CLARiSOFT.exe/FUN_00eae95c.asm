00eae95c PUSH 0x0
00eae95e MOV EAX,0xef7e91
00eae963 CALL 0x00ec9e5a
00eae968 MOV EAX,dword ptr [EBP + 0x10]
00eae96b LEA EDX,[EBP + 0xc]
00eae96e AND dword ptr [EBP + -0x4],0x0
00eae972 CMP dword ptr [EBP + 0xc],0x1
00eae976 PUSH EDX
00eae977 MOV ECX,dword ptr [EAX]
00eae979 PUSH EAX
00eae97a JNZ 0x00eae981
00eae97c CALL dword ptr [ECX + 0x2c]
00eae97f JMP 0x00eae984
00eae981 CALL dword ptr [ECX + 0x34]
00eae984 MOVD XMM0,dword ptr [EBP + 0x8]
00eae989 CVTDQ2PS XMM0,XMM0
00eae98c PUSH ECX
00eae98d DIVSS XMM0,dword ptr [EBP + 0xc]
00eae992 MOVSS dword ptr [ESP],XMM0
00eae997 CALL 0x00e34198
00eae99c OR dword ptr [EBP + -0x4],0xffffffff
00eae9a0 MOV ESI,EAX
00eae9a2 POP ECX
00eae9a3 MOV ECX,dword ptr [EBP + 0x10]
00eae9a6 TEST ECX,ECX
00eae9a8 JZ 0x00eae9b0
00eae9aa MOV EDX,dword ptr [ECX]
00eae9ac PUSH ECX
00eae9ad CALL dword ptr [EDX + 0x8]
00eae9b0 MOV EAX,ESI
00eae9b2 CALL 0x00ec9e28
00eae9b7 RET

4502bbc9 PUSH EBP
4502bbca MOV EBP,ESP
4502bbcc MOV EDX,dword ptr [EBP + 0xc]
4502bbcf TEST byte ptr [EDX + 0xc],0x40
4502bbd3 JZ 0x4502bbdb
4502bbd5 CMP dword ptr [EDX + 0x8],0x0
4502bbd9 JZ 0x4502bc0a
4502bbdb DEC dword ptr [EDX + 0x4]
4502bbde JS 0x4502bbee
4502bbe0 MOV EAX,dword ptr [EDX]
4502bbe2 MOV CL,byte ptr [EBP + 0x8]
4502bbe5 MOV byte ptr [EAX],CL
4502bbe7 INC dword ptr [EDX]
4502bbe9 MOVZX EAX,CL
4502bbec JMP 0x4502bbfd
4502bbee MOV EAX,dword ptr [EBP + 0x8]
4502bbf1 PUSH EDX
4502bbf2 MOVSX EAX,AL
4502bbf5 PUSH EAX
4502bbf6 CALL 0x450280b7
4502bbfb POP ECX
4502bbfc POP ECX
4502bbfd CMP EAX,-0x1
4502bc00 JNZ 0x4502bc0a
4502bc02 MOV EAX,dword ptr [EBP + 0x10]
4502bc05 OR dword ptr [EAX],0xffffffff
4502bc08 POP EBP
4502bc09 RET
4502bc0a MOV EAX,dword ptr [EBP + 0x10]
4502bc0d INC dword ptr [EAX]
4502bc0f POP EBP
4502bc10 RET

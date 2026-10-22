00eaf8d8 PUSH 0x8
00eaf8da MOV EAX,0xef81a7
00eaf8df CALL 0x00ec9e5a
00eaf8e4 MOV ESI,ECX
00eaf8e6 MOV dword ptr [EBP + -0x10],ESI
00eaf8e9 XOR EBX,EBX
00eaf8eb MOV dword ptr [ESI],0xf06a6c
00eaf8f1 LEA EDI,[ESI + 0x18]
00eaf8f4 PUSH EBX
00eaf8f5 PUSH EBX
00eaf8f6 MOV ECX,EDI
00eaf8f8 MOV dword ptr [EDI],EBX
00eaf8fa MOV dword ptr [EDI + 0x4],EBX
00eaf8fd CALL 0x00e461da
00eaf902 MOV dword ptr [EDI],EAX
00eaf904 MOV dword ptr [EBP + -0x4],EBX
00eaf907 MOV dword ptr [ESI + 0x20],EBX
00eaf90a PUSH 0xc
00eaf90c MOV byte ptr [EBP + -0x4],0x1
00eaf910 CALL 0x00eca369
00eaf915 POP ECX
00eaf916 MOV dword ptr [EBP + -0x14],EAX
00eaf919 MOV byte ptr [EBP + -0x4],0x2
00eaf91d TEST EAX,EAX
00eaf91f JZ 0x00eaf92a
00eaf921 MOV ECX,EAX
00eaf923 CALL 0x00e4b2e4
00eaf928 JMP 0x00eaf92c
00eaf92a MOV EAX,EBX
00eaf92c PUSH 0xc
00eaf92e MOV byte ptr [EBP + -0x4],0x1
00eaf932 MOV dword ptr [ESI + 0xc],EAX
00eaf935 CALL 0x00eca369
00eaf93a POP ECX
00eaf93b MOV dword ptr [EBP + -0x14],EAX
00eaf93e MOV byte ptr [EBP + -0x4],0x3
00eaf942 TEST EAX,EAX
00eaf944 JZ 0x00eaf94f
00eaf946 MOV ECX,EAX
00eaf948 CALL 0x00eaf85b
00eaf94d JMP 0x00eaf951
00eaf94f MOV EAX,EBX
00eaf951 MOV ECX,ESI
00eaf953 MOV byte ptr [EBP + -0x4],0x1
00eaf957 MOV dword ptr [ESI + 0x10],EAX
00eaf95a CALL 0x00eb7275
00eaf95f MOV dword ptr [ESI + 0x4],EBX
00eaf962 MOV dword ptr [ESI + 0x8],EBX
00eaf965 MOV dword ptr [ESI + 0x14],EBX
00eaf968 CALL dword ptr [0x00efc1c4]
00eaf96e PUSH EAX
00eaf96f PUSH 0xc00000
00eaf974 PUSH EDI
00eaf975 CALL 0x00eb70d6
00eaf97a ADD ESP,0xc
00eaf97d MOV EAX,ESI
00eaf97f CALL 0x00ec9e28
00eaf984 RET

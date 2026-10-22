4502cc6e PUSH EBP
4502cc6f MOV EBP,ESP
4502cc71 MOV EAX,dword ptr [EBP + 0x14]
4502cc74 CMP EAX,0x65
4502cc77 JZ 0x4502ccd8
4502cc79 CMP EAX,0x45
4502cc7c JZ 0x4502ccd8
4502cc7e CMP EAX,0x66
4502cc81 JNZ 0x4502cc9c
4502cc83 PUSH dword ptr [EBP + 0x20]
4502cc86 PUSH dword ptr [EBP + 0x18]
4502cc89 PUSH dword ptr [EBP + 0x10]
4502cc8c PUSH dword ptr [EBP + 0xc]
4502cc8f PUSH dword ptr [EBP + 0x8]
4502cc92 CALL 0x4502d379
4502cc97 ADD ESP,0x14
4502cc9a POP EBP
4502cc9b RET
4502cc9c CMP EAX,0x61
4502cc9f JZ 0x4502ccbf
4502cca1 CMP EAX,0x41
4502cca4 JZ 0x4502ccbf
4502cca6 PUSH dword ptr [EBP + 0x20]
4502cca9 PUSH dword ptr [EBP + 0x1c]
4502ccac PUSH dword ptr [EBP + 0x18]
4502ccaf PUSH dword ptr [EBP + 0x10]
4502ccb2 PUSH dword ptr [EBP + 0xc]
4502ccb5 PUSH dword ptr [EBP + 0x8]
4502ccb8 CALL 0x4502d43a
4502ccbd JMP 0x4502ccef
4502ccbf PUSH dword ptr [EBP + 0x20]
4502ccc2 PUSH dword ptr [EBP + 0x1c]
4502ccc5 PUSH dword ptr [EBP + 0x18]
4502ccc8 PUSH dword ptr [EBP + 0x10]
4502cccb PUSH dword ptr [EBP + 0xc]
4502ccce PUSH dword ptr [EBP + 0x8]
4502ccd1 CALL 0x4502ccf4
4502ccd6 JMP 0x4502ccef
4502ccd8 PUSH dword ptr [EBP + 0x20]
4502ccdb PUSH dword ptr [EBP + 0x1c]
4502ccde PUSH dword ptr [EBP + 0x18]
4502cce1 PUSH dword ptr [EBP + 0x10]
4502cce4 PUSH dword ptr [EBP + 0xc]
4502cce7 PUSH dword ptr [EBP + 0x8]
4502ccea CALL 0x4502d1bf
4502ccef ADD ESP,0x18
4502ccf2 POP EBP
4502ccf3 RET

00e4aee3 PUSH EBP
00e4aee4 MOV EBP,ESP
00e4aee6 PUSH EBX
00e4aee7 PUSH ESI
00e4aee8 MOV ESI,dword ptr [EBP + 0x8]
00e4aeeb MOV EBX,ECX
00e4aeed PUSH EDI
00e4aeee PUSH dword ptr [EBP + 0xc]
00e4aef1 PUSH dword ptr [ESI + 0x4]
00e4aef4 PUSH ESI
00e4aef5 CALL 0x00e65a7f
00e4aefa PUSH 0x1
00e4aefc MOV ECX,EBX
00e4aefe MOV EDI,EAX
00e4af00 CALL 0x00ebf4de
00e4af05 MOV dword ptr [ESI + 0x4],EDI
00e4af08 MOV ECX,dword ptr [EDI + 0x4]
00e4af0b MOV dword ptr [ECX],EDI
00e4af0d POP EDI
00e4af0e POP ESI
00e4af0f POP EBX
00e4af10 POP EBP
00e4af11 RET 0x8

00eafabc PUSH 0x4
00eafabe MOV EAX,0xef821c
00eafac3 CALL 0x00ec9e5a
00eafac8 MOV ESI,ECX
00eafaca MOV dword ptr [EBP + -0x10],ESI
00eafacd MOV dword ptr [ESI],0xf06a6c
00eafad3 MOV ECX,dword ptr [ESI + 0xc]
00eafad6 XOR EDI,EDI
00eafad8 INC EDI
00eafad9 MOV dword ptr [EBP + -0x4],EDI
00eafadc TEST ECX,ECX
00eafade JZ 0x00eafae5
00eafae0 MOV EAX,dword ptr [ECX]
00eafae2 PUSH EDI
00eafae3 CALL dword ptr [EAX]
00eafae5 MOV ECX,dword ptr [ESI + 0x10]
00eafae8 TEST ECX,ECX
00eafaea JZ 0x00eafaf1
00eafaec MOV EAX,dword ptr [ECX]
00eafaee PUSH EDI
00eafaef CALL dword ptr [EAX]
00eafaf1 PUSH dword ptr [ESI + 0x20]
00eafaf4 CALL dword ptr [0x00efc448]
00eafafa LEA ECX,[ESI + 0x18]
00eafafd CALL 0x00eb76fc
00eafb02 PUSH dword ptr [ESI + 0x18]
00eafb05 CALL 0x00ec99ef
00eafb0a POP ECX
00eafb0b CALL 0x00ec9e28
00eafb10 RET

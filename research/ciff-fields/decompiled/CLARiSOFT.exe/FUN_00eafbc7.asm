00eafbc7 PUSH 0x0
00eafbc9 MOV EAX,0xef8241
00eafbce CALL 0x00ec9e5a
00eafbd3 MOV EBX,ECX
00eafbd5 MOV EDI,dword ptr [EBP + 0xc]
00eafbd8 PUSH EDI
00eafbd9 PUSH dword ptr [EBP + 0x8]
00eafbdc CALL 0x00eb6b0d
00eafbe1 TEST AL,AL
00eafbe3 JNZ 0x00eafc20
00eafbe5 PUSH 0x8
00eafbe7 CALL 0x00eca369
00eafbec MOV ESI,EAX
00eafbee POP ECX
00eafbef MOV dword ptr [EBP + 0xc],ESI
00eafbf2 AND dword ptr [EBP + -0x4],0x0
00eafbf6 TEST ESI,ESI
00eafbf8 JZ 0x00eafc09
00eafbfa PUSH dword ptr [EBP + 0x8]
00eafbfd LEA ECX,[ESI + 0x4]
00eafc00 MOV dword ptr [ESI],EDI
00eafc02 CALL 0x00e03ab8
00eafc07 JMP 0x00eafc0b
00eafc09 XOR ESI,ESI
00eafc0b OR dword ptr [EBP + -0x4],0xffffffff
00eafc0f LEA EAX,[EBP + 0x8]
00eafc12 LEA ECX,[EBX + 0x4]
00eafc15 MOV dword ptr [EBP + 0x8],ESI
00eafc18 PUSH EAX
00eafc19 PUSH dword ptr [ECX]
00eafc1b CALL 0x00e4aee3
00eafc20 CALL 0x00ec9e28
00eafc25 RET 0x8

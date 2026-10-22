00e09bd0 PUSH 0xc
00e09bd2 MOV EAX,0xee7191
00e09bd7 CALL 0x00ec9ec3
00e09bdc MOV ESI,ECX
00e09bde MOV dword ptr [EBP + -0x18],ESI
00e09be1 XOR EBX,EBX
00e09be3 MOV dword ptr [ESI],EBX
00e09be5 MOV dword ptr [ESI + 0x4],EBX
00e09be8 CALL 0x00e0d17e
00e09bed MOV dword ptr [ESI],EAX
00e09bef MOV byte ptr [EBP + -0x14],BL
00e09bf2 MOV ECX,ESI
00e09bf4 PUSH dword ptr [EBP + -0x14]
00e09bf7 MOV dword ptr [EBP + -0x4],EBX
00e09bfa PUSH dword ptr [EBP + 0x8]
00e09bfd MOV byte ptr [EBP + -0x4],0x1
00e09c01 CALL 0x00e0835a
00e09c06 MOV EAX,ESI
00e09c08 CALL 0x00ec9e28
00e09c0d RET 0x8

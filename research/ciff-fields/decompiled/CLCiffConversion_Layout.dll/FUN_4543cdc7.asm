4543cdc7 PUSH EBP
4543cdc8 MOV EBP,ESP
4543cdca INC dword ptr [0x454616d4]
4543cdd0 PUSH ESI
4543cdd1 MOV ESI,0x1000
4543cdd6 PUSH ESI
4543cdd7 CALL 0x4543760c
4543cddc POP ECX
4543cddd MOV ECX,dword ptr [EBP + 0x8]
4543cde0 MOV dword ptr [ECX + 0x8],EAX
4543cde3 TEST EAX,EAX
4543cde5 JZ 0x4543cdf0
4543cde7 OR dword ptr [ECX + 0xc],0x8
4543cdeb MOV dword ptr [ECX + 0x18],ESI
4543cdee JMP 0x4543ce01
4543cdf0 OR dword ptr [ECX + 0xc],0x4
4543cdf4 LEA EAX,[ECX + 0x14]
4543cdf7 MOV dword ptr [ECX + 0x8],EAX
4543cdfa MOV dword ptr [ECX + 0x18],0x2
4543ce01 MOV EAX,dword ptr [ECX + 0x8]
4543ce04 AND dword ptr [ECX + 0x4],0x0
4543ce08 MOV dword ptr [ECX],EAX
4543ce0a POP ESI
4543ce0b POP EBP
4543ce0c RET

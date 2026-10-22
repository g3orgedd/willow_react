00ecd0ef PUSH EBP
00ecd0f0 MOV EBP,ESP
00ecd0f2 PUSH ECX
00ecd0f3 CMP dword ptr [EBP + 0x14],0x0
00ecd0f7 JNZ 0x00ecd111
00ecd0f9 CALL 0x00ed1b43
00ecd0fe MOV dword ptr [EAX],0x16
00ecd104 CALL 0x00ed2f39
00ecd109 OR EAX,0xffffffff
00ecd10c JMP 0x00ecd1eb
00ecd111 PUSH EBX
00ecd112 PUSH ESI
00ecd113 MOV ESI,dword ptr [EBP + 0x8]
00ecd116 PUSH EDI
00ecd117 MOV EDI,dword ptr [EBP + 0x10]
00ecd11a TEST EDI,EDI
00ecd11c JNZ 0x00ecd132
00ecd11e TEST ESI,ESI
00ecd120 JNZ 0x00ecd13a
00ecd122 CMP dword ptr [EBP + 0xc],ESI
00ecd125 JNZ 0x00ecd1d5
00ecd12b XOR EAX,EAX
00ecd12d JMP 0x00ecd1e8
00ecd132 TEST ESI,ESI
00ecd134 JZ 0x00ecd1d5
00ecd13a MOV EBX,dword ptr [EBP + 0xc]
00ecd13d TEST EBX,EBX
00ecd13f JZ 0x00ecd1d5
00ecd145 CALL 0x00ed1b43
00ecd14a PUSH dword ptr [EBP + 0x1c]
00ecd14d PUSH dword ptr [EBP + 0x18]
00ecd150 PUSH dword ptr [EBP + 0x14]
00ecd153 CMP EBX,EDI
00ecd155 JBE 0x00ecd183
00ecd157 MOV EBX,dword ptr [EAX]
00ecd159 LEA EAX,[EDI + 0x1]
00ecd15c PUSH EAX
00ecd15d PUSH ESI
00ecd15e PUSH 0xed6ca2
00ecd163 CALL 0x00ecd007
00ecd168 ADD ESP,0x18
00ecd16b CMP EAX,-0x2
00ecd16e JNZ 0x00ecd1bc
00ecd170 CALL 0x00ed1b43
00ecd175 CMP dword ptr [EAX],0x22
00ecd178 JNZ 0x00ecd1e5
00ecd17a CALL 0x00ed1b43
00ecd17f MOV dword ptr [EAX],EBX
00ecd181 JMP 0x00ecd1e5
00ecd183 MOV EAX,dword ptr [EAX]
00ecd185 PUSH EBX
00ecd186 PUSH ESI
00ecd187 PUSH 0xed6ca2
00ecd18c MOV dword ptr [EBP + -0x4],EAX
00ecd18f CALL 0x00ecd007
00ecd194 ADD ESP,0x18
00ecd197 MOV byte ptr [ESI + EBX*0x1 + -0x1],0x0
00ecd19c CMP EAX,-0x2
00ecd19f JNZ 0x00ecd1bc
00ecd1a1 CMP EDI,-0x1
00ecd1a4 JNZ 0x00ecd1c0
00ecd1a6 CALL 0x00ed1b43
00ecd1ab CMP dword ptr [EAX],0x22
00ecd1ae JNZ 0x00ecd1e5
00ecd1b0 CALL 0x00ed1b43
00ecd1b5 MOV ECX,dword ptr [EBP + -0x4]
00ecd1b8 MOV dword ptr [EAX],ECX
00ecd1ba JMP 0x00ecd1e5
00ecd1bc TEST EAX,EAX
00ecd1be JNS 0x00ecd1e8
00ecd1c0 MOV byte ptr [ESI],0x0
00ecd1c3 CMP EAX,-0x2
00ecd1c6 JNZ 0x00ecd1e5
00ecd1c8 CALL 0x00ed1b43
00ecd1cd MOV dword ptr [EAX],0x22
00ecd1d3 JMP 0x00ecd1e0
00ecd1d5 CALL 0x00ed1b43
00ecd1da MOV dword ptr [EAX],0x16
00ecd1e0 CALL 0x00ed2f39
00ecd1e5 OR EAX,0xffffffff
00ecd1e8 POP EDI
00ecd1e9 POP ESI
00ecd1ea POP EBX
00ecd1eb MOV ESP,EBP
00ecd1ed POP EBP
00ecd1ee RET

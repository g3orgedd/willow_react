00ec9dc5 PUSH EBP
00ec9dc6 MOV EBP,ESP
00ec9dc8 SUB ESP,0x20
00ec9dcb PUSH ESI
00ec9dcc PUSH EDI
00ec9dcd PUSH 0x8
00ec9dcf POP ECX
00ec9dd0 MOV ESI,0xf0a3b0
00ec9dd5 LEA EDI,[EBP + -0x20]
00ec9dd8 MOVSD.REP ES:EDI,ESI
00ec9dda MOV ESI,dword ptr [EBP + 0xc]
00ec9ddd MOV EDI,dword ptr [EBP + 0x8]
00ec9de0 TEST ESI,ESI
00ec9de2 JZ 0x00ec9df7
00ec9de4 TEST byte ptr [ESI],0x10
00ec9de7 JZ 0x00ec9df7
00ec9de9 MOV ECX,dword ptr [EDI]
00ec9deb SUB ECX,0x4
00ec9dee PUSH ECX
00ec9def MOV EAX,dword ptr [ECX]
00ec9df1 MOV ESI,dword ptr [EAX + 0x18]
00ec9df4 CALL dword ptr [EAX + 0x20]
00ec9df7 MOV dword ptr [EBP + -0x8],EDI
00ec9dfa MOV dword ptr [EBP + -0x4],ESI
00ec9dfd TEST ESI,ESI
00ec9dff JZ 0x00ec9e0d
00ec9e01 TEST byte ptr [ESI],0x8
00ec9e04 JZ 0x00ec9e0d
00ec9e06 MOV dword ptr [EBP + -0xc],0x1994000
00ec9e0d LEA EAX,[EBP + -0xc]
00ec9e10 PUSH EAX
00ec9e11 PUSH dword ptr [EBP + -0x10]
00ec9e14 PUSH dword ptr [EBP + -0x1c]
00ec9e17 PUSH dword ptr [EBP + -0x20]
00ec9e1a CALL dword ptr [0x00efc388]
00ec9e20 POP EDI
00ec9e21 POP ESI
00ec9e22 MOV ESP,EBP
00ec9e24 POP EBP
00ec9e25 RET 0x8

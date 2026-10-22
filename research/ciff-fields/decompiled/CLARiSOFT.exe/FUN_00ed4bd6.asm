00ed4bd6 PUSH 0x8
00ed4bd8 PUSH 0xf31990
00ed4bdd CALL 0x00ed4ea0
00ed4be2 MOV ESI,dword ptr [EBP + 0x8]
00ed4be5 MOV dword ptr [ESI + 0x5c],0xf0dfd0
00ed4bec AND dword ptr [ESI + 0x8],0x0
00ed4bf0 XOR EDI,EDI
00ed4bf2 INC EDI
00ed4bf3 MOV dword ptr [ESI + 0x14],EDI
00ed4bf6 MOV dword ptr [ESI + 0x70],EDI
00ed4bf9 PUSH 0x43
00ed4bfb POP EAX
00ed4bfc MOV word ptr [ESI + 0xb8],AX
00ed4c03 MOV word ptr [ESI + 0x1be],AX
00ed4c0a MOV dword ptr [ESI + 0x68],0xf38b08
00ed4c11 AND dword ptr [ESI + 0x3b8],0x0
00ed4c18 PUSH 0xd
00ed4c1a CALL 0x00ed03bd
00ed4c1f POP ECX
00ed4c20 AND dword ptr [EBP + -0x4],0x0
00ed4c24 MOV EAX,dword ptr [ESI + 0x68]
00ed4c27 MOV ECX,EDI
00ed4c29 XADD.LOCK dword ptr [EAX],ECX
00ed4c2d MOV dword ptr [EBP + -0x4],0xfffffffe
00ed4c34 CALL 0x00ed4c77
00ed4c39 PUSH 0xc
00ed4c3b CALL 0x00ed03bd
00ed4c40 POP ECX
00ed4c41 MOV dword ptr [EBP + -0x4],EDI
00ed4c44 MOV EAX,dword ptr [EBP + 0xc]
00ed4c47 MOV dword ptr [ESI + 0x6c],EAX
00ed4c4a TEST EAX,EAX
00ed4c4c JNZ 0x00ed4c56
00ed4c4e MOV EAX,[0x00f38f8c]
00ed4c53 MOV dword ptr [ESI + 0x6c],EAX
00ed4c56 PUSH dword ptr [ESI + 0x6c]
00ed4c59 CALL 0x00ed4ef9
00ed4c5e POP ECX
00ed4c5f MOV dword ptr [EBP + -0x4],0xfffffffe
00ed4c66 CALL 0x00ed4c80
00ed4c6b CALL 0x00ed4ee5
00ed4c70 RET

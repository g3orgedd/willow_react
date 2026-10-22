4144dc7d PUSH ESI
4144dc7e MOV ESI,ECX
4144dc80 PUSH EDI
4144dc81 XOR EDI,EDI
4144dc83 CMP dword ptr [ESI + 0x10],EDI
4144dc86 JZ 0x4144dc99
4144dc88 CMP dword ptr [ESI + 0x14],EDI
4144dc8b JZ 0x4144dc99
4144dc8d PUSH dword ptr [ESI + 0x14]
4144dc90 PUSH dword ptr [ESI + 0xc]
4144dc93 CALL dword ptr [0x41480090]
4144dc99 PUSH dword ptr [ESI + 0xc]
4144dc9c CALL dword ptr [0x414800bc]
4144dca2 CMP dword ptr [ESI + 0x10],EDI
4144dca5 JZ 0x4144dcb0
4144dca7 PUSH dword ptr [ESI + 0x10]
4144dcaa CALL dword ptr [0x41480088]
4144dcb0 MOV dword ptr [ESI + 0xc],EDI
4144dcb3 MOV dword ptr [ESI + 0x10],EDI
4144dcb6 MOV dword ptr [ESI + 0x14],EDI
4144dcb9 MOV dword ptr [ESI + 0x18],EDI
4144dcbc MOV dword ptr [ESI + 0x4],EDI
4144dcbf MOV dword ptr [ESI + 0x8],EDI
4144dcc2 MOV dword ptr [ESI + 0x1c],EDI
4144dcc5 POP EDI
4144dcc6 POP ESI
4144dcc7 RET

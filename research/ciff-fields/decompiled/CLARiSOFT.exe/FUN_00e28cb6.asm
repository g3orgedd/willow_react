00e28cb6 PUSH 0x4
00e28cb8 MOV EAX,0xee6dc5
00e28cbd CALL 0x00ec9e5a
00e28cc2 XOR EDX,EDX
00e28cc4 MOV dword ptr [EBP + -0x10],EDX
00e28cc7 MOV EDI,dword ptr [EBP + 0x8]
00e28cca MOV EAX,[0x00f35014]
00e28ccf MOV dword ptr [EDI],EAX
00e28cd1 MOV dword ptr [EBP + -0x4],EDX
00e28cd4 MOV dword ptr [EBP + -0x10],0x1
00e28cdb CMP dword ptr [EBP + 0x10],EDX
00e28cde JZ 0x00e28ceb
00e28ce0 PUSH dword ptr [EBP + 0x10]
00e28ce3 CALL dword ptr [0x00efc3b4]
00e28ce9 MOV EDX,EAX
00e28ceb MOV ECX,dword ptr [EBP + 0xc]
00e28cee PUSH dword ptr [EBP + 0x10]
00e28cf1 PUSH EDX
00e28cf2 MOV ECX,dword ptr [ECX]
00e28cf4 PUSH ECX
00e28cf5 PUSH dword ptr [ECX + -0x8]
00e28cf8 MOV ECX,EDI
00e28cfa CALL 0x00e04e44
00e28cff MOV EAX,EDI
00e28d01 CALL 0x00ec9e28
00e28d06 RET 0xc

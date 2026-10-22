4541cdb6 PUSH 0x4
4541cdb8 MOV EAX,0x454450f7
4541cdbd CALL 0x4542a975
4541cdc2 XOR EAX,EAX
4541cdc4 MOV dword ptr [EBP + -0x10],EAX
4541cdc7 MOV ESI,dword ptr [EBP + 0x8]
4541cdca MOV dword ptr [ESI],EAX
4541cdcc MOV ECX,dword ptr [ECX + 0x4]
4541cdcf PUSH ESI
4541cdd0 PUSH ECX
4541cdd1 MOV dword ptr [EBP + -0x4],EAX
4541cdd4 MOV EDX,dword ptr [ECX]
4541cdd6 MOV dword ptr [EBP + -0x10],0x1
4541cddd CALL dword ptr [EDX + 0xa8]
4541cde3 MOV EAX,ESI
4541cde5 CALL 0x4542a943
4541cdea RET 0x4

4541cbbe PUSH 0x4
4541cbc0 MOV EAX,0x454450f7
4541cbc5 CALL 0x4542a975
4541cbca XOR EAX,EAX
4541cbcc MOV dword ptr [EBP + -0x10],EAX
4541cbcf MOV ESI,dword ptr [EBP + 0x8]
4541cbd2 MOV dword ptr [ESI],EAX
4541cbd4 MOV ECX,dword ptr [ECX + 0x4]
4541cbd7 PUSH ESI
4541cbd8 PUSH ECX
4541cbd9 MOV dword ptr [EBP + -0x4],EAX
4541cbdc MOV EDX,dword ptr [ECX]
4541cbde MOV dword ptr [EBP + -0x10],0x1
4541cbe5 CALL dword ptr [EDX + 0x1c]
4541cbe8 MOV EAX,ESI
4541cbea CALL 0x4542a943
4541cbef RET 0x4

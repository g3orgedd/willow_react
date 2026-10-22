4502be52 PUSH 0x30
4502be54 PUSH 0x4504fbe0
4502be59 CALL 0x45026c30
4502be5e MOV EAX,dword ptr [EBP + 0x18]
4502be61 MOV dword ptr [EBP + -0x1c],EAX
4502be64 XOR EBX,EBX
4502be66 MOV dword ptr [EBP + -0x38],EBX
4502be69 MOV EDI,dword ptr [EBP + 0xc]
4502be6c MOV EAX,dword ptr [EDI + -0x4]
4502be6f MOV dword ptr [EBP + -0x28],EAX
4502be72 MOV ESI,dword ptr [EBP + 0x8]
4502be75 PUSH dword ptr [ESI + 0x18]
4502be78 LEA EAX,[EBP + -0x40]
4502be7b PUSH EAX
4502be7c CALL 0x450232c1
4502be81 POP ECX
4502be82 POP ECX
4502be83 MOV dword ptr [EBP + -0x2c],EAX
4502be86 CALL 0x45027957
4502be8b MOV EAX,dword ptr [EAX + 0x88]
4502be91 MOV dword ptr [EBP + -0x30],EAX
4502be94 CALL 0x45027957
4502be99 MOV EAX,dword ptr [EAX + 0x8c]
4502be9f MOV dword ptr [EBP + -0x34],EAX
4502bea2 CALL 0x45027957
4502bea7 MOV dword ptr [EAX + 0x88],ESI
4502bead CALL 0x45027957
4502beb2 MOV ECX,dword ptr [EBP + 0x10]
4502beb5 MOV dword ptr [EAX + 0x8c],ECX
4502bebb MOV dword ptr [EBP + -0x4],EBX
4502bebe XOR EAX,EAX
4502bec0 INC EAX
4502bec1 MOV dword ptr [EBP + 0x10],EAX
4502bec4 MOV dword ptr [EBP + -0x4],EAX
4502bec7 PUSH dword ptr [EBP + 0x20]
4502beca PUSH dword ptr [EBP + 0x1c]
4502becd PUSH dword ptr [EBP + 0x18]
4502bed0 PUSH dword ptr [EBP + 0x14]
4502bed3 PUSH EDI
4502bed4 CALL 0x4502307e
4502bed9 ADD ESP,0x14
4502bedc MOV dword ptr [EBP + -0x1c],EAX
4502bedf MOV dword ptr [EBP + -0x4],EBX
4502bee2 JMP 0x4502bf78
4502bf78 MOV dword ptr [EBP + -0x4],0xfffffffe
4502bf7f MOV dword ptr [EBP + 0x10],0x0
4502bf86 CALL 0x4502bf99
4502bf8b MOV EAX,EDI
4502bf8d CALL 0x45026c75
4502bf92 RET

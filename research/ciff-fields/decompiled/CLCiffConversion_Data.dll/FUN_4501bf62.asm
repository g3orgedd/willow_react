4501bf62 PUSH 0x8
4501bf64 MOV EAX,0x4503c0fd
4501bf69 CALL 0x45022ed6
4501bf6e MOV EDI,dword ptr [EBP + 0x8]
4501bf71 XOR ESI,ESI
4501bf73 MOV EAX,dword ptr [EBP + 0xc]
4501bf76 MOV dword ptr [EBP + -0x4],ESI
4501bf79 MOV dword ptr [EDI + 0x4],ESI
4501bf7c MOV dword ptr [EDI],ESI
4501bf7e TEST EAX,EAX
4501bf80 JZ 0x4501bfbe
4501bf82 MOV dword ptr [EBP + 0x8],ESI
4501bf85 LEA EDX,[EBP + 0x8]
4501bf88 MOV ECX,dword ptr [EAX]
4501bf8a PUSH EDX
4501bf8b PUSH EAX
4501bf8c CALL dword ptr [ECX + 0xc4]
4501bf92 CMP dword ptr [EBP + 0x8],ESI
4501bf95 JNZ 0x4501bfbb
4501bf97 MOV EBX,ESI
4501bf99 MOV dword ptr [EBP + -0x10],ESI
4501bf9c MOV dword ptr [EBP + -0x14],EBX
4501bf9f CALL 0x45003392
4501bfa4 TEST EAX,EAX
4501bfa6 JZ 0x4501bfb6
4501bfa8 LEA ECX,[EBP + -0x14]
4501bfab CALL 0x45003ecd
4501bfb0 MOV ESI,dword ptr [EBP + -0x10]
4501bfb3 MOV EBX,dword ptr [EBP + -0x14]
4501bfb6 MOV dword ptr [EDI],EBX
4501bfb8 MOV dword ptr [EDI + 0x4],ESI
4501bfbb MOV EAX,dword ptr [EBP + 0xc]
4501bfbe OR dword ptr [EBP + -0x4],0xffffffff
4501bfc2 TEST EAX,EAX
4501bfc4 JZ 0x4501bfcc
4501bfc6 MOV ECX,dword ptr [EAX]
4501bfc8 PUSH EAX
4501bfc9 CALL dword ptr [ECX + 0x8]
4501bfcc MOV EAX,EDI
4501bfce CALL 0x45022ea4
4501bfd3 RET

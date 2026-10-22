00eaf51f PUSH 0x28
00eaf521 MOV EAX,0xef80f5
00eaf526 CALL 0x00ec9e5a
00eaf52b MOV ESI,dword ptr [EBP + 0x8]
00eaf52e CMP dword ptr [ESI],0x0
00eaf531 JNZ 0x00eaf53a
00eaf533 XOR AL,AL
00eaf535 JMP 0x00eaf60d
00eaf53a LEA ECX,[EBP + -0x34]
00eaf53d XOR BL,BL
00eaf53f CALL 0x00e03b51
00eaf544 MOV EAX,dword ptr [ESI]
00eaf546 LEA EDX,[EBP + -0x34]
00eaf549 AND dword ptr [EBP + -0x4],0x0
00eaf54d PUSH EDX
00eaf54e PUSH EAX
00eaf54f MOV ECX,dword ptr [EAX]
00eaf551 CALL dword ptr [ECX + 0x47c]
00eaf557 MOV ESI,EAX
00eaf559 TEST ESI,ESI
00eaf55b JS 0x00eaf601
00eaf561 CMP dword ptr [EBP + -0x2c],0x0
00eaf565 JZ 0x00eaf601
00eaf56b PUSH dword ptr [EBP + -0x2c]
00eaf56e LEA ECX,[EBP + -0x14]
00eaf571 CALL 0x00eae5fb
00eaf576 LEA ECX,[EBP + -0x24]
00eaf579 CALL 0x00e03b51
00eaf57e MOV EAX,dword ptr [EBP + -0x14]
00eaf581 MOV byte ptr [EBP + -0x4],0x2
00eaf585 TEST EAX,EAX
00eaf587 JZ 0x00eaf597
00eaf589 MOV ECX,dword ptr [EAX]
00eaf58b LEA EDX,[EBP + -0x24]
00eaf58e PUSH EDX
00eaf58f PUSH 0x1
00eaf591 PUSH EAX
00eaf592 CALL dword ptr [ECX + 0x20]
00eaf595 MOV ESI,EAX
00eaf597 TEST ESI,ESI
00eaf599 JS 0x00eaf5e6
00eaf59b CMP dword ptr [EBP + -0x1c],0x0
00eaf59f JZ 0x00eaf5e6
00eaf5a1 PUSH dword ptr [EBP + -0x1c]
00eaf5a4 LEA ECX,[EBP + 0x8]
00eaf5a7 CALL 0x00eae5d2
00eaf5ac MOV EAX,dword ptr [EBP + 0x8]
00eaf5af MOV byte ptr [EBP + -0x4],0x3
00eaf5b3 TEST EAX,EAX
00eaf5b5 JZ 0x00eaf5d8
00eaf5b7 AND dword ptr [EBP + -0x10],0x0
00eaf5bb LEA EDX,[EBP + -0x10]
00eaf5be MOV ECX,dword ptr [EAX]
00eaf5c0 PUSH EDX
00eaf5c1 PUSH EAX
00eaf5c2 CALL dword ptr [ECX + 0x74]
00eaf5c5 TEST EAX,EAX
00eaf5c7 JS 0x00eaf5d3
00eaf5c9 CMP dword ptr [EBP + -0x10],0x1
00eaf5cd JNZ 0x00eaf5d3
00eaf5cf MOV BL,0x1
00eaf5d1 JMP 0x00eaf5d5
00eaf5d3 XOR BL,BL
00eaf5d5 MOV EAX,dword ptr [EBP + 0x8]
00eaf5d8 MOV byte ptr [EBP + -0x4],0x2
00eaf5dc TEST EAX,EAX
00eaf5de JZ 0x00eaf5e6
00eaf5e0 MOV ECX,dword ptr [EAX]
00eaf5e2 PUSH EAX
00eaf5e3 CALL dword ptr [ECX + 0x8]
00eaf5e6 LEA EAX,[EBP + -0x24]
00eaf5e9 PUSH EAX
00eaf5ea CALL dword ptr [0x00efc408]
00eaf5f0 MOV ECX,dword ptr [EBP + -0x14]
00eaf5f3 MOV byte ptr [EBP + -0x4],0x0
00eaf5f7 TEST ECX,ECX
00eaf5f9 JZ 0x00eaf601
00eaf5fb MOV EDX,dword ptr [ECX]
00eaf5fd PUSH ECX
00eaf5fe CALL dword ptr [EDX + 0x8]
00eaf601 LEA EAX,[EBP + -0x34]
00eaf604 PUSH EAX
00eaf605 CALL dword ptr [0x00efc408]
00eaf60b MOV AL,BL
00eaf60d CALL 0x00ec9e28
00eaf612 RET

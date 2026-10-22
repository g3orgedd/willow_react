4205deb7 PUSH 0x10
4205deb9 MOV EAX,0x42087536
4205debe CALL 0x4206a66c
4205dec3 MOV EDI,ECX
4205dec5 LEA ECX,[EBP + -0x1c]
4205dec8 CALL 0x42002e41
4205decd AND dword ptr [EBP + -0x4],0x0
4205ded1 CMP dword ptr [EDI + 0x40],0x0
4205ded5 MOV EBX,dword ptr [EBP + 0x14]
4205ded8 MOV ESI,dword ptr [EBP + 0x10]
4205dedb MOV dword ptr [EBP + -0x14],0x32
4205dee2 MOV dword ptr [EBP + -0x10],0x15
4205dee9 JZ 0x4205df43
4205deeb PUSH dword ptr [EBX]
4205deed LEA ECX,[EBP + 0x14]
4205def0 CALL 0x42033722
4205def5 MOV EAX,dword ptr [EBP + 0xc]
4205def8 MOV ECX,dword ptr [EDI + 0x40]
4205defb PUSH dword ptr [ESI]
4205defd MOV byte ptr [EBP + -0x4],0x1
4205df01 PUSH dword ptr [EAX]
4205df03 MOV EDX,dword ptr [ECX]
4205df05 PUSH dword ptr [EBX]
4205df07 CALL dword ptr [EDX + 0x4]
4205df0a MOV ECX,dword ptr [EDI + 0x40]
4205df0d LEA EAX,[EBP + -0x10]
4205df10 PUSH EAX
4205df11 LEA EAX,[EBP + 0x14]
4205df14 PUSH EAX
4205df15 CALL 0x4203407d
4205df1a MOV ECX,dword ptr [EDI + 0x40]
4205df1d MOV EAX,dword ptr [ECX]
4205df1f CALL dword ptr [EAX + 0x8]
4205df22 MOV EAX,dword ptr [EBP + 0x14]
4205df25 LEA EDX,[EBP + -0x14]
4205df28 PUSH EDX
4205df29 PUSH EAX
4205df2a MOV ECX,dword ptr [EAX]
4205df2c CALL dword ptr [ECX + 0x15c]
4205df32 MOV EAX,dword ptr [EBP + 0x14]
4205df35 MOV byte ptr [EBP + -0x4],0x0
4205df39 TEST EAX,EAX
4205df3b JZ 0x4205df43
4205df3d MOV ECX,dword ptr [EAX]
4205df3f PUSH EAX
4205df40 CALL dword ptr [ECX + 0x8]
4205df43 MOV EAX,dword ptr [EBX]
4205df45 LEA EDX,[EBP + -0x18]
4205df48 AND dword ptr [EBP + -0x18],0x0
4205df4c PUSH EDX
4205df4d PUSH EAX
4205df4e MOV ECX,dword ptr [EAX]
4205df50 CALL dword ptr [ECX + 0x108]
4205df56 CMP dword ptr [EBP + -0x18],0x1
4205df5a JNZ 0x4205df60
4205df5c ADD dword ptr [EBP + -0x10],0x8
4205df60 PUSH ECX
4205df61 MOV ECX,dword ptr [ESI]
4205df63 MOV EAX,ESP
4205df65 MOV dword ptr [EAX],ECX
4205df67 TEST ECX,ECX
4205df69 JZ 0x4205df71
4205df6b MOV EAX,dword ptr [ECX]
4205df6d PUSH ECX
4205df6e CALL dword ptr [EAX + 0x4]
4205df71 MOV EAX,dword ptr [EBP + -0x10]
4205df74 IMUL EAX,dword ptr [EBP + -0x14]
4205df78 PUSH 0x1
4205df7a PUSH EAX
4205df7b CALL 0x42003ac3
4205df80 MOV EDI,dword ptr [EBP + 0x8]
4205df83 ADD ESP,0x8
4205df86 MOV dword ptr [EDI],EAX
4205df88 MOV EAX,ESP
4205df8a MOV ECX,dword ptr [ESI]
4205df8c MOV dword ptr [EAX],ECX
4205df8e TEST ECX,ECX
4205df90 JZ 0x4205df98
4205df92 MOV EAX,dword ptr [ECX]
4205df94 PUSH ECX
4205df95 CALL dword ptr [EAX + 0x4]
4205df98 MOV EAX,dword ptr [EBP + -0x10]
4205df9b IMUL EAX,dword ptr [EBP + -0x14]
4205df9f PUSH 0x0
4205dfa1 PUSH EAX
4205dfa2 CALL 0x42003ac3
4205dfa7 OR dword ptr [EBP + -0x4],0xffffffff
4205dfab LEA ECX,[EBP + -0x1c]
4205dfae ADD ESP,0xc
4205dfb1 MOV dword ptr [EDI + 0x4],EAX
4205dfb4 CALL 0x420030e8
4205dfb9 XOR EAX,EAX
4205dfbb CALL 0x4206a63a
4205dfc0 RET 0x10

4542ad0b PUSH EBP
4542ad0c MOV EBP,ESP
4542ad0e PUSH ECX
4542ad0f PUSH ECX
4542ad10 PUSH EBX
4542ad11 PUSH ESI
4542ad12 PUSH EDI
4542ad13 MOV ESI,dword ptr FS:[0x0]
4542ad1a MOV dword ptr [EBP + -0x8],ESI
4542ad1d MOV dword ptr [EBP + -0x4],0x4542ad35
4542ad24 PUSH 0x0
4542ad26 PUSH dword ptr [EBP + 0xc]
4542ad29 PUSH dword ptr [EBP + -0x4]
4542ad2c PUSH dword ptr [EBP + 0x8]
4542ad2f CALL dword ptr [0x454471fc]
4542ad35 MOV EAX,dword ptr [EBP + 0xc]
4542ad38 MOV EAX,dword ptr [EAX + 0x4]
4542ad3b AND EAX,0xfffffffd
4542ad3e MOV ECX,dword ptr [EBP + 0xc]
4542ad41 MOV dword ptr [ECX + 0x4],EAX
4542ad44 MOV EDI,dword ptr FS:[0x0]
4542ad4b MOV EBX,dword ptr [EBP + -0x8]
4542ad4e MOV dword ptr [EBX],EDI
4542ad50 MOV dword ptr FS:[0x0],EBX
4542ad57 POP EDI
4542ad58 POP ESI
4542ad59 POP EBX
4542ad5a MOV ESP,EBP
4542ad5c POP EBP
4542ad5d RET 0x8

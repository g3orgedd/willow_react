4542acd9 PUSH EBP
4542acda MOV EBP,ESP
4542acdc PUSH ECX
4542acdd PUSH EBX
4542acde MOV EAX,dword ptr [EBP + 0xc]
4542ace1 ADD EAX,0xc
4542ace4 MOV dword ptr [EBP + -0x4],EAX
4542ace7 MOV EBX,dword ptr FS:[0x0]
4542acee MOV EAX,dword ptr [EBX]
4542acf0 MOV FS:[0x0],EAX
4542acf6 MOV EAX,dword ptr [EBP + 0x8]
4542acf9 MOV EBX,dword ptr [EBP + 0xc]
4542acfc MOV EBP,dword ptr [EBP + -0x4]
4542acff MOV ESP,dword ptr [EBX + -0x4]
4542ad02 JMP EAX

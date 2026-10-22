4202aea0 PUSH ESI
4202aea1 MOV ESI,ECX
4202aea3 MOV ECX,dword ptr [ESI + 0xf0]
4202aea9 TEST ECX,ECX
4202aeab JZ 0x4202aeba
4202aead AND dword ptr [ESI + 0xf0],0x0
4202aeb4 MOV EAX,dword ptr [ECX]
4202aeb6 PUSH ECX
4202aeb7 CALL dword ptr [EAX + 0x8]
4202aeba MOV ECX,dword ptr [ESI + 0xf4]
4202aec0 TEST ECX,ECX
4202aec2 JZ 0x4202aed1
4202aec4 AND dword ptr [ESI + 0xf4],0x0
4202aecb MOV EAX,dword ptr [ECX]
4202aecd PUSH ECX
4202aece CALL dword ptr [EAX + 0x8]
4202aed1 MOV ECX,dword ptr [ESI + 0xf8]
4202aed7 TEST ECX,ECX
4202aed9 JZ 0x4202aee8
4202aedb AND dword ptr [ESI + 0xf8],0x0
4202aee2 MOV EAX,dword ptr [ECX]
4202aee4 PUSH ECX
4202aee5 CALL dword ptr [EAX + 0x8]
4202aee8 MOV AL,0x1
4202aeea POP ESI
4202aeeb RET

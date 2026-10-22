4145cdaa PUSH 0x4
4145cdac MOV EAX,0x4147fa8c
4145cdb1 CALL 0x41461f00
4145cdb6 MOV ESI,ECX
4145cdb8 MOV dword ptr [EBP + -0x10],ESI
4145cdbb MOV dword ptr [ESI],0x4148c55c
4145cdc1 LEA ECX,[ESI + 0x154]
4145cdc7 MOV dword ptr [EBP + -0x4],0x3
4145cdce CALL 0x4145de0c
4145cdd3 MOV ECX,dword ptr [ESI + 0x140]
4145cdd9 MOV byte ptr [EBP + -0x4],0x2
4145cddd TEST ECX,ECX
4145cddf JZ 0x4145cde7
4145cde1 MOV EAX,dword ptr [ECX]
4145cde3 PUSH ECX
4145cde4 CALL dword ptr [EAX + 0x8]
4145cde7 MOV ECX,dword ptr [ESI + 0x13c]
4145cded MOV byte ptr [EBP + -0x4],0x1
4145cdf1 TEST ECX,ECX
4145cdf3 JZ 0x4145cdfb
4145cdf5 MOV EAX,dword ptr [ECX]
4145cdf7 PUSH ECX
4145cdf8 CALL dword ptr [EAX + 0x8]
4145cdfb MOV ECX,dword ptr [ESI + 0x138]
4145ce01 MOV byte ptr [EBP + -0x4],0x0
4145ce05 TEST ECX,ECX
4145ce07 JZ 0x4145ce0f
4145ce09 MOV EAX,dword ptr [ECX]
4145ce0b PUSH ECX
4145ce0c CALL dword ptr [EAX + 0x8]
4145ce0f OR dword ptr [EBP + -0x4],0xffffffff
4145ce13 MOV ECX,ESI
4145ce15 CALL 0x41407c3d
4145ce1a CALL 0x41461ece
4145ce1f RET

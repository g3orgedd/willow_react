45409c9b PUSH ESI
45409c9c MOV ESI,ECX
45409c9e MOV EAX,dword ptr [ESI]
45409ca0 PUSH dword ptr [EAX + 0x4]
45409ca3 CALL 0x45409c16
45409ca8 MOV EAX,dword ptr [ESI]
45409caa MOV dword ptr [EAX + 0x4],EAX
45409cad MOV EAX,dword ptr [ESI]
45409caf MOV dword ptr [EAX],EAX
45409cb1 MOV EAX,dword ptr [ESI]
45409cb3 MOV dword ptr [EAX + 0x8],EAX
45409cb6 AND dword ptr [ESI + 0x4],0x0
45409cba POP ESI
45409cbb RET

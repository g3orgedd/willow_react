45007aec PUSH ESI
45007aed MOV ESI,ECX
45007aef MOV EAX,dword ptr [ESI]
45007af1 PUSH dword ptr [EAX + 0x4]
45007af4 CALL 0x450079a9
45007af9 MOV EAX,dword ptr [ESI]
45007afb MOV dword ptr [EAX + 0x4],EAX
45007afe MOV EAX,dword ptr [ESI]
45007b00 MOV dword ptr [EAX],EAX
45007b02 MOV EAX,dword ptr [ESI]
45007b04 MOV dword ptr [EAX + 0x8],EAX
45007b07 AND dword ptr [ESI + 0x4],0x0
45007b0b POP ESI
45007b0c RET

00eaf837 PUSH ESI
00eaf838 MOV ESI,ECX
00eaf83a MOV dword ptr [ESI],0xf06a04
00eaf840 AND dword ptr [ESI + 0x4],0x0
00eaf844 MOV EAX,dword ptr [ESI + 0x4]
00eaf847 JZ 0x00eaf857
00eaf849 AND dword ptr [ESI + 0x4],0x0
00eaf84d TEST EAX,EAX
00eaf84f JZ 0x00eaf857
00eaf851 MOV ECX,dword ptr [EAX]
00eaf853 PUSH EAX
00eaf854 CALL dword ptr [ECX + 0x8]
00eaf857 MOV EAX,ESI
00eaf859 POP ESI
00eaf85a RET

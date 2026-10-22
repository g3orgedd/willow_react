45027ccc PUSH EBP
45027ccd MOV EBP,ESP
45027ccf SUB ESP,0x328
45027cd5 MOV EAX,[0x450518d0]
45027cda XOR EAX,EBP
45027cdc MOV dword ptr [EBP + -0x4],EAX
45027cdf CMP dword ptr [EBP + 0x8],-0x1
45027ce3 PUSH EDI
45027ce4 JZ 0x45027cef
45027ce6 PUSH dword ptr [EBP + 0x8]
45027ce9 CALL 0x4502ebed
45027cee POP ECX
45027cef AND dword ptr [EBP + 0xfffffce0],0x0
45027cf6 LEA EAX,[EBP + 0xfffffce4]
45027cfc PUSH 0x4c
45027cfe PUSH 0x0
45027d00 PUSH EAX
45027d01 CALL 0x45021c10
45027d06 LEA EAX,[EBP + 0xfffffce0]
45027d0c ADD ESP,0xc
45027d0f MOV dword ptr [EBP + 0xfffffcd8],EAX
45027d15 LEA EAX,[EBP + 0xfffffd30]
45027d1b MOV dword ptr [EBP + 0xfffffcdc],EAX
45027d21 MOV dword ptr [EBP + 0xfffffde0],EAX
45027d27 MOV dword ptr [EBP + 0xfffffddc],ECX
45027d2d MOV dword ptr [EBP + 0xfffffdd8],EDX
45027d33 MOV dword ptr [EBP + 0xfffffdd4],EBX
45027d39 MOV dword ptr [EBP + 0xfffffdd0],ESI
45027d3f MOV dword ptr [EBP + 0xfffffdcc],EDI
45027d45 MOV word ptr [EBP + 0xfffffdf8],SS
45027d4c MOV word ptr [EBP + 0xfffffdec],CS
45027d53 MOV word ptr [EBP + 0xfffffdc8],DS
45027d5a MOV word ptr [EBP + 0xfffffdc4],ES
45027d61 MOV word ptr [EBP + 0xfffffdc0],FS
45027d68 MOV word ptr [EBP + 0xfffffdbc],GS
45027d6f PUSHFD
45027d70 POP dword ptr [EBP + 0xfffffdf0]
45027d76 MOV EAX,dword ptr [EBP + 0x4]
45027d79 MOV dword ptr [EBP + 0xfffffde8],EAX
45027d7f LEA EAX,[EBP + 0x4]
45027d82 MOV dword ptr [EBP + 0xfffffdf4],EAX
45027d88 MOV dword ptr [EBP + 0xfffffd30],0x10001
45027d92 MOV EAX,dword ptr [EAX + -0x4]
45027d95 MOV dword ptr [EBP + 0xfffffde4],EAX
45027d9b MOV EAX,dword ptr [EBP + 0xc]
45027d9e MOV dword ptr [EBP + 0xfffffce0],EAX
45027da4 MOV EAX,dword ptr [EBP + 0x10]
45027da7 MOV dword ptr [EBP + 0xfffffce4],EAX
45027dad MOV EAX,dword ptr [EBP + 0x4]
45027db0 MOV dword ptr [EBP + 0xfffffcec],EAX
45027db6 CALL dword ptr [0x4503d190]
45027dbc MOV EDI,EAX
45027dbe LEA EAX,[EBP + 0xfffffcd8]
45027dc4 PUSH EAX
45027dc5 CALL 0x4502efaa
45027dca POP ECX
45027dcb TEST EAX,EAX
45027dcd JNZ 0x45027de2
45027dcf TEST EDI,EDI
45027dd1 JNZ 0x45027de2
45027dd3 CMP dword ptr [EBP + 0x8],-0x1
45027dd7 JZ 0x45027de2
45027dd9 PUSH dword ptr [EBP + 0x8]
45027ddc CALL 0x4502ebed
45027de1 POP ECX
45027de2 MOV ECX,dword ptr [EBP + -0x4]
45027de5 XOR ECX,EBP
45027de7 POP EDI
45027de8 CALL 0x45022e32
45027ded MOV ESP,EBP
45027def POP EBP
45027df0 RET

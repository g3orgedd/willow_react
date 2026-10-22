4540a9f1 PUSH EBP
4540a9f2 MOV EBP,ESP
4540a9f4 SUB ESP,0x54
4540a9f7 PUSH EBX
4540a9f8 PUSH ESI
4540a9f9 PUSH EDI
4540a9fa MOV EDI,ECX
4540a9fc MOV dword ptr [EBP + -0x34],EDI
4540a9ff CMP dword ptr [EDI + 0x104],0x0
4540aa06 JZ 0x4540b2b0
4540aa0c CMP dword ptr [EDI],0x0
4540aa0f JZ 0x4540b2b0
4540aa15 XOR ECX,ECX
4540aa17 XOR EDX,EDX
4540aa19 MOV dword ptr [EBP + -0x24],EDX
4540aa1c MOV dword ptr [EBP + -0x2c],ECX
4540aa1f CMP dword ptr [EDI],ECX
4540aa21 JBE 0x4540b2ac
4540aa27 LEA EAX,[EDI + 0x78]
4540aa2a MOV dword ptr [EBP + -0x48],0x1
4540aa31 MOV dword ptr [EBP + -0x4c],EAX
4540aa34 AND dword ptr [EBP + -0xc],0x0
4540aa38 OR EAX,0xffffffff
4540aa3b AND dword ptr [EBP + -0x1c],0x0
4540aa3f XOR EDX,EDX
4540aa41 OR dword ptr [EBP + -0x14],EAX
4540aa44 OR EBX,EAX
4540aa46 IMUL ESI,ECX,0x18
4540aa49 MOV dword ptr [EBP + -0x8],EAX
4540aa4c MOV dword ptr [EBP + -0x20],EBX
4540aa4f MOV byte ptr [EBP + -0x1],0x0
4540aa53 MOV dword ptr [EBP + -0x28],EDX
4540aa56 ADD ESI,dword ptr [EDI + 0xc]
4540aa59 MOV dword ptr [EBP + -0x10],ESI
4540aa5c CMP dword ptr [ESI + 0xc],EDX
4540aa5f JBE 0x4540b216
4540aa65 LEA EAX,[EDI + 0x24]
4540aa68 MOV dword ptr [EBP + -0x40],EAX
4540aa6b JMP 0x4540aa70
4540aa6d LEA EAX,[EDI + 0x24]
4540aa70 MOV ECX,dword ptr [ESI + 0x8]
4540aa73 ADD ECX,EDX
4540aa75 SHL ECX,0x5
4540aa78 ADD ECX,dword ptr [EAX]
4540aa7a MOV EAX,dword ptr [EDI + 0x6c]
4540aa7d MOV dword ptr [EBP + -0x18],ECX
4540aa80 MOV EDX,dword ptr [ECX + 0x8]
4540aa83 SUB EDX,dword ptr [EDI + 0x100]
4540aa89 SAR EDX,0x1
4540aa8b ADD EAX,EDX
4540aa8d MOV dword ptr [EBP + -0x38],EDX
4540aa90 PUSH EAX
4540aa91 LEA EDX,[ECX + 0x4]
4540aa94 PUSH EDX
4540aa95 PUSH dword ptr [ECX + 0xc]
4540aa98 MOV dword ptr [EBP + -0x44],EDX
4540aa9b PUSH dword ptr [ECX + 0x8]
4540aa9e CALL 0x454292c2
4540aaa3 TEST EAX,EAX
4540aaa5 JS 0x4540b2b5
4540aaab CMP dword ptr [EBP + -0xc],0x0
4540aaaf MOV EDX,dword ptr [EBP + -0x18]
4540aab2 JBE 0x4540ab26
4540aab4 MOV EAX,dword ptr [EBP + -0x44]
4540aab7 MOV ECX,0x400
4540aabc TEST word ptr [EAX],CX
4540aabf JZ 0x4540aac7
4540aac1 MOV ECX,dword ptr [EDX + 0x10]
4540aac4 DEC ECX
4540aac5 JMP 0x4540aac9
4540aac7 XOR ECX,ECX
4540aac9 ADD ECX,dword ptr [EBP + -0x38]
4540aacc MOV EAX,dword ptr [EDI + 0x90]
4540aad2 MOVZX EAX,word ptr [EAX + ECX*0x2]
4540aad6 ADD EAX,dword ptr [EDI + 0x6c]
4540aad9 MOV ECX,dword ptr [EBP + -0x38]
4540aadc TEST byte ptr [EAX + ECX*0x1],0x1
4540aae0 JZ 0x4540ab26
4540aae2 MOV EBX,dword ptr [ESI + 0x8]
4540aae5 ADD EBX,dword ptr [EBP + -0x28]
4540aae8 MOV EAX,dword ptr [EBP + -0x28]
4540aaeb MOV ECX,dword ptr [EDI + 0x24]
4540aaee SHL EBX,0x5
4540aaf1 DEC EAX
4540aaf2 MOV dword ptr [EBP + -0x8],EAX
4540aaf5 MOV EAX,0x400
4540aafa TEST word ptr [EBX + ECX*0x1 + -0x1c],AX
4540aaff JZ 0x4540ab05
4540ab01 XOR EBX,EBX
4540ab03 JMP 0x4540ab0a
4540ab05 MOV EBX,dword ptr [EBX + ECX*0x1 + -0x10]
4540ab09 DEC EBX
4540ab0a MOV EAX,dword ptr [EDI + 0x84]
4540ab10 MOV dword ptr [EBP + -0x20],EBX
4540ab13 MOV EAX,dword ptr [EAX + EBX*0x4]
4540ab16 MOV dword ptr [EBP + -0x14],EAX
4540ab19 MOV EAX,dword ptr [EBP + -0x1c]
4540ab1c ADD EAX,dword ptr [EBP + -0xc]
4540ab1f AND dword ptr [EBP + -0xc],0x0
4540ab23 MOV dword ptr [EBP + -0x1c],EAX
4540ab26 LEA ECX,[EDI + 0x84]
4540ab2c MOV EAX,dword ptr [ECX + 0x4]
4540ab2f SUB EAX,dword ptr [ECX]
4540ab31 SAR EAX,0x2
4540ab34 MOV dword ptr [EBP + -0x50],ECX
4540ab37 CMP EAX,dword ptr [EDX + 0x10]
4540ab3a JNC 0x4540ab44
4540ab3c PUSH dword ptr [EDX + 0x10]
4540ab3f CALL 0x4540d58f
4540ab44 MOV EAX,dword ptr [EBP + -0x18]
4540ab47 MOV ECX,dword ptr [EAX + 0x10]
4540ab4a MOV EAX,dword ptr [EDI + 0x7c]
4540ab4d SUB EAX,dword ptr [EDI + 0x78]
4540ab50 CMP EAX,ECX
4540ab52 JNC 0x4540ab5d
4540ab54 PUSH ECX
4540ab55 LEA ECX,[EDI + 0x78]
4540ab58 CALL 0x4540d67a
4540ab5d MOV EAX,dword ptr [EBP + -0x18]
4540ab60 MOV EAX,dword ptr [EAX + 0x10]
4540ab63 SHL EAX,0x2
4540ab66 PUSH EAX
4540ab67 PUSH -0x1
4540ab69 PUSH dword ptr [EDI + 0x84]
4540ab6f CALL 0x45429f70
4540ab74 MOV EAX,dword ptr [EBP + -0x18]
4540ab77 PUSH dword ptr [EAX + 0x10]
4540ab7a PUSH 0x0
4540ab7c PUSH dword ptr [EDI + 0x78]
4540ab7f CALL 0x45429f70
4540ab84 MOV ECX,dword ptr [EBP + -0x18]
4540ab87 ADD ESP,0x18
4540ab8a OR dword ptr [EBP + -0x3c],0xffffffff
4540ab8e AND dword ptr [EBP + -0x44],0x0
4540ab92 CMP dword ptr [ECX + 0xc],0x0
4540ab96 JBE 0x4540abf5
4540ab98 MOV ESI,dword ptr [EBP + -0x38]
4540ab9b MOV EBX,dword ptr [EBP + -0x44]
4540ab9e LEA EDX,[ESI + ESI*0x1]
4540aba1 MOV dword ptr [EBP + -0x38],EDX
4540aba4 MOV EAX,dword ptr [EDI + 0x90]
4540abaa MOVZX EDX,word ptr [EDX + EAX*0x1]
4540abae MOV dword ptr [EBP + -0x44],EDX
4540abb1 CMP EDX,dword ptr [EBP + -0x3c]
4540abb4 JZ 0x4540abdf
4540abb6 MOV EAX,dword ptr [EDI + 0x84]
4540abbc MOV dword ptr [EAX + EDX*0x4],EBX
4540abbf XOR EAX,EAX
4540abc1 INC EAX
4540abc2 PUSH EAX
4540abc3 MOV EAX,dword ptr [EDI + 0x6c]
4540abc6 ADD EAX,EBX
4540abc8 ADD EAX,ESI
4540abca PUSH EAX
4540abcb MOV EAX,dword ptr [EDI + 0x78]
4540abce ADD EAX,EDX
4540abd0 PUSH EAX
4540abd1 CALL 0x45429920
4540abd6 MOV ECX,dword ptr [EBP + -0x18]
4540abd9 ADD ESP,0xc
4540abdc MOV EDX,dword ptr [EBP + -0x44]
4540abdf ADD dword ptr [EBP + -0x38],0x2
4540abe3 INC EBX
4540abe4 MOV dword ptr [EBP + -0x3c],EDX
4540abe7 MOV EDX,dword ptr [EBP + -0x38]
4540abea CMP EBX,dword ptr [ECX + 0xc]
4540abed JC 0x4540aba4
4540abef MOV EBX,dword ptr [EBP + -0x20]
4540abf2 MOV ESI,dword ptr [EBP + -0x10]
4540abf5 MOV EDX,dword ptr [ECX + 0x10]
4540abf8 AND dword ptr [EBP + -0x30],0x0
4540abfc MOV dword ptr [EBP + -0x38],EDX
4540abff TEST EDX,EDX
4540ac01 JZ 0x4540b127
4540ac07 MOV AX,word ptr [ECX + 0x4]
4540ac0b SHR AX,0xa
4540ac0f AND AX,word ptr [EBP + -0x48]
4540ac13 MOV word ptr [EBP + -0x4],AX
4540ac17 JZ 0x4540ac1f
4540ac19 SUB EDX,dword ptr [EBP + -0x30]
4540ac1c DEC EDX
4540ac1d JMP 0x4540ac22
4540ac1f MOV EDX,dword ptr [EBP + -0x30]
4540ac22 MOV ECX,dword ptr [ECX + 0x14]
4540ac25 MOV EAX,dword ptr [EDI + 0x48]
4540ac28 ADD ECX,EDX
4540ac2a MOV ECX,dword ptr [EAX + ECX*0x4]
4540ac2d MOV EAX,dword ptr [EBP + -0x1c]
4540ac30 ADD EAX,ECX
4540ac32 MOV dword ptr [EBP + -0x3c],ECX
4540ac35 ADD EAX,dword ptr [EBP + -0xc]
4540ac38 LEA ECX,[EDI + 0x78]
4540ac3b MOV dword ptr [EBP + -0x44],EAX
4540ac3e CMP EAX,dword ptr [EBP + 0xc]
4540ac41 JBE 0x4540b0a9
4540ac47 MOV EAX,dword ptr [ECX]
4540ac49 TEST byte ptr [EDX + EAX*0x1],0x2
4540ac4d JNZ 0x4540b0a9
4540ac53 MOV EDX,dword ptr [EBP + -0x8]
4540ac56 TEST EDX,EDX
4540ac58 JS 0x4540b0a3
4540ac5e TEST EBX,EBX
4540ac60 JS 0x4540b0a3
4540ac66 CMP dword ptr [EBP + -0x14],0x0
4540ac6a JL 0x4540b0a3
4540ac70 MOV EAX,dword ptr [ESI + 0x10]
4540ac73 LEA ECX,[EAX + 0x1]
4540ac76 MOV dword ptr [ESI + 0x10],ECX
4540ac79 TEST EAX,EAX
4540ac7b JNZ 0x4540ac83
4540ac7d MOV EAX,dword ptr [EBP + -0x24]
4540ac80 MOV dword ptr [ESI + 0x14],EAX
4540ac83 MOV EAX,dword ptr [EDI + 0xdc]
4540ac89 SUB EAX,dword ptr [EDI + 0xd8]
4540ac8f ADD ECX,dword ptr [EBP + -0x24]
4540ac92 MOV ESI,dword ptr [EBP + -0x10]
4540ac95 SAR EAX,0x2
4540ac98 CMP EAX,ECX
4540ac9a JNC 0x4540acab
4540ac9c PUSH ECX
4540ac9d LEA ECX,[EDI + 0xd8]
4540aca3 CALL 0x4540d58f
4540aca8 MOV EDX,dword ptr [EBP + -0x8]
4540acab CMP dword ptr [EBP + -0x14],0x0
4540acaf JZ 0x4540b002
4540acb5 MOV ECX,dword ptr [ESI + 0x8]
4540acb8 MOV EAX,dword ptr [EDI + 0x24]
4540acbb ADD ECX,EDX
4540acbd SHL ECX,0x5
4540acc0 MOV EAX,dword ptr [ECX + EAX*0x1 + 0xc]
4540acc4 DEC EAX
4540acc5 CMP dword ptr [EBP + -0x14],EAX
4540acc8 JZ 0x4540b002
4540acce MOV EAX,dword ptr [EDI + 0x28]
4540acd1 SUB EAX,dword ptr [EDI + 0x24]
4540acd4 MOV ECX,dword ptr [EDI + 0x8]
4540acd7 INC ECX
4540acd8 SAR EAX,0x5
4540acdb CMP EAX,ECX
4540acdd JNC 0x4540ace8
4540acdf PUSH ECX
4540ace0 LEA ECX,[EDI + 0x24]
4540ace3 CALL 0x4540d7f6
4540ace8 MOV EDX,dword ptr [EDI + 0x8]
4540aceb LEA ECX,[EDI + 0x9c]
4540acf1 MOV EAX,dword ptr [ECX + 0x4]
4540acf4 INC EDX
4540acf5 SUB EAX,dword ptr [ECX]
4540acf7 CMP EAX,EDX
4540acf9 JNC 0x4540ad01
4540acfb PUSH EDX
4540acfc CALL 0x4540d4e9
4540ad01 MOV EDX,dword ptr [EDI + 0x8]
4540ad04 LEA ECX,[EDI + 0xa8]
4540ad0a MOV EAX,dword ptr [ECX + 0x4]
4540ad0d INC EDX
4540ad0e SUB EAX,dword ptr [ECX]
4540ad10 SAR EAX,0x2
4540ad13 CMP EAX,EDX
4540ad15 JNC 0x4540ad1d
4540ad17 PUSH EDX
4540ad18 CALL 0x4540d58f
4540ad1d MOV EDX,dword ptr [ESI + 0x8]
4540ad20 MOV ECX,dword ptr [EBP + -0x8]
4540ad23 MOV EAX,dword ptr [EDI + 0x8]
4540ad26 SUB EAX,EDX
4540ad28 SUB EAX,dword ptr [EBP + -0x8]
4540ad2b LEA ECX,[EDX + ECX*0x1]
4540ad2e SHL EAX,0x5
4540ad31 SHL ECX,0x5
4540ad34 ADD ECX,dword ptr [EDI + 0x24]
4540ad37 PUSH EAX
4540ad38 PUSH ECX
4540ad39 LEA EAX,[ECX + 0x20]
4540ad3c PUSH EAX
4540ad3d CALL 0x4542a090
4540ad42 MOV ECX,dword ptr [EDI + 0x9c]
4540ad48 MOV EAX,dword ptr [EDI + 0x8]
4540ad4b ADD ECX,dword ptr [ESI + 0x8]
4540ad4e SUB EAX,dword ptr [ESI + 0x8]
4540ad51 ADD ECX,dword ptr [EBP + -0x8]
4540ad54 SUB EAX,dword ptr [EBP + -0x8]
4540ad57 PUSH EAX
4540ad58 PUSH ECX
4540ad59 LEA EAX,[ECX + 0x1]
4540ad5c PUSH EAX
4540ad5d CALL 0x4542a090
4540ad62 MOV ECX,dword ptr [EBP + -0x8]
4540ad65 MOV EAX,dword ptr [EDI + 0xa8]
4540ad6b ADD ECX,dword ptr [ESI + 0x8]
4540ad6e LEA ECX,[EAX + ECX*0x4]
4540ad71 MOV EAX,dword ptr [EDI + 0x8]
4540ad74 SUB EAX,dword ptr [ESI + 0x8]
4540ad77 SUB EAX,dword ptr [EBP + -0x8]
4540ad7a SHL EAX,0x2
4540ad7d PUSH EAX
4540ad7e PUSH ECX
4540ad7f LEA EAX,[ECX + 0x4]
4540ad82 PUSH EAX
4540ad83 CALL 0x4542a090
4540ad88 MOV EAX,dword ptr [ESI + 0x8]
4540ad8b ADD ESP,0x24
4540ad8e MOV EDI,dword ptr [EBP + -0x40]
4540ad91 XOR EDX,EDX
4540ad93 INC dword ptr [ESI + 0xc]
4540ad96 MOV ESI,0x400
4540ad9b MOV ECX,dword ptr [EBP + -0x8]
4540ad9e ADD EAX,ECX
4540ada0 SHL EAX,0x5
4540ada3 MOV EDI,dword ptr [EDI]
4540ada5 MOV dword ptr [EBP + -0x18],EDI
4540ada8 MOV dword ptr [EBP + -0x38],EDX
4540adab MOV dword ptr [EBP + -0x1c],EAX
4540adae TEST word ptr [EAX + EDI*0x1 + 0x4],SI
4540adb3 MOV EDI,dword ptr [EBP + -0x34]
4540adb6 JZ 0x4540ae87
4540adbc MOV ESI,dword ptr [EBP + -0x18]
4540adbf LEA EAX,[EBX + 0x1]
4540adc2 MOV EDI,dword ptr [EBP + -0x1c]
4540adc5 MOV dword ptr [EBP + -0xc],EAX
4540adc8 CMP EAX,dword ptr [EDI + ESI*0x1 + 0x10]
4540adcc MOV ESI,dword ptr [EBP + -0x10]
4540adcf JNC 0x4540adf3
4540add1 MOV ECX,dword ptr [EBP + -0x4c]
4540add4 MOV EBX,dword ptr [EBP + -0x18]
4540add7 MOV EDI,dword ptr [ECX]
4540add9 MOV ECX,dword ptr [EBP + -0x1c]
4540addc TEST byte ptr [EDI + EAX*0x1],0x2
4540ade0 JZ 0x4540adea
4540ade2 INC EDX
4540ade3 INC EAX
4540ade4 CMP EAX,dword ptr [ECX + EBX*0x1 + 0x10]
4540ade8 JC 0x4540addc
4540adea MOV EBX,dword ptr [EBP + -0x20]
4540aded MOV ECX,dword ptr [EBP + -0x8]
4540adf0 MOV dword ptr [EBP + -0x38],EDX
4540adf3 MOV EDI,dword ptr [EBP + -0x18]
4540adf6 LEA EAX,[EDX + 0x1]
4540adf9 MOV EDX,dword ptr [EBP + -0x1c]
4540adfc ADD EAX,EBX
4540adfe ADD dword ptr [EDX + EDI*0x1 + 0x14],EAX
4540ae02 OR EAX,0xffffffff
4540ae05 MOV EDX,dword ptr [ESI + 0x8]
4540ae08 MOV EDI,dword ptr [EBP + -0x40]
4540ae0b ADD EDX,ECX
4540ae0d SUB EAX,dword ptr [EBP + -0x38]
4540ae10 SHL EDX,0x5
4540ae13 SUB EAX,EBX
4540ae15 MOV ECX,dword ptr [EDI]
4540ae17 ADD dword ptr [EDX + ECX*0x1 + 0x10],EAX
4540ae1b MOV ECX,dword ptr [ESI + 0x8]
4540ae1e ADD ECX,dword ptr [EBP + -0x8]
4540ae21 MOV EAX,dword ptr [EDI]
4540ae23 MOV EDX,dword ptr [EBP + -0xc]
4540ae26 MOV ESI,dword ptr [EBP + -0x38]
4540ae29 SHL ECX,0x5
4540ae2c ADD ESI,EBX
4540ae2e MOV EBX,dword ptr [EBP + -0x8]
4540ae31 MOV dword ptr [ECX + EAX*0x1 + 0x30],EDX
4540ae35 MOV EAX,dword ptr [EBP + -0x50]
4540ae38 MOV EDX,dword ptr [EBP + -0x10]
4540ae3b MOV ECX,dword ptr [EDI]
4540ae3d MOV EAX,dword ptr [EAX]
4540ae3f MOV EDX,dword ptr [EDX + 0x8]
4540ae42 ADD EDX,EBX
4540ae44 SHL EDX,0x5
4540ae47 MOV EAX,dword ptr [EAX + ESI*0x4]
4540ae4a MOV ESI,dword ptr [EBP + -0x10]
4540ae4d MOV dword ptr [EDX + ECX*0x1 + 0xc],EAX
4540ae51 MOV ECX,dword ptr [EDI]
4540ae53 MOV EDX,dword ptr [ESI + 0x8]
4540ae56 MOV EAX,dword ptr [EBP + -0x14]
4540ae59 ADD EDX,EBX
4540ae5b SHL EDX,0x5
4540ae5e ADD EAX,EAX
4540ae60 ADD dword ptr [EDX + ECX*0x1 + 0x28],EAX
4540ae64 MOV ECX,dword ptr [ESI + 0x8]
4540ae67 MOV EAX,dword ptr [EDI]
4540ae69 ADD ECX,EBX
4540ae6b MOV EDX,dword ptr [EBP + -0x14]
4540ae6e SHL ECX,0x5
4540ae71 SUB dword ptr [ECX + EAX*0x1 + 0x2c],EDX
4540ae75 MOV EAX,dword ptr [ESI + 0x8]
4540ae78 ADD EAX,EBX
4540ae7a SHL EAX,0x5
4540ae7d ADD EAX,dword ptr [EDI]
4540ae7f MOV EDI,dword ptr [EBP + -0x34]
4540ae82 JMP 0x4540af27
4540ae87 TEST EBX,EBX
4540ae89 JLE 0x4540ae9f
4540ae8b MOV EAX,dword ptr [EDI + 0x78]
4540ae8e DEC EAX
4540ae8f ADD EAX,EBX
4540ae91 TEST byte ptr [EAX],0x2
4540ae94 JZ 0x4540ae9c
4540ae96 INC EDX
4540ae97 DEC EAX
4540ae98 CMP EDX,EBX
4540ae9a JL 0x4540ae91
4540ae9c MOV EAX,dword ptr [EBP + -0x1c]
4540ae9f MOV ECX,dword ptr [EBP + -0x18]
4540aea2 MOV ESI,EBX
4540aea4 SUB ESI,EDX
4540aea6 MOV dword ptr [EBP + -0xc],EBX
4540aea9 MOV EDX,dword ptr [EBP + -0x10]
4540aeac MOV dword ptr [EAX + ECX*0x1 + 0x10],ESI
4540aeb0 MOV EAX,dword ptr [EDI + 0x24]
4540aeb3 MOV ECX,dword ptr [EDX + 0x8]
4540aeb6 ADD ECX,dword ptr [EBP + -0x8]
4540aeb9 SHL ECX,0x5
4540aebc ADD dword ptr [ECX + EAX*0x1 + 0x34],EBX
4540aec0 MOV ECX,dword ptr [EDX + 0x8]
4540aec3 ADD ECX,dword ptr [EBP + -0x8]
4540aec6 MOV EAX,dword ptr [EDI + 0x24]
4540aec9 SHL ECX,0x5
4540aecc SUB dword ptr [ECX + EAX*0x1 + 0x30],EBX
4540aed0 MOV EDX,dword ptr [EDX + 0x8]
4540aed3 MOV EAX,dword ptr [EDI + 0x84]
4540aed9 ADD EDX,dword ptr [EBP + -0x8]
4540aedc MOV ECX,dword ptr [EDI + 0x24]
4540aedf SHL EDX,0x5
4540aee2 MOV EAX,dword ptr [EAX + ESI*0x4]
4540aee5 MOV ESI,dword ptr [EBP + -0x10]
4540aee8 MOV EBX,dword ptr [EBP + -0x8]
4540aeeb MOV dword ptr [EDX + ECX*0x1 + 0xc],EAX
4540aeef MOV ECX,dword ptr [EDI + 0x24]
4540aef2 MOV EDX,dword ptr [ESI + 0x8]
4540aef5 ADD EDX,dword ptr [EBP + -0x8]
4540aef8 MOV EAX,dword ptr [EBP + -0x14]
4540aefb ADD EAX,EAX
4540aefd SHL EDX,0x5
4540af00 ADD dword ptr [EDX + ECX*0x1 + 0x28],EAX
4540af04 MOV ECX,dword ptr [ESI + 0x8]
4540af07 ADD ECX,dword ptr [EBP + -0x8]
4540af0a MOV EAX,dword ptr [EDI + 0x24]
4540af0d MOV EDI,dword ptr [EBP + -0x14]
4540af10 SHL ECX,0x5
4540af13 SUB dword ptr [ECX + EAX*0x1 + 0x2c],EDI
4540af17 MOV EAX,dword ptr [ESI + 0x8]
4540af1a MOV EDI,dword ptr [EBP + -0x34]
4540af1d INC EAX
4540af1e ADD EAX,dword ptr [EBP + -0x8]
4540af21 SHL EAX,0x5
4540af24 ADD EAX,dword ptr [EDI + 0x24]
4540af27 MOV ECX,dword ptr [EBP + -0x2c]
4540af2a INC dword ptr [EDI + 0x8]
4540af2d INC ECX
4540af2e MOV dword ptr [EBP + -0x38],EAX
4540af31 CMP ECX,dword ptr [EDI]
4540af33 JNC 0x4540af47
4540af35 IMUL EDX,ECX,0x18
4540af38 MOV EAX,dword ptr [EDI + 0xc]
4540af3b LEA EDX,[EDX + 0x18]
4540af3e INC dword ptr [EDX + EAX*0x1 + -0x10]
4540af42 INC ECX
4540af43 CMP ECX,dword ptr [EDI]
4540af45 JC 0x4540af38
4540af47 MOV ECX,dword ptr [EBP + -0x38]
4540af4a AND dword ptr [EBP + -0x44],0x0
4540af4e MOV EAX,dword ptr [ECX + 0x8]
4540af51 SUB EAX,dword ptr [EDI + 0x100]
4540af57 SAR EAX,0x1
4540af59 CMP dword ptr [ECX + 0xc],0x0
4540af5d JLE 0x4540af8d
4540af5f MOV ESI,dword ptr [EBP + -0x38]
4540af62 LEA ECX,[EAX + EAX*0x1]
4540af65 MOV EBX,dword ptr [EBP + -0x44]
4540af68 MOV EAX,dword ptr [EDI + 0x90]
4540af6e MOVZX EDX,word ptr [ECX + EAX*0x1]
4540af72 CMP EDX,dword ptr [EBP + -0xc]
4540af75 JL 0x4540af7e
4540af77 SUB EDX,dword ptr [EBP + -0xc]
4540af7a MOV word ptr [ECX + EAX*0x1],DX
4540af7e INC EBX
4540af7f ADD ECX,0x2
4540af82 CMP EBX,dword ptr [ESI + 0xc]
4540af85 JL 0x4540af68
4540af87 MOV ESI,dword ptr [EBP + -0x10]
4540af8a MOV EBX,dword ptr [EBP + -0x8]
4540af8d MOV EAX,dword ptr [ESI + 0x8]
4540af90 LEA EDX,[EDI + 0x24]
4540af93 ADD EAX,dword ptr [EBP + -0x28]
4540af96 SHL EAX,0x5
4540af99 ADD EAX,dword ptr [EDX]
4540af9b MOV dword ptr [EBP + -0x18],EAX
4540af9e XOR EAX,EAX
4540afa0 MOV dword ptr [EBP + -0x3c],EAX
4540afa3 MOV ECX,dword ptr [ESI + 0x8]
4540afa6 ADD ECX,EAX
4540afa8 ADD ECX,EBX
4540afaa SHL ECX,0x5
4540afad ADD ECX,dword ptr [EDX]
4540afaf AND dword ptr [ECX + 0x18],0x0
4540afb3 MOV EDX,dword ptr [ECX + 0x10]
4540afb6 TEST EDX,EDX
4540afb8 JLE 0x4540afe2
4540afba AND dword ptr [EBP + -0x44],0x0
4540afbe MOV EDX,dword ptr [ECX + 0x14]
4540afc1 MOV ESI,dword ptr [EBP + -0x44]
4540afc4 MOV EBX,dword ptr [ECX + 0x10]
4540afc7 SHL EDX,0x2
4540afca MOV EAX,dword ptr [EDI + 0x48]
4540afcd ADD ESI,dword ptr [EAX + EDX*0x1]
4540afd0 LEA EDX,[EDX + 0x4]
4540afd3 MOV dword ptr [ECX + 0x18],ESI
4540afd6 DEC EBX
4540afd7 JNZ 0x4540afca
4540afd9 MOV ESI,dword ptr [EBP + -0x10]
4540afdc MOV EBX,dword ptr [EBP + -0x8]
4540afdf MOV EAX,dword ptr [EBP + -0x3c]
4540afe2 INC EAX
4540afe3 LEA EDX,[EDI + 0x24]
4540afe6 MOV dword ptr [EBP + -0x3c],EAX
4540afe9 CMP EAX,0x2
4540afec JL 0x4540afa3
4540afee MOV EDX,dword ptr [EBP + -0x24]
4540aff1 LEA ECX,[EDI + 0xd8]
4540aff7 MOV EAX,dword ptr [ECX]
4540aff9 AND dword ptr [EBP + -0xc],0x0
4540affd MOV dword ptr [EAX + EDX*0x4],EBX
4540b000 JMP 0x4540b029
4540b002 MOV EAX,dword ptr [EDI + 0xd8]
4540b008 MOV ECX,dword ptr [EBP + -0x24]
4540b00b PUSH EBX
4540b00c PUSH EDX
4540b00d MOV dword ptr [EAX + ECX*0x4],EDX
4540b010 MOV ECX,EDI
4540b012 MOV EAX,dword ptr [EBP + -0x3c]
4540b015 PUSH dword ptr [ESI + 0x8]
4540b018 ADD dword ptr [EBP + -0xc],EAX
4540b01b CALL 0x4540ccfc
4540b020 MOV EDX,dword ptr [EBP + -0x24]
4540b023 LEA ECX,[EDI + 0xd8]
4540b029 CMP EDX,dword ptr [ESI + 0x14]
4540b02c JNZ 0x4540b032
4540b02e XOR EBX,EBX
4540b030 JMP 0x4540b039
4540b032 MOV EAX,dword ptr [ECX]
4540b034 MOV EBX,dword ptr [EAX + EDX*0x4 + -0x4]
4540b038 INC EBX
4540b039 CMP EBX,dword ptr [ESI + 0xc]
4540b03c JNC 0x4540b089
4540b03e MOV EDX,dword ptr [ESI + 0x8]
4540b041 MOV EAX,dword ptr [EDI + 0xa8]
4540b047 PUSH 0x0
4540b049 LEA ECX,[EDX + EBX*0x1]
4540b04c LEA EAX,[EAX + ECX*0x4]
4540b04f PUSH EAX
4540b050 MOV EAX,dword ptr [EDI + 0x9c]
4540b056 ADD EAX,EDX
4540b058 ADD EAX,EBX
4540b05a PUSH EAX
4540b05b MOV EAX,dword ptr [EBP + -0x8]
4540b05e SUB EAX,EBX
4540b060 INC EAX
4540b061 PUSH EAX
4540b062 CALL 0x454292a4
4540b067 MOV EDX,dword ptr [EBP + -0x8]
4540b06a MOV EAX,EBX
4540b06c CMP EBX,EDX
4540b06e JMP 0x4540b084
4540b070 MOV ECX,dword ptr [ESI + 0x8]
4540b073 ADD ECX,EAX
4540b075 MOV EAX,dword ptr [EDI + 0xa8]
4540b07b ADD dword ptr [EAX + ECX*0x4],EBX
4540b07e MOV EAX,dword ptr [EBP + -0x3c]
4540b081 INC EAX
4540b082 CMP EAX,EDX
4540b084 MOV dword ptr [EBP + -0x3c],EAX
4540b087 JLE 0x4540b070
4540b089 INC dword ptr [EBP + -0x24]
4540b08c OR EBX,0xffffffff
4540b08f INC dword ptr [EDI + 0x4]
4540b092 OR dword ptr [EBP + -0x8],0xffffffff
4540b096 AND dword ptr [EBP + -0x1c],0x0
4540b09a MOV dword ptr [EBP + -0x20],EBX
4540b09d MOV byte ptr [EBP + -0x1],0x0
4540b0a1 JMP 0x4540b10f
4540b0a3 OR dword ptr [EBP + -0x8],0xffffffff
4540b0a7 JMP 0x4540b10f
4540b0a9 MOV EAX,dword ptr [EBP + -0x38]
4540b0ac DEC EAX
4540b0ad MOV dword ptr [EBP + -0x54],EAX
4540b0b0 CMP dword ptr [EBP + -0x30],EAX
4540b0b3 JNC 0x4540b1bf
4540b0b9 MOV CX,word ptr [EBP + -0x4]
4540b0bd TEST CX,CX
4540b0c0 JZ 0x4540b0d0
4540b0c2 TEST EDX,EDX
4540b0c4 JZ 0x4540b0e3
4540b0c6 MOV EAX,dword ptr [EDI + 0x78]
4540b0c9 TEST byte ptr [EDX + EAX*0x1 + -0x1],0x1
4540b0ce JMP 0x4540b0dc
4540b0d0 CMP EDX,EAX
4540b0d2 JNC 0x4540b0e3
4540b0d4 MOV EAX,dword ptr [EDI + 0x78]
4540b0d7 TEST byte ptr [EDX + EAX*0x1 + 0x1],0x1
4540b0dc JZ 0x4540b0e3
4540b0de XOR EAX,EAX
4540b0e0 INC EAX
4540b0e1 JMP 0x4540b0e5
4540b0e3 XOR AL,AL
4540b0e5 OR byte ptr [EBP + -0x1],AL
4540b0e8 JNZ 0x4540b17c
4540b0ee TEST AL,AL
4540b0f0 JNZ 0x4540b180
4540b0f6 TEST CX,CX
4540b0f9 JZ 0x4540b16b
4540b0fb TEST EDX,EDX
4540b0fd JZ 0x4540b109
4540b0ff MOV EAX,dword ptr [EDI + 0x78]
4540b102 TEST byte ptr [EDX + EAX*0x1 + -0x1],0x4
4540b107 JNZ 0x4540b180
4540b109 MOV EAX,dword ptr [EBP + -0x3c]
4540b10c ADD dword ptr [EBP + -0xc],EAX
4540b10f MOV ECX,dword ptr [EBP + -0x18]
4540b112 MOV EAX,dword ptr [EBP + -0x30]
4540b115 INC EAX
4540b116 MOV dword ptr [EBP + -0x30],EAX
4540b119 MOV EDX,dword ptr [ECX + 0x10]
4540b11c MOV dword ptr [EBP + -0x38],EDX
4540b11f CMP EAX,EDX
4540b121 JC 0x4540ac07
4540b127 MOV EDX,dword ptr [EBP + -0x28]
4540b12a INC EDX
4540b12b MOV dword ptr [EBP + -0x28],EDX
4540b12e CMP EDX,dword ptr [ESI + 0xc]
4540b131 JC 0x4540aa6d
4540b137 MOV ECX,dword ptr [EBP + -0xc]
4540b13a TEST ECX,ECX
4540b13c JZ 0x4540b210
4540b142 MOV EAX,dword ptr [ESI + 0xc]
4540b145 MOV EBX,dword ptr [ESI + 0x8]
4540b148 MOV EDX,dword ptr [EDI + 0x24]
4540b14b ADD EBX,EAX
4540b14d SHL EBX,0x5
4540b150 MOV EDI,0x400
4540b155 DEC EAX
4540b156 TEST word ptr [EBX + EDX*0x1 + -0x1c],DI
4540b15b MOV EDI,dword ptr [EBP + -0x34]
4540b15e JZ 0x4540b206
4540b164 XOR EBX,EBX
4540b166 JMP 0x4540b20b
4540b16b CMP EDX,dword ptr [EBP + -0x54]
4540b16e JNC 0x4540b17a
4540b170 MOV EAX,dword ptr [EDI + 0x78]
4540b173 TEST byte ptr [EDX + EAX*0x1 + 0x1],0x4
4540b178 JNZ 0x4540b180
4540b17a XOR AL,AL
4540b17c TEST AL,AL
4540b17e JZ 0x4540b109
4540b180 MOV EAX,dword ptr [EBP + -0x28]
4540b183 LEA EBX,[EDX + 0x1]
4540b186 TEST CX,CX
4540b189 MOV dword ptr [EBP + -0x8],EAX
4540b18c LEA EAX,[EDX + -0x1]
4540b18f CMOVNZ EBX,EAX
4540b192 MOV dword ptr [EBP + -0x20],EBX
4540b195 TEST EBX,EBX
4540b197 JS 0x4540b1ac
4540b199 CMP EBX,dword ptr [EBP + -0x38]
4540b19c JGE 0x4540b1ac
4540b19e MOV EAX,dword ptr [EDI + 0x84]
4540b1a4 MOV ECX,dword ptr [EAX + EBX*0x4]
4540b1a7 MOV dword ptr [EBP + -0x14],ECX
4540b1aa JMP 0x4540b1b0
4540b1ac OR dword ptr [EBP + -0x14],0xffffffff
4540b1b0 MOV EAX,dword ptr [EBP + -0x44]
4540b1b3 AND dword ptr [EBP + -0xc],0x0
4540b1b7 MOV dword ptr [EBP + -0x1c],EAX
4540b1ba JMP 0x4540b10f
4540b1bf MOV EAX,dword ptr [ECX]
4540b1c1 TEST byte ptr [EDX + EAX*0x1],0x2
4540b1c5 JZ 0x4540b109
4540b1cb MOV CX,word ptr [EBP + -0x4]
4540b1cf MOV EAX,dword ptr [EBP + -0x28]
4540b1d2 MOV dword ptr [EBP + -0x8],EAX
4540b1d5 TEST CX,CX
4540b1d8 JZ 0x4540b1de
4540b1da XOR EBX,EBX
4540b1dc JMP 0x4540b1e2
4540b1de MOV EBX,dword ptr [EBP + -0x38]
4540b1e1 DEC EBX
4540b1e2 MOV EAX,dword ptr [EDI + 0x84]
4540b1e8 AND dword ptr [EBP + -0xc],0x0
4540b1ec MOV dword ptr [EBP + -0x20],EBX
4540b1ef MOV EAX,dword ptr [EAX + EBX*0x4]
4540b1f2 MOV dword ptr [EBP + -0x14],EAX
4540b1f5 MOV EAX,dword ptr [EBP + -0x44]
4540b1f8 MOV dword ptr [EBP + -0x1c],EAX
4540b1fb XOR EAX,EAX
4540b1fd INC EAX
4540b1fe MOV byte ptr [EBP + -0x1],AL
4540b201 JMP 0x4540b10f
4540b206 MOV EBX,dword ptr [EBX + EDX*0x1 + -0x10]
4540b20a DEC EBX
4540b20b ADD dword ptr [EBP + -0x1c],ECX
4540b20e JMP 0x4540b213
4540b210 MOV EAX,dword ptr [EBP + -0x8]
4540b213 MOV ECX,dword ptr [EBP + -0x2c]
4540b216 CMP dword ptr [ESI + 0x10],0x0
4540b21a JBE 0x4540b297
4540b21c TEST EAX,EAX
4540b21e JS 0x4540b297
4540b220 PUSH EBX
4540b221 PUSH EAX
4540b222 PUSH dword ptr [ESI + 0x8]
4540b225 MOV ECX,EDI
4540b227 CALL 0x4540ccfc
4540b22c MOV EDX,dword ptr [EBP + -0x24]
4540b22f CMP EDX,dword ptr [ESI + 0x14]
4540b232 JNZ 0x4540b238
4540b234 XOR EBX,EBX
4540b236 JMP 0x4540b243
4540b238 MOV EAX,dword ptr [EDI + 0xd8]
4540b23e MOV EBX,dword ptr [EAX + EDX*0x4 + -0x4]
4540b242 INC EBX
4540b243 MOV EAX,dword ptr [ESI + 0xc]
4540b246 LEA ECX,[EAX + -0x1]
4540b249 MOV dword ptr [EBP + -0x3c],ECX
4540b24c CMP EBX,EAX
4540b24e JNC 0x4540b294
4540b250 MOV EDX,dword ptr [ESI + 0x8]
4540b253 MOV EAX,dword ptr [EDI + 0xa8]
4540b259 PUSH 0x0
4540b25b LEA ECX,[EDX + EBX*0x1]
4540b25e LEA EAX,[EAX + ECX*0x4]
4540b261 PUSH EAX
4540b262 MOV EAX,dword ptr [EDI + 0x9c]
4540b268 ADD EAX,EDX
4540b26a ADD EAX,EBX
4540b26c PUSH EAX
4540b26d MOV EAX,dword ptr [EBP + -0x3c]
4540b270 SUB EAX,EBX
4540b272 INC EAX
4540b273 PUSH EAX
4540b274 CALL 0x454292a4
4540b279 MOV EDX,EBX
4540b27b CMP EBX,dword ptr [EBP + -0x3c]
4540b27e JG 0x4540b294
4540b280 MOV ECX,dword ptr [ESI + 0x8]
4540b283 MOV EAX,dword ptr [EDI + 0xa8]
4540b289 ADD ECX,EDX
4540b28b ADD dword ptr [EAX + ECX*0x4],EBX
4540b28e INC EDX
4540b28f CMP EDX,dword ptr [EBP + -0x3c]
4540b292 JLE 0x4540b280
4540b294 MOV ECX,dword ptr [EBP + -0x2c]
4540b297 MOV EAX,dword ptr [EBP + -0x1c]
4540b29a INC ECX
4540b29b MOV dword ptr [EDI + 0xfc],EAX
4540b2a1 MOV dword ptr [EBP + -0x2c],ECX
4540b2a4 CMP ECX,dword ptr [EDI]
4540b2a6 JC 0x4540aa34
4540b2ac XOR EAX,EAX
4540b2ae JMP 0x4540b2b5
4540b2b0 MOV EAX,0x8000ffff
4540b2b5 POP EDI
4540b2b6 POP ESI
4540b2b7 POP EBX
4540b2b8 MOV ESP,EBP
4540b2ba POP EBP
4540b2bb RET 0x8

00ecc570 PUSH EDI
00ecc571 PUSH ESI
00ecc572 MOV ESI,dword ptr [ESP + 0x10]
00ecc576 MOV ECX,dword ptr [ESP + 0x14]
00ecc57a MOV EDI,dword ptr [ESP + 0xc]
00ecc57e MOV EAX,ECX
00ecc580 MOV EDX,ECX
00ecc582 ADD EAX,ESI
00ecc584 CMP EDI,ESI
00ecc586 JBE 0x00ecc590
00ecc588 CMP EDI,EAX
00ecc58a JC 0x00ecc8f8
00ecc590 BT dword ptr [0x00f44fbc],0x1
00ecc598 JNC 0x00ecc5a1
00ecc59a MOVSB.REP ES:EDI,ESI
00ecc59c JMP 0x00ecc8b8
00ecc5a1 CMP ECX,0x80
00ecc5a7 JC 0x00ecc77b
00ecc5ad MOV EAX,EDI
00ecc5af XOR EAX,ESI
00ecc5b1 TEST EAX,0xf
00ecc5b6 JNZ 0x00ecc5c6
00ecc5b8 BT dword ptr [0x00f39054],0x1
00ecc5c0 JC 0x00eccaa0
00ecc5c6 BT dword ptr [0x00f44fbc],0x0
00ecc5ce JNC 0x00ecc77b
00ecc5d4 TEST EDI,0x3
00ecc5da JNZ 0x00ecc798
00ecc5e0 TEST ESI,0x3
00ecc5e6 JNZ 0x00ecc783
00ecc5ec BT EDI,0x2
00ecc5f0 JNC 0x00ecc5ff
00ecc5f2 MOV EAX,dword ptr [ESI]
00ecc5f4 SUB ECX,0x4
00ecc5f7 LEA ESI,[ESI + 0x4]
00ecc5fa MOV dword ptr [EDI],EAX
00ecc5fc LEA EDI,[EDI + 0x4]
00ecc5ff BT EDI,0x3
00ecc603 JNC 0x00ecc616
00ecc605 MOVQ XMM1,qword ptr [ESI]
00ecc609 SUB ECX,0x8
00ecc60c LEA ESI,[ESI + 0x8]
00ecc60f MOVQ qword ptr [EDI],XMM1
00ecc613 LEA EDI,[EDI + 0x8]
00ecc616 TEST ESI,0x7
00ecc61c JZ 0x00ecc681
00ecc61e BT ESI,0x3
00ecc622 JNC 0x00ecc6da
00ecc628 MOVDQA XMM1,xmmword ptr [ESI + -0xc]
00ecc62d LEA ESI,[ESI + -0xc]
00ecc630 MOVDQA XMM3,xmmword ptr [ESI + 0x10]
00ecc635 SUB ECX,0x30
00ecc638 MOVDQA XMM0,xmmword ptr [ESI + 0x20]
00ecc63d MOVDQA XMM5,xmmword ptr [ESI + 0x30]
00ecc642 LEA ESI,[ESI + 0x30]
00ecc645 CMP ECX,0x30
00ecc648 MOVDQA XMM2,XMM3
00ecc64c PALIGNR XMM3,XMM1,0xc
00ecc652 MOVDQA xmmword ptr [EDI],XMM3
00ecc656 MOVDQA XMM4,XMM0
00ecc65a PALIGNR XMM0,XMM2,0xc
00ecc660 MOVDQA xmmword ptr [EDI + 0x10],XMM0
00ecc665 MOVDQA XMM1,XMM5
00ecc669 PALIGNR XMM5,XMM4,0xc
00ecc66f MOVDQA xmmword ptr [EDI + 0x20],XMM5
00ecc674 LEA EDI,[EDI + 0x30]
00ecc677 JGE 0x00ecc630
00ecc679 LEA ESI,[ESI + 0xc]
00ecc67c JMP 0x00ecc730
00ecc681 MOVDQA XMM1,xmmword ptr [ESI + -0x8]
00ecc686 LEA ESI,[ESI + -0x8]
00ecc689 LEA ECX,[ECX]
00ecc68c MOVDQA XMM3,xmmword ptr [ESI + 0x10]
00ecc691 SUB ECX,0x30
00ecc694 MOVDQA XMM0,xmmword ptr [ESI + 0x20]
00ecc699 MOVDQA XMM5,xmmword ptr [ESI + 0x30]
00ecc69e LEA ESI,[ESI + 0x30]
00ecc6a1 CMP ECX,0x30
00ecc6a4 MOVDQA XMM2,XMM3
00ecc6a8 PALIGNR XMM3,XMM1,0x8
00ecc6ae MOVDQA xmmword ptr [EDI],XMM3
00ecc6b2 MOVDQA XMM4,XMM0
00ecc6b6 PALIGNR XMM0,XMM2,0x8
00ecc6bc MOVDQA xmmword ptr [EDI + 0x10],XMM0
00ecc6c1 MOVDQA XMM1,XMM5
00ecc6c5 PALIGNR XMM5,XMM4,0x8
00ecc6cb MOVDQA xmmword ptr [EDI + 0x20],XMM5
00ecc6d0 LEA EDI,[EDI + 0x30]
00ecc6d3 JGE 0x00ecc68c
00ecc6d5 LEA ESI,[ESI + 0x8]
00ecc6d8 JMP 0x00ecc730
00ecc6da MOVDQA XMM1,xmmword ptr [ESI + -0x4]
00ecc6df LEA ESI,[ESI + -0x4]
00ecc6e2 MOV EDI,EDI
00ecc6e4 MOVDQA XMM3,xmmword ptr [ESI + 0x10]
00ecc6e9 SUB ECX,0x30
00ecc6ec MOVDQA XMM0,xmmword ptr [ESI + 0x20]
00ecc6f1 MOVDQA XMM5,xmmword ptr [ESI + 0x30]
00ecc6f6 LEA ESI,[ESI + 0x30]
00ecc6f9 CMP ECX,0x30
00ecc6fc MOVDQA XMM2,XMM3
00ecc700 PALIGNR XMM3,XMM1,0x4
00ecc706 MOVDQA xmmword ptr [EDI],XMM3
00ecc70a MOVDQA XMM4,XMM0
00ecc70e PALIGNR XMM0,XMM2,0x4
00ecc714 MOVDQA xmmword ptr [EDI + 0x10],XMM0
00ecc719 MOVDQA XMM1,XMM5
00ecc71d PALIGNR XMM5,XMM4,0x4
00ecc723 MOVDQA xmmword ptr [EDI + 0x20],XMM5
00ecc728 LEA EDI,[EDI + 0x30]
00ecc72b JGE 0x00ecc6e4
00ecc72d LEA ESI,[ESI + 0x4]
00ecc730 CMP ECX,0x10
00ecc733 JL 0x00ecc748
00ecc735 MOVDQU XMM1,xmmword ptr [ESI]
00ecc739 SUB ECX,0x10
00ecc73c LEA ESI,[ESI + 0x10]
00ecc73f MOVDQA xmmword ptr [EDI],XMM1
00ecc743 LEA EDI,[EDI + 0x10]
00ecc746 JMP 0x00ecc730
00ecc748 BT ECX,0x2
00ecc74c JNC 0x00ecc75b
00ecc74e MOV EAX,dword ptr [ESI]
00ecc750 SUB ECX,0x4
00ecc753 LEA ESI,[ESI + 0x4]
00ecc756 MOV dword ptr [EDI],EAX
00ecc758 LEA EDI,[EDI + 0x4]
00ecc75b BT ECX,0x3
00ecc75f JNC 0x00ecc772
00ecc761 MOVQ XMM1,qword ptr [ESI]
00ecc765 SUB ECX,0x8
00ecc768 LEA ESI,[ESI + 0x8]
00ecc76b MOVQ qword ptr [EDI],XMM1
00ecc76f LEA EDI,[EDI + 0x8]
00ecc772 MOV EAX,dword ptr [ECX*0x4 + 0xecc8a8]
00ecc779 JMP EAX
00ecc77b TEST EDI,0x3
00ecc781 JNZ 0x00ecc798
00ecc783 SHR ECX,0x2
00ecc786 AND EDX,0x3
00ecc789 CMP ECX,0x8
00ecc78c JC 0x00ecc7b8
00ecc78e MOVSD.REP ES:EDI,ESI
00ecc790 JMP dword ptr [EDX*0x4 + 0xecc8a8]
00ecc798 MOV EAX,EDI
00ecc79a MOV EDX,0x3
00ecc79f SUB ECX,0x4
00ecc7a2 JC 0x00ecc7b0
00ecc7a4 AND EAX,0x3
00ecc7a7 ADD ECX,EAX
00ecc7a9 JMP dword ptr [EAX*0x4 + 0xecc7bc]
00ecc7b0 JMP dword ptr [ECX*0x4 + 0xecc8b8]
00ecc7b8 JMP dword ptr [ECX*0x4 + 0xecc83c]
00ecc7cc AND EDX,ECX
00ecc7ce MOV AL,byte ptr [ESI]
00ecc7d0 MOV byte ptr [EDI],AL
00ecc7d2 MOV AL,byte ptr [ESI + 0x1]
00ecc7d5 MOV byte ptr [EDI + 0x1],AL
00ecc7d8 MOV AL,byte ptr [ESI + 0x2]
00ecc7db SHR ECX,0x2
00ecc7de MOV byte ptr [EDI + 0x2],AL
00ecc7e1 ADD ESI,0x3
00ecc7e4 ADD EDI,0x3
00ecc7e7 CMP ECX,0x8
00ecc7ea JC 0x00ecc7b8
00ecc7ec MOVSD.REP ES:EDI,ESI
00ecc7ee JMP dword ptr [EDX*0x4 + 0xecc8a8]
00ecc7f8 AND EDX,ECX
00ecc7fa MOV AL,byte ptr [ESI]
00ecc7fc MOV byte ptr [EDI],AL
00ecc7fe MOV AL,byte ptr [ESI + 0x1]
00ecc801 SHR ECX,0x2
00ecc804 MOV byte ptr [EDI + 0x1],AL
00ecc807 ADD ESI,0x2
00ecc80a ADD EDI,0x2
00ecc80d CMP ECX,0x8
00ecc810 JC 0x00ecc7b8
00ecc812 MOVSD.REP ES:EDI,ESI
00ecc814 JMP dword ptr [EDX*0x4 + 0xecc8a8]
00ecc81c AND EDX,ECX
00ecc81e MOV AL,byte ptr [ESI]
00ecc820 MOV byte ptr [EDI],AL
00ecc822 ADD ESI,0x1
00ecc825 SHR ECX,0x2
00ecc828 ADD EDI,0x1
00ecc82b CMP ECX,0x8
00ecc82e JC 0x00ecc7b8
00ecc830 MOVSD.REP ES:EDI,ESI
00ecc832 JMP dword ptr [EDX*0x4 + 0xecc8a8]
00ecc85c MOV EAX,dword ptr [ESI + ECX*0x4 + -0x1c]
00ecc860 MOV dword ptr [EDI + ECX*0x4 + -0x1c],EAX
00ecc864 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x18]
00ecc868 MOV dword ptr [EDI + ECX*0x4 + -0x18],EAX
00ecc86c MOV EAX,dword ptr [ESI + ECX*0x4 + -0x14]
00ecc870 MOV dword ptr [EDI + ECX*0x4 + -0x14],EAX
00ecc874 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x10]
00ecc878 MOV dword ptr [EDI + ECX*0x4 + -0x10],EAX
00ecc87c MOV EAX,dword ptr [ESI + ECX*0x4 + -0xc]
00ecc880 MOV dword ptr [EDI + ECX*0x4 + -0xc],EAX
00ecc884 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x8]
00ecc888 MOV dword ptr [EDI + ECX*0x4 + -0x8],EAX
00ecc88c MOV EAX,dword ptr [ESI + ECX*0x4 + -0x4]
00ecc890 MOV dword ptr [EDI + ECX*0x4 + -0x4],EAX
00ecc894 LEA EAX,[ECX*0x4 + 0x0]
00ecc89b ADD ESI,EAX
00ecc89d ADD EDI,EAX
00ecc89f JMP dword ptr [EDX*0x4 + 0xecc8a8]
00ecc8b8 MOV EAX,dword ptr [ESP + 0xc]
00ecc8bc POP ESI
00ecc8bd POP EDI
00ecc8be RET
00ecc8c0 MOV AL,byte ptr [ESI]
00ecc8c2 MOV byte ptr [EDI],AL
00ecc8c4 MOV EAX,dword ptr [ESP + 0xc]
00ecc8c8 POP ESI
00ecc8c9 POP EDI
00ecc8ca RET
00ecc8cc MOV AL,byte ptr [ESI]
00ecc8ce MOV byte ptr [EDI],AL
00ecc8d0 MOV AL,byte ptr [ESI + 0x1]
00ecc8d3 MOV byte ptr [EDI + 0x1],AL
00ecc8d6 MOV EAX,dword ptr [ESP + 0xc]
00ecc8da POP ESI
00ecc8db POP EDI
00ecc8dc RET
00ecc8e0 MOV AL,byte ptr [ESI]
00ecc8e2 MOV byte ptr [EDI],AL
00ecc8e4 MOV AL,byte ptr [ESI + 0x1]
00ecc8e7 MOV byte ptr [EDI + 0x1],AL
00ecc8ea MOV AL,byte ptr [ESI + 0x2]
00ecc8ed MOV byte ptr [EDI + 0x2],AL
00ecc8f0 MOV EAX,dword ptr [ESP + 0xc]
00ecc8f4 POP ESI
00ecc8f5 POP EDI
00ecc8f6 RET
00ecc8f8 LEA ESI,[ECX + ESI*0x1 + -0x4]
00ecc8fc LEA EDI,[ECX + EDI*0x1 + -0x4]
00ecc900 TEST EDI,0x3
00ecc906 JNZ 0x00ecc92c
00ecc908 SHR ECX,0x2
00ecc90b AND EDX,0x3
00ecc90e CMP ECX,0x8
00ecc911 JC 0x00ecc920
00ecc913 STD
00ecc914 MOVSD.REP ES:EDI,ESI
00ecc916 CLD
00ecc917 JMP dword ptr [EDX*0x4 + 0xecca44]
00ecc920 NEG ECX
00ecc922 JMP dword ptr [ECX*0x4 + 0xecc9f4]
00ecc92c MOV EAX,EDI
00ecc92e MOV EDX,0x3
00ecc933 CMP ECX,0x4
00ecc936 JC 0x00ecc944
00ecc938 AND EAX,0x3
00ecc93b SUB ECX,EAX
00ecc93d JMP dword ptr [EAX*0x4 + 0xecc948]
00ecc944 JMP dword ptr [ECX*0x4 + 0xecca44]
00ecc958 MOV AL,byte ptr [ESI + 0x3]
00ecc95b AND EDX,ECX
00ecc95d MOV byte ptr [EDI + 0x3],AL
00ecc960 SUB ESI,0x1
00ecc963 SHR ECX,0x2
00ecc966 SUB EDI,0x1
00ecc969 CMP ECX,0x8
00ecc96c JC 0x00ecc920
00ecc96e STD
00ecc96f MOVSD.REP ES:EDI,ESI
00ecc971 CLD
00ecc972 JMP dword ptr [EDX*0x4 + 0xecca44]
00ecc97c MOV AL,byte ptr [ESI + 0x3]
00ecc97f AND EDX,ECX
00ecc981 MOV byte ptr [EDI + 0x3],AL
00ecc984 MOV AL,byte ptr [ESI + 0x2]
00ecc987 SHR ECX,0x2
00ecc98a MOV byte ptr [EDI + 0x2],AL
00ecc98d SUB ESI,0x2
00ecc990 SUB EDI,0x2
00ecc993 CMP ECX,0x8
00ecc996 JC 0x00ecc920
00ecc998 STD
00ecc999 MOVSD.REP ES:EDI,ESI
00ecc99b CLD
00ecc99c JMP dword ptr [EDX*0x4 + 0xecca44]
00ecc9a4 MOV AL,byte ptr [ESI + 0x3]
00ecc9a7 AND EDX,ECX
00ecc9a9 MOV byte ptr [EDI + 0x3],AL
00ecc9ac MOV AL,byte ptr [ESI + 0x2]
00ecc9af MOV byte ptr [EDI + 0x2],AL
00ecc9b2 MOV AL,byte ptr [ESI + 0x1]
00ecc9b5 SHR ECX,0x2
00ecc9b8 MOV byte ptr [EDI + 0x1],AL
00ecc9bb SUB ESI,0x3
00ecc9be SUB EDI,0x3
00ecc9c1 CMP ECX,0x8
00ecc9c4 JC 0x00ecc920
00ecc9ca STD
00ecc9cb MOVSD.REP ES:EDI,ESI
00ecc9cd CLD
00ecc9ce JMP dword ptr [EDX*0x4 + 0xecca44]
00ecc9f8 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1c]
00ecc9fc MOV dword ptr [EDI + ECX*0x4 + 0x1c],EAX
00ecca00 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x18]
00ecca04 MOV dword ptr [EDI + ECX*0x4 + 0x18],EAX
00ecca08 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x14]
00ecca0c MOV dword ptr [EDI + ECX*0x4 + 0x14],EAX
00ecca10 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x10]
00ecca14 MOV dword ptr [EDI + ECX*0x4 + 0x10],EAX
00ecca18 MOV EAX,dword ptr [ESI + ECX*0x4 + 0xc]
00ecca1c MOV dword ptr [EDI + ECX*0x4 + 0xc],EAX
00ecca20 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x8]
00ecca24 MOV dword ptr [EDI + ECX*0x4 + 0x8],EAX
00ecca28 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x4]
00ecca2c MOV dword ptr [EDI + ECX*0x4 + 0x4],EAX
00ecca30 LEA EAX,[ECX*0x4 + 0x0]
00ecca37 ADD ESI,EAX
00ecca39 ADD EDI,EAX
00ecca3b JMP dword ptr [EDX*0x4 + 0xecca44]
00ecca54 MOV EAX,dword ptr [ESP + 0xc]
00ecca58 POP ESI
00ecca59 POP EDI
00ecca5a RET
00ecca5c MOV AL,byte ptr [ESI + 0x3]
00ecca5f MOV byte ptr [EDI + 0x3],AL
00ecca62 MOV EAX,dword ptr [ESP + 0xc]
00ecca66 POP ESI
00ecca67 POP EDI
00ecca68 RET
00ecca6c MOV AL,byte ptr [ESI + 0x3]
00ecca6f MOV byte ptr [EDI + 0x3],AL
00ecca72 MOV AL,byte ptr [ESI + 0x2]
00ecca75 MOV byte ptr [EDI + 0x2],AL
00ecca78 MOV EAX,dword ptr [ESP + 0xc]
00ecca7c POP ESI
00ecca7d POP EDI
00ecca7e RET
00ecca80 MOV AL,byte ptr [ESI + 0x3]
00ecca83 MOV byte ptr [EDI + 0x3],AL
00ecca86 MOV AL,byte ptr [ESI + 0x2]
00ecca89 MOV byte ptr [EDI + 0x2],AL
00ecca8c MOV AL,byte ptr [ESI + 0x1]
00ecca8f MOV byte ptr [EDI + 0x1],AL
00ecca92 MOV EAX,dword ptr [ESP + 0xc]
00ecca96 POP ESI
00ecca97 POP EDI
00ecca98 RET
00eccaa0 PUSH EDI
00eccaa1 MOV EAX,ESI
00eccaa3 AND EAX,0xf
00eccaa6 TEST EAX,EAX
00eccaa8 JNZ 0x00eccb80
00eccaae MOV EDX,ECX
00eccab0 AND ECX,0x7f
00eccab3 SHR EDX,0x7
00eccab6 JZ 0x00eccb1d
00eccab8 LEA ESP,[ESP]
00eccabf NOP
00eccac0 MOVDQA XMM0,xmmword ptr [ESI]
00eccac4 MOVDQA XMM1,xmmword ptr [ESI + 0x10]
00eccac9 MOVDQA XMM2,xmmword ptr [ESI + 0x20]
00eccace MOVDQA XMM3,xmmword ptr [ESI + 0x30]
00eccad3 MOVDQA xmmword ptr [EDI],XMM0
00eccad7 MOVDQA xmmword ptr [EDI + 0x10],XMM1
00eccadc MOVDQA xmmword ptr [EDI + 0x20],XMM2
00eccae1 MOVDQA xmmword ptr [EDI + 0x30],XMM3
00eccae6 MOVDQA XMM4,xmmword ptr [ESI + 0x40]
00eccaeb MOVDQA XMM5,xmmword ptr [ESI + 0x50]
00eccaf0 MOVDQA XMM6,xmmword ptr [ESI + 0x60]
00eccaf5 MOVDQA XMM7,xmmword ptr [ESI + 0x70]
00eccafa MOVDQA xmmword ptr [EDI + 0x40],XMM4
00eccaff MOVDQA xmmword ptr [EDI + 0x50],XMM5
00eccb04 MOVDQA xmmword ptr [EDI + 0x60],XMM6
00eccb09 MOVDQA xmmword ptr [EDI + 0x70],XMM7
00eccb0e LEA ESI,[ESI + 0x80]
00eccb14 LEA EDI,[EDI + 0x80]
00eccb1a DEC EDX
00eccb1b JNZ 0x00eccac0
00eccb1d TEST ECX,ECX
00eccb1f JZ 0x00eccb70
00eccb21 MOV EDX,ECX
00eccb23 SHR EDX,0x4
00eccb26 TEST EDX,EDX
00eccb28 JZ 0x00eccb41
00eccb2a LEA EBX,[EBX]
00eccb30 MOVDQA XMM0,xmmword ptr [ESI]
00eccb34 MOVDQA xmmword ptr [EDI],XMM0
00eccb38 LEA ESI,[ESI + 0x10]
00eccb3b LEA EDI,[EDI + 0x10]
00eccb3e DEC EDX
00eccb3f JNZ 0x00eccb30
00eccb41 AND ECX,0xf
00eccb44 JZ 0x00eccb70
00eccb46 MOV EAX,ECX
00eccb48 SHR ECX,0x2
00eccb4b JZ 0x00eccb5a
00eccb4d MOV EDX,dword ptr [ESI]
00eccb4f MOV dword ptr [EDI],EDX
00eccb51 LEA ESI,[ESI + 0x4]
00eccb54 LEA EDI,[EDI + 0x4]
00eccb57 DEC ECX
00eccb58 JNZ 0x00eccb4d
00eccb5a MOV ECX,EAX
00eccb5c AND ECX,0x3
00eccb5f JZ 0x00eccb70
00eccb61 MOV AL,byte ptr [ESI]
00eccb63 MOV byte ptr [EDI],AL
00eccb65 INC ESI
00eccb66 INC EDI
00eccb67 DEC ECX
00eccb68 JNZ 0x00eccb61
00eccb6a LEA EBX,[EBX]
00eccb70 POP EAX
00eccb71 POP ESI
00eccb72 POP EDI
00eccb73 RET
00eccb80 MOV EDX,0x10
00eccb85 SUB EDX,EAX
00eccb87 SUB ECX,EDX
00eccb89 PUSH ECX
00eccb8a MOV EAX,EDX
00eccb8c MOV ECX,EAX
00eccb8e AND ECX,0x3
00eccb91 JZ 0x00eccb9c
00eccb93 MOV DL,byte ptr [ESI]
00eccb95 MOV byte ptr [EDI],DL
00eccb97 INC ESI
00eccb98 INC EDI
00eccb99 DEC ECX
00eccb9a JNZ 0x00eccb93
00eccb9c SHR EAX,0x2
00eccb9f JZ 0x00eccbae
00eccba1 MOV EDX,dword ptr [ESI]
00eccba3 MOV dword ptr [EDI],EDX
00eccba5 LEA ESI,[ESI + 0x4]
00eccba8 LEA EDI,[EDI + 0x4]
00eccbab DEC EAX
00eccbac JNZ 0x00eccba1
00eccbae POP ECX
00eccbaf JMP 0x00eccaae

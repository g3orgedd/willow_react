00ecbd80 PUSH EDI
00ecbd81 PUSH ESI
00ecbd82 MOV ESI,dword ptr [ESP + 0x10]
00ecbd86 MOV ECX,dword ptr [ESP + 0x14]
00ecbd8a MOV EDI,dword ptr [ESP + 0xc]
00ecbd8e MOV EAX,ECX
00ecbd90 MOV EDX,ECX
00ecbd92 ADD EAX,ESI
00ecbd94 CMP EDI,ESI
00ecbd96 JBE 0x00ecbda0
00ecbd98 CMP EDI,EAX
00ecbd9a JC 0x00ecc108
00ecbda0 BT dword ptr [0x00f44fbc],0x1
00ecbda8 JNC 0x00ecbdb1
00ecbdaa MOVSB.REP ES:EDI,ESI
00ecbdac JMP 0x00ecc0c8
00ecbdb1 CMP ECX,0x80
00ecbdb7 JC 0x00ecbf8b
00ecbdbd MOV EAX,EDI
00ecbdbf XOR EAX,ESI
00ecbdc1 TEST EAX,0xf
00ecbdc6 JNZ 0x00ecbdd6
00ecbdc8 BT dword ptr [0x00f39054],0x1
00ecbdd0 JC 0x00ecc2b0
00ecbdd6 BT dword ptr [0x00f44fbc],0x0
00ecbdde JNC 0x00ecbf8b
00ecbde4 TEST EDI,0x3
00ecbdea JNZ 0x00ecbfa8
00ecbdf0 TEST ESI,0x3
00ecbdf6 JNZ 0x00ecbf93
00ecbdfc BT EDI,0x2
00ecbe00 JNC 0x00ecbe0f
00ecbe02 MOV EAX,dword ptr [ESI]
00ecbe04 SUB ECX,0x4
00ecbe07 LEA ESI,[ESI + 0x4]
00ecbe0a MOV dword ptr [EDI],EAX
00ecbe0c LEA EDI,[EDI + 0x4]
00ecbe0f BT EDI,0x3
00ecbe13 JNC 0x00ecbe26
00ecbe15 MOVQ XMM1,qword ptr [ESI]
00ecbe19 SUB ECX,0x8
00ecbe1c LEA ESI,[ESI + 0x8]
00ecbe1f MOVQ qword ptr [EDI],XMM1
00ecbe23 LEA EDI,[EDI + 0x8]
00ecbe26 TEST ESI,0x7
00ecbe2c JZ 0x00ecbe91
00ecbe2e BT ESI,0x3
00ecbe32 JNC 0x00ecbeea
00ecbe38 MOVDQA XMM1,xmmword ptr [ESI + -0xc]
00ecbe3d LEA ESI,[ESI + -0xc]
00ecbe40 MOVDQA XMM3,xmmword ptr [ESI + 0x10]
00ecbe45 SUB ECX,0x30
00ecbe48 MOVDQA XMM0,xmmword ptr [ESI + 0x20]
00ecbe4d MOVDQA XMM5,xmmword ptr [ESI + 0x30]
00ecbe52 LEA ESI,[ESI + 0x30]
00ecbe55 CMP ECX,0x30
00ecbe58 MOVDQA XMM2,XMM3
00ecbe5c PALIGNR XMM3,XMM1,0xc
00ecbe62 MOVDQA xmmword ptr [EDI],XMM3
00ecbe66 MOVDQA XMM4,XMM0
00ecbe6a PALIGNR XMM0,XMM2,0xc
00ecbe70 MOVDQA xmmword ptr [EDI + 0x10],XMM0
00ecbe75 MOVDQA XMM1,XMM5
00ecbe79 PALIGNR XMM5,XMM4,0xc
00ecbe7f MOVDQA xmmword ptr [EDI + 0x20],XMM5
00ecbe84 LEA EDI,[EDI + 0x30]
00ecbe87 JGE 0x00ecbe40
00ecbe89 LEA ESI,[ESI + 0xc]
00ecbe8c JMP 0x00ecbf40
00ecbe91 MOVDQA XMM1,xmmword ptr [ESI + -0x8]
00ecbe96 LEA ESI,[ESI + -0x8]
00ecbe99 LEA ECX,[ECX]
00ecbe9c MOVDQA XMM3,xmmword ptr [ESI + 0x10]
00ecbea1 SUB ECX,0x30
00ecbea4 MOVDQA XMM0,xmmword ptr [ESI + 0x20]
00ecbea9 MOVDQA XMM5,xmmword ptr [ESI + 0x30]
00ecbeae LEA ESI,[ESI + 0x30]
00ecbeb1 CMP ECX,0x30
00ecbeb4 MOVDQA XMM2,XMM3
00ecbeb8 PALIGNR XMM3,XMM1,0x8
00ecbebe MOVDQA xmmword ptr [EDI],XMM3
00ecbec2 MOVDQA XMM4,XMM0
00ecbec6 PALIGNR XMM0,XMM2,0x8
00ecbecc MOVDQA xmmword ptr [EDI + 0x10],XMM0
00ecbed1 MOVDQA XMM1,XMM5
00ecbed5 PALIGNR XMM5,XMM4,0x8
00ecbedb MOVDQA xmmword ptr [EDI + 0x20],XMM5
00ecbee0 LEA EDI,[EDI + 0x30]
00ecbee3 JGE 0x00ecbe9c
00ecbee5 LEA ESI,[ESI + 0x8]
00ecbee8 JMP 0x00ecbf40
00ecbeea MOVDQA XMM1,xmmword ptr [ESI + -0x4]
00ecbeef LEA ESI,[ESI + -0x4]
00ecbef2 MOV EDI,EDI
00ecbef4 MOVDQA XMM3,xmmword ptr [ESI + 0x10]
00ecbef9 SUB ECX,0x30
00ecbefc MOVDQA XMM0,xmmword ptr [ESI + 0x20]
00ecbf01 MOVDQA XMM5,xmmword ptr [ESI + 0x30]
00ecbf06 LEA ESI,[ESI + 0x30]
00ecbf09 CMP ECX,0x30
00ecbf0c MOVDQA XMM2,XMM3
00ecbf10 PALIGNR XMM3,XMM1,0x4
00ecbf16 MOVDQA xmmword ptr [EDI],XMM3
00ecbf1a MOVDQA XMM4,XMM0
00ecbf1e PALIGNR XMM0,XMM2,0x4
00ecbf24 MOVDQA xmmword ptr [EDI + 0x10],XMM0
00ecbf29 MOVDQA XMM1,XMM5
00ecbf2d PALIGNR XMM5,XMM4,0x4
00ecbf33 MOVDQA xmmword ptr [EDI + 0x20],XMM5
00ecbf38 LEA EDI,[EDI + 0x30]
00ecbf3b JGE 0x00ecbef4
00ecbf3d LEA ESI,[ESI + 0x4]
00ecbf40 CMP ECX,0x10
00ecbf43 JL 0x00ecbf58
00ecbf45 MOVDQU XMM1,xmmword ptr [ESI]
00ecbf49 SUB ECX,0x10
00ecbf4c LEA ESI,[ESI + 0x10]
00ecbf4f MOVDQA xmmword ptr [EDI],XMM1
00ecbf53 LEA EDI,[EDI + 0x10]
00ecbf56 JMP 0x00ecbf40
00ecbf58 BT ECX,0x2
00ecbf5c JNC 0x00ecbf6b
00ecbf5e MOV EAX,dword ptr [ESI]
00ecbf60 SUB ECX,0x4
00ecbf63 LEA ESI,[ESI + 0x4]
00ecbf66 MOV dword ptr [EDI],EAX
00ecbf68 LEA EDI,[EDI + 0x4]
00ecbf6b BT ECX,0x3
00ecbf6f JNC 0x00ecbf82
00ecbf71 MOVQ XMM1,qword ptr [ESI]
00ecbf75 SUB ECX,0x8
00ecbf78 LEA ESI,[ESI + 0x8]
00ecbf7b MOVQ qword ptr [EDI],XMM1
00ecbf7f LEA EDI,[EDI + 0x8]
00ecbf82 MOV EAX,dword ptr [ECX*0x4 + 0xecc0b8]
00ecbf89 JMP EAX
00ecbf8b TEST EDI,0x3
00ecbf91 JNZ 0x00ecbfa8
00ecbf93 SHR ECX,0x2
00ecbf96 AND EDX,0x3
00ecbf99 CMP ECX,0x8
00ecbf9c JC 0x00ecbfc8
00ecbf9e MOVSD.REP ES:EDI,ESI
00ecbfa0 JMP dword ptr [EDX*0x4 + 0xecc0b8]
00ecbfa8 MOV EAX,EDI
00ecbfaa MOV EDX,0x3
00ecbfaf SUB ECX,0x4
00ecbfb2 JC 0x00ecbfc0
00ecbfb4 AND EAX,0x3
00ecbfb7 ADD ECX,EAX
00ecbfb9 JMP dword ptr [EAX*0x4 + 0xecbfcc]
00ecbfc0 JMP dword ptr [ECX*0x4 + 0xecc0c8]
00ecbfc8 JMP dword ptr [ECX*0x4 + 0xecc04c]
00ecbfdc AND EDX,ECX
00ecbfde MOV AL,byte ptr [ESI]
00ecbfe0 MOV byte ptr [EDI],AL
00ecbfe2 MOV AL,byte ptr [ESI + 0x1]
00ecbfe5 MOV byte ptr [EDI + 0x1],AL
00ecbfe8 MOV AL,byte ptr [ESI + 0x2]
00ecbfeb SHR ECX,0x2
00ecbfee MOV byte ptr [EDI + 0x2],AL
00ecbff1 ADD ESI,0x3
00ecbff4 ADD EDI,0x3
00ecbff7 CMP ECX,0x8
00ecbffa JC 0x00ecbfc8
00ecbffc MOVSD.REP ES:EDI,ESI
00ecbffe JMP dword ptr [EDX*0x4 + 0xecc0b8]
00ecc008 AND EDX,ECX
00ecc00a MOV AL,byte ptr [ESI]
00ecc00c MOV byte ptr [EDI],AL
00ecc00e MOV AL,byte ptr [ESI + 0x1]
00ecc011 SHR ECX,0x2
00ecc014 MOV byte ptr [EDI + 0x1],AL
00ecc017 ADD ESI,0x2
00ecc01a ADD EDI,0x2
00ecc01d CMP ECX,0x8
00ecc020 JC 0x00ecbfc8
00ecc022 MOVSD.REP ES:EDI,ESI
00ecc024 JMP dword ptr [EDX*0x4 + 0xecc0b8]
00ecc02c AND EDX,ECX
00ecc02e MOV AL,byte ptr [ESI]
00ecc030 MOV byte ptr [EDI],AL
00ecc032 ADD ESI,0x1
00ecc035 SHR ECX,0x2
00ecc038 ADD EDI,0x1
00ecc03b CMP ECX,0x8
00ecc03e JC 0x00ecbfc8
00ecc040 MOVSD.REP ES:EDI,ESI
00ecc042 JMP dword ptr [EDX*0x4 + 0xecc0b8]
00ecc06c MOV EAX,dword ptr [ESI + ECX*0x4 + -0x1c]
00ecc070 MOV dword ptr [EDI + ECX*0x4 + -0x1c],EAX
00ecc074 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x18]
00ecc078 MOV dword ptr [EDI + ECX*0x4 + -0x18],EAX
00ecc07c MOV EAX,dword ptr [ESI + ECX*0x4 + -0x14]
00ecc080 MOV dword ptr [EDI + ECX*0x4 + -0x14],EAX
00ecc084 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x10]
00ecc088 MOV dword ptr [EDI + ECX*0x4 + -0x10],EAX
00ecc08c MOV EAX,dword ptr [ESI + ECX*0x4 + -0xc]
00ecc090 MOV dword ptr [EDI + ECX*0x4 + -0xc],EAX
00ecc094 MOV EAX,dword ptr [ESI + ECX*0x4 + -0x8]
00ecc098 MOV dword ptr [EDI + ECX*0x4 + -0x8],EAX
00ecc09c MOV EAX,dword ptr [ESI + ECX*0x4 + -0x4]
00ecc0a0 MOV dword ptr [EDI + ECX*0x4 + -0x4],EAX
00ecc0a4 LEA EAX,[ECX*0x4 + 0x0]
00ecc0ab ADD ESI,EAX
00ecc0ad ADD EDI,EAX
00ecc0af JMP dword ptr [EDX*0x4 + 0xecc0b8]
00ecc0c8 MOV EAX,dword ptr [ESP + 0xc]
00ecc0cc POP ESI
00ecc0cd POP EDI
00ecc0ce RET
00ecc0d0 MOV AL,byte ptr [ESI]
00ecc0d2 MOV byte ptr [EDI],AL
00ecc0d4 MOV EAX,dword ptr [ESP + 0xc]
00ecc0d8 POP ESI
00ecc0d9 POP EDI
00ecc0da RET
00ecc0dc MOV AL,byte ptr [ESI]
00ecc0de MOV byte ptr [EDI],AL
00ecc0e0 MOV AL,byte ptr [ESI + 0x1]
00ecc0e3 MOV byte ptr [EDI + 0x1],AL
00ecc0e6 MOV EAX,dword ptr [ESP + 0xc]
00ecc0ea POP ESI
00ecc0eb POP EDI
00ecc0ec RET
00ecc0f0 MOV AL,byte ptr [ESI]
00ecc0f2 MOV byte ptr [EDI],AL
00ecc0f4 MOV AL,byte ptr [ESI + 0x1]
00ecc0f7 MOV byte ptr [EDI + 0x1],AL
00ecc0fa MOV AL,byte ptr [ESI + 0x2]
00ecc0fd MOV byte ptr [EDI + 0x2],AL
00ecc100 MOV EAX,dword ptr [ESP + 0xc]
00ecc104 POP ESI
00ecc105 POP EDI
00ecc106 RET
00ecc108 LEA ESI,[ECX + ESI*0x1 + -0x4]
00ecc10c LEA EDI,[ECX + EDI*0x1 + -0x4]
00ecc110 TEST EDI,0x3
00ecc116 JNZ 0x00ecc13c
00ecc118 SHR ECX,0x2
00ecc11b AND EDX,0x3
00ecc11e CMP ECX,0x8
00ecc121 JC 0x00ecc130
00ecc123 STD
00ecc124 MOVSD.REP ES:EDI,ESI
00ecc126 CLD
00ecc127 JMP dword ptr [EDX*0x4 + 0xecc254]
00ecc130 NEG ECX
00ecc132 JMP dword ptr [ECX*0x4 + 0xecc204]
00ecc13c MOV EAX,EDI
00ecc13e MOV EDX,0x3
00ecc143 CMP ECX,0x4
00ecc146 JC 0x00ecc154
00ecc148 AND EAX,0x3
00ecc14b SUB ECX,EAX
00ecc14d JMP dword ptr [EAX*0x4 + 0xecc158]
00ecc154 JMP dword ptr [ECX*0x4 + 0xecc254]
00ecc168 MOV AL,byte ptr [ESI + 0x3]
00ecc16b AND EDX,ECX
00ecc16d MOV byte ptr [EDI + 0x3],AL
00ecc170 SUB ESI,0x1
00ecc173 SHR ECX,0x2
00ecc176 SUB EDI,0x1
00ecc179 CMP ECX,0x8
00ecc17c JC 0x00ecc130
00ecc17e STD
00ecc17f MOVSD.REP ES:EDI,ESI
00ecc181 CLD
00ecc182 JMP dword ptr [EDX*0x4 + 0xecc254]
00ecc18c MOV AL,byte ptr [ESI + 0x3]
00ecc18f AND EDX,ECX
00ecc191 MOV byte ptr [EDI + 0x3],AL
00ecc194 MOV AL,byte ptr [ESI + 0x2]
00ecc197 SHR ECX,0x2
00ecc19a MOV byte ptr [EDI + 0x2],AL
00ecc19d SUB ESI,0x2
00ecc1a0 SUB EDI,0x2
00ecc1a3 CMP ECX,0x8
00ecc1a6 JC 0x00ecc130
00ecc1a8 STD
00ecc1a9 MOVSD.REP ES:EDI,ESI
00ecc1ab CLD
00ecc1ac JMP dword ptr [EDX*0x4 + 0xecc254]
00ecc1b4 MOV AL,byte ptr [ESI + 0x3]
00ecc1b7 AND EDX,ECX
00ecc1b9 MOV byte ptr [EDI + 0x3],AL
00ecc1bc MOV AL,byte ptr [ESI + 0x2]
00ecc1bf MOV byte ptr [EDI + 0x2],AL
00ecc1c2 MOV AL,byte ptr [ESI + 0x1]
00ecc1c5 SHR ECX,0x2
00ecc1c8 MOV byte ptr [EDI + 0x1],AL
00ecc1cb SUB ESI,0x3
00ecc1ce SUB EDI,0x3
00ecc1d1 CMP ECX,0x8
00ecc1d4 JC 0x00ecc130
00ecc1da STD
00ecc1db MOVSD.REP ES:EDI,ESI
00ecc1dd CLD
00ecc1de JMP dword ptr [EDX*0x4 + 0xecc254]
00ecc208 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x1c]
00ecc20c MOV dword ptr [EDI + ECX*0x4 + 0x1c],EAX
00ecc210 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x18]
00ecc214 MOV dword ptr [EDI + ECX*0x4 + 0x18],EAX
00ecc218 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x14]
00ecc21c MOV dword ptr [EDI + ECX*0x4 + 0x14],EAX
00ecc220 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x10]
00ecc224 MOV dword ptr [EDI + ECX*0x4 + 0x10],EAX
00ecc228 MOV EAX,dword ptr [ESI + ECX*0x4 + 0xc]
00ecc22c MOV dword ptr [EDI + ECX*0x4 + 0xc],EAX
00ecc230 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x8]
00ecc234 MOV dword ptr [EDI + ECX*0x4 + 0x8],EAX
00ecc238 MOV EAX,dword ptr [ESI + ECX*0x4 + 0x4]
00ecc23c MOV dword ptr [EDI + ECX*0x4 + 0x4],EAX
00ecc240 LEA EAX,[ECX*0x4 + 0x0]
00ecc247 ADD ESI,EAX
00ecc249 ADD EDI,EAX
00ecc24b JMP dword ptr [EDX*0x4 + 0xecc254]
00ecc264 MOV EAX,dword ptr [ESP + 0xc]
00ecc268 POP ESI
00ecc269 POP EDI
00ecc26a RET
00ecc26c MOV AL,byte ptr [ESI + 0x3]
00ecc26f MOV byte ptr [EDI + 0x3],AL
00ecc272 MOV EAX,dword ptr [ESP + 0xc]
00ecc276 POP ESI
00ecc277 POP EDI
00ecc278 RET
00ecc27c MOV AL,byte ptr [ESI + 0x3]
00ecc27f MOV byte ptr [EDI + 0x3],AL
00ecc282 MOV AL,byte ptr [ESI + 0x2]
00ecc285 MOV byte ptr [EDI + 0x2],AL
00ecc288 MOV EAX,dword ptr [ESP + 0xc]
00ecc28c POP ESI
00ecc28d POP EDI
00ecc28e RET
00ecc290 MOV AL,byte ptr [ESI + 0x3]
00ecc293 MOV byte ptr [EDI + 0x3],AL
00ecc296 MOV AL,byte ptr [ESI + 0x2]
00ecc299 MOV byte ptr [EDI + 0x2],AL
00ecc29c MOV AL,byte ptr [ESI + 0x1]
00ecc29f MOV byte ptr [EDI + 0x1],AL
00ecc2a2 MOV EAX,dword ptr [ESP + 0xc]
00ecc2a6 POP ESI
00ecc2a7 POP EDI
00ecc2a8 RET
00ecc2b0 PUSH EDI
00ecc2b1 MOV EAX,ESI
00ecc2b3 AND EAX,0xf
00ecc2b6 TEST EAX,EAX
00ecc2b8 JNZ 0x00ecc390
00ecc2be MOV EDX,ECX
00ecc2c0 AND ECX,0x7f
00ecc2c3 SHR EDX,0x7
00ecc2c6 JZ 0x00ecc32d
00ecc2c8 LEA ESP,[ESP]
00ecc2cf NOP
00ecc2d0 MOVDQA XMM0,xmmword ptr [ESI]
00ecc2d4 MOVDQA XMM1,xmmword ptr [ESI + 0x10]
00ecc2d9 MOVDQA XMM2,xmmword ptr [ESI + 0x20]
00ecc2de MOVDQA XMM3,xmmword ptr [ESI + 0x30]
00ecc2e3 MOVDQA xmmword ptr [EDI],XMM0
00ecc2e7 MOVDQA xmmword ptr [EDI + 0x10],XMM1
00ecc2ec MOVDQA xmmword ptr [EDI + 0x20],XMM2
00ecc2f1 MOVDQA xmmword ptr [EDI + 0x30],XMM3
00ecc2f6 MOVDQA XMM4,xmmword ptr [ESI + 0x40]
00ecc2fb MOVDQA XMM5,xmmword ptr [ESI + 0x50]
00ecc300 MOVDQA XMM6,xmmword ptr [ESI + 0x60]
00ecc305 MOVDQA XMM7,xmmword ptr [ESI + 0x70]
00ecc30a MOVDQA xmmword ptr [EDI + 0x40],XMM4
00ecc30f MOVDQA xmmword ptr [EDI + 0x50],XMM5
00ecc314 MOVDQA xmmword ptr [EDI + 0x60],XMM6
00ecc319 MOVDQA xmmword ptr [EDI + 0x70],XMM7
00ecc31e LEA ESI,[ESI + 0x80]
00ecc324 LEA EDI,[EDI + 0x80]
00ecc32a DEC EDX
00ecc32b JNZ 0x00ecc2d0
00ecc32d TEST ECX,ECX
00ecc32f JZ 0x00ecc380
00ecc331 MOV EDX,ECX
00ecc333 SHR EDX,0x4
00ecc336 TEST EDX,EDX
00ecc338 JZ 0x00ecc351
00ecc33a LEA EBX,[EBX]
00ecc340 MOVDQA XMM0,xmmword ptr [ESI]
00ecc344 MOVDQA xmmword ptr [EDI],XMM0
00ecc348 LEA ESI,[ESI + 0x10]
00ecc34b LEA EDI,[EDI + 0x10]
00ecc34e DEC EDX
00ecc34f JNZ 0x00ecc340
00ecc351 AND ECX,0xf
00ecc354 JZ 0x00ecc380
00ecc356 MOV EAX,ECX
00ecc358 SHR ECX,0x2
00ecc35b JZ 0x00ecc36a
00ecc35d MOV EDX,dword ptr [ESI]
00ecc35f MOV dword ptr [EDI],EDX
00ecc361 LEA ESI,[ESI + 0x4]
00ecc364 LEA EDI,[EDI + 0x4]
00ecc367 DEC ECX
00ecc368 JNZ 0x00ecc35d
00ecc36a MOV ECX,EAX
00ecc36c AND ECX,0x3
00ecc36f JZ 0x00ecc380
00ecc371 MOV AL,byte ptr [ESI]
00ecc373 MOV byte ptr [EDI],AL
00ecc375 INC ESI
00ecc376 INC EDI
00ecc377 DEC ECX
00ecc378 JNZ 0x00ecc371
00ecc37a LEA EBX,[EBX]
00ecc380 POP EAX
00ecc381 POP ESI
00ecc382 POP EDI
00ecc383 RET
00ecc390 MOV EDX,0x10
00ecc395 SUB EDX,EAX
00ecc397 SUB ECX,EDX
00ecc399 PUSH ECX
00ecc39a MOV EAX,EDX
00ecc39c MOV ECX,EAX
00ecc39e AND ECX,0x3
00ecc3a1 JZ 0x00ecc3ac
00ecc3a3 MOV DL,byte ptr [ESI]
00ecc3a5 MOV byte ptr [EDI],DL
00ecc3a7 INC ESI
00ecc3a8 INC EDI
00ecc3a9 DEC ECX
00ecc3aa JNZ 0x00ecc3a3
00ecc3ac SHR EAX,0x2
00ecc3af JZ 0x00ecc3be
00ecc3b1 MOV EDX,dword ptr [ESI]
00ecc3b3 MOV dword ptr [EDI],EDX
00ecc3b5 LEA ESI,[ESI + 0x4]
00ecc3b8 LEA EDI,[EDI + 0x4]
00ecc3bb DEC EAX
00ecc3bc JNZ 0x00ecc3b1
00ecc3be POP ECX
00ecc3bf JMP 0x00ecc2be

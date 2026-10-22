4542fb9c PUSH EBP
4542fb9d MOV EBP,ESP
4542fb9f SUB ESP,0x28
4542fba2 XOR EAX,EAX
4542fba4 MOV dword ptr [EBP + -0x8],EAX
4542fba7 MOV dword ptr [EBP + -0x4],EAX
4542fbaa CMP dword ptr [0x45460b88],EAX
4542fbb0 JZ 0x4542fbc2
4542fbb2 PUSH dword ptr [0x4546279c]
4542fbb8 CALL dword ptr [0x454470f0]
4542fbbe MOV ECX,EAX
4542fbc0 JMP 0x4542fbc7
4542fbc2 MOV ECX,0x4543ab73
4542fbc7 MOV EAX,dword ptr [EBP + 0x14]
4542fbca MOV EDX,0xa6
4542fbcf PUSH ESI
4542fbd0 CMP EAX,EDX
4542fbd2 JG 0x4542fd74
4542fbd8 JZ 0x4542fd61
4542fbde CMP EAX,0x19
4542fbe1 JG 0x4542fcea
4542fbe7 JZ 0x4542fce1
4542fbed PUSH 0x2
4542fbef POP EDX
4542fbf0 SUB EAX,EDX
4542fbf2 JZ 0x4542fcd2
4542fbf8 DEC EAX
4542fbf9 JZ 0x4542fcc6
4542fbff SUB EAX,0x5
4542fc02 JZ 0x4542fcb7
4542fc08 DEC EAX
4542fc09 JZ 0x4542fcab
4542fc0f SUB EAX,0x5
4542fc12 JZ 0x4542fc9b
4542fc18 DEC EAX
4542fc19 JZ 0x4542fc69
4542fc1b SUB EAX,0x9
4542fc1e JNZ 0x4542fe47
4542fc24 MOV dword ptr [EBP + -0x28],0x3
4542fc2b MOV dword ptr [EBP + -0x24],0x4544c190
4542fc32 MOV EAX,dword ptr [EBP + 0x8]
4542fc35 MOV ESI,dword ptr [EBP + 0x10]
4542fc38 FLD double ptr [EAX]
4542fc3a MOV EAX,dword ptr [EBP + 0xc]
4542fc3d FSTP double ptr [EBP + -0x20]
4542fc40 FLD double ptr [EAX]
4542fc42 LEA EAX,[EBP + -0x28]
4542fc45 FSTP double ptr [EBP + -0x18]
4542fc48 FLD double ptr [ESI]
4542fc4a PUSH EAX
4542fc4b FSTP double ptr [EBP + -0x10]
4542fc4e CALL ECX
4542fc50 POP ECX
4542fc51 TEST EAX,EAX
4542fc53 JNZ 0x4542fe42
4542fc59 CALL 0x45431fc5
4542fc5e MOV dword ptr [EAX],0x22
4542fc64 JMP 0x4542fe42
4542fc69 MOV dword ptr [EBP + -0x24],0x4544c18c
4542fc70 MOV EAX,dword ptr [EBP + 0x8]
4542fc73 MOV ESI,dword ptr [EBP + 0x10]
4542fc76 MOV dword ptr [EBP + -0x28],0x4
4542fc7d FLD double ptr [EAX]
4542fc7f MOV EAX,dword ptr [EBP + 0xc]
4542fc82 FSTP double ptr [EBP + -0x20]
4542fc85 FLD double ptr [EAX]
4542fc87 LEA EAX,[EBP + -0x28]
4542fc8a FSTP double ptr [EBP + -0x18]
4542fc8d FLD double ptr [ESI]
4542fc8f PUSH EAX
4542fc90 FSTP double ptr [EBP + -0x10]
4542fc93 CALL ECX
4542fc95 POP ECX
4542fc96 JMP 0x4542fe42
4542fc9b MOV dword ptr [EBP + -0x28],0x3
4542fca2 MOV dword ptr [EBP + -0x24],0x4544c18c
4542fca9 JMP 0x4542fc32
4542fcab MOV dword ptr [EBP + -0x24],0x4544c184
4542fcb2 JMP 0x4542fe0d
4542fcb7 MOV dword ptr [EBP + -0x28],EDX
4542fcba MOV dword ptr [EBP + -0x24],0x4544c184
4542fcc1 JMP 0x4542fc32
4542fcc6 MOV dword ptr [EBP + -0x24],0x4544c180
4542fccd JMP 0x4542fe0d
4542fcd2 MOV dword ptr [EBP + -0x28],EDX
4542fcd5 MOV dword ptr [EBP + -0x24],0x4544c180
4542fcdc JMP 0x4542fc32
4542fce1 MOV dword ptr [EBP + -0x24],0x4544c190
4542fce8 JMP 0x4542fc70
4542fcea SUB EAX,0x1a
4542fced JZ 0x4542fd55
4542fcef DEC EAX
4542fcf0 JZ 0x4542fd49
4542fcf2 DEC EAX
4542fcf3 JZ 0x4542fd3d
4542fcf5 DEC EAX
4542fcf6 JZ 0x4542fd27
4542fcf8 SUB EAX,0x14
4542fcfb JZ 0x4542fe06
4542fd01 SUB EAX,0x9
4542fd04 JZ 0x4542fd1b
4542fd06 SUB EAX,0x3
4542fd09 JNZ 0x4542fe47
4542fd0f MOV dword ptr [EBP + -0x24],0x4544c194
4542fd16 JMP 0x4542fe0d
4542fd1b MOV dword ptr [EBP + -0x24],0x4544c19c
4542fd22 JMP 0x4542fe0d
4542fd27 MOV dword ptr [EBP + -0x24],0x4544c190
4542fd2e MOV EAX,dword ptr [EBP + 0x8]
4542fd31 MOV ESI,dword ptr [EBP + 0x10]
4542fd34 FLD double ptr [EAX]
4542fd36 FSTP double ptr [ESI]
4542fd38 JMP 0x4542fe13
4542fd3d MOV dword ptr [EBP + -0x24],0x4544c190
4542fd44 JMP 0x4542fe0d
4542fd49 MOV dword ptr [EBP + -0x28],0x2
4542fd50 JMP 0x4542fc2b
4542fd55 MOV EAX,dword ptr [EBP + 0x10]
4542fd58 FLD1
4542fd5a FSTP double ptr [EAX]
4542fd5c JMP 0x4542fe47
4542fd61 MOV dword ptr [EBP + -0x28],0x3
4542fd68 MOV dword ptr [EBP + -0x24],0x4544c1a4
4542fd6f JMP 0x4542fc32
4542fd74 ADD EAX,0xfffffc18
4542fd79 CMP EAX,0xd
4542fd7c JA 0x4542fe47
4542fd82 JMP dword ptr [EAX*0x4 + 0x4542fe4c]
4542fd89 MOV dword ptr [EBP + -0x24],0x4544c180
4542fd90 JMP 0x4542fd2e
4542fd92 MOV dword ptr [EBP + -0x24],0x4544c184
4542fd99 JMP 0x4542fd2e
4542fd9b MOV dword ptr [EBP + -0x24],0x4544c18c
4542fda2 JMP 0x4542fd2e
4542fda4 MOV dword ptr [EBP + -0x24],0x4544c1ac
4542fdab JMP 0x4542fd2e
4542fdad MOV dword ptr [EBP + -0x24],0x4544c1b4
4542fdb4 JMP 0x4542fd2e
4542fdb9 MOV dword ptr [EBP + -0x24],0x4544c1bc
4542fdc0 JMP 0x4542fd2e
4542fdc5 MOV dword ptr [EBP + -0x24],0x4544c1c4
4542fdcc JMP 0x4542fd2e
4542fdd1 MOV dword ptr [EBP + -0x24],0x4544c1cc
4542fdd8 MOV EAX,dword ptr [EBP + 0x8]
4542fddb MOV ESI,dword ptr [EBP + 0x10]
4542fdde FLD double ptr [EAX]
4542fde0 FMUL double ptr [EBP + -0x8]
4542fde3 FST double ptr [ESI]
4542fde5 FLD double ptr [EAX]
4542fde7 MOV EAX,dword ptr [EBP + 0xc]
4542fdea FSTP double ptr [EBP + -0x20]
4542fded FLD double ptr [EAX]
4542fdef FSTP double ptr [EBP + -0x18]
4542fdf2 JMP 0x4542fe22
4542fdf4 MOV dword ptr [EBP + -0x24],0x4544c1d0
4542fdfb JMP 0x4542fdd8
4542fdfd MOV dword ptr [EBP + -0x24],0x4544c1d4
4542fe04 JMP 0x4542fdd8
4542fe06 MOV dword ptr [EBP + -0x24],0x4544c1d8
4542fe0d MOV EAX,dword ptr [EBP + 0x8]
4542fe10 MOV ESI,dword ptr [EBP + 0x10]
4542fe13 FLD double ptr [EAX]
4542fe15 MOV EAX,dword ptr [EBP + 0xc]
4542fe18 FSTP double ptr [EBP + -0x20]
4542fe1b FLD double ptr [EAX]
4542fe1d FSTP double ptr [EBP + -0x18]
4542fe20 FLD double ptr [ESI]
4542fe22 LEA EAX,[EBP + -0x28]
4542fe25 MOV dword ptr [EBP + -0x28],0x1
4542fe2c PUSH EAX
4542fe2d FSTP double ptr [EBP + -0x10]
4542fe30 CALL ECX
4542fe32 POP ECX
4542fe33 TEST EAX,EAX
4542fe35 JNZ 0x4542fe42
4542fe37 CALL 0x45431fc5
4542fe3c MOV dword ptr [EAX],0x21
4542fe42 FLD double ptr [EBP + -0x10]
4542fe45 FSTP double ptr [ESI]
4542fe47 POP ESI
4542fe48 MOV ESP,EBP
4542fe4a POP EBP
4542fe4b RET

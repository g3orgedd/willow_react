00e2ca77 PUSH 0x64
00e2ca79 MOV EAX,0xeeb23f
00e2ca7e CALL 0x00ec9e5a
00e2ca83 MOV EDI,ECX
00e2ca85 XOR EBX,EBX
00e2ca87 LEA ECX,[EDI + 0x4]
00e2ca8a PUSH EBX
00e2ca8b CALL 0x00e77808
00e2ca90 MOV EAX,dword ptr [EAX]
00e2ca92 TEST EAX,EAX
00e2ca94 JZ 0x00e2ca9e
00e2ca96 ADD EAX,-0x64
00e2ca99 MOV dword ptr [EBP + -0x10],EAX
00e2ca9c JMP 0x00e2caa1
00e2ca9e MOV dword ptr [EBP + -0x10],EBX
00e2caa1 MOV dword ptr [EBP + -0x14],EBX
00e2caa4 MOV ESI,dword ptr [EBP + 0x8]
00e2caa7 LEA EDX,[EBP + -0x14]
00e2caaa PUSH EDX
00e2caab MOV dword ptr [EBP + -0x4],EBX
00e2caae MOV EAX,dword ptr [ESI + 0x4]
00e2cab1 PUSH EAX
00e2cab2 MOV ECX,dword ptr [EAX]
00e2cab4 CALL dword ptr [ECX + 0x68]
00e2cab7 PUSH 0xefd464
00e2cabc LEA ECX,[EBP + -0x14]
00e2cabf CALL 0x00e03edc
00e2cac4 TEST AL,AL
00e2cac6 JNZ 0x00e2cadd
00e2cac8 PUSH 0xefcfd4
00e2cacd LEA ECX,[EBP + -0x14]
00e2cad0 CALL 0x00e03edc
00e2cad5 TEST AL,AL
00e2cad7 JZ 0x00e2cce7
00e2cadd MOV dword ptr [EBP + 0x8],EBX
00e2cae0 MOV dword ptr [EBP + -0x28],EBX
00e2cae3 MOV EAX,dword ptr [ESI + 0x4]
00e2cae6 LEA EDX,[EBP + -0x28]
00e2cae9 PUSH EDX
00e2caea PUSH EAX
00e2caeb MOV byte ptr [EBP + -0x4],0x2
00e2caef MOV ECX,dword ptr [EAX]
00e2caf1 CALL dword ptr [ECX + 0x5c]
00e2caf4 LEA ECX,[EBP + -0x70]
00e2caf7 CALL 0x00e03b51
00e2cafc MOV EAX,dword ptr [EBP + -0x28]
00e2caff LEA EDX,[EBP + -0x70]
00e2cb02 PUSH EDX
00e2cb03 PUSH 0x1
00e2cb05 PUSH EAX
00e2cb06 MOV ECX,dword ptr [EAX]
00e2cb08 MOV byte ptr [EBP + -0x4],0x3
00e2cb0c CALL dword ptr [ECX + 0x24]
00e2cb0f CMP word ptr [EBP + -0x70],0x0
00e2cb14 JZ 0x00e2ccc0
00e2cb1a PUSH dword ptr [EBP + -0x68]
00e2cb1d LEA ECX,[EBP + -0x24]
00e2cb20 CALL 0x00e0986a
00e2cb25 MOV EAX,dword ptr [EBP + -0x24]
00e2cb28 LEA EDX,[EBP + -0x2c]
00e2cb2b MOV dword ptr [EBP + -0x2c],EBX
00e2cb2e PUSH EDX
00e2cb2f PUSH EAX
00e2cb30 MOV ECX,dword ptr [EAX]
00e2cb32 MOV byte ptr [EBP + -0x4],0x4
00e2cb36 CALL dword ptr [ECX + 0x28]
00e2cb39 CMP dword ptr [EBP + -0x2c],0x4
00e2cb3d JNZ 0x00e2ccaf
00e2cb43 MOV EAX,dword ptr [EBP + -0x24]
00e2cb46 LEA EDX,[EBP + 0x8]
00e2cb49 PUSH EDX
00e2cb4a PUSH EAX
00e2cb4b MOV ECX,dword ptr [EAX]
00e2cb4d CALL dword ptr [ECX + 0xb4]
00e2cb53 LEA ECX,[EBP + -0x60]
00e2cb56 CALL 0x00e03b51
00e2cb5b MOV EAX,dword ptr [EDI + 0x19c]
00e2cb61 LEA EDX,[EBP + -0x60]
00e2cb64 PUSH EDX
00e2cb65 PUSH EAX
00e2cb66 MOV byte ptr [EBP + -0x4],0x5
00e2cb6a MOV ECX,dword ptr [EAX]
00e2cb6c CALL dword ptr [ECX + 0x64]
00e2cb6f CMP word ptr [EBP + -0x60],0x0
00e2cb74 JZ 0x00e2cca5
00e2cb7a PUSH dword ptr [EBP + -0x58]
00e2cb7d LEA ECX,[EBP + -0x1c]
00e2cb80 CALL 0x00e0e8b0
00e2cb85 LEA ECX,[EBP + -0x50]
00e2cb88 CALL 0x00e03b51
00e2cb8d MOV EAX,dword ptr [EBP + -0x1c]
00e2cb90 LEA EDX,[EBP + -0x50]
00e2cb93 PUSH EDX
00e2cb94 PUSH dword ptr [EBP + 0x8]
00e2cb97 MOV byte ptr [EBP + -0x4],0x7
00e2cb9b MOV ECX,dword ptr [EAX]
00e2cb9d PUSH EAX
00e2cb9e CALL dword ptr [ECX + 0x28]
00e2cba1 CMP word ptr [EBP + -0x50],0x0
00e2cba6 JZ 0x00e2cc8a
00e2cbac PUSH dword ptr [EBP + -0x48]
00e2cbaf LEA ECX,[EBP + -0x20]
00e2cbb2 CALL 0x00e09aa8
00e2cbb7 MOV EAX,dword ptr [EBP + -0x20]
00e2cbba LEA EDX,[EBP + -0x34]
00e2cbbd PUSH EDX
00e2cbbe PUSH EAX
00e2cbbf MOV byte ptr [EBP + -0x4],0x8
00e2cbc3 MOV ECX,dword ptr [EAX]
00e2cbc5 CALL dword ptr [ECX + 0x24]
00e2cbc8 MOV EAX,dword ptr [EBP + -0x20]
00e2cbcb LEA EDX,[EBP + -0x30]
00e2cbce PUSH EDX
00e2cbcf PUSH EAX
00e2cbd0 MOV ECX,dword ptr [EAX]
00e2cbd2 CALL dword ptr [ECX + 0x4c]
00e2cbd5 CMP dword ptr [EBP + -0x34],0x0
00e2cbd9 JZ 0x00e2cbf2
00e2cbdb CMP dword ptr [EBP + -0x30],0x2
00e2cbdf JNZ 0x00e2cbf2
00e2cbe1 MOV EAX,dword ptr [EBP + -0x1c]
00e2cbe4 PUSH dword ptr [EBP + 0x8]
00e2cbe7 PUSH EAX
00e2cbe8 MOV ECX,dword ptr [EAX]
00e2cbea CALL dword ptr [ECX + 0x24]
00e2cbed JMP 0x00e2cc79
00e2cbf2 MOV dword ptr [EBP + -0x18],EBX
00e2cbf5 MOV EAX,dword ptr [ESI + 0x4]
00e2cbf8 LEA EDX,[EBP + -0x18]
00e2cbfb PUSH EDX
00e2cbfc PUSH EAX
00e2cbfd MOV byte ptr [EBP + -0x4],0x9
00e2cc01 MOV ECX,dword ptr [EAX]
00e2cc03 CALL dword ptr [ECX + 0x1c]
00e2cc06 PUSH ECX
00e2cc07 LEA EAX,[EBP + -0x18]
00e2cc0a MOV dword ptr [EBP + -0x40],ESP
00e2cc0d MOV ECX,ESP
00e2cc0f PUSH EAX
00e2cc10 CALL 0x00e03ab8
00e2cc15 PUSH ECX
00e2cc16 LEA EAX,[EBP + 0x8]
00e2cc19 MOV byte ptr [EBP + -0x4],0xa
00e2cc1d MOV ECX,ESP
00e2cc1f PUSH EAX
00e2cc20 CALL 0x00e03ab8
00e2cc25 MOV ECX,EDI
00e2cc27 MOV byte ptr [EBP + -0x4],0x9
00e2cc2b CALL 0x00e29d43
00e2cc30 TEST AL,AL
00e2cc32 JNZ 0x00e2cc70
00e2cc34 PUSH ECX
00e2cc35 LEA EAX,[EBP + -0x18]
00e2cc38 MOV dword ptr [EBP + -0x40],ESP
00e2cc3b MOV ECX,ESP
00e2cc3d PUSH EAX
00e2cc3e CALL 0x00e03ab8
00e2cc43 PUSH ECX
00e2cc44 LEA EAX,[EBP + 0x8]
00e2cc47 MOV byte ptr [EBP + -0x4],0xb
00e2cc4b MOV ECX,ESP
00e2cc4d PUSH EAX
00e2cc4e CALL 0x00e03ab8
00e2cc53 MOV EAX,dword ptr [EBP + -0x1c]
00e2cc56 PUSH ECX
00e2cc57 MOV ECX,ESP
00e2cc59 MOV dword ptr [ECX],EAX
00e2cc5b TEST EAX,EAX
00e2cc5d JZ 0x00e2cc65
00e2cc5f MOV ECX,dword ptr [EAX]
00e2cc61 PUSH EAX
00e2cc62 CALL dword ptr [ECX + 0x4]
00e2cc65 MOV ECX,EDI
00e2cc67 MOV byte ptr [EBP + -0x4],0x9
00e2cc6b CALL 0x00e2cfdf
00e2cc70 PUSH dword ptr [EBP + -0x18]
00e2cc73 CALL dword ptr [0x00efc448]
00e2cc79 MOV EAX,dword ptr [EBP + -0x20]
00e2cc7c MOV byte ptr [EBP + -0x4],0x7
00e2cc80 TEST EAX,EAX
00e2cc82 JZ 0x00e2cc8a
00e2cc84 MOV ECX,dword ptr [EAX]
00e2cc86 PUSH EAX
00e2cc87 CALL dword ptr [ECX + 0x8]
00e2cc8a LEA EAX,[EBP + -0x50]
00e2cc8d PUSH EAX
00e2cc8e CALL dword ptr [0x00efc408]
00e2cc94 MOV EAX,dword ptr [EBP + -0x1c]
00e2cc97 MOV byte ptr [EBP + -0x4],0x5
00e2cc9b TEST EAX,EAX
00e2cc9d JZ 0x00e2cca5
00e2cc9f MOV ECX,dword ptr [EAX]
00e2cca1 PUSH EAX
00e2cca2 CALL dword ptr [ECX + 0x8]
00e2cca5 LEA EAX,[EBP + -0x60]
00e2cca8 PUSH EAX
00e2cca9 CALL dword ptr [0x00efc408]
00e2ccaf MOV EAX,dword ptr [EBP + -0x24]
00e2ccb2 MOV byte ptr [EBP + -0x4],0x3
00e2ccb6 TEST EAX,EAX
00e2ccb8 JZ 0x00e2ccc0
00e2ccba MOV ECX,dword ptr [EAX]
00e2ccbc PUSH EAX
00e2ccbd CALL dword ptr [ECX + 0x8]
00e2ccc0 LEA EAX,[EBP + -0x70]
00e2ccc3 PUSH EAX
00e2ccc4 CALL dword ptr [0x00efc408]
00e2ccca MOV EAX,dword ptr [EBP + -0x28]
00e2cccd MOV byte ptr [EBP + -0x4],0x1
00e2ccd1 TEST EAX,EAX
00e2ccd3 JZ 0x00e2ccdb
00e2ccd5 MOV ECX,dword ptr [EAX]
00e2ccd7 PUSH EAX
00e2ccd8 CALL dword ptr [ECX + 0x8]
00e2ccdb PUSH dword ptr [EBP + 0x8]
00e2ccde MOV byte ptr [EBP + -0x4],BL
00e2cce1 CALL dword ptr [0x00efc448]
00e2cce7 PUSH 0xefd018
00e2ccec LEA ECX,[EBP + -0x14]
00e2ccef CALL 0x00e03edc
00e2ccf4 TEST AL,AL
00e2ccf6 JZ 0x00e2cd2e
00e2ccf8 PUSH ECX
00e2ccf9 MOV ECX,dword ptr [EDI + 0x19c]
00e2ccff MOV EAX,ESP
00e2cd01 MOV dword ptr [EBP + 0x8],ESP
00e2cd04 MOV dword ptr [EAX],ECX
00e2cd06 TEST ECX,ECX
00e2cd08 JZ 0x00e2cd10
00e2cd0a MOV EAX,dword ptr [ECX]
00e2cd0c PUSH ECX
00e2cd0d CALL dword ptr [EAX + 0x4]
00e2cd10 MOV ECX,dword ptr [EBP + -0x10]
00e2cd13 MOV byte ptr [EBP + -0x4],0xc
00e2cd17 CALL 0x00e3e85d
00e2cd1c MOV ECX,dword ptr [EDI + 0x190]
00e2cd22 MOV byte ptr [EBP + -0x4],BL
00e2cd25 PUSH ESI
00e2cd26 MOV ECX,dword ptr [ECX + EAX*0x4]
00e2cd29 CALL 0x00e67954
00e2cd2e MOV ECX,ESI
00e2cd30 CALL 0x00e61fec
00e2cd35 TEST AL,AL
00e2cd37 JZ 0x00e2cf4c
00e2cd3d MOV dword ptr [EBP + 0x8],EBX
00e2cd40 MOV EAX,dword ptr [ESI + 0x4]
00e2cd43 LEA EDX,[EBP + 0x8]
00e2cd46 PUSH EDX
00e2cd47 PUSH EAX
00e2cd48 MOV byte ptr [EBP + -0x4],0xd
00e2cd4c MOV ECX,dword ptr [EAX]
00e2cd4e CALL dword ptr [ECX + 0x5c]
00e2cd51 MOV EAX,dword ptr [EBP + 0x8]
00e2cd54 TEST EAX,EAX
00e2cd56 JZ 0x00e2cf3f
00e2cd5c MOV ECX,dword ptr [EAX]
00e2cd5e LEA EDX,[EBP + -0x34]
00e2cd61 PUSH EDX
00e2cd62 PUSH EAX
00e2cd63 CALL dword ptr [ECX + 0x1c]
00e2cd66 CMP dword ptr [EBP + -0x34],0x0
00e2cd6a MOV dword ptr [EBP + -0x20],EBX
00e2cd6d JLE 0x00e2cf3c
00e2cd73 LEA ECX,[EBP + -0x60]
00e2cd76 CALL 0x00e03b51
00e2cd7b MOV EAX,dword ptr [EBP + 0x8]
00e2cd7e LEA EDX,[EBP + -0x60]
00e2cd81 PUSH EDX
00e2cd82 PUSH dword ptr [EBP + -0x20]
00e2cd85 MOV byte ptr [EBP + -0x4],0xe
00e2cd89 MOV ECX,dword ptr [EAX]
00e2cd8b PUSH EAX
00e2cd8c CALL dword ptr [ECX + 0x30]
00e2cd8f PUSH dword ptr [EBP + -0x58]
00e2cd92 LEA ECX,[EBP + -0x30]
00e2cd95 CALL 0x00e09841
00e2cd9a MOV EAX,dword ptr [EBP + -0x30]
00e2cd9d LEA EDX,[EBP + -0x38]
00e2cda0 PUSH EDX
00e2cda1 PUSH EAX
00e2cda2 MOV byte ptr [EBP + -0x4],0xf
00e2cda6 MOV ECX,dword ptr [EAX]
00e2cda8 CALL dword ptr [ECX + 0x50]
00e2cdab CMP dword ptr [EBP + -0x38],0x5
00e2cdaf JNZ 0x00e2cf11
00e2cdb5 MOV dword ptr [EBP + -0x18],EBX
00e2cdb8 MOV EAX,dword ptr [ESI + 0x4]
00e2cdbb LEA EDX,[EBP + -0x18]
00e2cdbe PUSH EDX
00e2cdbf PUSH EAX
00e2cdc0 MOV byte ptr [EBP + -0x4],0x10
00e2cdc4 MOV ECX,dword ptr [EAX]
00e2cdc6 CALL dword ptr [ECX + 0x5c]
00e2cdc9 MOV EAX,dword ptr [EBP + -0x18]
00e2cdcc TEST EAX,EAX
00e2cdce JZ 0x00e2cf03
00e2cdd4 LEA ECX,[EBP + -0x70]
00e2cdd7 CALL 0x00e03b51
00e2cddc MOV EAX,dword ptr [EBP + -0x18]
00e2cddf LEA EDX,[EBP + -0x70]
00e2cde2 PUSH EDX
00e2cde3 PUSH dword ptr [EBP + -0x20]
00e2cde6 MOV byte ptr [EBP + -0x4],0x11
00e2cdea MOV ECX,dword ptr [EAX]
00e2cdec PUSH EAX
00e2cded CALL dword ptr [ECX + 0x30]
00e2cdf0 CMP word ptr [EBP + -0x70],0x0
00e2cdf5 JZ 0x00e2cef6
00e2cdfb PUSH dword ptr [EBP + -0x68]
00e2cdfe LEA ECX,[EBP + -0x2c]
00e2ce01 CALL 0x00e09841
00e2ce06 MOV EAX,dword ptr [EBP + -0x2c]
00e2ce09 TEST EAX,EAX
00e2ce0b JZ 0x00e2cee8
00e2ce11 MOV dword ptr [EBP + -0x24],EBX
00e2ce14 MOV ECX,dword ptr [EAX]
00e2ce16 LEA EDX,[EBP + -0x24]
00e2ce19 PUSH EDX
00e2ce1a PUSH EAX
00e2ce1b MOV byte ptr [EBP + -0x4],0x13
00e2ce1f CALL dword ptr [ECX + 0xe4]
00e2ce25 MOV ECX,dword ptr [EBP + -0x10]
00e2ce28 CALL 0x00e3e85d
00e2ce2d MOV ECX,dword ptr [EDI + 0x190]
00e2ce33 MOV ECX,dword ptr [ECX + EAX*0x4]
00e2ce36 CALL 0x00e68567
00e2ce3b MOV ECX,dword ptr [EBP + -0x10]
00e2ce3e CALL 0x00e3e85d
00e2ce43 LEA ECX,[EBP + -0x1c]
00e2ce46 PUSH ECX
00e2ce47 MOV ECX,dword ptr [EDI + 0x190]
00e2ce4d MOV ECX,dword ptr [ECX + EAX*0x4]
00e2ce50 CALL 0x00e68547
00e2ce55 JMP 0x00e2ce97
00e2ce57 MOV EAX,dword ptr [ECX + 0x8]
00e2ce5a LEA ECX,[EBP + -0x28]
00e2ce5d PUSH ECX
00e2ce5e MOV ECX,EAX
00e2ce60 MOV dword ptr [EBP + -0x40],EAX
00e2ce63 CALL 0x00e616d4
00e2ce68 PUSH EBX
00e2ce69 PUSH 0x400
00e2ce6e PUSH dword ptr [EBP + -0x24]
00e2ce71 MOV byte ptr [EBP + -0x4],0x14
00e2ce75 PUSH dword ptr [EBP + -0x28]
00e2ce78 CALL 0x00ec8bc6
00e2ce7d CMP EAX,0x1
00e2ce80 JZ 0x00e2ceba
00e2ce82 PUSH dword ptr [EBP + -0x28]
00e2ce85 MOV byte ptr [EBP + -0x4],0x13
00e2ce89 CALL dword ptr [0x00efc448]
00e2ce8f MOV EAX,dword ptr [EBP + -0x1c]
00e2ce92 MOV EAX,dword ptr [EAX]
00e2ce94 MOV dword ptr [EBP + -0x1c],EAX
00e2ce97 MOV ECX,dword ptr [EBP + -0x10]
00e2ce9a CALL 0x00e3e85d
00e2ce9f MOV ECX,dword ptr [EDI + 0x190]
00e2cea5 LEA EDX,[EBP + -0x3c]
00e2cea8 PUSH EDX
00e2cea9 MOV ECX,dword ptr [ECX + EAX*0x4]
00e2ceac CALL 0x00e68558
00e2ceb1 MOV ECX,dword ptr [EBP + -0x1c]
00e2ceb4 CMP ECX,dword ptr [EAX]
00e2ceb6 JNZ 0x00e2ce57
00e2ceb8 JMP 0x00e2cedc
00e2ceba MOV ECX,dword ptr [EBP + -0x10]
00e2cebd CALL 0x00e3e85d
00e2cec2 MOV ECX,dword ptr [EDI + 0x190]
00e2cec8 PUSH dword ptr [EBP + -0x40]
00e2cecb MOV ECX,dword ptr [ECX + EAX*0x4]
00e2cece CALL 0x00e6616a
00e2ced3 PUSH dword ptr [EBP + -0x28]
00e2ced6 CALL dword ptr [0x00efc448]
00e2cedc PUSH dword ptr [EBP + -0x24]
00e2cedf CALL dword ptr [0x00efc448]
00e2cee5 MOV EAX,dword ptr [EBP + -0x2c]
00e2cee8 MOV byte ptr [EBP + -0x4],0x11
00e2ceec TEST EAX,EAX
00e2ceee JZ 0x00e2cef6
00e2cef0 MOV ECX,dword ptr [EAX]
00e2cef2 PUSH EAX
00e2cef3 CALL dword ptr [ECX + 0x8]
00e2cef6 LEA EAX,[EBP + -0x70]
00e2cef9 PUSH EAX
00e2cefa CALL dword ptr [0x00efc408]
00e2cf00 MOV EAX,dword ptr [EBP + -0x18]
00e2cf03 MOV byte ptr [EBP + -0x4],0xf
00e2cf07 TEST EAX,EAX
00e2cf09 JZ 0x00e2cf11
00e2cf0b MOV ECX,dword ptr [EAX]
00e2cf0d PUSH EAX
00e2cf0e CALL dword ptr [ECX + 0x8]
00e2cf11 MOV EAX,dword ptr [EBP + -0x30]
00e2cf14 MOV byte ptr [EBP + -0x4],0xe
00e2cf18 TEST EAX,EAX
00e2cf1a JZ 0x00e2cf22
00e2cf1c MOV ECX,dword ptr [EAX]
00e2cf1e PUSH EAX
00e2cf1f CALL dword ptr [ECX + 0x8]
00e2cf22 LEA EAX,[EBP + -0x60]
00e2cf25 PUSH EAX
00e2cf26 CALL dword ptr [0x00efc408]
00e2cf2c MOV EAX,dword ptr [EBP + -0x20]
00e2cf2f INC EAX
00e2cf30 MOV dword ptr [EBP + -0x20],EAX
00e2cf33 CMP EAX,dword ptr [EBP + -0x34]
00e2cf36 JL 0x00e2cd73
00e2cf3c MOV EAX,dword ptr [EBP + 0x8]
00e2cf3f MOV byte ptr [EBP + -0x4],BL
00e2cf42 TEST EAX,EAX
00e2cf44 JZ 0x00e2cf4c
00e2cf46 MOV EDX,dword ptr [EAX]
00e2cf48 PUSH EAX
00e2cf49 CALL dword ptr [EDX + 0x8]
00e2cf4c MOV ECX,dword ptr [EBP + -0x10]
00e2cf4f CALL 0x00e3e85d
00e2cf54 MOV ECX,dword ptr [EDI + 0x190]
00e2cf5a PUSH ESI
00e2cf5b MOV ECX,dword ptr [ECX + EAX*0x4]
00e2cf5e CALL 0x00e6616a
00e2cf63 MOV ESI,dword ptr [EDI + 0x190]
00e2cf69 MOV dword ptr [EBP + 0x8],EAX
00e2cf6c CMP ESI,dword ptr [EDI + 0x194]
00e2cf72 JZ 0x00e2cfc4
00e2cf74 MOV ECX,dword ptr [ESI]
00e2cf76 CALL 0x00e68567
00e2cf7b ADD ESI,0x4
00e2cf7e ADD EBX,EAX
00e2cf80 CMP ESI,dword ptr [EDI + 0x194]
00e2cf86 JNZ 0x00e2cf74
00e2cf88 TEST EBX,EBX
00e2cf8a JZ 0x00e2cfc4
00e2cf8c PUSH ECX
00e2cf8d MOV ECX,dword ptr [EDI + 0x160]
00e2cf93 MOV EAX,ESP
00e2cf95 MOV dword ptr [EAX],ECX
00e2cf97 TEST ECX,ECX
00e2cf99 JZ 0x00e2cfa1
00e2cf9b MOV EAX,dword ptr [ECX]
00e2cf9d PUSH ECX
00e2cf9e CALL dword ptr [EAX + 0x4]
00e2cfa1 PUSH ECX
00e2cfa2 MOV ECX,dword ptr [EDI + 0x19c]
00e2cfa8 MOV EAX,ESP
00e2cfaa MOV dword ptr [EAX],ECX
00e2cfac TEST ECX,ECX
00e2cfae JZ 0x00e2cfb6
00e2cfb0 MOV EAX,dword ptr [ECX]
00e2cfb2 PUSH ECX
00e2cfb3 CALL dword ptr [EAX + 0x4]
00e2cfb6 LEA ECX,[EDI + 0x1ac]
00e2cfbc CALL 0x00eb1fd0
00e2cfc1 MOV dword ptr [EDI + 0x28],EAX
00e2cfc4 MOV ECX,EDI
00e2cfc6 CALL 0x00e2b99e
00e2cfcb PUSH dword ptr [EBP + -0x14]
00e2cfce CALL dword ptr [0x00efc448]
00e2cfd4 MOV EAX,dword ptr [EBP + 0x8]
00e2cfd7 CALL 0x00ec9e28
00e2cfdc RET 0x4

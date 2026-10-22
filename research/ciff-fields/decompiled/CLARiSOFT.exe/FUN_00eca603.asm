00eca603 PUSH EBP
00eca604 MOV EBP,ESP
00eca606 PUSH EBX
00eca607 MOV EBX,dword ptr [EBP + 0x10]
00eca60a MOV EAX,EBX
00eca60c PUSH ESI
00eca60d SUB EAX,0x0
00eca610 JZ 0x00ecbcf3
00eca616 DEC EAX
00eca617 JZ 0x00ecbce2
00eca61d DEC EAX
00eca61e JZ 0x00ecbcb3
00eca624 DEC EAX
00eca625 JZ 0x00ecbc69
00eca62b MOV EDX,dword ptr [EBP + 0xc]
00eca62e DEC EAX
00eca62f JZ 0x00ecbbe1
00eca635 MOV ESI,dword ptr [EBP + 0x8]
00eca638 PUSH EDI
00eca639 CMP EBX,0x20
00eca63c JC 0x00ecaae3
00eca642 MOV EAX,dword ptr [ESI]
00eca644 CMP EAX,dword ptr [EDX]
00eca646 JZ 0x00eca6cc
00eca64c MOVZX EDI,AL
00eca64f MOVZX EAX,byte ptr [EDX]
00eca652 SUB EDI,EAX
00eca654 JZ 0x00eca66c
00eca656 XOR ECX,ECX
00eca658 TEST EDI,EDI
00eca65a SETG CL
00eca65d LEA ECX,[ECX*0x2 + 0xffffffff]
00eca664 TEST ECX,ECX
00eca666 JNZ 0x00ecaf07
00eca66c MOVZX EDI,byte ptr [ESI + 0x1]
00eca670 MOVZX EAX,byte ptr [EDX + 0x1]
00eca674 SUB EDI,EAX
00eca676 JZ 0x00eca68e
00eca678 XOR ECX,ECX
00eca67a TEST EDI,EDI
00eca67c SETG CL
00eca67f LEA ECX,[ECX*0x2 + 0xffffffff]
00eca686 TEST ECX,ECX
00eca688 JNZ 0x00ecaf07
00eca68e MOVZX EDI,byte ptr [ESI + 0x2]
00eca692 MOVZX EAX,byte ptr [EDX + 0x2]
00eca696 SUB EDI,EAX
00eca698 JZ 0x00eca6b0
00eca69a XOR ECX,ECX
00eca69c TEST EDI,EDI
00eca69e SETG CL
00eca6a1 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca6a8 TEST ECX,ECX
00eca6aa JNZ 0x00ecaf07
00eca6b0 MOVZX ECX,byte ptr [ESI + 0x3]
00eca6b4 MOVZX EAX,byte ptr [EDX + 0x3]
00eca6b8 SUB ECX,EAX
00eca6ba JZ 0x00eca6ce
00eca6bc XOR EAX,EAX
00eca6be TEST ECX,ECX
00eca6c0 SETG AL
00eca6c3 LEA ECX,[EAX*0x2 + 0xffffffff]
00eca6ca JMP 0x00eca6ce
00eca6cc XOR ECX,ECX
00eca6ce TEST ECX,ECX
00eca6d0 JNZ 0x00ecaf07
00eca6d6 MOV EAX,dword ptr [ESI + 0x4]
00eca6d9 CMP EAX,dword ptr [EDX + 0x4]
00eca6dc JZ 0x00eca75d
00eca6de MOVZX EDI,AL
00eca6e1 MOVZX EAX,byte ptr [EDX + 0x4]
00eca6e5 SUB EDI,EAX
00eca6e7 JZ 0x00eca6fd
00eca6e9 TEST EDI,EDI
00eca6eb SETG CL
00eca6ee LEA ECX,[ECX*0x2 + 0xffffffff]
00eca6f5 TEST ECX,ECX
00eca6f7 JNZ 0x00ecaf07
00eca6fd MOVZX EDI,byte ptr [ESI + 0x5]
00eca701 MOVZX EAX,byte ptr [EDX + 0x5]
00eca705 SUB EDI,EAX
00eca707 JZ 0x00eca71f
00eca709 XOR ECX,ECX
00eca70b TEST EDI,EDI
00eca70d SETG CL
00eca710 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca717 TEST ECX,ECX
00eca719 JNZ 0x00ecaf07
00eca71f MOVZX EDI,byte ptr [ESI + 0x6]
00eca723 MOVZX EAX,byte ptr [EDX + 0x6]
00eca727 SUB EDI,EAX
00eca729 JZ 0x00eca741
00eca72b XOR ECX,ECX
00eca72d TEST EDI,EDI
00eca72f SETG CL
00eca732 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca739 TEST ECX,ECX
00eca73b JNZ 0x00ecaf07
00eca741 MOVZX ECX,byte ptr [ESI + 0x7]
00eca745 MOVZX EAX,byte ptr [EDX + 0x7]
00eca749 SUB ECX,EAX
00eca74b JZ 0x00eca75f
00eca74d XOR EAX,EAX
00eca74f TEST ECX,ECX
00eca751 SETG AL
00eca754 LEA ECX,[EAX*0x2 + 0xffffffff]
00eca75b JMP 0x00eca75f
00eca75d XOR ECX,ECX
00eca75f TEST ECX,ECX
00eca761 JNZ 0x00ecaf07
00eca767 MOV EAX,dword ptr [ESI + 0x8]
00eca76a CMP EAX,dword ptr [EDX + 0x8]
00eca76d JZ 0x00eca7ee
00eca76f MOVZX EDI,AL
00eca772 MOVZX EAX,byte ptr [EDX + 0x8]
00eca776 SUB EDI,EAX
00eca778 JZ 0x00eca78e
00eca77a TEST EDI,EDI
00eca77c SETG CL
00eca77f LEA ECX,[ECX*0x2 + 0xffffffff]
00eca786 TEST ECX,ECX
00eca788 JNZ 0x00ecaf07
00eca78e MOVZX EDI,byte ptr [ESI + 0x9]
00eca792 MOVZX EAX,byte ptr [EDX + 0x9]
00eca796 SUB EDI,EAX
00eca798 JZ 0x00eca7b0
00eca79a XOR ECX,ECX
00eca79c TEST EDI,EDI
00eca79e SETG CL
00eca7a1 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca7a8 TEST ECX,ECX
00eca7aa JNZ 0x00ecaf07
00eca7b0 MOVZX EDI,byte ptr [ESI + 0xa]
00eca7b4 MOVZX EAX,byte ptr [EDX + 0xa]
00eca7b8 SUB EDI,EAX
00eca7ba JZ 0x00eca7d2
00eca7bc XOR ECX,ECX
00eca7be TEST EDI,EDI
00eca7c0 SETG CL
00eca7c3 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca7ca TEST ECX,ECX
00eca7cc JNZ 0x00ecaf07
00eca7d2 MOVZX ECX,byte ptr [ESI + 0xb]
00eca7d6 MOVZX EAX,byte ptr [EDX + 0xb]
00eca7da SUB ECX,EAX
00eca7dc JZ 0x00eca7f0
00eca7de XOR EAX,EAX
00eca7e0 TEST ECX,ECX
00eca7e2 SETG AL
00eca7e5 LEA ECX,[EAX*0x2 + 0xffffffff]
00eca7ec JMP 0x00eca7f0
00eca7ee XOR ECX,ECX
00eca7f0 TEST ECX,ECX
00eca7f2 JNZ 0x00ecaf07
00eca7f8 MOV EAX,dword ptr [ESI + 0xc]
00eca7fb CMP EAX,dword ptr [EDX + 0xc]
00eca7fe JZ 0x00eca87f
00eca800 MOVZX EDI,AL
00eca803 MOVZX EAX,byte ptr [EDX + 0xc]
00eca807 SUB EDI,EAX
00eca809 JZ 0x00eca81f
00eca80b TEST EDI,EDI
00eca80d SETG CL
00eca810 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca817 TEST ECX,ECX
00eca819 JNZ 0x00ecaf07
00eca81f MOVZX EDI,byte ptr [ESI + 0xd]
00eca823 MOVZX EAX,byte ptr [EDX + 0xd]
00eca827 SUB EDI,EAX
00eca829 JZ 0x00eca841
00eca82b XOR ECX,ECX
00eca82d TEST EDI,EDI
00eca82f SETG CL
00eca832 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca839 TEST ECX,ECX
00eca83b JNZ 0x00ecaf07
00eca841 MOVZX EDI,byte ptr [ESI + 0xe]
00eca845 MOVZX EAX,byte ptr [EDX + 0xe]
00eca849 SUB EDI,EAX
00eca84b JZ 0x00eca863
00eca84d XOR ECX,ECX
00eca84f TEST EDI,EDI
00eca851 SETG CL
00eca854 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca85b TEST ECX,ECX
00eca85d JNZ 0x00ecaf07
00eca863 MOVZX ECX,byte ptr [ESI + 0xf]
00eca867 MOVZX EAX,byte ptr [EDX + 0xf]
00eca86b SUB ECX,EAX
00eca86d JZ 0x00eca881
00eca86f XOR EAX,EAX
00eca871 TEST ECX,ECX
00eca873 SETG AL
00eca876 LEA ECX,[EAX*0x2 + 0xffffffff]
00eca87d JMP 0x00eca881
00eca87f XOR ECX,ECX
00eca881 TEST ECX,ECX
00eca883 JNZ 0x00ecaf07
00eca889 MOV EAX,dword ptr [ESI + 0x10]
00eca88c CMP EAX,dword ptr [EDX + 0x10]
00eca88f JZ 0x00eca915
00eca895 MOVZX EAX,byte ptr [EDX + 0x10]
00eca899 MOVZX EDI,byte ptr [ESI + 0x10]
00eca89d SUB EDI,EAX
00eca89f JZ 0x00eca8b5
00eca8a1 TEST EDI,EDI
00eca8a3 SETG CL
00eca8a6 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca8ad TEST ECX,ECX
00eca8af JNZ 0x00ecaf07
00eca8b5 MOVZX EDI,byte ptr [ESI + 0x11]
00eca8b9 MOVZX EAX,byte ptr [EDX + 0x11]
00eca8bd SUB EDI,EAX
00eca8bf JZ 0x00eca8d7
00eca8c1 XOR ECX,ECX
00eca8c3 TEST EDI,EDI
00eca8c5 SETG CL
00eca8c8 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca8cf TEST ECX,ECX
00eca8d1 JNZ 0x00ecaf07
00eca8d7 MOVZX EDI,byte ptr [ESI + 0x12]
00eca8db MOVZX EAX,byte ptr [EDX + 0x12]
00eca8df SUB EDI,EAX
00eca8e1 JZ 0x00eca8f9
00eca8e3 XOR ECX,ECX
00eca8e5 TEST EDI,EDI
00eca8e7 SETG CL
00eca8ea LEA ECX,[ECX*0x2 + 0xffffffff]
00eca8f1 TEST ECX,ECX
00eca8f3 JNZ 0x00ecaf07
00eca8f9 MOVZX ECX,byte ptr [ESI + 0x13]
00eca8fd MOVZX EAX,byte ptr [EDX + 0x13]
00eca901 SUB ECX,EAX
00eca903 JZ 0x00eca917
00eca905 XOR EAX,EAX
00eca907 TEST ECX,ECX
00eca909 SETG AL
00eca90c LEA ECX,[EAX*0x2 + 0xffffffff]
00eca913 JMP 0x00eca917
00eca915 XOR ECX,ECX
00eca917 TEST ECX,ECX
00eca919 JNZ 0x00ecaf07
00eca91f MOV EAX,dword ptr [ESI + 0x14]
00eca922 CMP EAX,dword ptr [EDX + 0x14]
00eca925 JZ 0x00eca9a6
00eca927 MOVZX EDI,AL
00eca92a MOVZX EAX,byte ptr [EDX + 0x14]
00eca92e SUB EDI,EAX
00eca930 JZ 0x00eca946
00eca932 TEST EDI,EDI
00eca934 SETG CL
00eca937 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca93e TEST ECX,ECX
00eca940 JNZ 0x00ecaf07
00eca946 MOVZX EDI,byte ptr [ESI + 0x15]
00eca94a MOVZX EAX,byte ptr [EDX + 0x15]
00eca94e SUB EDI,EAX
00eca950 JZ 0x00eca968
00eca952 XOR ECX,ECX
00eca954 TEST EDI,EDI
00eca956 SETG CL
00eca959 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca960 TEST ECX,ECX
00eca962 JNZ 0x00ecaf07
00eca968 MOVZX EDI,byte ptr [ESI + 0x16]
00eca96c MOVZX EAX,byte ptr [EDX + 0x16]
00eca970 SUB EDI,EAX
00eca972 JZ 0x00eca98a
00eca974 XOR ECX,ECX
00eca976 TEST EDI,EDI
00eca978 SETG CL
00eca97b LEA ECX,[ECX*0x2 + 0xffffffff]
00eca982 TEST ECX,ECX
00eca984 JNZ 0x00ecaf07
00eca98a MOVZX ECX,byte ptr [ESI + 0x17]
00eca98e MOVZX EAX,byte ptr [EDX + 0x17]
00eca992 SUB ECX,EAX
00eca994 JZ 0x00eca9a8
00eca996 XOR EAX,EAX
00eca998 TEST ECX,ECX
00eca99a SETG AL
00eca99d LEA ECX,[EAX*0x2 + 0xffffffff]
00eca9a4 JMP 0x00eca9a8
00eca9a6 XOR ECX,ECX
00eca9a8 TEST ECX,ECX
00eca9aa JNZ 0x00ecaf07
00eca9b0 MOV EAX,dword ptr [ESI + 0x18]
00eca9b3 CMP EAX,dword ptr [EDX + 0x18]
00eca9b6 JZ 0x00ecaa37
00eca9b8 MOVZX EDI,AL
00eca9bb MOVZX EAX,byte ptr [EDX + 0x18]
00eca9bf SUB EDI,EAX
00eca9c1 JZ 0x00eca9d7
00eca9c3 TEST EDI,EDI
00eca9c5 SETG CL
00eca9c8 LEA ECX,[ECX*0x2 + 0xffffffff]
00eca9cf TEST ECX,ECX
00eca9d1 JNZ 0x00ecaf07
00eca9d7 MOVZX EDI,byte ptr [ESI + 0x19]
00eca9db MOVZX EAX,byte ptr [EDX + 0x19]
00eca9df SUB EDI,EAX
00eca9e1 JZ 0x00eca9f9
00eca9e3 XOR ECX,ECX
00eca9e5 TEST EDI,EDI
00eca9e7 SETG CL
00eca9ea LEA ECX,[ECX*0x2 + 0xffffffff]
00eca9f1 TEST ECX,ECX
00eca9f3 JNZ 0x00ecaf07
00eca9f9 MOVZX EDI,byte ptr [ESI + 0x1a]
00eca9fd MOVZX EAX,byte ptr [EDX + 0x1a]
00ecaa01 SUB EDI,EAX
00ecaa03 JZ 0x00ecaa1b
00ecaa05 XOR ECX,ECX
00ecaa07 TEST EDI,EDI
00ecaa09 SETG CL
00ecaa0c LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaa13 TEST ECX,ECX
00ecaa15 JNZ 0x00ecaf07
00ecaa1b MOVZX ECX,byte ptr [ESI + 0x1b]
00ecaa1f MOVZX EAX,byte ptr [EDX + 0x1b]
00ecaa23 SUB ECX,EAX
00ecaa25 JZ 0x00ecaa39
00ecaa27 XOR EAX,EAX
00ecaa29 TEST ECX,ECX
00ecaa2b SETG AL
00ecaa2e LEA ECX,[EAX*0x2 + 0xffffffff]
00ecaa35 JMP 0x00ecaa39
00ecaa37 XOR ECX,ECX
00ecaa39 TEST ECX,ECX
00ecaa3b JNZ 0x00ecaf07
00ecaa41 MOV EAX,dword ptr [ESI + 0x1c]
00ecaa44 CMP EAX,dword ptr [EDX + 0x1c]
00ecaa47 JZ 0x00ecaac8
00ecaa49 MOVZX EDI,AL
00ecaa4c MOVZX EAX,byte ptr [EDX + 0x1c]
00ecaa50 SUB EDI,EAX
00ecaa52 JZ 0x00ecaa68
00ecaa54 TEST EDI,EDI
00ecaa56 SETG CL
00ecaa59 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaa60 TEST ECX,ECX
00ecaa62 JNZ 0x00ecaf07
00ecaa68 MOVZX EDI,byte ptr [ESI + 0x1d]
00ecaa6c MOVZX EAX,byte ptr [EDX + 0x1d]
00ecaa70 SUB EDI,EAX
00ecaa72 JZ 0x00ecaa8a
00ecaa74 XOR ECX,ECX
00ecaa76 TEST EDI,EDI
00ecaa78 SETG CL
00ecaa7b LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaa82 TEST ECX,ECX
00ecaa84 JNZ 0x00ecaf07
00ecaa8a MOVZX EDI,byte ptr [ESI + 0x1e]
00ecaa8e MOVZX EAX,byte ptr [EDX + 0x1e]
00ecaa92 SUB EDI,EAX
00ecaa94 JZ 0x00ecaaac
00ecaa96 XOR ECX,ECX
00ecaa98 TEST EDI,EDI
00ecaa9a SETG CL
00ecaa9d LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaaa4 TEST ECX,ECX
00ecaaa6 JNZ 0x00ecaf07
00ecaaac MOVZX ECX,byte ptr [ESI + 0x1f]
00ecaab0 MOVZX EAX,byte ptr [EDX + 0x1f]
00ecaab4 SUB ECX,EAX
00ecaab6 JZ 0x00ecaaca
00ecaab8 XOR EAX,EAX
00ecaaba TEST ECX,ECX
00ecaabc SETG AL
00ecaabf LEA ECX,[EAX*0x2 + 0xffffffff]
00ecaac6 JMP 0x00ecaaca
00ecaac8 XOR ECX,ECX
00ecaaca TEST ECX,ECX
00ecaacc JNZ 0x00ecaf07
00ecaad2 PUSH 0x20
00ecaad4 POP ECX
00ecaad5 SUB EBX,ECX
00ecaad7 ADD ESI,ECX
00ecaad9 ADD EDX,ECX
00ecaadb CMP EBX,ECX
00ecaadd JNC 0x00eca642
00ecaae3 ADD ESI,EBX
00ecaae5 ADD EDX,EBX
00ecaae7 CMP EBX,0x1f
00ecaaea JA 0x00ecaf05
00ecaaf0 JMP dword ptr [EBX*0x4 + 0xecbcfb]
00ecaaf7 MOV EAX,dword ptr [ESI + -0x1c]
00ecaafa CMP EAX,dword ptr [EDX + -0x1c]
00ecaafd JZ 0x00ecab84
00ecab03 MOVZX EDI,AL
00ecab06 MOVZX EAX,byte ptr [EDX + -0x1c]
00ecab0a SUB EDI,EAX
00ecab0c JZ 0x00ecab24
00ecab0e XOR ECX,ECX
00ecab10 TEST EDI,EDI
00ecab12 SETG CL
00ecab15 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecab1c TEST ECX,ECX
00ecab1e JNZ 0x00ecaf07
00ecab24 MOVZX EDI,byte ptr [ESI + -0x1b]
00ecab28 MOVZX EAX,byte ptr [EDX + -0x1b]
00ecab2c SUB EDI,EAX
00ecab2e JZ 0x00ecab46
00ecab30 XOR ECX,ECX
00ecab32 TEST EDI,EDI
00ecab34 SETG CL
00ecab37 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecab3e TEST ECX,ECX
00ecab40 JNZ 0x00ecaf07
00ecab46 MOVZX EDI,byte ptr [ESI + -0x1a]
00ecab4a MOVZX EAX,byte ptr [EDX + -0x1a]
00ecab4e SUB EDI,EAX
00ecab50 JZ 0x00ecab68
00ecab52 XOR ECX,ECX
00ecab54 TEST EDI,EDI
00ecab56 SETG CL
00ecab59 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecab60 TEST ECX,ECX
00ecab62 JNZ 0x00ecaf07
00ecab68 MOVZX ECX,byte ptr [ESI + -0x19]
00ecab6c MOVZX EAX,byte ptr [EDX + -0x19]
00ecab70 SUB ECX,EAX
00ecab72 JZ 0x00ecab86
00ecab74 XOR EAX,EAX
00ecab76 TEST ECX,ECX
00ecab78 SETG AL
00ecab7b LEA ECX,[EAX*0x2 + 0xffffffff]
00ecab82 JMP 0x00ecab86
00ecab84 XOR ECX,ECX
00ecab86 TEST ECX,ECX
00ecab88 JNZ 0x00ecaf07
00ecab8e MOV EAX,dword ptr [ESI + -0x18]
00ecab91 CMP EAX,dword ptr [EDX + -0x18]
00ecab94 JZ 0x00ecac1b
00ecab9a MOVZX EDI,AL
00ecab9d MOVZX EAX,byte ptr [EDX + -0x18]
00ecaba1 SUB EDI,EAX
00ecaba3 JZ 0x00ecabbb
00ecaba5 XOR ECX,ECX
00ecaba7 TEST EDI,EDI
00ecaba9 SETG CL
00ecabac LEA ECX,[ECX*0x2 + 0xffffffff]
00ecabb3 TEST ECX,ECX
00ecabb5 JNZ 0x00ecaf07
00ecabbb MOVZX EDI,byte ptr [ESI + -0x17]
00ecabbf MOVZX EAX,byte ptr [EDX + -0x17]
00ecabc3 SUB EDI,EAX
00ecabc5 JZ 0x00ecabdd
00ecabc7 XOR ECX,ECX
00ecabc9 TEST EDI,EDI
00ecabcb SETG CL
00ecabce LEA ECX,[ECX*0x2 + 0xffffffff]
00ecabd5 TEST ECX,ECX
00ecabd7 JNZ 0x00ecaf07
00ecabdd MOVZX EDI,byte ptr [ESI + -0x16]
00ecabe1 MOVZX EAX,byte ptr [EDX + -0x16]
00ecabe5 SUB EDI,EAX
00ecabe7 JZ 0x00ecabff
00ecabe9 XOR ECX,ECX
00ecabeb TEST EDI,EDI
00ecabed SETG CL
00ecabf0 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecabf7 TEST ECX,ECX
00ecabf9 JNZ 0x00ecaf07
00ecabff MOVZX ECX,byte ptr [ESI + -0x15]
00ecac03 MOVZX EAX,byte ptr [EDX + -0x15]
00ecac07 SUB ECX,EAX
00ecac09 JZ 0x00ecac1d
00ecac0b XOR EAX,EAX
00ecac0d TEST ECX,ECX
00ecac0f SETG AL
00ecac12 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecac19 JMP 0x00ecac1d
00ecac1b XOR ECX,ECX
00ecac1d TEST ECX,ECX
00ecac1f JNZ 0x00ecaf07
00ecac25 MOV EAX,dword ptr [ESI + -0x14]
00ecac28 CMP EAX,dword ptr [EDX + -0x14]
00ecac2b JZ 0x00ecacb2
00ecac31 MOVZX EDI,AL
00ecac34 MOVZX EAX,byte ptr [EDX + -0x14]
00ecac38 SUB EDI,EAX
00ecac3a JZ 0x00ecac52
00ecac3c XOR ECX,ECX
00ecac3e TEST EDI,EDI
00ecac40 SETG CL
00ecac43 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecac4a TEST ECX,ECX
00ecac4c JNZ 0x00ecaf07
00ecac52 MOVZX EDI,byte ptr [ESI + -0x13]
00ecac56 MOVZX EAX,byte ptr [EDX + -0x13]
00ecac5a SUB EDI,EAX
00ecac5c JZ 0x00ecac74
00ecac5e XOR ECX,ECX
00ecac60 TEST EDI,EDI
00ecac62 SETG CL
00ecac65 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecac6c TEST ECX,ECX
00ecac6e JNZ 0x00ecaf07
00ecac74 MOVZX EDI,byte ptr [ESI + -0x12]
00ecac78 MOVZX EAX,byte ptr [EDX + -0x12]
00ecac7c SUB EDI,EAX
00ecac7e JZ 0x00ecac96
00ecac80 XOR ECX,ECX
00ecac82 TEST EDI,EDI
00ecac84 SETG CL
00ecac87 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecac8e TEST ECX,ECX
00ecac90 JNZ 0x00ecaf07
00ecac96 MOVZX ECX,byte ptr [ESI + -0x11]
00ecac9a MOVZX EAX,byte ptr [EDX + -0x11]
00ecac9e SUB ECX,EAX
00ecaca0 JZ 0x00ecacb4
00ecaca2 XOR EAX,EAX
00ecaca4 TEST ECX,ECX
00ecaca6 SETG AL
00ecaca9 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecacb0 JMP 0x00ecacb4
00ecacb2 XOR ECX,ECX
00ecacb4 TEST ECX,ECX
00ecacb6 JNZ 0x00ecaf07
00ecacbc MOV EAX,dword ptr [ESI + -0x10]
00ecacbf CMP EAX,dword ptr [EDX + -0x10]
00ecacc2 JZ 0x00ecad49
00ecacc8 MOVZX EDI,AL
00ecaccb MOVZX EAX,byte ptr [EDX + -0x10]
00ecaccf SUB EDI,EAX
00ecacd1 JZ 0x00ecace9
00ecacd3 XOR ECX,ECX
00ecacd5 TEST EDI,EDI
00ecacd7 SETG CL
00ecacda LEA ECX,[ECX*0x2 + 0xffffffff]
00ecace1 TEST ECX,ECX
00ecace3 JNZ 0x00ecaf07
00ecace9 MOVZX EDI,byte ptr [ESI + -0xf]
00ecaced MOVZX EAX,byte ptr [EDX + -0xf]
00ecacf1 SUB EDI,EAX
00ecacf3 JZ 0x00ecad0b
00ecacf5 XOR ECX,ECX
00ecacf7 TEST EDI,EDI
00ecacf9 SETG CL
00ecacfc LEA ECX,[ECX*0x2 + 0xffffffff]
00ecad03 TEST ECX,ECX
00ecad05 JNZ 0x00ecaf07
00ecad0b MOVZX EDI,byte ptr [ESI + -0xe]
00ecad0f MOVZX EAX,byte ptr [EDX + -0xe]
00ecad13 SUB EDI,EAX
00ecad15 JZ 0x00ecad2d
00ecad17 XOR ECX,ECX
00ecad19 TEST EDI,EDI
00ecad1b SETG CL
00ecad1e LEA ECX,[ECX*0x2 + 0xffffffff]
00ecad25 TEST ECX,ECX
00ecad27 JNZ 0x00ecaf07
00ecad2d MOVZX ECX,byte ptr [ESI + -0xd]
00ecad31 MOVZX EAX,byte ptr [EDX + -0xd]
00ecad35 SUB ECX,EAX
00ecad37 JZ 0x00ecad4b
00ecad39 XOR EAX,EAX
00ecad3b TEST ECX,ECX
00ecad3d SETG AL
00ecad40 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecad47 JMP 0x00ecad4b
00ecad49 XOR ECX,ECX
00ecad4b TEST ECX,ECX
00ecad4d JNZ 0x00ecaf07
00ecad53 MOV EAX,dword ptr [ESI + -0xc]
00ecad56 CMP EAX,dword ptr [EDX + -0xc]
00ecad59 JZ 0x00ecade1
00ecad5f MOVZX EAX,byte ptr [EDX + -0xc]
00ecad63 MOVZX EDI,byte ptr [ESI + -0xc]
00ecad67 SUB EDI,EAX
00ecad69 JZ 0x00ecad81
00ecad6b XOR ECX,ECX
00ecad6d TEST EDI,EDI
00ecad6f SETG CL
00ecad72 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecad79 TEST ECX,ECX
00ecad7b JNZ 0x00ecaf07
00ecad81 MOVZX EDI,byte ptr [ESI + -0xb]
00ecad85 MOVZX EAX,byte ptr [EDX + -0xb]
00ecad89 SUB EDI,EAX
00ecad8b JZ 0x00ecada3
00ecad8d XOR ECX,ECX
00ecad8f TEST EDI,EDI
00ecad91 SETG CL
00ecad94 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecad9b TEST ECX,ECX
00ecad9d JNZ 0x00ecaf07
00ecada3 MOVZX EDI,byte ptr [ESI + -0xa]
00ecada7 MOVZX EAX,byte ptr [EDX + -0xa]
00ecadab SUB EDI,EAX
00ecadad JZ 0x00ecadc5
00ecadaf XOR ECX,ECX
00ecadb1 TEST EDI,EDI
00ecadb3 SETG CL
00ecadb6 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecadbd TEST ECX,ECX
00ecadbf JNZ 0x00ecaf07
00ecadc5 MOVZX ECX,byte ptr [ESI + -0x9]
00ecadc9 MOVZX EAX,byte ptr [EDX + -0x9]
00ecadcd SUB ECX,EAX
00ecadcf JZ 0x00ecade3
00ecadd1 XOR EAX,EAX
00ecadd3 TEST ECX,ECX
00ecadd5 SETG AL
00ecadd8 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecaddf JMP 0x00ecade3
00ecade1 XOR ECX,ECX
00ecade3 TEST ECX,ECX
00ecade5 JNZ 0x00ecaf07
00ecadeb MOV EAX,dword ptr [ESI + -0x8]
00ecadee CMP EAX,dword ptr [EDX + -0x8]
00ecadf1 JZ 0x00ecae78
00ecadf7 MOVZX EDI,AL
00ecadfa MOVZX EAX,byte ptr [EDX + -0x8]
00ecadfe SUB EDI,EAX
00ecae00 JZ 0x00ecae18
00ecae02 XOR ECX,ECX
00ecae04 TEST EDI,EDI
00ecae06 SETG CL
00ecae09 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecae10 TEST ECX,ECX
00ecae12 JNZ 0x00ecaf07
00ecae18 MOVZX EDI,byte ptr [ESI + -0x7]
00ecae1c MOVZX EAX,byte ptr [EDX + -0x7]
00ecae20 SUB EDI,EAX
00ecae22 JZ 0x00ecae3a
00ecae24 XOR ECX,ECX
00ecae26 TEST EDI,EDI
00ecae28 SETG CL
00ecae2b LEA ECX,[ECX*0x2 + 0xffffffff]
00ecae32 TEST ECX,ECX
00ecae34 JNZ 0x00ecaf07
00ecae3a MOVZX EDI,byte ptr [ESI + -0x6]
00ecae3e MOVZX EAX,byte ptr [EDX + -0x6]
00ecae42 SUB EDI,EAX
00ecae44 JZ 0x00ecae5c
00ecae46 XOR ECX,ECX
00ecae48 TEST EDI,EDI
00ecae4a SETG CL
00ecae4d LEA ECX,[ECX*0x2 + 0xffffffff]
00ecae54 TEST ECX,ECX
00ecae56 JNZ 0x00ecaf07
00ecae5c MOVZX ECX,byte ptr [ESI + -0x5]
00ecae60 MOVZX EAX,byte ptr [EDX + -0x5]
00ecae64 SUB ECX,EAX
00ecae66 JZ 0x00ecae7a
00ecae68 XOR EAX,EAX
00ecae6a TEST ECX,ECX
00ecae6c SETG AL
00ecae6f LEA ECX,[EAX*0x2 + 0xffffffff]
00ecae76 JMP 0x00ecae7a
00ecae78 XOR ECX,ECX
00ecae7a TEST ECX,ECX
00ecae7c JNZ 0x00ecaf07
00ecae82 MOV EAX,dword ptr [ESI + -0x4]
00ecae85 CMP EAX,dword ptr [EDX + -0x4]
00ecae88 JZ 0x00ecaeff
00ecae8a MOVZX EDI,AL
00ecae8d MOVZX EAX,byte ptr [EDX + -0x4]
00ecae91 SUB EDI,EAX
00ecae93 JZ 0x00ecaea7
00ecae95 XOR ECX,ECX
00ecae97 TEST EDI,EDI
00ecae99 SETG CL
00ecae9c LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaea3 TEST ECX,ECX
00ecaea5 JNZ 0x00ecaf07
00ecaea7 MOVZX EDI,byte ptr [ESI + -0x3]
00ecaeab MOVZX EAX,byte ptr [EDX + -0x3]
00ecaeaf SUB EDI,EAX
00ecaeb1 JZ 0x00ecaec5
00ecaeb3 XOR ECX,ECX
00ecaeb5 TEST EDI,EDI
00ecaeb7 SETG CL
00ecaeba LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaec1 TEST ECX,ECX
00ecaec3 JNZ 0x00ecaf07
00ecaec5 MOVZX EDI,byte ptr [ESI + -0x2]
00ecaec9 MOVZX EAX,byte ptr [EDX + -0x2]
00ecaecd SUB EDI,EAX
00ecaecf JZ 0x00ecaee3
00ecaed1 XOR ECX,ECX
00ecaed3 TEST EDI,EDI
00ecaed5 SETG CL
00ecaed8 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaedf TEST ECX,ECX
00ecaee1 JNZ 0x00ecaf07
00ecaee3 MOVZX ECX,byte ptr [ESI + -0x1]
00ecaee7 MOVZX EAX,byte ptr [EDX + -0x1]
00ecaeeb SUB ECX,EAX
00ecaeed JZ 0x00ecaf01
00ecaeef XOR EAX,EAX
00ecaef1 TEST ECX,ECX
00ecaef3 SETG AL
00ecaef6 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecaefd JMP 0x00ecaf01
00ecaeff XOR ECX,ECX
00ecaf01 TEST ECX,ECX
00ecaf03 JNZ 0x00ecaf07
00ecaf05 XOR ECX,ECX
00ecaf07 MOV EAX,ECX
00ecaf09 POP EDI
00ecaf0a JMP 0x00ecbcf5
00ecaf0f MOV EAX,dword ptr [ESI + -0x1d]
00ecaf12 CMP EAX,dword ptr [EDX + -0x1d]
00ecaf15 JZ 0x00ecaf8c
00ecaf17 MOVZX EDI,AL
00ecaf1a MOVZX EAX,byte ptr [EDX + -0x1d]
00ecaf1e SUB EDI,EAX
00ecaf20 JZ 0x00ecaf34
00ecaf22 XOR ECX,ECX
00ecaf24 TEST EDI,EDI
00ecaf26 SETG CL
00ecaf29 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaf30 TEST ECX,ECX
00ecaf32 JNZ 0x00ecaf07
00ecaf34 MOVZX EDI,byte ptr [ESI + -0x1c]
00ecaf38 MOVZX EAX,byte ptr [EDX + -0x1c]
00ecaf3c SUB EDI,EAX
00ecaf3e JZ 0x00ecaf52
00ecaf40 XOR ECX,ECX
00ecaf42 TEST EDI,EDI
00ecaf44 SETG CL
00ecaf47 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaf4e TEST ECX,ECX
00ecaf50 JNZ 0x00ecaf07
00ecaf52 MOVZX EDI,byte ptr [ESI + -0x1b]
00ecaf56 MOVZX EAX,byte ptr [EDX + -0x1b]
00ecaf5a SUB EDI,EAX
00ecaf5c JZ 0x00ecaf70
00ecaf5e XOR ECX,ECX
00ecaf60 TEST EDI,EDI
00ecaf62 SETG CL
00ecaf65 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecaf6c TEST ECX,ECX
00ecaf6e JNZ 0x00ecaf07
00ecaf70 MOVZX ECX,byte ptr [ESI + -0x1a]
00ecaf74 MOVZX EAX,byte ptr [EDX + -0x1a]
00ecaf78 SUB ECX,EAX
00ecaf7a JZ 0x00ecaf8e
00ecaf7c XOR EAX,EAX
00ecaf7e TEST ECX,ECX
00ecaf80 SETG AL
00ecaf83 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecaf8a JMP 0x00ecaf8e
00ecaf8c XOR ECX,ECX
00ecaf8e TEST ECX,ECX
00ecaf90 JNZ 0x00ecaf07
00ecaf96 MOV EAX,dword ptr [ESI + -0x19]
00ecaf99 CMP EAX,dword ptr [EDX + -0x19]
00ecaf9c JZ 0x00ecb023
00ecafa2 MOVZX EDI,AL
00ecafa5 MOVZX EAX,byte ptr [EDX + -0x19]
00ecafa9 SUB EDI,EAX
00ecafab JZ 0x00ecafc3
00ecafad XOR ECX,ECX
00ecafaf TEST EDI,EDI
00ecafb1 SETG CL
00ecafb4 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecafbb TEST ECX,ECX
00ecafbd JNZ 0x00ecaf07
00ecafc3 MOVZX EDI,byte ptr [ESI + -0x18]
00ecafc7 MOVZX EAX,byte ptr [EDX + -0x18]
00ecafcb SUB EDI,EAX
00ecafcd JZ 0x00ecafe5
00ecafcf XOR ECX,ECX
00ecafd1 TEST EDI,EDI
00ecafd3 SETG CL
00ecafd6 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecafdd TEST ECX,ECX
00ecafdf JNZ 0x00ecaf07
00ecafe5 MOVZX EDI,byte ptr [ESI + -0x17]
00ecafe9 MOVZX EAX,byte ptr [EDX + -0x17]
00ecafed SUB EDI,EAX
00ecafef JZ 0x00ecb007
00ecaff1 XOR ECX,ECX
00ecaff3 TEST EDI,EDI
00ecaff5 SETG CL
00ecaff8 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecafff TEST ECX,ECX
00ecb001 JNZ 0x00ecaf07
00ecb007 MOVZX ECX,byte ptr [ESI + -0x16]
00ecb00b MOVZX EAX,byte ptr [EDX + -0x16]
00ecb00f SUB ECX,EAX
00ecb011 JZ 0x00ecb025
00ecb013 XOR EAX,EAX
00ecb015 TEST ECX,ECX
00ecb017 SETG AL
00ecb01a LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb021 JMP 0x00ecb025
00ecb023 XOR ECX,ECX
00ecb025 TEST ECX,ECX
00ecb027 JNZ 0x00ecaf07
00ecb02d MOV EAX,dword ptr [ESI + -0x15]
00ecb030 CMP EAX,dword ptr [EDX + -0x15]
00ecb033 JZ 0x00ecb0ba
00ecb039 MOVZX EDI,AL
00ecb03c MOVZX EAX,byte ptr [EDX + -0x15]
00ecb040 SUB EDI,EAX
00ecb042 JZ 0x00ecb05a
00ecb044 XOR ECX,ECX
00ecb046 TEST EDI,EDI
00ecb048 SETG CL
00ecb04b LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb052 TEST ECX,ECX
00ecb054 JNZ 0x00ecaf07
00ecb05a MOVZX EDI,byte ptr [ESI + -0x14]
00ecb05e MOVZX EAX,byte ptr [EDX + -0x14]
00ecb062 SUB EDI,EAX
00ecb064 JZ 0x00ecb07c
00ecb066 XOR ECX,ECX
00ecb068 TEST EDI,EDI
00ecb06a SETG CL
00ecb06d LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb074 TEST ECX,ECX
00ecb076 JNZ 0x00ecaf07
00ecb07c MOVZX EDI,byte ptr [ESI + -0x13]
00ecb080 MOVZX EAX,byte ptr [EDX + -0x13]
00ecb084 SUB EDI,EAX
00ecb086 JZ 0x00ecb09e
00ecb088 XOR ECX,ECX
00ecb08a TEST EDI,EDI
00ecb08c SETG CL
00ecb08f LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb096 TEST ECX,ECX
00ecb098 JNZ 0x00ecaf07
00ecb09e MOVZX ECX,byte ptr [ESI + -0x12]
00ecb0a2 MOVZX EAX,byte ptr [EDX + -0x12]
00ecb0a6 SUB ECX,EAX
00ecb0a8 JZ 0x00ecb0bc
00ecb0aa XOR EAX,EAX
00ecb0ac TEST ECX,ECX
00ecb0ae SETG AL
00ecb0b1 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb0b8 JMP 0x00ecb0bc
00ecb0ba XOR ECX,ECX
00ecb0bc TEST ECX,ECX
00ecb0be JNZ 0x00ecaf07
00ecb0c4 MOV EAX,dword ptr [ESI + -0x11]
00ecb0c7 CMP EAX,dword ptr [EDX + -0x11]
00ecb0ca JZ 0x00ecb151
00ecb0d0 MOVZX EDI,AL
00ecb0d3 MOVZX EAX,byte ptr [EDX + -0x11]
00ecb0d7 SUB EDI,EAX
00ecb0d9 JZ 0x00ecb0f1
00ecb0db XOR ECX,ECX
00ecb0dd TEST EDI,EDI
00ecb0df SETG CL
00ecb0e2 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb0e9 TEST ECX,ECX
00ecb0eb JNZ 0x00ecaf07
00ecb0f1 MOVZX EDI,byte ptr [ESI + -0x10]
00ecb0f5 MOVZX EAX,byte ptr [EDX + -0x10]
00ecb0f9 SUB EDI,EAX
00ecb0fb JZ 0x00ecb113
00ecb0fd XOR ECX,ECX
00ecb0ff TEST EDI,EDI
00ecb101 SETG CL
00ecb104 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb10b TEST ECX,ECX
00ecb10d JNZ 0x00ecaf07
00ecb113 MOVZX EDI,byte ptr [ESI + -0xf]
00ecb117 MOVZX EAX,byte ptr [EDX + -0xf]
00ecb11b SUB EDI,EAX
00ecb11d JZ 0x00ecb135
00ecb11f XOR ECX,ECX
00ecb121 TEST EDI,EDI
00ecb123 SETG CL
00ecb126 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb12d TEST ECX,ECX
00ecb12f JNZ 0x00ecaf07
00ecb135 MOVZX ECX,byte ptr [ESI + -0xe]
00ecb139 MOVZX EAX,byte ptr [EDX + -0xe]
00ecb13d SUB ECX,EAX
00ecb13f JZ 0x00ecb153
00ecb141 XOR EAX,EAX
00ecb143 TEST ECX,ECX
00ecb145 SETG AL
00ecb148 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb14f JMP 0x00ecb153
00ecb151 XOR ECX,ECX
00ecb153 TEST ECX,ECX
00ecb155 JNZ 0x00ecaf07
00ecb15b MOV EAX,dword ptr [ESI + -0xd]
00ecb15e CMP EAX,dword ptr [EDX + -0xd]
00ecb161 JZ 0x00ecb1e8
00ecb167 MOVZX EDI,AL
00ecb16a MOVZX EAX,byte ptr [EDX + -0xd]
00ecb16e SUB EDI,EAX
00ecb170 JZ 0x00ecb188
00ecb172 XOR ECX,ECX
00ecb174 TEST EDI,EDI
00ecb176 SETG CL
00ecb179 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb180 TEST ECX,ECX
00ecb182 JNZ 0x00ecaf07
00ecb188 MOVZX EDI,byte ptr [ESI + -0xc]
00ecb18c MOVZX EAX,byte ptr [EDX + -0xc]
00ecb190 SUB EDI,EAX
00ecb192 JZ 0x00ecb1aa
00ecb194 XOR ECX,ECX
00ecb196 TEST EDI,EDI
00ecb198 SETG CL
00ecb19b LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb1a2 TEST ECX,ECX
00ecb1a4 JNZ 0x00ecaf07
00ecb1aa MOVZX EDI,byte ptr [ESI + -0xb]
00ecb1ae MOVZX EAX,byte ptr [EDX + -0xb]
00ecb1b2 SUB EDI,EAX
00ecb1b4 JZ 0x00ecb1cc
00ecb1b6 XOR ECX,ECX
00ecb1b8 TEST EDI,EDI
00ecb1ba SETG CL
00ecb1bd LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb1c4 TEST ECX,ECX
00ecb1c6 JNZ 0x00ecaf07
00ecb1cc MOVZX ECX,byte ptr [ESI + -0xa]
00ecb1d0 MOVZX EAX,byte ptr [EDX + -0xa]
00ecb1d4 SUB ECX,EAX
00ecb1d6 JZ 0x00ecb1ea
00ecb1d8 XOR EAX,EAX
00ecb1da TEST ECX,ECX
00ecb1dc SETG AL
00ecb1df LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb1e6 JMP 0x00ecb1ea
00ecb1e8 XOR ECX,ECX
00ecb1ea TEST ECX,ECX
00ecb1ec JNZ 0x00ecaf07
00ecb1f2 MOV EAX,dword ptr [ESI + -0x9]
00ecb1f5 CMP EAX,dword ptr [EDX + -0x9]
00ecb1f8 JZ 0x00ecb280
00ecb1fe MOVZX EAX,byte ptr [EDX + -0x9]
00ecb202 MOVZX EDI,byte ptr [ESI + -0x9]
00ecb206 SUB EDI,EAX
00ecb208 JZ 0x00ecb220
00ecb20a XOR ECX,ECX
00ecb20c TEST EDI,EDI
00ecb20e SETG CL
00ecb211 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb218 TEST ECX,ECX
00ecb21a JNZ 0x00ecaf07
00ecb220 MOVZX EDI,byte ptr [ESI + -0x8]
00ecb224 MOVZX EAX,byte ptr [EDX + -0x8]
00ecb228 SUB EDI,EAX
00ecb22a JZ 0x00ecb242
00ecb22c XOR ECX,ECX
00ecb22e TEST EDI,EDI
00ecb230 SETG CL
00ecb233 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb23a TEST ECX,ECX
00ecb23c JNZ 0x00ecaf07
00ecb242 MOVZX EDI,byte ptr [ESI + -0x7]
00ecb246 MOVZX EAX,byte ptr [EDX + -0x7]
00ecb24a SUB EDI,EAX
00ecb24c JZ 0x00ecb264
00ecb24e XOR ECX,ECX
00ecb250 TEST EDI,EDI
00ecb252 SETG CL
00ecb255 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb25c TEST ECX,ECX
00ecb25e JNZ 0x00ecaf07
00ecb264 MOVZX ECX,byte ptr [ESI + -0x6]
00ecb268 MOVZX EAX,byte ptr [EDX + -0x6]
00ecb26c SUB ECX,EAX
00ecb26e JZ 0x00ecb282
00ecb270 XOR EAX,EAX
00ecb272 TEST ECX,ECX
00ecb274 SETG AL
00ecb277 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb27e JMP 0x00ecb282
00ecb280 XOR ECX,ECX
00ecb282 TEST ECX,ECX
00ecb284 JNZ 0x00ecaf07
00ecb28a MOV EAX,dword ptr [ESI + -0x5]
00ecb28d CMP EAX,dword ptr [EDX + -0x5]
00ecb290 JZ 0x00ecb317
00ecb296 MOVZX EDI,AL
00ecb299 MOVZX EAX,byte ptr [EDX + -0x5]
00ecb29d SUB EDI,EAX
00ecb29f JZ 0x00ecb2b7
00ecb2a1 XOR ECX,ECX
00ecb2a3 TEST EDI,EDI
00ecb2a5 SETG CL
00ecb2a8 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb2af TEST ECX,ECX
00ecb2b1 JNZ 0x00ecaf07
00ecb2b7 MOVZX EDI,byte ptr [ESI + -0x4]
00ecb2bb MOVZX EAX,byte ptr [EDX + -0x4]
00ecb2bf SUB EDI,EAX
00ecb2c1 JZ 0x00ecb2d9
00ecb2c3 XOR ECX,ECX
00ecb2c5 TEST EDI,EDI
00ecb2c7 SETG CL
00ecb2ca LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb2d1 TEST ECX,ECX
00ecb2d3 JNZ 0x00ecaf07
00ecb2d9 MOVZX EDI,byte ptr [ESI + -0x3]
00ecb2dd MOVZX EAX,byte ptr [EDX + -0x3]
00ecb2e1 SUB EDI,EAX
00ecb2e3 JZ 0x00ecb2fb
00ecb2e5 XOR ECX,ECX
00ecb2e7 TEST EDI,EDI
00ecb2e9 SETG CL
00ecb2ec LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb2f3 TEST ECX,ECX
00ecb2f5 JNZ 0x00ecaf07
00ecb2fb MOVZX ECX,byte ptr [ESI + -0x2]
00ecb2ff MOVZX EAX,byte ptr [EDX + -0x2]
00ecb303 SUB ECX,EAX
00ecb305 JZ 0x00ecb319
00ecb307 XOR EAX,EAX
00ecb309 TEST ECX,ECX
00ecb30b SETG AL
00ecb30e LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb315 JMP 0x00ecb319
00ecb317 XOR ECX,ECX
00ecb319 TEST ECX,ECX
00ecb31b JNZ 0x00ecaf07
00ecb321 MOVZX EAX,byte ptr [EDX + -0x1]
00ecb325 MOVZX ECX,byte ptr [ESI + -0x1]
00ecb329 SUB ECX,EAX
00ecb32b JZ 0x00ecaf07
00ecb331 XOR EAX,EAX
00ecb333 TEST ECX,ECX
00ecb335 SETG AL
00ecb338 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb33f JMP 0x00ecaf07
00ecb344 MOV EAX,dword ptr [ESI + -0x1e]
00ecb347 CMP EAX,dword ptr [EDX + -0x1e]
00ecb34a JZ 0x00ecb3d1
00ecb350 MOVZX EDI,AL
00ecb353 MOVZX EAX,byte ptr [EDX + -0x1e]
00ecb357 SUB EDI,EAX
00ecb359 JZ 0x00ecb371
00ecb35b XOR ECX,ECX
00ecb35d TEST EDI,EDI
00ecb35f SETG CL
00ecb362 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb369 TEST ECX,ECX
00ecb36b JNZ 0x00ecaf07
00ecb371 MOVZX EDI,byte ptr [ESI + -0x1d]
00ecb375 MOVZX EAX,byte ptr [EDX + -0x1d]
00ecb379 SUB EDI,EAX
00ecb37b JZ 0x00ecb393
00ecb37d XOR ECX,ECX
00ecb37f TEST EDI,EDI
00ecb381 SETG CL
00ecb384 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb38b TEST ECX,ECX
00ecb38d JNZ 0x00ecaf07
00ecb393 MOVZX EDI,byte ptr [ESI + -0x1c]
00ecb397 MOVZX EAX,byte ptr [EDX + -0x1c]
00ecb39b SUB EDI,EAX
00ecb39d JZ 0x00ecb3b5
00ecb39f XOR ECX,ECX
00ecb3a1 TEST EDI,EDI
00ecb3a3 SETG CL
00ecb3a6 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb3ad TEST ECX,ECX
00ecb3af JNZ 0x00ecaf07
00ecb3b5 MOVZX ECX,byte ptr [ESI + -0x1b]
00ecb3b9 MOVZX EAX,byte ptr [EDX + -0x1b]
00ecb3bd SUB ECX,EAX
00ecb3bf JZ 0x00ecb3d3
00ecb3c1 XOR EAX,EAX
00ecb3c3 TEST ECX,ECX
00ecb3c5 SETG AL
00ecb3c8 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb3cf JMP 0x00ecb3d3
00ecb3d1 XOR ECX,ECX
00ecb3d3 TEST ECX,ECX
00ecb3d5 JNZ 0x00ecaf07
00ecb3db MOV EAX,dword ptr [ESI + -0x1a]
00ecb3de CMP EAX,dword ptr [EDX + -0x1a]
00ecb3e1 JZ 0x00ecb468
00ecb3e7 MOVZX EDI,AL
00ecb3ea MOVZX EAX,byte ptr [EDX + -0x1a]
00ecb3ee SUB EDI,EAX
00ecb3f0 JZ 0x00ecb408
00ecb3f2 XOR ECX,ECX
00ecb3f4 TEST EDI,EDI
00ecb3f6 SETG CL
00ecb3f9 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb400 TEST ECX,ECX
00ecb402 JNZ 0x00ecaf07
00ecb408 MOVZX EDI,byte ptr [ESI + -0x19]
00ecb40c MOVZX EAX,byte ptr [EDX + -0x19]
00ecb410 SUB EDI,EAX
00ecb412 JZ 0x00ecb42a
00ecb414 XOR ECX,ECX
00ecb416 TEST EDI,EDI
00ecb418 SETG CL
00ecb41b LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb422 TEST ECX,ECX
00ecb424 JNZ 0x00ecaf07
00ecb42a MOVZX EDI,byte ptr [ESI + -0x18]
00ecb42e MOVZX EAX,byte ptr [EDX + -0x18]
00ecb432 SUB EDI,EAX
00ecb434 JZ 0x00ecb44c
00ecb436 XOR ECX,ECX
00ecb438 TEST EDI,EDI
00ecb43a SETG CL
00ecb43d LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb444 TEST ECX,ECX
00ecb446 JNZ 0x00ecaf07
00ecb44c MOVZX ECX,byte ptr [ESI + -0x17]
00ecb450 MOVZX EAX,byte ptr [EDX + -0x17]
00ecb454 SUB ECX,EAX
00ecb456 JZ 0x00ecb46a
00ecb458 XOR EAX,EAX
00ecb45a TEST ECX,ECX
00ecb45c SETG AL
00ecb45f LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb466 JMP 0x00ecb46a
00ecb468 XOR ECX,ECX
00ecb46a TEST ECX,ECX
00ecb46c JNZ 0x00ecaf07
00ecb472 MOV EAX,dword ptr [ESI + -0x16]
00ecb475 CMP EAX,dword ptr [EDX + -0x16]
00ecb478 JZ 0x00ecb4ff
00ecb47e MOVZX EDI,AL
00ecb481 MOVZX EAX,byte ptr [EDX + -0x16]
00ecb485 SUB EDI,EAX
00ecb487 JZ 0x00ecb49f
00ecb489 XOR ECX,ECX
00ecb48b TEST EDI,EDI
00ecb48d SETG CL
00ecb490 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb497 TEST ECX,ECX
00ecb499 JNZ 0x00ecaf07
00ecb49f MOVZX EDI,byte ptr [ESI + -0x15]
00ecb4a3 MOVZX EAX,byte ptr [EDX + -0x15]
00ecb4a7 SUB EDI,EAX
00ecb4a9 JZ 0x00ecb4c1
00ecb4ab XOR ECX,ECX
00ecb4ad TEST EDI,EDI
00ecb4af SETG CL
00ecb4b2 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb4b9 TEST ECX,ECX
00ecb4bb JNZ 0x00ecaf07
00ecb4c1 MOVZX EDI,byte ptr [ESI + -0x14]
00ecb4c5 MOVZX EAX,byte ptr [EDX + -0x14]
00ecb4c9 SUB EDI,EAX
00ecb4cb JZ 0x00ecb4e3
00ecb4cd XOR ECX,ECX
00ecb4cf TEST EDI,EDI
00ecb4d1 SETG CL
00ecb4d4 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb4db TEST ECX,ECX
00ecb4dd JNZ 0x00ecaf07
00ecb4e3 MOVZX ECX,byte ptr [ESI + -0x13]
00ecb4e7 MOVZX EAX,byte ptr [EDX + -0x13]
00ecb4eb SUB ECX,EAX
00ecb4ed JZ 0x00ecb501
00ecb4ef XOR EAX,EAX
00ecb4f1 TEST ECX,ECX
00ecb4f3 SETG AL
00ecb4f6 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb4fd JMP 0x00ecb501
00ecb4ff XOR ECX,ECX
00ecb501 TEST ECX,ECX
00ecb503 JNZ 0x00ecaf07
00ecb509 MOV EAX,dword ptr [ESI + -0x12]
00ecb50c CMP EAX,dword ptr [EDX + -0x12]
00ecb50f JZ 0x00ecb596
00ecb515 MOVZX EDI,AL
00ecb518 MOVZX EAX,byte ptr [EDX + -0x12]
00ecb51c SUB EDI,EAX
00ecb51e JZ 0x00ecb536
00ecb520 XOR ECX,ECX
00ecb522 TEST EDI,EDI
00ecb524 SETG CL
00ecb527 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb52e TEST ECX,ECX
00ecb530 JNZ 0x00ecaf07
00ecb536 MOVZX EDI,byte ptr [ESI + -0x11]
00ecb53a MOVZX EAX,byte ptr [EDX + -0x11]
00ecb53e SUB EDI,EAX
00ecb540 JZ 0x00ecb558
00ecb542 XOR ECX,ECX
00ecb544 TEST EDI,EDI
00ecb546 SETG CL
00ecb549 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb550 TEST ECX,ECX
00ecb552 JNZ 0x00ecaf07
00ecb558 MOVZX EDI,byte ptr [ESI + -0x10]
00ecb55c MOVZX EAX,byte ptr [EDX + -0x10]
00ecb560 SUB EDI,EAX
00ecb562 JZ 0x00ecb57a
00ecb564 XOR ECX,ECX
00ecb566 TEST EDI,EDI
00ecb568 SETG CL
00ecb56b LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb572 TEST ECX,ECX
00ecb574 JNZ 0x00ecaf07
00ecb57a MOVZX ECX,byte ptr [ESI + -0xf]
00ecb57e MOVZX EAX,byte ptr [EDX + -0xf]
00ecb582 SUB ECX,EAX
00ecb584 JZ 0x00ecb598
00ecb586 XOR EAX,EAX
00ecb588 TEST ECX,ECX
00ecb58a SETG AL
00ecb58d LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb594 JMP 0x00ecb598
00ecb596 XOR ECX,ECX
00ecb598 TEST ECX,ECX
00ecb59a JNZ 0x00ecaf07
00ecb5a0 MOV EAX,dword ptr [ESI + -0xe]
00ecb5a3 CMP EAX,dword ptr [EDX + -0xe]
00ecb5a6 JZ 0x00ecb62d
00ecb5ac MOVZX EDI,AL
00ecb5af MOVZX EAX,byte ptr [EDX + -0xe]
00ecb5b3 SUB EDI,EAX
00ecb5b5 JZ 0x00ecb5cd
00ecb5b7 XOR ECX,ECX
00ecb5b9 TEST EDI,EDI
00ecb5bb SETG CL
00ecb5be LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb5c5 TEST ECX,ECX
00ecb5c7 JNZ 0x00ecaf07
00ecb5cd MOVZX EDI,byte ptr [ESI + -0xd]
00ecb5d1 MOVZX EAX,byte ptr [EDX + -0xd]
00ecb5d5 SUB EDI,EAX
00ecb5d7 JZ 0x00ecb5ef
00ecb5d9 XOR ECX,ECX
00ecb5db TEST EDI,EDI
00ecb5dd SETG CL
00ecb5e0 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb5e7 TEST ECX,ECX
00ecb5e9 JNZ 0x00ecaf07
00ecb5ef MOVZX EDI,byte ptr [ESI + -0xc]
00ecb5f3 MOVZX EAX,byte ptr [EDX + -0xc]
00ecb5f7 SUB EDI,EAX
00ecb5f9 JZ 0x00ecb611
00ecb5fb XOR ECX,ECX
00ecb5fd TEST EDI,EDI
00ecb5ff SETG CL
00ecb602 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb609 TEST ECX,ECX
00ecb60b JNZ 0x00ecaf07
00ecb611 MOVZX ECX,byte ptr [ESI + -0xb]
00ecb615 MOVZX EAX,byte ptr [EDX + -0xb]
00ecb619 SUB ECX,EAX
00ecb61b JZ 0x00ecb62f
00ecb61d XOR EAX,EAX
00ecb61f TEST ECX,ECX
00ecb621 SETG AL
00ecb624 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb62b JMP 0x00ecb62f
00ecb62d XOR ECX,ECX
00ecb62f TEST ECX,ECX
00ecb631 JNZ 0x00ecaf07
00ecb637 MOV EAX,dword ptr [ESI + -0xa]
00ecb63a CMP EAX,dword ptr [EDX + -0xa]
00ecb63d JZ 0x00ecb6c5
00ecb643 MOVZX EAX,byte ptr [EDX + -0xa]
00ecb647 MOVZX EDI,byte ptr [ESI + -0xa]
00ecb64b SUB EDI,EAX
00ecb64d JZ 0x00ecb665
00ecb64f XOR ECX,ECX
00ecb651 TEST EDI,EDI
00ecb653 SETG CL
00ecb656 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb65d TEST ECX,ECX
00ecb65f JNZ 0x00ecaf07
00ecb665 MOVZX EAX,byte ptr [EDX + -0x9]
00ecb669 MOVZX EDI,byte ptr [ESI + -0x9]
00ecb66d SUB EDI,EAX
00ecb66f JZ 0x00ecb687
00ecb671 XOR ECX,ECX
00ecb673 TEST EDI,EDI
00ecb675 SETG CL
00ecb678 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb67f TEST ECX,ECX
00ecb681 JNZ 0x00ecaf07
00ecb687 MOVZX EAX,byte ptr [EDX + -0x8]
00ecb68b MOVZX EDI,byte ptr [ESI + -0x8]
00ecb68f SUB EDI,EAX
00ecb691 JZ 0x00ecb6a9
00ecb693 XOR ECX,ECX
00ecb695 TEST EDI,EDI
00ecb697 SETG CL
00ecb69a LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb6a1 TEST ECX,ECX
00ecb6a3 JNZ 0x00ecaf07
00ecb6a9 MOVZX EAX,byte ptr [EDX + -0x7]
00ecb6ad MOVZX ECX,byte ptr [ESI + -0x7]
00ecb6b1 SUB ECX,EAX
00ecb6b3 JZ 0x00ecb6c7
00ecb6b5 XOR EAX,EAX
00ecb6b7 TEST ECX,ECX
00ecb6b9 SETG AL
00ecb6bc LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb6c3 JMP 0x00ecb6c7
00ecb6c5 XOR ECX,ECX
00ecb6c7 TEST ECX,ECX
00ecb6c9 JNZ 0x00ecaf07
00ecb6cf MOV EAX,dword ptr [ESI + -0x6]
00ecb6d2 CMP EAX,dword ptr [EDX + -0x6]
00ecb6d5 JZ 0x00ecb75c
00ecb6db MOVZX EDI,AL
00ecb6de MOVZX EAX,byte ptr [EDX + -0x6]
00ecb6e2 SUB EDI,EAX
00ecb6e4 JZ 0x00ecb6fc
00ecb6e6 XOR ECX,ECX
00ecb6e8 TEST EDI,EDI
00ecb6ea SETG CL
00ecb6ed LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb6f4 TEST ECX,ECX
00ecb6f6 JNZ 0x00ecaf07
00ecb6fc MOVZX EDI,byte ptr [ESI + -0x5]
00ecb700 MOVZX EAX,byte ptr [EDX + -0x5]
00ecb704 SUB EDI,EAX
00ecb706 JZ 0x00ecb71e
00ecb708 XOR ECX,ECX
00ecb70a TEST EDI,EDI
00ecb70c SETG CL
00ecb70f LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb716 TEST ECX,ECX
00ecb718 JNZ 0x00ecaf07
00ecb71e MOVZX EDI,byte ptr [ESI + -0x4]
00ecb722 MOVZX EAX,byte ptr [EDX + -0x4]
00ecb726 SUB EDI,EAX
00ecb728 JZ 0x00ecb740
00ecb72a XOR ECX,ECX
00ecb72c TEST EDI,EDI
00ecb72e SETG CL
00ecb731 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb738 TEST ECX,ECX
00ecb73a JNZ 0x00ecaf07
00ecb740 MOVZX ECX,byte ptr [ESI + -0x3]
00ecb744 MOVZX EAX,byte ptr [EDX + -0x3]
00ecb748 SUB ECX,EAX
00ecb74a JZ 0x00ecb75e
00ecb74c XOR EAX,EAX
00ecb74e TEST ECX,ECX
00ecb750 SETG AL
00ecb753 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb75a JMP 0x00ecb75e
00ecb75c XOR ECX,ECX
00ecb75e TEST ECX,ECX
00ecb760 JNZ 0x00ecaf07
00ecb766 MOV AX,word ptr [ESI + -0x2]
00ecb76a CMP AX,word ptr [EDX + -0x2]
00ecb76e JZ 0x00ecaf05
00ecb774 JMP 0x00ecbbbe
00ecb779 MOV EAX,dword ptr [ESI + -0x1f]
00ecb77c CMP EAX,dword ptr [EDX + -0x1f]
00ecb77f JZ 0x00ecb807
00ecb785 MOVZX EAX,byte ptr [EDX + -0x1f]
00ecb789 MOVZX EDI,byte ptr [ESI + -0x1f]
00ecb78d SUB EDI,EAX
00ecb78f JZ 0x00ecb7a7
00ecb791 XOR ECX,ECX
00ecb793 TEST EDI,EDI
00ecb795 SETG CL
00ecb798 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb79f TEST ECX,ECX
00ecb7a1 JNZ 0x00ecaf07
00ecb7a7 MOVZX EDI,byte ptr [ESI + -0x1e]
00ecb7ab MOVZX EAX,byte ptr [EDX + -0x1e]
00ecb7af SUB EDI,EAX
00ecb7b1 JZ 0x00ecb7c9
00ecb7b3 XOR ECX,ECX
00ecb7b5 TEST EDI,EDI
00ecb7b7 SETG CL
00ecb7ba LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb7c1 TEST ECX,ECX
00ecb7c3 JNZ 0x00ecaf07
00ecb7c9 MOVZX EDI,byte ptr [ESI + -0x1d]
00ecb7cd MOVZX EAX,byte ptr [EDX + -0x1d]
00ecb7d1 SUB EDI,EAX
00ecb7d3 JZ 0x00ecb7eb
00ecb7d5 XOR ECX,ECX
00ecb7d7 TEST EDI,EDI
00ecb7d9 SETG CL
00ecb7dc LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb7e3 TEST ECX,ECX
00ecb7e5 JNZ 0x00ecaf07
00ecb7eb MOVZX ECX,byte ptr [ESI + -0x1c]
00ecb7ef MOVZX EAX,byte ptr [EDX + -0x1c]
00ecb7f3 SUB ECX,EAX
00ecb7f5 JZ 0x00ecb809
00ecb7f7 XOR EAX,EAX
00ecb7f9 TEST ECX,ECX
00ecb7fb SETG AL
00ecb7fe LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb805 JMP 0x00ecb809
00ecb807 XOR ECX,ECX
00ecb809 TEST ECX,ECX
00ecb80b JNZ 0x00ecaf07
00ecb811 MOV EAX,dword ptr [ESI + -0x1b]
00ecb814 CMP EAX,dword ptr [EDX + -0x1b]
00ecb817 JZ 0x00ecb89e
00ecb81d MOVZX EDI,AL
00ecb820 MOVZX EAX,byte ptr [EDX + -0x1b]
00ecb824 SUB EDI,EAX
00ecb826 JZ 0x00ecb83e
00ecb828 XOR ECX,ECX
00ecb82a TEST EDI,EDI
00ecb82c SETG CL
00ecb82f LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb836 TEST ECX,ECX
00ecb838 JNZ 0x00ecaf07
00ecb83e MOVZX EDI,byte ptr [ESI + -0x1a]
00ecb842 MOVZX EAX,byte ptr [EDX + -0x1a]
00ecb846 SUB EDI,EAX
00ecb848 JZ 0x00ecb860
00ecb84a XOR ECX,ECX
00ecb84c TEST EDI,EDI
00ecb84e SETG CL
00ecb851 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb858 TEST ECX,ECX
00ecb85a JNZ 0x00ecaf07
00ecb860 MOVZX EDI,byte ptr [ESI + -0x19]
00ecb864 MOVZX EAX,byte ptr [EDX + -0x19]
00ecb868 SUB EDI,EAX
00ecb86a JZ 0x00ecb882
00ecb86c XOR ECX,ECX
00ecb86e TEST EDI,EDI
00ecb870 SETG CL
00ecb873 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb87a TEST ECX,ECX
00ecb87c JNZ 0x00ecaf07
00ecb882 MOVZX ECX,byte ptr [ESI + -0x18]
00ecb886 MOVZX EAX,byte ptr [EDX + -0x18]
00ecb88a SUB ECX,EAX
00ecb88c JZ 0x00ecb8a0
00ecb88e XOR EAX,EAX
00ecb890 TEST ECX,ECX
00ecb892 SETG AL
00ecb895 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb89c JMP 0x00ecb8a0
00ecb89e XOR ECX,ECX
00ecb8a0 TEST ECX,ECX
00ecb8a2 JNZ 0x00ecaf07
00ecb8a8 MOV EAX,dword ptr [ESI + -0x17]
00ecb8ab CMP EAX,dword ptr [EDX + -0x17]
00ecb8ae JZ 0x00ecb935
00ecb8b4 MOVZX EDI,AL
00ecb8b7 MOVZX EAX,byte ptr [EDX + -0x17]
00ecb8bb SUB EDI,EAX
00ecb8bd JZ 0x00ecb8d5
00ecb8bf XOR ECX,ECX
00ecb8c1 TEST EDI,EDI
00ecb8c3 SETG CL
00ecb8c6 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb8cd TEST ECX,ECX
00ecb8cf JNZ 0x00ecaf07
00ecb8d5 MOVZX EDI,byte ptr [ESI + -0x16]
00ecb8d9 MOVZX EAX,byte ptr [EDX + -0x16]
00ecb8dd SUB EDI,EAX
00ecb8df JZ 0x00ecb8f7
00ecb8e1 XOR ECX,ECX
00ecb8e3 TEST EDI,EDI
00ecb8e5 SETG CL
00ecb8e8 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb8ef TEST ECX,ECX
00ecb8f1 JNZ 0x00ecaf07
00ecb8f7 MOVZX EDI,byte ptr [ESI + -0x15]
00ecb8fb MOVZX EAX,byte ptr [EDX + -0x15]
00ecb8ff SUB EDI,EAX
00ecb901 JZ 0x00ecb919
00ecb903 XOR ECX,ECX
00ecb905 TEST EDI,EDI
00ecb907 SETG CL
00ecb90a LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb911 TEST ECX,ECX
00ecb913 JNZ 0x00ecaf07
00ecb919 MOVZX ECX,byte ptr [ESI + -0x14]
00ecb91d MOVZX EAX,byte ptr [EDX + -0x14]
00ecb921 SUB ECX,EAX
00ecb923 JZ 0x00ecb937
00ecb925 XOR EAX,EAX
00ecb927 TEST ECX,ECX
00ecb929 SETG AL
00ecb92c LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb933 JMP 0x00ecb937
00ecb935 XOR ECX,ECX
00ecb937 TEST ECX,ECX
00ecb939 JNZ 0x00ecaf07
00ecb93f MOV EAX,dword ptr [ESI + -0x13]
00ecb942 CMP EAX,dword ptr [EDX + -0x13]
00ecb945 JZ 0x00ecb9cc
00ecb94b MOVZX EDI,AL
00ecb94e MOVZX EAX,byte ptr [EDX + -0x13]
00ecb952 SUB EDI,EAX
00ecb954 JZ 0x00ecb96c
00ecb956 XOR ECX,ECX
00ecb958 TEST EDI,EDI
00ecb95a SETG CL
00ecb95d LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb964 TEST ECX,ECX
00ecb966 JNZ 0x00ecaf07
00ecb96c MOVZX EDI,byte ptr [ESI + -0x12]
00ecb970 MOVZX EAX,byte ptr [EDX + -0x12]
00ecb974 SUB EDI,EAX
00ecb976 JZ 0x00ecb98e
00ecb978 XOR ECX,ECX
00ecb97a TEST EDI,EDI
00ecb97c SETG CL
00ecb97f LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb986 TEST ECX,ECX
00ecb988 JNZ 0x00ecaf07
00ecb98e MOVZX EDI,byte ptr [ESI + -0x11]
00ecb992 MOVZX EAX,byte ptr [EDX + -0x11]
00ecb996 SUB EDI,EAX
00ecb998 JZ 0x00ecb9b0
00ecb99a XOR ECX,ECX
00ecb99c TEST EDI,EDI
00ecb99e SETG CL
00ecb9a1 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb9a8 TEST ECX,ECX
00ecb9aa JNZ 0x00ecaf07
00ecb9b0 MOVZX ECX,byte ptr [ESI + -0x10]
00ecb9b4 MOVZX EAX,byte ptr [EDX + -0x10]
00ecb9b8 SUB ECX,EAX
00ecb9ba JZ 0x00ecb9ce
00ecb9bc XOR EAX,EAX
00ecb9be TEST ECX,ECX
00ecb9c0 SETG AL
00ecb9c3 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecb9ca JMP 0x00ecb9ce
00ecb9cc XOR ECX,ECX
00ecb9ce TEST ECX,ECX
00ecb9d0 JNZ 0x00ecaf07
00ecb9d6 MOV EAX,dword ptr [ESI + -0xf]
00ecb9d9 CMP EAX,dword ptr [EDX + -0xf]
00ecb9dc JZ 0x00ecba64
00ecb9e2 MOVZX EAX,byte ptr [EDX + -0xf]
00ecb9e6 MOVZX EDI,byte ptr [ESI + -0xf]
00ecb9ea SUB EDI,EAX
00ecb9ec JZ 0x00ecba04
00ecb9ee XOR ECX,ECX
00ecb9f0 TEST EDI,EDI
00ecb9f2 SETG CL
00ecb9f5 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecb9fc TEST ECX,ECX
00ecb9fe JNZ 0x00ecaf07
00ecba04 MOVZX EDI,byte ptr [ESI + -0xe]
00ecba08 MOVZX EAX,byte ptr [EDX + -0xe]
00ecba0c SUB EDI,EAX
00ecba0e JZ 0x00ecba26
00ecba10 XOR ECX,ECX
00ecba12 TEST EDI,EDI
00ecba14 SETG CL
00ecba17 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecba1e TEST ECX,ECX
00ecba20 JNZ 0x00ecaf07
00ecba26 MOVZX EDI,byte ptr [ESI + -0xd]
00ecba2a MOVZX EAX,byte ptr [EDX + -0xd]
00ecba2e SUB EDI,EAX
00ecba30 JZ 0x00ecba48
00ecba32 XOR ECX,ECX
00ecba34 TEST EDI,EDI
00ecba36 SETG CL
00ecba39 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecba40 TEST ECX,ECX
00ecba42 JNZ 0x00ecaf07
00ecba48 MOVZX ECX,byte ptr [ESI + -0xc]
00ecba4c MOVZX EAX,byte ptr [EDX + -0xc]
00ecba50 SUB ECX,EAX
00ecba52 JZ 0x00ecba66
00ecba54 XOR EAX,EAX
00ecba56 TEST ECX,ECX
00ecba58 SETG AL
00ecba5b LEA ECX,[EAX*0x2 + 0xffffffff]
00ecba62 JMP 0x00ecba66
00ecba64 XOR ECX,ECX
00ecba66 TEST ECX,ECX
00ecba68 JNZ 0x00ecaf07
00ecba6e MOV EAX,dword ptr [ESI + -0xb]
00ecba71 CMP EAX,dword ptr [EDX + -0xb]
00ecba74 JZ 0x00ecbafb
00ecba7a MOVZX EDI,AL
00ecba7d MOVZX EAX,byte ptr [EDX + -0xb]
00ecba81 SUB EDI,EAX
00ecba83 JZ 0x00ecba9b
00ecba85 XOR ECX,ECX
00ecba87 TEST EDI,EDI
00ecba89 SETG CL
00ecba8c LEA ECX,[ECX*0x2 + 0xffffffff]
00ecba93 TEST ECX,ECX
00ecba95 JNZ 0x00ecaf07
00ecba9b MOVZX EDI,byte ptr [ESI + -0xa]
00ecba9f MOVZX EAX,byte ptr [EDX + -0xa]
00ecbaa3 SUB EDI,EAX
00ecbaa5 JZ 0x00ecbabd
00ecbaa7 XOR ECX,ECX
00ecbaa9 TEST EDI,EDI
00ecbaab SETG CL
00ecbaae LEA ECX,[ECX*0x2 + 0xffffffff]
00ecbab5 TEST ECX,ECX
00ecbab7 JNZ 0x00ecaf07
00ecbabd MOVZX EDI,byte ptr [ESI + -0x9]
00ecbac1 MOVZX EAX,byte ptr [EDX + -0x9]
00ecbac5 SUB EDI,EAX
00ecbac7 JZ 0x00ecbadf
00ecbac9 XOR ECX,ECX
00ecbacb TEST EDI,EDI
00ecbacd SETG CL
00ecbad0 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecbad7 TEST ECX,ECX
00ecbad9 JNZ 0x00ecaf07
00ecbadf MOVZX ECX,byte ptr [ESI + -0x8]
00ecbae3 MOVZX EAX,byte ptr [EDX + -0x8]
00ecbae7 SUB ECX,EAX
00ecbae9 JZ 0x00ecbafd
00ecbaeb XOR EAX,EAX
00ecbaed TEST ECX,ECX
00ecbaef SETG AL
00ecbaf2 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecbaf9 JMP 0x00ecbafd
00ecbafb XOR ECX,ECX
00ecbafd TEST ECX,ECX
00ecbaff JNZ 0x00ecaf07
00ecbb05 MOV EAX,dword ptr [ESI + -0x7]
00ecbb08 CMP EAX,dword ptr [EDX + -0x7]
00ecbb0b JZ 0x00ecbb92
00ecbb11 MOVZX EDI,AL
00ecbb14 MOVZX EAX,byte ptr [EDX + -0x7]
00ecbb18 SUB EDI,EAX
00ecbb1a JZ 0x00ecbb32
00ecbb1c XOR ECX,ECX
00ecbb1e TEST EDI,EDI
00ecbb20 SETG CL
00ecbb23 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecbb2a TEST ECX,ECX
00ecbb2c JNZ 0x00ecaf07
00ecbb32 MOVZX EDI,byte ptr [ESI + -0x6]
00ecbb36 MOVZX EAX,byte ptr [EDX + -0x6]
00ecbb3a SUB EDI,EAX
00ecbb3c JZ 0x00ecbb54
00ecbb3e XOR ECX,ECX
00ecbb40 TEST EDI,EDI
00ecbb42 SETG CL
00ecbb45 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecbb4c TEST ECX,ECX
00ecbb4e JNZ 0x00ecaf07
00ecbb54 MOVZX EDI,byte ptr [ESI + -0x5]
00ecbb58 MOVZX EAX,byte ptr [EDX + -0x5]
00ecbb5c SUB EDI,EAX
00ecbb5e JZ 0x00ecbb76
00ecbb60 XOR ECX,ECX
00ecbb62 TEST EDI,EDI
00ecbb64 SETG CL
00ecbb67 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecbb6e TEST ECX,ECX
00ecbb70 JNZ 0x00ecaf07
00ecbb76 MOVZX ECX,byte ptr [ESI + -0x4]
00ecbb7a MOVZX EAX,byte ptr [EDX + -0x4]
00ecbb7e SUB ECX,EAX
00ecbb80 JZ 0x00ecbb94
00ecbb82 XOR EAX,EAX
00ecbb84 TEST ECX,ECX
00ecbb86 SETG AL
00ecbb89 LEA ECX,[EAX*0x2 + 0xffffffff]
00ecbb90 JMP 0x00ecbb94
00ecbb92 XOR ECX,ECX
00ecbb94 TEST ECX,ECX
00ecbb96 JNZ 0x00ecaf07
00ecbb9c MOVZX EDI,byte ptr [ESI + -0x3]
00ecbba0 MOVZX EAX,byte ptr [EDX + -0x3]
00ecbba4 SUB EDI,EAX
00ecbba6 JZ 0x00ecbbbe
00ecbba8 XOR ECX,ECX
00ecbbaa TEST EDI,EDI
00ecbbac SETG CL
00ecbbaf LEA ECX,[ECX*0x2 + 0xffffffff]
00ecbbb6 TEST ECX,ECX
00ecbbb8 JNZ 0x00ecaf07
00ecbbbe MOVZX EAX,byte ptr [EDX + -0x2]
00ecbbc2 MOVZX EDI,byte ptr [ESI + -0x2]
00ecbbc6 SUB EDI,EAX
00ecbbc8 JZ 0x00ecb321
00ecbbce XOR ECX,ECX
00ecbbd0 TEST EDI,EDI
00ecbbd2 SETG CL
00ecbbd5 LEA ECX,[ECX*0x2 + 0xffffffff]
00ecbbdc JMP 0x00ecb319
00ecbbe1 MOV ECX,dword ptr [EBP + 0x8]
00ecbbe4 MOVZX EAX,byte ptr [EDX]
00ecbbe7 MOVZX ESI,byte ptr [ECX]
00ecbbea SUB ESI,EAX
00ecbbec JZ 0x00ecbc04
00ecbbee XOR EAX,EAX
00ecbbf0 TEST ESI,ESI
00ecbbf2 SETG AL
00ecbbf5 LEA EAX,[EAX*0x2 + 0xffffffff]
00ecbbfc TEST EAX,EAX
00ecbbfe JNZ 0x00ecbcf5
00ecbc04 MOVZX ESI,byte ptr [ECX + 0x1]
00ecbc08 MOVZX EAX,byte ptr [EDX + 0x1]
00ecbc0c SUB ESI,EAX
00ecbc0e JZ 0x00ecbc26
00ecbc10 XOR EAX,EAX
00ecbc12 TEST ESI,ESI
00ecbc14 SETG AL
00ecbc17 LEA EAX,[EAX*0x2 + 0xffffffff]
00ecbc1e TEST EAX,EAX
00ecbc20 JNZ 0x00ecbcf5
00ecbc26 MOVZX ESI,byte ptr [ECX + 0x2]
00ecbc2a MOVZX EAX,byte ptr [EDX + 0x2]
00ecbc2e SUB ESI,EAX
00ecbc30 JZ 0x00ecbc48
00ecbc32 XOR EAX,EAX
00ecbc34 TEST ESI,ESI
00ecbc36 SETG AL
00ecbc39 LEA EAX,[EAX*0x2 + 0xffffffff]
00ecbc40 TEST EAX,EAX
00ecbc42 JNZ 0x00ecbcf5
00ecbc48 MOVZX ECX,byte ptr [ECX + 0x3]
00ecbc4c MOVZX EAX,byte ptr [EDX + 0x3]
00ecbc50 SUB ECX,EAX
00ecbc52 JZ 0x00ecbc62
00ecbc54 XOR EAX,EAX
00ecbc56 TEST ECX,ECX
00ecbc58 SETG AL
00ecbc5b LEA ECX,[EAX*0x2 + 0xffffffff]
00ecbc62 MOV EAX,ECX
00ecbc64 JMP 0x00ecbcf5
00ecbc69 MOV EDX,dword ptr [EBP + 0x8]
00ecbc6c MOV ESI,dword ptr [EBP + 0xc]
00ecbc6f MOVZX ECX,byte ptr [EDX]
00ecbc72 MOVZX EAX,byte ptr [ESI]
00ecbc75 SUB ECX,EAX
00ecbc77 JZ 0x00ecbc8b
00ecbc79 XOR EAX,EAX
00ecbc7b TEST ECX,ECX
00ecbc7d SETG AL
00ecbc80 LEA EAX,[EAX*0x2 + 0xffffffff]
00ecbc87 TEST EAX,EAX
00ecbc89 JNZ 0x00ecbcf5
00ecbc8b MOVZX ECX,byte ptr [EDX + 0x1]
00ecbc8f MOVZX EAX,byte ptr [ESI + 0x1]
00ecbc93 SUB ECX,EAX
00ecbc95 JZ 0x00ecbca9
00ecbc97 XOR EAX,EAX
00ecbc99 TEST ECX,ECX
00ecbc9b SETG AL
00ecbc9e LEA EAX,[EAX*0x2 + 0xffffffff]
00ecbca5 TEST EAX,EAX
00ecbca7 JNZ 0x00ecbcf5
00ecbca9 MOVZX ECX,byte ptr [EDX + 0x2]
00ecbcad MOVZX EAX,byte ptr [ESI + 0x2]
00ecbcb1 JMP 0x00ecbc50
00ecbcb3 MOV EDX,dword ptr [EBP + 0x8]
00ecbcb6 MOV ESI,dword ptr [EBP + 0xc]
00ecbcb9 MOVZX ECX,byte ptr [EDX]
00ecbcbc MOVZX EAX,byte ptr [ESI]
00ecbcbf SUB ECX,EAX
00ecbcc1 JZ 0x00ecbcd5
00ecbcc3 XOR EAX,EAX
00ecbcc5 TEST ECX,ECX
00ecbcc7 SETG AL
00ecbcca LEA EAX,[EAX*0x2 + 0xffffffff]
00ecbcd1 TEST EAX,EAX
00ecbcd3 JNZ 0x00ecbcf5
00ecbcd5 MOVZX ECX,byte ptr [EDX + 0x1]
00ecbcd9 MOVZX EAX,byte ptr [ESI + 0x1]
00ecbcdd JMP 0x00ecbc50
00ecbce2 MOV EAX,dword ptr [EBP + 0x8]
00ecbce5 MOVZX ECX,byte ptr [EAX]
00ecbce8 MOV EAX,dword ptr [EBP + 0xc]
00ecbceb MOVZX EAX,byte ptr [EAX]
00ecbcee JMP 0x00ecbc50
00ecbcf3 XOR EAX,EAX
00ecbcf5 POP ESI
00ecbcf6 POP EBX
00ecbcf7 POP EBP
00ecbcf8 RET

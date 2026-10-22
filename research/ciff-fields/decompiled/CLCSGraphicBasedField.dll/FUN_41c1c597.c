// Source: CLCSGraphicBasedField.dll @ 41c1c597; FUN_41c1c597

int __cdecl
FUN_41c1c597(short *param_1,uint param_2,short *param_3,short *param_4,short *param_5,short *param_6
            )

{
  short sVar1;
  int *piVar2;
  short *psVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  short *psVar7;
  int iStack_14;
  
  if ((param_1 == (short *)0x0) || (param_2 == 0)) {
    piVar2 = __errno();
    iStack_14 = 0x16;
    goto LAB_41c1c6ab;
  }
  uVar5 = 0;
  psVar4 = param_1;
  if ((param_3 == (short *)0x0) || (*param_3 == 0)) {
LAB_41c1c5e1:
    if ((param_4 != (short *)0x0) && (*param_4 != 0)) {
      do {
        psVar7 = param_4;
        uVar6 = uVar5;
        psVar3 = psVar4;
        uVar5 = uVar6 + 1;
        if (param_2 <= uVar5) goto LAB_41c1c68f;
        *psVar3 = *psVar7;
        psVar4 = psVar3 + 1;
        param_4 = psVar7 + 1;
      } while (psVar7[1] != 0);
      if ((*psVar7 != 0x2f) && (*psVar7 != 0x5c)) {
        uVar5 = uVar6 + 2;
        if (param_2 <= uVar5) goto LAB_41c1c68f;
        *psVar4 = 0x5c;
        psVar4 = psVar3 + 2;
      }
    }
    if (param_5 != (short *)0x0) {
      for (; *param_5 != 0; param_5 = param_5 + 1) {
        uVar5 = uVar5 + 1;
        if (param_2 <= uVar5) goto LAB_41c1c68f;
        *psVar4 = *param_5;
        psVar4 = psVar4 + 1;
      }
    }
    if ((param_6 == (short *)0x0) || (*param_6 == 0)) {
LAB_41c1c688:
      if (uVar5 + 1 <= param_2) {
        *psVar4 = 0;
        return 0;
      }
    }
    else {
      if (*param_6 == 0x2e) goto LAB_41c1c681;
      uVar5 = uVar5 + 1;
      if (uVar5 < param_2) {
        sVar1 = 0x2e;
        while( true ) {
          *psVar4 = sVar1;
          psVar4 = psVar4 + 1;
LAB_41c1c681:
          if (*param_6 == 0) goto LAB_41c1c688;
          uVar5 = uVar5 + 1;
          if (param_2 <= uVar5) break;
          sVar1 = *param_6;
          param_6 = param_6 + 1;
        }
      }
    }
  }
  else {
    uVar5 = 2;
    if (2 < param_2) {
      *param_1 = *param_3;
      param_1[1] = 0x3a;
      psVar4 = param_1 + 2;
      goto LAB_41c1c5e1;
    }
  }
LAB_41c1c68f:
  *param_1 = 0;
  piVar2 = __errno();
  iStack_14 = 0x22;
LAB_41c1c6ab:
  *piVar2 = iStack_14;
  FUN_41c1e6f2();
  return iStack_14;
}



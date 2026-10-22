// Source: CLCSGraphicBasedField.dll @ 41c1c6ba; FUN_41c1c6ba

undefined4 __cdecl
FUN_41c1c6ba(short *param_1,short *param_2,uint param_3,short *param_4,uint param_5,short *param_6,
            uint param_7,short *param_8,uint param_9)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  short *psVar6;
  short *psVar7;
  short *psVar8;
  
  psVar7 = (short *)0x0;
  if (param_1 != (short *)0x0) {
    if (param_2 == (short *)0x0) {
      if (param_3 == 0) {
LAB_41c1c6e8:
        if (param_4 == (short *)0x0) {
          if (param_5 == 0) {
LAB_41c1c6f9:
            if (param_6 == (short *)0x0) {
              if (param_7 == 0) {
LAB_41c1c70c:
                if (param_8 == (short *)0x0) {
                  if (param_9 == 0) {
LAB_41c1c71d:
                    iVar2 = 1;
                    psVar6 = param_1;
                    do {
                      if (*psVar6 == 0) break;
                      psVar6 = psVar6 + 1;
                      iVar2 = iVar2 + -1;
                    } while (iVar2 != 0);
                    if (*psVar6 == 0x3a) {
                      if (param_2 != (short *)0x0) {
                        if (param_3 < 3) goto LAB_41c1c84b;
                        FUN_41c1a99d(param_2,param_3,param_1,2);
                      }
                      param_1 = psVar6 + 1;
                    }
                    else if (param_2 != (short *)0x0) {
                      *param_2 = 0;
                    }
                    sVar1 = *param_1;
                    psVar6 = (short *)0x0;
                    psVar8 = param_1;
                    if (sVar1 == 0) {
LAB_41c1c7c1:
                      psVar6 = param_1;
                      if (param_4 != (short *)0x0) {
                        *param_4 = 0;
                      }
LAB_41c1c7cd:
                      param_1 = psVar6;
                      if ((psVar7 == (short *)0x0) || (psVar7 < psVar6)) {
                        if (param_6 == (short *)0x0) {
LAB_41c1c836:
                          if (param_8 == (short *)0x0) {
                            return 0;
                          }
                          *param_8 = 0;
                          return 0;
                        }
                        uVar3 = (int)psVar8 - (int)psVar6 >> 1;
                        if (uVar3 < param_7) {
                          FUN_41c1a99d(param_6,param_7,psVar6,uVar3);
                          goto LAB_41c1c836;
                        }
                      }
                      else {
                        if (param_6 != (short *)0x0) {
                          uVar3 = (int)psVar7 - (int)psVar6 >> 1;
                          if (param_7 <= uVar3) goto LAB_41c1c849;
                          FUN_41c1a99d(param_6,param_7,psVar6,uVar3);
                        }
                        if (param_8 == (short *)0x0) {
                          return 0;
                        }
                        uVar3 = (int)psVar8 - (int)psVar7 >> 1;
                        if (uVar3 < param_9) {
                          FUN_41c1a99d(param_8,param_9,psVar7,uVar3);
                          return 0;
                        }
                      }
                    }
                    else {
                      do {
                        if ((sVar1 == 0x2f) || (sVar1 == 0x5c)) {
                          psVar6 = psVar8 + 1;
                        }
                        else if (sVar1 == 0x2e) {
                          psVar7 = psVar8;
                        }
                        psVar8 = psVar8 + 1;
                        sVar1 = *psVar8;
                      } while (sVar1 != 0);
                      if (psVar6 == (short *)0x0) goto LAB_41c1c7c1;
                      if (param_4 == (short *)0x0) goto LAB_41c1c7cd;
                      uVar3 = (int)psVar6 - (int)param_1 >> 1;
                      if (uVar3 < param_5) {
                        FUN_41c1a99d(param_4,param_5,param_1,uVar3);
                        goto LAB_41c1c7cd;
                      }
                    }
LAB_41c1c849:
                    psVar7 = (short *)0x0;
                    goto LAB_41c1c84b;
                  }
                }
                else if (param_9 != 0) goto LAB_41c1c71d;
              }
            }
            else if (param_7 != 0) goto LAB_41c1c70c;
          }
        }
        else if (param_5 != 0) goto LAB_41c1c6f9;
      }
    }
    else if (param_3 != 0) goto LAB_41c1c6e8;
  }
  psVar7 = (short *)0x1;
LAB_41c1c84b:
  if ((param_2 != (short *)0x0) && (param_3 != 0)) {
    *param_2 = 0;
  }
  if ((param_4 != (short *)0x0) && (param_5 != 0)) {
    *param_4 = 0;
  }
  if ((param_6 != (short *)0x0) && (param_7 != 0)) {
    *param_6 = 0;
  }
  if ((param_8 != (short *)0x0) && (param_9 != 0)) {
    *param_8 = 0;
  }
  piVar4 = __errno();
  if ((param_1 == (short *)0x0) || (psVar7 != (short *)0x0)) {
    uVar5 = 0x16;
    *piVar4 = 0x16;
    FUN_41c1e6f2();
  }
  else {
    uVar5 = 0x22;
    *piVar4 = 0x22;
  }
  return uVar5;
}



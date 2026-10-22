// Source: CLCiffConversion_Layout.dll @ 4542e60d; FUN_4542e60d

int FUN_4542e60d(uint param_1,short *param_2,uint param_3,uint param_4,uint param_5)

{
  short *psVar1;
  short sVar2;
  int *piVar3;
  short *psVar4;
  short *psVar5;
  int iStack_14;
  
  if (param_2 == (short *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45432798();
    return 0x16;
  }
  if (param_3 != 0) {
    *param_2 = 0;
    if (param_3 <= (param_5 != 0) + 1) {
      piVar3 = __errno();
      iStack_14 = 0x22;
      goto LAB_4542e6ce;
    }
    iStack_14 = 0x22;
    if (param_4 - 2 < 0x23) {
      psVar4 = param_2;
      if (param_5 != 0) {
        *param_2 = 0x2d;
        psVar4 = param_2 + 1;
        param_1 = -param_1;
      }
      param_5 = (uint)(param_5 != 0);
      psVar1 = psVar4;
      do {
        psVar5 = psVar1;
        sVar2 = (short)(param_1 % param_4);
        if (param_1 % param_4 < 10) {
          sVar2 = sVar2 + 0x30;
        }
        else {
          sVar2 = sVar2 + 0x57;
        }
        *psVar5 = sVar2;
        param_5 = param_5 + 1;
      } while ((param_1 / param_4 != 0) &&
              (param_1 = param_1 / param_4, psVar1 = psVar5 + 1, param_5 < param_3));
      if (param_5 < param_3) {
        psVar5[1] = 0;
        do {
          sVar2 = *psVar5;
          *psVar5 = *psVar4;
          psVar5 = psVar5 + -1;
          *psVar4 = sVar2;
          psVar4 = psVar4 + 1;
        } while (psVar4 < psVar5);
        return 0;
      }
      *param_2 = 0;
      piVar3 = __errno();
      goto LAB_4542e6ce;
    }
  }
  piVar3 = __errno();
  iStack_14 = 0x16;
LAB_4542e6ce:
  *piVar3 = iStack_14;
  FUN_45432798();
  return iStack_14;
}



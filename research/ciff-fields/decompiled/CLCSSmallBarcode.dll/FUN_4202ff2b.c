// Source: CLCSSmallBarcode.dll @ 4202ff2b; FUN_4202ff2b

int * FUN_4202ff2b(byte *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if (param_2 < 2) {
    *param_3 = 7;
    return (int *)0x0;
  }
  iVar1 = _isdigit((uint)*param_1);
  if ((iVar1 != 0) && (iVar1 = _isdigit((uint)param_1[1]), iVar1 != 0)) {
    iVar1 = (param_1[1] - 0x210) + (uint)*param_1 * 10;
    piVar3 = FUN_4202fe6c(iVar1,2);
    if ((piVar3[7] != -1) && (piVar3[7] != -2)) {
      return piVar3;
    }
    if (param_2 < 3) {
LAB_4202ffce:
      *param_3 = 7;
      return piVar3;
    }
    iVar2 = _isdigit((uint)param_1[2]);
    if (iVar2 != 0) {
      iVar1 = (uint)param_1[2] + iVar1 * 10 + -0x30;
      if (piVar3[7] == -2) {
        if (param_2 < 4) goto LAB_4202ffce;
        iVar2 = _isdigit((uint)param_1[3]);
        if (iVar2 == 0) goto LAB_42030007;
        iVar2 = 4;
        iVar1 = (uint)param_1[3] + iVar1 * 10 + -0x30;
      }
      else {
        iVar2 = 3;
      }
      piVar3 = FUN_4202fe6c(iVar1,iVar2);
      return piVar3;
    }
  }
LAB_42030007:
  *param_3 = 8;
  return piVar3;
}



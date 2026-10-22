// Source: CLCiffConversion_Data.dll @ 45031354; FUN_45031354

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_45031354(int param_1,int param_2,int param_3,int param_4,double *param_5)

{
  double dVar1;
  double dVar2;
  int iVar3;
  
  dVar1 = ABS((double)CONCAT44(param_2,param_1));
  dVar2 = _DAT_45052228;
  if (param_4 == 0x7ff00000) {
    if (param_3 == 0) {
      if ((dVar1 <= 1.0) && (dVar2 = 1.0, dVar1 < 1.0)) {
        dVar2 = 0.0;
      }
      goto LAB_45031478;
    }
  }
  else if ((param_4 == -0x100000) && (param_3 == 0)) {
    if (dVar1 <= 1.0) {
      if (1.0 <= dVar1) {
        *param_5 = _DAT_45052230;
        return 1;
      }
    }
    else {
      dVar2 = 0.0;
    }
    goto LAB_45031478;
  }
  if (param_2 == 0x7ff00000) {
    if (param_1 != 0) {
      return 0;
    }
    if (((double)CONCAT44(param_4,param_3) <= 0.0) &&
       (dVar2 = 0.0, 0.0 <= (double)CONCAT44(param_4,param_3))) {
      dVar2 = 1.0;
    }
  }
  else {
    if (param_2 != -0x100000) {
      return 0;
    }
    if (param_1 != 0) {
      return 0;
    }
    iVar3 = FUN_450312ec((double)CONCAT44(param_4,param_3));
    if ((double)CONCAT44(param_4,param_3) <= 0.0) {
      if (0.0 <= (double)CONCAT44(param_4,param_3)) {
        *param_5 = 1.0;
        return 0;
      }
      dVar2 = 0.0;
      if (iVar3 == 1) {
        dVar2 = _DAT_45052248;
      }
    }
    else {
      dVar2 = _DAT_45052228;
      if (iVar3 == 1) {
        dVar2 = -_DAT_45052228;
      }
    }
  }
LAB_45031478:
  *param_5 = dVar2;
  return 0;
}



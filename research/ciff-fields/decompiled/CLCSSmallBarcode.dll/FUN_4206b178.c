// Source: CLCSSmallBarcode.dll @ 4206b178; FUN_4206b178

int __cdecl
FUN_4206b178(char *param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_4 == 0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_4206db72();
    return -1;
  }
  if (param_3 == 0) {
    if (param_1 == (char *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_4206b1c3:
      if (param_2 != 0) {
        piVar2 = __errno();
        if (param_3 < param_2) {
          iVar1 = *piVar2;
          iVar3 = FUN_4206b2a4(FUN_42071fa2,param_1,param_3 + 1,param_4,param_5,param_6);
          if (iVar3 == -2) {
            piVar2 = __errno();
            if (*piVar2 != 0x22) {
              return -1;
            }
            piVar2 = __errno();
            *piVar2 = iVar1;
            return -1;
          }
LAB_4206b247:
          if (-1 < iVar3) {
            return iVar3;
          }
        }
        else {
          iVar1 = *piVar2;
          iVar3 = FUN_4206b2a4(FUN_42071fa2,param_1,param_2,param_4,param_5,param_6);
          (param_1 + param_2 * 2 + -2)[0] = '\0';
          (param_1 + param_2 * 2 + -2)[1] = '\0';
          if (iVar3 != -2) goto LAB_4206b247;
          if (param_3 == 0xffffffff) {
            piVar2 = __errno();
            if (*piVar2 != 0x22) {
              return -1;
            }
            piVar2 = __errno();
            *piVar2 = iVar1;
            return -1;
          }
        }
        param_1[0] = '\0';
        param_1[1] = '\0';
        if (iVar3 != -2) {
          return -1;
        }
        piVar2 = __errno();
        *piVar2 = 0x22;
        goto LAB_4206b26d;
      }
    }
  }
  else if (param_1 != (char *)0x0) goto LAB_4206b1c3;
  piVar2 = __errno();
  *piVar2 = 0x16;
LAB_4206b26d:
  FUN_4206db72();
  return -1;
}



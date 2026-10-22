// Source: CLCiffConversion_Data.dll @ 45016f68; FUN_45016f68

uint FUN_45016f68(int param_1,uint param_2,int *param_3,uint *param_4)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  if ((param_3 == (int *)0x0) || ((1 < param_2 && (param_4 == (uint *)0x0)))) {
    uVar4 = 0x80004003;
  }
  else if (((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) ||
          (*(int *)(param_1 + 0x10) == 0)) {
    uVar4 = 0x80004005;
  }
  else {
    uVar5 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10) >> 2;
    uVar4 = (uint)(uVar5 < param_2);
    if (param_2 < uVar5) {
      uVar5 = param_2;
    }
    piVar2 = param_3;
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar5;
    }
    while (uVar5 != 0) {
      uVar5 = uVar5 - 1;
      uVar3 = FUN_450189b5(piVar2,*(int **)(param_1 + 0x10));
      if ((int)uVar3 < 0) {
        for (; param_3 < piVar2; param_3 = param_3 + 1) {
          piVar1 = (int *)*param_3;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
        }
        if (param_4 == (uint *)0x0) {
          return uVar3;
        }
        *param_4 = 0;
        return uVar3;
      }
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 4;
      piVar2 = piVar2 + 1;
    }
  }
  return uVar4;
}



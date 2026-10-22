// Source: CLCiffConversion_Data.dll @ 45016bd6; FUN_45016bd6

undefined4 __thiscall FUN_45016bd6(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_45053874 = *param_3;
    DAT_45053878 = param_3[1];
    DAT_4505387c = param_3[2];
    DAT_45053880 = param_3[3];
  }
  piVar1 = DAT_450538b4;
  piVar2 = DAT_450538b0;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar1 = DAT_450538b4, piVar2 = DAT_450538b0,
     param_1 != (int *)0x0)) {
    for (; piVar1 = DAT_450538b4, piVar2 = DAT_450538b0, *param_1 != 0; param_1 = param_1 + 9) {
      (*(code *)param_1[8])(1);
    }
  }
  for (; piVar2 < piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x1c))(1);
      piVar1 = DAT_450538b4;
    }
  }
  return 0;
}



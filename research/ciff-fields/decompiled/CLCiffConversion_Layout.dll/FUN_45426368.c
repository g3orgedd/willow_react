// Source: CLCiffConversion_Layout.dll @ 45426368; FUN_45426368

undefined4 __thiscall FUN_45426368(void *this,int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  
  if (param_3 != (undefined4 *)0x0) {
    DAT_4545fbac = *param_3;
    DAT_4545fbb0 = param_3[1];
    DAT_4545fbb4 = param_3[2];
    DAT_4545fbb8 = param_3[3];
  }
  piVar1 = DAT_45460750;
  piVar2 = DAT_4546074c;
  if ((param_1 != (int *)0xffffffff) &&
     (*(int **)((int)this + 0x2c) = param_1, piVar1 = DAT_45460750, piVar2 = DAT_4546074c,
     param_1 != (int *)0x0)) {
    for (; piVar1 = DAT_45460750, piVar2 = DAT_4546074c, *param_1 != 0; param_1 = param_1 + 9) {
      (*(code *)param_1[8])(1);
    }
  }
  for (; piVar2 < piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      (**(code **)(*piVar2 + 0x1c))(1);
      piVar1 = DAT_45460750;
    }
  }
  return 0;
}



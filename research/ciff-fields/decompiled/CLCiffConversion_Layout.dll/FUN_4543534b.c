// Source: CLCiffConversion_Layout.dll @ 4543534b; FUN_4543534b

undefined4 __cdecl
FUN_4543534b(uint param_1,uint *param_2,undefined4 *param_3,undefined8 *param_4,undefined4 *param_5)

{
  uint uVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  uVar1 = *param_2;
  if (param_1 == uVar1) {
    if ((undefined8 *)*param_3 == param_4) {
      pvVar2 = FUN_454375c4(uVar1,4);
      *param_3 = pvVar2;
      if (pvVar2 != (LPVOID)0x0) {
        *param_5 = 1;
        FUN_45429920((undefined8 *)*param_3,param_4,*param_2 * 2);
LAB_454353a4:
        *param_2 = *param_2 << 1;
        goto LAB_454353a6;
      }
    }
    else {
      pvVar4 = FUN_4543769d((undefined8 *)*param_3,uVar1,4);
      if (pvVar4 != (void *)0x0) {
        *param_3 = pvVar4;
        goto LAB_454353a4;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_454353a6:
    uVar3 = 1;
  }
  return uVar3;
}



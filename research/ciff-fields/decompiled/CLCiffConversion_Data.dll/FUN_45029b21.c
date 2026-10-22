// Source: CLCiffConversion_Data.dll @ 45029b21; FUN_45029b21

undefined4 __cdecl
FUN_45029b21(uint param_1,uint *param_2,undefined4 *param_3,undefined8 *param_4,undefined4 *param_5)

{
  uint uVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  uVar1 = *param_2;
  if (param_1 == uVar1) {
    if ((undefined8 *)*param_3 == param_4) {
      pvVar2 = FUN_4502dee1(uVar1,4);
      *param_3 = pvVar2;
      if (pvVar2 != (LPVOID)0x0) {
        *param_5 = 1;
        FUN_45021540((undefined8 *)*param_3,param_4,*param_2 * 2);
LAB_45029b7a:
        *param_2 = *param_2 << 1;
        goto LAB_45029b7c;
      }
    }
    else {
      pvVar4 = FUN_4502dfba((undefined8 *)*param_3,uVar1,4);
      if (pvVar4 != (void *)0x0) {
        *param_3 = pvVar4;
        goto LAB_45029b7a;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_45029b7c:
    uVar3 = 1;
  }
  return uVar3;
}



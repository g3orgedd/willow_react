// Source: CLCiffConversion_Data.dll @ 4501c0b8; FUN_4501c0b8

undefined4 __thiscall FUN_4501c0b8(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  
  puVar1 = param_1;
  (**(code **)(*(int *)*param_1 + 0x28))((int *)*param_1,&param_1);
  bVar2 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0xe4),
                       L"Print Preview");
  if (((!bVar2) &&
      (bVar2 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0xe4),
                            L"JobSelection"), !bVar2)) &&
     (bVar2 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0xe4),
                           L"Capi"), !bVar2)) {
    return 0;
  }
  if (param_1 == (undefined4 *)0x0) {
    FUN_4501c157(this,puVar1);
  }
  else if (param_1 == (undefined4 *)0x4) {
    FUN_4501c292(this,puVar1);
  }
  else if (param_1 == (undefined4 *)0x7) {
    FUN_4501c4d7(this,puVar1);
  }
  return 0;
}



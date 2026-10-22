// Source: CLCiffConversion_Data.dll @ 450113ae; FUN_450113ae

void __thiscall FUN_450113ae(void *this,undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int *local_8;
  
  local_8 = this;
  CComQIPtr<>(&local_8,param_3);
  FUN_450022ba((void *)((int)this + 0xd0),(int *)&local_8);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  VariantClear((VARIANTARG *)&param_1);
  return;
}



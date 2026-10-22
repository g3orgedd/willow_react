// Source: CLCiffConversion_Data.dll @ 45014bce; FUN_45014bce

undefined4 __thiscall FUN_45014bce(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
  pvVar1 = FUN_4502391c(*(LPCVOID *)this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = FUN_4502391c(*(LPCVOID *)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_45016ca5(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



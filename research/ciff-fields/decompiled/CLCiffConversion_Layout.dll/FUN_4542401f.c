// Source: CLCiffConversion_Layout.dll @ 4542401f; FUN_4542401f

undefined4 __thiscall FUN_4542401f(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
  pvVar1 = FUN_4542ede8(*(LPCVOID *)this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = FUN_4542ede8(*(LPCVOID *)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_454263ef(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



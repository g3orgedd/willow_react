// Source: CiffMgr.dll @ 6810bf0b; FUN_6810bf0b

undefined4 __thiscall FUN_6810bf0b(void *this,undefined4 *param_1,undefined4 *param_2)

{
  void *pvVar1;
  
  pvVar1 = FUN_68134915(*(LPCVOID *)this,*(int *)((int)this + 8) + 1,4);
  if (pvVar1 != (void *)0x0) {
    *(void **)this = pvVar1;
    pvVar1 = FUN_68134915(*(LPCVOID *)((int)this + 4),*(int *)((int)this + 8) + 1,4);
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)this + 4) = pvVar1;
      FUN_6810d689(this,*(int *)((int)this + 8),param_1,param_2);
      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
      return 1;
    }
  }
  return 0;
}



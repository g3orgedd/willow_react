// Source: CiffMgr.dll @ 68102703; FUN_68102703

void __thiscall FUN_68102703(void *this,OLECHAR *param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
  FUN_68102644((void *)((int)this + 0x40),param_1);
  *(undefined4 *)((int)this + 0x8c) = param_2;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
  return;
}



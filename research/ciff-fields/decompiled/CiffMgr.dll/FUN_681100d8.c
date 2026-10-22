// Source: CiffMgr.dll @ 681100d8; FUN_681100d8

void __thiscall FUN_681100d8(void *this,OLECHAR *param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x2c));
  FUN_68102644((void *)((int)this + 0x28),param_1);
  FUN_68102644((void *)((int)this + 0x24),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x2c));
  return;
}



// Source: CiffMgr.dll @ 68115e2b; FUN_68115e2b

void __thiscall FUN_68115e2b(void *this,OLECHAR *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 200));
  FUN_68102644((void *)((int)this + 0x24),param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 200));
  return;
}



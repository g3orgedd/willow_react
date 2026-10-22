// Source: CiffMgr.dll @ 68113ff0; FUN_68113ff0

void __thiscall FUN_68113ff0(void *this,OLECHAR *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x2c));
  FUN_68102644((void *)((int)this + 0x24),param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x2c));
  return;
}



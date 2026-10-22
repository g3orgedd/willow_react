// Source: CiffMgr.dll @ 681136f8; FUN_681136f8

void __thiscall FUN_681136f8(void *this,OLECHAR *param_1,int param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
  FUN_68102644((void *)((int)this + 0x40),param_1);
  *(uint *)((int)this + 0xcc) = (uint)(param_2 == 1);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x10));
  return;
}



// Source: CiffMgr.dll @ 681048ee; FUN_681048ee

void __thiscall FUN_681048ee(void *this,int param_1,int param_2,int param_3,int param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x34));
  SetRect((LPRECT)((int)this + 0x24),param_1,param_2,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x34));
  return;
}



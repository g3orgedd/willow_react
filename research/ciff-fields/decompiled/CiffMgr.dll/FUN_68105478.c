// Source: CiffMgr.dll @ 68105478; FUN_68105478

void __thiscall
FUN_68105478(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0xf8));
  *(undefined4 *)((int)this + 0x44) = param_1;
  *(undefined4 *)((int)this + 0x30) = param_2;
  *(undefined4 *)((int)this + 0x34) = param_3;
  *(undefined4 *)((int)this + 0x38) = param_4;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0xf8));
  return;
}



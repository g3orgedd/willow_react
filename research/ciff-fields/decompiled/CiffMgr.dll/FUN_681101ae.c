// Source: CiffMgr.dll @ 681101ae; FUN_681101ae

void __thiscall
FUN_681101ae(void *this,undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x6c));
  *(undefined4 *)((int)this + 0x24) = param_1;
  *(undefined4 *)((int)this + 0x28) = param_2;
  *(undefined2 *)((int)this + 0x2c) = param_3;
  *(undefined4 *)((int)this + 0x5c) = param_4;
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x6c));
  return;
}



// Source: CiffMgr.dll @ 68111c19; FUN_68111c19

void __thiscall
FUN_68111c19(void *this,OLECHAR *param_1,OLECHAR *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,uint param_6)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x80));
  FUN_68102644((void *)((int)this + 0x40),param_1);
  FUN_68102644((void *)((int)this + 0x44),param_2);
  *(undefined4 *)((int)this + 0x54) = param_4;
  *(undefined4 *)((int)this + 0x30) = param_4;
  *(undefined4 *)((int)this + 0x50) = param_3;
  *(undefined4 *)((int)this + 0x34) = param_3;
  *(undefined4 *)((int)this + 0x58) = param_5;
  if (0 < (int)param_6) {
    FUN_681136ca((void *)((int)this + 4),param_6);
    FUN_6811228a((void *)((int)this + 0x98),param_6);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x80));
  return;
}



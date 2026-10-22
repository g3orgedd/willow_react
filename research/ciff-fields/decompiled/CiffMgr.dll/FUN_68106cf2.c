// Source: CiffMgr.dll @ 68106cf2; FUN_68106cf2

undefined4 FUN_68106cf2(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  FUN_68102644((void *)(param_1 + 0x58),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}



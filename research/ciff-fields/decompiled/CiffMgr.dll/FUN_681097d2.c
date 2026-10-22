// Source: CiffMgr.dll @ 681097d2; FUN_681097d2

undefined4 FUN_681097d2(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_68102644((void *)(param_1 + 0xc08),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  return 0;
}



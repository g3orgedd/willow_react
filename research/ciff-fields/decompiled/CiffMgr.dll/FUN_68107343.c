// Source: CiffMgr.dll @ 68107343; FUN_68107343

undefined4 FUN_68107343(int param_1,OLECHAR *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if (*(int *)(param_1 + 0x44) == 1) {
    FUN_68102644((void *)(param_1 + 0x7c),param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}



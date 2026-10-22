// Source: CiffMgr.dll @ 68107378; FUN_68107378

undefined4 FUN_68107378(int param_1,OLECHAR *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  if (*(int *)(param_1 + 0x44) == 2) {
    FUN_68102644((void *)(param_1 + 0x8c),param_2);
  }
  else {
    uVar1 = 0x80070005;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return uVar1;
}



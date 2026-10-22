// Source: CiffMgr.dll @ 68113e97; FUN_68113e97

undefined4 FUN_68113e97(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 - 1U < 100) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    *(int *)(param_1 + 0x94) = param_2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070057;
  }
  return uVar1;
}



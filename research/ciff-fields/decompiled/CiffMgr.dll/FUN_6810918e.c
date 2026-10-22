// Source: CiffMgr.dll @ 6810918e; FUN_6810918e

undefined4 FUN_6810918e(IUnknownVtbl *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  uVar1 = FUN_68118e92(&param_1[7].AddRef,param_1,param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  return uVar1;
}



// Source: CiffMgr.dll @ 6810acbf; FUN_6810acbf

void __fastcall FUN_6810acbf(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_681089f7((int *)(param_1 + 4));
  FUN_68103d54(param_1 + 0x10);
  return;
}



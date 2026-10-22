// Source: CiffMgr.dll @ 6811515a; FUN_6811515a

void __fastcall FUN_6811515a(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



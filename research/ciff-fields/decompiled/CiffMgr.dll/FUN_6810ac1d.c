// Source: CiffMgr.dll @ 6810ac1d; FUN_6810ac1d

void __fastcall FUN_6810ac1d(int param_1)

{
  int *piVar1;
  
  SysFreeString(*(BSTR *)(param_1 + 0xc24));
  SysFreeString(*(BSTR *)(param_1 + 0xc20));
  SysFreeString(*(BSTR *)(param_1 + 0xc1c));
  SysFreeString(*(BSTR *)(param_1 + 0xc0c));
  SysFreeString(*(BSTR *)(param_1 + 0xc08));
  SysFreeString(*(BSTR *)(param_1 + 0xc04));
  piVar1 = *(int **)(param_1 + 0xc00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_6810acf1((undefined4 *)(param_1 + 0x58));
  piVar1 = *(int **)(param_1 + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x50);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x4c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_681089f7((int *)(param_1 + 4));
  FUN_68103d54(param_1 + 0x10);
  return;
}



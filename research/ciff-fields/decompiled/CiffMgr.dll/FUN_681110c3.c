// Source: CiffMgr.dll @ 681110c3; FUN_681110c3

void __fastcall FUN_681110c3(int param_1)

{
  int *piVar1;
  
  SysFreeString(*(BSTR *)(param_1 + 0x68));
  SysFreeString(*(BSTR *)(param_1 + 0x4c));
  SysFreeString(*(BSTR *)(param_1 + 0x48));
  SysFreeString(*(BSTR *)(param_1 + 0x44));
  SysFreeString(*(BSTR *)(param_1 + 0x40));
  SysFreeString(*(BSTR *)(param_1 + 0x3c));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}



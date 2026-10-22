// Source: CiffMgr.dll @ 68117723; FUN_68117723

void __fastcall FUN_68117723(int param_1)

{
  int *piVar1;
  
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 200));
  SysFreeString(*(BSTR *)(param_1 + 0xc0));
  SysFreeString(*(BSTR *)(param_1 + 0xbc));
  SysFreeString(*(BSTR *)(param_1 + 0xb8));
  piVar1 = *(int **)(param_1 + 0xa4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0xa0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  SysFreeString(*(BSTR *)(param_1 + 0x7c));
  SysFreeString(*(BSTR *)(param_1 + 0x78));
  SysFreeString(*(BSTR *)(param_1 + 0x68));
  SysFreeString(*(BSTR *)(param_1 + 0x54));
  SysFreeString(*(BSTR *)(param_1 + 0x44));
  SysFreeString(*(BSTR *)(param_1 + 0x24));
  FUN_68103d54(param_1 + 4);
  return;
}



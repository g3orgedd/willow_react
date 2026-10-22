// Source: CiffMgr.dll @ 6810809e; FUN_6810809e

void __fastcall FUN_6810809e(int param_1)

{
  int *piVar1;
  
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  piVar1 = *(int **)(param_1 + 0xf4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  SysFreeString(*(BSTR *)(param_1 + 0xf0));
  SysFreeString(*(BSTR *)(param_1 + 0xec));
  SysFreeString(*(BSTR *)(param_1 + 0xe0));
  SysFreeString(*(BSTR *)(param_1 + 0xdc));
  SysFreeString(*(BSTR *)(param_1 + 0xd8));
  SysFreeString(*(BSTR *)(param_1 + 0xd4));
  SysFreeString(*(BSTR *)(param_1 + 0xb4));
  SysFreeString(*(BSTR *)(param_1 + 0xa8));
  SysFreeString(*(BSTR *)(param_1 + 0xa4));
  SysFreeString(*(BSTR *)(param_1 + 0xa0));
  SysFreeString(*(BSTR *)(param_1 + 0x90));
  SysFreeString(*(BSTR *)(param_1 + 0x8c));
  SysFreeString(*(BSTR *)(param_1 + 0x7c));
  FUN_68108a2b((int *)(param_1 + 0x74));
  FID_conflict__free(*(void **)(param_1 + 0x74));
  SysFreeString(*(BSTR *)(param_1 + 100));
  SysFreeString(*(BSTR *)(param_1 + 0x60));
  SysFreeString(*(BSTR *)(param_1 + 0x58));
  SysFreeString(*(BSTR *)(param_1 + 0x4c));
  FUN_681089f7((int *)(param_1 + 4));
  FUN_68103d54(param_1 + 0x10);
  return;
}



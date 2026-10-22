// Source: CiffMgr.dll @ 6810f462; FUN_6810f462

void __fastcall FUN_6810f462(int param_1)

{
  SysFreeString(*(BSTR *)(param_1 + 0x48));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_681089f7((int *)(param_1 + 4));
  FUN_68103d54(param_1 + 0x10);
  return;
}



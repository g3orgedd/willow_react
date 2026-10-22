// Source: CiffMgr.dll @ 68108163; FUN_68108163

void __fastcall FUN_68108163(int param_1)

{
  SysFreeString(*(BSTR *)(param_1 + 0x50));
  SysFreeString(*(BSTR *)(param_1 + 0x4c));
  SysFreeString(*(BSTR *)(param_1 + 0x48));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x30));
  FUN_681089f7((int *)(param_1 + 4));
  FUN_68103d54(param_1 + 0x10);
  return;
}



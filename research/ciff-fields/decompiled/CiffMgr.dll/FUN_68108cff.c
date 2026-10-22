// Source: CiffMgr.dll @ 68108cff; FUN_68108cff

void __fastcall FUN_68108cff(int param_1)

{
  FUN_68108cde((undefined4 *)(param_1 + 0x98));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x80));
  SysFreeString(*(BSTR *)(param_1 + 0x4c));
  SysFreeString(*(BSTR *)(param_1 + 0x48));
  SysFreeString(*(BSTR *)(param_1 + 0x44));
  SysFreeString(*(BSTR *)(param_1 + 0x40));
  FUN_681089f7((int *)(param_1 + 4));
  FUN_68103d54(param_1 + 0x10);
  return;
}



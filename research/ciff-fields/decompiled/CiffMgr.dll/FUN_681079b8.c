// Source: CiffMgr.dll @ 681079b8; FUN_681079b8

void __fastcall FUN_681079b8(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  SysFreeString(*(BSTR *)(param_1 + 0x24));
  FUN_68103d54(param_1 + 4);
  return;
}



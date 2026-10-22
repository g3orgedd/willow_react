// Source: CiffMgr.dll @ 6811419d; FUN_6811419d

void __fastcall FUN_6811419d(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  SysFreeString(*(BSTR *)(param_1 + 0x28));
  SysFreeString(*(BSTR *)(param_1 + 0x24));
  FUN_68103d54(param_1 + 4);
  return;
}



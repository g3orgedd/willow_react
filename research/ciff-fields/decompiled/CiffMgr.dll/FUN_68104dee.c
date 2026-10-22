// Source: CiffMgr.dll @ 68104dee; FUN_68104dee

void __fastcall FUN_68104dee(int param_1)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x6c));
  SysFreeString(*(BSTR *)(param_1 + 0x54));
  SysFreeString(*(BSTR *)(param_1 + 0x50));
  SysFreeString(*(BSTR *)(param_1 + 0x4c));
  SysFreeString(*(BSTR *)(param_1 + 0x44));
  SysFreeString(*(BSTR *)(param_1 + 0x40));
  SysFreeString(*(BSTR *)(param_1 + 0x3c));
  SysFreeString(*(BSTR *)(param_1 + 0x38));
  FUN_68103d54(param_1 + 4);
  return;
}



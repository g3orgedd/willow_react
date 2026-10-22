// Source: CiffMgr.dll @ 68114b4b; FUN_68114b4b

void __fastcall FUN_68114b4b(int param_1)

{
  SysFreeString(*(BSTR *)(param_1 + 0x30));
  SysFreeString(*(BSTR *)(param_1 + 0x2c));
  SysFreeString(*(BSTR *)(param_1 + 0x28));
  SysFreeString(*(BSTR *)(param_1 + 0x24));
  FUN_68103d54(param_1 + 4);
  return;
}



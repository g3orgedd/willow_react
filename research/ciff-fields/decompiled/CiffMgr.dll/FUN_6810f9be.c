// Source: CiffMgr.dll @ 6810f9be; FUN_6810f9be

void __fastcall FUN_6810f9be(int param_1)

{
  SysFreeString(*(BSTR *)(param_1 + 0x5c));
  VariantClear((VARIANTARG *)(param_1 + 0x48));
  SysFreeString(*(BSTR *)(param_1 + 0x3c));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  FUN_68103d54(param_1 + 4);
  return;
}



// Source: CiffMgr.dll @ 6810f1be; FUN_6810f1be

HRESULT FUN_6810f1be(int param_1,VARIANTARG *param_2)

{
  HRESULT HVar1;
  
  if (param_2 == (VARIANTARG *)0x0) {
    HVar1 = -0x7fffbffd;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
    HVar1 = VariantCopy(param_2,(VARIANTARG *)(param_1 + 0x48));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  }
  return HVar1;
}



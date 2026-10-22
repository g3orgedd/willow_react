// Source: CiffMgr.dll @ 6810f2a1; FUN_6810f2a1

undefined4 FUN_6810f2a1(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  VariantCopy((VARIANTARG *)(param_1 + 0x48),(VARIANTARG *)&stack0x00000008);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x24));
  return 0;
}



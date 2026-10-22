// Source: CiffMgr.dll @ 68105047; FUN_68105047

undefined4 FUN_68105047(int param_1)

{
  _union_2683 local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  local_14.n2.vt = 0;
  FUN_68104449(&local_14,(VARIANTARG *)&stack0x00000008);
  FUN_68106adf((void *)(param_1 + 4),(VARIANTARG *)&local_14.n2);
  VariantClear((VARIANTARG *)&local_14.n2);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));
  return 0;
}



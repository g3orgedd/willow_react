// Source: CiffMgr.dll @ 6810f09d; FUN_6810f09d

void __thiscall FUN_6810f09d(void *this,OLECHAR *param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  FUN_68102644((void *)((int)this + 0x3c),param_1);
  *(undefined4 *)((int)this + 0x40) = param_2;
  if ((VARIANTARG *)((int)this + 0x48) != (VARIANTARG *)&stack0x0000000c) {
    FUN_68104449((VARIANTARG *)((int)this + 0x48),(VARIANTARG *)&stack0x0000000c);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0x24));
  return;
}



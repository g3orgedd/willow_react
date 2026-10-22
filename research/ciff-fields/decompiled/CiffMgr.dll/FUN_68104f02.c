// Source: CiffMgr.dll @ 68104f02; FUN_68104f02

undefined4 * __thiscall FUN_68104f02(void *this,byte param_1)

{
  FUN_68104db4(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



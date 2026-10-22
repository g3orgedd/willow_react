// Source: CiffMgr.dll @ 68107a55; FUN_68107a55

undefined4 * __thiscall FUN_68107a55(void *this,byte param_1)

{
  FUN_68107979(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



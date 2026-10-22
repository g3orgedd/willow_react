// Source: CiffMgr.dll @ 6810ad4e; FUN_6810ad4e

undefined4 * __thiscall FUN_6810ad4e(void *this,byte param_1)

{
  FUN_6810aa9e(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



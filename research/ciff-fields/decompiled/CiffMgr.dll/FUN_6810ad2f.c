// Source: CiffMgr.dll @ 6810ad2f; FUN_6810ad2f

undefined4 * __thiscall FUN_6810ad2f(void *this,byte param_1)

{
  FUN_6810aa64(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



// Source: CiffMgr.dll @ 6810f4ea; FUN_6810f4ea

undefined4 * __thiscall FUN_6810f4ea(void *this,byte param_1)

{
  FUN_6810f428(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



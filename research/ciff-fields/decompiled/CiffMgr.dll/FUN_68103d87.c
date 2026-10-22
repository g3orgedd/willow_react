// Source: CiffMgr.dll @ 68103d87; FUN_68103d87

undefined4 * __thiscall FUN_68103d87(void *this,byte param_1)

{
  FUN_68103d1a(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



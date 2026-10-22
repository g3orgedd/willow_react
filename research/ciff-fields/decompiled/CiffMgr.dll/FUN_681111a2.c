// Source: CiffMgr.dll @ 681111a2; FUN_681111a2

undefined4 * __thiscall FUN_681111a2(void *this,byte param_1)

{
  FUN_68110f7e(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



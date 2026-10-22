// Source: CiffMgr.dll @ 681111ff; FUN_681111ff

undefined4 * __thiscall FUN_681111ff(void *this,byte param_1)

{
  FUN_68111033(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



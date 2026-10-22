// Source: CiffMgr.dll @ 68109c5a; FUN_68109c5a

undefined4 * __thiscall FUN_68109c5a(void *this,byte param_1)

{
  FUN_68109bbf(this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



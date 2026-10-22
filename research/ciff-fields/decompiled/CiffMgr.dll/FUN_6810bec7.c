// Source: CiffMgr.dll @ 6810bec7; FUN_6810bec7

undefined4 * __thiscall FUN_6810bec7(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComModule::vftable;
  FUN_6810ea45((int)this);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



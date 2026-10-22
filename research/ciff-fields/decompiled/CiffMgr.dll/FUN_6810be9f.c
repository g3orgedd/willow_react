// Source: CiffMgr.dll @ 6810be9f; FUN_6810be9f

undefined4 * __thiscall FUN_6810be9f(void *this,byte param_1)

{
  *(undefined ***)this = ATL::CComClassFactory::vftable;
  FUN_68103d54((int)this + 4);
  if ((param_1 & 1) != 0) {
    FID_conflict__free(this);
  }
  return this;
}



// Source: CiffMgr.dll @ 6810bc2c; FUN_6810bc2c

undefined4 * __thiscall FUN_6810bc2c(void *this,undefined4 param_1)

{
  FUN_68103c5f((undefined4 *)((int)this + 4));
  *(undefined4 *)((int)this + 4) = param_1;
  *(undefined ***)this = ATL::CComContainedObject<CCiffManager>::vftable;
  return this;
}



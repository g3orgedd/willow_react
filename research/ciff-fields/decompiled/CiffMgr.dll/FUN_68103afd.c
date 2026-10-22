// Source: CiffMgr.dll @ 68103afd; FUN_68103afd

IUnknown * __thiscall FUN_68103afd(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_681044c1(this,(int *)*param_1);
  if (bVar1) {
    pIVar2 = *(IUnknown **)this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign(this,(IUnknown *)*param_1,(_GUID *)&DAT_68147780);
  }
  return pIVar2;
}



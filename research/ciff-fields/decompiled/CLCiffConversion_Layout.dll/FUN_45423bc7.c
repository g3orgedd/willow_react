// Source: CLCiffConversion_Layout.dll @ 45423bc7; FUN_45423bc7

IUnknown * __thiscall FUN_45423bc7(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_45426468(this,(int *)*param_1);
  if (bVar1) {
    pIVar2 = *(IUnknown **)this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign(this,(IUnknown *)*param_1,(_GUID *)&DAT_4544ab3c);
  }
  return pIVar2;
}



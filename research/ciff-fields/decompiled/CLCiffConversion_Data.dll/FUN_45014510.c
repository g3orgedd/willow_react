// Source: CLCiffConversion_Data.dll @ 45014510; FUN_45014510

IUnknown * __thiscall FUN_45014510(void *this,undefined4 *param_1)

{
  bool bVar1;
  IUnknown *pIVar2;
  
  bVar1 = FUN_45016d1e(this,(int *)*param_1);
  if (bVar1) {
    pIVar2 = *(IUnknown **)this;
  }
  else {
    pIVar2 = ATL::AtlComQIPtrAssign(this,(IUnknown *)*param_1,(_GUID *)&DAT_4503fdcc);
  }
  return pIVar2;
}



// Source: CLCiffConversion_Layout.dll @ 45402f77; ATL::AtlComQIPtrAssign

/* Library Function - Single Match
    struct IUnknown * __stdcall ATL::AtlComQIPtrAssign(struct IUnknown * *,struct IUnknown *,struct
   _GUID const &)
   
   Library: Visual Studio 2012 Release */

IUnknown * ATL::AtlComQIPtrAssign(IUnknown **param_1,IUnknown *param_2,_GUID *param_3)

{
  IUnknown *This;
  HRESULT HVar1;
  
  if (param_1 != (IUnknown **)0x0) {
    This = *param_1;
    if ((param_2 == (IUnknown *)0x0) ||
       (HVar1 = (*param_2->lpVtbl->QueryInterface)(param_2,param_3,param_1), HVar1 < 0)) {
      *param_1 = (IUnknown *)0x0;
    }
    if (This != (IUnknown *)0x0) {
      (*This->lpVtbl->Release)(This);
    }
    return *param_1;
  }
  return (IUnknown *)0x0;
}



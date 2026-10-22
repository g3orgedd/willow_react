// Source: CLCiffConversion_Layout.dll @ 45402cfb; ATL::CComBSTR::operator==

/* Library Function - Single Match
    public: bool __thiscall ATL::CComBSTR::operator==(class ATL::CComBSTR const &)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

bool __thiscall ATL::CComBSTR::operator==(CComBSTR *this,CComBSTR *param_1)

{
  HRESULT HVar1;
  
  HVar1 = VarBstrCmp(*(BSTR *)this,*(BSTR *)param_1,0x400,0);
  return (bool)('\x01' - (HVar1 != 1));
}



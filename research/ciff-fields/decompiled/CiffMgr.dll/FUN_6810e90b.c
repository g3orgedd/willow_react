// Source: CiffMgr.dll @ 6810e90b; ATL::CRegKey::SetStringValue

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::SetStringValue(wchar_t const *,wchar_t const *,unsigned
   long)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall
ATL::CRegKey::SetStringValue(CRegKey *this,wchar_t *param_1,wchar_t *param_2,ulong param_3)

{
  size_t sVar1;
  long lVar2;
  
  if (param_2 == (wchar_t *)0x0) {
    lVar2 = 0xd;
  }
  else {
    sVar1 = _wcslen(param_2);
    lVar2 = RegSetValueExW(*(HKEY *)this,param_1,0,param_3,(BYTE *)param_2,sVar1 * 2 + 2);
  }
  return lVar2;
}



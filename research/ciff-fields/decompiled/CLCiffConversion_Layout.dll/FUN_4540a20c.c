// Source: CLCiffConversion_Layout.dll @ 4540a20c; ATL::CRegKey::SetStringValue

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::SetStringValue(char const *,char const *,unsigned long)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall
ATL::CRegKey::SetStringValue(CRegKey *this,char *param_1,char *param_2,ulong param_3)

{
  size_t sVar1;
  long lVar2;
  
  if (param_2 == (char *)0x0) {
    lVar2 = 0xd;
  }
  else {
    sVar1 = _strlen(param_2);
    lVar2 = RegSetValueExA(*(HKEY *)this,param_1,0,param_3,(BYTE *)param_2,sVar1 + 1);
  }
  return lVar2;
}



// Source: CLCiffConversion_Data.dll @ 450174f6; ATL::CRegKey::RecurseDeleteKey

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::RecurseDeleteKey(wchar_t const *)
   
   Library: Visual Studio 2015 Release */

long __thiscall ATL::CRegKey::RecurseDeleteKey(CRegKey *this,wchar_t *param_1)

{
  int iVar1;
  LSTATUS LVar2;
  long lVar3;
  _FILETIME local_220;
  HKEY local_218;
  undefined4 local_214;
  undefined4 local_210;
  DWORD local_20c;
  wchar_t local_208 [256];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_218 = (HKEY)0x0;
  local_214 = 0;
  local_210 = 0;
  iVar1 = Open(&local_218,*(HKEY *)this,param_1,*(uint *)(this + 4) | 0x2001f);
  do {
    if (iVar1 != 0) {
LAB_4501759a:
      Close((CRegKey *)&local_218);
      lVar3 = FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
      return lVar3;
    }
    local_20c = 0x100;
    LVar2 = RegEnumKeyExW(local_218,0,local_208,&local_20c,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                          &local_220);
    if (LVar2 != 0) {
      Close((CRegKey *)&local_218);
      DeleteSubKey(this,param_1);
      goto LAB_4501759a;
    }
    iVar1 = RecurseDeleteKey((CRegKey *)&local_218,local_208);
  } while( true );
}



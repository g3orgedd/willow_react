// Source: CLCiffConversion_Layout.dll @ 4540a093; ATL::CRegKey::RecurseDeleteKey

/* Library Function - Single Match
    public: long __thiscall ATL::CRegKey::RecurseDeleteKey(char const *)
   
   Library: Visual Studio 2015 Release */

long __thiscall ATL::CRegKey::RecurseDeleteKey(CRegKey *this,char *param_1)

{
  int iVar1;
  LSTATUS LVar2;
  long lVar3;
  _FILETIME local_120;
  HKEY local_118;
  undefined4 local_114;
  undefined4 local_110;
  DWORD local_10c;
  char local_108 [256];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_118 = (HKEY)0x0;
  local_114 = 0;
  local_110 = 0;
  iVar1 = Open(&local_118,*(HKEY *)this,param_1,*(uint *)(this + 4) | 0x2001f);
  do {
    if (iVar1 != 0) {
LAB_4540a137:
      Close((CRegKey *)&local_118);
      lVar3 = FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
      return lVar3;
    }
    local_10c = 0x100;
    LVar2 = RegEnumKeyExA(local_118,0,local_108,&local_10c,(LPDWORD)0x0,(LPSTR)0x0,(LPDWORD)0x0,
                          &local_120);
    if (LVar2 != 0) {
      Close((CRegKey *)&local_118);
      DeleteSubKey(this,param_1);
      goto LAB_4540a137;
    }
    iVar1 = RecurseDeleteKey((CRegKey *)&local_118,local_108);
  } while( true );
}



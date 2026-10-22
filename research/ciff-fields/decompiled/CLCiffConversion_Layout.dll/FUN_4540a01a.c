// Source: CLCiffConversion_Layout.dll @ 4540a01a; DeleteSubKey

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2012 Release */

void __thiscall DeleteSubKey(void *this,LPCSTR param_1)

{
  HMODULE hModule;
  
  if (*(void **)((int)this + 8) == (void *)0x0) {
    if (DAT_45460780 == '\0') {
      hModule = GetModuleHandleA("Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_4546077c = GetProcAddress(hModule,"RegDeleteKeyExA");
      }
      DAT_45460780 = '\x01';
    }
    if (DAT_4546077c == (FARPROC)0x0) {
      RegDeleteKeyA(*(HKEY *)this,param_1);
    }
    else {
      (*DAT_4546077c)(*(undefined4 *)this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
    FUN_4540a1ba(*(void **)((int)this + 8),*(HKEY *)this,param_1);
  }
  return;
}



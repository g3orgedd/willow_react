// Source: CLCiffConversion_Data.dll @ 45016315; DeleteSubKey

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2012 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(void **)((int)this + 8) == (void *)0x0) {
    if (DAT_45053940 == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_4505393c = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_45053940 = '\x01';
    }
    if (DAT_4505393c == (FARPROC)0x0) {
      RegDeleteKeyW(*(HKEY *)this,param_1);
    }
    else {
      (*DAT_4505393c)(*(undefined4 *)this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
    FUN_45017619(*(void **)((int)this + 8),*(HKEY *)this,param_1);
  }
  return;
}



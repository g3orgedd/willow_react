// Source: CiffMgr.dll @ 6810d312; DeleteSubKey

/* Library Function - Multiple Matches With Same Base Name
    public: long __thiscall ATL::CRegKey::DeleteSubKey(char const *)
    public: long __thiscall ATL::CRegKey::DeleteSubKey(wchar_t const *)
   
   Library: Visual Studio 2012 Release */

void __thiscall DeleteSubKey(void *this,LPCWSTR param_1)

{
  HMODULE hModule;
  
  if (*(void **)((int)this + 8) == (void *)0x0) {
    if (DAT_681670ac == '\0') {
      hModule = GetModuleHandleW(L"Advapi32.dll");
      if (hModule != (HMODULE)0x0) {
        DAT_681670a8 = GetProcAddress(hModule,"RegDeleteKeyExW");
      }
      DAT_681670ac = '\x01';
    }
    if (DAT_681670a8 == (FARPROC)0x0) {
      RegDeleteKeyW(*(HKEY *)this,param_1);
    }
    else {
      (*DAT_681670a8)(*(undefined4 *)this,param_1,*(undefined4 *)((int)this + 4),0);
    }
  }
  else {
    FUN_6810dcf1(*(void **)((int)this + 8),*(HKEY *)this,param_1);
  }
  return;
}



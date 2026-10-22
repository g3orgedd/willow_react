// Source: CiffMgr.dll @ 68102520; FUN_68102520

void __cdecl FUN_68102520(LPVOID *param_1)

{
  HRESULT HVar1;
  UINT UVar2;
  HMODULE hModule;
  FARPROC pFVar3;
  int iVar4;
  int iVar5;
  wchar_t local_414 [256];
  WCHAR local_214 [262];
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  HVar1 = CoCreateInstance((IID *)&DAT_681474c0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_681476c8,param_1);
  if (((HVar1 < 0) || (*param_1 == (LPVOID)0x0)) &&
     (UVar2 = GetSystemDirectoryW(local_214,0x105), UVar2 != 0)) {
    _wcscat_s(local_214,0x105,L"\\MSXML3.DLL");
    iVar5 = 0;
    hModule = LoadLibraryW(local_214);
    if (hModule == (HMODULE)0x0) {
      iVar5 = 1;
    }
    else {
      pFVar3 = GetProcAddress(hModule,"DllRegisterServer");
      if (pFVar3 == (FARPROC)0x0) {
        iVar5 = 2;
      }
      else {
        iVar4 = (*pFVar3)();
        if (iVar4 < 0) {
          iVar5 = 3;
        }
      }
    }
    FreeLibrary(hModule);
    if (iVar5 == 0) {
      CoCreateInstance((IID *)&DAT_681474c0,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_681476c8,param_1);
    }
    else {
      _swprintf_s(local_414,0x100,
                  L"%s has not been installed correctly. (failed to create MSXML.dll [%d])\n %s can still run but parameter names and values will be displayed incorrectly.\nInstalling Internet Explorer 5.0 or later will solve this problem."
                  ,DAT_68167038,iVar5,DAT_68167038);
      MessageBoxW((HWND)0x0,local_414,DAT_68167038,0);
    }
  }
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



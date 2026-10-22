// Source: CLCiffConversion_Layout.dll @ 4543a81e; FUN_4543a81e

LPSTR FUN_4543a81e(void)

{
  WCHAR WVar1;
  LPWCH lpWideCharStr;
  LPSTR lpMultiByteStr;
  size_t cbMultiByte;
  WCHAR *pWVar2;
  int iVar4;
  WCHAR *pWVar3;
  
  lpWideCharStr = GetEnvironmentStringsW();
  lpMultiByteStr = (LPSTR)0x0;
  if (lpWideCharStr != (LPWCH)0x0) {
    WVar1 = *lpWideCharStr;
    pWVar2 = lpWideCharStr;
    while (WVar1 != L'\0') {
      do {
        pWVar3 = pWVar2;
        pWVar2 = pWVar3 + 1;
      } while (*pWVar2 != L'\0');
      pWVar2 = pWVar3 + 2;
      WVar1 = *pWVar2;
    }
    iVar4 = ((int)pWVar2 - (int)lpWideCharStr >> 1) + 1;
    cbMultiByte = WideCharToMultiByte(0,0,lpWideCharStr,iVar4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if ((cbMultiByte == 0) ||
       (lpMultiByteStr = FUN_4543760c(cbMultiByte), lpMultiByteStr == (LPSTR)0x0)) {
      FreeEnvironmentStringsW(lpWideCharStr);
      lpMultiByteStr = (LPSTR)0x0;
    }
    else {
      iVar4 = WideCharToMultiByte(0,0,lpWideCharStr,iVar4,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      if (iVar4 == 0) {
        FID_conflict__free(lpMultiByteStr);
        lpMultiByteStr = (LPSTR)0x0;
      }
      FreeEnvironmentStringsW(lpWideCharStr);
    }
  }
  return lpMultiByteStr;
}



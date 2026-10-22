// Source: CLCiffConversion_Layout.dll @ 4543247e; FUN_4543247e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_4543247e(int param_1)

{
  wchar_t *_Src;
  int iVar1;
  errno_t eVar2;
  DWORD DVar3;
  size_t sVar4;
  HANDLE hFile;
  uint uVar5;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  DWORD local_200;
  char local_1fc [500];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  _Src = __GET_RTERRMSG(param_1);
  if (_Src != (wchar_t *)0x0) {
    iVar1 = __set_error_mode(3);
    if ((iVar1 == 1) || ((iVar1 = __set_error_mode(3), iVar1 == 0 && (DAT_45460bd8 == 1)))) {
      hFile = GetStdHandle(0xfffffff4);
      if ((hFile != (HANDLE)0x0) && (hFile != (HANDLE)0xffffffff)) {
        uVar5 = 0;
        do {
          local_1fc[uVar5] = (char)_Src[uVar5];
          if (_Src[uVar5] == L'\0') break;
          uVar5 = uVar5 + 1;
        } while (uVar5 < 500);
        lpOverlapped = (LPOVERLAPPED)0x0;
        lpNumberOfBytesWritten = &local_200;
        local_1fc[499] = 0;
        sVar4 = _strlen(local_1fc);
        WriteFile(hFile,local_1fc,sVar4,lpNumberOfBytesWritten,lpOverlapped);
      }
    }
    else if (param_1 != 0xfc) {
      eVar2 = _wcscpy_s((wchar_t *)&DAT_45460be0,0x314,L"Runtime Error!\n\nProgram: ");
      if (eVar2 == 0) {
        _DAT_45460e1a = 0;
        DVar3 = GetModuleFileNameW((HMODULE)0x0,(LPWSTR)&DAT_45460c12,0x104);
        if ((DVar3 != 0) ||
           (eVar2 = _wcscpy_s((wchar_t *)&DAT_45460c12,0x2fb,L"<program name unknown>"), eVar2 == 0)
           ) {
          sVar4 = _wcslen((wchar_t *)&DAT_45460c12);
          if (0x3c < sVar4 + 1) {
            sVar4 = _wcslen((wchar_t *)&DAT_45460c12);
            iVar1 = FUN_4542df68((short *)((int)&DAT_45460b9c + sVar4 * 2),
                                 0x2fb - ((int)(sVar4 * 2 + -0x76) >> 1),(short *)&DAT_4544cc2c,3);
            if (iVar1 != 0) goto LAB_45432630;
          }
          eVar2 = _wcscat_s((wchar_t *)&DAT_45460be0,0x314,L"\n\n");
          if ((eVar2 == 0) && (eVar2 = _wcscat_s((wchar_t *)&DAT_45460be0,0x314,_Src), eVar2 == 0))
          {
            FUN_4543b85b((LPCWSTR)&DAT_45460be0,L"Microsoft Visual C++ Runtime Library",0x12010);
            goto LAB_45432620;
          }
        }
      }
LAB_45432630:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
LAB_45432620:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



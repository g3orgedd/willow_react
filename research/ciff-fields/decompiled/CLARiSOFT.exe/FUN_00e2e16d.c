// Source: CLARiSOFT.exe @ 00e2e16d; FUN_00e2e16d

undefined4 __fastcall FUN_00e2e16d(int param_1)

{
  LPWSTR lpBuffer;
  int iVar1;
  wchar_t *_Dst;
  uint uVar2;
  uint uVar3;
  wchar_t *_Format;
  
  lpBuffer = (LPWSTR)(param_1 + 0xc);
  if (*(int *)lpBuffer == 0) {
    FormatMessageW(0x1300,(LPCVOID)0x0,*(DWORD *)(param_1 + 4),0x400,lpBuffer,0,(va_list *)0x0);
    if (*(int *)lpBuffer == 0) {
      _Dst = LocalAlloc(0,0x40);
      *(wchar_t **)lpBuffer = _Dst;
      if (_Dst != (wchar_t *)0x0) {
        uVar2 = FUN_00e30037(*(int *)(param_1 + 4));
        uVar3 = uVar2 & 0xffff;
        if ((short)uVar2 == 0) {
          uVar3 = *(uint *)(param_1 + 4);
          _Format = L"Unknown error 0x%0lX";
        }
        else {
          _Format = L"IDispatch error #%d";
        }
        _swprintf_s(_Dst,0x20,_Format,uVar3);
      }
    }
    else {
      iVar1 = lstrlenW(*(LPCWSTR *)lpBuffer);
      if ((1 < iVar1) && (*(short *)(*(int *)lpBuffer + -2 + iVar1 * 2) == 10)) {
        *(undefined2 *)(*(int *)lpBuffer + -2 + iVar1 * 2) = 0;
        if (*(short *)(*(int *)lpBuffer + -4 + iVar1 * 2) == 0xd) {
          *(undefined2 *)(*(int *)lpBuffer + -4 + iVar1 * 2) = 0;
        }
      }
    }
  }
  return *(undefined4 *)lpBuffer;
}



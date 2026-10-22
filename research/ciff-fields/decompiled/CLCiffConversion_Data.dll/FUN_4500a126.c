// Source: CLCiffConversion_Data.dll @ 4500a126; FUN_4500a126

void __thiscall FUN_4500a126(void *this,wchar_t *param_1,UINT param_2)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  DWORD DVar4;
  uint cbMultiByte;
  bool bVar5;
  
  if (param_1 == (wchar_t *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    sVar1 = _wcslen(param_1);
    iVar2 = sVar1 + 1;
    FUN_45009b90(this,iVar2 * 4,(int)this + 4,0x80);
    iVar3 = WideCharToMultiByte(param_2,0,param_1,iVar2,*(LPSTR *)this,iVar2 * 4,(LPCSTR)0x0,
                                (LPBOOL)0x0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      bVar5 = true;
      if (DVar4 == 0x7a) {
        cbMultiByte = WideCharToMultiByte(param_2,0,param_1,iVar2,(LPSTR)0x0,0,(LPCSTR)0x0,
                                          (LPBOOL)0x0);
        FUN_45009b90(this,cbMultiByte,(int)this + 4,0x80);
        iVar2 = WideCharToMultiByte(param_2,0,param_1,iVar2,*(LPSTR *)this,cbMultiByte,(LPCSTR)0x0,
                                    (LPBOOL)0x0);
        bVar5 = iVar2 == 0;
      }
      if (bVar5) {
                    /* WARNING: Subroutine does not return */
        FUN_45009d7f();
      }
    }
  }
  return;
}



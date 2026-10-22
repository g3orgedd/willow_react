// Source: CLCiffConversion_Layout.dll @ 454295e0; FUN_454295e0

LPSTR FUN_454295e0(LPCWSTR param_1)

{
  WCHAR WVar1;
  size_t cbMultiByte;
  DWORD DVar2;
  LPSTR lpMultiByteStr;
  int iVar3;
  LPCWSTR pWVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_45446470;
  local_10 = ExceptionList;
  if (param_1 == (LPCWSTR)0x0) {
    return (LPSTR)0x0;
  }
  pWVar4 = param_1;
  do {
    WVar1 = *pWVar4;
    pWVar4 = pWVar4 + 1;
  } while (WVar1 != L'\0');
  iVar3 = ((int)pWVar4 - (int)(param_1 + 1) >> 1) + 1;
  ExceptionList = &local_10;
  cbMultiByte = WideCharToMultiByte(0,0,param_1,iVar3,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  if (cbMultiByte == 0) {
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
                    /* WARNING: Subroutine does not return */
    _com_issue_error(DVar2);
  }
  local_8 = 0;
  lpMultiByteStr = (LPSTR)FUN_454298b4(cbMultiByte);
  local_8 = 0xffffffff;
  if (lpMultiByteStr == (LPSTR)0x0) {
                    /* WARNING: Subroutine does not return */
    _com_issue_error(-0x7ff8fff2);
  }
  iVar3 = WideCharToMultiByte(0,0,param_1,iVar3,lpMultiByteStr,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
  if (iVar3 == 0) {
    FID_conflict__free(lpMultiByteStr);
    DVar2 = GetLastError();
    if (0 < (int)DVar2) {
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
                    /* WARNING: Subroutine does not return */
    _com_issue_error(DVar2);
  }
  ExceptionList = local_10;
  return lpMultiByteStr;
}



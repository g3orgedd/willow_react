// Source: CLCiffConversion_Layout.dll @ 45429700; ConvertStringToBSTR

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Multiple Matches With Same Base Name
    unsigned short * __stdcall _com_util::ConvertStringToBSTR(char const *)
    wchar_t * __stdcall _com_util::ConvertStringToBSTR(char const *)
   
   Library: Visual Studio 2012 Release */

void ConvertStringToBSTR(LPCSTR param_1)

{
  uint uVar1;
  int iVar2;
  int cchWideChar;
  DWORD DVar3;
  OLECHAR *lpWideCharStr;
  BSTR pOVar4;
  uint local_3c;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  pcStack_10 = FUN_4542ea40;
  local_14 = ExceptionList;
  local_c = DAT_4545d9f0 ^ 0x4545abf8;
  uVar1 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_14;
  local_3c = uVar1;
  if (param_1 != (LPCSTR)0x0) {
    iVar2 = lstrlenA(param_1);
    cchWideChar = MultiByteToWideChar(0,0,param_1,iVar2 + 1,(LPWSTR)0x0,0);
    if (cchWideChar == 0) {
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      _com_issue_error(DVar3);
    }
    local_8 = 0;
    if (cchWideChar < 0x1000) {
      lpWideCharStr = (OLECHAR *)&local_3c;
    }
    else {
      lpWideCharStr = _malloc(cchWideChar * 2);
    }
    local_8 = 0xfffffffe;
    if (lpWideCharStr == (OLECHAR *)0x0) {
                    /* WARNING: Subroutine does not return */
      _com_issue_error(-0x7ff8fff2);
    }
    iVar2 = MultiByteToWideChar(0,0,param_1,iVar2 + 1,lpWideCharStr,cchWideChar);
    if (iVar2 == 0) {
      if (0xfff < cchWideChar) {
        FID_conflict__free(lpWideCharStr);
      }
      DVar3 = GetLastError();
      if (0 < (int)DVar3) {
        DVar3 = DVar3 & 0xffff | 0x80070000;
      }
                    /* WARNING: Subroutine does not return */
      _com_issue_error(DVar3);
    }
    pOVar4 = SysAllocString(lpWideCharStr);
    if (0xfff < cchWideChar) {
      FID_conflict__free(lpWideCharStr);
    }
    if (pOVar4 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
      _com_issue_error(-0x7ff8fff2);
    }
  }
  ExceptionList = local_14;
  FUN_4542a8d1(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}



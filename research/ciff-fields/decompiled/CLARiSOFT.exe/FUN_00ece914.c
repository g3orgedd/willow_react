// Source: CLARiSOFT.exe @ 00ece914; FUN_00ece914

HANDLE __cdecl
FUN_00ece914(LPSECURITY_ATTRIBUTES param_1,SIZE_T param_2,DWORD param_3,undefined4 param_4,
            DWORD param_5,LPDWORD param_6)

{
  DWORD DVar1;
  int *piVar2;
  LPVOID lpParameter;
  _ptiddata p_Var3;
  LPDWORD lpThreadId;
  HANDLE pvVar4;
  DWORD DVar5;
  
  DVar1 = param_3;
  DVar5 = 0;
  if (param_3 == 0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_00ed2f39();
  }
  else {
    lpParameter = FUN_00ed19e8(1,0x3bc);
    if (lpParameter != (LPVOID)0x0) {
      p_Var3 = __getptd();
      FUN_00ed4bd6((int)lpParameter,(int)p_Var3->ptlocinfo);
      *(undefined4 *)((int)lpParameter + 4) = 0xffffffff;
      *(undefined4 *)((int)lpParameter + 0x58) = param_4;
      *(DWORD *)((int)lpParameter + 0x54) = DVar1;
      lpThreadId = param_6;
      if (param_6 == (LPDWORD)0x0) {
        lpThreadId = &param_3;
      }
      pvVar4 = CreateThread(param_1,param_2,__threadstartex_4,lpParameter,param_5,lpThreadId);
      if (pvVar4 != (HANDLE)0x0) {
        return pvVar4;
      }
      DVar5 = GetLastError();
    }
    FID_conflict__free(lpParameter);
    if (DVar5 != 0) {
      FID_conflict___dosmaperr(DVar5);
    }
  }
  return (HANDLE)0x0;
}



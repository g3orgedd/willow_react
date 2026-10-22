// Source: CLARiSOFT.exe @ 00e2d2d6; FUN_00e2d2d6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

undefined4 __fastcall FUN_00e2d2d6(int param_1)

{
  LSTATUS LVar1;
  HWND pHVar2;
  LPARAM LVar3;
  undefined **local_5c;
  undefined4 local_58;
  void *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  DWORD local_30;
  DWORD local_2c;
  int local_28;
  int local_24;
  int local_20;
  HKEY local_1c;
  HKEY local_18;
  char local_11 [9];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0xe2d2e2;
  if (*(int *)(param_1 + 0x160) != 0) {
    local_24 = 0;
    local_20 = 0;
    (**(code **)(**(int **)(param_1 + 0x160) + 0x22c))(*(int **)(param_1 + 0x160),&local_20);
    (**(code **)(**(int **)(param_1 + 0x160) + 0x234))(*(int **)(param_1 + 0x160),&local_24);
    if ((local_20 != 0) && (local_24 != 0)) {
      local_18 = (HKEY)0x0;
      local_28 = 0;
      LVar1 = RegOpenKeyExW((HKEY)0x80000001,
                            L"Software\\Claricom Ltd\\CLARiSOFT\\DisableTemplateWarning",0,0xf003f,
                            &local_18);
      if (LVar1 == 0) {
        local_2c = 0;
        local_1c = (HKEY)0x4;
        RegQueryValueExW(local_18,(LPCWSTR)0x0,(LPDWORD)0x0,&local_2c,(LPBYTE)&local_28,
                         (LPDWORD)&local_1c);
        RegCloseKey(local_18);
      }
      local_58 = 0;
      local_48 = (void *)0x0;
      local_44 = 0;
      local_40 = 0;
      local_5c = CCoderWarnDLG::vftable;
      local_3c = 0;
      local_38 = 0;
      local_11[0] = local_28 != 0;
      local_8 = 0;
      if (!(bool)local_11[0]) {
        FUN_00e46d09(&local_5c,local_11);
        LVar3 = 0;
        pHVar2 = GetActiveWindow();
        FUN_00e2d483(&local_5c,pHVar2,LVar3);
        if (local_11[0] == '\x01') {
          local_1c = (HKEY)0x0;
          local_2c = 1;
          LVar1 = RegCreateKeyExW((HKEY)0x80000001,
                                  L"Software\\Claricom Ltd\\CLARiSOFT\\DisableTemplateWarning",0,
                                  (LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,&local_1c,
                                  &local_30);
          if (LVar1 == 0) {
            RegSetValueExW(local_1c,(LPCWSTR)0x0,0,4,(BYTE *)&local_2c,4);
            RegCloseKey(local_1c);
          }
        }
      }
      local_8 = 0xffffffff;
      local_5c = CCoderWarnDLG::vftable;
      if (local_48 != (void *)0x0) {
        ATL::__FreeStdCallThunk(local_48);
      }
    }
  }
  return 0;
}



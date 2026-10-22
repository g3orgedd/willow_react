// Source: CLARiSOFT.exe @ 00e98d5f; FUN_00e98d5f

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_00e98d5f(int param_1)

{
  int local_5c;
  int local_58;
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  int *local_4c;
  LPCWSTR local_48;
  wchar_t local_44 [12];
  wchar_t local_2c [18];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0xe98d6b;
  KillTimer(*(HWND *)(param_1 + 4),0);
  if ((*(int *)(param_1 + 0x9c) != 0) &&
     ((**(code **)(**(int **)(param_1 + 0x9c) + 0x1c))(*(int **)(param_1 + 0x9c)), 0 < (int)local_48
     )) {
    (**(code **)(**(int **)(param_1 + 0x9c) + 0x20))();
  }
  CComQIPtr<>(&local_4c,*(undefined4 **)(param_1 + 0x98));
  local_8 = 0;
  if (local_4c != (int *)0x0) {
    (**(code **)(*local_4c + 0x70))(local_4c,local_50,local_54,&local_58,&local_5c);
    local_48 = (LPCWSTR)((float)local_5c / DAT_00efe908);
    _swprintf_s(local_2c,0xc,L"%0.2f",(double)((float)local_58 / DAT_00efe908));
    _swprintf_s(local_44,0xc,L"%0.2f",(double)(float)local_48);
    local_48 = (LPCWSTR)PTR_DAT_00f35014;
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00e052f9(&local_48,L"Image Size %smm x %smm\n\n%ld %% Black (%ld Pixels)");
    SetWindowTextW(*(HWND *)(param_1 + 200),local_48);
    FUN_00e01f81((int *)&local_48);
  }
  local_8 = 0xffffffff;
  if (local_4c != (int *)0x0) {
    (**(code **)(*local_4c + 8))();
  }
  FUN_00ec9e3c();
  return;
}



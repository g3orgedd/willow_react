// Source: CLARiSOFT.exe @ 00e3e098; FUN_00e3e098

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_00e3e098(int param_1)

{
  int *piVar1;
  int local_1c;
  LPCWSTR local_18;
  LPCWSTR local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_18 = (LPCWSTR)PTR_DAT_00f35014;
  local_14[0] = (LPCWSTR)PTR_DAT_00f35014;
  local_8 = 1;
  uStack_7 = 0;
  piVar1 = FUN_00eb9380(&local_1c,0x6003);
  local_8 = 2;
  FUN_00e06f61(&local_18,piVar1);
  local_8 = 1;
  FUN_00e01f81(&local_1c);
  piVar1 = FUN_00eb9380(&local_1c,0x619e);
  _local_8 = CONCAT31(uStack_7,3);
  FUN_00e06f61(local_14,piVar1);
  FUN_00e01f81(&local_1c);
  MessageBoxW(*(HWND *)(param_1 + 4),local_18,local_14[0],0x30);
  FUN_00e01f81((int *)local_14);
  FUN_00e01f81((int *)&local_18);
  return;
}



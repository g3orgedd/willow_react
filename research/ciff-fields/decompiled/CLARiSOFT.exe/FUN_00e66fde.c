// Source: CLARiSOFT.exe @ 00e66fde; FUN_00e66fde

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __fastcall FUN_00e66fde(int param_1)

{
  bool bVar1;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  if (*(int *)(param_1 + 0x1c) == 0) {
    bVar1 = false;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x44))(*(int **)(param_1 + 0x1c),local_14);
    bVar1 = FUN_00e03edc(local_14,L"Line");
  }
  SysFreeString(local_14[0]);
  return bVar1;
}



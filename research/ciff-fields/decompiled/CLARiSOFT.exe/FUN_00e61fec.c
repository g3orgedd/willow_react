// Source: CLARiSOFT.exe @ 00e61fec; FUN_00e61fec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __fastcall FUN_00e61fec(int param_1)

{
  uint uVar1;
  undefined4 extraout_EAX;
  uint extraout_EAX_00;
  int local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0xe61ff8;
  uVar1 = (**(code **)(**(int **)(param_1 + 4) + 100))(*(int **)(param_1 + 4),&local_18);
  if ((-1 < (int)uVar1) && (local_18 == 1)) {
    local_14[0] = (BSTR)0x0;
    local_8 = 0;
    (**(code **)(**(int **)(param_1 + 4) + 0x98))(*(int **)(param_1 + 4),local_14);
    if (*local_14[0] == L'+') {
      SysFreeString(local_14[0]);
      return CONCAT31((int3)((uint)extraout_EAX >> 8),1);
    }
    SysFreeString(local_14[0]);
    uVar1 = extraout_EAX_00;
  }
  return uVar1 & 0xffffff00;
}



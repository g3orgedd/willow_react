// Source: CLARiSOFT.exe @ 00e496ca; FUN_00e496ca

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_00e496ca(HANDLE param_1,undefined4 *param_2,DWORD param_3)

{
  bool bVar1;
  DWORD local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0xe496d6;
  local_18[0] = 0;
  GetPrinterW(param_1,param_3,(LPBYTE)0x0,0,local_18);
  if (local_18[0] != 0) {
    local_8 = 0;
    FUN_00ec8db7(local_18[0]);
    bVar1 = FUN_00e49712();
    return bVar1;
  }
  *param_2 = 0;
  return false;
}



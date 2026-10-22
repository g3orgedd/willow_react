// Source: CLCiffConversion_Data.dll @ 450033e4; FUN_450033e4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_450033e4(void)

{
  LPCWSTR lpFileName;
  LPCWSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (LPCWSTR)PTR_DAT_4505101c;
  local_8 = 0;
  FUN_450037ea(local_14,L"%d");
  lpFileName = FUN_4501ca38();
  WritePrivateProfileStringW(L"Generic",L"Start of Day Enabled",local_14[0],lpFileName);
  FUN_45002256((int *)local_14);
  return;
}



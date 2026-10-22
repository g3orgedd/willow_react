// Source: CLARiSOFT.exe @ 00e28cb6; FUN_00e28cb6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * FUN_00e28cb6(undefined4 *param_1,undefined4 *param_2,LPCWSTR param_3)

{
  int iVar1;
  
  iVar1 = 0;
  *param_1 = PTR_DAT_00f35014;
  if (param_3 != (LPCWSTR)0x0) {
    iVar1 = lstrlenW(param_3);
  }
  FUN_00e04e44(param_1,*(int *)((int)*param_2 + -8),(void *)*param_2,iVar1,param_3);
  return param_1;
}



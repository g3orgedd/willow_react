// Source: CLCiffConversion_Layout.dll @ 45413224; FUN_45413224

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * FUN_45413224(undefined4 *param_1,undefined4 *param_2,LPCSTR param_3)

{
  rsize_t rVar1;
  
  rVar1 = 0;
  *param_1 = PTR_DAT_4545d110;
  if (param_3 != (LPCSTR)0x0) {
    rVar1 = lstrlenA(param_3);
  }
  FUN_45405b4a(param_1,*(rsize_t *)((int)*param_2 + -8),(void *)*param_2,rVar1,param_3);
  return param_1;
}



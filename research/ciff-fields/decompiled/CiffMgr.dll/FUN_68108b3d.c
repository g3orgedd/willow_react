// Source: CiffMgr.dll @ 68108b3d; FUN_68108b3d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl
FUN_68108b3d(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,BSTR param_4)

{
  undefined4 *puVar1;
  BSTR extraout_var;
  
  FUN_6810794a(&stack0xffffffd8,(int *)&param_4);
  puVar1 = FUN_68108af8(param_2,param_3,extraout_var);
  *param_1 = puVar1;
  SysFreeString(param_4);
  return param_1;
}



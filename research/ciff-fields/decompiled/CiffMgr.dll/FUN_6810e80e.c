// Source: CiffMgr.dll @ 6810e80e; FUN_6810e80e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_6810e80e(undefined4 param_1,LPCWSTR param_2,LPCWSTR param_3,LPCWSTR param_4)

{
  undefined4 uVar1;
  
  if ((param_3 == (LPCWSTR)0x0) || (param_4 == (LPCWSTR)0x0)) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = FUN_6810ded5(param_2,param_3,param_4);
  }
  return uVar1;
}



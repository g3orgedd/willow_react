// Source: CiffHelper.dll @ 4081c006; FUN_4081c006

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_4081c006(undefined4 *param_1)

{
  UINT UVar1;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(*(int *)*param_1 + 100))((int *)*param_1,local_14);
  UVar1 = SysStringLen(local_14[0]);
  SysFreeString(local_14[0]);
  return UVar1 != 0;
}



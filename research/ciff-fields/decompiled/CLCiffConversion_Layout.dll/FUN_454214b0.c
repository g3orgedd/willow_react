// Source: CLCiffConversion_Layout.dll @ 454214b0; FUN_454214b0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_454214b0(void *this,void *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  uVar1 = FUN_454214e8(this,param_1,param_2,(int *)local_14);
  SysFreeString(local_14[0]);
  return uVar1;
}



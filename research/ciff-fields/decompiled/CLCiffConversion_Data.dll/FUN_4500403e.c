// Source: CLCiffConversion_Data.dll @ 4500403e; FUN_4500403e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4500403e(void *this,undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar1 = *(int *)(*(int *)this + -8);
  if (iVar1 < param_2 + param_3) {
    param_3 = iVar1 - param_2;
  }
  if (iVar1 < param_2) {
    param_3 = 0;
  }
  *param_1 = PTR_DAT_4505101c;
  FUN_450024bc(this,param_1,param_3,param_2,0);
  return param_1;
}



// Source: CLCiffConversion_Data.dll @ 45003e81; FUN_45003e81

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_45003e81(void *this,undefined4 *param_1,int param_2)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (*(int *)(*(int *)this + -8) < param_2) {
    param_2 = *(int *)(*(int *)this + -8);
  }
  *param_1 = PTR_DAT_4505101c;
  FUN_450024bc(this,param_1,param_2,0,0);
  return param_1;
}



// Source: CLCiffConversion_Layout.dll @ 4541cd68; FUN_4541cd68

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4541cd68(void *this,undefined4 *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  *param_1 = 0;
  (**(code **)(*piVar1 + 0xac))(piVar1,param_1);
  (**(code **)(*piVar1 + 8))(piVar1);
  return param_1;
}



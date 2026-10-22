// Source: CLCiffConversion_Data.dll @ 450087c1; FUN_450087c1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_450087c1(void *param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)&LAB_4503a024;
  if (param_1 != (void *)0x0) {
    piVar1 = FUN_4500201a(param_1,(int *)*param_3);
    *(undefined4 *)((int)param_1 + 4) = 0;
  }
  return piVar1;
}



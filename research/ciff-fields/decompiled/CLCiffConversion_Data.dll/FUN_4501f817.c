// Source: CLCiffConversion_Data.dll @ 4501f817; FUN_4501f817

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * FUN_4501f817(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)&LAB_4503a024;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    puVar1 = FUN_45001ef3(param_1 + 1,param_2 + 1);
  }
  return puVar1;
}



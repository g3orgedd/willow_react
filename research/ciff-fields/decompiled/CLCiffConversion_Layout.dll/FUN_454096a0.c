// Source: CLCiffConversion_Layout.dll @ 454096a0; FUN_454096a0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_454096a0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (DAT_45460724 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_454298b4(0x1c);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_45460724 = (undefined4 *)0x0;
    }
    else {
      DAT_45460724 = FUN_454075ab(puVar1);
    }
  }
  *param_1 = 0;
  FUN_45407c84(DAT_45460724,param_2,param_1);
  return param_1;
}



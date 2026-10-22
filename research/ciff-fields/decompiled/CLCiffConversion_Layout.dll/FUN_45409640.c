// Source: CLCiffConversion_Layout.dll @ 45409640; FUN_45409640

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __cdecl FUN_45409640(undefined4 *param_1)

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
  FUN_4540793b(DAT_45460724,param_1);
  return param_1;
}



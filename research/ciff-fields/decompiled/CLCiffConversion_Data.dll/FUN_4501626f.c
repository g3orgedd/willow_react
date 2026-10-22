// Source: CLCiffConversion_Data.dll @ 4501626f; FUN_4501626f

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4501626f(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)0x0;
  uVar3 = 0x8007000e;
  *param_1 = 0;
  puVar1 = (undefined4 *)FUN_45025ad0(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = FUN_450145f7(puVar1);
  }
  if (puVar2 != (undefined4 *)0x0) {
    uVar3 = 0;
  }
  *param_1 = puVar2;
  return uVar3;
}



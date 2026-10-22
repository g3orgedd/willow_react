// Source: CLCiffConversion_Layout.dll @ 4542598d; FUN_4542598d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4542598d(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    puVar3 = (undefined4 *)0x0;
    uVar1 = 0x8007000e;
    *param_1 = 0;
    puVar2 = (undefined4 *)FUN_4542ee51(0x1c);
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = FUN_45423c80(puVar2);
    }
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = 0;
    }
    *param_1 = puVar3;
  }
  return uVar1;
}



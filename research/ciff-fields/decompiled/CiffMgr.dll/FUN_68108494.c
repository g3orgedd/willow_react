// Source: CiffMgr.dll @ 68108494; FUN_68108494

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_68108494(undefined4 *param_1)

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
    puVar2 = (undefined4 *)FUN_68132c9e(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = FUN_68107d5d(puVar2);
    }
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = 0;
    }
    *param_1 = puVar3;
  }
  return uVar1;
}



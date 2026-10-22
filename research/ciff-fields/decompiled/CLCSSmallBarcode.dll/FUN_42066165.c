// Source: CLCSSmallBarcode.dll @ 42066165; FUN_42066165

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_42066165(void *this,int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  *(undefined4 *)this = 0;
  if (param_1 == 3) {
    puVar1 = (undefined4 *)FUN_42067914(0x110);
    if (puVar1 != (undefined4 *)0x0) {
      puVar2 = FUN_42065fa6(puVar1);
    }
  }
  else {
    if (param_1 - 6U < 2) {
      puVar1 = (undefined4 *)FUN_42067914(0x2e0);
    }
    else {
      puVar1 = (undefined4 *)FUN_42067914(0x2e0);
    }
    if (puVar1 != (undefined4 *)0x0) {
      puVar2 = FUN_42065ff1(puVar1);
    }
  }
  *(undefined4 **)this = puVar2;
  return this;
}



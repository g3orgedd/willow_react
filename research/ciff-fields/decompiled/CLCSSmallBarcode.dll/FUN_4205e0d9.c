// Source: CLCSSmallBarcode.dll @ 4205e0d9; FUN_4205e0d9

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4205e0d9(void *this,int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 *puVar2;
  undefined3 uVar3;
  undefined4 *puVar4;
  
  bVar1 = FUN_4200827f(this,param_1);
  uVar3 = extraout_var;
  if ((bVar1) && (puVar4 = (undefined4 *)0x0, *(int *)((int)this + 0x40) == 0)) {
    puVar2 = (undefined4 *)FUN_42067914(0xf8);
    if (puVar2 != (undefined4 *)0x0) {
      puVar4 = FUN_4203374b(puVar2);
    }
    uVar3 = 0;
    *(undefined4 **)((int)this + 0x40) = puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      bVar1 = false;
    }
  }
  return CONCAT31(uVar3,bVar1);
}



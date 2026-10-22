// Source: CLCiffConversion_Layout.dll @ 454129dd; FUN_454129dd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_454129dd(void *this,int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    *(undefined ***)this = &PTR_45449d90;
    FUN_454127a6((undefined4 *)((int)this + 0x10));
  }
  *(undefined ***)((int)this + *(int *)(*(int *)this + 4)) = CCIFFResolveFieldWidth::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  uVar1 = FUN_454043b0((int *)0x0,(int *)0x0);
  *(undefined4 *)((int)this + 4) = uVar1;
  return this;
}



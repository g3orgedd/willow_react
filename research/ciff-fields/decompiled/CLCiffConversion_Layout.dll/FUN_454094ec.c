// Source: CLCiffConversion_Layout.dll @ 454094ec; FUN_454094ec

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_454094ec(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  void *this_00;
  
  piVar1 = *(int **)((int)this + 4);
  if ((param_1 < piVar1) && (*(int **)this <= param_1)) {
    iVar2 = *(int *)this;
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_45409418(this,1);
    }
    this_00 = *(void **)((int)this + 4);
    param_1 = (int *)(*(int *)this + ((int)param_1 - iVar2 >> 2) * 4);
  }
  else {
    if (piVar1 == *(int **)((int)this + 8)) {
      FUN_45409418(this,1);
    }
    this_00 = *(void **)((int)this + 4);
  }
  if (this_00 != (void *)0x0) {
    FUN_4540288a(this_00,param_1);
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 4;
  return;
}



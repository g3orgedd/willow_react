// Source: CLCiffConversion_Layout.dll @ 4540d67a; FUN_4540d67a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540d67a(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)this;
  uVar2 = *(int *)((int)this + 4) - iVar1;
  if (uVar2 <= param_1) {
    if (param_1 <= uVar2) {
      return;
    }
    FUN_4540d3c2(this,(iVar1 - *(int *)((int)this + 4)) + param_1);
    FUN_4540a3a9(*(undefined1 **)((int)this + 4),(*(int *)this - *(int *)((int)this + 4)) + param_1)
    ;
    iVar1 = *(int *)this;
  }
  *(uint *)((int)this + 4) = iVar1 + param_1;
  return;
}



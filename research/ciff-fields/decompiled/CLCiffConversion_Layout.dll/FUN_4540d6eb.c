// Source: CLCiffConversion_Layout.dll @ 4540d6eb; FUN_4540d6eb

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540d6eb(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(int *)((int)this + 4) - *(int *)this >> 1;
  if (param_1 < uVar2) {
    iVar1 = *(int *)((int)this + 4) + (param_1 - uVar2) * 2;
  }
  else {
    if (param_1 <= uVar2) {
      return;
    }
    FUN_4540d402(this,param_1 - uVar2);
    FUN_4540a3c3(*(undefined2 **)((int)this + 4),
                 param_1 - (*(int *)((int)this + 4) - *(int *)this >> 1));
    iVar1 = *(int *)((int)this + 4) + (param_1 - (*(int *)((int)this + 4) - *(int *)this >> 1)) * 2;
  }
  *(int *)((int)this + 4) = iVar1;
  return;
}



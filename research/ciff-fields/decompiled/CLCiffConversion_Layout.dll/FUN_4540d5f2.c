// Source: CLCiffConversion_Layout.dll @ 4540d5f2; FUN_4540d5f2

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540d5f2(void *this,uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(int *)((int)this + 4) - *(int *)this >> 3;
  if (param_1 < uVar2) {
    iVar1 = *(int *)((int)this + 4) + (param_1 - uVar2) * 8;
  }
  else {
    if (param_1 <= uVar2) {
      return;
    }
    FUN_4540d377(this,param_1 - uVar2);
    FUN_4540a389(*(undefined4 **)((int)this + 4),
                 param_1 - (*(int *)((int)this + 4) - *(int *)this >> 3));
    iVar1 = *(int *)((int)this + 4) + (param_1 - (*(int *)((int)this + 4) - *(int *)this >> 3)) * 8;
  }
  *(int *)((int)this + 4) = iVar1;
  return;
}



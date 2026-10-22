// Source: CLCiffConversion_Layout.dll @ 4540d770; FUN_4540d770

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540d770(void *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = (*(int *)((int)this + 4) - *(int *)this) / 0x18;
  if (uVar1 <= param_1) {
    if (param_1 <= uVar1) {
      return;
    }
    FUN_4540d44b(this,param_1 - uVar1);
    FUN_4540a3e1(*(undefined4 **)((int)this + 4),
                 param_1 - (*(int *)((int)this + 4) - *(int *)this) / 0x18);
    uVar1 = (*(int *)((int)this + 4) - *(int *)this) / 0x18;
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + (param_1 - uVar1) * 0x18;
  return;
}



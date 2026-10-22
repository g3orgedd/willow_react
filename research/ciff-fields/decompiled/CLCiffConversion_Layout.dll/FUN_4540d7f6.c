// Source: CLCiffConversion_Layout.dll @ 4540d7f6; FUN_4540d7f6

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_4540d7f6(void *this,undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &LAB_45443143;
  puVar2 = (undefined1 *)(*(int *)((int)this + 4) - *(int *)this >> 5);
  if (puVar2 <= param_1) {
    if (param_1 <= puVar2) {
      return puVar1;
    }
    FUN_4540d49e(this,(int)param_1 - (int)puVar2);
    FUN_4540a407(*(undefined4 **)((int)this + 4),
                 (int)param_1 - (*(int *)((int)this + 4) - *(int *)this >> 5));
    puVar1 = (undefined1 *)(*(int *)((int)this + 4) - *(int *)this >> 5);
    puVar2 = puVar1;
  }
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + ((int)param_1 - (int)puVar2) * 0x20;
  return puVar1;
}



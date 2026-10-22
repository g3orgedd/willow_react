// Source: CLCiffConversion_Data.dll @ 45020a4d; FUN_45020a4d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_45020a4d(void *this,uint param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = &LAB_4503c896;
  uVar2 = *(int *)((int)this + 4) - *(int *)this >> 3;
  if (param_1 < uVar2) {
    puVar1 = (undefined1 *)FUN_45020961(this,uVar2 - param_1);
  }
  else if (uVar2 < param_1) {
    FUN_45020a02(this,param_1 - uVar2);
    FUN_4501f7a0(*(int *)((int)this + 4),param_1 - (*(int *)((int)this + 4) - *(int *)this >> 3));
    puVar1 = (undefined1 *)
             (*(int *)((int)this + 4) +
             (param_1 - (*(int *)((int)this + 4) - *(int *)this >> 3)) * 8);
    *(undefined1 **)((int)this + 4) = puVar1;
  }
  return puVar1;
}



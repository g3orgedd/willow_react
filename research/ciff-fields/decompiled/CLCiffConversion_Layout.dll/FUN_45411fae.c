// Source: CLCiffConversion_Layout.dll @ 45411fae; FUN_45411fae

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * __thiscall FUN_45411fae(void *this,uint param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = &LAB_45443644;
  uVar2 = *(int *)((int)this + 4) - *(int *)this >> 3;
  if (param_1 < uVar2) {
    puVar1 = (undefined1 *)FUN_45411ec2(this,uVar2 - param_1);
  }
  else if (uVar2 < param_1) {
    FUN_45411f63(this,param_1 - uVar2);
    FUN_45410902(*(int *)((int)this + 4),param_1 - (*(int *)((int)this + 4) - *(int *)this >> 3));
    puVar1 = (undefined1 *)
             (*(int *)((int)this + 4) +
             (param_1 - (*(int *)((int)this + 4) - *(int *)this >> 3)) * 8);
    *(undefined1 **)((int)this + 4) = puVar1;
  }
  return puVar1;
}



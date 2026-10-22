// Source: CLCiffConversion_Layout.dll @ 45411ee6; FUN_45411ee6

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45411ee6(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)_Allocate<>(param_1);
  FUN_454108de(*(undefined4 **)this,*(undefined4 **)((int)this + 4),puVar3);
  iVar1 = *(int *)((int)this + 4);
  iVar2 = *(int *)this;
  if (*(int *)this != 0) {
    FUN_4540f8f2(*(int *)this,*(int *)((int)this + 4));
    FID_conflict__free(*(void **)this);
  }
  *(undefined4 **)this = puVar3;
  *(undefined4 **)((int)this + 8) = puVar3 + param_1 * 2;
  *(undefined4 **)((int)this + 4) = puVar3 + (iVar1 - iVar2 >> 3) * 2;
  return;
}



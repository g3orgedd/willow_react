// Source: CLCiffConversion_Layout.dll @ 4542228a; FUN_4542228a

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4542228a(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)_Allocate<>(param_1);
  FUN_45412315(*(undefined4 **)this,*(undefined4 **)((int)this + 4),puVar3);
  iVar1 = *(int *)((int)this + 4);
  iVar2 = *(int *)this;
  if (*(int *)this != 0) {
    FUN_45421f2e(*(void **)this,*(void **)((int)this + 4));
    FID_conflict__free(*(void **)this);
  }
  *(undefined4 **)this = puVar3;
  *(undefined4 **)((int)this + 8) = puVar3 + param_1;
  *(undefined4 **)((int)this + 4) = puVar3 + (iVar1 - iVar2 >> 2);
  return;
}



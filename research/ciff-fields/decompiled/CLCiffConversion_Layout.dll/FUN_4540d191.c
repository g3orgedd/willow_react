// Source: CLCiffConversion_Layout.dll @ 4540d191; FUN_4540d191

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540d191(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)_Allocate<>(param_1);
  FUN_4540a2f9(*(uint *)this,*(uint *)((int)this + 4),puVar3);
  iVar1 = *(int *)((int)this + 4);
  iVar2 = *(int *)this;
  if (*(int *)this != 0) {
    FID_conflict__free(*(void **)this);
  }
  *(undefined2 **)this = puVar3;
  *(undefined2 **)((int)this + 8) = puVar3 + param_1;
  *(undefined2 **)((int)this + 4) = puVar3 + (iVar1 - iVar2 >> 1);
  return;
}



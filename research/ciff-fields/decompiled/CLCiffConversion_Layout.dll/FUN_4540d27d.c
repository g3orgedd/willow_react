// Source: CLCiffConversion_Layout.dll @ 4540d27d; FUN_4540d27d

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4540d27d(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)_Allocate<>(param_1);
  FUN_4540a365(*(undefined4 **)this,*(undefined4 **)((int)this + 4),puVar3);
  iVar1 = *(int *)((int)this + 4);
  iVar2 = *(int *)this;
  if (*(int *)this != 0) {
    FID_conflict__free(*(void **)this);
  }
  *(undefined4 **)this = puVar3;
  *(undefined4 **)((int)this + 8) = puVar3 + param_1 * 8;
  *(uint *)((int)this + 4) = (iVar1 - iVar2 & 0xffffffe0U) + (int)puVar3;
  return;
}



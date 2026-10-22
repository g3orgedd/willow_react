// Source: CLCiffConversion_Data.dll @ 45004b45; FUN_45004b45

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45004b45(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  iVar2 = 0;
  local_8 = 0;
  iVar3 = 0;
  if (*(int *)(param_1 + -8) == 5) {
    puVar1 = FUN_45003e81(&param_1,local_14,2);
    iVar2 = FUN_45022835((wchar_t *)*puVar1);
    FUN_45002256(local_14);
    puVar1 = FUN_450041ee(&param_1,local_14,2);
    iVar3 = FUN_45022835((wchar_t *)*puVar1);
    FUN_45002256(local_14);
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  if (0x17 < iVar2) {
    iVar2 = 0x17;
  }
  *(int *)this = iVar2;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (0x3b < iVar3) {
    iVar3 = 0x3b;
  }
  *(int *)((int)this + 4) = iVar3;
  FUN_45002256(&param_1);
  return;
}



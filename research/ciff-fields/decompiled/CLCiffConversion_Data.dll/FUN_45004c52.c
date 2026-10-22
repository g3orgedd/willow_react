// Source: CLCiffConversion_Data.dll @ 45004c52; FUN_45004c52

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_45004c52(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  iVar5 = 0;
  local_8 = 0;
  if (*(int *)(param_1 + -8) == 9) {
    puVar1 = FUN_4500403e(&param_1,local_14,1,2);
    iVar5 = FUN_45022835((wchar_t *)*puVar1);
    FUN_45002256(local_14);
    puVar1 = FUN_4500403e(&param_1,local_14,4,2);
    iVar2 = FUN_45022835((wchar_t *)*puVar1);
    FUN_45002256(local_14);
    puVar1 = FUN_450041ee(&param_1,local_14,2);
    iVar3 = FUN_45022835((wchar_t *)*puVar1);
    FUN_45002256(local_14);
    puVar1 = FUN_45003e81(&param_1,local_14,1);
    iVar4 = _wcscmp((wchar_t *)*puVar1,L"-");
    FUN_45002256(local_14);
    iVar5 = ((iVar5 * 0x3c + iVar2) * 0x3c + iVar3) * ((-(uint)(iVar4 != 0) & 2) - 1);
  }
  if (0x1517f < iVar5) {
    iVar5 = 0x1517f;
  }
  if (iVar5 < -0x1517f) {
    iVar5 = -0x1517f;
  }
  *(int *)this = iVar5;
  FUN_45002256(&param_1);
  return;
}



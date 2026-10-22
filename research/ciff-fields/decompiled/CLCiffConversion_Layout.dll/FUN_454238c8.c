// Source: CLCiffConversion_Layout.dll @ 454238c8; FUN_454238c8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_454238c8(int param_1)

{
  int iVar1;
  void *pvVar2;
  char cVar3;
  UINT UVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x454238d4;
  iVar7 = 0;
  *(undefined1 *)(param_1 + 0x100) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x4c) + 0x3c);
  if (iVar1 == 0) {
    cVar3 = '\0';
  }
  else {
    cVar3 = FUN_4541b028(iVar1);
  }
  if (cVar3 == '\0') {
    UVar4 = SysStringLen(*(BSTR *)(param_1 + 0x48));
    if (UVar4 == 0) {
      return 0;
    }
    puVar5 = FUN_45402ac2(&local_18,*(wchar_t **)(param_1 + 0x48));
    local_8 = 1;
    pvVar2 = *(void **)(*(int *)(param_1 + 0x4c) + 0x3c);
    if (pvVar2 != (void *)0x0) {
      iVar7 = FUN_4541c12a(pvVar2,puVar5);
    }
    piVar6 = &local_18;
  }
  else {
    UVar4 = SysStringLen(*(BSTR *)(param_1 + 0x48));
    if (UVar4 == 0) {
      return 0;
    }
    puVar5 = FUN_45402ac2(local_14,*(wchar_t **)(param_1 + 0x48));
    local_8 = 0;
    pvVar2 = *(void **)(*(int *)(param_1 + 0x4c) + 0x3c);
    if (pvVar2 != (void *)0x0) {
      iVar7 = FUN_4541c12a(pvVar2,puVar5);
    }
    piVar6 = local_14;
  }
  FUN_45402c5d(piVar6);
  if (iVar7 != 0) {
    *(undefined1 *)(param_1 + 0x100) = 1;
  }
  return 0;
}



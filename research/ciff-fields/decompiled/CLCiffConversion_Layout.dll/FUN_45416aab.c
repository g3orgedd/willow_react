// Source: CLCiffConversion_Layout.dll @ 45416aab; FUN_45416aab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45416aab(void *this,BSTR param_1)

{
  int *piVar1;
  void *pvVar2;
  bool bVar3;
  UINT UVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int *local_38;
  undefined4 local_34;
  BSTR local_30;
  int *local_2c;
  BSTR local_28;
  void *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x45416ab7;
  piVar8 = (int *)((int)this + -8);
  local_2c = piVar8;
  local_24 = this;
  FUN_45404ce5((void *)((int)this + *(int *)(*piVar8 + 4) + 0x54),(int *)param_1);
  local_34 = 0;
  local_38 = (int *)FUN_454043b0((int *)0x0,(int *)0x0);
  local_8 = 0;
  FUN_45406d62((int *)param_1,&local_38);
  local_18 = (int *)0x0;
  FUN_45404ce5(&local_18,(int *)(*(int *)(*piVar8 + 4) + 100 + (int)this));
  local_8._0_1_ = 1;
  FUN_4541db3e(&local_18,&local_28);
  local_8._0_1_ = 2;
  *(undefined1 *)((int)this + -4) = 0;
  UVar4 = SysStringLen(local_28);
  if ((UVar4 != 0) && (bVar3 = FUN_45402d4b(&local_28,L"Default"), !bVar3)) {
    puVar5 = FUN_4541da01(&local_18,&param_1);
    local_8._0_1_ = 3;
    bVar3 = FUN_45402d4b(puVar5,L"Line");
    local_8._0_1_ = 2;
    SysFreeString(param_1);
    if (bVar3) {
      *(undefined1 *)((int)this + -4) = 1;
    }
  }
  iVar9 = -1;
  iVar7 = -1;
  param_1 = (BSTR)CONCAT13(1,param_1._0_3_);
  piVar8 = (int *)*local_38;
  if (piVar8 != local_38) {
    do {
      local_14 = (void *)piVar8[2];
      puVar5 = FUN_4541cbbe(local_14,&local_30);
      local_8._0_1_ = 4;
      FUN_45407800((void *)((int)local_24 + *(int *)(*local_2c + 4) + 0x5c),(wchar_t *)*puVar5);
      local_8._0_1_ = 2;
      SysFreeString(local_30);
      local_20 = FUN_4541cd30((int)local_14);
      local_1c = FUN_4541cd4c((int)local_14);
      iVar6 = FUN_4541cb7f((int)local_14);
      if (*(char *)((int)local_24 + -4) == '\0') {
        if (param_1._3_1_ == '\0') {
          if (local_1c < iVar7) goto LAB_45416c37;
        }
        else {
          param_1 = (BSTR)((uint)param_1 & 0xffffff);
LAB_45416c37:
          iVar7 = local_1c;
          iVar9 = local_20;
        }
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        if (iVar9 < 0) {
          iVar9 = 0;
        }
      }
      else if ((iVar6 == 1) || (local_1c == 0)) {
        iVar7 = FUN_4541cd14((int)local_14);
        if ((iVar9 == -1) || (iVar9 < local_20 + iVar7)) {
          iVar9 = local_20 + iVar7;
        }
        iVar7 = 0;
      }
      piVar8 = (int *)*piVar8;
    } while (piVar8 != local_38);
  }
  pvVar2 = local_24;
  FUN_454065f3((int *)&local_38);
  piVar8 = (int *)((int)pvVar2 + -8);
  FUN_454133bf(piVar8,iVar9,iVar7);
  piVar1 = *(int **)(*(int *)(*piVar8 + 4) + 0x54 + (int)pvVar2);
  if ((piVar1 != (int *)0x0) &&
     (*(undefined4 *)(*(int *)(*piVar8 + 4) + 0x54 + (int)pvVar2) = 0, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45402cd0((void *)((int)pvVar2 + *(int *)(*piVar8 + 4) + 0x5c),"");
  SysFreeString(local_28);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  FUN_454224ff((int *)&local_38);
  FID_conflict__free(local_38);
  return 0;
}



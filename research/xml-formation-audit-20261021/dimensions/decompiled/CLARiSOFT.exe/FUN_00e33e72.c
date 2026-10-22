// Source: CLARiSOFT.exe @ 00e33e72; FUN_00e33e72

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool __thiscall FUN_00e33e72(void *this,BSTR param_1)

{
  BSTR pOVar1;
  bool bVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  VARIANTARG *pVVar8;
  VARIANTARG local_34;
  BSTR local_24;
  void *local_20;
  int *local_1c;
  int local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0x24;
  bVar7 = false;
  if ((param_1 == (BSTR)0x0) || (local_24 = param_1 + 2, *(int *)local_24 == 0)) {
    return false;
  }
  local_14[0] = (BSTR)0x0;
  local_8 = 0;
  local_20 = this;
  (**(code **)(**(int **)local_24 + 0x1c))(*(int **)local_24,local_14);
  if (((*(void **)((int)this + 0x28) == (void *)0x0) ||
      (uVar3 = FUN_00e2e20c(*(void **)((int)this + 0x28),(CComBSTR *)local_14), (char)uVar3 == '\0')
      ) && (uVar3 = FUN_00e2e707(this,pOVar1), (char)uVar3 != '\0')) {
    piVar4 = (int *)FUN_00e77808((void *)((int)this + 4),0);
    if (*piVar4 == 0) {
      local_18 = 0;
    }
    else {
      local_18 = *piVar4 + -100;
    }
    iVar5 = FUN_00e3e85d(local_18);
    bVar2 = FUN_00e66fde(*(int *)(*(int *)((int)this + 400) + iVar5 * 4));
    if (!bVar2) {
      FUN_00e03b51((uint *)&local_34);
      piVar4 = *(int **)((int)this + 0x19c);
      pVVar8 = &local_34;
      local_8._0_1_ = 1;
      iVar5 = *piVar4;
      iVar6 = FUN_00e3e85d(local_18);
      (**(code **)(iVar5 + 0x24))(piVar4,iVar6 + 1,pVVar8);
      CComQIPtr<>(&local_1c,(undefined4 *)local_34.n1._8_4_);
      local_8._0_1_ = 2;
      param_1 = (BSTR)CONCAT13(1,param_1._0_3_);
      FUN_00eb1a01((undefined4 *)((int)this + 0x19c),&local_1c,(undefined4 *)local_24,
                   (int *)((int)local_20 + 0x160),
                   (undefined4 *)(uint)*(byte *)((int)local_20 + 0x154),(byte *)((int)&param_1 + 3))
      ;
      bVar7 = param_1._3_1_ == '\0';
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      VariantClear(&local_34);
      goto LAB_00e33ff1;
    }
    param_1 = (BSTR)0x1;
    (**(code **)(**(int **)(pOVar1 + 2) + 0x24))(*(int **)(pOVar1 + 2),&param_1);
    if (((*(char *)((int)this + 0x154) != '\0') || (param_1 != (BSTR)0x1)) ||
       ((uVar3 = FUN_00e2f031(this,pOVar1), (char)uVar3 != '\0' &&
        ((uVar3 = FUN_00e2fd81(this,(int)pOVar1), (char)uVar3 != '\0' &&
         (bVar2 = FUN_00e296b3(this,(int)pOVar1), bVar2)))))) goto LAB_00e33ff1;
  }
  bVar7 = true;
LAB_00e33ff1:
  SysFreeString(local_14[0]);
  return bVar7;
}



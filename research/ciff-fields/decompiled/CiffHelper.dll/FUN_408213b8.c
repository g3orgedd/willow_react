// Source: CiffHelper.dll @ 408213b8; FUN_408213b8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x4082155e) */
/* WARNING: Removing unreachable block (ram,0x40821531) */
/* WARNING: Removing unreachable block (ram,0x40821564) */
/* WARNING: Removing unreachable block (ram,0x4082157c) */

int __thiscall FUN_408213b8(void *this,int *param_1,BSTR param_2)

{
  undefined4 *puVar1;
  CComBSTR *pCVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  CComBSTR *pCVar6;
  BSTR extraout_ECX;
  BSTR pOVar7;
  CComBSTR **ppCVar8;
  _union_2683 local_4c;
  _union_2683 local_3c;
  CComBSTR *local_2c;
  CComBSTR *local_28;
  undefined4 local_24;
  BSTR local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0;
  FUN_40822d03(param_1,1);
  puVar1 = *(undefined4 **)((int)this + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_40807854(puVar1);
    FID_conflict__free(puVar1);
    *(undefined4 *)((int)this + 0x10) = 0;
  }
  local_14 = (int *)FUN_4082d9f3(0xc);
  local_8._0_1_ = 1;
  if (local_14 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_4080772c(local_14);
  }
  local_18 = (BSTR)0x0;
  *(int **)((int)this + 0x10) = piVar4;
  local_8._0_1_ = 2;
  iVar5 = (**(code **)(*(int *)*param_1 + 0x44))();
  local_2c = (CComBSTR *)0x0;
  local_28 = (CComBSTR *)0x0;
  local_24 = 0;
  local_8._0_1_ = 3;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 3;
  if (iVar5 == 0) {
    ppCVar8 = &local_2c;
    pOVar7 = extraout_ECX;
    FUN_40803baf(&stack0xffffff94,(int *)&local_18);
    FUN_40807c42(*(void **)((int)this + 0x10),pOVar7,ppCVar8);
    pCVar2 = local_28;
    local_14 = (int *)((uint)local_14 & 0xffffff00);
    pCVar6 = FUN_40821251(local_2c,local_28,(CComBSTR *)&param_2);
    if (pCVar6 == pCVar2) {
      iVar5 = -0x7ff8ffa9;
    }
    else {
      FUN_40802e76((uint *)&local_4c);
      local_8._0_1_ = 4;
      iVar5 = (**(code **)(*(int *)*param_1 + 0x80))();
      if ((-1 < iVar5) && (local_4c.n2.vt == 9)) {
        local_14 = (int *)0x0;
        local_8._0_1_ = 5;
        iVar5 = (*(code *)**(undefined4 **)local_4c._8_4_)();
        if ((-1 < iVar5) && (local_14 != (int *)0x0)) {
          FUN_40802e76((uint *)&local_3c);
          local_8._0_1_ = 6;
          iVar5 = (**(code **)(*local_14 + 0x4c))();
          if ((-1 < iVar5) && (local_3c.n2.vt == 9)) {
            local_8._0_1_ = 7;
            iVar5 = (*(code *)**(undefined4 **)local_3c._8_4_)();
            local_8._0_1_ = 6;
          }
          VariantClear((VARIANTARG *)&local_3c.n2);
        }
        local_8._0_1_ = 4;
        if (local_14 != (int *)0x0) {
          (**(code **)(*local_14 + 8))();
        }
      }
      VariantClear((VARIANTARG *)&local_4c.n2);
    }
  }
  else {
    puVar1 = *(undefined4 **)((int)this + 0x10);
    local_8._0_1_ = uVar3;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_40807854(puVar1);
      FID_conflict__free(puVar1);
      *(undefined4 *)((int)this + 0x10) = 0;
    }
  }
  FUN_40807f8c((int *)&local_2c);
  SysFreeString(local_18);
  SysFreeString(param_2);
  return iVar5;
}



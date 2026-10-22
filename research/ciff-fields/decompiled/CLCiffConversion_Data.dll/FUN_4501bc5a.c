// Source: CLCiffConversion_Data.dll @ 4501bc5a; FUN_4501bc5a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __thiscall FUN_4501bc5a(void *this,BSTR param_1)

{
  BSTR pOVar1;
  UINT UVar2;
  int iVar3;
  BSTR extraout_ECX;
  LPCWSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  undefined4 extraout_ECX_02;
  LPCWSTR extraout_ECX_03;
  BSTR extraout_ECX_04;
  undefined4 uVar4;
  BSTR pOVar5;
  undefined4 *puVar6;
  LPCWSTR pWVar7;
  undefined1 **ppuVar8;
  BSTR pOVar9;
  undefined1 **ppuVar10;
  BSTR *ppOVar11;
  undefined1 *local_2c;
  undefined1 *local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  BSTR local_18;
  undefined1 local_11;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4501bc66;
  UVar2 = SysStringLen(*(BSTR *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xe8 + (int)this));
  pOVar1 = param_1;
  if (UVar2 == 0) {
    return 0;
  }
  local_11 = 0;
  iVar3 = (**(code **)(*(int *)param_1 + 0x4c))();
  if (iVar3 < 0) {
    return local_11;
  }
  if ((local_1c != 1) && (local_1c != 2)) {
    return local_11;
  }
  param_1 = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(*(int *)pOVar1 + 0x94))();
  UVar2 = SysStringLen(param_1);
  if (UVar2 == 0) {
    (**(code **)(*(int *)pOVar1 + 0x1c))();
  }
  local_20 = 0;
  (**(code **)(*(int *)pOVar1 + 0x24))();
  local_18 = (BSTR)0x0;
  if (local_20 == 1) {
    ppOVar11 = &local_18;
    local_8._0_1_ = 1;
    local_2c = &stack0xffffffbc;
    pOVar9 = extraout_ECX;
    FUN_45001f5d(&stack0xffffffbc,L"UserEnteredDate");
    local_28 = &stack0xffffffb8;
    local_8._0_1_ = 2;
    pWVar7 = extraout_ECX_00;
    FUN_45001ef3(&stack0xffffffb8,(int *)&param_1);
    local_8._0_1_ = 3;
    pOVar5 = extraout_ECX_01;
    FUN_45001ef3(&stack0xffffffb4,(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xe8 + (int)this))
    ;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = FUN_45020b7c((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0xec),pOVar5,
                         pWVar7,pOVar9,(uint *)ppOVar11);
    local_11 = iVar3 != 0;
    if ((!(bool)local_11) || (UVar2 = SysStringLen(local_18), UVar2 == 0)) goto LAB_4501be4b;
    local_24 = 0;
    ppuVar10 = &local_28;
    ppuVar8 = &local_2c;
    puVar6 = &local_24;
    uVar4 = extraout_ECX_02;
    FUN_450020a5(&stack0xffffffb4,local_18);
    FUN_4501d667(uVar4,puVar6,ppuVar8,(uint *)ppuVar10);
    (**(code **)(*(int *)pOVar1 + 0x40))();
  }
  else {
    ppOVar11 = &local_18;
    local_8._0_1_ = 4;
    local_2c = &stack0xffffffbc;
    pOVar9 = extraout_ECX;
    FUN_45001f5d(&stack0xffffffbc,L"DateOffset");
    local_28 = &stack0xffffffb8;
    local_8._0_1_ = 5;
    pWVar7 = extraout_ECX_03;
    FUN_45001ef3(&stack0xffffffb8,(int *)&param_1);
    local_8._0_1_ = 6;
    pOVar5 = extraout_ECX_04;
    FUN_45001ef3(&stack0xffffffb4,(int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0xe8 + (int)this))
    ;
    local_8 = CONCAT31(local_8._1_3_,4);
    iVar3 = FUN_45020b7c((void *)((int)this + *(int *)(*(int *)((int)this + 4) + 4) + 0xec),pOVar5,
                         pWVar7,pOVar9,(uint *)ppOVar11);
    if ((iVar3 == 0) || (UVar2 = SysStringLen(local_18), UVar2 == 0)) goto LAB_4501be4b;
    local_24 = 0;
    iVar3 = FUN_45022b22(local_18,0x4504081c);
    if (iVar3 != 3) goto LAB_4501be4b;
    (**(code **)(*(int *)pOVar1 + 0x40))();
  }
  (**(code **)(*(int *)pOVar1 + 0x38))();
  (**(code **)(*(int *)pOVar1 + 0x30))();
LAB_4501be4b:
  SysFreeString(local_18);
  SysFreeString(param_1);
  return local_11;
}



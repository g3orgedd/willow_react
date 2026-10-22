// Source: CLCiffConversion_Layout.dll @ 45422547; FUN_45422547

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_45422547(void *this,int *param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  code *pcVar4;
  BSTR pOVar5;
  BSTR pOVar6;
  void *local_38 [2];
  void *local_30 [2];
  int *local_28;
  undefined4 local_24;
  BSTR local_20;
  BSTR local_1c;
  BSTR local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x45422553;
  local_24 = 0;
  FUN_45402a11((int *)local_38);
  local_8 = 1;
  FUN_45402881(local_14);
  local_8._0_1_ = 2;
  FUN_4541c90f(param_2,&local_1c);
  local_8._0_1_ = 3;
  bVar1 = FUN_45402d4b(&local_1c,L"DateText");
  if (bVar1) {
    piVar2 = FUN_4541c943(param_2,(int *)&local_20,(int *)0x1);
    piVar2 = (int *)*piVar2;
    local_28 = piVar2;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
    local_8._0_1_ = 4;
    if (local_20 != (BSTR)0x0) {
      (**(code **)(*(int *)local_20 + 8))();
    }
    local_18 = (BSTR)0x0;
    local_8._0_1_ = 5;
    (**(code **)(*piVar2 + 0x80))();
    param_2 = (int *)0x0;
    local_8._0_1_ = 6;
    pOVar5 = extraout_ECX;
    FUN_4540288a(&stack0xffffffac,(int *)&local_18);
    FUN_45403838((int *)(*(int *)(*(int *)((int)this + 4) + 4) + 0x3c + (int)this),&param_2,pOVar5);
    local_20 = (BSTR)0x0;
    local_8._0_1_ = 7;
    FUN_4541a358(&param_2,(int *)&local_20);
    pOVar5 = local_20;
    if (param_2 == (int *)0x0) {
      local_8._0_1_ = 6;
      if (local_20 != (BSTR)0x0) {
        (**(code **)(*(int *)local_20 + 8))();
      }
      local_8._0_1_ = 5;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))();
      }
      pcVar4 = SysFreeString_exref;
      SysFreeString(local_18);
      local_8 = CONCAT31(local_8._1_3_,3);
      (**(code **)(*piVar2 + 8))();
      FUN_45402826(param_1,local_38);
      local_24 = 1;
    }
    else {
      pOVar6 = local_20;
      if (local_20 != (BSTR)0x0) {
        (**(code **)(*(int *)local_20 + 4))(local_20);
      }
      puVar3 = FUN_45402939(local_30,(int *)pOVar6);
      local_8._0_1_ = 8;
      FUN_45402826(param_1,puVar3);
      local_24 = 1;
      FUN_45404963((int *)local_30);
      FID_conflict__free(local_30[0]);
      local_8._0_1_ = 6;
      if (pOVar5 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar5 + 8))();
      }
      local_8._0_1_ = 5;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))();
      }
      pcVar4 = SysFreeString_exref;
      SysFreeString(local_18);
      local_8 = CONCAT31(local_8._1_3_,3);
      (**(code **)(*piVar2 + 8))();
    }
    (*pcVar4)(local_1c);
  }
  else {
    FUN_4541c774(param_2,&local_20);
    local_8 = CONCAT31(local_8._1_3_,9);
    pOVar5 = extraout_ECX_00;
    FUN_4540288a(&stack0xffffffb4,(int *)&local_20);
    FUN_45403ab4(param_1,pOVar5);
    local_24 = 1;
    SysFreeString(local_20);
    SysFreeString(local_1c);
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_45402c42(local_14);
  FUN_45404963((int *)local_38);
  FID_conflict__free(local_38[0]);
  return param_1;
}



// Source: CLCiffConversion_Data.dll @ 4501a36c; FUN_4501a36c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4501a36c(void *this,BSTR param_1)

{
  int iVar1;
  int *piVar2;
  BSTR this_00;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  BSTR pOVar6;
  bool bVar7;
  int *local_20;
  undefined4 local_1c;
  BSTR local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  this_00 = param_1;
  uStack_4 = 0x10;
  if (param_1 == (BSTR)0x0) {
    return 0x80004003;
  }
  *(undefined1 *)((int)this + -8) = 0;
  param_1 = (BSTR)0x0;
  local_8 = 0;
  pOVar6 = this_00 + 2;
  local_18 = pOVar6;
  FUN_450022ba((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0x54),(int *)pOVar6);
  puVar4 = FUN_45007442(this_00,local_14);
  local_8._0_1_ = 1;
  FUN_45002365((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0x58),
               (LPCWSTR)*puVar4);
  local_8._0_1_ = 0;
  SysFreeString(local_14[0]);
  puVar4 = FUN_450072f3(this_00,local_14);
  local_8._0_1_ = 2;
  FUN_45002365((void *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0x5c),
               (LPCWSTR)*puVar4);
  local_8._0_1_ = 0;
  SysFreeString(local_14[0]);
  local_1c = 0;
  local_20 = (int *)FUN_45013f7b((int *)0x0,(int *)0x0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_4500735e((int *)this_00,&local_20);
  piVar5 = FUN_4500732a(this_00,local_14);
  FUN_450058c3((void *)((int)this + -4),piVar5);
  SysFreeString(local_14[0]);
  piVar3 = local_20;
  piVar2 = local_20;
  for (piVar5 = (int *)*local_20; local_20 = piVar2, piVar5 != piVar3; piVar5 = (int *)*piVar5) {
    (**(code **)(*(int *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + -0xc) + 0xc))
              (piVar5[2]);
    pOVar6 = local_18;
    piVar2 = local_20;
  }
  piVar5 = (int *)*piVar2;
  if (piVar5 == piVar2) {
LAB_4501a4c2:
    FUN_45002326(&param_1,L"");
  }
  else {
    do {
      local_14[0] = (BSTR)0x0;
      local_8._0_1_ = 4;
      (**(code **)(**(int **)piVar5[2] + 0x60))(*(int **)piVar5[2],local_14);
      FUN_4500263d(&param_1,local_14[0]);
      local_8 = CONCAT31(local_8._1_3_,3);
      SysFreeString(local_14[0]);
      piVar5 = (int *)*piVar5;
    } while (piVar5 != piVar2);
    pOVar6 = local_18;
    if (param_1 == (BSTR)0x0) goto LAB_4501a4c2;
  }
  FUN_4501b149((int *)pOVar6,(int *)&param_1);
  (**(code **)(**(int **)pOVar6 + 0x9c))(*(int **)pOVar6,param_1);
  FUN_45004f8d((int *)&local_20);
  iVar1 = *(int *)(*(int *)((int)this + -0xc) + 4);
  piVar5 = *(int **)(iVar1 + 0x54 + (int)this);
  if ((piVar5 != (int *)0x0) &&
     (*(undefined4 *)(iVar1 + 0x54 + (int)this) = 0, piVar5 != (int *)0x0)) {
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  FUN_45007216((int *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0x58));
  FUN_45007216((int *)((int)this + *(int *)(*(int *)((int)this + -0xc) + 4) + 0x5c));
  if (*(char *)((int)this + -8) == '\0') goto LAB_4501a5d6;
  (**(code **)(**(int **)pOVar6 + 100))(*(int **)pOVar6,&local_18);
  if (local_18 == (BSTR)0x0) {
    CComQIPtr<>(&local_18,*(undefined4 **)pOVar6);
    local_8._0_1_ = 5;
    bVar7 = local_18 == (BSTR)0x0;
    if (!bVar7) {
      (**(code **)(*(int *)local_18 + 0x174))(local_18,1);
LAB_4501a5c5:
      bVar7 = local_18 == (BSTR)0x0;
    }
  }
  else if (local_18 == (BSTR)0x1) {
    CComQIPtr<>(&local_18,*(undefined4 **)pOVar6);
    local_8._0_1_ = 6;
    bVar7 = local_18 == (BSTR)0x0;
    if (!bVar7) {
      (**(code **)(*(int *)local_18 + 0x240))(local_18,1);
      goto LAB_4501a5c5;
    }
  }
  else {
    if (local_18 != (BSTR)0x2) goto LAB_4501a5d6;
    CComQIPtr<>(&local_18,*(undefined4 **)pOVar6);
    local_8._0_1_ = 7;
    bVar7 = local_18 == (BSTR)0x0;
    if (!bVar7) {
      (**(code **)(*(int *)local_18 + 0xf8))(local_18,1);
      goto LAB_4501a5c5;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (!bVar7) {
    (**(code **)(*(int *)local_18 + 8))(local_18);
  }
LAB_4501a5d6:
  FUN_4501423d((int *)&local_20);
  FID_conflict__free(local_20);
  SysFreeString(param_1);
  return 0;
}



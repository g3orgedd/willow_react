// Source: CiffMgr.dll @ 6811f5a7; FUN_6811f5a7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811f5a7(int *param_1,BSTR param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  BSTR pOVar4;
  wchar_t *local_20;
  int *local_1c;
  void *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar4 = param_2;
  uStack_4 = 0x10;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(**(int **)param_2 + 0x94))
                    (*(int **)param_2,PTR_u_HRDisplayed_6815fe50,local_14);
  if ((iVar2 == 0) && (local_14[0] != (int *)0x0)) {
    local_20 = (wchar_t *)0x0;
    iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_20);
    if (-1 < iVar2) {
      piVar1 = (int *)*param_1;
      iVar2 = *piVar1;
      uVar3 = FUN_6812e988(local_20);
      (**(code **)(iVar2 + 0xc4))(piVar1,uVar3);
      pOVar4 = param_2;
    }
    SysFreeString(local_20);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_14[0] = (int *)0x0;
  local_8 = 1;
  iVar2 = (**(code **)(**(int **)pOVar4 + 0x94))(*(int **)pOVar4,PTR_u_HRPos_6815fe54,local_14);
  if ((iVar2 == 0) && (local_14[0] != (int *)0x0)) {
    local_20 = (wchar_t *)0x0;
    iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&local_20);
    if (-1 < iVar2) {
      piVar1 = (int *)*param_1;
      iVar2 = *piVar1;
      uVar3 = FUN_6812f048(local_20);
      (**(code **)(iVar2 + 0xcc))(piVar1,uVar3);
      pOVar4 = param_2;
    }
    SysFreeString(local_20);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_14[0] = (int *)0x0;
  local_8 = 2;
  iVar2 = (**(code **)(**(int **)pOVar4 + 0x94))(*(int **)pOVar4,PTR_u_HRFont_6815fe58,local_14);
  if ((iVar2 == 0) && (local_14[0] != (int *)0x0)) {
    param_2 = (BSTR)0x0;
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar2 = (**(code **)(*local_14[0] + 0x30))(local_14[0],&param_2);
    if ((iVar2 == 0) && (param_2 != (BSTR)0x0)) {
      iVar2 = FUN_6811ec7d(local_18,param_1,&param_2);
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if (param_2 != (BSTR)0x0) {
      (**(code **)(*(int *)param_2 + 8))(param_2);
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  CComQIPtr<>(&local_1c,(undefined4 *)*param_1);
  if (local_1c != (int *)0x0) {
    param_1 = (int *)0x0;
    local_8 = 5;
    iVar2 = (**(code **)(**(int **)pOVar4 + 0x94))
                      (*(int **)pOVar4,PTR_u_HRPrintCheckDigit_6815ffd8,&param_1);
    if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
      param_2 = (BSTR)0x0;
      iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&param_2);
      piVar1 = local_1c;
      if (-1 < iVar2) {
        iVar2 = *local_1c;
        uVar3 = FUN_6812e988(param_2);
        iVar2 = (**(code **)(iVar2 + 0x218))(piVar1,uVar3);
      }
      SysFreeString(param_2);
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  if (iVar2 == 1) {
    iVar2 = 0;
  }
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return iVar2;
}



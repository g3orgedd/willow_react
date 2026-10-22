// Source: CiffMgr.dll @ 68120b7a; FUN_68120b7a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68120b7a(BSTR param_1,BSTR param_2,BSTR param_3,int *param_4,int *param_5)

{
  BSTR pOVar1;
  int iVar2;
  int iVar3;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(**(int **)param_1 + 0x94))(*(int **)param_1,PTR_u_Seconds_6815fc98,local_14);
  if ((iVar2 == 0) && (local_14[0] != (int *)0x0)) {
    param_1 = (BSTR)0x0;
    iVar2 = (**(code **)(*local_14[0] + 0x68))(local_14[0],&param_1);
    if (-1 < iVar2) {
      iVar2 = FUN_6812f116((ushort *)param_1);
      *(int *)param_2 = iVar2;
    }
    SysFreeString(param_1);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  param_1 = (BSTR)0x0;
  local_8 = 1;
  iVar2 = (**(code **)(**(int **)pOVar1 + 0x94))(*(int **)pOVar1,PTR_DAT_6815fc9c,&param_1);
  if ((iVar2 == 0) && (param_1 != (BSTR)0x0)) {
    param_2 = (BSTR)0x0;
    iVar2 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&param_2);
    if (-1 < iVar2) {
      iVar2 = FUN_6812f116((ushort *)param_2);
      *(int *)param_3 = iVar2;
    }
    SysFreeString(param_2);
  }
  local_8 = 0xffffffff;
  if (param_1 != (BSTR)0x0) {
    (**(code **)(*(int *)param_1 + 8))(param_1);
  }
  param_1 = (BSTR)0x0;
  local_8 = 2;
  iVar2 = (**(code **)(**(int **)pOVar1 + 0x94))(*(int **)pOVar1,PTR_u_Month_6815fca0,&param_1);
  if ((iVar2 == 0) && (param_1 != (BSTR)0x0)) {
    param_2 = (BSTR)0x0;
    iVar2 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&param_2);
    if (-1 < iVar2) {
      iVar2 = FUN_6812f116((ushort *)param_2);
      *param_4 = iVar2;
    }
    SysFreeString(param_2);
  }
  local_8 = 0xffffffff;
  if (param_1 != (BSTR)0x0) {
    (**(code **)(*(int *)param_1 + 8))(param_1);
  }
  param_2 = (BSTR)0x0;
  local_8 = 3;
  iVar2 = (**(code **)(**(int **)pOVar1 + 0x94))(*(int **)pOVar1,PTR_u_Year_6815fca4,&param_2);
  if ((iVar2 == 0) && (param_2 != (BSTR)0x0)) {
    param_3 = (BSTR)0x0;
    iVar2 = (**(code **)(*(int *)param_2 + 0x68))(param_2,&param_3);
    if (-1 < iVar2) {
      iVar3 = FUN_6812f116((ushort *)param_3);
      *param_5 = iVar3;
    }
    SysFreeString(param_3);
  }
  local_8 = 0xffffffff;
  if (param_2 != (BSTR)0x0) {
    (**(code **)(*(int *)param_2 + 8))(param_2);
  }
  if (iVar2 == 1) {
    iVar2 = 0;
  }
  return iVar2;
}



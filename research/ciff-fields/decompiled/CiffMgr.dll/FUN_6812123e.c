// Source: CiffMgr.dll @ 6812123e; FUN_6812123e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812123e(int *param_1,BSTR param_2)

{
  int *piVar1;
  int *piVar2;
  BSTR pOVar3;
  int iVar4;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_1;
  uStack_4 = 4;
  local_8 = 0x6812124a;
  if (param_1 == (int *)0x0) {
    iVar4 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 0x58))(param_1,1);
    pOVar3 = param_2;
    param_1 = (int *)0x0;
    local_8 = 0;
    iVar4 = (**(code **)(**(int **)param_2 + 0x94))
                      (*(int **)param_2,PTR_u_ConnStr_6815fca8,&param_1);
    if ((iVar4 == 0) && (param_1 != (int *)0x0)) {
      param_2 = (BSTR)0x0;
      iVar4 = (**(code **)(*param_1 + 0x68))(param_1,&param_2);
      if (-1 < iVar4) {
        (**(code **)(*piVar2 + 0x60))(piVar2,param_2);
      }
      SysFreeString(param_2);
    }
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    param_1 = (int *)0x0;
    piVar1 = *(int **)pOVar3;
    local_8 = 1;
    iVar4 = (**(code **)(*piVar1 + 0x94))(piVar1,PTR_u_DateSQL_6815fcac,&param_1);
    if ((iVar4 == 0) && (param_1 != (int *)0x0)) {
      param_2 = (BSTR)0x0;
      iVar4 = (**(code **)(*param_1 + 0x68))(param_1,&param_2);
      if (-1 < iVar4) {
        (**(code **)(*piVar2 + 0x68))(piVar2,param_2);
      }
      SysFreeString(param_2);
    }
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    param_2 = (BSTR)0x0;
    piVar1 = *(int **)pOVar3;
    local_8 = 2;
    iVar4 = (**(code **)(*piVar1 + 0x94))(piVar1,PTR_u_DateMask_6815fcb0,&param_2);
    if ((iVar4 == 0) && (param_2 != (BSTR)0x0)) {
      local_14[0] = (BSTR)0x0;
      iVar4 = (**(code **)(*(int *)param_2 + 0x68))(param_2,local_14);
      if (-1 < iVar4) {
        iVar4 = (**(code **)(*piVar2 + 0x70))(piVar2,local_14[0]);
      }
      SysFreeString(local_14[0]);
    }
    local_8 = 0xffffffff;
    if (param_2 != (BSTR)0x0) {
      (**(code **)(*(int *)param_2 + 8))(param_2);
    }
    if (iVar4 == 1) {
      iVar4 = 0;
    }
  }
  return iVar4;
}



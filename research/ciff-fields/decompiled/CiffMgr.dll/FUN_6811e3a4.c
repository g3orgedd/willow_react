// Source: CiffMgr.dll @ 6811e3a4; FUN_6811e3a4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811e3a4(int *param_1,BSTR param_2)

{
  int *piVar1;
  BSTR pOVar2;
  int iVar3;
  undefined4 uVar4;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_2;
  piVar1 = param_1;
  uStack_4 = 8;
  if (param_1 == (int *)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    param_1 = (int *)0x0;
    local_8 = 0;
    iVar3 = (**(code **)(**(int **)param_2 + 0x94))
                      (*(int **)param_2,PTR_u_PadChar_6815fd60,&param_1);
    if ((-1 < iVar3) && (param_1 != (int *)0x0)) {
      param_2 = (BSTR)0x0;
      iVar3 = (**(code **)(*param_1 + 0x68))(param_1,&param_2);
      if (-1 < iVar3) {
        (**(code **)(*piVar1 + 0xa8))(piVar1,*param_2);
      }
      SysFreeString(param_2);
    }
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
    param_2 = (BSTR)0x0;
    local_8 = 1;
    iVar3 = (**(code **)(**(int **)pOVar2 + 0x94))(*(int **)pOVar2,PTR_u_PadMode_6815fd64,&param_2);
    if ((iVar3 == 0) && (param_2 != (BSTR)0x0)) {
      local_14[0] = (wchar_t *)0x0;
      iVar3 = (**(code **)(*(int *)param_2 + 0x68))(param_2,local_14);
      if (-1 < iVar3) {
        iVar3 = *piVar1;
        uVar4 = FUN_6812edc3(local_14[0]);
        iVar3 = (**(code **)(iVar3 + 0xb0))(piVar1,uVar4);
      }
      SysFreeString(local_14[0]);
    }
    local_8 = 0xffffffff;
    if (param_2 != (BSTR)0x0) {
      (**(code **)(*(int *)param_2 + 8))(param_2);
    }
    if (iVar3 == 1) {
      iVar3 = 0;
    }
  }
  return iVar3;
}



// Source: CiffMgr.dll @ 68120d2b; FUN_68120d2b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68120d2b(int *param_1,BSTR param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  UINT UVar4;
  long lVar5;
  BSTR pOVar6;
  int local_20 [2];
  int *local_18;
  BSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x10;
  local_8 = 0x68120d37;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 0x28))(param_1,local_20);
    pOVar6 = param_2;
    if (local_20[0] == 2) {
      param_1 = (int *)0x0;
      local_8 = 0;
      iVar2 = (**(code **)(**(int **)param_2 + 0x94))
                        (*(int **)param_2,PTR_u_ConnStr_6815fca8,&param_1);
      if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
        local_14[0] = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1,local_14);
        if (-1 < iVar2) {
          (**(code **)(*piVar1 + 0x74))(piVar1,local_14[0]);
        }
        SysFreeString(local_14[0]);
      }
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      param_1 = (int *)0x0;
      local_8 = 1;
      iVar2 = (**(code **)(**(int **)pOVar6 + 0x94))(*(int **)pOVar6,PTR_u_SrcSQL_6815fd70,&param_1)
      ;
      if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
        local_14[0] = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1,local_14);
        if (-1 < iVar2) {
          (**(code **)(*piVar1 + 0x6c))(piVar1,local_14[0]);
        }
        SysFreeString(local_14[0]);
      }
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      param_1 = (int *)0x0;
      local_8 = 2;
      iVar2 = (**(code **)(**(int **)pOVar6 + 0x94))
                        (*(int **)pOVar6,PTR_u_StartChar_6815fd68,&param_1);
      if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
        local_14[0] = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1,local_14);
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          iVar3 = FUN_6812f116((ushort *)local_14[0]);
          (**(code **)(iVar2 + 0xf0))(piVar1,iVar3);
          pOVar6 = param_2;
        }
        SysFreeString(local_14[0]);
      }
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      param_1 = (int *)0x0;
      local_8 = 3;
      iVar2 = (**(code **)(**(int **)pOVar6 + 0x94))
                        (*(int **)pOVar6,PTR_u_NoOfChars_6815fd6c,&param_1);
      if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
        local_14[0] = (BSTR)0x0;
        iVar2 = (**(code **)(*param_1 + 0x68))(param_1,local_14);
        if (-1 < iVar2) {
          iVar2 = *piVar1;
          iVar3 = FUN_6812f116((ushort *)local_14[0]);
          iVar2 = (**(code **)(iVar2 + 0xf8))(piVar1,iVar3);
        }
        SysFreeString(local_14[0]);
      }
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      CComQIPtr<>(&local_18,piVar1);
      if (local_18 != (int *)0x0) {
        local_14[0] = (BSTR)0x0;
        local_8._0_1_ = 5;
        local_8._1_3_ = 0;
        iVar2 = (**(code **)(**(int **)param_2 + 0x94))
                          (*(int **)param_2,PTR_u_SelectMode_6815fff0,local_14);
        if ((iVar2 == 0) && (local_14[0] != (BSTR)0x0)) {
          param_2 = (BSTR)0x0;
          local_8._0_1_ = 6;
          iVar2 = (**(code **)(*(int *)local_14[0] + 0x68))(local_14[0],&param_2);
          if ((-1 < iVar2) && (UVar4 = SysStringLen(param_2), UVar4 != 0)) {
            lVar5 = __wtol(param_2);
            iVar2 = (**(code **)(*local_18 + 0x194))(local_18,lVar5 == 1);
          }
          SysFreeString(param_2);
        }
        local_8 = CONCAT31(local_8._1_3_,4);
        if (local_14[0] != (BSTR)0x0) {
          (**(code **)(*(int *)local_14[0] + 8))(local_14[0]);
        }
      }
      if (iVar2 == 1) {
        iVar2 = 0;
      }
      local_8 = 0xffffffff;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
    else {
      iVar2 = -0x7ff8ffa9;
    }
  }
  return iVar2;
}



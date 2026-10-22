// Source: CiffMgr.dll @ 6811bb98; FUN_6811bb98

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811bb98(BSTR param_1,undefined4 *param_2)

{
  BSTR pOVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  code *pcVar7;
  int local_24;
  int *local_20;
  int *local_1c;
  wchar_t *local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0x14;
  local_8 = 0x6811bba4;
  if (param_1 == (BSTR)0x0) {
    iVar3 = -0x7fffbffd;
  }
  else {
    (**(code **)(*(int *)param_1 + 0x28))(param_1,&local_24);
    puVar6 = param_2;
    if (local_24 == 5) {
      local_18 = (wchar_t *)0x0;
      local_8 = 0;
      iVar3 = (**(code **)(*(int *)*param_2 + 0x94))
                        ((int *)*param_2,PTR_u_Rollover_6815fd88,&local_18);
      pcVar7 = SysFreeString_exref;
      if ((iVar3 == 0) && (local_18 != (wchar_t *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          uVar4 = FUN_6812e988(param_1);
          (**(code **)(iVar3 + 0x100))(pOVar1,uVar4);
          puVar6 = param_2;
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (wchar_t *)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      local_18 = (wchar_t *)0x0;
      local_8 = 1;
      iVar3 = (**(code **)(*(int *)*puVar6 + 0x94))
                        ((int *)*puVar6,PTR_u_PrnPerCnt_6815fd8c,&local_18);
      if ((iVar3 == 0) && (local_18 != (wchar_t *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          iVar5 = FUN_6812f116((ushort *)param_1);
          (**(code **)(iVar3 + 0x108))(pOVar1,iVar5);
          puVar6 = param_2;
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (wchar_t *)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      local_18 = (wchar_t *)0x0;
      local_8 = 2;
      iVar3 = (**(code **)(*(int *)*puVar6 + 0x94))
                        ((int *)*puVar6,PTR_u_ResetOnSel_6815fc7c,&local_18);
      if ((iVar3 == 0) && (local_18 != (wchar_t *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          iVar3 = *(int *)pOVar1;
          uVar4 = FUN_6812f7ea(param_1);
          (**(code **)(iVar3 + 0x110))(pOVar1,uVar4);
          puVar6 = param_2;
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (wchar_t *)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      local_18 = (wchar_t *)0x0;
      local_8 = 3;
      iVar3 = (**(code **)(*(int *)*puVar6 + 0x94))
                        ((int *)*puVar6,PTR_u_ParentCounter_6815fd90,&local_18);
      if ((iVar3 == 0) && (local_18 != (wchar_t *)0x0)) {
        param_1 = (BSTR)0x0;
        iVar3 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&param_1);
        if (-1 < iVar3) {
          iVar3 = (**(code **)(*(int *)pOVar1 + 0x118))(pOVar1,param_1);
        }
        SysFreeString(param_1);
      }
      local_8 = 0xffffffff;
      if (local_18 != (wchar_t *)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      CComQIPtr<>(&local_1c,(undefined4 *)pOVar1);
      puVar6 = param_2;
      local_8._0_1_ = 4;
      local_8._1_3_ = 0;
      if (local_1c != (int *)0x0) {
        param_1 = (BSTR)0x0;
        local_8 = 5;
        iVar3 = (**(code **)(*(int *)*param_2 + 0x94))
                          ((int *)*param_2,PTR_u_RolloverError_6815ff38,&param_1);
        if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
          local_18 = (wchar_t *)0x0;
          iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_18);
          piVar2 = local_1c;
          if (-1 < iVar3) {
            iVar3 = *local_1c;
            uVar4 = FUN_6812e988(local_18);
            (**(code **)(iVar3 + 0x174))(piVar2,uVar4);
            puVar6 = param_2;
            pcVar7 = SysFreeString_exref;
          }
          (*pcVar7)(local_18);
        }
        local_8._0_1_ = 4;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,6);
        iVar3 = (**(code **)(*(int *)*puVar6 + 0x94))
                          ((int *)*puVar6,PTR_u_PromptWith_6815ff3c,&param_1);
        if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
          local_18 = (wchar_t *)0x0;
          iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_18);
          piVar2 = local_1c;
          if (-1 < iVar3) {
            iVar3 = *local_1c;
            uVar4 = FUN_6812eab8(local_18);
            iVar3 = (**(code **)(iVar3 + 0x17c))(piVar2,uVar4);
            pcVar7 = SysFreeString_exref;
          }
          (*pcVar7)(local_18);
        }
        local_8._0_1_ = 4;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
      }
      CComQIPtr<>(&local_20,(undefined4 *)pOVar1);
      if (local_20 != (int *)0x0) {
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,8);
        iVar3 = (**(code **)(*(int *)*param_2 + 0x94))
                          ((int *)*param_2,PTR_u_ResetSource_6815ffa4,&param_1);
        if ((iVar3 == 0) && (param_1 != (BSTR)0x0)) {
          local_18 = (wchar_t *)0x0;
          iVar3 = (**(code **)(*(int *)param_1 + 0x68))(param_1,&local_18);
          piVar2 = local_20;
          if (-1 < iVar3) {
            iVar3 = *local_20;
            uVar4 = FUN_6812eb30(local_18);
            iVar3 = (**(code **)(iVar3 + 0x184))(piVar2,uVar4);
            pcVar7 = SysFreeString_exref;
          }
          (*pcVar7)(local_18);
        }
        local_8._0_1_ = 7;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
      }
      if (-1 < iVar3) {
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,9);
        iVar3 = (**(code **)(*(int *)*param_2 + 0x90))
                          ((int *)*param_2,PTR_u_SubCnt_6815fd94,&param_1);
        if ((-1 < iVar3) && (param_1 != (BSTR)0x0)) {
          iVar3 = FUN_681215f4(local_14,(int *)pOVar1,&param_1);
        }
        local_8._0_1_ = 7;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      if (iVar3 == 1) {
        iVar3 = 0;
      }
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      local_8 = 0xffffffff;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
    else {
      iVar3 = -0x7ff8ffa9;
    }
  }
  return iVar3;
}



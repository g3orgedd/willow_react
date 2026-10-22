// Source: CiffMgr.dll @ 6812d7a8; FUN_6812d7a8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812d7a8(int *param_1,BSTR param_2,undefined4 *param_3)

{
  int *piVar1;
  BSTR pOVar2;
  int iVar3;
  UINT UVar4;
  undefined *puVar5;
  uint uVar6;
  code *pcVar7;
  _union_2683 local_48;
  _union_2683 local_38;
  int *local_28 [2];
  int local_20;
  uint local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  pOVar2 = param_2;
  uStack_4 = 0x38;
  local_18 = (BSTR)0x0;
  local_8 = 0;
  uStack_7 = 0;
  iVar3 = (**(code **)(**(int **)param_2 + 0xbc))(*(int **)param_2,&local_18);
  if (iVar3 < 0) goto LAB_6812dc09;
  UVar4 = SysStringLen(local_18);
  piVar1 = param_1;
  if (UVar4 != 0) {
    iVar3 = FUN_6810226e(param_1,param_3,PTR_u_Prompt_6815fc78,local_18);
  }
  if (iVar3 < 0) goto LAB_6812dc09;
  param_2 = (BSTR)0x0;
  local_1c = 1;
  local_8 = 1;
  iVar3 = (**(code **)(**(int **)pOVar2 + 0xc4))(*(int **)pOVar2,&param_2);
  if ((-1 < iVar3) && (UVar4 = SysStringLen(param_2), UVar4 != 0)) {
    iVar3 = FUN_6810226e(piVar1,param_3,PTR_u_Mask_6815fd74,param_2);
  }
  local_8 = 0;
  SysFreeString(param_2);
  if (iVar3 < 0) goto LAB_6812dc09;
  param_2 = (BSTR)0x0;
  local_8 = 2;
  iVar3 = (**(code **)(**(int **)pOVar2 + 0xcc))(*(int **)pOVar2,&param_2);
  if ((-1 < iVar3) && (UVar4 = SysStringLen(param_2), UVar4 != 0)) {
    iVar3 = FUN_6810226e(piVar1,param_3,PTR_u_UserEnterData_6815fd78,param_2);
  }
  local_8 = 0;
  SysFreeString(param_2);
  if ((iVar3 < 0) ||
     (iVar3 = (**(code **)(**(int **)pOVar2 + 0xd4))(*(int **)pOVar2,&param_2), iVar3 < 0))
  goto LAB_6812dc09;
  if (param_2 != (BSTR)0x1) {
    puVar5 = FUN_6812e9d1((int)param_2);
    iVar3 = FUN_6810248f(piVar1,param_3,PTR_u_PromptAtCoder_6815fd7c,puVar5);
  }
  if ((iVar3 < 0) ||
     (iVar3 = (**(code **)(**(int **)pOVar2 + 0xdc))(*(int **)pOVar2,&param_2), iVar3 < 0))
  goto LAB_6812dc09;
  if (param_2 != (BSTR)0x0) {
    puVar5 = FUN_6812fbab((int)param_2);
    iVar3 = FUN_6810248f(piVar1,param_3,PTR_u_ResetOnSel_6815fc7c,puVar5);
  }
  if (iVar3 < 0) goto LAB_6812dc09;
  CComQIPtr<>(local_28,*(undefined4 **)pOVar2);
  if (local_28[0] != (int *)0x0) {
    FUN_68132710((uint *)&local_38,0,0x10);
    VariantInit((VARIANTARG *)&local_38.n2);
    local_8 = 4;
    iVar3 = (**(code **)(*local_28[0] + 0x13c))(local_28[0],&local_38);
    if (((-1 < iVar3) && (local_38.n2.vt == 9)) &&
       ((undefined4 *)local_38._8_4_ != (undefined4 *)0x0)) {
      param_1 = (int *)0x0;
      local_8 = 5;
      iVar3 = (*(code *)**(undefined4 **)local_38._8_4_)(local_38._8_4_,&DAT_68147bcc,&param_1);
      if ((-1 < iVar3) && (param_1 != (int *)0x0)) {
        local_20 = 0;
        iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,&local_20);
        if (-1 < iVar3) {
          uVar6 = 1;
          pcVar7 = SysFreeString_exref;
          if (local_20 < 1) {
            param_2 = (BSTR)0x0;
            local_8 = 6;
            iVar3 = (**(code **)(*param_1 + 0x48))(param_1,&param_2);
            if (-1 < iVar3) {
              UVar4 = SysStringLen(param_2);
              local_1c = CONCAT31(local_1c._1_3_,-(UVar4 != 0)) & 0xffffff01;
            }
            pcVar7 = SysFreeString_exref;
            SysFreeString(param_2);
            uVar6 = local_1c;
          }
          if ((-1 < iVar3) && ((char)uVar6 != '\0')) {
            param_2 = (BSTR)0x0;
            local_8 = 7;
            iVar3 = (**(code **)(*(int *)*piVar1 + 0xbc))
                              ((int *)*piVar1,PTR_u_ListData_6815fd80,&param_2);
            if (-1 < iVar3) {
              if (param_2 != (BSTR)0x0) {
                local_1c = 0;
                local_8 = 8;
                iVar3 = (**(code **)(*param_1 + 0x38))(param_1,&local_1c);
                if (-1 < iVar3) {
                  local_14[0] = (int *)0x0;
                  local_8 = 9;
                  iVar3 = (**(code **)(*(int *)param_2 + 0x44))(param_2,local_14);
                  if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
                    local_48.n2.vt = 0;
                    FUN_68102191(&local_48,(int *)&local_1c);
                    local_8 = 10;
                    iVar3 = FUN_681021f5(piVar1,local_14,PTR_u_Mask_68160104,(undefined4 *)&local_48
                                        );
                    VariantClear((VARIANTARG *)&local_48.n2);
                  }
                  local_8 = 8;
                  if (local_14[0] != (int *)0x0) {
                    (**(code **)(*local_14[0] + 8))(local_14[0]);
                  }
                }
                local_8 = 7;
                (*pcVar7)(local_1c);
              }
              if (-1 < iVar3) {
                local_1c = 0;
                _local_8 = CONCAT31(uStack_7,0xb);
                iVar3 = (**(code **)(*param_1 + 0x40))(param_1,&local_1c);
                if (-1 < iVar3) {
                  iVar3 = FUN_6810248f(piVar1,&param_2,PTR_u_ConnStr_6815fff8,local_1c);
                }
                local_8 = 7;
                (*pcVar7)(local_1c);
                if (-1 < iVar3) {
                  local_1c = 0;
                  _local_8 = CONCAT31(uStack_7,0xc);
                  iVar3 = (**(code **)(*param_1 + 0x48))(param_1,&local_1c);
                  if (-1 < iVar3) {
                    iVar3 = FUN_6810248f(piVar1,&param_2,PTR_u_SourceSQL_6815fffc,local_1c);
                  }
                  local_8 = 7;
                  (*pcVar7)(local_1c);
                }
              }
            }
            if (local_20 < 1) {
LAB_6812dbb8:
              if (-1 < iVar3) {
                iVar3 = (**(code **)(*(int *)*param_3 + 0x54))((int *)*param_3,param_2,0);
              }
            }
            else if (-1 < iVar3) {
              if (param_2 != (BSTR)0x0) {
                iVar3 = FUN_6812d4ec(piVar1,&param_1,&param_2);
              }
              goto LAB_6812dbb8;
            }
            local_8 = 5;
            if (param_2 != (BSTR)0x0) {
              (**(code **)(*(int *)param_2 + 8))(param_2);
            }
          }
        }
      }
      local_8 = 4;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
    }
    VariantClear((VARIANTARG *)&local_38.n2);
  }
  local_8 = 0;
  if (local_28[0] != (int *)0x0) {
    (**(code **)(*local_28[0] + 8))(local_28[0]);
  }
LAB_6812dc09:
  SysFreeString(local_18);
  return iVar3;
}



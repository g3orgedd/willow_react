// Source: CiffMgr.dll @ 6811e7a1; FUN_6811e7a1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811e7a1(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  BSTR pOVar5;
  undefined *puVar6;
  int *piVar7;
  bool bVar8;
  int local_28;
  int local_24;
  wchar_t *local_20;
  BSTR local_1c;
  BSTR local_18;
  void *local_14;
  uint local_8;
  undefined4 uStack_4;
  
  piVar7 = param_1;
  uStack_4 = 0x18;
  local_8 = 0x6811e7ad;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*param_1 + 100))(param_1,&local_24);
  if (local_24 != 2) {
    return (int)piVar7;
  }
  param_1 = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)*piVar7)(piVar7,&DAT_6814a9b8,&param_1);
  piVar7 = param_2;
  if ((iVar2 < 0) || (param_1 == (int *)0x0)) goto LAB_6811ec5d;
  local_18 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = (**(code **)(*(int *)*param_2 + 0x94))((int *)*param_2,PTR_u_GfxW_6815fe74,&local_18);
  if ((iVar2 == 0) && (local_18 != (BSTR)0x0)) {
    local_1c = (BSTR)0x0;
    iVar2 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&local_1c);
    piVar1 = param_1;
    if (-1 < iVar2) {
      iVar2 = *param_1;
      iVar3 = FUN_6812f116((ushort *)local_1c);
      (**(code **)(iVar2 + 0xac))(piVar1,iVar3);
      piVar7 = param_2;
    }
    SysFreeString(local_1c);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_18 != (BSTR)0x0) {
    (**(code **)(*(int *)local_18 + 8))(local_18);
  }
  local_18 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_GfxH_6815fe78,&local_18);
  if ((iVar2 == 0) && (local_18 != (BSTR)0x0)) {
    local_1c = (BSTR)0x0;
    iVar2 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&local_1c);
    piVar1 = param_1;
    if (-1 < iVar2) {
      iVar2 = *param_1;
      iVar3 = FUN_6812f116((ushort *)local_1c);
      iVar2 = (**(code **)(iVar2 + 0xb4))(piVar1,iVar3);
      piVar7 = param_2;
    }
    SysFreeString(local_1c);
  }
  local_8 = local_8 & 0xffffff00;
  if (local_18 != (BSTR)0x0) {
    (**(code **)(*(int *)local_18 + 8))(local_18);
  }
  (**(code **)(*param_1 + 0xb8))(param_1,&local_28);
  if (local_28 == 0) {
    param_2 = (int *)0x0;
    local_8._0_1_ = 3;
    iVar2 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,PTR_u_Primitive_6815fe80,&param_2);
    if (iVar2 != 0) goto LAB_6811ec49;
    bVar8 = param_2 == (int *)0x0;
    if (!bVar8) {
      local_18 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar2 = (**(code **)(*param_2 + 0x94))(param_2,PTR_u_Shape_6815fe94,&local_18);
      if ((iVar2 == 0) && (local_18 != (BSTR)0x0)) {
        local_20 = (wchar_t *)0x0;
        iVar2 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&local_20);
        piVar7 = param_1;
        if (-1 < iVar2) {
          iVar2 = *param_1;
          uVar4 = FUN_6812f94e(local_20);
          (**(code **)(iVar2 + 0xd0))(piVar7,uVar4);
        }
        SysFreeString(local_20);
      }
      local_8._0_1_ = 3;
      if (local_18 != (BSTR)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      local_18 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,5);
      iVar2 = (**(code **)(*param_2 + 0x94))(param_2,PTR_u_LineW_6815fe98,&local_18);
      if ((iVar2 == 0) && (local_18 != (BSTR)0x0)) {
        local_20 = (BSTR)0x0;
        iVar2 = (**(code **)(*(int *)local_18 + 0x68))(local_18,&local_20);
        piVar7 = param_1;
        if (-1 < iVar2) {
          iVar2 = *param_1;
          iVar3 = FUN_6812f116((ushort *)local_20);
          (**(code **)(iVar2 + 0xd8))(piVar7,iVar3);
        }
        SysFreeString(local_20);
      }
      local_8._0_1_ = 3;
      if (local_18 != (BSTR)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      local_1c = (BSTR)0x0;
      local_8._0_1_ = 6;
      iVar2 = (**(code **)(*param_2 + 0x94))(param_2,PTR_u_ComplexShape_6815fe9c,&local_1c);
      if ((iVar2 == 0) && (local_1c != (BSTR)0x0)) {
        local_18 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,7);
        iVar2 = (**(code **)(*(int *)local_1c + 0x90))(local_1c,PTR_u_Point_6815fea0,&local_18);
        if ((iVar2 == 0) && (local_18 != (BSTR)0x0)) {
          iVar2 = FUN_6811ff99(local_14,param_1,&local_18);
        }
        local_8._0_1_ = 6;
        if (local_18 != (BSTR)0x0) {
          (**(code **)(*(int *)local_18 + 8))(local_18);
        }
      }
      local_8._0_1_ = 3;
      pOVar5 = local_1c;
LAB_6811ec3f:
      if (pOVar5 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar5 + 8))(pOVar5);
      }
      goto LAB_6811ec49;
    }
  }
  else {
    if (((local_28 != 1) && (local_28 != 2)) && (local_28 != 3)) goto LAB_6811ec5d;
    param_2 = (int *)0x0;
    local_8._0_1_ = 8;
    puVar6 = PTR_u_StaticGfx_6815fe7c;
    if (((local_28 != 1) && (puVar6 = PTR_u_VariableGfx_6815fe84, local_28 != 2)) &&
       (puVar6 = PTR_u_EmbeddedGfx_6815fe88, local_28 != 3)) {
      puVar6 = (undefined *)0x0;
    }
    iVar2 = (**(code **)(*(int *)*piVar7 + 0x94))((int *)*piVar7,puVar6,&param_2);
    if (iVar2 == 0) {
      bVar8 = true;
      if (param_2 != (int *)0x0) {
        local_1c = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,9);
        iVar2 = (**(code **)(*param_2 + 0x94))(param_2,PTR_u_AspectRatio_6815fe8c,&local_1c);
        if ((iVar2 == 0) && (local_1c != (BSTR)0x0)) {
          local_20 = (wchar_t *)0x0;
          iVar2 = (**(code **)(*(int *)local_1c + 0x68))(local_1c,&local_20);
          piVar7 = param_1;
          if (-1 < iVar2) {
            iVar2 = *param_1;
            uVar4 = FUN_6812e988(local_20);
            (**(code **)(iVar2 + 0xc0))(piVar7,uVar4);
          }
          SysFreeString(local_20);
        }
        local_8._0_1_ = 8;
        if (local_1c != (BSTR)0x0) {
          (**(code **)(*(int *)local_1c + 8))(local_1c);
        }
        local_1c = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,10);
        iVar2 = (**(code **)(*param_2 + 0x94))(param_2,PTR_u_ResizeFrame_6815fe90,&local_1c);
        if ((iVar2 == 0) && (local_1c != (BSTR)0x0)) {
          local_20 = (wchar_t *)0x0;
          iVar2 = (**(code **)(*(int *)local_1c + 0x68))(local_1c,&local_20);
          piVar7 = param_1;
          if (-1 < iVar2) {
            iVar2 = *param_1;
            uVar4 = FUN_6812e988(local_20);
            iVar2 = (**(code **)(iVar2 + 200))(piVar7,uVar4);
          }
          SysFreeString(local_20);
        }
        local_8._0_1_ = 8;
        if (local_1c != (BSTR)0x0) {
          (**(code **)(*(int *)local_1c + 8))(local_1c);
        }
        CComQIPtr<>(&local_18,param_1);
        if (local_18 != (BSTR)0x0) {
          local_1c = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,0xc);
          iVar2 = (**(code **)(*param_2 + 0x94))
                            (param_2,PTR_u_LogoReferencePrinter_6815fff4,&local_1c);
          if ((iVar2 == 0) && (local_1c != (BSTR)0x0)) {
            local_20 = (wchar_t *)0x0;
            iVar2 = (**(code **)(*(int *)local_1c + 0x68))(local_1c,&local_20);
            pOVar5 = local_18;
            if (-1 < iVar2) {
              iVar2 = *(int *)local_18;
              uVar4 = FUN_6812e988(local_20);
              iVar2 = (**(code **)(iVar2 + 0x100))(pOVar5,uVar4);
            }
            SysFreeString(local_20);
          }
          local_8._0_1_ = 0xb;
          if (local_1c != (BSTR)0x0) {
            (**(code **)(*(int *)local_1c + 8))(local_1c);
          }
        }
        local_8._0_1_ = 8;
        pOVar5 = local_18;
        goto LAB_6811ec3f;
      }
      goto LAB_6811ec4e;
    }
LAB_6811ec49:
    bVar8 = param_2 == (int *)0x0;
  }
LAB_6811ec4e:
  local_8 = (uint)local_8._1_3_ << 8;
  if (!bVar8) {
    (**(code **)(*param_2 + 8))(param_2);
  }
LAB_6811ec5d:
  if (iVar2 == 1) {
    iVar2 = 0;
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return iVar2;
}



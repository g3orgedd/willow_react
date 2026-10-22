// Source: CiffMgr.dll @ 6812b048; FUN_6812b048

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int FUN_6812b048(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  OLECHAR *pOVar4;
  int iVar5;
  short *psVar6;
  UINT UVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int **ppiVar11;
  undefined1 local_68 [16];
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  BSTR local_38;
  BSTR local_34;
  BSTR local_30;
  BSTR local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_18 = (int *)0x0;
  local_8 = 0;
  puVar3 = (undefined4 *)(**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_18);
  piVar2 = param_1;
  puVar10 = param_2;
  if ((-1 < (int)puVar3) && (local_18 != (int *)0x0)) {
    FUN_68132710((uint *)local_68,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_68)->n2);
    puVar10 = param_2;
    local_68._8_4_ = (BSTR)0x0;
    local_68._0_2_ = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    puVar3 = (undefined4 *)
             (**(code **)(*(int *)*param_2 + 0x1c))
                       ((int *)*param_2,&(((_union_2683 *)local_68)->n2).n3);
    if ((-1 < (int)puVar3) &&
       (((puVar3 = (undefined4 *)
                   FUN_681021f5(piVar2,&local_18,PTR_u_Name_68160030,(undefined4 *)local_68),
         -1 < (int)puVar3 &&
         (piVar1 = (int *)*puVar10,
         puVar3 = (undefined4 *)(**(code **)(*piVar1 + 0x74))(piVar1,&param_1), -1 < (int)puVar3))
        && (param_1 != (int *)0x0)))) {
      SysFreeString((BSTR)local_68._8_4_);
      pOVar4 = (OLECHAR *)FUN_6812f578((int)param_1);
      local_68._8_4_ = SysAllocString(pOVar4);
      puVar3 = (undefined4 *)
               FUN_681021f5(piVar2,&local_18,PTR_u_Type_6816003c,(undefined4 *)local_68);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_68)->n2);
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  if ((-1 < (int)puVar3) &&
     (puVar3 = (undefined4 *)(**(code **)(*(int *)*puVar10 + 0x3c))((int *)*puVar10,&local_3c),
     -1 < (int)puVar3)) {
    local_40 = 0;
    puVar3 = (undefined4 *)(**(code **)(*(int *)*puVar10 + 0x34))((int *)*puVar10,&local_40);
    if (-1 < (int)puVar3) {
      if ((local_3c != 0) || (local_40 != 0)) {
        local_1c = (int *)0x0;
        local_8 = 2;
        iVar5 = FUN_68124179(piVar2,param_3,PTR_DAT_6815fecc,(int *)&local_1c);
        if ((-1 < iVar5) && (local_3c != 0)) {
          param_1 = (int *)0x0;
          local_8._0_1_ = 3;
          iVar5 = (**(code **)(*local_1c + 0x44))(local_1c,&param_1);
          if ((-1 < iVar5) && (param_1 != (int *)0x0)) {
            FUN_68132710((uint *)local_68,0,0x10);
            VariantInit((VARIANTARG *)&((_union_2683 *)local_68)->n2);
            local_8._0_1_ = 4;
            local_68._0_2_ = 8;
            local_68._8_4_ = 0;
            pOVar4 = (OLECHAR *)FUN_6812e9d1(local_3c);
            local_68._8_4_ = SysAllocString(pOVar4);
            iVar5 = FUN_681021f5(piVar2,&param_1,PTR_u_Used_68160040,(undefined4 *)local_68);
            if (-1 < iVar5) {
              local_18 = (int *)0x0;
              piVar1 = (int *)*piVar2;
              ppiVar11 = &local_18;
              iVar5 = *piVar1;
              local_8 = CONCAT31(local_8._1_3_,5);
              psVar6 = FUN_6812f174(local_14,local_40);
              iVar5 = (**(code **)(iVar5 + 0xc4))(piVar1,psVar6,ppiVar11);
              if ((-1 < iVar5) && (local_18 != (int *)0x0)) {
                (**(code **)(*local_1c + 0x54))(local_1c,local_18,0);
              }
              local_8._0_1_ = 4;
              puVar10 = param_2;
              if (local_18 != (int *)0x0) {
                (**(code **)(*local_18 + 8))(local_18);
                puVar10 = param_2;
              }
            }
            VariantClear((VARIANTARG *)&((_union_2683 *)local_68)->n2);
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        }
        local_8 = 0xffffffff;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
      }
      local_44 = 0;
      iVar5 = (**(code **)(*(int *)*puVar10 + 0x44))((int *)*puVar10,&local_44);
      local_20 = 0;
      if (((-1 < iVar5) &&
          ((**(code **)(*(int *)*puVar10 + 0x4c))((int *)*puVar10,&local_20), local_20 != 0)) ||
         (local_44 != 0)) {
        local_28 = (int *)0x0;
        local_8 = 6;
        iVar5 = FUN_68124179(piVar2,param_3,PTR_DAT_6815fed0,(int *)&local_28);
        if ((-1 < iVar5) && (local_20 != 0)) {
          param_1 = (int *)0x0;
          local_8._0_1_ = 7;
          iVar5 = (**(code **)(*local_28 + 0x44))(local_28,&param_1);
          if ((-1 < iVar5) && (param_1 != (int *)0x0)) {
            FUN_68132710((uint *)local_68,0,0x10);
            VariantInit((VARIANTARG *)&((_union_2683 *)local_68)->n2);
            local_8._0_1_ = 8;
            local_68._0_2_ = 8;
            local_68._8_4_ = 0;
            pOVar4 = (OLECHAR *)FUN_6812e9d1(local_20);
            local_68._8_4_ = SysAllocString(pOVar4);
            iVar5 = FUN_681021f5(piVar2,&param_1,PTR_u_Used_68160040,(undefined4 *)local_68);
            if (-1 < iVar5) {
              local_24 = (int *)0x0;
              piVar1 = (int *)*piVar2;
              ppiVar11 = &local_24;
              iVar5 = *piVar1;
              local_8 = CONCAT31(local_8._1_3_,9);
              psVar6 = FUN_6812f174(local_14,local_44);
              iVar5 = (**(code **)(iVar5 + 0xc4))(piVar1,psVar6,ppiVar11);
              if ((-1 < iVar5) && (local_24 != (int *)0x0)) {
                (**(code **)(*local_28 + 0x54))(local_28,local_24,0);
              }
              puVar10 = param_2;
              local_8._0_1_ = 8;
              if (local_24 != (int *)0x0) {
                (**(code **)(*local_24 + 8))(local_24);
                puVar10 = param_2;
              }
            }
            VariantClear((VARIANTARG *)&((_union_2683 *)local_68)->n2);
          }
          local_8 = CONCAT31(local_8._1_3_,6);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        }
        local_8 = 0xffffffff;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))(local_28);
        }
      }
      iVar5 = (**(code **)(*(int *)*puVar10 + 0x2c))((int *)*puVar10,&local_54);
      puVar9 = param_3;
      if (-1 < iVar5) {
        psVar6 = FUN_6812f174(local_14,local_54);
        puVar9 = param_3;
        FUN_6810248f(piVar2,param_3,PTR_u_Current_6815fec8,psVar6);
      }
      iVar5 = (**(code **)(*(int *)*puVar10 + 0x24))((int *)*puVar10,&local_58);
      if (-1 < iVar5) {
        psVar6 = FUN_6812f174(local_14,local_58);
        FUN_6810248f(piVar2,puVar9,PTR_u_Default_6815fd44,psVar6);
      }
      iVar5 = (**(code **)(*(int *)*puVar10 + 0x7c))((int *)*puVar10,&local_48);
      if ((-1 < iVar5) && (local_48 != 2)) {
        psVar6 = FUN_6812f174(local_14,local_48);
        FUN_6810248f(piVar2,puVar9,PTR_u_DecimalPlaces_6815fed4,psVar6);
      }
      local_38 = (BSTR)0x0;
      local_8 = 10;
      iVar5 = (**(code **)(*(int *)*puVar10 + 0x8c))((int *)*puVar10,&local_38);
      if ((-1 < iVar5) && (UVar7 = SysStringLen(local_38), UVar7 != 0)) {
        FUN_6810226e(piVar2,puVar9,PTR_u_Prompt_6815fc78,local_38);
      }
      iVar5 = (**(code **)(*(int *)*puVar10 + 0x84))((int *)*puVar10,&local_4c);
      if ((-1 < iVar5) && (local_4c != 0)) {
        puVar8 = FUN_6812f500(local_4c);
        FUN_6810248f(piVar2,puVar9,PTR_u_ResetOnSel_6815fc7c,puVar8);
      }
      local_34 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0xb);
      (**(code **)(*(int *)*puVar10 + 0x6c))((int *)*puVar10,&local_34);
      UVar7 = SysStringLen(local_34);
      if (UVar7 != 0) {
        FUN_6810248f(piVar2,puVar9,PTR_u_SrcField_6815fee0,local_34);
      }
      iVar5 = (**(code **)(*(int *)*puVar10 + 0x54))((int *)*puVar10,&local_50);
      if ((-1 < iVar5) && (local_50 != 0)) {
        puVar8 = FUN_6812e9d1(local_50);
        FUN_6810248f(piVar2,puVar9,PTR_u_SQLUsed_6815fed8,puVar8);
      }
      local_30 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0xc);
      (**(code **)(*(int *)*puVar10 + 0x5c))((int *)*puVar10,&local_30);
      UVar7 = SysStringLen(local_30);
      if (UVar7 != 0) {
        FUN_6810248f(piVar2,puVar9,PTR_u_PriceSQL_6815fedc,local_30);
      }
      local_2c = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,0xd);
      param_2 = (undefined4 *)(**(code **)(*(int *)*puVar10 + 100))((int *)*puVar10,&local_2c);
      UVar7 = SysStringLen(local_2c);
      puVar3 = param_2;
      if (UVar7 != 0) {
        puVar3 = (undefined4 *)FUN_6810248f(piVar2,puVar9,PTR_u_ConnStr_6815fca8,local_2c);
      }
      SysFreeString(local_2c);
      SysFreeString(local_30);
      SysFreeString(local_34);
      SysFreeString(local_38);
    }
  }
  return (int)puVar3;
}



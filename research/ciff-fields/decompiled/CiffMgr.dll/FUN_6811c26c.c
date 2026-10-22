// Source: CiffMgr.dll @ 6811c26c; FUN_6811c26c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __thiscall FUN_6811c26c(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  DWORD DVar5;
  undefined4 uVar6;
  DWORD DVar7;
  uint uVar8;
  undefined4 bstrString;
  code *pcVar9;
  _union_2683 local_bc;
  _union_2683 local_ac;
  _union_2683 local_9c;
  _union_2683 local_8c;
  _union_2683 local_7c;
  _union_2683 local_6c;
  uint local_5c;
  BSTR local_58;
  _union_2683 local_54;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  DWORD local_30;
  void *local_2c;
  int *local_28;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_2c = this;
  do {
    pvVar2 = local_2c;
    local_1c = (int *)0x0;
    local_8 = 0;
    uVar3 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_1c);
    local_5c = uVar3;
    if ((uVar3 == 0) && (local_1c != (int *)0x0)) {
      local_30 = GetTickCount();
      local_18 = (int *)0x0;
      local_8._0_1_ = 1;
      iVar4 = (**(code **)(*local_1c + 0x44))(local_1c,&local_18);
      local_40 = -1;
      bstrString = (BSTR)0x0;
      local_44 = 1;
      local_38 = 0;
      local_34 = 0;
      local_3c = 0;
      local_58 = (BSTR)0x0;
      local_8._0_1_ = 2;
      if ((-1 < iVar4) && (local_18 != (int *)0x0)) {
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 3;
        iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_u_Index_68160050,local_14);
        pcVar9 = VariantClear_exref;
        if ((iVar4 == 0) && (local_14[0] != (int *)0x0)) {
          FUN_68132710((uint *)&local_7c,0,0x10);
          VariantInit((VARIANTARG *)&local_7c.n2);
          local_8._0_1_ = 4;
          (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_7c);
          if (local_7c.n2.vt == 8) {
            local_40 = FUN_6812f116((ushort *)local_7c._8_4_);
          }
          pcVar9 = VariantClear_exref;
          VariantClear((VARIANTARG *)&local_7c.n2);
        }
        local_8._0_1_ = 2;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 5;
        iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_u_Static_68160054,local_14);
        if ((iVar4 == 0) && (local_14[0] != (int *)0x0)) {
          FUN_68132710((uint *)&local_ac,0,0x10);
          VariantInit((VARIANTARG *)&local_ac.n2);
          local_8._0_1_ = 6;
          (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_ac);
          if (local_ac.n2.vt == 8) {
            local_44 = FUN_6812e988((wchar_t *)local_ac._8_4_);
          }
          (*pcVar9)(&local_ac);
        }
        local_8._0_1_ = 2;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 7;
        iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_u_Parse_68160058,local_14);
        if ((iVar4 == 0) && (local_14[0] != (int *)0x0)) {
          FUN_68132710((uint *)&local_8c,0,0x10);
          VariantInit((VARIANTARG *)&local_8c.n2);
          local_8._0_1_ = 8;
          (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_8c);
          if (local_8c.n2.vt == 8) {
            local_38 = FUN_6812e988((wchar_t *)local_8c._8_4_);
          }
          (*pcVar9)(&local_8c);
        }
        local_8._0_1_ = 2;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 9;
        iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_u_EqRef_681600a4,local_14);
        if ((iVar4 == 0) && (local_14[0] != (int *)0x0)) {
          FUN_68132710((uint *)&local_9c,0,0x10);
          VariantInit((VARIANTARG *)&local_9c.n2);
          local_8._0_1_ = 10;
          (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_9c);
          if ((local_9c.n2.vt == 8) &&
             (local_34 = FUN_6812ecb9((wchar_t *)local_9c._8_4_), local_34 != 0)) {
            *(undefined4 *)((int)pvVar2 + 4) = 1;
          }
          (*pcVar9)(&local_9c);
        }
        local_8._0_1_ = 2;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 0xb;
        iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_u_Param_681600ec,local_14);
        if ((iVar4 == 0) && (local_14[0] != (int *)0x0)) {
          FUN_68132710((uint *)&local_bc,0,0x10);
          VariantInit((VARIANTARG *)&local_bc.n2);
          local_8._0_1_ = 0xc;
          (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_bc);
          if (local_bc.n2.vt == 8) {
            local_3c = FUN_6812e988((wchar_t *)local_bc._8_4_);
          }
          (*pcVar9)(&local_bc);
        }
        local_8._0_1_ = 2;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 0xd;
        iVar4 = (**(code **)(*local_18 + 0x1c))(local_18,PTR_u_Reference_68160108,local_14);
        if ((iVar4 == 0) && (local_14[0] != (int *)0x0)) {
          FUN_68132710((uint *)&local_54,0,0x10);
          VariantInit((VARIANTARG *)&local_54.n2);
          local_8._0_1_ = 0xe;
          (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_54);
          uVar6 = local_54._8_4_;
          if (local_54.n2.vt == 8) {
            if ((BSTR)local_54._8_4_ != (BSTR)0x0) {
              SysFreeString((BSTR)0x0);
              local_58 = (BSTR)uVar6;
              bstrString = uVar6;
            }
            local_54.n2.vt = 0;
            pcVar9 = VariantClear_exref;
          }
          else {
            (*pcVar9)(&local_54);
          }
          (*pcVar9)(&local_54);
        }
        local_8._0_1_ = 2;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      }
      DVar5 = GetTickCount();
      piVar1 = (int *)((int)pvVar2 + 0xb4c);
      *piVar1 = *piVar1 + (DVar5 - local_30);
      DVar5 = GetTickCount();
      uVar6 = FUN_68119d48(&local_1c);
      DVar7 = GetTickCount();
      *(int *)((int)local_2c + 0xb50) = *(int *)((int)local_2c + 0xb50) + (DVar7 - DVar5);
      FUN_68132710((uint *)&local_6c,0,0x10);
      VariantInit((VARIANTARG *)&local_6c.n2);
      local_8._0_1_ = 0xf;
      DVar5 = GetTickCount();
      uVar8 = (**(code **)(*(int *)*param_1 + 0x28))
                        ((int *)*param_1,uVar6,local_40,local_44,local_38,&local_6c);
      DVar7 = GetTickCount();
      pvVar2 = local_2c;
      *(int *)((int)local_2c + 0xb54) = *(int *)((int)local_2c + 0xb54) + (DVar7 - DVar5);
      local_30 = GetTickCount();
      if ((-1 < (int)uVar8) && (local_6c.n2.vt == 9)) {
        CComQIPtr<>(&local_24,(undefined4 *)local_6c._8_4_);
        local_8._0_1_ = 0x10;
        uVar8 = (**(code **)(*(int *)local_24 + 0x4c))(local_24,local_34);
        uVar3 = (**(code **)(*(int *)local_24 + 0x18c))(local_24,local_3c);
        uVar8 = uVar8 | uVar3;
        CComQIPtr<>(&local_28,(undefined4 *)local_6c._8_4_);
        local_8._0_1_ = 0x11;
        if (local_28 != (int *)0x0) {
          uVar3 = (**(code **)(*local_28 + 0x1ac))(local_28,bstrString);
          uVar8 = uVar8 | uVar3;
        }
        if (-1 < (int)uVar8) {
          local_20 = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,0x12);
          uVar8 = (**(code **)(*local_1c + 0x30))(local_1c,&local_20);
          if ((-1 < (int)uVar8) && (local_20 != (int *)0x0)) {
            uVar8 = FUN_6811bf88(pvVar2,local_24,&local_20);
          }
          local_8._0_1_ = 0x11;
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
          }
        }
        local_8._0_1_ = 0x10;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))(local_28);
        }
        local_8._0_1_ = 0xf;
        if (local_24 != (BSTR)0x0) {
          (**(code **)(*(int *)local_24 + 8))(local_24);
        }
      }
      DVar5 = GetTickCount();
      piVar1 = (int *)((int)pvVar2 + 0xb58);
      *piVar1 = *piVar1 + (DVar5 - local_30);
      uVar3 = local_5c;
      if ((int)uVar8 < 0) {
        uVar3 = uVar8;
      }
      VariantClear((VARIANTARG *)&local_6c.n2);
      SysFreeString((BSTR)bstrString);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
    local_8 = 0xffffffff;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  } while (uVar3 == 0);
  if (uVar3 == 1) {
    uVar3 = 0;
  }
  return uVar3;
}



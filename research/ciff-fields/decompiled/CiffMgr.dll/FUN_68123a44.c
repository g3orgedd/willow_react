// Source: CiffMgr.dll @ 68123a44; FUN_68123a44

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

ULONG __thiscall FUN_68123a44(void *this,SAFEARRAY *param_1,int *param_2,ULONG param_3)

{
  int *piVar1;
  ULONG UVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  DWORD DVar6;
  DWORD DVar7;
  SAFEARRAY *pSVar8;
  _union_2683 local_34;
  int *local_24;
  IUnknown local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x68123a50;
  piVar1 = (int *)GetTickCount();
  local_1c = (int *)0x0;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_24 = piVar1;
  UVar2 = (**(code **)(*(int *)*param_2 + 0x44))((int *)*param_2,&local_1c);
  if (-1 < (int)UVar2) {
    if (local_1c != (int *)0x0) {
      local_20.lpVtbl = (IUnknownVtbl *)0x0;
      local_8._0_1_ = 1;
      iVar3 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_InternalName_68160020,&local_20);
      if ((-1 < iVar3) && (local_20.lpVtbl != (IUnknownVtbl *)0x0)) {
        FUN_68132710((uint *)&local_34,0,0x10);
        VariantInit((VARIANTARG *)&local_34.n2);
        local_8._0_1_ = 2;
        (**(code **)((local_20.lpVtbl)->QueryInterface + 0x20))(local_20.lpVtbl,&local_34);
        if (local_34.n2.vt == 8) {
          (**(code **)(**(int **)param_1 + 0x60))(*(int **)param_1,local_34._8_4_);
        }
        VariantClear((VARIANTARG *)&local_34.n2);
      }
      pSVar8 = param_1;
      CComQIPtr<>(&local_18,*(undefined4 **)param_1);
      if (local_18 != (int *)0x0) {
        local_14[0] = (int *)0x0;
        local_8._0_1_ = 4;
        iVar3 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_Version_681600f4,local_14);
        if ((iVar3 == 0) && (local_14[0] != (int *)0x0)) {
          FUN_68132710((uint *)&local_34,0,0x10);
          VariantInit((VARIANTARG *)&local_34.n2);
          local_8._0_1_ = 5;
          (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_34);
          piVar1 = local_18;
          if (local_34.n2.vt == 8) {
            iVar3 = *local_18;
            iVar4 = FUN_6812f116((ushort *)local_34._8_4_);
            (**(code **)(iVar3 + 0xd4))(piVar1,iVar4);
            pSVar8 = param_1;
          }
          else {
            (**(code **)(*local_18 + 0xd4))(local_18,1);
          }
          VariantClear((VARIANTARG *)&local_34.n2);
        }
        else {
          (**(code **)(*local_18 + 0xd4))(local_18,1);
        }
        local_8._0_1_ = 3;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      }
      local_14[0] = (int *)0x0;
      local_8._0_1_ = 6;
      UVar2 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_Temporary_681600a8,local_14);
      if ((UVar2 == 0) && (local_14[0] != (int *)0x0)) {
        FUN_68132710((uint *)&local_34,0,0x10);
        VariantInit((VARIANTARG *)&local_34.n2);
        local_8._0_1_ = 7;
        UVar2 = (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_34);
        if (local_34.n2.vt == 8) {
          piVar1 = *(int **)pSVar8;
          iVar3 = *piVar1;
          uVar5 = FUN_6812e988((wchar_t *)local_34._8_4_);
          UVar2 = (**(code **)(iVar3 + 0xa0))(piVar1,uVar5);
        }
        VariantClear((VARIANTARG *)&local_34.n2);
      }
      local_8._0_1_ = 3;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      local_8._0_1_ = 1;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
      local_8._0_1_ = 0;
      piVar1 = local_24;
      if (local_20.lpVtbl != (IUnknownVtbl *)0x0) {
        (**(code **)((local_20.lpVtbl)->QueryInterface + 8))(local_20.lpVtbl);
        piVar1 = local_24;
      }
    }
    if (-1 < (int)UVar2) {
      local_20.lpVtbl = (IUnknownVtbl *)0x0;
      local_8._0_1_ = 8;
      UVar2 = (**(code **)(*(int *)*param_2 + 0x94))
                        ((int *)*param_2,PTR_u_Header_6815fc40,&local_20);
      if (UVar2 == 0) {
        if (local_20.lpVtbl != (IUnknownVtbl *)0x0) {
          UVar2 = FUN_6811eef8((int *)param_1,&local_20);
          local_8._0_1_ = 0;
          if (local_20.lpVtbl != (IUnknownVtbl *)0x0) {
            (**(code **)((local_20.lpVtbl)->QueryInterface + 8))(local_20.lpVtbl);
          }
          goto LAB_68123cd1;
        }
LAB_68123f99:
        UVar2 = 0x80030104;
      }
      else if ((UVar2 == 1) || (local_20.lpVtbl == (IUnknownVtbl *)0x0)) goto LAB_68123f99;
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_20.lpVtbl != (IUnknownVtbl *)0x0) {
        (**(code **)((local_20.lpVtbl)->QueryInterface + 8))(local_20.lpVtbl);
      }
      goto LAB_68123f75;
    }
  }
LAB_68123cd1:
  DVar6 = GetTickCount();
  *(DWORD *)((int)this + 0xb18) = DVar6 - (int)piVar1;
  DVar6 = GetTickCount();
  if (-1 < (int)UVar2) {
    local_18 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,9);
    UVar2 = (**(code **)(*(int *)*param_2 + 0x90))
                      ((int *)*param_2,PTR_u_SubImage_6815fc44,&local_18);
    if ((-1 < (int)UVar2) && (local_18 != (int *)0x0)) {
      UVar2 = FUN_68122545(this,(int *)param_1,&local_18);
    }
    local_8._0_1_ = 0;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))(local_18);
    }
  }
  DVar7 = GetTickCount();
  *(DWORD *)((int)this + 0xb1c) = DVar7 - DVar6;
  DVar6 = GetTickCount();
  if (-1 < (int)UVar2) {
    local_20.lpVtbl = (IUnknownVtbl *)0x0;
    local_8._0_1_ = 10;
    UVar2 = (**(code **)(*(int *)*param_2 + 0x94))
                      ((int *)*param_2,PTR_u_GenericSettings_6815fc48,&local_20);
    if ((UVar2 == 0) && (local_20.lpVtbl != (IUnknownVtbl *)0x0)) {
      local_18 = (int *)0x0;
      local_8._0_1_ = 0xb;
      UVar2 = (**(code **)((local_20.lpVtbl)->QueryInterface + 0x30))(local_20.lpVtbl,&local_18);
      if ((UVar2 == 0) && (local_18 != (int *)0x0)) {
        FUN_68132710((uint *)&local_34,0,0x10);
        VariantInit((VARIANTARG *)&local_34.n2);
        local_8._0_1_ = 0xc;
        UVar2 = (**(code **)(**(int **)param_1 + 0x80))(*(int **)param_1,&local_34);
        if ((-1 < (int)UVar2) && (local_34.n2.vt == 9)) {
          CComQIPtr<>(&local_24,(undefined4 *)local_34._8_4_);
          local_8._0_1_ = 0xd;
          UVar2 = FUN_6811e4ae(this,param_1,local_24,&local_18);
          local_8._0_1_ = 0xc;
          if (local_24 != (int *)0x0) {
            (**(code **)(*local_24 + 8))(local_24);
          }
        }
        VariantClear((VARIANTARG *)&local_34.n2);
      }
      local_8._0_1_ = 10;
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 8))(local_18);
      }
    }
    local_8._0_1_ = 0;
    if (local_20.lpVtbl != (IUnknownVtbl *)0x0) {
      (**(code **)((local_20.lpVtbl)->QueryInterface + 8))(local_20.lpVtbl);
    }
  }
  DVar7 = GetTickCount();
  *(DWORD *)((int)this + 0xb20) = DVar7 - DVar6;
  DVar6 = GetTickCount();
  if (-1 < (int)UVar2) {
    local_20.lpVtbl = (IUnknownVtbl *)0x0;
    local_8._0_1_ = 0xe;
    UVar2 = (**(code **)(*(int *)*param_2 + 0x94))
                      ((int *)*param_2,PTR_u_Embedded_6815feb4,&local_20);
    if ((UVar2 == 0) && (local_20.lpVtbl != (IUnknownVtbl *)0x0)) {
      param_2 = (int *)0x0;
      local_8._0_1_ = 0xf;
      UVar2 = (**(code **)((local_20.lpVtbl)->QueryInterface + 0x30))(local_20.lpVtbl,&param_2);
      if ((UVar2 == 0) && (param_2 != (int *)0x0)) {
        FUN_68132710((uint *)&local_34,0,0x10);
        VariantInit((VARIANTARG *)&local_34.n2);
        local_8._0_1_ = 0x10;
        UVar2 = (**(code **)(**(int **)param_1 + 0xac))(*(int **)param_1,&local_34);
        if ((-1 < (int)UVar2) && (local_34.n2.vt == 9)) {
          CComQIPtr<>(&param_1,(undefined4 *)local_34._8_4_);
          local_8._0_1_ = 0x11;
          UVar2 = FUN_6811d8ed(this,param_1,(int *)&param_2,param_3);
          local_8._0_1_ = 0x10;
          if (param_1 != (SAFEARRAY *)0x0) {
            (**(code **)(*(int *)param_1 + 8))(param_1);
          }
        }
        VariantClear((VARIANTARG *)&local_34.n2);
      }
      local_8._0_1_ = 0xe;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    local_8._0_1_ = 0;
    if (local_20.lpVtbl != (IUnknownVtbl *)0x0) {
      (**(code **)((local_20.lpVtbl)->QueryInterface + 8))(local_20.lpVtbl);
    }
  }
  DVar7 = GetTickCount();
  *(DWORD *)((int)this + 0xb24) = DVar7 - DVar6;
  if (UVar2 == 1) {
    UVar2 = 0;
  }
LAB_68123f75:
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return UVar2;
}



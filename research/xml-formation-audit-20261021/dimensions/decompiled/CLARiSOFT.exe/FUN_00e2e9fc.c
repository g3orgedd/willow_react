// Source: CLARiSOFT.exe @ 00e2e9fc; FUN_00e2e9fc

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_00e2e9fc(void *this,void *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  UINT UVar6;
  HRESULT HVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  bool bVar12;
  VARIANTARG local_ac;
  VARIANTARG local_9c;
  int local_8c;
  VARIANTARG local_88;
  int *local_78;
  BSTR local_74;
  int local_70;
  int *local_6c;
  int local_68;
  int *local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  BSTR local_50;
  int *local_4c;
  int local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  uint local_38;
  BSTR local_34;
  int *local_30;
  int *local_2c;
  char local_25;
  int local_24;
  BSTR local_20;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x9c;
  local_8 = 0xe2ea0b;
  if (param_1 == (void *)0x0) goto LAB_00e2f029;
  piVar2 = (int *)FUN_00e77808((void *)((int)this + 4),0);
  if (*piVar2 == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = *piVar2 + -100;
  }
  if (iVar10 == 0) goto LAB_00e2f029;
  iVar3 = FUN_00e61ea6((int)param_1);
  if (iVar3 == 3) {
    FUN_00e2bd07(this,(int)param_1);
    goto LAB_00e2f029;
  }
  iVar3 = FUN_00e61ea6((int)param_1);
  if (iVar3 == 2) {
    FUN_00e2bb58(this,(int)param_1);
    goto LAB_00e2f029;
  }
  iVar3 = FUN_00e61ea6((int)param_1);
  if (iVar3 != 1) goto LAB_00e2f029;
  CComQIPtr<>(&local_2c,*(undefined4 **)((int)param_1 + 4));
  local_70 = 0;
  local_8 = 0;
  (**(code **)(*local_2c + 0xb0))(local_2c,&local_70);
  local_54 = 1;
  CComQIPtr<>(&local_64,local_2c);
  local_8._0_1_ = 1;
  if (local_64 != (int *)0x0) {
    (**(code **)(*local_64 + 0x168))(local_64,&local_54);
  }
  local_50 = (BSTR)0x0;
  local_8._0_1_ = 2;
  (**(code **)(*local_2c + 0xa8))(local_2c,&local_50);
  iVar3 = FUN_00e3e85d(iVar10);
  bVar1 = FUN_00e66fde(*(int *)(*(int *)((int)this + 400) + iVar3 * 4));
  if (bVar1) {
    FUN_00eae6d1(&local_30);
    local_5c = local_70 / local_54;
    local_38 = 0;
    local_68 = 0;
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00e61ccc(param_1,&local_24,'\x01');
    local_60 = local_24;
    local_34 = local_20;
    iVar3 = FUN_00e61ed8((int)param_1);
    if (iVar3 != 1) {
      piVar2 = *(int **)((int)this + 0x160);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      FUN_00eaeae0(local_60,1.4013e-45,piVar2);
      piVar2 = *(int **)((int)this + 0x160);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      local_34 = (BSTR)FUN_00eaeae0((int)local_34,0.0,piVar2);
    }
    (**(code **)(**(int **)((int)this + 0x15c) + 0x2c))(*(int **)((int)this + 0x15c),&local_38);
    (**(code **)(**(int **)((int)this + 0x15c) + 0x34))(*(int **)((int)this + 0x15c),&local_68);
    local_40 = 0;
    (**(code **)(**(int **)((int)this + 0x15c) + 0x24))(*(int **)((int)this + 0x15c),&local_40);
    local_3c = (int *)FUN_00e34198((float)local_5c / (float)local_68);
    iVar3 = FUN_00e35299(this,(int)local_34);
    iVar4 = local_40 / local_68;
    if (iVar4 == 1) {
      if (iVar3 < 2) {
LAB_00e2ec26:
        local_8._0_1_ = 2;
        FUN_00eae7b2(&local_30);
        goto LAB_00e2ec32;
      }
    }
    else if (iVar4 == 2) {
      if ((local_3c != (int *)0x2) || (iVar3 != 2)) {
        bVar12 = SBORROW4(iVar3,2);
        iVar4 = iVar3 + -2;
        bVar1 = iVar4 == 0;
LAB_00e2ec20:
        if (bVar1 || bVar12 != iVar4 < 0) goto LAB_00e2ec26;
      }
    }
    else {
      if (iVar4 != 3) goto LAB_00e2ec26;
      if (((local_3c != (int *)0x3) || (iVar3 == 1)) && ((local_3c != (int *)0x2 || (iVar3 != 3))))
      {
        bVar12 = SBORROW4(iVar3,3);
        iVar4 = iVar3 + -3;
        bVar1 = iVar3 == 3;
        goto LAB_00e2ec20;
      }
    }
    iVar10 = FUN_00e3e85d(iVar10);
    FUN_00e67029(*(void **)(*(int *)((int)this + 400) + iVar10 * 4),param_1,1);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00eae7b2(&local_30);
  }
  else {
LAB_00e2ec32:
    local_40 = 0;
    piVar2 = (int *)FUN_00e68516((int *)0x0,(int *)0x0);
    local_25 = '\0';
    local_44 = piVar2;
    FUN_00e03b51((uint *)&local_9c);
    local_8._0_1_ = 5;
    (**(code **)(**(int **)((int)this + 0x15c) + 0x7c))(*(int **)((int)this + 0x15c),&local_9c);
    CComQIPtr<>(&local_6c,(undefined4 *)local_9c.n1._8_4_);
    local_8 = CONCAT31(local_8._1_3_,6);
    (**(code **)(*local_6c + 0x24))(local_6c,&local_58);
    if (0 < local_58) {
      iVar10 = 0;
      if (0 < local_58) {
        do {
          FUN_00e03b51((uint *)&local_88);
          iVar10 = iVar10 + 1;
          local_8._0_1_ = 7;
          (**(code **)(*local_6c + 0x20))(local_6c,iVar10,&local_88);
          CComQIPtr<>(&local_30,(undefined4 *)local_88.n1._8_4_);
          local_8._0_1_ = 8;
          (**(code **)(*local_30 + 0x2c))(local_30,&local_38);
          FUN_00e4aee3(&local_44,piVar2,&local_38);
          local_8._0_1_ = 7;
          if (local_30 != (int *)0x0) {
            (**(code **)(*local_30 + 8))(local_30);
          }
          local_8 = CONCAT31(local_8._1_3_,6);
          VariantClear(&local_88);
          piVar2 = local_44;
        } while (iVar10 < local_58);
      }
      local_38 = local_38 & 0xffffff00;
      FUN_00e27ee6(&local_44);
      local_30 = (int *)0x0;
      puVar11 = (undefined4 *)*local_44;
      iVar10 = local_48;
      if (0 < local_58) {
        iVar4 = local_70 / local_54;
        iVar3 = local_48;
        do {
          iVar10 = puVar11[2];
          puVar11 = (undefined4 *)*puVar11;
          if (iVar10 == iVar4) break;
          if (local_25 == '\0') {
            if (iVar4 < iVar10) break;
LAB_00e2edab:
            local_25 = '\x01';
            iVar9 = iVar4 - iVar10;
          }
          else {
            if (iVar10 <= iVar4) goto LAB_00e2edab;
            iVar9 = iVar10 - iVar4;
            if (iVar3 <= iVar9) {
              iVar10 = iVar4 - iVar3;
              break;
            }
          }
          local_30 = (int *)((int)local_30 + 1);
          iVar3 = iVar9;
        } while ((int)local_30 < local_58);
      }
      FUN_00e03b51((uint *)&local_ac);
      local_8._0_1_ = 9;
      (**(code **)(**(int **)((int)this + 0x160) + 0x474))(*(int **)((int)this + 0x160),&local_ac);
      CComQIPtr<>(&local_3c,(undefined4 *)local_ac.n1._8_4_);
      local_8 = CONCAT31(local_8._1_3_,10);
      uVar5 = (**(code **)(*local_3c + 0x24))(local_3c,&local_60);
      local_30 = (int *)(uVar5 & 0xffffff00);
      uVar5 = 0;
      if (0 < local_60) {
        do {
          if ((char)local_30 != '\0') break;
          FUN_00e03b51((uint *)&local_88);
          uVar5 = uVar5 + 1;
          local_8._0_1_ = 0xb;
          local_38 = uVar5;
          (**(code **)(*local_3c + 0x20))(local_3c,uVar5,&local_88);
          CComQIPtr<>(&local_4c,(undefined4 *)local_88.n1._8_4_);
          local_8._0_1_ = 0xc;
          (**(code **)(*local_4c + 0x3c))(local_4c,&local_8c);
          if (local_8c == iVar10) {
            FUN_00e0e8d9(&local_5c);
            local_34 = (BSTR)0x0;
            local_8 = CONCAT31(local_8._1_3_,0xe);
            (**(code **)(*local_4c + 0x1c))(local_4c,&local_34);
            UVar6 = SysStringLen(local_50);
            if (UVar6 != 0) {
              HVar7 = VarBstrCmp(local_34,local_50,0x400,0);
              local_30 = (int *)CONCAT31((int3)((uint)-(HVar7 + -1) >> 8),'\x01' - (HVar7 + -1 != 0)
                                        );
            }
            local_74 = (BSTR)0x0;
            local_8._0_1_ = 0xf;
            (**(code **)(*local_4c + 0x24))(local_4c,&local_74);
            (**(code **)(*local_4c + 0x3c))(local_4c,&local_48);
            (**(code **)(*local_2c + 0xac))(local_2c,local_34);
            piVar2 = local_2c;
            iVar3 = *local_2c;
            uVar8 = FUN_00e10203(&local_74);
            (**(code **)(iVar3 + 0x100))(piVar2,uVar8);
            (**(code **)(*local_2c + 0xb4))(local_2c,local_48 * local_54);
            CComQIPtr<>(&local_78,local_2c);
            local_8._0_1_ = 0x10;
            if (local_78 != (int *)0x0) {
              (**(code **)(*local_78 + 0x16c))(local_78,local_54);
            }
            (**(code **)(*local_2c + 0xbc))(local_2c,100);
            (**(code **)(*local_2c + 0x120))(local_2c,100);
            local_8._0_1_ = 0xf;
            if (local_78 != (int *)0x0) {
              (**(code **)(*local_78 + 8))(local_78);
            }
            SysFreeString(local_74);
            SysFreeString(local_34);
            local_8._0_1_ = 0xc;
            FUN_00e0e9b5(&local_5c);
            uVar5 = local_38;
          }
          local_8 = CONCAT31(local_8._1_3_,0xb);
          if (local_4c != (int *)0x0) {
            (**(code **)(*local_4c + 8))(local_4c);
          }
          VariantClear(&local_88);
        } while ((int)uVar5 < local_60);
      }
      local_8 = CONCAT31(local_8._1_3_,9);
      if (local_3c != (int *)0x0) {
        (**(code **)(*local_3c + 8))(local_3c);
      }
      VariantClear(&local_ac);
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if (local_6c != (int *)0x0) {
      (**(code **)(*local_6c + 8))(local_6c);
    }
    VariantClear(&local_9c);
    FUN_00e384b8((int *)&local_44);
    FID_conflict__free(local_44);
  }
  SysFreeString(local_50);
  local_8 = local_8 & 0xffffff00;
  if (local_64 != (int *)0x0) {
    (**(code **)(*local_64 + 8))(local_64);
  }
  local_8 = 0xffffffff;
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
  }
LAB_00e2f029:
  FUN_00ec9e3c();
  return;
}



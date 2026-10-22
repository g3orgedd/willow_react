// Source: CLCSTextBasedField.dll @ 42426819; FUN_42426819

int FUN_42426819(void *self,void *position,VARIANTARG ciffFile,VARIANTARG coderCapabilities,
                VARIANTARG field)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  BSTR extraout_ECX;
  int *piVar5;
  int iVar7;
  undefined4 in_stack_0000003c;
  undefined4 *in_stack_00000040;
  undefined4 in_stack_00000044;
  BSTR pOVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int *piVar12;
  VARIANTARG local_b4;
  float local_a4;
  _union_2683 local_a0;
  int local_90;
  int local_8c;
  float local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  uint local_64;
  int *local_60;
  int local_5c;
  undefined4 local_58;
  int local_54 [2];
  int local_4c;
  int local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  BSTR local_34;
  BSTR local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  uint uVar6;
  
  CComQIPtr<>(&local_44,(undefined4 *)coderCapabilities.n1.decVal.Hi32);
  CComQIPtr<>(&local_60,(undefined4 *)field.n1.decVal.Hi32);
  piVar3 = local_60;
  local_14 = local_60;
  if (local_60 != (int *)0x0) {
    (**(code **)(*local_60 + 4))();
  }
  CComQIPtr<>(&local_8,in_stack_00000040);
  local_64 = 1;
  local_1c = 1;
  CComQIPtr<>(&local_24,local_8);
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 0x168))();
  }
  local_3c = 0;
  (**(code **)(*local_8 + 0x80))();
  local_2c = 0;
  (**(code **)(*local_8 + 0x78))();
  local_74 = 0;
  (**(code **)(*local_8 + 0x124))();
  local_30 = (BSTR)0x0;
  (**(code **)(*local_8 + 0xa8))();
  FUN_42403802((uint *)&local_b4);
  (**(code **)(*piVar3 + 0x474))();
  CComQIPtr<>(&local_18,(undefined4 *)local_b4.n1._8_4_);
  FUN_42403802((uint *)&local_a0);
  (**(code **)(*local_18 + 0x30))();
  local_34 = (BSTR)0x0;
  if ((local_a0.n2.vt == 0) ||
     (CComQIPtr<>(&local_c,(undefined4 *)local_a0._8_4_), local_c == (int *)0x0)) {
LAB_42426c5f:
    FUN_42458671(&local_70);
    (**(code **)(*local_8 + 0x80))();
    (**(code **)(*local_44 + 0x54))();
    iVar7 = local_20;
    if (local_78 == 0) {
      (**(code **)(*piVar3 + 4))();
      local_20 = FUN_424589da(local_20,0.0,piVar3);
    }
    else {
      (**(code **)(*piVar3 + 4))();
      iVar7 = FUN_42458843(local_20,0.0,piVar3);
    }
    iVar2 = local_20;
    if (local_20 < 2) {
      iVar2 = 2;
    }
    piVar3 = (int *)((iVar7 * 0x48) / 0x9ec);
    local_20 = iVar2;
    (**(code **)(*local_8 + 0xbc))(local_8,100);
    if ((int)piVar3 < 1) {
      piVar3 = (int *)0x1;
    }
    local_c = piVar3;
    (**(code **)(*local_8 + 0xb4))(local_8,(int)piVar3 * local_1c);
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 0x16c))(local_24,local_1c);
    }
    (**(code **)(*(int *)self + 0x30))
              (self,&local_4c,field.n1._12_4_,in_stack_0000003c,in_stack_00000040,in_stack_00000044,
               coderCapabilities.n1._12_4_,field.n1._0_4_,field.n1.decVal.Hi32,field.n1._8_4_,
               ciffFile.n1._12_4_,coderCapabilities.n1._0_4_,coderCapabilities.n1.decVal.Hi32,
               coderCapabilities.n1._8_4_);
    if (iVar2 <= local_48) {
      local_64 = 0;
    }
    cVar4 = iVar2 > local_48;
    local_28 = local_48;
    local_10 = (int *)(iVar2 - local_48);
    if (-1 < (int)local_10) goto LAB_42426df1;
    piVar3 = (int *)-(int)local_10;
    uVar6 = (uint)(byte)cVar4;
    do {
      cVar4 = (char)uVar6;
      local_28 = local_48;
      local_10 = piVar3;
LAB_42426df1:
      if (local_28 == iVar2) break;
      if (cVar4 == '\x01') {
        local_c = (int *)((int)local_c + 1);
      }
      else {
        local_c = (int *)((int)local_c + -1);
      }
      local_48 = local_28;
      (**(code **)(*local_8 + 0xb4))(local_8,(int)local_c * local_1c);
      if (local_24 != (int *)0x0) {
        (**(code **)(*local_24 + 0x16c))(local_24,local_1c);
      }
      (**(code **)(*(int *)self + 0x30))
                (self,&local_4c,field.n1._12_4_,in_stack_0000003c,in_stack_00000040,
                 in_stack_00000044,coderCapabilities.n1._12_4_,field.n1._0_4_,field.n1.decVal.Hi32,
                 field.n1._8_4_,ciffFile.n1._12_4_,coderCapabilities.n1._0_4_,
                 coderCapabilities.n1.decVal.Hi32,coderCapabilities.n1._8_4_);
      piVar3 = (int *)(iVar2 - local_48);
      if ((int)piVar3 < 0) {
        piVar3 = (int *)-(int)piVar3;
      }
      uVar6 = local_64;
    } while ((int)piVar3 < (int)local_10);
    piVar3 = local_14;
    local_48 = local_28;
    if (local_78 == 0) {
      piVar5 = local_14;
      (**(code **)(*local_14 + 4))(local_14);
      FUN_424587c9(&local_4c,piVar5);
    }
    (**(code **)(*local_8 + 0x84))(local_8,local_48);
    (**(code **)(*local_8 + 0x78))(local_8,&local_8c);
    (**(code **)(*piVar3 + 0x2c))(piVar3,&local_88);
    (**(code **)(*piVar3 + 0x34))(piVar3,&local_a4);
    local_40 = -1;
    local_38 = -1;
    iVar7 = (int)((float)(local_8c * 100) / ((float)local_4c * (local_88 / local_a4)));
    if (local_a0.n2.vt != 0) {
      CComQIPtr<>(&self,(undefined4 *)local_a0._8_4_);
      if (self != (void *)0x0) {
        (**(code **)(*(int *)self + 0xcc))(self,&local_38);
        (**(code **)(*(int *)self + 0xd4))(self,&local_40);
        if (self != (void *)0x0) {
          (**(code **)(*(int *)self + 8))(self);
        }
      }
      if ((-1 < local_38) && (iVar7 < local_38)) {
        iVar7 = local_38;
      }
      if ((-1 < local_40) && (local_40 < iVar7)) {
        iVar7 = local_40;
      }
    }
    (**(code **)(*local_8 + 0xbc))(local_8,iVar7);
    FUN_42458752(&local_70);
  }
  else {
    local_7c = 0;
    (**(code **)(*local_c + 0x9c))();
    bVar1 = FUN_42403bfa(&local_34,L"ZFBF");
    if (bVar1) {
      (**(code **)(*local_c + 0xfc))();
    }
    if (local_7c == 0) {
      bVar1 = FUN_42403bfa(&local_34,L"FixedBitmap");
      if ((!bVar1) && (local_74 != 2)) {
        pOVar8 = extraout_ECX;
        uVar9 = coderCapabilities.n1._12_4_;
        uVar10 = field.n1._0_4_;
        uVar11 = field.n1.decVal.Hi32;
        FUN_42403768(&stack0xfffffef8,(int *)&local_30);
        bVar1 = FUN_42425abf((void *)((int)self + -8),pOVar8,uVar9,uVar10,(IUnknown *)uVar11);
        piVar3 = local_14;
        if (!bVar1) goto LAB_42426b9c;
      }
      piVar3 = local_c;
      if (local_c != (int *)0x0) {
        local_c = (int *)0x0;
        (**(code **)(*piVar3 + 8))();
      }
      piVar5 = local_18;
      piVar3 = local_14;
      if (local_18 != (int *)0x0) {
        local_18 = (int *)0x0;
        (**(code **)(*piVar5 + 8))();
        piVar3 = local_14;
      }
    }
    else {
      (**(code **)(*(int *)self + 0x30))
                (self,&local_84,field.n1._12_4_,in_stack_0000003c,in_stack_00000040,
                 in_stack_00000044,coderCapabilities.n1._12_4_,field.n1._0_4_,field.n1.decVal.Hi32);
      (**(code **)(*local_c + 0x3c))(local_c,local_54);
      iVar2 = local_2c;
      iVar7 = local_3c;
      (**(code **)(*local_44 + 0x54))(local_44,&local_90);
      piVar3 = local_14;
      if (local_90 == 0) {
        FUN_42458671(&local_58);
        piVar3 = local_14;
        piVar5 = local_14;
        piVar12 = local_14;
        (**(code **)(*local_14 + 4))();
        iVar2 = FUN_424589da(iVar2,0.0,piVar5);
        (**(code **)(*piVar3 + 4))();
        iVar7 = FUN_424589da(iVar7,0.0,piVar12);
        FUN_42458752(&local_58);
      }
      if ((local_84 < 1) || (local_80 < 1)) {
LAB_42426b9c:
        local_28 = -1;
        local_6c = -1;
        CComQIPtr<>(&local_10,(undefined4 *)local_a0._8_4_);
        if (local_10 != (int *)0x0) {
          (**(code **)(*local_10 + 0xcc))();
          (**(code **)(*local_10 + 0xd4))();
        }
        local_68 = -1;
        local_5c = -1;
        (**(code **)(*local_10 + 0x6c))();
        (**(code **)(*local_10 + 0x74))();
        piVar5 = local_10;
        if (((local_68 != local_5c) || (local_28 != local_6c)) || ((local_68 < 1 && (local_6c < 1)))
           ) {
          if (local_10 != (int *)0x0) {
            (**(code **)(*local_10 + 8))();
          }
          piVar3 = local_14;
          if (local_c != (int *)0x0) {
            (**(code **)(*local_c + 8))();
            piVar3 = local_14;
          }
          goto LAB_42426c5f;
        }
        if (local_10 != (int *)0x0) {
          local_10 = (int *)0x0;
          (**(code **)(*piVar5 + 8))();
        }
        piVar5 = local_18;
        if (local_18 != (int *)0x0) {
          local_18 = (int *)0x0;
          (**(code **)(*piVar5 + 8))();
        }
        piVar5 = local_10;
        if (local_10 != (int *)0x0) goto LAB_42426b8a;
      }
      else {
        self = (void *)((float)iVar2 / (float)local_84);
        if ((float)iVar7 / (float)local_80 <= (float)iVar2 / (float)local_84) {
          self = (void *)((float)iVar7 / (float)local_80);
        }
        local_54[0] = (int)((float)local_54[0] * (float)self + DAT_424983e0);
        (**(code **)(*local_8 + 0xb4))();
        if (local_24 != (int *)0x0) {
          (**(code **)(*local_24 + 0x16c))();
        }
        local_2c = (int)((float)local_2c * (float)self + DAT_424983e0);
        (**(code **)(*local_8 + 0x7c))();
        local_3c = (int)((float)local_3c * (float)self + DAT_424983e0);
        (**(code **)(*local_8 + 0x84))(local_8);
        piVar5 = local_c;
        if (local_c != (int *)0x0) {
          local_c = (int *)0x0;
          (**(code **)(*piVar5 + 8))();
        }
        piVar5 = local_18;
        if (local_18 != (int *)0x0) {
          local_18 = (int *)0x0;
LAB_42426b8a:
          (**(code **)(*piVar5 + 8))();
        }
      }
    }
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))();
    }
  }
  SysFreeString(local_34);
  VariantClear((VARIANTARG *)&local_a0.n2);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  VariantClear(&local_b4);
  SysFreeString(local_30);
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))();
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))();
  }
  (**(code **)(*piVar3 + 8))();
  if (local_60 != (int *)0x0) {
    (**(code **)(*local_60 + 8))();
  }
  if (local_44 != (int *)0x0) {
    (**(code **)(*local_44 + 8))();
  }
  return 0;
}



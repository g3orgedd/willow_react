// Source: CLPrintPreview.ocx @ 3f413a63; FUN_3f413a63

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_3f413a63(void *this,undefined4 *param_1)

{
  HDC hdc;
  int iVar1;
  int iVar2;
  HGDIOBJ h;
  HGDIOBJ pvVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  _union_2683 local_7c;
  int local_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  HCURSOR local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  _union_2683 local_4c;
  int *local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  int *local_1c;
  char local_15;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  local_8._0_1_ = 0x6f;
  local_8._1_3_ = 0x3f413a;
  if ((*(int *)((int)this + 0xe0) != 0) && (*(int *)((int)this + 0x124) != 0)) {
    local_58 = 0;
    local_54 = 0;
    local_5c = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    FUN_3f4153c1(&local_5c);
    *(undefined4 *)((int)this + 0x1d4) = 0;
    local_8 = 0;
    (**(code **)(**(int **)((int)this + 0xe0) + 0x54))
              (*(int **)((int)this + 0xe0),(int)this + 0x130);
    local_30 = 0;
    (**(code **)(**(int **)((int)this + 0xe0) + 0x1c))(*(int **)((int)this + 0xe0),&local_30);
    FUN_3f4272e0((uint *)&local_7c,0,0x10);
    VariantInit((VARIANTARG *)&local_7c.n2);
    local_8._0_1_ = 1;
    iVar1 = (**(code **)(**(int **)((int)this + 0xe0) + 0x24))
                      (*(int **)((int)this + 0xe0),1,&local_7c);
    local_24 = (int *)0x0;
    local_2c = 0;
    if ((-1 < iVar1) && (local_7c.n2.vt == 9)) {
      CComQIPtr<>(&local_1c,(undefined4 *)local_7c._8_4_);
      local_8._0_1_ = 2;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 0x5c))(local_1c,&local_24);
        if (local_24 == (int *)0x0) {
          (**(code **)(*local_1c + 0x3c))(local_1c,&local_24);
        }
        (**(code **)(*local_1c + 100))(local_1c,&local_2c);
        if (local_2c == 0) {
          (**(code **)(*local_1c + 0x44))(local_1c,&local_2c);
        }
      }
      local_8._0_1_ = 1;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
    iVar1 = 1;
    if (1 < local_30) {
      do {
        FUN_3f4272e0((uint *)&local_4c,0,0x10);
        VariantInit((VARIANTARG *)&local_4c.n2);
        iVar1 = iVar1 + 1;
        local_8._0_1_ = 3;
        iVar2 = (**(code **)(**(int **)((int)this + 0xe0) + 0x24))
                          (*(int **)((int)this + 0xe0),iVar1,&local_4c);
        if ((-1 < iVar2) && (local_4c.n2.vt == 9)) {
          CComQIPtr<>(&local_28,(undefined4 *)local_4c._8_4_);
          local_8._0_1_ = 4;
          if (local_28 != (int *)0x0) {
            local_1c = (int *)0x0;
            (**(code **)(*local_28 + 0x5c))(local_28,&local_1c);
            if (local_1c == (int *)0x0) {
              (**(code **)(*local_28 + 0x3c))(local_28,&local_1c);
            }
            local_20 = 0;
            (**(code **)(*local_28 + 100))(local_28,&local_20);
            if (local_20 == 0) {
              (**(code **)(*local_28 + 0x44))(local_28,&local_20);
            }
            if ((int)local_24 < (int)local_1c) {
              local_24 = local_1c;
            }
            local_2c = local_2c + local_20;
          }
          local_8._0_1_ = 3;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
        }
        local_8._0_1_ = 1;
        VariantClear((VARIANTARG *)&local_4c.n2);
      } while (iVar1 < local_30);
    }
    piVar4 = (int *)((int)this + 0x144);
    (**(code **)(**(int **)((int)this + 0xe8) + 0x3c))(*(int **)((int)this + 0xe8),piVar4);
    piVar5 = (int *)((int)this + 0x148);
    *piVar5 = 0;
    local_50 = (**(code **)(**(int **)((int)this + 0x124) + 0x24))
                         (*(int **)((int)this + 0x124),piVar5);
    iVar1 = *piVar5;
    *piVar5 = iVar1 * local_30;
    if (iVar1 * local_30 == 0) {
      local_50 = (**(code **)(**(int **)((int)this + 0xe8) + 0x44))
                           (*(int **)((int)this + 0xe8),piVar5);
      *piVar5 = *piVar5 * local_30;
    }
    if (*(int *)((int)this + 0x1e4) == 0) {
      FUN_3f415273(this,(HDC)*param_1);
    }
    piVar6 = *(int **)((int)this + 0xe8);
    local_15 = '\0';
    if (piVar6 != (int *)0x0) {
      local_20 = 0;
      iVar1 = (**(code **)(*piVar6 + 0x41c))(piVar6,&local_20);
      if ((iVar1 < 0) || (local_15 = '\x01', local_20 == 0)) {
        local_15 = '\0';
      }
    }
    *(int **)((int)this + 0x14c) = local_24;
    *(int *)((int)this + 0x150) = local_2c;
    if (*(int *)((int)this + 0x130) == 1) {
      piVar4 = (int *)*piVar4;
      local_24 = (int *)(int)(((float)(int)local_24 * *(float *)((int)this + 0x13c)) /
                             *(float *)((int)this + 0x134));
      local_2c = (int)(((float)local_2c * *(float *)((int)this + 0x140)) /
                      *(float *)((int)this + 0x138));
      if ((piVar4 != (int *)0x0) && ((int)piVar4 <= (int)local_24)) {
        local_24 = piVar4;
      }
      iVar1 = *piVar5;
      if ((iVar1 != 0) && (iVar1 <= local_2c)) {
        local_2c = iVar1;
      }
      piVar5 = local_24;
      if ((piVar4 != (int *)0x0) && (piVar5 = piVar4, (int)local_24 < (int)piVar4)) {
        piVar5 = local_24;
      }
      *(int **)((int)this + 0x1b8) = piVar5;
      iVar2 = local_2c;
      if ((iVar1 != 0) && (iVar2 = iVar1, local_2c < iVar1)) {
        iVar2 = local_2c;
      }
      *(int *)((int)this + 0x1bc) = iVar2;
      *(int **)((int)this + 0x1b0) = local_24;
      *(int *)((int)this + 0x1b4) = local_2c;
    }
    else {
      FUN_3f402fa5(&local_34);
      piVar6 = *(int **)((int)this + 0xe8);
      local_8 = CONCAT31(local_8._1_3_,5);
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 4))(piVar6);
      }
      local_24 = (int *)FUN_3f403cfa((int)local_24,0.0,piVar6);
      piVar6 = *(int **)((int)this + 0xe8);
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 4))(piVar6);
      }
      local_2c = FUN_3f403cfa(local_2c,0.0,piVar6);
      local_20 = *piVar5;
      piVar4 = (int *)*piVar4;
      if ((int)local_24 < *(int *)((int)this + 0x144)) {
        piVar4 = local_24;
      }
      iVar1 = local_20;
      if (local_2c < local_20) {
        iVar1 = local_2c;
      }
      if ((*(int *)((int)this + 0x144) < (int)local_24) && (local_15 != '\0')) {
        piVar4 = local_24;
      }
      if ((local_20 < local_2c) && (local_15 != '\0')) {
        iVar1 = local_2c;
      }
      local_8._0_1_ = 1;
      if (*(int *)((int)this + 0x144) != 0) {
        local_24 = piVar4;
      }
      if (local_20 != 0) {
        local_2c = iVar1;
      }
      *(int **)((int)this + 0x1b8) = local_24;
      *(int *)((int)this + 0x1bc) = local_2c;
      *(int **)((int)this + 0x1b0) = local_24;
      *(int *)((int)this + 0x1b4) = local_2c;
      FUN_3f40335c(&local_34);
    }
    *(int *)((int)this + 0x1bc) = local_2c;
    *(int **)((int)this + 0x1b8) = local_24;
    FUN_3f417e69(this);
    FUN_3f4183f5((int)this);
    local_1c = (int *)0x0;
    local_6c = 0;
    iStack_68 = 0;
    iStack_64 = 0;
    iStack_60 = 0;
    FUN_3f412846(this,param_1,&local_6c);
    iVar1 = 0;
    if (0 < local_30) {
      do {
        FUN_3f4272e0((uint *)&local_4c,0,0x10);
        VariantInit((VARIANTARG *)&local_4c.n2);
        local_38 = iVar1 + 1;
        local_8._0_1_ = 6;
        iVar2 = (**(code **)(**(int **)((int)this + 0xe0) + 0x24))
                          (*(int **)((int)this + 0xe0),local_38,&local_4c);
        if ((-1 < iVar2) && (local_4c.n2.vt == 9)) {
          CComQIPtr<>(&local_28,(undefined4 *)local_4c._8_4_);
          local_34 = 0;
          CComQIPtr<>(&local_3c,local_28);
          local_8._0_1_ = 8;
          if (local_3c != (int *)0x0) {
            (**(code **)(*local_3c + 0xb4))(local_3c,&local_34);
          }
          local_8 = CONCAT31(local_8._1_3_,7);
          *(bool *)((int)this + 0x218) = local_34 == 1;
          if (local_3c != (int *)0x0) {
            (**(code **)(*local_3c + 8))(local_3c);
          }
          piVar4 = local_1c;
          if (0 < iVar1) {
            FUN_3f4139be(this,param_1,(int)local_1c);
          }
          FUN_3f4130f7(this,param_1,local_28,(int)piVar4);
          local_20 = 0;
          (**(code **)(*local_28 + 100))(local_28,&local_20);
          if (local_20 == 0) {
            (**(code **)(*local_28 + 0x44))(local_28,&local_20);
          }
          local_1c = (int *)((int)piVar4 + local_20);
          local_8._0_1_ = 6;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
        }
        local_8._0_1_ = 1;
        VariantClear((VARIANTARG *)&local_4c.n2);
        iVar1 = local_38;
      } while (local_38 < local_30);
    }
    h = SelectObject((HDC)*param_1,*(HGDIOBJ *)((int)this + 0x164));
    hdc = (HDC)*param_1;
    pvVar3 = GetStockObject(5);
    pvVar3 = SelectObject(hdc,pvVar3);
    Rectangle((HDC)*param_1,local_6c,iStack_68,iStack_64,iStack_60);
    SelectObject((HDC)*param_1,pvVar3);
    SelectObject((HDC)*param_1,h);
    VariantClear((VARIANTARG *)&local_7c.n2);
    FUN_3f4153a2((int)&local_5c);
  }
  FUN_3f42804e();
  return;
}



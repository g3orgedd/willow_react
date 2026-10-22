// Source: CLPrintPreview.ocx @ 3f412ce9; FUN_3f412ce9

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_3f412ce9(void *this,undefined4 *param_1)

{
  int *piVar1;
  HDC hdc;
  int iVar2;
  int *piVar3;
  HGDIOBJ h;
  HGDIOBJ pvVar4;
  int iVar5;
  int *piVar6;
  _union_2683 local_5c;
  int local_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  HCURSOR local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  char local_15;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8._0_1_ = 0xf5;
  local_8._1_3_ = 0x3f412c;
  if ((*(int *)((int)this + 0xe0) != 0) && (*(int *)((int)this + 0x124) != 0)) {
    local_38 = 0;
    local_34 = 0;
    local_3c = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    FUN_3f4153c1(&local_3c);
    *(undefined4 *)((int)this + 0x1d4) = 0;
    local_8 = 0;
    (**(code **)(**(int **)((int)this + 0xe0) + 0x54))
              (*(int **)((int)this + 0xe0),(int)this + 0x130);
    FUN_3f4272e0((uint *)&local_5c,0,0x10);
    VariantInit((VARIANTARG *)&local_5c.n2);
    local_8._0_1_ = 1;
    iVar2 = (**(code **)(**(int **)((int)this + 0xe0) + 0x30))
                      (*(int **)((int)this + 0xe0),*(undefined4 *)((int)this + 0x11c),&local_5c);
    if ((-1 < iVar2) && (local_5c.n2.vt == 9)) {
      CComQIPtr<>(&local_28,(undefined4 *)local_5c._8_4_);
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_28 == (int *)0x0) {
        FUN_3f41266f(this,(HDC)*param_1,L"Error - no sub-image");
      }
      else {
        local_1c = 0;
        (**(code **)(*local_28 + 0x5c))(local_28,&local_1c);
        if (local_1c == 0) {
          (**(code **)(*local_28 + 0x3c))(local_28,&local_1c);
        }
        local_24 = (int *)0x0;
        (**(code **)(*local_28 + 100))(local_28,&local_24);
        if (local_24 == (int *)0x0) {
          (**(code **)(*local_28 + 0x44))(local_28,&local_24);
        }
        piVar3 = (int *)((int)this + 0x144);
        (**(code **)(**(int **)((int)this + 0xe8) + 0x3c))(*(int **)((int)this + 0xe8),piVar3);
        piVar1 = (int *)((int)this + 0x148);
        *piVar1 = 0;
        local_30 = (**(code **)(**(int **)((int)this + 0x124) + 0x24))
                             (*(int **)((int)this + 0x124),piVar1);
        if (*piVar1 == 0) {
          local_30 = (**(code **)(**(int **)((int)this + 0xe8) + 0x44))
                               (*(int **)((int)this + 0xe8),piVar1);
        }
        if (*(int *)((int)this + 0x1e4) == 0) {
          FUN_3f415273(this,(HDC)*param_1);
        }
        piVar6 = *(int **)((int)this + 0xe8);
        local_15 = '\0';
        if (piVar6 != (int *)0x0) {
          local_20 = (int *)0x0;
          iVar2 = (**(code **)(*piVar6 + 0x41c))(piVar6,&local_20);
          if ((iVar2 < 0) || (local_15 = '\x01', local_20 == (int *)0x0)) {
            local_15 = '\0';
          }
        }
        if (*(int *)((int)this + 0x130) == 1) {
          iVar2 = *piVar3;
          local_1c = (int)(((float)local_1c * *(float *)((int)this + 0x13c)) /
                          *(float *)((int)this + 0x134));
          local_24 = (int *)(int)(((float)(int)local_24 * *(float *)((int)this + 0x140)) /
                                 *(float *)((int)this + 0x138));
          if ((iVar2 != 0) && (iVar2 <= local_1c)) {
            local_1c = iVar2;
          }
          piVar1 = (int *)*piVar1;
          if ((piVar1 != (int *)0x0) && ((int)piVar1 <= (int)local_24)) {
            local_24 = piVar1;
          }
          iVar5 = local_1c;
          if ((iVar2 != 0) && (iVar5 = iVar2, local_1c < iVar2)) {
            iVar5 = local_1c;
          }
          *(int *)((int)this + 0x1b8) = iVar5;
          piVar3 = local_24;
          if ((piVar1 != (int *)0x0) && (piVar3 = piVar1, (int)local_24 < (int)piVar1)) {
            piVar3 = local_24;
          }
          *(int **)((int)this + 0x1bc) = piVar3;
          *(int *)((int)this + 0x1b0) = local_1c;
          *(int **)((int)this + 0x1b4) = local_24;
        }
        else {
          FUN_3f402fa5(&local_2c);
          piVar6 = *(int **)((int)this + 0xe8);
          local_8 = CONCAT31(local_8._1_3_,3);
          if (piVar6 != (int *)0x0) {
            (**(code **)(*piVar6 + 4))(piVar6);
          }
          local_1c = FUN_3f403cfa(local_1c,0.0,piVar6);
          piVar6 = *(int **)((int)this + 0xe8);
          if (piVar6 != (int *)0x0) {
            (**(code **)(*piVar6 + 4))(piVar6);
          }
          local_24 = (int *)FUN_3f403cfa((int)local_24,0.0,piVar6);
          local_20 = (int *)*piVar1;
          iVar2 = *piVar3;
          if (local_1c < *(int *)((int)this + 0x144)) {
            iVar2 = local_1c;
          }
          piVar3 = local_20;
          if ((int)local_24 < (int)local_20) {
            piVar3 = local_24;
          }
          if ((*(int *)((int)this + 0x144) < local_1c) && (local_15 != '\0')) {
            iVar2 = local_1c;
          }
          if (((int)local_20 < (int)local_24) && (local_15 != '\0')) {
            piVar3 = local_24;
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          if (*(int *)((int)this + 0x144) != 0) {
            local_1c = iVar2;
          }
          if (local_20 != (int *)0x0) {
            local_24 = piVar3;
          }
          *(int *)((int)this + 0x1b8) = local_1c;
          *(int **)((int)this + 0x1bc) = local_24;
          *(int *)((int)this + 0x1b0) = local_1c;
          *(int **)((int)this + 0x1b4) = local_24;
          FUN_3f40335c(&local_2c);
        }
        *(int **)((int)this + 0x1bc) = local_24;
        *(int *)((int)this + 0x1b8) = local_1c;
        FUN_3f417e69(this);
        FUN_3f4183f5((int)this);
        local_2c = 0;
        CComQIPtr<>(&local_20,local_28);
        local_8._0_1_ = 4;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 0xb4))(local_20,&local_2c);
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        *(bool *)((int)this + 0x218) = local_2c == 1;
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
        }
        local_4c = 0;
        iStack_48 = 0;
        iStack_44 = 0;
        iStack_40 = 0;
        FUN_3f412846(this,param_1,&local_4c);
        FUN_3f4130f7(this,param_1,local_28,0);
        h = SelectObject((HDC)*param_1,*(HGDIOBJ *)((int)this + 0x164));
        hdc = (HDC)*param_1;
        pvVar4 = GetStockObject(5);
        pvVar4 = SelectObject(hdc,pvVar4);
        Rectangle((HDC)*param_1,local_4c,iStack_48,iStack_44,iStack_40);
        SelectObject((HDC)*param_1,pvVar4);
        SelectObject((HDC)*param_1,h);
      }
      local_8._0_1_ = 1;
      if (local_28 != (int *)0x0) {
        (**(code **)(*local_28 + 8))(local_28);
      }
    }
    VariantClear((VARIANTARG *)&local_5c.n2);
    FUN_3f4153a2((int)&local_3c);
  }
  FUN_3f42804e();
  return;
}



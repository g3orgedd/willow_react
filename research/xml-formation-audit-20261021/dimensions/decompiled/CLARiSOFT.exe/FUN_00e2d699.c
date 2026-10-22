// Source: CLARiSOFT.exe @ 00e2d699; FUN_00e2d699

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_00e2d699(void *this,undefined4 *param_1,char param_2)

{
  void *pvVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  void *pvVar10;
  void *pvVar11;
  BSTR pOVar12;
  int *piVar13;
  char cVar14;
  BSTR pOVar15;
  COLORREF CVar16;
  VARIANTARG *pVVar17;
  VARIANTARG local_c8;
  int local_b8;
  tagSIZE local_b4;
  int local_ac;
  undefined4 *local_a8;
  int local_a4;
  tagSIZE local_a0;
  tagSIZE local_98;
  tagSIZE local_90;
  int *local_88;
  tagSIZE local_84;
  tagSIZE local_7c;
  undefined4 *local_74;
  undefined4 local_70;
  tagSIZE local_6c;
  void *local_64;
  tagSIZE local_60;
  BSTR local_58;
  tagRECT local_54;
  tagRECT local_44;
  int local_34 [3];
  int local_28;
  tagPOINT local_24;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xbc;
  local_8 = 0xe2d6a8;
  local_a8 = param_1;
  local_64 = this;
  if ((*(int *)((int)this + 0x194) - *(int *)((int)this + 400) & 0xfffffffcU) != 0) {
    piVar4 = (int *)FUN_00e77808((void *)((int)this + 4),0);
    if (*piVar4 == 0) {
      local_58 = (BSTR)0x0;
    }
    else {
      local_58 = (BSTR)(*piVar4 + -100);
    }
    local_44.left = 0;
    local_44.top = 0;
    local_44.right = 0;
    local_44.bottom = 0;
    GetClipBox((HDC)*param_1,&local_44);
    local_54.left = local_44.left;
    local_54.top = local_44.top;
    local_54.right = local_44.right;
    local_54.bottom = local_44.bottom;
    InflateRect(&local_54,1,1);
    pvVar10 = local_64;
    local_8 = 0;
    if (param_2 == '\0') {
      FUN_00e33899(local_64,param_1);
    }
    if (*(char *)((int)pvVar10 + 0x88) != '\0') {
      FUN_00e03b51((uint *)&local_c8);
      piVar4 = *(int **)((int)pvVar10 + 0x19c);
      pVVar17 = &local_c8;
      local_8._0_1_ = 1;
      iVar7 = *piVar4;
      iVar5 = FUN_00e3e85d((int)local_58);
      (**(code **)(iVar7 + 0x24))(piVar4,iVar5 + 1,pVVar17);
      CComQIPtr<>(&local_88,(undefined4 *)local_c8.n1._8_4_);
      local_8._0_1_ = 2;
      (**(code **)(*local_88 + 0x5c))(local_88,&local_a4);
      (**(code **)(*local_88 + 100))(local_88,&local_ac);
      local_74 = (undefined4 *)0x0;
      CComQIPtr<>(&local_90.cy,local_88);
      local_8._0_1_ = 3;
      if ((int *)local_90.cy != (int *)0x0) {
        (**(code **)(*(int *)local_90.cy + 0xb4))(local_90.cy,&local_74);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      local_70 = CONCAT31(local_70._1_3_,local_74 == (undefined4 *)0x1);
      cVar3 = local_74 == (undefined4 *)0x1;
      if ((int *)local_90.cy != (int *)0x0) {
        (**(code **)(*(int *)local_90.cy + 8))(local_90.cy);
        cVar3 = (char)local_70;
      }
      pvVar10 = local_64;
      uVar6 = 0xffffff;
      if (cVar3 != '\0') {
        uVar6 = 0;
      }
      *(undefined4 *)((int)local_64 + 0x16c) = uVar6;
      (**(code **)(**(int **)((int)local_64 + 0x19c) + 0x54))
                (*(int **)((int)local_64 + 0x19c),&local_b8);
      pOVar12 = local_58;
      if (local_b8 == 0) {
        if (param_2 == '\0') {
          FUN_00e3e8f6(local_58,500,'\0');
          FUN_00e3e8f6(pOVar12,500,'\x01');
        }
        else {
          FUN_00e2f535((int)pvVar10,'\0');
          FUN_00e2f535((int)pvVar10,'\x01');
          pOVar12 = local_58;
        }
      }
      else if (param_2 == '\0') {
        FUN_00e3e82d(local_58,local_a4,'\0');
        FUN_00e3e82d(pOVar12,local_ac,'\x01');
      }
      local_24.x = 0;
      local_24.y = 0;
      local_1c = local_a4;
      local_18 = local_ac;
      FUN_00e3e6ed(pOVar12,&local_24,'\x01');
      local_1c = local_1c + 1;
      local_18 = local_18 + 1;
      iVar7 = FUN_00e3e85d((int)pOVar12);
      FUN_00e66fde(*(int *)(*(int *)((int)pvVar10 + 400) + iVar7 * 4));
      local_6c.cx = 0;
      local_6c.cy = 0;
      local_84.cx = 0;
      local_84.cy = 0;
      SetMapMode((HDC)*param_1,8);
      SetViewportExtEx((HDC)*param_1,1,1,&local_6c);
      SetWindowExtEx((HDC)*param_1,1,1,&local_84);
      pvVar10 = local_64;
      FUN_00e2de4e(local_64,param_1,local_24.x,local_24.y,local_1c,local_18,param_2);
      if (((char)local_70 == '\0') && (param_2 == '\0')) {
        bVar2 = FUN_00e2de18((int)pvVar10);
        pvVar11 = pvVar10;
        if (bVar2) {
          iVar5 = FUN_00e3e8f6(local_58,500,'\0');
          iVar7 = *(int *)((int)pvVar10 + 0x140);
          iVar8 = FUN_00e3e8f6(local_58,500,'\x01');
          pvVar11 = local_64;
          param_1 = local_a8;
          FUN_00e33906(local_64,local_a8,(iVar5 * iVar7) / 500,
                       (iVar8 * *(int *)((int)pvVar10 + 0x144)) / 500,
                       *(HGDIOBJ *)((int)local_64 + 0x178),local_24.x,local_24.y,local_1c,local_18);
        }
        bVar2 = FUN_00e2de25((int)pvVar11);
        pvVar1 = local_64;
        pvVar10 = pvVar11;
        if (bVar2) {
          FUN_00e33c73(local_64,param_1,*(COLORREF *)((int)local_64 + 0x17c),local_24.x,local_24.y,
                       local_1c,local_18);
          pvVar10 = pvVar1;
        }
      }
      local_b4.cx = 0;
      local_b4.cy = 0;
      SetViewportExtEx((HDC)*param_1,local_6c.cx,local_6c.cy,&local_b4);
      SetWindowExtEx((HDC)*param_1,local_84.cx,local_84.cy,&local_b4);
      local_60.cx = 0;
      local_60.cy = 0;
      GetViewportExtEx((HDC)*param_1,&local_60);
      pOVar12 = local_58;
      if (param_2 == '\0') {
        iVar7 = FUN_00e3e85d((int)local_58);
        local_90.cy = FUN_00e68567(*(int *)(*(int *)((int)pvVar10 + 400) + iVar7 * 4));
        iVar7 = FUN_00e3e85d((int)pOVar12);
        FUN_00e68547(*(void **)(*(int *)((int)pvVar10 + 400) + iVar7 * 4),&local_74);
        local_a0.cy = 0;
        for (; (int *)local_90.cy != (int *)0x0; local_90.cy = local_90.cy + -1) {
          GetViewportExtEx((HDC)*param_1,&local_60);
          local_58 = (BSTR)local_74[2];
          FUN_00e61ccc(local_58,local_34,'\x01');
          if (local_a0.cy < local_28) {
            local_a0.cy = local_28;
          }
          bVar2 = FUN_00e33e72(pvVar10,local_58);
          if (bVar2) {
            GetViewportExtEx((HDC)*param_1,&local_60);
            if ((local_60.cx != local_6c.cx) || (local_60.cy != local_6c.cy)) {
              SetMapMode((HDC)*param_1,8);
              SetViewportExtEx((HDC)*param_1,local_6c.cx,local_6c.cy,&local_60);
              SetWindowExtEx((HDC)*param_1,local_84.cx,local_84.cy,&local_60);
              GetViewportExtEx((HDC)*param_1,&local_60);
            }
            CVar16 = 0xff;
          }
          else {
            cVar3 = FUN_00e2c5b7((int *)local_58);
            if (cVar3 == '\0') {
              GetViewportExtEx((HDC)*param_1,&local_60);
              if ((local_60.cx != local_6c.cx) || (local_60.cy != local_6c.cy)) {
                SetMapMode((HDC)*param_1,8);
                SetViewportExtEx((HDC)*param_1,local_6c.cx,local_6c.cy,&local_60);
                SetWindowExtEx((HDC)*param_1,local_84.cx,local_84.cy,&local_60);
                GetViewportExtEx((HDC)*param_1,&local_60);
              }
              if ((((char)local_58[0x2e] != '\0') &&
                  (iVar7 = (**(code **)(**(int **)((int)pvVar10 + 0x15c) + 0x4c))
                                     (*(int **)((int)pvVar10 + 0x15c),&local_98.cy), -1 < iVar7)) &&
                 (local_98.cy == 1)) {
                FUN_00e318c4(pvVar10,1);
              }
              CVar16 = 0;
            }
            else {
              GetViewportExtEx((HDC)*param_1,&local_60);
              if ((local_60.cx != local_6c.cx) || (local_60.cy != local_6c.cy)) {
                SetMapMode((HDC)*param_1,8);
                SetViewportExtEx((HDC)*param_1,local_6c.cx,local_6c.cy,&local_60);
                SetWindowExtEx((HDC)*param_1,local_84.cx,local_84.cy,&local_60);
                GetViewportExtEx((HDC)*param_1,&local_60);
              }
              CVar16 = 0x6400;
            }
          }
          cVar3 = '\0';
          piVar4 = *(int **)((int)pvVar10 + 0x19c);
          uVar6 = local_70;
          pOVar15 = pOVar12;
          if (piVar4 != (int *)0x0) {
            cVar3 = '\0';
            (**(code **)(*piVar4 + 4))(piVar4);
          }
          cVar14 = (char)uVar6;
          piVar13 = *(int **)((int)pvVar10 + 0x160);
          if (piVar13 != (int *)0x0) {
            (**(code **)(*piVar13 + 4))(piVar13);
          }
          FUN_00e60ee2(local_58,param_1,piVar13,piVar4,cVar14,pOVar15,cVar3,CVar16);
          GetViewportExtEx((HDC)*param_1,&local_60);
          uVar9 = FUN_00e3eb14(pOVar12,(int)local_58);
          if ((char)uVar9 == '\0') {
            if (*(char *)((int)pvVar10 + 0x155) != '\0') {
              FUN_00e611d6(local_58,param_1,pOVar12);
            }
          }
          else {
            piVar4 = *(int **)((int)pvVar10 + 0x160);
            if (piVar4 != (int *)0x0) {
              (**(code **)(*piVar4 + 4))(piVar4);
            }
            FUN_00e6134a(local_58,param_1,pOVar12,piVar4);
          }
          local_74 = (undefined4 *)*local_74;
        }
      }
      if ((char)local_70 != '\0') {
        local_7c.cx = 0;
        local_7c.cy = 0;
        local_98.cx = 0;
        local_98.cy = 0;
        SetMapMode((HDC)*param_1,8);
        SetViewportExtEx((HDC)*param_1,1,1,&local_7c);
        SetWindowExtEx((HDC)*param_1,1,1,&local_98);
        if (param_2 == '\0') {
          bVar2 = FUN_00e2de18((int)pvVar10);
          pvVar11 = pvVar10;
          if (bVar2) {
            iVar5 = FUN_00e3e8f6(pOVar12,500,'\0');
            iVar7 = *(int *)((int)pvVar10 + 0x140);
            iVar8 = FUN_00e3e8f6(pOVar12,500,'\x01');
            pvVar11 = local_64;
            param_1 = local_a8;
            FUN_00e33906(local_64,local_a8,(iVar5 * iVar7) / 500,
                         (iVar8 * *(int *)((int)pvVar10 + 0x144)) / 500,
                         *(HGDIOBJ *)((int)local_64 + 0x178),local_24.x,local_24.y,local_1c,local_18
                        );
          }
          bVar2 = FUN_00e2de25((int)pvVar11);
          if (bVar2) {
            FUN_00e33c73(local_64,param_1,*(COLORREF *)((int)local_64 + 0x17c),local_24.x,local_24.y
                         ,local_1c,local_18);
          }
        }
        local_a0.cx = 0;
        local_a0.cy = 0;
        SetViewportExtEx((HDC)*param_1,local_7c.cx,local_7c.cy,&local_a0);
        SetWindowExtEx((HDC)*param_1,local_98.cx,local_98.cy,&local_a0);
        local_90.cx = 0;
        local_90.cy = 0;
        GetViewportExtEx((HDC)*param_1,&local_90);
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_88 != (int *)0x0) {
        (**(code **)(*local_88 + 8))(local_88);
      }
      VariantClear(&local_c8);
    }
  }
  FUN_00ec9e3c();
  return;
}



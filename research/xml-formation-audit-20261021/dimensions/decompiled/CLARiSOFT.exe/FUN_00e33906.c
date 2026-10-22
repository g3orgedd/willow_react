// Source: CLARiSOFT.exe @ 00e33906; FUN_00e33906

void __thiscall
FUN_00e33906(void *this,undefined4 *param_1,undefined4 param_2,undefined4 param_3,HGDIOBJ param_4,
            undefined4 param_5,undefined4 param_6,int param_7,int param_8)

{
  void *pvVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  HPEN pHVar7;
  HPEN pHVar8;
  void *pvVar9;
  tagPOINT local_44;
  HGDIOBJ local_3c;
  void *local_38;
  void *local_34;
  HPEN local_30;
  HPEN local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  local_3c = param_4;
  local_44.x = 0;
  local_44.y = 0;
  local_34 = this;
  SetViewportOrgEx((HDC)*param_1,0,0,&local_44);
  piVar3 = (int *)FUN_00e77808((void *)((int)this + 4),0);
  if (*piVar3 == 0) {
    pvVar9 = (void *)0x0;
  }
  else {
    pvVar9 = (void *)(*piVar3 + -100);
  }
  local_30 = (HPEN)(param_7 + -1);
  local_2c = (HPEN)(param_8 + -1);
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  local_38 = pvVar9;
  GetClipBox((HDC)*param_1,&local_28);
  if ((int)local_30 < local_28.right) {
    local_28.right = (LONG)local_30;
  }
  if ((int)local_2c < local_28.bottom) {
    local_28.bottom = (LONG)local_2c;
  }
  if (local_28.left == 0) {
    local_28.left = 1;
  }
  if (local_28.top == 0) {
    local_28.top = 1;
  }
  iVar4 = FUN_00e3e85d((int)pvVar9);
  bVar2 = FUN_00e66fde(*(int *)(*(int *)((int)this + 400) + iVar4 * 4));
  pvVar9 = local_38;
  local_18.left = local_28.left;
  local_18.top = local_28.top;
  local_18.right = local_28.right;
  local_18.bottom = local_28.bottom;
  if (bVar2) {
    GetClientRect(*(HWND *)((int)local_38 + 4),&local_18);
    iVar4 = (int)local_30 - *(int *)((int)pvVar9 + 0x24);
    pHVar8 = (HPEN)((int)local_2c - *(int *)((int)pvVar9 + 0x28));
    if (iVar4 < local_18.right) {
      local_18.right = iVar4;
    }
    if ((int)pHVar8 < local_18.bottom) {
      local_18.bottom = (LONG)pHVar8;
    }
    local_2c = CreatePen(2,1,(COLORREF)local_3c);
    local_3c = SelectObject((HDC)*param_1,local_2c);
    local_30 = (HPEN)0x0;
    iVar4 = FUN_00e3e85d((int)pvVar9);
    if (*(int *)(*(int *)(*(int *)((int)local_34 + 400) + iVar4 * 4) + 4) != 1) {
      do {
        pvVar1 = local_34;
        iVar5 = FUN_00e3e85d((int)pvVar9);
        iVar4 = *(int *)((int)pvVar1 + 400);
        iVar6 = FUN_00e3e85d((int)local_38);
        pvVar9 = local_38;
        iVar4 = FUN_00e3e82d(local_38,*(int *)(*(int *)(*(int *)(iVar4 + iVar5 * 4) + 0xc) +
                                              (int)local_30 * 4) +
                                      *(int *)(*(int *)(*(int *)((int)local_34 + 400) + iVar6 * 4) +
                                              8),'\x01');
        MoveToEx((HDC)*param_1,local_18.left,iVar4,(LPPOINT)0x0);
        LineTo((HDC)*param_1,local_18.right,iVar4);
        local_30 = (HPEN)((int)&local_30->unused + 1);
        iVar4 = FUN_00e3e85d((int)pvVar9);
      } while (local_30 <
               (HPEN)(*(int *)(*(int *)(*(int *)((int)local_34 + 400) + iVar4 * 4) + 4) + -1));
    }
    SelectObject((HDC)*param_1,local_3c);
    DeleteObject(local_2c);
  }
  else {
    GetClientRect(*(HWND *)((int)local_38 + 4),&local_18);
    iVar4 = (int)local_30 - *(int *)((int)pvVar9 + 0x24);
    pHVar8 = (HPEN)((int)local_2c - *(int *)((int)pvVar9 + 0x28));
    if (iVar4 < local_18.right) {
      local_18.right = iVar4;
    }
    if ((int)pHVar8 < local_18.bottom) {
      local_18.bottom = (LONG)pHVar8;
    }
    if (local_18.left == 0) {
      local_18.left = 1;
    }
    if (local_18.top == 0) {
      local_18.top = 1;
    }
    pHVar8 = CreatePen(2,1,(COLORREF)local_3c);
    local_38 = SelectObject((HDC)*param_1,pHVar8);
    if (local_18.left == 1) {
      local_18.left = 0;
      local_18.right = local_18.right + -1;
    }
    if (local_18.top == 1) {
      local_18.top = 0;
      local_18.bottom = (int)&((HPEN)(local_18.bottom + -4))->unused + 3;
    }
    local_30 = *(HPEN *)((int)local_34 + 0x140);
    pHVar7 = local_30;
    if (0 < local_18.right) {
      do {
        local_2c = pHVar7;
        iVar4 = FUN_00e3e8f6(pvVar9,(int)local_2c,'\0');
        iVar4 = iVar4 - *(int *)((int)pvVar9 + 0x24);
        local_2c = (HPEN)((int)&local_30->unused + (int)&local_2c->unused);
        if (0 < iVar4) {
          if (local_18.right <= iVar4) break;
          MoveToEx((HDC)*param_1,iVar4,local_18.top,(LPPOINT)0x0);
          LineTo((HDC)*param_1,iVar4,local_18.bottom);
        }
        pHVar7 = local_2c;
      } while (iVar4 < local_18.right);
    }
    local_30 = *(HPEN *)((int)local_34 + 0x144);
    pHVar7 = local_30;
    if (0 < local_18.bottom) {
      do {
        local_2c = pHVar7;
        iVar4 = FUN_00e3e8f6(pvVar9,(int)local_2c,'\x01');
        iVar4 = iVar4 - *(int *)((int)pvVar9 + 0x28);
        local_2c = (HPEN)((int)&local_30->unused + (int)&local_2c->unused);
        if (0 < iVar4) {
          if (local_18.bottom <= iVar4) break;
          MoveToEx((HDC)*param_1,local_18.left,iVar4,(LPPOINT)0x0);
          LineTo((HDC)*param_1,local_18.right,iVar4);
        }
        pHVar7 = local_2c;
      } while (iVar4 < local_18.bottom);
    }
    pHVar7 = CreatePen(0,1,(COLORREF)local_3c);
    SelectObject((HDC)*param_1,pHVar7);
    MoveToEx((HDC)*param_1,local_18.left,local_18.top,(LPPOINT)0x0);
    SelectObject((HDC)*param_1,local_38);
    DeleteObject(pHVar8);
    DeleteObject(pHVar7);
  }
  SetViewportOrgEx((HDC)*param_1,local_44.x,local_44.y,(LPPOINT)0x0);
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



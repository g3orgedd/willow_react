// Source: CLARiSOFT.exe @ 00e867d5; FUN_00e867d5

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00e867d5(void *this,int param_1,HDC param_2)

{
  void *this_00;
  void *pvVar1;
  void *this_01;
  HDC hdc;
  int iVar2;
  int iVar3;
  int cy;
  HGDIOBJ h;
  HBRUSH pHVar4;
  int *piVar5;
  int x;
  int cx;
  int cx_00;
  undefined4 *puVar6;
  int cy_00;
  int *piVar7;
  void *pvVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  HGDIOBJ pvVar11;
  HBITMAP local_70;
  float local_60;
  float local_5c;
  HBRUSH local_58;
  void *local_54;
  int local_50;
  void *local_4c;
  HDC local_48;
  tagPOINT local_44 [2];
  RECT local_34;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x7c;
  local_8 = 0xe867e1;
  local_54 = this;
  if (param_1 == 0) {
    this_00 = *(void **)((int)this + 0x1be8);
    local_8 = 0;
    SetMapMode(param_2,8);
    SetWindowOrgEx(param_2,0,0,(LPPOINT)0x0);
    SetWindowExtEx(param_2,100,100,(LPSIZE)0x0);
    local_60 = 1.0;
    local_5c = 1.0;
    piVar5 = *(int **)(*(int *)((int)this + 0x1efc) + 0x160);
    (**(code **)(*piVar5 + 0x2c))(piVar5,&local_60);
    piVar5 = *(int **)(*(int *)((int)this + 0x1efc) + 0x160);
    (**(code **)(*piVar5 + 0x34))(piVar5,&local_5c);
    local_60 = local_60 * DAT_00efe90c;
    local_5c = local_5c * DAT_00efe90c;
    iVar2 = GetDeviceCaps(param_2,0x58);
    iVar3 = GetDeviceCaps(param_2,0x5a);
    x = (int)(((double)iVar2 * DAT_00f02e30) / (double)local_60 + _DAT_00f017c8);
    iVar3 = (int)(((double)iVar3 * DAT_00f02e30) / (double)local_5c + _DAT_00f017c8);
    SetViewportExtEx(param_2,x,iVar3,(LPSIZE)0x0);
    local_48 = (HDC)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    local_48 = CreateCompatibleDC(param_2);
    local_58 = (HBRUSH)0xa;
    local_50 = *(int *)(*(int *)((int)local_54 + 0x1efc) + 0x8c) + 1;
    local_4c = (void *)(*(int *)(*(int *)((int)local_54 + 0x1efc) + 0x90) + 1);
    cx = local_50 * 10;
    cy = (int)local_4c * 10;
    local_70 = CreateCompatibleBitmap(param_2,cx,cy);
    pvVar1 = local_4c;
    iVar2 = local_50;
    if (local_70 == (HBITMAP)0x0) {
      cx_00 = cx;
      cy_00 = cy;
      do {
        cy_00 = cy_00 - (int)pvVar1;
        local_58 = (HBRUSH)((int)local_58 + -1);
        cx_00 = cx_00 - iVar2;
        if (local_58 == (HBRUSH)0x0) {
          MessageBoxW(*(HWND *)((int)local_54 + -0x38),L"Not enough memory to print",L"System Error"
                      ,0x10);
          break;
        }
        local_70 = CreateCompatibleBitmap(param_2,cx_00,cy_00);
      } while (local_70 == (HBITMAP)0x0);
    }
    GetLastError();
    h = SelectObject(local_48,local_70);
    pHVar4 = CreateSolidBrush(0xffffff);
    local_24.left = 0;
    local_24.top = 0;
    local_58 = pHVar4;
    local_24.right = cx;
    local_24.bottom = cy;
    FillRect(local_48,&local_24,pHVar4);
    FUN_00e2d699(this_00,&local_48,'\x01');
    BitBlt(param_2,0,0,local_50,(int)local_4c,local_48,0,0,0xcc0020);
    local_24.left = 1;
    local_24.top = 1;
    local_24.right = local_50 + -1;
    local_24.bottom = (int)local_4c + -1;
    FillRect(param_2,&local_24,pHVar4);
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = local_50;
    local_24.bottom = (LONG)local_4c;
    FillRect(local_48,&local_24,pHVar4);
    SetMapMode(local_48,8);
    SetWindowOrgEx(local_48,0,0,(LPPOINT)0x0);
    SetWindowExtEx(local_48,100,100,(LPSIZE)0x0);
    SetViewportExtEx(local_48,x,iVar3,(LPSIZE)0x0);
    iVar2 = *(int *)(**(int **)((int)this_00 + 400) + 0x14);
    piVar5 = (int *)FUN_00e77808((void *)((int)this_00 + 4),0);
    if (*piVar5 == 0) {
      local_4c = (void *)0x0;
    }
    else {
      local_4c = (void *)(*piVar5 + -100);
    }
    puVar6 = (undefined4 *)**(undefined4 **)(**(int **)((int)this_00 + 400) + 0x10);
    pvVar1 = (void *)iVar2;
    if (0 < iVar2) {
      do {
        local_54 = pvVar1;
        SetMapMode(local_48,8);
        SetWindowOrgEx(local_48,0,0,(LPPOINT)0x0);
        SetWindowExtEx(local_48,100,100,(LPSIZE)0x0);
        SetViewportExtEx(local_48,x,iVar3,(LPSIZE)0x0);
        this_01 = local_4c;
        pvVar1 = (void *)puVar6[2];
        puVar6 = (undefined4 *)*puVar6;
        pvVar11 = (HGDIOBJ)0x1;
        uVar10 = 0;
        uVar9 = 1;
        piVar5 = *(int **)((int)this_00 + 0x19c);
        pvVar8 = local_4c;
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 4))(piVar5);
        }
        piVar7 = *(int **)((int)this_00 + 0x160);
        if (piVar7 != (int *)0x0) {
          (**(code **)(*piVar7 + 4))(piVar7);
        }
        FUN_00e626fb(pvVar1,&local_24.right,&local_48,piVar7,piVar5,pvVar8,uVar9,uVar10,pvVar11);
        FUN_00e6166f(pvVar1,&local_44[0].x);
        FUN_00e3e6ed(this_01,local_44,'\0');
        pHVar4 = CreateSolidBrush(0);
        pvVar11 = SelectObject(param_2,pHVar4);
        BitBlt(param_2,local_44[0].x,local_44[0].y,local_24.right + -1,local_24.bottom + -1,local_48
               ,0,0,0x8800c6);
        GetLastError();
        SelectObject(param_2,pvVar11);
        DeleteObject(pHVar4);
        local_34.left = 0;
        local_34.top = 0;
        local_34.right = cx;
        local_34.bottom = cy;
        FillRect(local_48,&local_34,local_58);
        pvVar1 = (void *)((int)local_54 + -1);
      } while ((int)local_54 + -1 != 0);
      local_54 = (void *)0x0;
    }
    SelectObject(local_48,h);
    DeleteObject(local_70);
    DeleteObject(local_58);
    DeleteDC(local_48);
    puVar6 = (undefined4 *)**(undefined4 **)(**(int **)((int)this_00 + 400) + 0x10);
    if (0 < iVar2) {
      do {
        piVar5 = puVar6 + 2;
        puVar6 = (undefined4 *)*puVar6;
        FUN_00e6166a(*piVar5);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    InvalidateRect(*(HWND *)((int)local_4c + 4),(RECT *)0x0,1);
    hdc = local_48;
    if (local_48 != (HDC)0x0) {
      local_48 = (HDC)0x0;
      DeleteDC(hdc);
    }
  }
  FUN_00ec9e3c();
  return;
}



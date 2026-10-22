// Source: CLARiSOFT.exe @ 00e4234d; FUN_00e4234d

void __thiscall FUN_00e4234d(void *this,int param_1,int param_2,int param_3,char param_4)

{
  byte bVar1;
  HWND hWnd;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_2c;
  int local_28;
  undefined1 local_24 [12];
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00f385b8 ^ (uint)&stack0xfffffffc;
  if (this == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)this + -0x24;
  }
  local_2c = 0;
  *(int *)((int)this + 8) = param_1;
  *(int *)((int)this + 0xc) = param_2;
  local_28 = 0;
  if (param_4 == '\0') {
    local_2c = *(int *)this;
    local_28 = *(int *)((int)this + 4);
    FUN_00e3dd6a((void *)(iVar2 + 0x24),&local_2c,&local_28);
  }
  iVar3 = *(int *)this - local_2c;
  local_24._0_4_ = 0x1c;
  iVar5 = *(int *)((int)this + 4);
  *(int *)((int)this + 4) = local_28;
  bVar1 = *(byte *)((int)this + 0x3c);
  puVar6 = (undefined4 *)(local_24 + 4);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *(int *)this = local_2c;
  local_24._4_4_ = 7;
  if ((bVar1 & 0x20) != 0) {
    local_24._4_4_ = 0xf;
  }
  local_24._8_4_ = 0;
  local_18.left = param_1 + -1;
  local_18.top = *(UINT *)((int)this + 0x20);
  local_18.right = local_2c;
  local_2c = iVar5 - local_28;
  local_28 = iVar3;
  SetScrollInfo(*(HWND *)(iVar2 + 4),0,(LPCSCROLLINFO)local_24,param_3);
  local_24._0_4_ = 0x1c;
  puVar6 = (undefined4 *)(local_24 + 4);
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  local_24._4_4_ = 7;
  if ((*(byte *)((int)this + 0x3c) & 0x10) != 0) {
    local_24._4_4_ = 0xf;
  }
  local_24._8_4_ = 0;
  local_18.left = *(int *)((int)this + 0xc) + -1;
  local_18.top = *(UINT *)((int)this + 0x24);
  local_18.right = *(int *)((int)this + 4);
  SetScrollInfo(*(HWND *)(iVar2 + 4),1,(LPCSCROLLINFO)local_24,param_3);
  if (((*(byte *)((int)this + 0x3c) & 1) != 0) && ((local_28 != 0 || (local_2c != 0)))) {
    hWnd = GetWindow(*(HWND *)(iVar2 + 4),5);
    iVar5 = local_28;
    for (; hWnd != (HWND)0x0; hWnd = GetWindow(hWnd,2)) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect(hWnd,(LPRECT)(local_24 + 0xc));
      MapWindowPoints((HWND)0x0,*(HWND *)(iVar2 + 4),(LPPOINT)(local_24 + 0xc),1);
      SetWindowPos(hWnd,(HWND)0x0,local_18.left + iVar5,local_18.top + local_2c,0,0,0x15);
    }
  }
  iVar4 = 1;
  iVar5 = *(int *)((int)this + 8) / 100;
  if (iVar5 < 1) {
    iVar5 = iVar4;
  }
  *(int *)((int)this + 0x10) = iVar5;
  iVar5 = *(int *)((int)this + 0xc) / 100;
  if (iVar5 < 1) {
    iVar5 = iVar4;
  }
  *(int *)((int)this + 0x14) = iVar5;
  iVar5 = *(int *)((int)this + 8) / 10;
  if (iVar5 < 1) {
    iVar5 = iVar4;
  }
  *(int *)((int)this + 0x18) = iVar5;
  iVar5 = *(int *)((int)this + 0xc) / 10;
  if (iVar5 < 1) {
    iVar5 = iVar4;
  }
  *(int *)((int)this + 0x1c) = iVar5;
  if (param_3 != 0) {
    InvalidateRect(*(HWND *)(iVar2 + 4),(RECT *)0x0,1);
  }
  FUN_00ec9db6(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Source: CLARiSOFT.exe @ 00e98e99; FUN_00e98e99

undefined4 __thiscall
FUN_00e98e99(void *this,undefined4 param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  void *pvVar4;
  void *local_c;
  void *local_8;
  
  local_c = this;
  local_8 = this;
  iVar1 = GetScrollPos(*(HWND *)((int)this + 0xf8),2);
  uVar2 = param_2 & 0xffff;
  if (uVar2 == 0) {
    pvVar4 = (void *)(iVar1 + -1);
  }
  else if (uVar2 == 1) {
    pvVar4 = (void *)(iVar1 + 1);
  }
  else if (uVar2 == 2) {
    pvVar4 = (void *)(iVar1 + -10);
  }
  else if (uVar2 == 3) {
    pvVar4 = (void *)(iVar1 + 10);
  }
  else {
    if (1 < uVar2 - 4) goto LAB_00e98f2d;
    pvVar4 = (void *)(param_2 >> 0x10);
  }
  GetScrollRange(*(HWND *)((int)this + 0xf8),2,(LPINT)&local_8,(LPINT)&local_c);
  pvVar3 = local_8;
  if ((int)local_8 < (int)pvVar4) {
    pvVar3 = pvVar4;
  }
  pvVar4 = local_c;
  if ((int)pvVar3 < (int)local_c) {
    pvVar4 = pvVar3;
  }
  SetScrollPos(*(HWND *)((int)this + 0xf8),2,(int)pvVar4,1);
  (**(code **)(**(int **)((int)this + 0x98) + 0x40))(*(int **)((int)this + 0x98),pvVar4);
LAB_00e98f2d:
  *param_4 = 1;
  return 0;
}



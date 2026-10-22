// Source: CLARiSOFT.exe @ 00e3df71; FUN_00e3df71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e3df71(void *this,LPPOINT param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  tagPOINT local_3c;
  tagSIZE local_34;
  tagSIZE local_2c;
  HDC local_24;
  HWND local_20;
  int *local_18;
  undefined4 local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0xe3df7d;
  local_20 = *(HWND *)((int)this + 4);
  local_24 = (HDC)0x0;
  local_24 = GetDC(local_20);
  local_8 = 0;
  local_2c.cx = 0;
  local_2c.cy = 0;
  local_34.cx = 0;
  local_34.cy = 0;
  GetViewportExtEx(local_24,&local_2c);
  GetWindowExtEx(local_24,&local_34);
  (**(code **)(*(int *)this + 0x10))(&local_24,0);
  local_3c.x = 0;
  local_3c.y = 0;
  SetViewportOrgEx(local_24,0,0,&local_3c);
  DPtoLP(local_24,param_1,2);
  SetViewportExtEx(local_24,local_2c.cx,local_2c.cy,(LPSIZE)0x0);
  SetWindowExtEx(local_24,local_34.cx,local_34.cy,(LPSIZE)0x0);
  SetViewportOrgEx(local_24,local_3c.x,local_3c.y,(LPPOINT)0x0);
  iVar1 = *(int *)((int)this + 0x68);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x160) != 0)) {
    iVar3 = FUN_00e2f6c6(iVar1);
    if (iVar3 != 0) {
      FUN_00eae6d1(local_14);
      piVar2 = *(int **)(iVar1 + 0x160);
      local_8._0_1_ = 1;
      local_18 = piVar2;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      local_8._0_1_ = 2;
      piVar4 = piVar2;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      FUN_00eae8ae(&param_1->x,piVar4);
      local_8._0_1_ = 1;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00eae7b2(local_14);
    }
  }
  FUN_00e3db8c(&local_24);
  return;
}



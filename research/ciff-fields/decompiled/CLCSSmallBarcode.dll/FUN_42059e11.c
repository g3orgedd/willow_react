// Source: CLCSSmallBarcode.dll @ 42059e11; FUN_42059e11

undefined4 __thiscall
FUN_42059e11(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,HDC param_4,
            undefined1 param_5)

{
  undefined4 uVar1;
  tagSIZE local_14;
  tagSIZE local_c;
  
  uVar1 = 0x80004005;
  if (*(int *)((int)this + 0x40) != 0) {
    local_c.cx = 0;
    local_c.cy = 0;
    GetViewportExtEx(param_4,&local_c);
    SetViewportExtEx(param_4,100,100,&local_c);
    local_14.cx = 0;
    local_14.cy = 0;
    GetWindowExtEx(param_4,&local_14);
    SetWindowExtEx(param_4,100,100,&local_14);
    (**(code **)(**(int **)((int)this + 0x40) + 4))(*param_3,*param_1,*param_2);
    (**(code **)(**(int **)((int)this + 0x40) + 0xc))(param_4,param_5);
    (**(code **)(**(int **)((int)this + 0x40) + 8))();
    uVar1 = 0;
  }
  return uVar1;
}



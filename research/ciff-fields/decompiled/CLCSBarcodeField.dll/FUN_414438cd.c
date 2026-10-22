// Source: CLCSBarcodeField.dll @ 414438cd; FUN_414438cd

undefined4 __thiscall
FUN_414438cd(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,HDC param_4)

{
  void *pvVar1;
  tagSIZE local_18;
  tagSIZE local_10;
  void *local_8;
  
  if (*(int *)((int)this + 0x44) != 0) {
    local_10.cx = 0;
    local_10.cy = 0;
    local_8 = this;
    GetViewportExtEx(param_4,&local_10);
    SetViewportExtEx(param_4,100,100,&local_10);
    local_18.cx = 0;
    local_18.cy = 0;
    GetWindowExtEx(param_4,&local_18);
    SetWindowExtEx(param_4,100,100,&local_18);
    FUN_41443d8a(local_8,param_1,param_2,param_3);
    pvVar1 = local_8;
    FUN_4144beb9(*(void **)((int)local_8 + 0x44),(IUnknown *)*param_3,(IUnknown *)*param_1,
                 (IUnknown *)*param_2);
    FUN_4144a1c7(*(void **)((int)pvVar1 + 0x44),param_4);
    FUN_4144b05d(*(int *)((int)pvVar1 + 0x44));
  }
  return 0;
}



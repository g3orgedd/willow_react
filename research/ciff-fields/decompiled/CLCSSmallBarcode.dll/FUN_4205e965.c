// Source: CLCSSmallBarcode.dll @ 4205e965; FUN_4205e965

undefined4 __thiscall
FUN_4205e965(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,HDC param_4)

{
  tagSIZE local_14;
  tagSIZE local_c;
  
  if (*(int *)((int)this + 0x40) != 0) {
    local_c.cx = 0;
    local_c.cy = 0;
    GetViewportExtEx(param_4,&local_c);
    SetViewportExtEx(param_4,100,100,&local_c);
    local_14.cx = 0;
    local_14.cy = 0;
    GetWindowExtEx(param_4,&local_14);
    SetWindowExtEx(param_4,100,100,&local_14);
    FUN_4202bc38(*(void **)((int)this + 0x40),(IUnknown *)*param_3,(IUnknown *)*param_1,
                 (IUnknown *)*param_2);
    FUN_4202a1f2(*(void **)((int)this + 0x40),param_4);
    FUN_4202aea0(*(int *)((int)this + 0x40));
  }
  return 0;
}



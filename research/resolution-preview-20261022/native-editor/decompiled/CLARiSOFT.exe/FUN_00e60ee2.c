// Source: CLARiSOFT.exe @ 00e60ee2; FUN_00e60ee2

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall
FUN_00e60ee2(void *this,undefined4 *param_1,int *param_2,int *param_3,char param_4,void *param_5,
            char param_6,COLORREF param_7)

{
  bool bVar1;
  HGDIOBJ pvVar2;
  int *piVar3;
  HDC hdc;
  bool bVar4;
  undefined1 local_a8 [4];
  int local_a4;
  int local_a0;
  undefined4 local_90;
  ULONG UStack_8c;
  int *piStack_88;
  undefined4 uStack_84;
  int local_80;
  ULONG UStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  _union_2683 local_70;
  _union_2683 local_60;
  _union_2683 local_50;
  tagSIZE local_40;
  HGDIOBJ local_38;
  int local_34;
  int local_30;
  tagSIZE local_2c;
  tagPOINT local_24;
  int local_1c;
  BSTR local_18;
  HDC local_14;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x98;
  local_8 = 1;
  local_14 = CreateCompatibleDC((HDC)*param_1);
  local_38 = GetCurrentObject(local_14,7);
  local_2c.cx = 0;
  local_2c.cy = 0;
  local_40.cx = 0;
  local_40.cy = 0;
  GetViewportExtEx((HDC)*param_1,&local_2c);
  GetWindowExtEx((HDC)*param_1,&local_40);
  GetDeviceCaps((HDC)*param_1,8);
  GetDeviceCaps((HDC)*param_1,4);
  GetDeviceCaps((HDC)*param_1,10);
  GetDeviceCaps((HDC)*param_1,6);
  hdc = local_14;
  *(float *)((int)this + 0x20) = (float)local_2c.cx;
  if (*(float *)((int)param_5 + 0x70) != 0.0) {
    *(float *)((int)this + 0x20) = *(float *)((int)param_5 + 0x70);
  }
  *(float *)((int)this + 0x24) = (float)local_2c.cy;
  if (*(float *)((int)param_5 + 0x74) != 0.0) {
    *(float *)((int)this + 0x24) = *(float *)((int)param_5 + 0x74);
  }
  if (*(char *)((int)this + 0x48) == '\0') {
    SelectObject(local_14,*(HGDIOBJ *)((int)this + 8));
  }
  else {
    *(undefined1 *)((int)this + 0x48) = 0;
    if (*(int *)((int)this + 0x3c) != 0) {
      local_60.n2.vt = 9;
      local_60._8_4_ = param_3;
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 4))(param_3);
      }
      local_8._0_1_ = 2;
      local_90 = local_60._0_4_;
      local_70.n2.vt = 9;
      UStack_8c = local_60.decVal.Hi32;
      local_70._8_4_ = param_2;
      piStack_88 = (int *)local_60._8_4_;
      uStack_84 = local_60._12_4_;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2);
      }
      local_50._8_4_ = *(int *)((int)this + 4);
      local_8._0_1_ = 3;
      local_80 = local_70._0_4_;
      UStack_7c = local_70.decVal.Hi32;
      local_50.n2.vt = 9;
      piStack_78 = (int *)local_70._8_4_;
      uStack_74 = local_70._12_4_;
      if ((int *)local_50._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_50._8_4_ + 4))(local_50._8_4_);
      }
      local_8._0_1_ = 4;
      (**(code **)(**(int **)((int)this + 0x3c) + 0xc))
                (*(int **)((int)this + 0x3c),local_14,1,local_50._0_4_,local_50.decVal.Hi32,
                 local_50._8_4_,local_50._12_4_,local_80,UStack_7c,piStack_78,uStack_74,local_90,
                 UStack_8c,piStack_88,uStack_84,param_7);
      VariantClear((VARIANTARG *)&local_50.n2);
      VariantClear((VARIANTARG *)&local_70.n2);
      local_8 = CONCAT31(local_8._1_3_,1);
      VariantClear((VARIANTARG *)&local_60.n2);
    }
    if (*(int *)((int)this + 8) != 0) {
      DeleteObject(*(HGDIOBJ *)((int)this + 8));
    }
    hdc = local_14;
    pvVar2 = GetCurrentObject(local_14,7);
    *(HGDIOBJ *)((int)this + 8) = pvVar2;
  }
  GetObjectW(*(HANDLE *)((int)this + 8),0x18,local_a8);
  local_34 = local_a4;
  local_14 = (HDC)local_a0;
  local_24.x = 0;
  local_24.y = 0;
  if (param_6 == '\0') {
    piVar3 = FUN_00e61ccc(this,&local_80,'\x01');
    local_24.x = *piVar3;
    local_24.y = piVar3[1];
    FUN_00e3e5b0(param_5,&local_24,'\0');
  }
  (**(code **)(**(int **)((int)this + 4) + 0x24))(*(int **)((int)this + 4),&local_30);
  if (local_30 == 0) {
    param_7 = 0xc0c0c0;
  }
  local_1c = 2;
  (**(code **)(**(int **)((int)this + 4) + 0x54))(*(int **)((int)this + 4),&local_1c);
  bVar4 = local_1c == 3;
  local_18 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,5);
  (**(code **)(**(int **)((int)this + 4) + 0x68))(*(int **)((int)this + 4),&local_18);
  bVar1 = FUN_00e03edc(&local_18,L"GraphicPrimitive");
  FUN_00e62f49(param_1,&local_24.x,local_34,(int)local_14,hdc,param_7,param_4,bVar4,bVar1);
  pvVar2 = SelectObject(hdc,local_38);
  if (pvVar2 != *(HGDIOBJ *)((int)this + 8)) {
    DeleteObject(pvVar2);
  }
  DeleteDC(hdc);
  SysFreeString(local_18);
  local_8 = local_8 & 0xffffff00;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return;
}



// Source: CLCSSmallBarcode.dll @ 4200cb5f; FUN_4200cb5f

void __thiscall FUN_4200cb5f(void *this,HDC param_1,int *param_2)

{
  int iVar1;
  UINT UVar2;
  int y;
  tagSIZE local_58;
  int local_50;
  int *local_4c;
  HDC local_48;
  tagTEXTMETRICW local_44;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  local_48 = param_1;
  local_4c = param_2;
  iVar1 = (**(code **)*param_2)
                    (param_2,&local_48,*(undefined4 *)((int)this + 0x5c),
                     *(undefined4 *)((int)this + 0x60),*(undefined4 *)((int)this + 0x68),
                     *(undefined4 *)((int)this + 100),0,0,3,*(undefined4 *)((int)this + 0x10),
                     *(undefined4 *)((int)this + 0x14));
  if (-1 < iVar1) {
    UVar2 = SysStringLen(*(BSTR *)((int)this + 0x58));
    GetTextExtentPoint32W(local_48,*(LPCWSTR *)((int)this + 0x58),UVar2,&local_58);
    GetTextMetricsW(local_48,&local_44);
    local_50 = (*(int *)((int)this + 0x70) / 2 + *(int *)((int)this + 0x84)) - local_58.cx / 2;
    iVar1 = *(int *)((int)this + 0xe8);
    if (*(int *)((int)this + 0x3c) == 0) {
      if (local_44.tmInternalLeading < 0) {
        local_44.tmInternalLeading = 0;
      }
      y = (*(int *)((int)this + 0x88) - local_44.tmInternalLeading) + *(int *)((int)this + 0x78) +
          iVar1;
    }
    else {
      y = (*(int *)((int)this + 0x88) - iVar1) - local_58.cy;
      *(int *)((int)this + 0x88) = y;
    }
    *(int *)((int)this + 0x78) = *(int *)((int)this + 0x78) + iVar1 + local_58.cy;
    UVar2 = SysStringLen(*(BSTR *)((int)this + 0x58));
    ExtTextOutW(local_48,local_50,y,0,(RECT *)0x0,*(LPCWSTR *)((int)this + 0x58),UVar2,(INT *)0x0);
    (**(code **)(*local_4c + 4))(local_4c,&local_48);
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



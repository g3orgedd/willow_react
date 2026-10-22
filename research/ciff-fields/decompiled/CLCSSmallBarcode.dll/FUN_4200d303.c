// Source: CLCSSmallBarcode.dll @ 4200d303; FUN_4200d303

void __thiscall FUN_4200d303(void *this,HDC param_1,undefined4 param_2)

{
  int iVar1;
  HGDIOBJ h;
  undefined1 local_5c [20];
  undefined4 local_48;
  int local_40;
  ushort local_36;
  uint local_8;
  
  local_8 = DAT_420b8f90 ^ (uint)&stack0xfffffffc;
  if ((param_1 != (HDC)0x0) && (param_1 != (HDC)0xffffffff)) {
    iVar1 = FUN_4200da9f((int)this);
    if (iVar1 == 1) {
      FUN_4200d514((int)this);
    }
    h = GetCurrentObject(param_1,7);
    *(HGDIOBJ *)((int)this + 0x10) = h;
    if (h != (HGDIOBJ)0x0) {
      iVar1 = GetObjectW(h,0x54,local_5c);
      if (iVar1 == 0) {
        *(undefined4 *)((int)this + 0x10) = 0;
      }
      else {
        *(undefined4 *)((int)this + 0x18) = local_48;
        *(undefined4 *)((int)this + 0x14) = param_2;
        *(HDC *)((int)this + 0xc) = param_1;
        *(uint *)((int)this + 0x1c) = (uint)local_36 * local_40 + 0x1f >> 3 & 0x1ffffffc;
      }
    }
  }
  FUN_4206a5c8(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



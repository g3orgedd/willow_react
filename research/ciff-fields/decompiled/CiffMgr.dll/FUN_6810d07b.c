// Source: CiffMgr.dll @ 6810d07b; FUN_6810d07b

uint __cdecl FUN_6810d07b(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff;
  if (0x2f < uVar1) {
    if (uVar1 < 0x3a) {
      return uVar1 - 0x30;
    }
    if (0x40 < uVar1) {
      if (uVar1 < 0x47) {
        return uVar1 - 0x37;
      }
      param_1 = uVar1 - 0x61;
      if (param_1 < 6) {
        return uVar1 - 0x57;
      }
    }
  }
  return param_1 & 0xffffff00;
}



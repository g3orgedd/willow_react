// Source: CiffMgr.dll @ 6810c93a; FUN_6810c93a

uint __cdecl FUN_6810c93a(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff | 0x80070000;
  if ((int)param_1 < 1) {
    uVar1 = param_1;
  }
  return uVar1;
}



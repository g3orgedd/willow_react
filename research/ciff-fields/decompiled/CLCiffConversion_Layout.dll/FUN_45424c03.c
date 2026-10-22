// Source: CLCiffConversion_Layout.dll @ 45424c03; FUN_45424c03

uint __cdecl FUN_45424c03(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff | 0x80070000;
  if ((int)param_1 < 1) {
    uVar1 = param_1;
  }
  return uVar1;
}



// Source: CLCiffConversion_Layout.dll @ 4543c2b0; FUN_4543c2b0

byte __cdecl FUN_4543c2b0(uint param_1)

{
  int *piVar1;
  
  if (param_1 == 0xfffffffe) {
    piVar1 = __errno();
    *piVar1 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_454626e8)) {
      return *(byte *)((&DAT_454612f8)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x40) & 0x40;
    }
    piVar1 = __errno();
    *piVar1 = 9;
    FUN_45432798();
  }
  return 0;
}



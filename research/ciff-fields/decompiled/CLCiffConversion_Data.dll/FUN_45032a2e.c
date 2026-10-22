// Source: CLCiffConversion_Data.dll @ 45032a2e; FUN_45032a2e

byte __cdecl FUN_45032a2e(uint param_1)

{
  int *piVar1;
  
  if (param_1 == 0xfffffffe) {
    piVar1 = __errno();
    *piVar1 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_45056ee8)) {
      return *(byte *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x40) & 0x40;
    }
    piVar1 = __errno();
    *piVar1 = 9;
    FUN_45027e29();
  }
  return 0;
}



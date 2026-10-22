// Source: CLCiffConversion_Data.dll @ 450311e8; FUN_450311e8

uint __cdecl FUN_450311e8(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7ff00000) != 0x7ff00000) {
    return param_2 & 0x7ff00000;
  }
  return param_2;
}



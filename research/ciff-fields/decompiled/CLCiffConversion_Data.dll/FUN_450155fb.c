// Source: CLCiffConversion_Data.dll @ 450155fb; FUN_450155fb

uint __cdecl FUN_450155fb(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffff | 0x80070000;
  if ((int)param_1 < 1) {
    uVar1 = param_1;
  }
  return uVar1;
}



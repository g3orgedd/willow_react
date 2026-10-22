// Source: CLCiffConversion_Data.dll @ 4501d5f2; FUN_4501d5f2

void __fastcall FUN_4501d5f2(double *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_4501dc99(param_1);
  if ((((char)uVar2 != '\0') && (bVar1 = FUN_4501dd59(&local_18,*param_1), bVar1)) &&
     (local_18.wMonth == 2)) {
    FUN_4501dbe4(param_1);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



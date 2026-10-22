// Source: CLCiffConversion_Data.dll @ 4501e0de; FUN_4501e0de

void __fastcall FUN_4501e0de(double *param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  DOUBLE local_20;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  uVar3 = FUN_4501dc99(param_1);
  if (((char)uVar3 != '\0') && (bVar1 = FUN_4501dd59(&local_18,*param_1), bVar1)) {
    cVar2 = FUN_4501dcf2(&local_20,local_18.wYear,1,1,0,0,0);
    if (cVar2 == '\0') {
      local_20 = DAT_4503d998;
    }
    FUN_4501d4fe(&local_20);
    FUN_4501d54f(param_1,'\x01');
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



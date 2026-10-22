// Source: CLCiffConversion_Layout.dll @ 4540f80c; FUN_4540f80c

void __fastcall FUN_4540f80c(double *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  double local_20;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_4540f3bd(param_1);
  if (((char)uVar2 != '\0') && (bVar1 = FUN_4540f44f(&local_18,*param_1), bVar1)) {
    FUN_4540f664(&local_20,local_18.wYear,1,1,0,0,0);
    FUN_4540f1a7(&local_20);
    FUN_4540f1f8(param_1,'\x01');
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



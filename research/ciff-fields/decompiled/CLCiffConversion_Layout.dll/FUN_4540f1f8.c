// Source: CLCiffConversion_Layout.dll @ 4540f1f8; FUN_4540f1f8

void __thiscall FUN_4540f1f8(void *this,char param_1)

{
  bool bVar1;
  undefined4 uVar2;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_4540f3bd(this);
  if (((((char)uVar2 != '\0') && (bVar1 = FUN_4540f44f(&local_18,*(DOUBLE *)this), bVar1)) &&
      ((local_18.wMonth != 2 || (local_18.wDay != 0x1d)))) && (param_1 != '\0')) {
    FUN_4540f348(this);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



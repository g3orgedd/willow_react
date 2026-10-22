// Source: CLCiffConversion_Data.dll @ 4501d54f; FUN_4501d54f

void __thiscall FUN_4501d54f(void *this,char param_1)

{
  bool bVar1;
  undefined4 uVar2;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_4501dc99(this);
  if (((((char)uVar2 != '\0') && (bVar1 = FUN_4501dd59(&local_18,*(DOUBLE *)this), bVar1)) &&
      ((local_18.wMonth != 2 || (local_18.wDay != 0x1d)))) && (param_1 != '\0')) {
    FUN_4501dbe4(this);
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



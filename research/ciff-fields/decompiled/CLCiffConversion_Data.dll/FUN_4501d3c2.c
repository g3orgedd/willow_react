// Source: CLCiffConversion_Data.dll @ 4501d3c2; FUN_4501d3c2

void __thiscall FUN_4501d3c2(void *this,short param_1)

{
  bool bVar1;
  undefined4 uVar2;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_4501dc99(this);
  if ((char)uVar2 == '\0') goto LAB_4501d452;
  bVar1 = FUN_4501dd59(&local_18,*(DOUBLE *)this);
  if (!bVar1) goto LAB_4501d452;
  local_18.wYear = local_18.wYear + param_1;
  if ((local_18.wMonth == 2) && (local_18.wDay == 0x1d)) {
    if ((local_18.wYear & 3) == 0) {
      if (((uint)local_18.wYear % 100 != 0) || ((uint)local_18.wYear % 400 == 0)) goto LAB_4501d442;
    }
    local_18.wDay = 0x1c;
  }
LAB_4501d442:
  SystemTimeToVariantTime(&local_18,this);
LAB_4501d452:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



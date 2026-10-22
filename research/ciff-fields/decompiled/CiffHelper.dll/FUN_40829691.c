// Source: CiffHelper.dll @ 40829691; FUN_40829691

void __thiscall FUN_40829691(void *this,short param_1)

{
  bool bVar1;
  undefined4 uVar2;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_40829b07(this);
  if ((char)uVar2 == '\0') goto LAB_40829721;
  bVar1 = FUN_40829bc7(&local_18,*(DOUBLE *)this);
  if (!bVar1) goto LAB_40829721;
  local_18.wYear = local_18.wYear + param_1;
  if ((local_18.wMonth == 2) && (local_18.wDay == 0x1d)) {
    if ((local_18.wYear & 3) == 0) {
      if (((uint)local_18.wYear % 100 != 0) || ((uint)local_18.wYear % 400 == 0)) goto LAB_40829711;
    }
    local_18.wDay = 0x1c;
  }
LAB_40829711:
  SystemTimeToVariantTime(&local_18,this);
LAB_40829721:
  FUN_4082d440(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



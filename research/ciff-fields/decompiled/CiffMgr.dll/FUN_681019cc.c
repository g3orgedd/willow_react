// Source: CiffMgr.dll @ 681019cc; FUN_681019cc

void __thiscall FUN_681019cc(void *this,short param_1)

{
  double *pvtime;
  bool bVar1;
  undefined4 uVar2;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  pvtime = (double *)((int)this + 8);
  uVar2 = FUN_68101adf(pvtime);
  if ((char)uVar2 == '\0') goto LAB_68101a5d;
  bVar1 = FUN_68101b38(&local_18,*pvtime);
  if (!bVar1) goto LAB_68101a5d;
  local_18.wYear = local_18.wYear + param_1;
  if ((local_18.wMonth == 2) && (local_18.wDay == 0x1d)) {
    if ((local_18.wYear & 3) == 0) {
      if (((uint)local_18.wYear % 100 != 0) || ((uint)local_18.wYear % 400 == 0)) goto LAB_68101a4d;
    }
    local_18.wDay = 0x1c;
  }
LAB_68101a4d:
  SystemTimeToVariantTime(&local_18,pvtime);
LAB_68101a5d:
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



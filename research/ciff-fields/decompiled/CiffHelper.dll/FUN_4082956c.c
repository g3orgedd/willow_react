// Source: CiffHelper.dll @ 4082956c; FUN_4082956c

void __thiscall FUN_4082956c(void *this,int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_40829b07(this);
  if (((char)uVar2 != '\0') && (bVar1 = FUN_40829bc7(&local_18,*(DOUBLE *)this), bVar1)) {
    if (param_1 < 1) {
      for (iVar4 = -param_1; sVar3 = (short)param_1, (int)(uint)local_18.wMonth <= iVar4;
          iVar4 = iVar4 + -0xc) {
        param_1 = param_1 + 0xc;
        local_18.wYear = local_18.wYear - 1;
      }
    }
    else {
      for (iVar4 = (uint)local_18.wMonth + param_1; sVar3 = (short)param_1, 0xc < iVar4;
          iVar4 = iVar4 + -0xc) {
        param_1 = param_1 + -0xc;
        local_18.wYear = local_18.wYear + 1;
      }
    }
    local_18.wMonth = local_18.wMonth + sVar3;
    if ((local_18.wMonth == 2) && (0x1c < local_18.wDay)) {
      if (((local_18.wYear & 3) == 0) &&
         (((uint)local_18.wYear % 100 != 0 || ((uint)local_18.wYear % 400 == 0)))) {
        local_18.wDay = 0x1d;
      }
      else {
        local_18.wDay = 0x1c;
      }
    }
    else if (*(int *)(&DAT_40850074 + (uint)local_18.wMonth * 4) < (int)(uint)local_18.wDay) {
      local_18.wDay = *(WORD *)(&DAT_40850074 + (uint)local_18.wMonth * 4);
    }
    SystemTimeToVariantTime(&local_18,this);
  }
  FUN_4082d440(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



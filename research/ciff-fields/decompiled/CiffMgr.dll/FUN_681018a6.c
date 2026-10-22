// Source: CiffMgr.dll @ 681018a6; FUN_681018a6

void __thiscall FUN_681018a6(void *this,int param_1)

{
  double *pvtime;
  bool bVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  pvtime = (double *)((int)this + 8);
  uVar2 = FUN_68101adf(pvtime);
  if (((char)uVar2 != '\0') && (bVar1 = FUN_68101b38(&local_18,*pvtime), bVar1)) {
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
    else if (*(int *)(&DAT_681472c8 + (uint)local_18.wMonth * 4) < (int)(uint)local_18.wDay) {
      local_18.wDay = *(WORD *)(&DAT_681472c8 + (uint)local_18.wMonth * 4);
    }
    SystemTimeToVariantTime(&local_18,pvtime);
  }
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



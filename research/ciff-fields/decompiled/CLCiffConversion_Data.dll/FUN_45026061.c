// Source: CLCiffConversion_Data.dll @ 45026061; FUN_45026061

void __cdecl FUN_45026061(undefined8 *param_1)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  DWORD DVar4;
  DWORD DVar5;
  DWORD DVar6;
  longlong lVar7;
  undefined8 uVar8;
  _FILETIME local_c0;
  int local_b8;
  _TIME_ZONE_INFORMATION local_b4;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_b8 = 0;
  if (param_1 == (undefined8 *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_45027e29();
  }
  else {
    ___tzset();
    iVar3 = FUN_4502fda3(&local_b8);
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    *(short *)((int)param_1 + 10) = (short)(local_b8 / 0x3c);
    GetSystemTimeAsFileTime(&local_c0);
    DVar6 = local_c0.dwHighDateTime;
    DVar5 = local_c0.dwLowDateTime;
    lVar7 = __aulldiv(local_c0.dwLowDateTime,local_c0.dwHighDateTime,600000000,0);
    lVar1 = CONCAT44(DAT_45055354,DAT_45055350);
    if (lVar7 != lVar1) {
      DVar4 = GetTimeZoneInformation(&local_b4);
      DAT_450518e0 = 0xffffffff;
      DVar5 = local_c0.dwLowDateTime;
      DVar6 = local_c0.dwHighDateTime;
      lVar1 = lVar7;
      if (DVar4 != 0xffffffff) {
        if (((DVar4 == 2) && (local_b4.DaylightDate.wMonth != 0)) && (local_b4.DaylightBias != 0)) {
          DAT_450518e0 = 1;
        }
        else {
          DAT_450518e0 = 0;
        }
      }
    }
    DAT_45055354 = (undefined4)((ulonglong)lVar1 >> 0x20);
    DAT_45055350 = (undefined4)lVar1;
    *(short *)((int)param_1 + 0xc) = (short)DAT_450518e0;
    uVar8 = __aulldiv(DVar5,DVar6,10000,0);
    uVar8 = __aullrem((uint)uVar8,(uint)((ulonglong)uVar8 >> 0x20),1000,0);
    *(short *)(param_1 + 1) = (short)uVar8;
    uVar8 = __aulldiv(DVar5 + 0x2ac18000,DVar6 + 0xfe624e21 + (uint)(0xd53e7fff < DVar5),10000000,0)
    ;
    *param_1 = uVar8;
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



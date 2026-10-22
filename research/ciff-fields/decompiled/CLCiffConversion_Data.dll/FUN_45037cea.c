// Source: CLCiffConversion_Data.dll @ 45037cea; FUN_45037cea

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_45037cea(uint param_1)

{
  int *piVar1;
  HANDLE hFile;
  BOOL BVar2;
  ulong *puVar3;
  int iVar4;
  DWORD DVar5;
  undefined4 uVar6;
  
  DVar5 = 0;
  if (param_1 == 0xfffffffe) {
    piVar1 = __errno();
    *piVar1 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_45056ee8)) {
      iVar4 = (param_1 & 0x1f) * 0x40;
      if ((*(byte *)(iVar4 + 4 + (&DAT_45055ae0)[(int)param_1 >> 5]) & 1) != 0) {
        FUN_45036390(param_1);
        if ((*(byte *)(iVar4 + 4 + (&DAT_45055ae0)[(int)param_1 >> 5]) & 1) != 0) {
          hFile = (HANDLE)FUN_450364a4(param_1);
          BVar2 = FlushFileBuffers(hFile);
          if (BVar2 == 0) {
            DVar5 = GetLastError();
          }
          uVar6 = 0;
          if (DVar5 == 0) goto LAB_45037d9c;
          puVar3 = ___doserrno();
          *puVar3 = DVar5;
        }
        piVar1 = __errno();
        *piVar1 = 9;
        uVar6 = 0xffffffff;
LAB_45037d9c:
        FUN_45037db2();
        return uVar6;
      }
    }
    piVar1 = __errno();
    *piVar1 = 9;
    FUN_45027e29();
  }
  return 0xffffffff;
}



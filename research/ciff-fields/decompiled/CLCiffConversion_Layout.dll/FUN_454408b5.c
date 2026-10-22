// Source: CLCiffConversion_Layout.dll @ 454408b5; FUN_454408b5

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_454408b5(uint param_1)

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
    if ((-1 < (int)param_1) && (param_1 < DAT_454626e8)) {
      iVar4 = (param_1 & 0x1f) * 0x40;
      if ((*(byte *)(iVar4 + 4 + (&DAT_454612f8)[(int)param_1 >> 5]) & 1) != 0) {
        FUN_4543fe54(param_1);
        if ((*(byte *)(iVar4 + 4 + (&DAT_454612f8)[(int)param_1 >> 5]) & 1) != 0) {
          hFile = (HANDLE)FUN_4543ff68(param_1);
          BVar2 = FlushFileBuffers(hFile);
          if (BVar2 == 0) {
            DVar5 = GetLastError();
          }
          uVar6 = 0;
          if (DVar5 == 0) goto LAB_45440967;
          puVar3 = ___doserrno();
          *puVar3 = DVar5;
        }
        piVar1 = __errno();
        *piVar1 = 9;
        uVar6 = 0xffffffff;
LAB_45440967:
        FUN_4544097d();
        return uVar6;
      }
    }
    piVar1 = __errno();
    *piVar1 = 9;
    FUN_45432798();
  }
  return 0xffffffff;
}



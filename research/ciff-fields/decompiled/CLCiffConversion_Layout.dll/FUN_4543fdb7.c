// Source: CLCiffConversion_Layout.dll @ 4543fdb7; FUN_4543fdb7

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

int FUN_4543fdb7(void)

{
  FILE *pFVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  __lock(1);
  for (iVar3 = 3; iVar3 < DAT_454626e4; iVar3 = iVar3 + 1) {
    pFVar1 = *(FILE **)(DAT_454626e0 + iVar3 * 4);
    if (pFVar1 != (FILE *)0x0) {
      if ((pFVar1->_flag & 0x83) != 0) {
        iVar2 = FUN_45440a0a(pFVar1);
        if (iVar2 != -1) {
          iVar4 = iVar4 + 1;
        }
      }
      if (0x13 < iVar3) {
        DeleteCriticalSection((LPCRITICAL_SECTION)(*(int *)(DAT_454626e0 + iVar3 * 4) + 0x20));
        FID_conflict__free(*(void **)(DAT_454626e0 + iVar3 * 4));
        *(undefined4 *)(DAT_454626e0 + iVar3 * 4) = 0;
      }
    }
  }
  FUN_4543fe4b();
  return iVar4;
}



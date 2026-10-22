// Source: CLCiffConversion_Layout.dll @ 4543fe54; FUN_4543fe54

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_4543fe54(uint param_1)

{
  int iVar1;
  
  iVar1 = (param_1 & 0x1f) * 0x40 + (&DAT_454612f8)[(int)param_1 >> 5];
  if (*(int *)(iVar1 + 8) == 0) {
    __lock(10);
    if (*(int *)(iVar1 + 8) == 0) {
      FUN_454396de((LPCRITICAL_SECTION)(iVar1 + 0xc),4000,0);
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    FUN_4543fed9();
  }
  EnterCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_454612f8)[(int)param_1 >> 5] + 0xc + (param_1 & 0x1f) * 0x40));
  return 1;
}



// Source: CLCiffConversion_Layout.dll @ 45440ab7; FUN_45440ab7

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

uint __cdecl FUN_45440ab7(uint param_1,LPWSTR param_2,uint param_3)

{
  ulong *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 == 0xfffffffe) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
    return 0xffffffff;
  }
  if (((int)param_1 < 0) || (DAT_454626e8 <= param_1)) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
  }
  else {
    iVar4 = (param_1 & 0x1f) * 0x40;
    if ((*(byte *)((&DAT_454612f8)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      if (param_3 < 0x80000000) {
        FUN_4543fe54(param_1);
        if ((*(byte *)((&DAT_454612f8)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) {
          piVar2 = __errno();
          *piVar2 = 9;
          puVar1 = ___doserrno();
          *puVar1 = 0;
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = FUN_45440bcb(param_1,param_2,param_3);
        }
        FUN_45440ba3();
        return uVar3;
      }
      puVar1 = ___doserrno();
      *puVar1 = 0;
      piVar2 = __errno();
      *piVar2 = 0x16;
      goto LAB_45440bbd;
    }
    puVar1 = ___doserrno();
    *puVar1 = 0;
  }
  piVar2 = __errno();
  *piVar2 = 9;
LAB_45440bbd:
  FUN_45432798();
  return 0xffffffff;
}



// Source: CLCiffConversion_Data.dll @ 45037e09; FUN_45037e09

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

uint __cdecl FUN_45037e09(uint param_1,LPWSTR param_2,uint param_3)

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
  if (((int)param_1 < 0) || (DAT_45056ee8 <= param_1)) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
  }
  else {
    iVar4 = (param_1 & 0x1f) * 0x40;
    if ((*(byte *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      if (param_3 < 0x80000000) {
        FUN_45036390(param_1);
        if ((*(byte *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) {
          piVar2 = __errno();
          *piVar2 = 9;
          puVar1 = ___doserrno();
          *puVar1 = 0;
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = FUN_45037f1d(param_1,param_2,param_3);
        }
        FUN_45037ef5();
        return uVar3;
      }
      puVar1 = ___doserrno();
      *puVar1 = 0;
      piVar2 = __errno();
      *piVar2 = 0x16;
      goto LAB_45037f0f;
    }
    puVar1 = ___doserrno();
    *puVar1 = 0;
  }
  piVar2 = __errno();
  *piVar2 = 9;
LAB_45037f0f:
  FUN_45027e29();
  return 0xffffffff;
}



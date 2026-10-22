// Source: CLCiffConversion_Data.dll @ 450333d6; FUN_450333d6

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined8 __cdecl
FUN_450333d6(uint param_1,undefined4 param_2,undefined4 param_3,PLARGE_INTEGER param_4)

{
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (param_1 == 0xfffffffe) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
  }
  else {
    if ((-1 < (int)param_1) && (param_1 < DAT_45056ee8)) {
      iVar3 = (param_1 & 0x1f) * 0x40;
      if ((*(byte *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + iVar3) & 1) != 0) {
        FUN_45036390(param_1);
        if ((*(byte *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + iVar3) & 1) == 0) {
          piVar2 = __errno();
          *piVar2 = 9;
          puVar1 = ___doserrno();
          *puVar1 = 0;
          uVar4 = 0xffffffffffffffff;
        }
        else {
          uVar4 = FUN_450334d2(param_1,param_2,param_3,param_4);
        }
        FUN_450334a8();
        return uVar4;
      }
    }
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
    FUN_45027e29();
  }
  return 0xffffffffffffffff;
}



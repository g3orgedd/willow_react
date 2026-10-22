// Source: CLCiffConversion_Data.dll @ 45032a82; FUN_45032a82

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_45032a82(WCHAR *param_1,WCHAR *param_2,uint param_3)

{
  ulong *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == (WCHAR *)0xfffffffe) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
  }
  else {
    if (((int)param_1 < 0) || (DAT_45056ee8 <= param_1)) {
      puVar1 = ___doserrno();
      *puVar1 = 0;
    }
    else {
      iVar4 = ((uint)param_1 & 0x1f) * 0x40;
      if ((*(byte *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
        FUN_45036390((uint)param_1);
        if ((*(byte *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + iVar4) & 1) == 0) {
          piVar2 = __errno();
          *piVar2 = 9;
          puVar1 = ___doserrno();
          *puVar1 = 0;
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = FUN_45032b71(param_1,param_2,param_3);
        }
        FUN_45032b49();
        return uVar3;
      }
      puVar1 = ___doserrno();
      *puVar1 = 0;
    }
    piVar2 = __errno();
    *piVar2 = 9;
    FUN_45027e29();
  }
  return 0xffffffff;
}



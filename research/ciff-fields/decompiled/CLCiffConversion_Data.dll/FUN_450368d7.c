// Source: CLCiffConversion_Data.dll @ 450368d7; FUN_450368d7

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

uint __cdecl FUN_450368d7(uint param_1,FILE *param_2)

{
  int *piVar1;
  uint uVar2;
  
  if (param_2 == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_45027e29();
    uVar2 = 0xffffffff;
  }
  else {
    __lock_file(param_2);
    uVar2 = FUN_450367f7(param_1,param_2);
    FUN_4503693f();
  }
  return uVar2;
}



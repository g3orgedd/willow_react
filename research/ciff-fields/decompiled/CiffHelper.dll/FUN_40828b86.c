// Source: CiffHelper.dll @ 40828b86; FUN_40828b86

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_40828b86(int *param_1,double *param_2)

{
  int iVar1;
  int local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = 0;
  local_8 = 0;
  iVar1 = FUN_408286d0(param_1,local_1c);
  if (-1 < iVar1) {
    FUN_40828bd6(local_1c,param_2);
  }
  local_8 = 0xffffffff;
  FUN_408290fb(local_1c);
  return iVar1;
}



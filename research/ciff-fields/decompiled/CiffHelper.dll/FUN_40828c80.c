// Source: CiffHelper.dll @ 40828c80; FUN_40828c80

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

double * __cdecl FUN_40828c80(double *param_1,int *param_2,int *param_3,double *param_4)

{
  undefined **local_24;
  int local_20 [3];
  undefined1 local_11 [9];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_24 = CCheckedResolveDateOffsets::vftable;
  local_20[0] = 0;
  local_20[1] = 0;
  local_20[2] = 0;
  local_8 = 0;
  FUN_40828cca(local_11,param_1,(int *)&local_24,param_2,param_3,param_4);
  FUN_4082912f(local_20);
  return param_1;
}



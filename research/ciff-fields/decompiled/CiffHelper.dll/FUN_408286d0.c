// Source: CiffHelper.dll @ 408286d0; FUN_408286d0

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_408286d0(int *param_1,void *param_2)

{
  int iVar1;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar1 = (**(code **)(*param_1 + 0x10c))(param_1,local_14);
  if (-1 < iVar1) {
    iVar1 = FUN_40828555(local_14,FUN_40828671,param_2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar1;
}



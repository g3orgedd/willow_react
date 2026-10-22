// Source: CLCiffConversion_Data.dll @ 45019853; FUN_45019853

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl FUN_45019853(undefined4 *param_1,undefined *param_2,void *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar1 = param_1;
  uStack_4 = 4;
  local_8 = 0x4501985f;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,&param_1);
  if (-1 < iVar2) {
    if (param_1 == (undefined4 *)0x0) {
      iVar2 = 1;
    }
    else {
      FUN_45019b81(param_3,(uint)param_1);
      iVar2 = 0;
      if (0 < (int)param_1) {
        do {
          local_14[0] = (int *)0x0;
          local_8 = 0;
          iVar2 = iVar2 + 1;
          iVar3 = (**(code **)(*(int *)*puVar1 + 0x20))((int *)*puVar1,iVar2,local_14);
          if ((iVar3 < 0) || (iVar3 = (*(code *)param_2)(local_14[0],param_3), iVar3 < 0)) {
            local_8 = 0xffffffff;
            if (local_14[0] == (int *)0x0) {
              return iVar3;
            }
            (**(code **)(*local_14[0] + 8))(local_14[0]);
            return iVar3;
          }
          local_8 = 0xffffffff;
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
        } while (iVar2 < (int)param_1);
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}



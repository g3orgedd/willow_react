// Source: CiffMgr.dll @ 681023dc; FUN_681023dc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __cdecl
FUN_681023dc(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,void *param_5)

{
  int *piVar1;
  int iVar2;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 4;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_1 + 0xbc))((int *)*param_1,param_3,local_14);
  if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
    param_1 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar2 = (**(code **)(*(int *)*piVar1 + 0xc4))((int *)*piVar1,param_4,&param_1);
    if ((-1 < iVar2) &&
       ((param_1 != (int *)0x0 &&
        (iVar2 = (**(code **)(*local_14[0] + 0x54))(local_14[0],param_1,0), -1 < iVar2)))) {
      iVar2 = (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,local_14[0],0);
    }
    FUN_68102161(param_5,(int *)local_14);
    local_8 = local_8 & 0xffffff00;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



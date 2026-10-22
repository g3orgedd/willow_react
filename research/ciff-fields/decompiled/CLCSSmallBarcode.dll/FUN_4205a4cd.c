// Source: CLCSSmallBarcode.dll @ 4205a4cd; FUN_4205a4cd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_4205a4cd(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  int *piVar5;
  int *piVar6;
  double local_2c;
  undefined4 local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x4205a4d9;
  FUN_42002e41(&local_24);
  puVar1 = param_4;
  local_8 = 0;
  (**(code **)(*(int *)*param_4 + 0x78))((int *)*param_4,param_1);
  piVar3 = param_1 + 1;
  (**(code **)(*(int *)*puVar1 + 0x80))((int *)*puVar1,piVar3);
  if (*piVar3 == 0) {
    *piVar3 = 1;
  }
  if (*param_1 == 0) {
    *param_1 = 1;
  }
  local_18 = 1;
  (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,&local_18);
  if (local_18 == 0) {
    piVar5 = (int *)*param_3;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    iVar2 = FUN_42003ac3(*piVar3,0.0,piVar5);
    *piVar3 = iVar2;
  }
  else {
    (**(code **)(*(int *)*puVar1 + 0x80))((int *)*puVar1,piVar3);
  }
  local_14[0] = 0;
  (**(code **)(*(int *)*puVar1 + 0xb0))((int *)*puVar1,local_14);
  local_1c = 0;
  (**(code **)(*(int *)*puVar1 + 0x108))((int *)*puVar1,&local_1c);
  local_2c = 0.0;
  piVar3 = local_20;
  if (local_1c == 0) {
    param_4 = (undefined4 *)0x0;
    (**(code **)(*(int *)*puVar1 + 0xc0))((int *)*puVar1,&param_4);
    param_2 = (undefined4 *)0x0;
    (**(code **)(*local_20 + 0x1c))(local_14[0],param_4 == (undefined4 *)0x1,&param_2);
    local_2c = (double)((float)param_2 + 0.0);
    piVar3 = local_20;
  }
  piVar6 = param_3;
  piVar5 = (int *)*param_3;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))(piVar5);
  }
  iVar2 = FUN_42003ac3((int)*(double *)(piVar3 + 0xc),1.4013e-45,piVar5);
  *param_1 = iVar2;
  piVar3 = (int *)*piVar6;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))(piVar3);
  }
  iVar2 = FUN_42003a36(*param_1,1.4013e-45,piVar3);
  *param_1 = iVar2;
  piVar6 = (int *)*piVar6;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))(piVar6);
  }
  fVar4 = 1.4013e-45;
  iVar2 = FUN_42004376(((double)*param_1 * (double)local_14[0]) / DAT_42089818 - local_2c);
  iVar2 = FUN_42003ac3(iVar2,fVar4,piVar6);
  local_8 = 0xffffffff;
  *param_1 = iVar2;
  FUN_420030e8(&local_24);
  return 0;
}



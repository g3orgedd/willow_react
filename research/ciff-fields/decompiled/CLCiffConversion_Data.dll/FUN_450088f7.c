// Source: CLCiffConversion_Data.dll @ 450088f7; FUN_450088f7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __fastcall FUN_450088f7(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  piVar1 = (int *)param_1[6];
  local_8 = 5;
  if (piVar1 != (int *)0x0) {
    param_1[6] = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = param_1 + 4;
  local_14[0] = *(int *)*piVar1;
  if ((int *)local_14[0] != (int *)*piVar1) {
    do {
      piVar2 = *(int **)(local_14[0] + 0x14);
      if (piVar2 != (int *)0x0) {
        *(undefined4 *)(local_14[0] + 0x14) = 0;
        (**(code **)(*piVar2 + 8))(piVar2);
      }
      FUN_45005947(local_14);
    } while (local_14[0] != *piVar1);
  }
  if (param_1[3] != 0) {
    (**(code **)(*(int *)param_1[3] + 0x38))((int *)param_1[3]);
  }
  piVar2 = (int *)param_1[3];
  if (piVar2 != (int *)0x0) {
    param_1[3] = 0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  piVar2 = (int *)param_1[6];
  local_8._0_1_ = 4;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  FUN_450088b8(piVar1);
  piVar1 = (int *)param_1[3];
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_45002256(param_1 + 2);
  FUN_45002256(param_1 + 1);
  FUN_45002256(param_1);
  return;
}



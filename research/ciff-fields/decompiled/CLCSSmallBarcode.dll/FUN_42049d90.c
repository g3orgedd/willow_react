// Source: CLCSSmallBarcode.dll @ 42049d90; FUN_42049d90

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_42049d90(int *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int *local_24;
  char local_20 [24];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x42049d9c;
  FUN_42002e41(&local_3c);
  local_8 = 0;
  local_28 = 0x32;
  local_30 = 700;
  local_34 = 700;
  CComQIPtr<>(&local_24,(undefined4 *)*param_4);
  local_8._0_1_ = 1;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 0x164))(local_24,&local_38);
    FUN_4206ce87(local_38,local_20,10,10);
    FUN_42002f14(&local_2c,local_20);
    local_8._0_1_ = 2;
    FUN_4202c07e(local_38,&local_30,&local_34);
    (**(code **)(*local_24 + 0x15c))(local_24,&local_28);
    local_8._0_1_ = 1;
    FUN_42003103(&local_2c);
  }
  piVar2 = (int *)*param_3;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  iVar1 = FUN_42003ac3(local_30 * local_28,1.4013e-45,piVar2);
  *param_1 = iVar1;
  piVar2 = (int *)*param_3;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  iVar1 = FUN_42003ac3(local_34 * local_28,0.0,piVar2);
  param_1[1] = iVar1;
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  local_8 = 0xffffffff;
  FUN_420030e8(&local_3c);
  FUN_4206a64e();
  return;
}



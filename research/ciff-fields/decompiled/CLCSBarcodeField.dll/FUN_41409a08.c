// Source: CLCSBarcodeField.dll @ 41409a08; FUN_41409a08

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_41409a08(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  puVar3 = param_4;
  piVar2 = param_1;
  uStack_4 = 4;
  local_8 = 0x41409a14;
  (**(code **)(*(int *)*param_4 + 0x78))((int *)*param_4,param_1);
  piVar1 = piVar2 + 1;
  (**(code **)(*(int *)*puVar3 + 0x80))((int *)*puVar3,piVar1);
  if (*piVar2 == 0) {
    *piVar2 = 1;
  }
  if (*piVar1 == 0) {
    *piVar1 = 1;
  }
  param_4 = (undefined4 *)0x1;
  (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,&param_4);
  if (param_4 == (undefined4 *)0x0) {
    FUN_4144c328(local_14);
    piVar6 = param_3;
    local_8 = 0;
    piVar5 = (int *)*param_3;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(piVar5);
    }
    iVar4 = FUN_4144c3fb(*piVar2,1.4013e-45,piVar5);
    *piVar2 = iVar4;
    piVar6 = (int *)*piVar6;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 4))(piVar6);
    }
    iVar4 = FUN_4144c3fb(*piVar1,0.0,piVar6);
    local_8 = 0xffffffff;
    *piVar1 = iVar4;
    FUN_4144c348(local_14);
  }
  else {
    param_1 = (int *)0x0;
    (**(code **)(*(int *)*puVar3 + 0x78))((int *)*puVar3,&param_1);
    param_2 = (undefined4 *)0x0;
    (**(code **)(*(int *)*puVar3 + 0x80))((int *)*puVar3,&param_2);
    *piVar2 = (int)param_1;
    *piVar1 = (int)param_2;
  }
  return 0;
}



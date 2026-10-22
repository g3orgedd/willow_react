// Source: CLCSSmallBarcode.dll @ 42003ac3; FUN_42003ac3

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __cdecl FUN_42003ac3(int param_1,float param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uStack_2c;
  int *piStack_28;
  float *pfStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  pfStack_24 = &param_2;
  local_8 = 0;
  piStack_28 = param_3;
  if (param_2 == 1.4013e-45) {
    puVar5 = &uStack_2c;
    uStack_2c = 0x42003ae6;
    (**(code **)(*param_3 + 0x2c))();
    uVar4 = extraout_ECX;
  }
  else {
    puVar5 = &uStack_2c;
    uStack_2c = 0x42003aeb;
    (**(code **)(*param_3 + 0x34))();
    uVar4 = extraout_ECX_00;
  }
  *(undefined4 *)((int)puVar5 + -4) = uVar4;
  *(float *)((int)puVar5 + -4) = (float)param_1 * param_2;
  *(undefined4 *)((int)puVar5 + -8) = 0x42003b03;
  iVar3 = FUN_4200434d(*(float *)((int)puVar5 + -4));
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    iVar1 = *param_3;
    *(int **)((int)puVar5 + -4) = param_3;
    pcVar2 = *(code **)(iVar1 + 8);
    puVar6 = (undefined4 *)((int)puVar5 + -8);
    puVar5 = (undefined4 *)((int)puVar5 + -8);
    *puVar6 = 0x42003b17;
    (*pcVar2)();
  }
  *(undefined4 *)((int)puVar5 + -4) = 0x42003b1e;
  return iVar3;
}



// Source: CLCSSmallBarcode.dll @ 42046180; FUN_42046180

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_42046180(BSTR param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int *piVar2;
  UINT UVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int local_38 [3];
  uint local_2c;
  BSTR local_28;
  int *local_24;
  int local_20;
  int local_1c;
  float local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_4;
  uStack_4 = 0x28;
  local_8 = 0x4204618c;
  iVar4 = *(int *)(param_1 + 6);
  iVar5 = *(int *)(param_1 + 2);
  iVar7 = *(int *)(param_1 + 4) - *(int *)param_1;
  (**(code **)(*(int *)*param_4 + 0xb0))((int *)*param_4,&local_1c);
  (**(code **)(*(int *)*piVar2 + 0x84))((int *)*piVar2,iVar4 - iVar5);
  (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,&local_20);
  local_28 = (BSTR)0x0;
  local_8 = 0;
  (**(code **)(*(int *)*piVar2 + 0x98))((int *)*piVar2,&local_28);
  (**(code **)(*(int *)*piVar2 + 0xf0))((int *)*piVar2,&local_2c);
  uVar6 = (int)local_2c >> 8;
  local_2c = local_2c & 0xff;
  uVar1 = local_2c;
  if ((int)uVar6 < (int)local_2c) {
    uVar1 = uVar6;
    uVar6 = local_2c;
  }
  param_1 = (BSTR)0x0;
  param_4 = (int *)((float)(int)uVar6 / (float)(int)uVar1);
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*(int *)*piVar2 + 0x98))((int *)*piVar2,&param_1);
  UVar3 = SysStringLen(param_1);
  local_14[0] = 0;
  param_4 = (int *)((float)(int)(UVar3 + 2) * ((float)param_4 * _DAT_4209d574 + _DAT_4209d578));
  (**(code **)(*(int *)*piVar2 + 0x108))((int *)*piVar2,local_14);
  piVar8 = param_4;
  if (local_14[0] == 1) {
    piVar8 = (int *)((float)param_4 + _DAT_4209d57c);
  }
  param_4 = (int *)FUN_4200434d((float)piVar8);
  piVar8 = param_3;
  (**(code **)(*(int *)*param_3 + 0x2c))((int *)*param_3,&local_18);
  if (local_20 == 0) {
    iVar7 = FUN_4200434d((float)iVar7 * local_18);
  }
  iVar4 = (int)((double)iVar7 / (double)(int)param_4);
  if ((int)((double)iVar7 / (double)(int)param_4) < 2) {
    iVar4 = 1;
  }
  for (iVar4 = iVar4 * 1000; local_1c = (int)((float)iVar4 / (local_18 * _DAT_4208982c)),
      0x5db < local_1c; iVar4 = iVar4 + -1000) {
  }
  (**(code **)(*(int *)*piVar2 + 0xb4))((int *)*piVar2,local_1c);
  local_38[0] = 0;
  local_38[1] = 0;
  (**(code **)(*local_24 + 0xc))(local_38,param_2,piVar8,piVar2);
  FUN_42002e41(local_38 + 2);
  local_8._0_1_ = 2;
  if (local_20 == 0) {
    piVar8 = (int *)*piVar8;
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 4))(piVar8);
    }
    local_38[0] = FUN_42003a36(local_38[0],1.4013e-45,piVar8);
  }
  piVar8 = (int *)*piVar2;
  iVar4 = *piVar8;
  iVar5 = FUN_42004376((double)local_38[0]);
  (**(code **)(iVar4 + 0x7c))(piVar8,iVar5);
  FUN_42066bbc(param_2,param_3,piVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_420030e8(local_38 + 2);
  SysFreeString(param_1);
  SysFreeString(local_28);
  return 0;
}



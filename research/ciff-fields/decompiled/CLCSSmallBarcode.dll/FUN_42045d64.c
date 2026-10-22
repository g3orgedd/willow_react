// Source: CLCSSmallBarcode.dll @ 42045d64; FUN_42045d64

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_42045d64(int *param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  UINT UVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  int *piVar8;
  undefined4 local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  BSTR local_18;
  float local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x42045d70;
  FUN_42002e41(&local_2c);
  local_8 = 0;
  (**(code **)(*(int *)*param_4 + 0x78))((int *)*param_4,param_1);
  piVar1 = param_1 + 1;
  (**(code **)(*(int *)*param_4 + 0x80))((int *)*param_4,piVar1);
  if (*piVar1 == 0) {
    *piVar1 = 1;
  }
  if (*param_1 == 0) {
    *param_1 = 1;
  }
  local_1c = 1;
  (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,&local_1c);
  if (local_1c == 0) {
    piVar8 = (int *)*param_3;
    if (piVar8 != (int *)0x0) {
      (**(code **)(*piVar8 + 4))(piVar8);
    }
    iVar3 = FUN_42003ac3(*piVar1,0.0,piVar8);
    *piVar1 = iVar3;
  }
  else {
    (**(code **)(*(int *)*param_4 + 0x80))((int *)*param_4,piVar1);
  }
  local_18 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*(int *)*param_4 + 0x98))((int *)*param_4,&local_18);
  UVar4 = SysStringLen(local_18);
  (**(code **)(*(int *)*param_4 + 0xf0))((int *)*param_4,&local_28);
  uVar5 = (int)(local_28 + ((int)local_28 >> 0x1f & 0xffU)) >> 8;
  local_28 = local_28 & 0x800000ff;
  if ((int)local_28 < 0) {
    local_28 = (local_28 - 1 | 0xffffff00) + 1;
  }
  uVar2 = local_28;
  if ((int)uVar5 < (int)local_28) {
    uVar2 = uVar5;
    uVar5 = local_28;
  }
  (**(code **)(*(int *)*param_4 + 0xb0))((int *)*param_4,&local_24);
  (**(code **)(*(int *)*param_3 + 0x2c))((int *)*param_3,local_14);
  local_14[0] = local_14[0] * _DAT_4208982c;
  iVar3 = FUN_4200434d(((float)local_24 * local_14[0]) / DAT_4209d580);
  local_20 = 0;
  fVar7 = (((float)(int)uVar5 / (float)(int)uVar2) * _DAT_4209d574 + _DAT_4209d578) *
          (float)(int)(UVar4 + 2) * (float)iVar3 + (float)(int)((UVar4 + 1) * iVar3);
  (**(code **)(*(int *)*param_4 + 0x108))((int *)*param_4,&local_20);
  if (local_20 == 1) {
    if (local_24 < 0xfb) {
      fVar6 = local_14[0] * _DAT_4209d570 * DAT_4209d56c;
    }
    else {
      fVar6 = (float)(iVar3 * 0x14);
    }
    fVar7 = fVar6 + fVar7;
  }
  iVar3 = FUN_4200434d(fVar7);
  *param_1 = iVar3;
  SysFreeString(local_18);
  local_8 = 0xffffffff;
  FUN_420030e8(&local_2c);
  return 0;
}



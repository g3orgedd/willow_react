// Source: CLCSSmallBarcode.dll @ 4205e132; FUN_4205e132

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_4205e132(void *this,int *param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float local_28;
  int local_24;
  float local_20;
  int local_1c;
  int local_18;
  float local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x4205e13e;
  uVar3 = 0x80004003;
  CComQIPtr<>(&param_4,(undefined4 *)*param_4);
  local_8 = 0;
  if (param_4 != (int *)0x0) {
    iVar1 = FUN_4203407d(*(void **)((int)this + 0x40),(int *)&param_4,&local_18);
    if (-1 < iVar1) {
      local_1c = 0;
      (**(code **)(*param_4 + 0x108))(param_4,&local_1c);
      if (local_1c == 1) {
        local_18 = local_18 + 8;
      }
    }
    fVar4 = (float)(param_1[2] - *param_1);
    local_20 = (float)(param_1[3] - param_1[1]);
    (**(code **)(*(int *)*param_3 + 0x2c))((int *)*param_3,local_14);
    (**(code **)(*(int *)*param_3 + 0x34))((int *)*param_3,&local_28);
    (**(code **)(*(int *)*param_2 + 0x54))((int *)*param_2,&local_24);
    fVar5 = local_20;
    if (local_24 == 1) {
      iVar1 = FUN_4200434d(local_14[0] * _DAT_4208982c);
      iVar2 = FUN_4200434d(local_28 * _DAT_4208982c);
      fVar4 = (fVar4 / (float)iVar1) * _DAT_4208982c;
      fVar5 = (local_20 / (float)iVar2) * _DAT_4208982c;
    }
    if (fVar5 < fVar4) {
      fVar4 = fVar5;
    }
    iVar1 = FUN_4200434d(fVar4 / (float)local_18);
    iVar1 = FUN_4200434d((float)iVar1 * local_14[0]);
    if ((int)(local_14[0] * _DAT_4209e278) < iVar1) {
      iVar1 = (int)(local_14[0] * _DAT_4209e278);
    }
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    iVar2 = (int)((float)iVar1 / local_14[0]) * local_18;
    (**(code **)(*param_4 + 0x160))(param_4,(int)((float)iVar1 / local_14[0]));
    (**(code **)(*param_4 + 0x7c))(param_4,iVar2);
    (**(code **)(*param_4 + 0x84))(param_4,iVar2);
    (**(code **)(*param_4 + 0xbc))(param_4,iVar2);
    uVar3 = 0;
  }
  local_8 = 0xffffffff;
  if (param_4 != (int *)0x0) {
    (**(code **)(*param_4 + 8))(param_4);
  }
  return uVar3;
}



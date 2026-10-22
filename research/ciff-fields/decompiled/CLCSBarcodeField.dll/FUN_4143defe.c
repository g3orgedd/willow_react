// Source: CLCSBarcodeField.dll @ 4143defe; FUN_4143defe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_4143defe(void *this,undefined4 *param_1,int *param_2,BSTR param_3,undefined4 *param_4,
            int param_5,int param_6)

{
  BSTR pOVar1;
  undefined4 *puVar2;
  uint uVar3;
  UINT UVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  double dVar10;
  int *piVar11;
  undefined1 local_48 [4];
  int local_44;
  undefined4 local_3c;
  int local_38;
  int *local_34;
  uint local_30;
  BSTR local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  float local_18;
  float local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x4143df0a;
  local_34 = this;
  FUN_4144c328(&local_3c);
  piVar11 = param_2;
  local_14[0] = 0.0;
  local_8 = 0;
  (**(code **)(*(int *)*param_2 + 0x2c))((int *)*param_2,local_14);
  local_14[0] = local_14[0] * _DAT_4148100c;
  local_18 = 0.0;
  (**(code **)(*(int *)*piVar11 + 0x34))((int *)*piVar11,&local_18);
  pOVar1 = param_3;
  local_18 = local_18 * _DAT_4148100c;
  (**(code **)(*(int *)this + 0x24))(param_3);
  puVar2 = param_4;
  (**(code **)(*(int *)*param_4 + 0x54))((int *)*param_4,*(undefined4 *)((int)this + 0x1c));
  piVar11 = (int *)*puVar2;
  (**(code **)(*piVar11 + 0x5c))(piVar11,*(undefined4 *)((int)this + 0x20));
  piVar11 = (int *)*puVar2;
  (**(code **)(*piVar11 + 100))(piVar11,*(undefined4 *)((int)this + 0x20));
  (**(code **)(**(int **)pOVar1 + 0x9c))(*(int **)pOVar1,*(undefined4 *)((int)this + 0x20));
  local_2c = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(**(int **)pOVar1 + 0x98))(*(int **)pOVar1,&local_2c);
  local_1c = 0;
  (**(code **)(**(int **)pOVar1 + 0xb0))(*(int **)pOVar1,&local_1c);
  uVar3 = FUN_414092db(((float)(int)local_1c * local_14[0]) / _DAT_41481014);
  uVar7 = uVar3 & 0x80000001;
  if ((int)uVar7 < 0) {
    uVar7 = (uVar7 - 1 | 0xfffffffe) + 1;
  }
  local_1c = uVar3;
  if (uVar7 != 0) {
    (**(code **)(**(int **)pOVar1 + 0xf4))(*(int **)pOVar1,0x103);
  }
  param_4 = (undefined4 *)0x0;
  (**(code **)(**(int **)pOVar1 + 0x108))(*(int **)pOVar1,&param_4);
  local_24 = 0;
  (**(code **)(**(int **)pOVar1 + 0x120))(*(int **)pOVar1,&local_24);
  param_3 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,2);
  (**(code **)(**(int **)pOVar1 + 0x98))(*(int **)pOVar1,&param_3);
  if (uVar7 == 1) {
    UVar4 = SysStringLen(param_3);
    iVar8 = (UVar4 + 1) * uVar3 * 9;
  }
  else {
    UVar4 = SysStringLen(param_3);
    iVar8 = FUN_41409304(((double)(int)(UVar4 << 3) +
                          *(double *)(&DAT_41483fc0 + ((int)(UVar4 << 3) >> 0x1f) * -8) +
                         _DAT_41484068) * (double)(int)uVar3);
  }
  if (param_4 == (undefined4 *)0x1) {
    iVar8 = iVar8 + local_1c * 0x14;
  }
  if (local_24 == 1) {
    iVar8 = iVar8 + local_1c * 7;
  }
  local_28 = 0;
  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,&local_28);
  iVar5 = param_5;
  if (local_28 == 0) {
    iVar5 = FUN_414092db(((float)param_5 * local_14[0]) / _DAT_4148100c);
  }
  param_5 = iVar5;
  if ((iVar5 != 0) && (iVar5 < iVar8)) {
    UVar4 = SysStringLen(param_3);
    dVar10 = (double)(int)(UVar4 << 3) +
             *(double *)(&DAT_41483fc0 + ((int)(UVar4 << 3) >> 0x1f) * -8);
    if (param_4 == (undefined4 *)0x1) {
      dVar10 = dVar10 + DAT_41484070;
    }
    uVar3 = FUN_41409304((double)param_5 / (dVar10 + _DAT_41484068));
    if ((int)uVar3 < 1) {
      uVar3 = 1;
    }
    local_30 = uVar3;
    param_5 = FUN_414092db(635.0);
    piVar11 = (int *)*param_2;
    if (piVar11 != (int *)0x0) {
      (**(code **)(*piVar11 + 4))(piVar11);
    }
    iVar8 = FUN_4144c3fb(param_5,1.4013e-45,piVar11);
    iVar6 = local_1c * 10;
    if (iVar6 - iVar8 != 0 && iVar8 <= iVar6) {
      iVar8 = iVar6;
    }
    if (param_4 == (undefined4 *)0x1) {
      iVar5 = iVar8 * 2;
    }
    uVar7 = uVar3 & 0x80000001;
    bVar9 = uVar7 == 0;
    if ((int)uVar7 < 0) {
      bVar9 = (uVar7 - 1 | 0xfffffffe) == 0xffffffff;
    }
    if (bVar9) {
      iVar8 = FUN_41409304((double)(int)uVar3 * _DAT_41484068);
      UVar4 = SysStringLen(param_3);
      iVar8 = iVar5 + iVar8 + UVar4 * local_30 * 8;
    }
    else {
      UVar4 = SysStringLen(param_3);
      iVar8 = iVar5 + (UVar4 + 1) * uVar3 * 9;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  SysFreeString(param_3);
  local_20 = 0;
  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,&local_20);
  if (local_20 == 0) {
    iVar8 = FUN_41409304((double)(iVar8 * 100) / (double)local_14[0]);
  }
  (**(code **)(*local_34 + 0x20))(pOVar1,param_2,local_34 + 8,local_48);
  (**(code **)(**(int **)pOVar1 + 0xb8))(*(int **)pOVar1,&local_38);
  iVar5 = 0;
  if (local_44 != 0) {
    if (local_20 == 0) {
      param_2 = (int *)0x0;
      (**(code **)(**(int **)pOVar1 + 0xb0))(*(int **)pOVar1,&param_2);
      local_44 = FUN_41409304((double)(local_44 * 100) / (double)local_18);
      iVar5 = ((int)param_2 * 0x21 + 500) / 1000;
    }
    else {
      iVar5 = FUN_41409304((double)local_18 / DAT_414825d8);
    }
    iVar5 = local_44 + iVar5;
  }
  iVar6 = iVar5 + local_38;
  if (param_6 < iVar5 + local_38) {
    iVar6 = param_6;
  }
  (**(code **)(**(int **)pOVar1 + 0x84))(*(int **)pOVar1,iVar6);
  (**(code **)(**(int **)pOVar1 + 0x7c))(*(int **)pOVar1,iVar8);
  SysFreeString(local_2c);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_3c);
  return 0;
}



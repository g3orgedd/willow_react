// Source: CLCSBarcodeField.dll @ 4142295e; FUN_4142295e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_4142295e(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,
            undefined4 *param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  BSTR extraout_ECX;
  int iVar6;
  int iVar7;
  BSTR pOVar8;
  undefined1 local_40 [4];
  int local_3c;
  undefined4 local_38;
  int local_34;
  int *local_30;
  int local_2c;
  int local_28;
  BSTR local_24;
  int local_20;
  int local_1c;
  float local_18;
  float local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x4142296a;
  local_30 = this;
  FUN_4144c328(&local_38);
  local_14 = 0.0;
  local_8 = 0;
  (**(code **)(*(int *)*param_2 + 0x2c))();
  local_14 = local_14 * _DAT_4148100c;
  local_18 = 0.0;
  (**(code **)(*(int *)*param_2 + 0x34))();
  puVar5 = param_3;
  local_18 = local_18 * _DAT_4148100c;
  (**(code **)(*(int *)this + 0x24))();
  puVar1 = param_4;
  (**(code **)(*(int *)*param_4 + 0x54))();
  (**(code **)(*(int *)*puVar1 + 0x5c))();
  (**(code **)(*(int *)*puVar1 + 100))();
  (**(code **)(*(int *)*puVar5 + 0x9c))();
  local_24 = (BSTR)0x0;
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*puVar5 + 0x98))();
  FUN_4144d140(&param_4);
  local_8._0_1_ = 2;
  pOVar8 = extraout_ECX;
  FUN_41402eab(&stack0xffffff6c,(int *)&local_24);
  uVar2 = FUN_4144d19d(pOVar8);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4144d149(&param_4);
  (**(code **)(*(int *)*puVar5 + 0xb0))();
  iVar3 = FUN_414092db(((float)local_28 * local_14) / _DAT_41481014);
  local_1c = 0;
  (**(code **)(*(int *)*param_3 + 0x108))((int *)*param_3,&local_1c);
  local_2c = iVar3 * 0x14;
  iVar7 = uVar2 * 0xb;
  iVar6 = 0;
  if (local_1c == 1) {
    iVar6 = local_2c;
  }
  local_20 = 0;
  param_4 = (undefined4 *)(iVar7 + 0x23);
  iVar6 = iVar6 + (int)param_4 * iVar3;
  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,&local_20);
  iVar3 = local_20;
  iVar4 = param_5;
  if (local_20 == 0) {
    iVar4 = FUN_414092db(((float)param_5 * local_14) / _DAT_4148100c);
  }
  if ((iVar4 != 0) && (iVar4 < iVar6)) {
    if (local_1c == 1) {
      iVar7 = iVar7 + 0x14;
    }
    iVar4 = iVar4 / (iVar7 + 0x23);
    if (iVar4 < 1) {
      iVar4 = 1;
    }
    puVar5 = param_4;
    if (local_1c == 1) {
      puVar5 = (undefined4 *)((int)param_4 + local_2c);
    }
    iVar6 = iVar4 * (int)puVar5;
  }
  if (iVar3 == 0) {
    iVar6 = FUN_41409304((double)(iVar6 * 100) / (double)local_14);
  }
  puVar5 = param_3;
  (**(code **)(*local_30 + 0x20))(param_3,param_2,local_30 + 8,local_40);
  (**(code **)(*(int *)*puVar5 + 0xb8))((int *)*puVar5,&local_34);
  iVar3 = 0;
  if (local_3c != 0) {
    if (local_20 == 0) {
      param_3 = (undefined4 *)0x0;
      (**(code **)(*(int *)*puVar5 + 0xb0))((int *)*puVar5,&param_3);
      local_3c = FUN_41409304((double)(local_3c * 100) / (double)local_18);
      iVar3 = ((int)param_3 * 0x21 + 500) / 1000;
    }
    else {
      iVar3 = FUN_41409304((double)local_18 / DAT_414825d8);
    }
    iVar3 = local_3c + iVar3;
  }
  iVar7 = iVar3 + local_34;
  if (param_6 < iVar3 + local_34) {
    iVar7 = param_6;
  }
  (**(code **)(*(int *)*puVar5 + 0x84))((int *)*puVar5,iVar7);
  (**(code **)(*(int *)*puVar5 + 0x7c))((int *)*puVar5,iVar6);
  SysFreeString(local_24);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_38);
  return 0;
}



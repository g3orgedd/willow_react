// Source: CLCSBarcodeField.dll @ 41442744; FUN_41442744

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_41442744(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,
            undefined4 *param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  BSTR extraout_ECX;
  int iVar6;
  BSTR pOVar7;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  BSTR local_20;
  float local_1c;
  int local_18;
  float local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x41442750;
  FUN_4144c328(&local_30);
  puVar1 = param_2;
  local_14 = 0.0;
  local_8 = 0;
  (**(code **)(*(int *)*param_2 + 0x2c))();
  local_14 = local_14 * _DAT_4148100c;
  local_1c = 0.0;
  (**(code **)(*(int *)*puVar1 + 0x34))();
  puVar1 = param_3;
  local_1c = local_1c * _DAT_4148100c;
  (**(code **)(*(int *)this + 0x24))();
  puVar2 = param_4;
  (**(code **)(*(int *)*param_4 + 0x54))();
  (**(code **)(*(int *)*puVar2 + 0x5c))();
  (**(code **)(*(int *)*puVar2 + 100))();
  (**(code **)(*(int *)*puVar1 + 0x9c))();
  local_20 = (BSTR)0x0;
  local_8._0_1_ = 1;
  (**(code **)(*(int *)*puVar1 + 0x98))();
  FUN_4144d140(&param_2);
  local_8._0_1_ = 2;
  pOVar7 = extraout_ECX;
  FUN_41402eab(&stack0xffffff7c,(int *)&local_20);
  param_4 = (undefined4 *)FUN_4144d19d(pOVar7);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_4144d149(&param_2);
  local_24 = 0;
  (**(code **)(*(int *)*puVar1 + 0xb0))();
  iVar3 = FUN_414092db(((float)local_24 * local_14) / _DAT_41481014);
  local_18 = 0;
  local_2c = iVar3 * 10;
  (**(code **)(*(int *)*puVar1 + 0x108))((int *)*puVar1,&local_18);
  iVar4 = 0;
  if (local_18 == 1) {
    iVar4 = iVar3 * 0x14;
  }
  iVar6 = (int)param_4 * 0xb;
  local_28 = 0;
  iVar3 = (iVar6 + 0x23 + iVar4) * iVar3;
  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,&local_28);
  iVar4 = local_28;
  iVar5 = param_5;
  if (local_28 == 0) {
    iVar5 = FUN_414092db(((float)param_5 * local_14) / _DAT_4148100c);
  }
  if (iVar3 - iVar5 != 0 && iVar5 <= iVar3) {
    iVar3 = iVar6;
    if (local_18 == 1) {
      iVar3 = iVar6 + 0x14;
    }
    iVar5 = iVar5 / (iVar3 + 0x23);
    iVar6 = iVar6 + 0x23;
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    if (local_18 == 1) {
      iVar6 = iVar6 + local_2c * 2;
    }
    iVar3 = iVar5 * iVar6;
  }
  if (iVar4 == 0) {
    iVar3 = FUN_41409304((double)(iVar3 * 100) / (double)local_14);
    iVar6 = 0x27b;
  }
  else {
    iVar6 = 0x27b;
    if (iVar4 == 1) {
      iVar6 = FUN_414092db((local_1c * _DAT_41484220) / _DAT_4148100c);
    }
  }
  if ((double)iVar6 < (double)iVar3 * _DAT_41484208) {
    iVar6 = FUN_41409304((double)iVar3 * _DAT_41484208);
  }
  puVar1 = param_3;
  if (param_6 < iVar6) {
    iVar6 = param_6;
  }
  (**(code **)(*(int *)*param_3 + 0x84))((int *)*param_3,iVar6);
  (**(code **)(*(int *)*puVar1 + 0x7c))((int *)*puVar1,iVar3);
  SysFreeString(local_20);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_30);
  return 0;
}



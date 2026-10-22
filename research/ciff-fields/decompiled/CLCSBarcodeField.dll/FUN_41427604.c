// Source: CLCSBarcodeField.dll @ 41427604; FUN_41427604

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_41427604(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,BSTR param_4,
            int param_5,int param_6)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  BSTR pOVar6;
  BSTR extraout_ECX;
  int iVar7;
  int iVar8;
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
  local_8 = 0x41427610;
  local_30 = this;
  FUN_4144c328(&local_38);
  local_14 = 0.0;
  local_8 = 0;
  (**(code **)(*(int *)*param_2 + 0x2c))();
  local_14 = local_14 * _DAT_4148100c;
  local_18 = 0.0;
  (**(code **)(*(int *)*param_2 + 0x34))();
  puVar2 = param_3;
  local_18 = local_18 * _DAT_4148100c;
  (**(code **)(*(int *)this + 0x24))();
  pOVar6 = param_4;
  (**(code **)(**(int **)param_4 + 0x54))();
  (**(code **)(**(int **)pOVar6 + 0x5c))();
  (**(code **)(**(int **)pOVar6 + 100))();
  piVar1 = (int *)*puVar2;
  FUN_41402f15(&param_4,L"æ0105012345123455");
  local_8._0_1_ = 1;
  (**(code **)(*piVar1 + 0x9c))();
  SysFreeString(param_4);
  local_24 = (BSTR)0x0;
  local_8._0_1_ = 2;
  (**(code **)(*(int *)*puVar2 + 0x98))();
  FUN_4144d140(&param_4);
  local_8._0_1_ = 3;
  pOVar6 = extraout_ECX;
  FUN_41402eab(&stack0xffffff6c,(int *)&local_24);
  uVar3 = FUN_4144d19d(pOVar6);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_4144d149(&param_4);
  local_28 = 0;
  (**(code **)(*(int *)*puVar2 + 0xb0))();
  iVar4 = FUN_414092db(((float)local_28 * local_14) / _DAT_41481014);
  local_1c = 0;
  (**(code **)(*(int *)*param_3 + 0x108))((int *)*param_3,&local_1c);
  local_2c = iVar4 * 0x14;
  iVar8 = uVar3 * 0xb;
  iVar7 = 0;
  if (local_1c == 1) {
    iVar7 = local_2c;
  }
  local_20 = 0;
  param_4 = (BSTR)(iVar8 + 0x23);
  iVar7 = iVar7 + (int)param_4 * iVar4;
  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,&local_20);
  iVar4 = local_20;
  iVar5 = param_5;
  if (local_20 == 0) {
    iVar5 = FUN_414092db(((float)param_5 * local_14) / _DAT_4148100c);
  }
  if ((iVar5 != 0) && (iVar5 < iVar7)) {
    if (local_1c == 1) {
      iVar8 = iVar8 + 0x14;
    }
    iVar5 = iVar5 / (iVar8 + 0x23);
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    pOVar6 = param_4;
    if (local_1c == 1) {
      pOVar6 = (BSTR)((int)param_4 + local_2c);
    }
    iVar7 = iVar5 * (int)pOVar6;
  }
  if (iVar4 == 0) {
    iVar7 = FUN_41409304((double)(iVar7 * 100) / (double)local_14);
  }
  puVar2 = param_3;
  (**(code **)(*local_30 + 0x20))(param_3,param_2,local_30 + 8,local_40);
  (**(code **)(*(int *)*puVar2 + 0xb8))((int *)*puVar2,&local_34);
  iVar4 = 0;
  if (local_3c != 0) {
    if (local_20 == 0) {
      param_3 = (undefined4 *)0x0;
      (**(code **)(*(int *)*puVar2 + 0xb0))((int *)*puVar2,&param_3);
      local_3c = FUN_41409304((double)(local_3c * 100) / (double)local_18);
      iVar4 = ((int)param_3 * 0x21 + 500) / 1000;
    }
    else {
      iVar4 = FUN_41409304((double)local_18 / DAT_414825d8);
    }
    iVar4 = local_3c + iVar4;
  }
  iVar8 = iVar4 + local_34;
  if (param_6 < iVar4 + local_34) {
    iVar8 = param_6;
  }
  (**(code **)(*(int *)*puVar2 + 0x84))((int *)*puVar2,iVar8);
  (**(code **)(*(int *)*puVar2 + 0x7c))((int *)*puVar2,iVar7);
  SysFreeString(local_24);
  local_8 = 0xffffffff;
  FUN_4144c348(&local_38);
  return 0;
}



// Source: CLCSSmallBarcode.dll @ 42049ea8; FUN_42049ea8

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_42049ea8(void *this,undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  UINT UVar4;
  wchar_t *pwVar5;
  int *piVar6;
  _union_2683 local_50;
  _union_2683 local_40;
  undefined4 local_30;
  BSTR local_2c;
  int local_28;
  int local_24;
  int *local_20;
  BSTR local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x42049eb4;
  FUN_42002e41(&local_30);
  local_8 = 0;
  FUN_42002e4a(&local_1c,(int *)((int)this + 0x20));
  local_8._0_1_ = 1;
  (**(code **)(*(int *)this + 0x18))(param_3);
  if (*param_2 == 0) goto LAB_4204a0a4;
  FUN_420698e0((uint *)&local_50,0,0x10);
  VariantInit((VARIANTARG *)&local_50.n2);
  local_8._0_1_ = 2;
  iVar1 = (**(code **)(*(int *)*param_2 + 0x480))((int *)*param_2,&local_50);
  if ((-1 < iVar1) && (local_50.n2.vt == 9)) {
    CComQIPtr<>(&local_20,(undefined4 *)local_50._8_4_);
    if (local_20 != (int *)0x0) {
      FUN_420698e0((uint *)&local_40,0,0x10);
      VariantInit((VARIANTARG *)&local_40.n2);
      local_8._0_1_ = 4;
      FUN_42002eae(&local_2c,L"DataMatrix");
      local_8._0_1_ = 5;
      iVar1 = (**(code **)(*local_20 + 0x30))(local_20,local_2c,&local_40);
      if ((-1 < iVar1) && (local_40.n2.vt == 9)) {
        CComQIPtr<>(local_14,(undefined4 *)local_40._8_4_);
        CComQIPtr<>(&local_18,(undefined4 *)*param_3);
        local_8._0_1_ = 7;
        if ((local_14[0] != (int *)0x0) && (local_18 != (int *)0x0)) {
          local_24 = 0x10;
          local_28 = 0x10;
          uVar2 = (**(code **)(*local_14[0] + 0xd4))(local_14[0],&local_24);
          uVar3 = (**(code **)(*local_14[0] + 0xdc))(local_14[0],&local_28);
          if ((-1 < (int)(uVar2 | uVar3)) &&
             (((0 < local_24 && (local_24 < 0x10)) || (local_28 - 1U < 0xf)))) {
            if (local_24 - 1U < 0xf) {
              iVar1 = *local_18;
              if (local_28 - 1U < 0xf) {
LAB_4204a034:
                (**(code **)(iVar1 + 0x168))(local_18,0);
                pwVar5 = L"012345";
              }
              else {
                (**(code **)(iVar1 + 0x168))(local_18,0x18);
                pwVar5 = L"0123456789";
              }
              FUN_42005767(&local_1c,pwVar5);
            }
            else if (local_28 - 1U < 0xf) {
              iVar1 = *local_18;
              goto LAB_4204a034;
            }
          }
        }
        local_8._0_1_ = 6;
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        local_8._0_1_ = 5;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
      }
      SysFreeString(local_2c);
      VariantClear((VARIANTARG *)&local_40.n2);
    }
    local_8._0_1_ = 2;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
  }
  local_8._0_1_ = 1;
  VariantClear((VARIANTARG *)&local_50.n2);
LAB_4204a0a4:
  piVar6 = (int *)*param_2;
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 4))(piVar6);
  }
  iVar1 = FUN_42003ac3((int)*(double *)((int)this + 0x30),1.4013e-45,piVar6);
  (**(code **)(*(int *)*param_3 + 0x7c))((int *)*param_3,iVar1);
  (**(code **)(*(int *)*param_3 + 0x84))((int *)*param_3,iVar1);
  (**(code **)(*(int *)*param_4 + 0x54))((int *)*param_4,*(undefined4 *)((int)this + 0x1c));
  (**(code **)(*(int *)*param_4 + 0x5c))((int *)*param_4,local_1c);
  (**(code **)(*(int *)*param_4 + 100))((int *)*param_4,local_1c);
  piVar6 = (int *)*param_4;
  UVar4 = SysStringLen(local_1c);
  (**(code **)(*piVar6 + 0x98))(piVar6,UVar4);
  (**(code **)(*(int *)*param_3 + 0x9c))((int *)*param_3,local_1c);
  (**(code **)(*(int *)*param_3 + 0x28))((int *)*param_3,1);
  (**(code **)(*(int *)*param_3 + 0x48))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x50))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x40))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x58))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0x94))((int *)*param_3,0);
  (**(code **)(*(int *)*param_3 + 0xb4))((int *)*param_3,1000);
  (**(code **)(*(int *)*param_3 + 0x104))((int *)*param_3,0);
  SysFreeString(local_1c);
  local_8 = 0xffffffff;
  FUN_420030e8(&local_30);
  return 0;
}



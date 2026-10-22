// Source: CLCSSmallBarcode.dll @ 42031404; FUN_42031404

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_42031404(void *this,undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  UINT UVar2;
  int iVar3;
  bool bVar4;
  VARIANTARG local_2c;
  int *local_1c;
  int *local_18;
  float local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x42031410;
  iVar3 = -0x7ff8ffa9;
  CComQIPtr<>(&local_1c,param_2);
  local_8 = 0;
  FUN_420698e0((uint *)&local_2c,0,0x10);
  VariantInit(&local_2c);
  local_8._0_1_ = 1;
  (**(code **)(*local_1c + 0x24))(local_1c,1,&local_2c);
  CComQIPtr<>(&local_18,(undefined4 *)local_2c.n1._8_4_);
  local_8._0_1_ = 2;
  if (local_18 == (int *)0x0) {
    FUN_420034ad(0x42095294);
    iVar3 = -0x7fffbffb;
    goto LAB_42031572;
  }
  (**(code **)(*local_18 + 100))(local_18,(int)this + 0xa8);
  (**(code **)(*local_18 + 0x5c))(local_18,(int)this + 0xa4);
  (**(code **)(**(int **)((int)this + 0xc) + 0x2c))(*(int **)((int)this + 0xc),local_14);
  iVar1 = FUN_420039d2(local_14[0] * _DAT_42093e98);
  *(int *)((int)this + 0xac) = iVar1;
  (**(code **)(**(int **)((int)this + 0xc) + 0x34))(*(int **)((int)this + 0xc),local_14);
  iVar1 = FUN_420039d2(local_14[0] * _DAT_42093e98);
  *(int *)((int)this + 0xb0) = iVar1;
  CComQIPtr<>(&param_2,param_3);
  local_8._0_1_ = 3;
  if (param_2 != (int *)0x0) {
    FUN_420034ad(0x420952c4);
    if (param_2 != (int *)0x0) {
      iVar3 = (**(code **)(*(int *)this + 0x10))(param_2,param_5);
      bVar4 = iVar3 < 0;
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*(int *)this + 0x18))(param_1);
        if (iVar3 < 0) goto LAB_42031556;
        iVar3 = 0;
        bVar4 = false;
      }
      if (!bVar4) {
        UVar2 = SysStringLen(*(BSTR *)((int)this + 0x7c));
        if (UVar2 != 0) {
          iVar3 = 0x4022a;
        }
      }
    }
LAB_42031556:
    FUN_420034ad(0x420952f4);
  }
  local_8._0_1_ = 2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
LAB_42031572:
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  VariantClear(&local_2c);
  local_8 = 0xffffffff;
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  return iVar3;
}



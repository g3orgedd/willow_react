// Source: CLCSSmallBarcode.dll @ 4203416b; FUN_4203416b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
FUN_4203416b(void *this,int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  UINT UVar4;
  VARIANTARG local_2c;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x42034177;
  if ((param_2 == (undefined4 *)0x0) || (param_3 == (undefined4 *)0x0)) {
    iVar2 = -0x7fffbffd;
  }
  else {
    iVar2 = -0x7ff8ffa9;
    if (param_1 != -1) {
      CComQIPtr<>(&local_1c,param_2);
      local_8 = 0;
      if (local_1c != (int *)0x0) {
        FUN_420698e0((uint *)&local_2c,0,0x10);
        VariantInit(&local_2c);
        local_8._0_1_ = 1;
        (**(code **)(*local_1c + 0x24))(local_1c,1,&local_2c);
        CComQIPtr<>(&local_18,(undefined4 *)local_2c.n1._8_4_);
        local_8._0_1_ = 2;
        uVar1 = (undefined1)local_8;
        local_8._0_1_ = 2;
        if (local_18 == (int *)0x0) {
          local_8._0_1_ = uVar1;
          FUN_420034ad(0x42095294);
          iVar2 = -0x7fffbffb;
        }
        else {
          (**(code **)(*local_18 + 100))(local_18,(int)this + 0xb4);
          (**(code **)(*local_18 + 0x5c))(local_18,(int)this + 0xb0);
          (**(code **)(**(int **)((int)this + 0xc) + 0x2c))(*(int **)((int)this + 0xc),&param_2);
          iVar3 = FUN_420039d2((float)param_2 * _DAT_42093e98);
          *(int *)((int)this + 0x7c) = iVar3;
          (**(code **)(**(int **)((int)this + 0xc) + 0x34))(*(int **)((int)this + 0xc),&param_2);
          iVar3 = FUN_420039d2((float)param_2 * _DAT_42093e98);
          *(int *)((int)this + 0x80) = iVar3;
          CComQIPtr<>(local_14,param_3);
          local_8._0_1_ = 3;
          if (local_14[0] != (int *)0x0) {
            FUN_4201bb2c(0x4209b380);
            *(double *)((int)this + 0x88) =
                 (double)*(int *)((int)this + 0x80) / (double)*(int *)((int)this + 0x7c);
            iVar2 = (**(code **)(*(int *)this + 0x10))(local_14[0],param_5);
            if (((-1 < iVar2) && (iVar2 = (**(code **)(*(int *)this + 0x18))(param_1), -1 < iVar2))
               && (UVar4 = SysStringLen(*(BSTR *)((int)this + 0xec)), UVar4 != 0)) {
              iVar2 = 0x4022a;
            }
            FUN_4201bb2c(0x4209b3bc);
          }
          local_8._0_1_ = 2;
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))(local_18);
        }
        VariantClear(&local_2c);
      }
      local_8 = 0xffffffff;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
  }
  return iVar2;
}



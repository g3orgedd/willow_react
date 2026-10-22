// Source: CLARiSOFT.exe @ 00e2bd07; FUN_00e2bd07

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e2bd07(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  VARIANTARG local_64;
  _union_2683 local_54;
  VARIANTARG local_44;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  iVar3 = param_1;
  uStack_4 = 0x54;
  local_8 = 0xe2bd13;
  iVar1 = FUN_00e61ea6(param_1);
  if (iVar1 != 3) {
    return;
  }
  FUN_00eae6d1(&local_34);
  local_8 = 0;
  (**(code **)(**(int **)((int)this + 0x19c) + 0x54))(*(int **)((int)this + 0x19c),&local_2c);
  CComQIPtr<>(local_14,*(undefined4 **)(iVar3 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  (**(code **)(*local_14[0] + 0xc4))(local_14[0],&local_30);
  if (local_30 == 1) goto LAB_00e2bf4c;
  local_18 = 0;
  if (*(int *)((int)this + 0x160) != 0) {
    (**(code **)(**(int **)((int)this + 0x160) + 0x2fc))(*(int **)((int)this + 0x160),&local_18);
  }
  FUN_00e03b51((uint *)&local_64);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)this + 0x15c) + 0x7c))(*(int **)((int)this + 0x15c),&local_64);
  CComQIPtr<>(&local_1c,(undefined4 *)local_64.n1._8_4_);
  local_8 = CONCAT31(local_8._1_3_,3);
  (**(code **)(*local_1c + 0x24))(local_1c,&local_28);
  if ((local_28 < 1) || (local_18 != 0)) {
    if ((local_28 == 0) || (local_18 == 1)) {
      (**(code **)(**(int **)((int)this + 0x15c) + 0x24))(*(int **)((int)this + 0x15c),&param_1);
      if (local_2c == 0) {
        piVar4 = *(int **)((int)this + 0x160);
        if (piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 4))(piVar4);
        }
        param_1 = FUN_00eae95c(param_1,0.0,piVar4);
      }
      (**(code **)(*local_14[0] + 0x84))(local_14[0],param_1);
      local_54._8_4_ = *(undefined4 *)(iVar3 + 4);
      local_54.n2.vt = 9;
      if ((int *)local_54._8_4_ != (int *)0x0) {
        (**(code **)(*(int *)local_54._8_4_ + 4))(local_54._8_4_);
      }
      local_8 = CONCAT31(local_8._1_3_,7);
      goto LAB_00e2bf15;
    }
  }
  else {
    iVar1 = 0;
    local_24 = (int *)0x0;
    if (0 < local_28) {
      iVar2 = 0;
      do {
        FUN_00e03b51((uint *)&local_44);
        iVar2 = iVar2 + 1;
        local_8._0_1_ = 4;
        (**(code **)(*local_1c + 0x20))(local_1c,iVar2,&local_44);
        CComQIPtr<>(&local_24,(undefined4 *)local_44.n1._8_4_);
        local_8._0_1_ = 5;
        (**(code **)(*local_24 + 0x2c))(local_24,&local_20);
        if (iVar1 < local_20) {
          iVar1 = local_20;
        }
        local_8._0_1_ = 4;
        if (local_24 != (int *)0x0) {
          (**(code **)(*local_24 + 8))(local_24);
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        VariantClear(&local_44);
        iVar3 = param_1;
      } while (iVar2 < local_28);
    }
    if (local_2c == 0) {
      piVar4 = *(int **)((int)this + 0x160);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 4))(piVar4);
      }
      iVar1 = FUN_00eae95c(iVar1,0.0,piVar4);
    }
    (**(code **)(*local_14[0] + 0x84))(local_14[0],iVar1);
    local_54._8_4_ = *(int *)(iVar3 + 4);
    local_54.n2.vt = 9;
    if ((int *)local_54._8_4_ != (int *)0x0) {
      (**(code **)(*(int *)local_54._8_4_ + 4))(local_54._8_4_);
    }
    local_8 = CONCAT31(local_8._1_3_,6);
LAB_00e2bf15:
    (**(code **)(**(int **)((int)this + 0x1a8) + 0x40))(*(int **)((int)this + 0x1a8),&local_54,2);
    VariantClear((VARIANTARG *)&local_54.n2);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  VariantClear(&local_64);
LAB_00e2bf4c:
  local_8 = local_8 & 0xffffff00;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  local_8 = 0xffffffff;
  FUN_00eae7b2(&local_34);
  return;
}



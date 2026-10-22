// Source: CLARiSOFT.exe @ 00e2bb58; FUN_00e2bb58

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e2bb58(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  VARIANTARG local_48;
  VARIANTARG local_38;
  undefined4 local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  iVar2 = param_1;
  uStack_4 = 0x38;
  local_8 = 0xe2bb64;
  iVar1 = FUN_00e61ea6(param_1);
  if (iVar1 != 2) {
    return;
  }
  FUN_00eae6d1(&local_28);
  local_8 = 0;
  (**(code **)(**(int **)((int)this + 0x19c) + 0x54))(*(int **)((int)this + 0x19c),&local_24);
  CComQIPtr<>(&local_18,*(undefined4 **)(iVar2 + 4));
  FUN_00e03b51((uint *)&local_48);
  local_8._0_1_ = 2;
  (**(code **)(**(int **)((int)this + 0x15c) + 0x7c))(*(int **)((int)this + 0x15c),&local_48);
  CComQIPtr<>(local_14,(undefined4 *)local_48.n1._8_4_);
  local_8 = CONCAT31(local_8._1_3_,3);
  (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_20);
  if (local_20 < 1) {
    (**(code **)(**(int **)((int)this + 0x15c) + 0x24))(*(int **)((int)this + 0x15c),&param_1);
    if (param_1 == 0) goto LAB_00e2bcc7;
    iVar2 = param_1;
    if (local_24 == 0) {
      piVar3 = *(int **)((int)this + 0x160);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      param_1 = FUN_00eae95c(param_1,0.0,piVar3);
      iVar2 = param_1;
    }
  }
  else {
    iVar2 = 0;
    iVar1 = 0;
    if (0 < local_20) {
      do {
        FUN_00e03b51((uint *)&local_38);
        iVar1 = iVar1 + 1;
        local_8._0_1_ = 4;
        (**(code **)(*local_14[0] + 0x20))(local_14[0],iVar1,&local_38);
        CComQIPtr<>(&local_1c,(undefined4 *)local_38.n1._8_4_);
        local_8._0_1_ = 5;
        (**(code **)(*local_1c + 0x2c))(local_1c,&param_1);
        if (iVar2 < param_1) {
          iVar2 = param_1;
        }
        local_8._0_1_ = 4;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        VariantClear(&local_38);
      } while (iVar1 < local_20);
    }
    if (local_24 == 0) {
      piVar3 = *(int **)((int)this + 0x160);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 4))(piVar3);
      }
      iVar2 = FUN_00eae95c(iVar2,0.0,piVar3);
    }
  }
  (**(code **)(*local_18 + 0x84))(local_18,iVar2);
LAB_00e2bcc7:
  local_8._0_1_ = 2;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  VariantClear(&local_48);
  local_8 = (uint)local_8._1_3_ << 8;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = 0xffffffff;
  FUN_00eae7b2(&local_28);
  return;
}



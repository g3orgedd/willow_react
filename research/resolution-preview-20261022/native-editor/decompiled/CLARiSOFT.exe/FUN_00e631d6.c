// Source: CLARiSOFT.exe @ 00e631d6; FUN_00e631d6

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e631d6(void *this,int *param_1,int *param_2)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  VARIANTARG local_2c;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_3c.n1._8_4_ = *(int *)((int)this + 4);
  local_8 = 1;
  local_3c.n1.n2.vt = 9;
  if ((int *)local_3c.n1._8_4_ != (int *)0x0) {
    (**(code **)(*(int *)local_3c.n1._8_4_ + 4))();
  }
  local_8._0_1_ = 2;
  local_2c.n1.n2.vt = 9;
  local_2c.n1._8_4_ = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))();
  }
  CComQIPtr<>(local_14,*(undefined4 **)((int)this + 0x3c));
  local_8._0_1_ = 4;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 4;
  if (local_14[0] == (int *)0x0) {
    local_8._0_1_ = uVar1;
    (**(code **)(**(int **)((int)this + 0x3c) + 0x28))();
  }
  else {
    CComQIPtr<>(&local_18,local_14[0]);
    local_8._0_1_ = 5;
    uVar1 = (undefined1)local_8;
    local_8._0_1_ = 5;
    if (local_18 == (int *)0x0) {
      local_8._0_1_ = uVar1;
      (**(code **)(*local_14[0] + 0x40))();
    }
    else {
      local_4c.n1.n2.vt = 9;
      local_4c.n1._8_4_ = param_1;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 4))();
      }
      local_8._0_1_ = 6;
      (**(code **)(*local_18 + 0x4c))();
      VariantClear(&local_4c);
    }
    local_8._0_1_ = 4;
    if (local_18 != (int *)0x0) {
      (**(code **)(*local_18 + 8))();
    }
  }
  piVar3 = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  piVar2 = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  FUN_00e60cce(this,&local_1c,piVar2,piVar3);
  *(undefined1 *)((int)this + 0x48) = 1;
  local_8._0_1_ = 3;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))();
  }
  VariantClear(&local_2c);
  VariantClear(&local_3c);
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  return;
}



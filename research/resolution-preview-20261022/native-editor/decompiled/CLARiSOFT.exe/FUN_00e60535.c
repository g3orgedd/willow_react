// Source: CLARiSOFT.exe @ 00e60535; FUN_00e60535

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void __thiscall
FUN_00e60535(void *this,int *param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
            int *param_6,int *param_7,undefined4 param_8,int *param_9)

{
  undefined4 *this_00;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  VARIANTARG local_5c;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  int local_2c [2];
  void *local_24;
  undefined4 *local_20;
  int local_1c;
  int *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  *(undefined ***)this = CField::vftable;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  this_00 = (undefined4 *)((int)this + 0x3c);
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *this_00 = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  *(undefined1 *)((int)this + 0x48) = 1;
  *(undefined4 *)((int)this + 8) = 0;
  local_24 = this;
  local_20 = (undefined4 *)FUN_00eca369(0x28);
  local_8._0_1_ = 10;
  if (local_20 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_00ebad08(local_20);
  }
  *(undefined4 **)((int)this + 0x4c) = puVar1;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  (**(code **)(*param_7 + 0x54))();
  local_5c.n1._8_4_ = param_6;
  local_5c.n1.n2.vt = 9;
  if (param_6 != (int *)0x0) {
    (**(code **)(*param_6 + 4))();
  }
  local_8._0_1_ = 0xc;
  local_4c.n1.n2.vt = 9;
  local_4c.n1._8_4_ = param_7;
  if (param_7 != (int *)0x0) {
    (**(code **)(*param_7 + 4))();
  }
  FUN_00e03b51((uint *)&local_3c);
  FUN_00e11de5(this_00,&param_5);
  CComQIPtr<>(local_18,(undefined4 *)*this_00);
  local_8._0_1_ = 0xf;
  if (local_18[0] != (int *)0x0) {
    *(int **)((int)this + 0x40) = local_18[0];
    (**(code **)(*local_18[0] + 4))();
  }
  if (param_9 == (int *)0x0) {
    iVar2 = (**(code **)(*(int *)*this_00 + 0x1c))();
    if (iVar2 != 0) {
      piVar5 = *(int **)((int)this + 4);
      if ((piVar5 != (int *)0x0) && (*(undefined4 *)((int)this + 4) = 0, piVar5 != (int *)0x0)) {
        (**(code **)(*piVar5 + 8))();
      }
      local_8 = CONCAT31(local_8._1_3_,0xe);
      if (local_18[0] != (int *)0x0) {
        (**(code **)(*local_18[0] + 8))();
      }
      VariantClear(&local_3c);
      VariantClear(&local_4c);
      VariantClear(&local_5c);
      FUN_00e60862();
      return;
    }
    CComQIPtr<>(&param_3,(undefined4 *)local_3c.n1._8_4_);
    local_8._0_1_ = 0x10;
    *(int **)((int)this + 4) = param_3;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 4))();
    }
    if (((*(int *)((int)this + 4) != 0) && (param_7 != (int *)0x0)) && (param_6 != (int *)0x0)) {
      CComQIPtr<>(&param_1,*(undefined4 **)((int)this + 4));
      local_8._0_1_ = 0x11;
      if (param_1 != (int *)0x0) {
        local_1c = 0;
        iVar2 = (**(code **)(*param_1 + 0x124))(param_1);
        param_4 = 0;
        iVar3 = (**(code **)(*param_7 + 0x54))(param_7,&param_4);
        if (((-1 < iVar3) && (param_4 == 0)) && ((-1 < iVar2 && (local_1c == 2)))) {
          FUN_00eae6d1(&local_20);
          local_8._0_1_ = 0x12;
          piVar5 = param_6;
          if (param_6 != (int *)0x0) {
            (**(code **)(*param_6 + 4))(param_6);
          }
          FUN_00eae95c(1,0.0,piVar5);
          (**(code **)(*param_1 + 0x154))(param_1);
          local_8._0_1_ = 0x11;
          FUN_00eae7b2(&local_20);
        }
      }
      local_8._0_1_ = 0x10;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))();
      }
    }
    local_8._0_1_ = 0xf;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 8))();
    }
  }
  else {
    *(int **)((int)this + 4) = param_9;
    (**(code **)(*param_9 + 4))();
  }
  piVar5 = param_7;
  if (param_7 != (int *)0x0) {
    (**(code **)(*param_7 + 4))(param_7);
  }
  piVar4 = param_6;
  if (param_6 != (int *)0x0) {
    (**(code **)(*param_6 + 4))(param_6);
  }
  FUN_00e631d6(this,piVar4,piVar5);
  piVar5 = param_7;
  if (param_7 != (int *)0x0) {
    (**(code **)(*param_7 + 4))(param_7);
  }
  piVar4 = param_6;
  if (param_6 != (int *)0x0) {
    (**(code **)(*param_6 + 4))(param_6);
  }
  FUN_00e60cce(this,local_2c,piVar4,piVar5);
  piVar5 = param_6;
  if (param_6 != (int *)0x0) {
    (**(code **)(*param_6 + 4))(param_6);
  }
  FUN_00e61a5e(this,piVar5);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  if (local_18[0] != (int *)0x0) {
    (**(code **)(*local_18[0] + 8))();
  }
  VariantClear(&local_3c);
  VariantClear(&local_4c);
  VariantClear(&local_5c);
  local_8 = 9;
  FUN_00e60862();
  return;
}



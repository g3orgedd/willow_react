// Source: CLARiSOFT.exe @ 00e60cce; FUN_00e60cce

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * __thiscall FUN_00e60cce(void *this,int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  _union_2683 local_80;
  _union_2683 local_70;
  _union_2683 local_60;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined1 local_38 [4];
  undefined1 local_34 [8];
  int *local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x70;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  local_40 = 0;
  local_3c = 0;
  if (*(int *)((int)this + 0x3c) != 0) {
    local_80._8_4_ = *(int *)((int)this + 4);
    local_80.n2.vt = 9;
    if ((int *)local_80._8_4_ != (int *)0x0) {
      (**(code **)(*(int *)local_80._8_4_ + 4))(local_80._8_4_);
    }
    local_8._0_1_ = 2;
    local_60.n2.vt = 9;
    local_60._8_4_ = param_2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 4))(param_2);
    }
    local_8._0_1_ = 3;
    local_70.n2.vt = 9;
    local_70._8_4_ = param_3;
    if (param_3 != (int *)0x0) {
      (**(code **)(*param_3 + 4))(param_3);
    }
    local_8._0_1_ = 4;
    (**(code **)(**(int **)((int)this + 0x3c) + 0x30))
              (*(int **)((int)this + 0x3c),&local_40,local_80._0_4_,local_80.decVal.Hi32,
               local_80._8_4_,local_80._12_4_,local_60._0_4_,local_60.decVal.Hi32,local_60._8_4_,
               local_60._12_4_,local_70._0_4_,local_70.decVal.Hi32,local_70._8_4_,local_70._12_4_);
    (**(code **)(*param_3 + 0x54))(param_3,&local_18);
    if (local_18 == 0) {
      FUN_00eae6d1(&local_1c);
      CComQIPtr<>(local_14,(undefined4 *)local_60._8_4_);
      piVar1 = local_14[0];
      local_8 = CONCAT31(local_8._1_3_,7);
      local_2c = local_14[0];
      piVar2 = local_14[0];
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 4))(local_14[0]);
        piVar2 = piVar1;
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      local_40 = FUN_00eae95c(local_40,1.4013e-45,piVar2);
      piVar2 = piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      local_3c = FUN_00eae95c(local_3c,0.0,piVar2);
      local_8._0_1_ = 6;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      local_8._0_1_ = 5;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      local_8._0_1_ = 4;
      FUN_00eae7b2(&local_1c);
    }
    (**(code **)(**(int **)((int)this + 4) + 0x2c))(*(int **)((int)this + 4),&local_24);
    (**(code **)(**(int **)((int)this + 4) + 0x34))(*(int **)((int)this + 4),&local_20);
    (**(code **)(**(int **)((int)this + 4) + 100))(*(int **)((int)this + 4),local_34);
    (**(code **)(**(int **)((int)this + 4) + 0x3c))(*(int **)((int)this + 4),local_38);
    local_48 = local_40 + local_24;
    local_44 = local_3c + local_20;
    local_4c = local_20;
    local_50 = local_24;
    (**(code **)(**(int **)((int)this + 4) + 0x88))(*(int **)((int)this + 4),&local_28);
    FUN_00e62bd7(this,local_50,local_4c,local_48,local_44,local_28,'\0');
    VariantClear((VARIANTARG *)&local_70.n2);
    VariantClear((VARIANTARG *)&local_60.n2);
    VariantClear((VARIANTARG *)&local_80.n2);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  *param_1 = local_40;
  param_1[1] = local_3c;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 8))(param_3);
  }
  return param_1;
}



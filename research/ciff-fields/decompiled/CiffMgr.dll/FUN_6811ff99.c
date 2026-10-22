// Source: CiffMgr.dll @ 6811ff99; FUN_6811ff99

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811ff99(void *this,int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  _union_2683 local_60;
  _union_2683 local_50;
  _union_2683 local_40;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x50;
  if (param_1 == (int *)0x0) {
    local_30 = -0x7fffbffd;
  }
  else {
    *(undefined4 *)((int)this + 4) = 1;
    do {
      local_24 = -1;
      local_20 = (int *)0x0;
      local_28 = -0x80000000;
      local_2c = -0x80000000;
      local_8 = 0;
      local_30 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_20);
      if ((local_30 == 0) && (local_20 != (int *)0x0)) {
        param_1 = (int *)0x0;
        local_8._0_1_ = 1;
        iVar3 = (**(code **)(*local_20 + 0x44))(local_20,&param_1);
        if ((-1 < iVar3) && (param_1 != (int *)0x0)) {
          local_1c = (int *)0x0;
          local_8._0_1_ = 2;
          iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,PTR_DAT_6816008c,&local_1c);
          if (iVar3 == 0) {
            if (local_1c != (int *)0x0) {
              FUN_68132710((uint *)&local_40,0,0x10);
              VariantInit((VARIANTARG *)&local_40.n2);
              local_8._0_1_ = 3;
              iVar3 = (**(code **)(*local_1c + 0x20))(local_1c,&local_40);
              if (local_40.n2.vt == 8) {
                local_24 = FUN_6812f116((ushort *)local_40._8_4_);
              }
              VariantClear((VARIANTARG *)&local_40.n2);
              goto LAB_68120094;
            }
LAB_6812009a:
            local_14[0] = (int *)0x0;
            local_8._0_1_ = 4;
            iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,PTR_DAT_68160090,local_14);
            if ((iVar3 == 0) && (local_14[0] != (int *)0x0)) {
              FUN_68132710((uint *)&local_50,0,0x10);
              VariantInit((VARIANTARG *)&local_50.n2);
              local_8._0_1_ = 5;
              iVar3 = (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_50);
              if (local_50.n2.vt == 8) {
                local_28 = FUN_6812f116((ushort *)local_50._8_4_);
              }
              VariantClear((VARIANTARG *)&local_50.n2);
            }
            local_8._0_1_ = 2;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            if (-1 < iVar3) {
              local_18 = (int *)0x0;
              local_8._0_1_ = 6;
              iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,PTR_DAT_68160094,&local_18);
              if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
                FUN_68132710((uint *)&local_60,0,0x10);
                VariantInit((VARIANTARG *)&local_60.n2);
                local_8._0_1_ = 7;
                iVar3 = (**(code **)(*local_18 + 0x20))(local_18,&local_60);
                if (local_60.n2.vt == 8) {
                  local_2c = FUN_6812f116((ushort *)local_60._8_4_);
                }
                VariantClear((VARIANTARG *)&local_60.n2);
              }
              local_8._0_1_ = 2;
              if (local_18 != (int *)0x0) {
                (**(code **)(*local_18 + 8))(local_18);
              }
              iVar2 = local_2c;
              if ((((-1 < iVar3) && (-0x80000000 < local_28)) && (-0x80000000 < local_2c)) &&
                 (iVar3 = (**(code **)(*piVar1 + 0xe4))(piVar1,local_24,local_28), -1 < iVar3)) {
                (**(code **)(*piVar1 + 0xec))(piVar1,local_24,iVar2);
              }
            }
          }
          else {
LAB_68120094:
            if (-1 < iVar3) goto LAB_6812009a;
          }
          local_8._0_1_ = 1;
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
        }
      }
      local_8 = 0xffffffff;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
    } while (local_30 == 0);
  }
  return local_30;
}



// Source: CiffMgr.dll @ 6811b867; FUN_6811b867

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811b867(void *this,undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  VARIANTARG local_7c;
  _union_2683 local_6c;
  _union_2683 local_5c;
  _union_2683 local_4c;
  _union_2683 local_3c;
  int local_2c;
  int local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6c;
  do {
    local_24 = (int *)0x0;
    local_8 = 0;
    iVar1 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_24);
    if ((iVar1 == 0) && (local_24 != (int *)0x0)) {
      local_14[0] = (int *)0x0;
      local_8._0_1_ = 1;
      iVar2 = (**(code **)(*local_24 + 0x44))(local_24,local_14);
      local_2c = -0x80000000;
      local_28 = -0x80000000;
      local_20 = -0x80000000;
      local_1c = -0x80000000;
      if (iVar2 < 0) {
LAB_6811bb5d:
        iVar1 = iVar2;
      }
      else {
        if (local_14[0] != (int *)0x0) {
          local_18 = (int *)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Left_68160070,&local_18);
          if ((iVar2 == 0) && (local_18 != (int *)0x0)) {
            FUN_68132710((uint *)&local_3c,0,0x10);
            VariantInit((VARIANTARG *)&local_3c.n2);
            local_8._0_1_ = 3;
            (**(code **)(*local_18 + 0x20))(local_18,&local_3c);
            if (local_3c.n2.vt == 8) {
              local_20 = FUN_6812f116((ushort *)local_3c._8_4_);
            }
            VariantClear((VARIANTARG *)&local_3c.n2);
          }
          local_8._0_1_ = 1;
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))(local_18);
          }
          local_18 = (int *)0x0;
          local_8._0_1_ = 4;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_DAT_68160074,&local_18);
          if ((iVar2 == 0) && (local_18 != (int *)0x0)) {
            FUN_68132710((uint *)&local_4c,0,0x10);
            VariantInit((VARIANTARG *)&local_4c.n2);
            local_8._0_1_ = 5;
            (**(code **)(*local_18 + 0x20))(local_18,&local_4c);
            if (local_4c.n2.vt == 8) {
              local_1c = FUN_6812f116((ushort *)local_4c._8_4_);
            }
            VariantClear((VARIANTARG *)&local_4c.n2);
          }
          local_8._0_1_ = 1;
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))(local_18);
          }
          local_18 = (int *)0x0;
          local_8._0_1_ = 6;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Right_68160078,&local_18);
          if ((iVar2 == 0) && (local_18 != (int *)0x0)) {
            FUN_68132710((uint *)&local_5c,0,0x10);
            VariantInit((VARIANTARG *)&local_5c.n2);
            local_8._0_1_ = 7;
            (**(code **)(*local_18 + 0x20))(local_18,&local_5c);
            if (local_5c.n2.vt == 8) {
              local_2c = FUN_6812f116((ushort *)local_5c._8_4_);
            }
            VariantClear((VARIANTARG *)&local_5c.n2);
          }
          local_8._0_1_ = 1;
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))(local_18);
          }
          local_18 = (int *)0x0;
          local_8._0_1_ = 8;
          iVar2 = (**(code **)(*local_14[0] + 0x1c))(local_14[0],PTR_u_Bottom_6816007c,&local_18);
          if ((iVar2 == 0) && (local_18 != (int *)0x0)) {
            FUN_68132710((uint *)&local_6c,0,0x10);
            VariantInit((VARIANTARG *)&local_6c.n2);
            local_8._0_1_ = 9;
            iVar2 = (**(code **)(*local_18 + 0x20))(local_18,&local_6c);
            if (local_6c.n2.vt == 8) {
              local_28 = FUN_6812f116((ushort *)local_6c._8_4_);
            }
            VariantClear((VARIANTARG *)&local_6c.n2);
          }
          local_8._0_1_ = 1;
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))(local_18);
          }
        }
        if (iVar2 < 0) goto LAB_6811bb5d;
        if ((((-0x80000000 < local_20) && (-0x80000000 < local_1c)) && (-0x80000000 < local_2c)) &&
           (-0x80000000 < local_28)) {
          FUN_68132710((uint *)&local_7c,0,0x10);
          VariantInit(&local_7c);
          *(undefined4 *)((int)this + 4) = 1;
          local_8._0_1_ = 10;
          iVar2 = (**(code **)(*(int *)*param_1 + 0x28))
                            ((int *)*param_1,local_20,local_1c,local_2c,local_28,&local_7c);
          VariantClear(&local_7c);
        }
        if (iVar2 < 0) goto LAB_6811bb5d;
      }
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    local_8 = 0xffffffff;
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))(local_24);
    }
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = 0;
      }
      return iVar1;
    }
  } while( true );
}



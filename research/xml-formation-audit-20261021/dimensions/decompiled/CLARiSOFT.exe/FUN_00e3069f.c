// Source: CLARiSOFT.exe @ 00e3069f; FUN_00e3069f

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e3069f(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  _union_2683 local_3c;
  LPCWSTR local_2c;
  LPCWSTR local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)FUN_00e77808((void *)((int)this + 4),0);
    if (*piVar1 == 0) {
      this_00 = (void *)0x0;
    }
    else {
      this_00 = (void *)(*piVar1 + -100);
    }
    if (this_00 != (void *)0x0) {
      FUN_00e42531(this_00,0);
    }
    piVar1 = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    FUN_00e36ae5(this,piVar1);
    if (*(int *)((int)this + 0x19c) != 0) {
      local_1c = 0;
      iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_1c);
      if (-1 < iVar2) {
        iVar3 = 0;
        if (0 < local_1c) {
          do {
            FUN_00e03b51((uint *)&local_3c);
            local_8._0_1_ = 1;
            if (*(int *)((int)this + 0x19c) != 0) {
              iVar2 = (**(code **)(**(int **)((int)this + 0x19c) + 0x24))
                                (*(int **)((int)this + 0x19c),iVar3 + 1,&local_3c);
            }
            if (((-1 < iVar2) && (local_3c.n2.vt == 9)) && ((int *)local_3c._8_4_ != (int *)0x0)) {
              CComQIPtr<>(local_14,(undefined4 *)local_3c._8_4_);
              local_8._0_1_ = 2;
              if (local_14[0] != (int *)0x0) {
                local_18 = 0;
                iVar2 = (**(code **)(*local_14[0] + 0x54))(local_14[0],&local_18);
                if ((-1 < iVar2) && ((local_18 == 900 || (local_18 == 0xa8c)))) {
                  local_20 = 0;
                  local_28 = (LPCWSTR)0x0;
                  local_24 = 0;
                  local_2c = (LPCWSTR)0x0;
                  iVar2 = (**(code **)(*local_14[0] + 0x44))(local_14[0],&local_24);
                  if ((-1 < iVar2) &&
                     (((iVar2 = (**(code **)(*local_14[0] + 0x3c))(local_14[0],&local_20),
                       -1 < iVar2 &&
                       (iVar2 = (**(code **)(*local_14[0] + 100))(local_14[0],&local_2c), -1 < iVar2
                       )) && (iVar2 = (**(code **)(*local_14[0] + 0x5c))(local_14[0],&local_28),
                             -1 < iVar2)))) {
                    (**(code **)(*local_14[0] + 0x48))(local_14[0],local_20);
                    (**(code **)(*local_14[0] + 0x40))(local_14[0],local_24);
                    (**(code **)(*local_14[0] + 0x68))(local_14[0],local_28);
                    iVar2 = (**(code **)(*local_14[0] + 0x60))(local_14[0],local_2c);
                  }
                }
              }
              local_8._0_1_ = 1;
              if (local_14[0] != (int *)0x0) {
                (**(code **)(*local_14[0] + 8))(local_14[0]);
              }
            }
            local_8 = (uint)local_8._1_3_ << 8;
            VariantClear((VARIANTARG *)&local_3c.n2);
            iVar3 = iVar3 + 1;
          } while (iVar3 < local_1c);
        }
        FUN_00e2ade2((int)this);
        FUN_00e2b99e((int)this);
        if (*(int *)((int)this + 0x1a8) != 0) {
          local_3c._8_4_ = *(int *)((int)this + 0x19c);
          local_3c.n2.vt = 9;
          if ((int *)local_3c._8_4_ != (int *)0x0) {
            (**(code **)(*(int *)local_3c._8_4_ + 4))(local_3c._8_4_);
          }
          local_8._0_1_ = 3;
          (**(code **)(**(int **)((int)this + 0x1a8) + 0x20))
                    (*(int **)((int)this + 0x1a8),local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_
                     ,local_3c._12_4_);
          local_8 = (uint)local_8._1_3_ << 8;
          VariantClear((VARIANTARG *)&local_3c.n2);
        }
        FUN_00e36830(this);
        FUN_00e2a16a((int)this);
        FUN_00e33341((int)this);
        FUN_00e318c4(this,1);
        (**(code **)(*(int *)this + 4))(0,1);
        if (*(char *)((int)this + 0x23b) != '\0') {
          (**(code **)(*(int *)this + 4))(1,0);
        }
        if (*(char *)((int)this + 0x1d4) != '\0') {
          FUN_00eb9380(&local_28,0xfc1d);
          local_8 = CONCAT31(local_8._1_3_,4);
          FUN_00eb9380(&local_2c,0xfc1c);
          MessageBoxW((HWND)0x0,local_2c,local_28,0x30);
          FUN_00e01f81((int *)&local_2c);
          FUN_00e01f81((int *)&local_28);
        }
      }
    }
  }
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return;
}



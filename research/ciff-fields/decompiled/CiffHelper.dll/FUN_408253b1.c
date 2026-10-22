// Source: CiffHelper.dll @ 408253b1; FUN_408253b1

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_408253b1(void *this,int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  _union_2683 local_44;
  int local_34;
  int local_30;
  int local_2c;
  int *local_28;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x408253bd;
  iVar3 = -0x7ff8ffa9;
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    local_2c = 0;
    iVar3 = (**(code **)(*piVar1 + 0x1c))(piVar1,&local_2c);
    if ((-1 < iVar3) && (iVar2 = 0, 0 < local_2c)) {
      do {
        FUN_40802e76((uint *)&local_44);
        local_8 = 0;
        iVar2 = iVar2 + 1;
        local_34 = iVar2;
        iVar3 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1,iVar2,&local_44);
        if ((-1 < iVar3) && (local_44.n2.vt == 9)) {
          CComQIPtr<>(&local_18,(undefined4 *)local_44._8_4_);
          local_8._0_1_ = 1;
          if (local_18 != (int *)0x0) {
            iVar3 = (**(code **)(*local_18 + 100))(local_18,(int *)((int)this + 0x14));
            iVar2 = local_34;
            if (-1 < iVar3) {
              (**(code **)(*local_18 + 0x90))(local_18,(int)this + 0x1c);
              local_20 = (int *)0x0;
              local_8._0_1_ = 2;
              iVar3 = (**(code **)(*local_18 + 0x5c))(local_18,&local_20);
              if ((-1 < iVar3) && (local_20 != (int *)0x0)) {
                iVar3 = FUN_408251e8(this,&local_20);
              }
              iVar2 = *(int *)((int)this + 0x14);
              if (iVar2 == 0) {
                CComQIPtr<>(local_14,local_18);
                local_8._0_1_ = 3;
                bVar4 = local_14[0] == (int *)0x0;
                piVar1 = local_14[0];
                if (!bVar4) {
                  FUN_40823f08(this,(int *)local_14);
                  bVar4 = FUN_40803ed6((void *)((int)this + 0xc),L"Excel 1310 DN Unicode");
                  if (bVar4) {
                    FUN_40823e7b(this,(int *)local_14);
                  }
                  FUN_40826dde(this,(int *)local_14);
                  FUN_40824fb1(this,local_14);
                  iVar3 = FUN_40826b97(this,(int *)local_14);
                  piVar1 = local_14[0];
                  if (*(int *)((int)this + 8) < 0x17) {
                    CComQIPtr<>(&local_28,local_18);
                    local_8._0_1_ = 4;
                    if (local_28 != (int *)0x0) {
                      local_30 = 0;
                      (**(code **)(*local_28 + 0x134))(local_28,&local_30);
                      if (local_30 == 1) {
                        local_24 = (BSTR)0x0;
                        local_8._0_1_ = 5;
                        (**(code **)(*local_28 + 0x68))(local_28,&local_24);
                        bVar4 = FUN_40803ed6(&local_24,L"DateText");
                        if ((bVar4) || (bVar4 = FUN_40803ed6(&local_24,L"OffsetDateText"), bVar4)) {
                          FUN_408250f8(this,&local_20);
                        }
                        SysFreeString(local_24);
                      }
                    }
                    local_8._0_1_ = 3;
                    piVar1 = local_14[0];
                    if (local_28 != (int *)0x0) {
                      (**(code **)(*local_28 + 8))(local_28);
                      piVar1 = local_14[0];
                    }
                  }
LAB_408255e1:
                  bVar4 = piVar1 == (int *)0x0;
                }
LAB_408255e3:
                local_8._0_1_ = 2;
                if (!bVar4) {
                  (**(code **)(*piVar1 + 8))(piVar1);
                }
              }
              else if (iVar2 == 1) {
                CComQIPtr<>(&local_1c,local_18);
                local_8._0_1_ = 6;
                bVar4 = true;
                piVar1 = local_1c;
                if (local_1c != (int *)0x0) {
                  FUN_40823c42(this,&local_1c);
                  FUN_40824e60(this,(int *)&local_1c);
                  iVar3 = FUN_40825cf5(this,&local_1c);
                  piVar1 = local_1c;
                  goto LAB_408255e1;
                }
                goto LAB_408255e3;
              }
              local_8._0_1_ = 1;
              iVar2 = local_34;
              if (local_20 != (int *)0x0) {
                (**(code **)(*local_20 + 8))(local_20);
                iVar2 = local_34;
              }
            }
          }
          local_8 = (uint)local_8._1_3_ << 8;
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))(local_18);
          }
        }
        local_8 = 0xffffffff;
        VariantClear((VARIANTARG *)&local_44.n2);
      } while (iVar2 < local_2c);
    }
  }
  return iVar3;
}



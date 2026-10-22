// Source: CLCiffConversion_Layout.dll @ 45406806; FUN_45406806

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_45406806(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  BSTR pOVar3;
  uint uVar4;
  uint uVar5;
  void *pvVar6;
  int *piVar7;
  int iVar8;
  float10 fVar9;
  _union_2683 local_64;
  _union_2683 local_54;
  _union_2683 local_44;
  int *local_34;
  int *local_30;
  BSTR local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  BSTR local_1c;
  BSTR local_18;
  void *local_14;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x45406812;
  piVar1 = *(int **)((int)this + 0x38);
  local_30 = piVar1;
  local_14 = this;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  local_8 = 0;
  local_2c = (BSTR)((int)this + 0x6c);
  piVar2 = *(int **)local_2c;
  local_34 = piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  CComQIPtr<>(&local_20,(undefined4 *)*param_1);
  local_1c = (BSTR)0x0;
  local_18 = (BSTR)0x0;
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_45404ce5((void *)((int)local_14 + 0x5c),param_1);
  if (*(char *)((int)local_14 + 0x100) == '\0') {
    if (local_20 != (int *)0x0) {
      piVar7 = *(int **)((int)this + 0x38);
      (**(code **)(*piVar7 + 0x1c))(piVar7,&local_1c);
      (**(code **)(*local_20 + 0xa0))(local_20,local_1c);
    }
  }
  else if (local_20 != (int *)0x0) {
    uVar4 = (**(code **)(*local_20 + 0x9c))(local_20,&local_1c);
    uVar5 = (**(code **)(*(int *)*param_1 + 0x4c))((int *)*param_1,&local_18);
    if (-1 < (int)(uVar4 | uVar5)) {
      pvVar6 = (void *)FUN_4541b899((void *)(*(int *)((int)local_14 + 0x4c) + 0x4d0),&local_1c);
      if (pvVar6 != (void *)0x0) {
        piVar7 = FUN_45415515(pvVar6,(int *)&local_28);
        pvVar6 = local_14;
        FUN_454066cc((void *)((int)local_14 + 0x38),piVar7);
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))(local_28);
        }
        if (*(int *)((int)pvVar6 + 0x38) != 0) {
          FUN_45429f70((uint *)&local_64,0,0x10);
          VariantInit((VARIANTARG *)&local_64.n2);
          local_8._0_1_ = 6;
          iVar8 = (**(code **)(**(int **)((int)pvVar6 + 0x38) + 0x4c0))
                            (*(int **)((int)pvVar6 + 0x38),local_18,&local_64);
          if (((-1 < iVar8) && (local_64.n2.vt == 9)) &&
             ((undefined4 *)local_64._8_4_ != (undefined4 *)0x0)) {
            CComQIPtr<>(&local_28,(undefined4 *)local_64._8_4_);
            if (local_28 != (int *)0x0) {
              FUN_45404ce5((void *)((int)pvVar6 + 0x38),(int *)&local_28);
              FUN_45429f70((uint *)&local_54,0,0x10);
              VariantInit((VARIANTARG *)&local_54.n2);
              local_8._0_1_ = 8;
              iVar8 = (**(code **)(**(int **)((int)pvVar6 + 0x38) + 0x470))
                                (*(int **)((int)pvVar6 + 0x38),&local_54);
              if (-1 < iVar8) {
                if ((local_54.n2.vt == 9) && ((undefined4 *)local_54._8_4_ != (undefined4 *)0x0)) {
                  CComQIPtr<>(&local_24,(undefined4 *)local_54._8_4_);
                  if (local_24 != (int *)0x0) {
                    FUN_45429f70((uint *)&local_44,0,0x10);
                    VariantInit((VARIANTARG *)&local_44.n2);
                    local_8._0_1_ = 10;
                    iVar8 = (**(code **)(*local_24 + 0x30))(local_24,local_18,&local_44);
                    pOVar3 = local_2c;
                    if (((-1 < iVar8) && (local_44.n2.vt == 9)) &&
                       ((undefined4 *)local_44._8_4_ != (undefined4 *)0x0)) {
                      piVar7 = *(int **)local_2c;
                      if (piVar7 != (int *)0x0) {
                        local_2c[0] = L'\0';
                        local_2c[1] = L'\0';
                        (**(code **)(*piVar7 + 8))(piVar7);
                      }
                      (*(code *)**(undefined4 **)local_44._8_4_)
                                (local_44._8_4_,&DAT_45447e5c,pOVar3);
                    }
                    VariantClear((VARIANTARG *)&local_44.n2);
                  }
                  local_8._0_1_ = 8;
                  if (local_24 != (int *)0x0) {
                    (**(code **)(*local_24 + 8))(local_24);
                  }
                }
              }
              VariantClear((VARIANTARG *)&local_54.n2);
            }
            local_8._0_1_ = 6;
            if (local_28 != (int *)0x0) {
              (**(code **)(*local_28 + 8))(local_28);
            }
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          VariantClear((VARIANTARG *)&local_64.n2);
        }
      }
    }
    goto LAB_45406adc;
  }
  local_28 = (int *)0x0;
  FUN_45404ce5(&local_28,(int *)local_2c);
  local_8._0_1_ = 5;
  piVar7 = FUN_4541db3e(&local_28,&local_2c);
  FUN_454066f3(&local_18,piVar7);
  SysFreeString(local_2c);
  (**(code **)(*(int *)*param_1 + 0x50))((int *)*param_1,local_18);
  local_8 = CONCAT31(local_8._1_3_,4);
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
LAB_45406adc:
  piVar7 = (int *)*param_1;
  local_2c = (BSTR)(*piVar7 + 0x70);
  fVar9 = FUN_45406d0a((int)local_14);
  (**(code **)local_2c)(piVar7,(float)fVar9);
  piVar7 = (int *)*param_1;
  local_2c = (BSTR)(*piVar7 + 0x78);
  fVar9 = FUN_45406d26((int)local_14);
  (**(code **)local_2c)(piVar7,(float)fVar9);
  pvVar6 = local_14;
  FUN_45406edf(local_14,param_1);
  if (*(char *)((int)pvVar6 + 0x100) != '\0') {
    FUN_45404ce5((void *)((int)pvVar6 + 0x38),(int *)&local_30);
    FUN_45404ce5((void *)((int)pvVar6 + 0x6c),(int *)&local_34);
  }
  piVar7 = *(int **)((int)pvVar6 + 0x5c);
  if ((piVar7 != (int *)0x0) && (*(undefined4 *)((int)pvVar6 + 0x5c) = 0, piVar7 != (int *)0x0)) {
    (**(code **)(*piVar7 + 8))(piVar7);
  }
  SysFreeString(local_18);
  SysFreeString(local_1c);
  local_8._0_1_ = 1;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



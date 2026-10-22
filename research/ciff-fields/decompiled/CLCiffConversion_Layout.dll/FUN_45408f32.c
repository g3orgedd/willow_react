// Source: CLCiffConversion_Layout.dll @ 45408f32; FUN_45408f32

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_45408f32(void *this,int *param_1,void *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  _union_2683 local_38;
  BSTR local_28;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  iVar3 = -0x7fffbffb;
  if (*(int *)((int)this + 8) != 0) {
    local_28 = (BSTR)0x0;
    local_8 = 0;
    FUN_4540876e(&local_28,0x45448148);
    local_20 = (int *)0x0;
    local_8._0_1_ = 1;
    iVar3 = (**(code **)(**(int **)((int)this + 8) + 0x94))
                      (*(int **)((int)this + 8),local_28,&local_20);
    if ((-1 < iVar3) && (local_20 != (int *)0x0)) {
      local_14[0] = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,2);
      iVar3 = (**(code **)(*local_20 + 0x90))(local_20,&DAT_45448190,local_14);
      if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
        do {
          local_1c = (int *)0x0;
          local_8._0_1_ = 3;
          iVar2 = (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_1c);
          if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
            local_18 = (int *)0x0;
            local_8._0_1_ = 4;
            iVar2 = (**(code **)(*local_1c + 0x44))(local_1c,&local_18);
            if ((-1 < iVar2) && (local_18 != (int *)0x0)) {
              param_1 = (int *)0x0;
              local_8._0_1_ = 5;
              iVar2 = (**(code **)(*local_18 + 0x1c))(local_18,L"DisplayName",&param_1);
              if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
                FUN_45429f70((uint *)&local_38,0,0x10);
                VariantInit((VARIANTARG *)&local_38.n2);
                local_8._0_1_ = 6;
                iVar2 = (**(code **)(*param_1 + 0x20))(param_1,&local_38);
                uVar1 = local_38._8_4_;
                if ((-1 < iVar2) && (local_38.n2.vt == 8)) {
                  local_24 = (BSTR)0x0;
                  local_8._0_1_ = 7;
                  if ((BSTR)local_38._8_4_ != (BSTR)0x0) {
                    SysFreeString((BSTR)0x0);
                    local_24 = (BSTR)uVar1;
                  }
                  local_38._8_4_ = (BSTR)0x0;
                  FUN_454094ec(param_2,(int *)&local_24);
                  SysFreeString(local_24);
                }
                VariantClear((VARIANTARG *)&local_38.n2);
              }
              local_8._0_1_ = 4;
              if (param_1 != (int *)0x0) {
                (**(code **)(*param_1 + 8))(param_1);
              }
            }
            local_8._0_1_ = 3;
            if (local_18 != (int *)0x0) {
              (**(code **)(*local_18 + 8))(local_18);
            }
          }
          local_8 = CONCAT31(local_8._1_3_,2);
          if (local_1c != (int *)0x0) {
            (**(code **)(*local_1c + 8))(local_1c);
          }
        } while (iVar2 == 0);
        if (iVar2 < 0) {
          iVar3 = iVar2;
        }
      }
      local_8._0_1_ = 1;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
    FUN_45408930((int *)&local_28);
  }
  return iVar3;
}



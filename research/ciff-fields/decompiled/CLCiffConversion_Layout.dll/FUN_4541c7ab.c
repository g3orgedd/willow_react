// Source: CLCiffConversion_Layout.dll @ 4541c7ab; FUN_4541c7ab

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_4541c7ab(void *this,undefined4 *param_1)

{
  int iVar1;
  _union_2683 local_54;
  _union_2683 local_44;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x4541c7b7;
  FUN_45429f70((uint *)&local_54,0,0x10);
  VariantInit((VARIANTARG *)&local_54.n2);
  local_8 = 0;
  (**(code **)(**(int **)this + 0x7c))(*(int **)this,&local_54);
  if (local_54.n2.vt != 0) {
    CComQIPtr<>(&local_1c,(undefined4 *)local_54._8_4_);
    local_18 = 0;
    local_8._0_1_ = 1;
    (**(code **)(*local_1c + 0x24))(local_1c,&local_18);
    iVar1 = 0;
    if (0 < local_18) {
      do {
        FUN_45429f70((uint *)&local_44,0,0x10);
        VariantInit((VARIANTARG *)&local_44.n2);
        iVar1 = iVar1 + 1;
        local_8._0_1_ = 2;
        (**(code **)(*local_1c + 0x20))(local_1c,iVar1,&local_44);
        if (local_44.n2.vt != 0) {
          CComQIPtr<>(local_14,(undefined4 *)local_44._8_4_);
          local_8._0_1_ = 3;
          (**(code **)(*local_14[0] + 0x2c))(local_14[0],&local_20);
          (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_28);
          (**(code **)(*local_14[0] + 0x1c))(local_14[0],&local_24);
          local_2c = local_20;
          local_34 = local_24;
          local_30 = local_28;
          FUN_4541225e(param_1,(int *)*param_1,&local_34);
          local_8._0_1_ = 2;
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
        }
        VariantClear((VARIANTARG *)&local_44.n2);
      } while (iVar1 < local_18);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
  }
  VariantClear((VARIANTARG *)&local_54.n2);
  return;
}



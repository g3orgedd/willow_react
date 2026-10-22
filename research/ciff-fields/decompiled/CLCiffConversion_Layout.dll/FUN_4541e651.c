// Source: CLCiffConversion_Layout.dll @ 4541e651; FUN_4541e651

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint __fastcall FUN_4541e651(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  HRESULT HVar4;
  _union_2683 local_38;
  _union_2683 local_28;
  BSTR local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  puVar2 = &LAB_45445455;
  local_8 = 0x4541e65d;
  if (*(int *)(param_1 + 0x38) != 0) {
    FUN_45429f70((uint *)&local_28,0,0x10);
    VariantInit((VARIANTARG *)&local_28.n2);
    local_8 = 0;
    (**(code **)(**(int **)(param_1 + 0x38) + 0x480))(*(int **)(param_1 + 0x38),&local_28);
    if (local_28.n2.vt != 0) {
      CComQIPtr<>(local_14,(undefined4 *)local_28._8_4_);
      FUN_45429f70((uint *)&local_38,0,0x10);
      VariantInit((VARIANTARG *)&local_38.n2);
      piVar1 = local_14[0];
      local_8._0_1_ = 2;
      puVar3 = FUN_454028ee(&local_18,L"EAN13PriceVerifier");
      local_8._0_1_ = 3;
      (**(code **)(*piVar1 + 0x30))(piVar1,*puVar3,&local_38);
      SysFreeString(local_18);
      if (local_38.n2.vt != 0) {
        VariantClear((VARIANTARG *)&local_38.n2);
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))(local_14[0]);
        }
        HVar4 = VariantClear((VARIANTARG *)&local_28.n2);
        return CONCAT31((int3)((uint)HVar4 >> 8),1);
      }
      VariantClear((VARIANTARG *)&local_38.n2);
      local_8 = (uint)local_8._1_3_ << 8;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    puVar2 = (undefined1 *)VariantClear((VARIANTARG *)&local_28.n2);
  }
  return (uint)puVar2 & 0xffffff00;
}



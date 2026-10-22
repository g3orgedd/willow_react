// Source: CLCiffConversion_Layout.dll @ 4541eb21; FUN_4541eb21

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __fastcall FUN_4541eb21(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  VARIANTARG local_48;
  VARIANTARG local_38;
  VARIANTARG local_28;
  BSTR local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x4541eb2d;
  FUN_45429f70((uint *)&local_48,0,0x10);
  VariantInit(&local_48);
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)param_1[1] + 0x3c))((int *)param_1[1],&local_48);
  if (-1 < iVar2) {
    CComQIPtr<>(local_14,(undefined4 *)local_48.n1._8_4_);
    FUN_45429f70((uint *)&local_38,0,0x10);
    VariantInit(&local_38);
    piVar1 = local_14[0];
    local_8._0_1_ = 2;
    puVar3 = FUN_454028b9(&local_18,(char *)*param_1);
    local_8._0_1_ = 3;
    iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,*puVar3,&local_38);
    local_8._0_1_ = 2;
    SysFreeString(local_18);
    if (-1 < iVar2) {
      (*(code *)**(undefined4 **)local_38.n1._8_4_)(local_38.n1._8_4_,&DAT_45447e4c,param_1 + 3);
      FUN_45429f70((uint *)&local_28,0,0x10);
      VariantInit(&local_28);
      piVar1 = (int *)param_1[3];
      local_8._0_1_ = 4;
      iVar2 = (**(code **)(*piVar1 + 0x470))(piVar1,&local_28);
      if (-1 < iVar2) {
        (*(code *)**(undefined4 **)local_28.n1._8_4_)(local_28.n1._8_4_,&DAT_45447e6c,param_1 + 4);
      }
      VariantClear(&local_28);
    }
    VariantClear(&local_38);
    local_8 = (uint)local_8._1_3_ << 8;
    if (local_14[0] != (int *)0x0) {
      (**(code **)(*local_14[0] + 8))(local_14[0]);
    }
  }
  VariantClear(&local_48);
  return iVar2;
}



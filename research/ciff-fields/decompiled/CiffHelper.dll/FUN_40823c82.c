// Source: CiffHelper.dll @ 40823c82; FUN_40823c82

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40823c82(BSTR param_1)

{
  int *piVar1;
  BSTR pOVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  _union_2683 local_3c;
  double local_2c;
  undefined4 local_24;
  float local_20;
  float local_1c;
  int local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  pOVar2 = param_1;
  uStack_4 = 0x2c;
  piVar1 = *(int **)param_1;
  if (piVar1 == (int *)0x0) {
    local_24 = 0x80004003;
  }
  else {
    param_1 = (BSTR)0x0;
    local_8 = 0;
    local_24 = (**(code **)(*piVar1 + 0x44))(piVar1);
    bVar3 = FUN_40803ed6(&param_1,L"VJ8510");
    if (((((bVar3) || (bVar3 = FUN_40803ed6(&param_1,L"VJ8610"), bVar3)) ||
         (bVar3 = FUN_40803ed6(&param_1,L"Viper"), bVar3)) ||
        ((bVar3 = FUN_40803ed6(&param_1,L"m600 Touch"), bVar3 ||
         (bVar3 = FUN_40803ed6(&param_1,L"m600 Universal"), bVar3)))) ||
       ((bVar3 = FUN_40803ed6(&param_1,L"VJ8520"), bVar3 ||
        (bVar3 = FUN_40803ed6(&param_1,L"m610 Touch"), bVar3)))) {
      piVar1 = *(int **)pOVar2;
      local_18 = 0;
      iVar4 = (**(code **)(*piVar1 + 0x1c))(piVar1);
      iVar5 = 0;
      if (0 < local_18) {
        do {
          if (iVar4 < 0) break;
          FUN_40802e76((uint *)&local_3c);
          piVar1 = *(int **)pOVar2;
          iVar5 = iVar5 + 1;
          local_8._0_1_ = 1;
          iVar4 = (**(code **)(*piVar1 + 0x24))(piVar1,iVar5);
          if ((-1 < iVar4) && (local_3c.n2.vt == 9)) {
            CComQIPtr<>(local_14,(undefined4 *)local_3c._8_4_);
            local_8._0_1_ = 2;
            if (local_14[0] != (int *)0x0) {
              local_1c = 0.0;
              local_20 = 0.0;
              (**(code **)(*local_14[0] + 0x6c))(local_14[0],&local_1c);
              (**(code **)(*local_14[0] + 0x74))(local_14[0],&local_20);
              fVar6 = FUN_408316cb(SUB84((double)local_1c - _DAT_4084fac8,0),
                                   (int)((ulonglong)((double)local_1c - _DAT_4084fac8) >> 0x20));
              local_2c = (double)fVar6;
              if (DAT_4084fac0 <= local_2c) {
                fVar6 = FUN_408316cb(SUB84((double)local_20 - _DAT_4084fac8,0),
                                     (int)((ulonglong)((double)local_20 - _DAT_4084fac8) >> 0x20));
                local_2c = (double)fVar6;
                if (DAT_4084fac0 <= local_2c) goto LAB_40823e42;
              }
              (**(code **)(*local_14[0] + 0x70))(local_14[0]);
              (**(code **)(*local_14[0] + 0x78))(local_14[0],0x3e71e3a8);
            }
LAB_40823e42:
            local_8._0_1_ = 1;
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))();
            }
          }
          local_8 = (uint)local_8._1_3_ << 8;
          VariantClear((VARIANTARG *)&local_3c.n2);
        } while (iVar5 < local_18);
      }
    }
    SysFreeString(param_1);
  }
  return local_24;
}



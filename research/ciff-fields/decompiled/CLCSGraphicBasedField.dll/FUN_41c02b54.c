// Source: CLCSGraphicBasedField.dll @ 41c02b54; FUN_41c02b54

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __cdecl FUN_41c02b54(BSTR param_1,CComBSTR *param_2,void *param_3)

{
  BSTR pOVar1;
  bool bVar2;
  undefined4 uVar3;
  UINT UVar4;
  code *pcVar5;
  VARIANTARG local_40;
  VARIANTARG local_30;
  int *local_20;
  int local_1c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  pOVar1 = param_1;
  uStack_4 = 0x30;
  local_8 = 0x41c02b60;
  if (*(int *)param_1 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    UVar4 = SysStringLen(*(BSTR *)param_2);
    if (UVar4 == 0) {
      uVar3 = 0x80070057;
    }
    else {
      FUN_41c18d70((uint *)&local_40,0,0x10);
      VariantInit(&local_40);
      local_8 = 0;
      (**(code **)(**(int **)pOVar1 + 100))(*(int **)pOVar1,&local_40);
      CComQIPtr<>(&local_20,(undefined4 *)local_40.n1._8_4_);
      local_1c = 0;
      uVar3 = 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      (**(code **)(*local_20 + 0x1c))(local_20,&local_1c);
      local_18 = 0;
      pcVar5 = VariantClear_exref;
      if (0 < local_1c) {
        do {
          FUN_41c18d70((uint *)&local_30,0,0x10);
          VariantInit(&local_30);
          local_18 = local_18 + 1;
          local_8._0_1_ = 2;
          (**(code **)(*local_20 + 0x30))(local_20,local_18,&local_30);
          CComQIPtr<>(local_14,(undefined4 *)local_30.n1._8_4_);
          param_1 = (BSTR)0x0;
          local_8._0_1_ = 4;
          (**(code **)(*local_14[0] + 0x1c))(local_14[0],&param_1);
          bVar2 = ATL::CComBSTR::operator==((CComBSTR *)&param_1,param_2);
          pcVar5 = VariantClear_exref;
          if (bVar2) {
            FUN_41c0168b(param_3,(int *)local_14);
            SysFreeString(param_1);
            local_8 = CONCAT31(local_8._1_3_,2);
            if (local_14[0] != (int *)0x0) {
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            VariantClear(&local_30);
            uVar3 = 0;
            break;
          }
          SysFreeString(param_1);
          local_8 = CONCAT31(local_8._1_3_,2);
          if (local_14[0] != (int *)0x0) {
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
          VariantClear(&local_30);
        } while (local_18 < local_1c);
      }
      local_8 = local_8 & 0xffffff00;
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
      }
      (*pcVar5)(&local_40);
    }
  }
  return uVar3;
}



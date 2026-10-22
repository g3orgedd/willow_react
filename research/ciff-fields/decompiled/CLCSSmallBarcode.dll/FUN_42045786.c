// Source: CLCSSmallBarcode.dll @ 42045786; FUN_42045786

int FUN_42045786(void *self,VARIANTARG field,VARIANTARG ciffFile)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  BSTR extraout_ECX;
  BSTR pOVar4;
  BSTR pOVar5;
  undefined1 local_7c [8];
  BSTR local_74;
  BSTR local_70;
  BSTR local_6c;
  _union_2683 local_68;
  VARIANTARG local_58;
  _union_2683 local_48;
  int *local_38;
  int local_34;
  int local_30;
  BSTR local_2c;
  int local_28;
  BSTR local_24;
  BSTR local_20;
  int *local_1c;
  BSTR local_18;
  BSTR local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  CComQIPtr<>(&local_8,(undefined4 *)field.n1.decVal.Hi32);
  local_10 = (int *)0x0;
  (**(code **)(*local_8 + 0x5c))();
  FUN_420698e0((uint *)&local_48,0,0x10);
  VariantInit((VARIANTARG *)&local_48.n2);
  (**(code **)(*local_10 + 0x24))();
  if (local_48.n2.vt != 0) {
    CComQIPtr<>(&local_38,(undefined4 *)local_48._8_4_);
    local_2c = (BSTR)0x0;
    (**(code **)(*local_8 + 0x68))();
    piVar1 = local_8;
    puVar3 = FUN_42002eae(&local_24,L"");
    (**(code **)(*piVar1 + 0x9c))(piVar1,*puVar3);
    SysFreeString(local_24);
    (**(code **)(*local_10 + 0x1c))(local_10,&local_28);
    if (0 < local_28) {
      pOVar4 = (BSTR)0x0;
      do {
        FUN_420698e0((uint *)&local_58,0,0x10);
        VariantInit(&local_58);
        pOVar4 = (BSTR)((int)pOVar4 + 1);
        local_20 = pOVar4;
        (**(code **)(*local_10 + 0x24))(local_10);
        CComQIPtr<>(&local_c,(undefined4 *)local_58.n1._8_4_);
        (**(code **)(*local_c + 0x50))(local_c,&local_30);
        if (local_30 == 6) {
          local_20 = (BSTR)0x0;
          (**(code **)(*local_c + 0x58))(local_c,&local_20);
          (**(code **)(*local_c + 100))(local_c,local_20);
          SysFreeString(local_20);
        }
        else {
          local_68.n2.vt = 9;
          local_68._8_4_ = local_c;
          if (local_c != (int *)0x0) {
            (**(code **)(*local_c + 4))(local_c);
          }
          (**(code **)(**(int **)((int)self + 0x78) + 0x1c))
                    (*(int **)((int)self + 0x78),&local_68,field.n1._12_4_,ciffFile.n1._0_4_,
                     ciffFile.n1.decVal.Hi32,ciffFile.n1._8_4_);
          VariantClear((VARIANTARG *)&local_68.n2);
          pOVar4 = local_20;
        }
        local_14 = (BSTR)0x0;
        local_24 = (BSTR)0x0;
        (**(code **)(*local_8 + 0x98))(local_8,&local_14);
        (**(code **)(*local_c + 0x60))(local_c,&local_24);
        FUN_42005ada(&local_14,local_24);
        (**(code **)(*local_8 + 0x9c))(local_8,local_14);
        SysFreeString(local_24);
        SysFreeString(local_14);
        if (local_c != (int *)0x0) {
          (**(code **)(*local_c + 8))();
        }
        VariantClear(&local_58);
      } while ((int)pOVar4 < local_28);
      CComQIPtr<>(&local_1c,local_8);
      (**(code **)(*local_1c + 0xa8))();
      local_18 = (BSTR)0x0;
      (**(code **)(*local_8 + 0x98))(local_8,&local_18);
      pOVar5 = (BSTR)0xffffffff;
      pOVar4 = extraout_ECX;
      FUN_42002e4a(&stack0xffffff5c,(int *)&local_18);
      FUN_42022692(local_7c,local_34,pOVar4,pOVar5);
      FUN_42022efb(local_7c,&self);
      uVar2 = FUN_42043938((int)local_7c);
      if (CONCAT31(extraout_var,uVar2) == 2) {
        local_24 = (BSTR)0x0;
        (**(code **)(*local_1c + 0x100))();
        if (local_24 == (BSTR)0x1) {
          (**(code **)(*local_1c + 0x9c))();
          FUN_4200572b(&local_18,(int *)&self);
        }
      }
      SysFreeString(self);
      SysFreeString(local_6c);
      SysFreeString(local_70);
      SysFreeString(local_74);
      SysFreeString(local_18);
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))();
      }
    }
    SysFreeString(local_2c);
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))();
    }
  }
  VariantClear((VARIANTARG *)&local_48.n2);
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))();
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))();
  }
  return 0;
}



// Source: CLCSBlockTextField.dll @ 41812c81; FUN_41812c81

int FUN_41812c81(void *self,VARIANTARG field,VARIANTARG ciffFile)

{
  bool bVar1;
  BSTR pOVar2;
  _union_2683 local_5c;
  VARIANTARG local_4c;
  VARIANTARG local_3c;
  int *local_2c;
  int local_28;
  int local_24;
  int *local_20;
  BSTR local_1c;
  BSTR local_18;
  BSTR local_14;
  BSTR local_10;
  int *local_c;
  int *local_8;
  
  local_2c = (int *)field.n1.decVal.Hi32;
  if (field.n1.decVal.Hi32 != 0) {
    (**(code **)(*(int *)field.n1.decVal.Hi32 + 4))(field.n1.decVal.Hi32);
  }
  pOVar2 = (BSTR)0x0;
  local_c = (int *)0x0;
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x5c))(field.n1.decVal.Hi32,&local_c);
  FUN_4181e810((uint *)&local_4c,0,0x10);
  VariantInit(&local_4c);
  (**(code **)(*local_c + 0x24))(local_c,1,&local_4c);
  CComQIPtr<>(&local_20,(undefined4 *)local_4c.n1._8_4_);
  local_1c = (BSTR)0x0;
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x68))(field.n1.decVal.Hi32,&local_1c);
  bVar1 = FUN_418016e4(&local_1c,L"OffsetDateText");
  if (!bVar1) goto LAB_41812dbe;
  local_18 = (BSTR)0x0;
  (**(code **)(*local_20 + 0xb4))(local_20,&local_18);
  CComQIPtr<>(&local_10,(undefined4 *)ciffFile.n1.decVal.Hi32);
  if (local_10 != (BSTR)0x0) {
    local_8 = (int *)0x0;
    FUN_41804204((BSTR)&local_10,(CComBSTR *)&local_18,&local_8);
    if (local_8 == (int *)0x0) {
      FUN_418046e1((int *)&local_10,(int *)&local_8);
      local_14 = (BSTR)0x0;
      (**(code **)(*local_8 + 0x1c))(local_8,&local_14);
      (**(code **)(*local_20 + 0xb8))(local_20,local_14);
      (**(code **)(*local_8 + 0x9c))(local_8,&local_28);
      (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x94))(field.n1.decVal.Hi32,local_28 == 2);
      SysFreeString(local_14);
      if (local_8 != (int *)0x0) goto LAB_41812da6;
    }
    else {
LAB_41812da6:
      (**(code **)(*local_8 + 8))(local_8);
    }
    if (local_10 != (BSTR)0x0) {
      (**(code **)(*(int *)local_10 + 8))(local_10);
    }
  }
  SysFreeString(local_18);
LAB_41812dbe:
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x9c))(field.n1.decVal.Hi32,&DAT_41835638);
  (**(code **)(*local_c + 0x1c))(local_c,&local_24);
  if (0 < local_24) {
    do {
      FUN_4181e810((uint *)&local_3c,0,0x10);
      VariantInit(&local_3c);
      pOVar2 = (BSTR)((int)pOVar2 + 1);
      local_18 = pOVar2;
      (**(code **)(*local_c + 0x24))(local_c,pOVar2,&local_3c);
      CComQIPtr<>(&local_8,(undefined4 *)local_3c.n1._8_4_);
      (**(code **)(*local_8 + 0x50))(local_8,&local_28);
      if (local_28 == 6) {
        local_18 = (BSTR)0x0;
        (**(code **)(*local_8 + 0x58))(local_8,&local_18);
        (**(code **)(*local_8 + 100))(local_8,local_18);
        SysFreeString(local_18);
      }
      else {
        local_5c.n2.vt = 9;
        local_5c._8_4_ = local_8;
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))(local_8);
        }
        (**(code **)(**(int **)((int)self + 0x78) + 0x1c))
                  (*(int **)((int)self + 0x78),&local_5c,field.n1._12_4_,ciffFile.n1._0_4_,
                   ciffFile.n1.decVal.Hi32,ciffFile.n1._8_4_);
        VariantClear((VARIANTARG *)&local_5c.n2);
        field.n1.decVal.Hi32 = (ULONG)local_2c;
        pOVar2 = local_18;
      }
      local_10 = (BSTR)0x0;
      local_14 = (BSTR)0x0;
      (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x98))(field.n1.decVal.Hi32,&local_10);
      (**(code **)(*local_8 + 0x60))(local_8,&local_14);
      FUN_41803393(&local_10,local_14);
      (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x9c))(field.n1.decVal.Hi32,local_10);
      SysFreeString(local_14);
      SysFreeString(local_10);
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 8))(local_8);
      }
      VariantClear(&local_3c);
    } while ((int)pOVar2 < local_24);
  }
  SysFreeString(local_1c);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  VariantClear(&local_4c);
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 8))(field.n1.decVal.Hi32);
  return 0;
}



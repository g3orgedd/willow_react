// Source: CLCSGraphicBasedField.dll @ 41c0cee0; FUN_41c0cee0

int FUN_41c0cee0(void *self,VARIANTARG field,VARIANTARG ciffFile)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  LPVOID *ppv;
  _union_2683 local_58;
  VARIANTARG local_48;
  VARIANTARG local_38;
  int local_28;
  int *local_24;
  BSTR local_20;
  BSTR local_1c;
  BSTR local_18;
  int *local_14;
  int *local_10;
  LPVOID *local_c;
  int *local_8;
  
  CComQIPtr<>(&local_8,(undefined4 *)field.n1.decVal.Hi32);
  local_10 = (int *)0x0;
  (**(code **)(*local_8 + 0x5c))(local_8,&local_10);
  FUN_41c18d70((uint *)&local_48,0,0x10);
  VariantInit(&local_48);
  (**(code **)(*local_10 + 0x24))(local_10,1,&local_48);
  CComQIPtr<>(&local_24,(undefined4 *)local_48.n1._8_4_);
  local_20 = (BSTR)0x0;
  (**(code **)(*local_8 + 0x68))(local_8,&local_20);
  bVar1 = FUN_41c01781(&local_20,L"OffsetDateText");
  if (bVar1) {
    local_1c = (BSTR)0x0;
    (**(code **)(*local_24 + 0xb4))(local_24,&local_1c);
    CComQIPtr<>(&local_14,(undefined4 *)ciffFile.n1.decVal.Hi32);
    if (local_14 != (int *)0x0) {
      local_c = (LPVOID *)0x0;
      FUN_41c02b54((BSTR)&local_14,(CComBSTR *)&local_1c,&local_c);
      if (local_c != (LPVOID *)0x0) {
        FUN_41c03098((int *)&local_14,(int *)&local_c);
        local_18 = (BSTR)0x0;
        (**(code **)((int)*local_c + 0x1c))(local_c,&local_18);
        (**(code **)(*local_24 + 0xb8))(local_24,local_18);
        SysFreeString(local_18);
        if (local_c != (LPVOID *)0x0) {
          (**(code **)((int)*local_c + 8))(local_c);
        }
      }
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 8))(local_14);
      }
    }
    SysFreeString(local_1c);
  }
  piVar3 = local_8;
  puVar2 = FUN_41c013b1(&local_1c,L"");
  (**(code **)(*piVar3 + 0x9c))(piVar3,*puVar2);
  SysFreeString(local_1c);
  ppv = (LPVOID *)((int)self + 0x54);
  local_c = ppv;
  if (*ppv == (LPVOID)0x0) {
    CoCreateInstance((IID *)&DAT_41c30d54,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_41c3178c,ppv);
  }
  (**(code **)(*local_10 + 0x1c))(local_10,&local_28);
  if (0 < local_28) {
    piVar3 = (int *)0x0;
    do {
      FUN_41c18d70((uint *)&local_38,0,0x10);
      VariantInit(&local_38);
      local_14 = (int *)((int)piVar3 + 1);
      (**(code **)(*local_10 + 0x24))(local_10,local_14,&local_38);
      CComQIPtr<>(&local_18,(undefined4 *)local_38.n1._8_4_);
      local_58.n2.vt = 9;
      local_58._8_4_ = local_18;
      if (local_18 != (BSTR)0x0) {
        (**(code **)(*(int *)local_18 + 4))(local_18);
      }
      (**(code **)(*(int *)*ppv + 0x1c))
                (*ppv,&local_58,field.n1._12_4_,ciffFile.n1._0_4_,ciffFile.n1.decVal.Hi32,
                 ciffFile.n1._8_4_);
      self = (void *)0x0;
      (**(code **)(*local_8 + 0x98))(local_8,&self);
      local_1c = (BSTR)0x0;
      (**(code **)(*(int *)local_18 + 0x60))(local_18,&local_1c);
      FUN_41c01a2c(&self,local_1c);
      (**(code **)(*local_8 + 0x9c))(local_8,self);
      SysFreeString(local_1c);
      SysFreeString(self);
      VariantClear((VARIANTARG *)&local_58.n2);
      if (local_18 != (BSTR)0x0) {
        (**(code **)(*(int *)local_18 + 8))(local_18);
      }
      VariantClear(&local_38);
      piVar3 = local_14;
      ppv = local_c;
    } while ((int)local_14 < local_28);
  }
  SysFreeString(local_20);
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  VariantClear(&local_48);
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return 0;
}



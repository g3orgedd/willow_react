// Source: CLCSTextBasedField.dll @ 42427b81; FUN_42427b81

int FUN_42427b81(void *self,VARIANTARG field,VARIANTARG ciffFile)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  VARIANTARG local_64;
  VARIANTARG local_54;
  _union_2683 local_44;
  int local_30;
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
  local_c = (int *)0x0;
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x5c))(field.n1.decVal.Hi32,&local_c);
  FUN_42403802((uint *)&local_64);
  (**(code **)(*local_c + 0x24))(local_c,1,&local_64);
  CComQIPtr<>(&local_20,(undefined4 *)local_64.n1._8_4_);
  local_1c = (BSTR)0x0;
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x68))(field.n1.decVal.Hi32,&local_1c);
  bVar2 = FUN_42403bfa(&local_1c,L"OffsetDateText");
  if (!bVar2) goto LAB_42427c8a;
  local_18 = (BSTR)0x0;
  (**(code **)(*local_20 + 0xb4))(local_20,&local_18);
  CComQIPtr<>(&local_10,(undefined4 *)ciffFile.n1.decVal.Hi32);
  if (local_10 != (BSTR)0x0) {
    local_8 = (int *)0x0;
    FUN_424051d3((BSTR)&local_10,(CComBSTR *)&local_18,&local_8);
    if (local_8 == (int *)0x0) {
      FUN_42405861((int *)&local_10,&local_8);
      if (local_8 != (int *)0x0) {
        local_14 = (BSTR)0x0;
        (**(code **)(*local_8 + 0x1c))(local_8,&local_14);
        (**(code **)(*local_20 + 0xb8))(local_20,local_14);
        SysFreeString(local_14);
        if (local_8 != (int *)0x0) goto LAB_42427c72;
      }
    }
    else {
LAB_42427c72:
      (**(code **)(*local_8 + 8))(local_8);
    }
    if (local_10 != (BSTR)0x0) {
      (**(code **)(*(int *)local_10 + 8))(local_10);
    }
  }
  SysFreeString(local_18);
LAB_42427c8a:
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x9c))(field.n1.decVal.Hi32,&DAT_42495874);
  (**(code **)(*local_c + 0x1c))(local_c,&local_24);
  iVar3 = 0;
  if (0 < local_24) {
    do {
      FUN_42403802((uint *)&local_54);
      local_30 = iVar3 + 1;
      (**(code **)(*local_c + 0x24))(local_c,local_30,&local_54);
      CComQIPtr<>(&local_8,(undefined4 *)local_54.n1._8_4_);
      (**(code **)(*local_8 + 0x50))(local_8,&local_28);
      if (local_28 == 6) {
        local_18 = (BSTR)0x0;
        (**(code **)(*local_8 + 0x58))(local_8,&local_18);
        (**(code **)(*local_8 + 100))(local_8,local_18);
        piVar1 = local_8;
        piVar4 = local_8;
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))(local_8);
          piVar4 = piVar1;
          (**(code **)(*piVar1 + 4))(piVar1);
        }
        FUN_42420e0e(piVar4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        SysFreeString(local_18);
      }
      else {
        local_44.n2.vt = 9;
        local_44._8_4_ = local_8;
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))(local_8);
        }
        (**(code **)(**(int **)((int)self + 0xe8) + 0x1c))
                  (*(int **)((int)self + 0xe8),&local_44,field.n1._12_4_,ciffFile.n1._0_4_,
                   ciffFile.n1.decVal.Hi32,ciffFile.n1._8_4_);
        VariantClear((VARIANTARG *)&local_44.n2);
        field.n1.decVal.Hi32 = (ULONG)local_2c;
      }
      local_10 = (BSTR)0x0;
      local_14 = (BSTR)0x0;
      (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x98))(field.n1.decVal.Hi32,&local_10);
      (**(code **)(*local_8 + 0x60))(local_8,&local_14);
      FUN_42403ee7(&local_10,local_14);
      (**(code **)(*(int *)field.n1.decVal.Hi32 + 0x9c))(field.n1.decVal.Hi32,local_10);
      SysFreeString(local_14);
      SysFreeString(local_10);
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 8))(local_8);
      }
      VariantClear(&local_54);
      iVar3 = local_30;
    } while (local_30 < local_24);
  }
  SysFreeString(local_1c);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  VariantClear(&local_64);
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  (**(code **)(*(int *)field.n1.decVal.Hi32 + 8))(field.n1.decVal.Hi32);
  return 0;
}



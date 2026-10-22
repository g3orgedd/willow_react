// Source: CLCSBarcodeField.dll @ 414164f5; FUN_414164f5

int FUN_414164f5(void *self,VARIANTARG field,VARIANTARG ciffFile)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  code *pcVar5;
  _union_2683 local_68;
  VARIANTARG local_58;
  VARIANTARG local_48;
  int *local_38;
  int *local_34;
  int local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_24;
  int local_20;
  BSTR local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  iVar4 = -0x7fffbffb;
  CComQIPtr<>(&local_28,(undefined4 *)ciffFile.n1.decVal.Hi32);
  CComQIPtr<>(&local_8,(undefined4 *)field.n1.decVal.Hi32);
  (**(code **)(*local_8 + 0xa8))(local_8,&local_2c);
  piVar2 = (int *)FUN_414158db((void *)((int)self + -4),local_2c);
  local_34 = piVar2;
  if (piVar2 != (int *)0x0) {
    local_10 = (int *)0x0;
    (**(code **)(*local_8 + 0x5c))(local_8,&local_10);
    FUN_41460bf0((uint *)&local_58,0,0x10);
    VariantInit(&local_58);
    (**(code **)(*local_10 + 0x24))(local_10,1,&local_58);
    CComQIPtr<>(&local_38,(undefined4 *)local_58.n1._8_4_);
    local_24 = 0;
    (**(code **)(*local_8 + 0x68))(local_8,&local_24);
    piVar1 = local_8;
    puVar3 = FUN_41402f15(&local_1c,L"");
    (**(code **)(*piVar1 + 0x9c))(piVar1,*puVar3);
    pcVar5 = SysFreeString_exref;
    SysFreeString(local_1c);
    (**(code **)(*local_10 + 0x1c))(local_10,&local_20);
    if (0 < local_20) {
      iVar4 = 0;
      do {
        FUN_41460bf0((uint *)&local_48,0,0x10);
        VariantInit(&local_48);
        iVar4 = iVar4 + 1;
        (**(code **)(*local_10 + 0x24))(local_10,iVar4,&local_48);
        CComQIPtr<>(&local_c,(undefined4 *)local_48.n1._8_4_);
        (**(code **)(*local_c + 0x50))(local_c,&local_30);
        if (local_30 == 6) {
          local_18 = 0;
          (**(code **)(*local_c + 0x58))(local_c,&local_18);
          (**(code **)(*local_c + 100))(local_c,local_18);
          (*pcVar5)(local_18);
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
          pcVar5 = SysFreeString_exref;
        }
        local_14 = 0;
        local_1c = (BSTR)0x0;
        (**(code **)(*local_8 + 0x98))(local_8,&local_14);
        (**(code **)(*local_c + 0x60))(local_c,&local_1c);
        FUN_41403758(&local_14,local_1c);
        (**(code **)(*local_8 + 0x9c))(local_8,local_14);
        (*pcVar5)(local_1c);
        (*pcVar5)(local_14);
        if (local_c != (int *)0x0) {
          (**(code **)(*local_c + 8))(local_c);
        }
        VariantClear(&local_48);
        piVar2 = local_34;
      } while (iVar4 < local_20);
    }
    iVar4 = (**(code **)(*piVar2 + 0x1c))(&local_28,&local_8);
    (*pcVar5)(local_24);
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))(local_38);
    }
    VariantClear(&local_58);
    if (local_10 != (int *)0x0) {
      (**(code **)(*local_10 + 8))(local_10);
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  return iVar4;
}



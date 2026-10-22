// Source: CLCSBarcodeField.dll @ 41414b7b; FUN_41414b7b

int FUN_41414b7b(void *self,int fieldType,wchar_t *fontName,int fontPitch,VARIANTARG ciffFile,
                wchar_t *subImage,wchar_t *fieldName,VARIANTARG coderCapabilities,
                VARIANTARG *outField)

{
  void *pvVar1;
  wchar_t *pwVar2;
  VARIANTARG *pVVar3;
  HWND pHVar4;
  INT_PTR IVar5;
  int *piVar6;
  int iVar7;
  HRESULT HVar8;
  int iVar9;
  code *pcVar10;
  int *piVar11;
  void **ppvVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  LPARAM LVar16;
  undefined4 local_d4 [8];
  undefined4 local_b4;
  VARIANTARG local_8c;
  VARIANTARG local_7c;
  VARIANTARG local_6c;
  VARIANTARG local_5c;
  _union_2683 local_4c;
  int *local_3c [2];
  undefined4 local_34;
  undefined1 local_30 [4];
  int local_2c;
  wchar_t *local_28;
  BSTR local_24;
  void **local_20;
  int *local_1c;
  int *local_18;
  BSTR local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  pVVar3 = outField;
  if (outField == (VARIANTARG *)0x0) {
    return -0x7fffbffd;
  }
  CComQIPtr<>(&local_8,(undefined4 *)ciffFile.n1._8_4_);
  CComQIPtr<>(&local_10,(undefined4 *)coderCapabilities.n1._8_4_);
  pvVar1 = self;
  FUN_41413c1e((void *)((int)self + 0x70),(int *)&local_10);
  FUN_41460bf0((uint *)&local_6c,0,0x10);
  VariantInit(&local_6c);
  (**(code **)(*local_8 + 0x30))();
  CComQIPtr<>(&outField,(undefined4 *)local_6c.n1._8_4_);
  (**(code **)(*(int *)&outField->n1 + 0x28))();
  CComQIPtr<>(&local_c,*(undefined4 **)((int)&pVVar3->n1 + 8));
  FUN_414139ad(local_30,(GUID *)&DAT_41481228);
  (**(code **)(*local_c + 0x74))();
  local_1c = (int *)0x0;
  (**(code **)(*local_c + 0x5c))();
  FUN_41460bf0((uint *)&local_8c,0,0x10);
  VariantInit(&local_8c);
  (**(code **)(*local_1c + 0x28))();
  CComQIPtr<>(&local_18,(undefined4 *)local_8c.n1._8_4_);
  if (local_18 == (int *)0x0) {
    piVar6 = *(int **)((int)pvVar1 + 0x70);
    if (piVar6 != (int *)0x0) {
      *(undefined4 *)((int)pvVar1 + 0x70) = 0;
      (**(code **)(*piVar6 + 8))();
    }
    iVar7 = -0x7fffbffb;
    pcVar10 = SysFreeString_exref;
    goto LAB_41414f76;
  }
  local_2c = 0;
  local_34 = 0;
  local_24 = (BSTR)0x0;
  (**(code **)(*(int *)&outField->n1 + 0x4c))();
  FUN_41460bf0((uint *)&local_5c,0,0x10);
  VariantInit(&local_5c);
  (**(code **)(*local_10 + 0x470))();
  CComQIPtr<>(local_3c,(undefined4 *)local_5c.n1._8_4_);
  FUN_41460bf0((uint *)&local_7c,0,0x10);
  VariantInit(&local_7c);
  (**(code **)(*local_3c[0] + 0x30))();
  CComQIPtr<>(&local_20,(undefined4 *)local_7c.n1._8_4_);
  local_28 = (wchar_t *)0x0;
  (**(code **)((int)*local_20 + 0x44))();
  if (local_28 == L"Line") {
    piVar6 = &local_2c;
    piVar11 = local_10;
    if (local_10 != (int *)0x0) {
      (**(code **)(*local_10 + 4))();
    }
    piVar14 = local_8;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
    ppvVar12 = local_20;
    if (local_20 != (void **)0x0) {
      (**(code **)((int)*local_20 + 4))(local_20);
    }
    FUN_4144c457(ppvVar12,piVar14,piVar11,piVar6);
  }
  else if (outField != (VARIANTARG *)0x0) {
    (**(code **)(*(int *)&outField->n1 + 100))();
  }
  (**(code **)(*(int *)&outField->n1 + 0x5c))();
  uVar15 = 0;
  uVar13 = 0xe9;
  piVar11 = (int *)0x6a;
  iVar7 = (int)pvVar1 + 0x90;
  piVar6 = local_10;
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 4))(local_10);
  }
  FUN_41454bbe(local_d4,piVar6,iVar7,piVar11,uVar13,uVar15);
  LVar16 = 0;
  pHVar4 = GetActiveWindow();
  IVar5 = FUN_4141508b(local_d4,pHVar4,LVar16);
  if (IVar5 == 1) {
    (**(code **)(*local_c + 0x6c))(local_c);
    piVar6 = (int *)FUN_414158db((void *)((int)pvVar1 + -4),local_b4);
    if (piVar6 == (int *)0x0) goto LAB_41414e2a;
    iVar7 = (**(code **)(*piVar6 + 0x10))();
    if ((iVar7 < 0) && (piVar6 = *(int **)((int)pvVar1 + 0x70), piVar6 != (int *)0x0)) {
      *(undefined4 *)((int)pvVar1 + 0x70) = 0;
      (**(code **)(*piVar6 + 8))();
    }
  }
  else {
    (**(code **)(*(int *)&outField->n1 + 0x2c))(outField);
LAB_41414e2a:
    piVar6 = *(int **)((int)pvVar1 + 0x70);
    if (piVar6 != (int *)0x0) {
      *(undefined4 *)((int)pvVar1 + 0x70) = 0;
      (**(code **)(*piVar6 + 8))();
    }
    iVar7 = -0x7fffbffb;
  }
  local_14 = (BSTR)0x0;
  subImage = (wchar_t *)0x0;
  HVar8 = CoCreateInstance((IID *)&DAT_41480e2c,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_41482148,&subImage);
  pwVar2 = subImage;
  if (HVar8 < 0) {
LAB_41414f00:
    if (subImage != (wchar_t *)0x0) {
      (**(code **)(*(int *)subImage + 8))();
    }
  }
  else if (subImage != (wchar_t *)0x0) {
    local_4c.n2.vt = 9;
    local_4c._8_4_ = local_8;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))();
    }
    iVar9 = (**(code **)(*(int *)pwVar2 + 200))();
    VariantClear((VARIANTARG *)&local_4c.n2);
    if ((-1 < iVar9) && (CComQIPtr<>(&self,local_c), self != (void *)0x0)) {
      local_14 = (BSTR)0x0;
      (**(code **)(*(int *)self + 0x20))();
      pwVar2 = subImage;
      local_4c.n2.vt = 9;
      local_4c._8_4_ = local_8;
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 4))();
      }
      (**(code **)(*(int *)pwVar2 + 0xc4))();
      VariantClear((VARIANTARG *)&local_4c.n2);
      if (self != (void *)0x0) {
        (**(code **)(*(int *)self + 8))();
      }
    }
    goto LAB_41414f00;
  }
  pcVar10 = SysFreeString_exref;
  SysFreeString(local_14);
  FUN_41454ca9(local_d4);
  SysFreeString(local_28);
  if (local_20 != (void **)0x0) {
    (**(code **)((int)*local_20 + 8))();
  }
  VariantClear(&local_7c);
  if (local_3c[0] != (int *)0x0) {
    (**(code **)(*local_3c[0] + 8))();
  }
  VariantClear(&local_5c);
  SysFreeString(local_24);
LAB_41414f76:
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  VariantClear(&local_8c);
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))();
  }
  (*pcVar10)();
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))();
  }
  if (outField != (VARIANTARG *)0x0) {
    (**(code **)(*(int *)&outField->n1 + 8))();
  }
  VariantClear(&local_6c);
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))();
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))();
  }
  return iVar7;
}



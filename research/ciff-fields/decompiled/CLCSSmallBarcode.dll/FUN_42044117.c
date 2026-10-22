// Source: CLCSSmallBarcode.dll @ 42044117; FUN_42044117

int FUN_42044117(void *self,int fieldType,wchar_t *fontName,int fontPitch,VARIANTARG ciffFile,
                wchar_t *subImage,wchar_t *fieldName,VARIANTARG coderCapabilities,
                VARIANTARG *outField)

{
  VARIANTARG *pVVar1;
  bool bVar2;
  HWND pHVar3;
  INT_PTR IVar4;
  int iVar5;
  int *piVar6;
  HRESULT HVar7;
  code *pcVar8;
  code *pcVar9;
  int iVar10;
  void **ppvVar11;
  int *piVar12;
  undefined4 uVar13;
  wchar_t **ppwVar14;
  undefined4 uVar15;
  LPARAM LVar16;
  undefined4 local_d0 [8];
  int local_b0;
  VARIANTARG local_88;
  VARIANTARG local_78;
  VARIANTARG local_68;
  VARIANTARG local_58;
  _union_2683 local_48;
  undefined1 local_38 [4];
  int *local_34 [2];
  BSTR local_2c;
  void **local_28;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  BSTR local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  pVVar1 = outField;
  if (outField == (VARIANTARG *)0x0) {
    return -0x7fffbffd;
  }
  CComQIPtr<>(&local_8,(undefined4 *)ciffFile.n1._8_4_);
  CComQIPtr<>(&local_c,(undefined4 *)coderCapabilities.n1._8_4_);
  if ((local_8 == (int *)0x0) || (local_c == (int *)0x0)) {
    iVar10 = -0x7fffbffb;
    goto LAB_42044637;
  }
  FUN_420698e0((uint *)&local_68,0,0x10);
  VariantInit(&local_68);
  (**(code **)(*local_8 + 0x30))();
  CComQIPtr<>(&local_10,(undefined4 *)local_68.n1._8_4_);
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 0x28))();
  }
  CComQIPtr<>(&outField,*(undefined4 **)((int)&pVVar1->n1 + 8));
  pcVar8 = VariantClear_exref;
  if (outField == (VARIANTARG *)0x0) {
    iVar10 = -0x7fffbffd;
  }
  else {
    FUN_42043628(local_38,(GUID *)&DAT_4209c448);
    (**(code **)(*(int *)&outField->n1 + 0x74))();
    local_20 = (int *)0x0;
    iVar10 = (**(code **)(*(int *)&outField->n1 + 0x5c))();
    FUN_420698e0((uint *)&local_88,0,0x10);
    VariantInit(&local_88);
    if ((-1 < iVar10) && (local_20 != (int *)0x0)) {
      iVar10 = (**(code **)(*local_20 + 0x28))(local_20,0,0);
    }
    CComQIPtr<>(&local_1c,(undefined4 *)local_88.n1._8_4_);
    pcVar9 = SysFreeString_exref;
    if ((iVar10 < 0) || (local_1c == (int *)0x0)) {
      piVar6 = *(int **)((int)self + 0x70);
      if (piVar6 != (int *)0x0) {
        *(undefined4 *)((int)self + 0x70) = 0;
        (**(code **)(*piVar6 + 8))();
      }
      iVar10 = -0x7fffbffb;
    }
    else {
      subImage = (wchar_t *)0x0;
      local_24 = (BSTR)0x0;
      if (local_10 != (int *)0x0) {
        (**(code **)(*local_10 + 0x4c))();
      }
      FUN_420698e0((uint *)&local_58,0,0x10);
      VariantInit(&local_58);
      iVar10 = (**(code **)(*local_c + 0x470))();
      CComQIPtr<>(local_34,(undefined4 *)local_58.n1._8_4_);
      FUN_420698e0((uint *)&local_78,0,0x10);
      VariantInit(&local_78);
      if ((-1 < iVar10) && (local_34[0] != (int *)0x0)) {
        iVar10 = (**(code **)(*local_34[0] + 0x30))();
      }
      CComQIPtr<>(&local_28,(undefined4 *)local_78.n1._8_4_);
      local_2c = (BSTR)0x0;
      if (iVar10 < 0) {
LAB_42044356:
        if (local_10 != (int *)0x0) {
          iVar10 = (**(code **)(*local_10 + 100))();
        }
      }
      else {
        if (local_28 != (void **)0x0) {
          iVar10 = (**(code **)((int)*local_28 + 0x44))();
        }
        if ((iVar10 < 0) || (bVar2 = FUN_42003230(&local_2c,L"Line"), !bVar2)) goto LAB_42044356;
        ppwVar14 = &subImage;
        piVar6 = local_c;
        if (local_c != (int *)0x0) {
          (**(code **)(*local_c + 4))();
        }
        piVar12 = local_8;
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))(local_8);
        }
        ppvVar11 = local_28;
        if (local_28 != (void **)0x0) {
          (**(code **)((int)*local_28 + 4))(local_28);
        }
        iVar10 = FUN_42003cc2(ppvVar11,piVar12,piVar6,(int *)ppwVar14);
      }
      uVar15 = 0;
      uVar13 = 0xe9;
      piVar12 = (int *)0xc9;
      iVar5 = (int)self + 0x88;
      piVar6 = local_c;
      if (local_c != (int *)0x0) {
        (**(code **)(*local_c + 4))(local_c);
      }
      FUN_42016340(local_d0,piVar6,iVar5,piVar12,uVar13,uVar15);
      LVar16 = 0;
      pHVar3 = GetActiveWindow();
      IVar4 = FUN_42044704(local_d0,pHVar3,LVar16);
      if (IVar4 == 1) {
        (**(code **)(*(int *)&outField->n1 + 0x6c))();
        if (local_b0 == 5) {
          FUN_42044dcd(local_d0,&fieldName);
          iVar5 = _wcscmp(fieldName,L"EAN13PriceVerifier");
          if (iVar5 == 0) {
            (**(code **)(*(int *)&outField->n1 + 0x6c))();
          }
          FUN_42003103((int *)&fieldName);
        }
        piVar6 = (int *)FUN_42044d95(self,local_b0);
        if ((piVar6 != (int *)0x0) &&
           (iVar10 = (**(code **)(*piVar6 + 0x10))(&local_8,&local_c), -1 < iVar10)) {
          fieldName = (wchar_t *)0x0;
          iVar10 = (**(code **)(*(int *)&outField->n1 + 0xb8))();
          if (-1 < iVar10) {
            if ((int)subImage < (int)fieldName) {
              iVar10 = (**(code **)(*(int *)&outField->n1 + 0xbc))();
            }
            if (-1 < iVar10) goto LAB_420444a5;
          }
        }
        piVar6 = *(int **)((int)self + 0x70);
        if (piVar6 != (int *)0x0) {
          *(undefined4 *)((int)self + 0x70) = 0;
          (**(code **)(*piVar6 + 8))();
        }
      }
      else if (local_10 != (int *)0x0) {
        (**(code **)(*local_10 + 0x2c))();
        piVar6 = *(int **)((int)self + 0x70);
        if (piVar6 != (int *)0x0) {
          *(undefined4 *)((int)self + 0x70) = 0;
          (**(code **)(*piVar6 + 8))();
        }
        iVar10 = -0x7fffbffb;
      }
LAB_420444a5:
      local_14 = (BSTR)0x0;
      local_18 = (int *)0x0;
      HVar7 = CoCreateInstance((IID *)&DAT_4208a8c8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_420932d8,
                               &local_18);
      piVar6 = local_18;
      if (HVar7 < 0) {
LAB_4204456b:
        if (local_18 != (int *)0x0) {
          (**(code **)(*local_18 + 8))();
        }
      }
      else if (local_18 != (int *)0x0) {
        local_48.n2.vt = 9;
        local_48._8_4_ = local_8;
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))();
        }
        iVar5 = (**(code **)(*piVar6 + 200))();
        VariantClear((VARIANTARG *)&local_48.n2);
        if ((-1 < iVar5) &&
           (CComQIPtr<>(&fieldName,(undefined4 *)outField), fieldName != (wchar_t *)0x0)) {
          local_14 = (BSTR)0x0;
          (**(code **)(*(int *)fieldName + 0x20))();
          piVar6 = local_18;
          local_48._8_4_ = *(undefined4 *)((int)self + 0x6c);
          local_48.n2.vt = 9;
          if ((int *)local_48._8_4_ != (int *)0x0) {
            (**(code **)(*(int *)local_48._8_4_ + 4))();
          }
          (**(code **)(*piVar6 + 0xc4))(piVar6);
          VariantClear((VARIANTARG *)&local_48.n2);
          if (fieldName != (wchar_t *)0x0) {
            (**(code **)(*(int *)fieldName + 8))();
          }
        }
        goto LAB_4204456b;
      }
      pcVar9 = SysFreeString_exref;
      SysFreeString(local_14);
      FUN_42016472(local_d0);
      SysFreeString(local_2c);
      if (local_28 != (void **)0x0) {
        (**(code **)((int)*local_28 + 8))();
      }
      pcVar8 = VariantClear_exref;
      VariantClear(&local_78);
      if (local_34[0] != (int *)0x0) {
        (**(code **)(*local_34[0] + 8))();
      }
      VariantClear(&local_58);
      SysFreeString(local_24);
    }
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))();
    }
    (*pcVar8)();
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))();
    }
    (*pcVar9)();
    if (outField != (VARIANTARG *)0x0) {
      (**(code **)(*(int *)&outField->n1 + 8))();
    }
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))();
  }
  (*pcVar8)();
LAB_42044637:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))();
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))();
  }
  return iVar10;
}



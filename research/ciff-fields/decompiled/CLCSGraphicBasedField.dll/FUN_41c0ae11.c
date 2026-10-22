// Source: CLCSGraphicBasedField.dll @ 41c0ae11; FUN_41c0ae11

int FUN_41c0ae11(void *self,int fieldType,wchar_t *fontName,int fontPitch,VARIANTARG ciffFile,
                wchar_t *subImage,wchar_t *fieldName,VARIANTARG coderCapabilities,
                VARIANTARG *outField)

{
  wchar_t *pwVar1;
  VARIANTARG *pVVar2;
  int iVar3;
  HRESULT HVar4;
  int iVar5;
  BSTR extraout_ECX;
  BSTR pOVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  IUnknown *pIVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  _union_2683 local_2c;
  VARIANTARG local_1c;
  IUnknown local_c;
  int *local_8;
  
  CComQIPtr<>(&local_8,(undefined4 *)ciffFile.n1._8_4_);
  FUN_41c18d70((uint *)&local_1c,0,0x10);
  VariantInit(&local_1c);
  iVar3 = (**(code **)(*local_8 + 0x30))();
  if (iVar3 != 0) goto LAB_41c0affa;
  CComQIPtr<>(&local_c,(undefined4 *)local_1c.n1._8_4_);
  iVar3 = (**(code **)((local_c.lpVtbl)->QueryInterface + 0x28))();
  pVVar2 = outField;
  if (-1 < iVar3) {
    pIVar12 = &local_c;
    puVar7 = *(undefined4 **)((int)&outField->n1 + 8);
    pOVar6 = extraout_ECX;
    iVar5 = fontPitch;
    uVar8 = ciffFile.n1._0_4_;
    uVar9 = ciffFile.n1.decVal.Hi32;
    uVar10 = ciffFile.n1._8_4_;
    uVar11 = ciffFile.n1._12_4_;
    uVar13 = coderCapabilities.n1._0_4_;
    uVar14 = coderCapabilities.n1.decVal.Hi32;
    uVar15 = coderCapabilities.n1._8_4_;
    uVar16 = coderCapabilities.n1._12_4_;
    FUN_41c013b1(&stack0xffffff8c,fontName);
    FUN_41c0b0c7(self,pOVar6,iVar5,puVar7,uVar8,uVar9,(undefined4 *)uVar10,uVar11,pIVar12,uVar13,
                 uVar14,(int *)uVar15,uVar16);
    CComQIPtr<>(&outField,*(undefined4 **)((int)&pVVar2->n1 + 8));
    (**(code **)(*(int *)&outField->n1 + 0x28))();
    (**(code **)(*(int *)&outField->n1 + 0x48))();
    (**(code **)(*(int *)&outField->n1 + 0x50))();
    (**(code **)(*(int *)&outField->n1 + 0x40))();
    (**(code **)(*(int *)&outField->n1 + 0x58))();
    (**(code **)(*(int *)&outField->n1 + 0x94))();
    fieldName = (wchar_t *)0x0;
    subImage = (wchar_t *)0x0;
    HVar4 = CoCreateInstance((IID *)&DAT_41c30d54,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_41c3179c,&subImage
                            );
    pwVar1 = subImage;
    if (HVar4 < 0) {
LAB_41c0afca:
      if (subImage != (wchar_t *)0x0) {
        (**(code **)(*(int *)subImage + 8))();
      }
    }
    else if (subImage != (wchar_t *)0x0) {
      local_2c.n2.vt = 9;
      local_2c._8_4_ = local_8;
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 4))();
      }
      iVar5 = (**(code **)(*(int *)pwVar1 + 200))();
      VariantClear((VARIANTARG *)&local_2c.n2);
      if (-1 < iVar5) {
        CComQIPtr<>(&fontPitch,(undefined4 *)outField);
        if (fontPitch != 0) {
          fieldName = (wchar_t *)0x0;
          (**(code **)(*(int *)fontPitch + 0x20))();
          pwVar1 = subImage;
          local_2c.n2.vt = 9;
          local_2c._8_4_ = local_8;
          if (local_8 != (int *)0x0) {
            (**(code **)(*local_8 + 4))();
          }
          (**(code **)(*(int *)pwVar1 + 0xc4))();
          VariantClear((VARIANTARG *)&local_2c.n2);
          if (fontPitch != 0) {
            (**(code **)(*(int *)fontPitch + 8))();
          }
        }
      }
      goto LAB_41c0afca;
    }
    SysFreeString(fieldName);
    if (outField != (VARIANTARG *)0x0) {
      (**(code **)(*(int *)&outField->n1 + 8))();
    }
  }
  if (local_c.lpVtbl != (IUnknownVtbl *)0x0) {
    (**(code **)((local_c.lpVtbl)->QueryInterface + 8))();
  }
LAB_41c0affa:
  VariantClear(&local_1c);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))();
  }
  return iVar3;
}



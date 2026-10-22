// Source: CLCSTextBasedField.dll @ 42421f6e; FUN_42421f6e

int FUN_42421f6e(void *self,int fieldType,wchar_t *fontName,int fontPitch,VARIANTARG ciffFile,
                wchar_t *subImage,wchar_t *fieldName,VARIANTARG coderCapabilities,
                VARIANTARG *outField)

{
  void *pvVar1;
  VARIANTARG *pVVar2;
  bool bVar3;
  HRESULT HVar4;
  UINT UVar5;
  BSTR pOVar6;
  int iVar7;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  wchar_t *pwVar8;
  uint uVar9;
  VARTYPE VVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  wchar_t **ppwVar17;
  int *piVar18;
  BSTR pOVar19;
  undefined4 local_98 [18];
  VARIANTARG local_50;
  _union_2683 local_40;
  _union_2683 local_30;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int *local_c;
  int *local_8;
  
  CComQIPtr<>(&local_8,(undefined4 *)ciffFile.n1._8_4_);
  FUN_42403802((uint *)&local_50);
  (**(code **)(*local_8 + 0x30))();
  CComQIPtr<>(&local_20,(undefined4 *)local_50.n1._8_4_);
  pVVar2 = outField;
  local_18 = (**(code **)(*local_20 + 0x28))();
  pwVar8 = fontName;
  if (local_18 < 0) goto LAB_42422459;
  subImage = (wchar_t *)CONCAT13(1,subImage._0_3_);
  pOVar6 = (BSTR)(fieldType + -1);
  if (pOVar6 == (BSTR)0x0) {
    piVar18 = *(int **)((int)&pVVar2->n1 + 8);
    iVar7 = fontPitch;
    uVar11 = coderCapabilities.n1._0_4_;
    uVar13 = coderCapabilities.n1.decVal.Hi32;
    uVar15 = coderCapabilities.n1._8_4_;
    uVar16 = coderCapabilities.n1._12_4_;
    FUN_424037d2(&stack0xffffff20,fontName);
    FUN_424233b5(pOVar6,iVar7,uVar11,uVar13,(undefined4 *)uVar15,uVar16,piVar18);
LAB_4242219c:
    if (subImage._3_1_ == '\0') goto LAB_42422459;
  }
  else {
    pOVar6 = (BSTR)(fieldType + -2);
    if (pOVar6 == (BSTR)0x0) {
      piVar18 = *(int **)((int)&pVVar2->n1 + 8);
      iVar7 = fontPitch;
      uVar11 = coderCapabilities.n1._0_4_;
      uVar13 = coderCapabilities.n1.decVal.Hi32;
      uVar15 = coderCapabilities.n1._8_4_;
      uVar16 = coderCapabilities.n1._12_4_;
      FUN_424037d2(&stack0xffffff20,fontName);
      FUN_4242296c(pOVar6,iVar7,uVar11,uVar13,(undefined4 *)uVar15,uVar16,piVar18);
    }
    else {
      pOVar6 = (BSTR)(fieldType + -3);
      if (pOVar6 == (BSTR)0x0) {
        piVar18 = *(int **)((int)&pVVar2->n1 + 8);
        iVar7 = fontPitch;
        uVar11 = coderCapabilities.n1._0_4_;
        uVar13 = coderCapabilities.n1.decVal.Hi32;
        uVar15 = coderCapabilities.n1._8_4_;
        uVar16 = coderCapabilities.n1._12_4_;
        FUN_424037d2(&stack0xffffff20,fontName);
        FUN_424226b2(pOVar6,iVar7,uVar11,uVar13,(undefined4 *)uVar15,uVar16,piVar18);
      }
      else {
        iVar7 = fieldType + -4;
        if (iVar7 == 0) {
          piVar18 = *(int **)((int)&pVVar2->n1 + 8);
          iVar12 = fontPitch;
          uVar11 = coderCapabilities.n1._0_4_;
          uVar13 = coderCapabilities.n1.decVal.Hi32;
          uVar15 = coderCapabilities.n1._8_4_;
          uVar16 = coderCapabilities.n1._12_4_;
          FUN_424037d2(&stack0xffffff20,fontName);
          FUN_42422d37((void *)((int)self + -8),ciffFile.n1._0_4_,ciffFile.n1.decVal.Hi32,
                       (undefined4 *)ciffFile.n1._8_4_,ciffFile.n1._12_4_,iVar7,iVar12,uVar11,uVar13
                       ,(undefined4 *)uVar15,uVar16,piVar18);
        }
        else {
          pOVar6 = (BSTR)(fieldType + -5);
          if (pOVar6 == (BSTR)0x0) {
            fieldType = 0;
            FUN_42405861((int *)&local_8,&fieldType);
            pwVar8 = fontName;
            pvVar1 = self;
            if (fieldType == 0) {
              subImage = (wchar_t *)((uint)subImage & 0xffffff);
              *(undefined1 *)((int)self + 0xf0) = 1;
              FUN_42403b70((void *)((int)self + 0xf4),fontName);
              *(int *)((int)pvVar1 + 0xf8) = fontPitch;
              *(undefined4 *)((int)pvVar1 + 0xfc) = *(undefined4 *)((int)&pVVar2->n1 + 8);
              SendMessageW(*(HWND *)((int)pvVar1 + 0xe4),0x405,0,*(LPARAM *)((int)pvVar1 + 0x30));
            }
            else {
              fieldName = (wchar_t *)0x0;
              (**(code **)(*(int *)fieldType + 0x1c))();
              pOVar19 = extraout_ECX;
              FUN_42403768(&stack0xffffff38,(int *)&fieldName);
              pwVar8 = fontName;
              piVar18 = *(int **)((int)&pVVar2->n1 + 8);
              pOVar6 = extraout_ECX_00;
              iVar7 = fontPitch;
              uVar11 = coderCapabilities.n1._0_4_;
              uVar13 = coderCapabilities.n1.decVal.Hi32;
              uVar15 = coderCapabilities.n1._8_4_;
              uVar16 = coderCapabilities.n1._12_4_;
              FUN_424037d2(&stack0xffffff1c,fontName);
              FUN_42422b48(pOVar6,iVar7,uVar11,uVar13,(undefined4 *)uVar15,uVar16,piVar18,pOVar19);
              SysFreeString(fieldName);
            }
            if (fieldType != 0) {
              (**(code **)(*(int *)fieldType + 8))();
            }
            goto LAB_4242219c;
          }
          piVar18 = *(int **)((int)&pVVar2->n1 + 8);
          iVar7 = fontPitch;
          uVar11 = coderCapabilities.n1._0_4_;
          uVar13 = coderCapabilities.n1.decVal.Hi32;
          uVar15 = coderCapabilities.n1._8_4_;
          uVar16 = coderCapabilities.n1._12_4_;
          FUN_424037d2(&stack0xffffff20,fontName);
          FUN_424231a9(pOVar6,iVar7,uVar11,uVar13,(undefined4 *)uVar15,uVar16,piVar18);
        }
      }
    }
  }
  fontName = (wchar_t *)((uint)fontName & 0xffffff00);
  local_10 = local_10 & 0xffffff00;
  uVar11 = 1;
  CComQIPtr<>(&fieldType,(undefined4 *)coderCapabilities.n1._8_4_);
  if (fieldType != 0) {
    self = (void *)0x0;
    (**(code **)(*(int *)fieldType + 0x29c))();
    fontName = (wchar_t *)((uint)fontName & 0xff);
    if (self == (void *)0x1) {
      fontName = (wchar_t *)0x1;
    }
  }
  CComQIPtr<>(&fontPitch,*(undefined4 **)((int)&outField->n1 + 8));
  if (fontPitch != 0) {
    if ((char)fontName == '\0') {
      FUN_42403802((uint *)&local_30);
      (**(code **)(*(int *)fieldType + 0x474))();
      CComQIPtr<>(&local_c,(undefined4 *)local_30._8_4_);
      (**(code **)(*local_c + 0x24))();
      iVar7 = 0;
      uVar9 = local_10;
      if (0 < local_14) {
        do {
          FUN_42403802((uint *)&local_40);
          iVar7 = iVar7 + 1;
          (**(code **)(*local_c + 0x20))();
          if (local_40.n2.vt != 0) {
            CComQIPtr<>(&self,(undefined4 *)local_40._8_4_);
            outField = (VARIANTARG *)0x0;
            (**(code **)(*(int *)self + 0x1c))();
            bVar3 = FUN_42403bfa(&outField,pwVar8);
            if (bVar3) {
              (**(code **)(*(int *)self + 0x4c))();
              uVar9 = local_10 & 0xff;
              if (local_1c != 0) {
                uVar9 = 1;
              }
              fontName = (wchar_t *)0x0;
              local_18 = (**(code **)(*(int *)self + 0x9c))();
              if ((-1 < local_18) && (UVar5 = SysStringLen(fontName), uVar11 = 1, UVar5 != 0)) {
                bVar3 = FUN_42403bfa(&fontName,L"TrueType");
                if (bVar3) {
                  uVar11 = 1;
                }
                else {
                  bVar3 = FUN_42403bfa(&fontName,L"ZFBF");
                  if (bVar3) {
                    uVar11 = 2;
                  }
                  else {
                    bVar3 = FUN_42403bfa(&fontName,L"FixedBitmap");
                    if (bVar3) {
                      uVar11 = 0;
                    }
                  }
                }
              }
              SysFreeString(fontName);
              SysFreeString((BSTR)outField);
              if (self != (void *)0x0) {
                (**(code **)(*(int *)self + 8))();
              }
              VariantClear((VARIANTARG *)&local_40.n2);
              break;
            }
            SysFreeString((BSTR)outField);
            if (self != (void *)0x0) {
              (**(code **)(*(int *)self + 8))();
            }
          }
          VariantClear((VARIANTARG *)&local_40.n2);
          uVar9 = local_10;
        } while (iVar7 < local_14);
      }
      if (local_c != (int *)0x0) {
        (**(code **)(*local_c + 8))();
      }
      VariantClear((VARIANTARG *)&local_30.n2);
      if ((char)uVar9 == '\0') goto LAB_424222ef;
      (**(code **)(*(int *)fontPitch + 0xc4))();
    }
    else {
      uVar11 = 2;
      FUN_424037d2(&outField,pwVar8);
      (**(code **)(*(int *)fontPitch + 0xac))();
      CComQIPtr<>(&self,(undefined4 *)fontPitch);
      if (self != (void *)0x0) {
        FUN_42458671(&local_10);
        FUN_42467b8d(local_98);
        ppwVar17 = &fontName;
        fontName = (wchar_t *)0x0;
        pOVar6 = extraout_ECX_01;
        FUN_42403768(&stack0xffffff2c,(int *)&outField);
        FUN_42467f17(local_98,pOVar6,(uint *)ppwVar17);
        (**(code **)(*local_8 + 0x54))();
        local_c = (int *)0x0;
        FUN_42420daa(&local_c,&fieldType);
        piVar18 = local_c;
        if (local_14 == 0) {
          piVar14 = local_c;
          if (local_c != (int *)0x0) {
            (**(code **)(*local_c + 4))();
          }
          FUN_42458843((int)fontName,0.0,piVar14);
        }
        (**(code **)(*(int *)self + 0x154))();
        if (piVar18 != (int *)0x0) {
          (**(code **)(*piVar18 + 8))();
        }
        FUN_42467c23(local_98);
        FUN_42458752(&local_10);
        if (self != (void *)0x0) {
          (**(code **)(*(int *)self + 8))();
        }
      }
      SysFreeString((BSTR)outField);
LAB_424222ef:
      (**(code **)(*(int *)fontPitch + 0xc4))();
    }
    (**(code **)(*(int *)fontPitch + 0x110))();
    (**(code **)(*(int *)fontPitch + 0x28))();
    (**(code **)(*(int *)fontPitch + 0x48))(fontPitch,0);
    (**(code **)(*(int *)fontPitch + 0x50))(fontPitch,0);
    (**(code **)(*(int *)fontPitch + 0x40))(fontPitch,0);
    (**(code **)(*(int *)fontPitch + 0x58))(fontPitch,0);
    (**(code **)(*(int *)fontPitch + 0x94))(fontPitch,0);
    (**(code **)(*(int *)fontPitch + 0xcc))(fontPitch,0);
    (**(code **)(*(int *)fontPitch + 0x128))(fontPitch,uVar11);
    fieldName = (wchar_t *)0x0;
    subImage = (wchar_t *)0x0;
    HVar4 = CoCreateInstance((IID *)&DAT_42495e00,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_42495e7c,&subImage
                            );
    pwVar8 = subImage;
    if (HVar4 < 0) {
LAB_42422426:
      if (subImage != (wchar_t *)0x0) {
        (**(code **)(*(int *)subImage + 8))();
      }
    }
    else if (subImage != (wchar_t *)0x0) {
      local_30._8_4_ = local_8;
      VVar10 = 9;
      local_30.n2.vt = VVar10;
      if (local_8 != (int *)0x0) {
        (**(code **)(*local_8 + 4))();
      }
      iVar7 = (**(code **)(*(int *)pwVar8 + 200))();
      VariantClear((VARIANTARG *)&local_30.n2);
      if ((-1 < iVar7) &&
         (CComQIPtr<>(&fontName,(undefined4 *)fontPitch), fontName != (wchar_t *)0x0)) {
        fieldName = (wchar_t *)0x0;
        (**(code **)(*(int *)fontName + 0x20))();
        pwVar8 = subImage;
        local_30._8_4_ = local_8;
        local_30.n2.vt = VVar10;
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))();
        }
        (**(code **)(*(int *)pwVar8 + 0xc4))();
        VariantClear((VARIANTARG *)&local_30.n2);
        if (fontName != (wchar_t *)0x0) {
          (**(code **)(*(int *)fontName + 8))();
        }
      }
      goto LAB_42422426;
    }
    SysFreeString(fieldName);
    if (fontPitch != 0) {
      (**(code **)(*(int *)fontPitch + 8))();
    }
  }
  if (fieldType != 0) {
    (**(code **)(*(int *)fieldType + 8))();
  }
LAB_42422459:
  iVar7 = local_18;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))();
  }
  VariantClear(&local_50);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))();
  }
  return iVar7;
}



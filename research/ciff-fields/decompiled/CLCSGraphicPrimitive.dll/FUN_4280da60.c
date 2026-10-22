// Source: CLCSGraphicPrimitive.dll @ 4280da60; FUN_4280da60

int FUN_4280da60(void *self,int fieldType,wchar_t *fontName,int fontPitch,VARIANTARG ciffFile,
                wchar_t *subImage,wchar_t *fieldName,VARIANTARG coderCapabilities,
                VARIANTARG *outField)

{
  void *pvVar1;
  wchar_t *pwVar2;
  VARIANTARG *pVVar3;
  UINT UVar4;
  HRESULT HVar5;
  int iVar6;
  _union_2683 local_48;
  VARIANTARG local_38;
  VARIANTARG local_28;
  int *local_18;
  BSTR local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  CComQIPtr<>(&local_8,(undefined4 *)ciffFile.n1._8_4_);
  FUN_42812970((uint *)&local_38,0,0x10);
  VariantInit(&local_38);
  (**(code **)(*local_8 + 0x30))(local_8,subImage,&local_38);
  CComQIPtr<>(&local_18,(undefined4 *)local_38.n1._8_4_);
  pVVar3 = outField;
  (**(code **)(*local_18 + 0x28))(local_18,2,fieldName,0,outField);
  FUN_4280dcfd(*(int **)((int)&pVVar3->n1 + 8),ciffFile.n1._0_4_,ciffFile.n1.decVal.Hi32,
               (undefined4 *)ciffFile.n1._8_4_);
  CComQIPtr<>(&subImage,*(undefined4 **)((int)&pVVar3->n1 + 8));
  (**(code **)(*(int *)subImage + 0x6c))(subImage,L"GraphicPrimitive");
  (**(code **)(*(int *)subImage + 0x28))(subImage,1);
  (**(code **)(*(int *)subImage + 0x48))(subImage,0);
  (**(code **)(*(int *)subImage + 0x50))(subImage,0);
  (**(code **)(*(int *)subImage + 0x40))(subImage,0);
  (**(code **)(*(int *)subImage + 0x58))(subImage,0);
  (**(code **)(*(int *)subImage + 0x94))(subImage,0);
  FUN_4280d201(&local_14,(GUID *)&DAT_4282c898);
  (**(code **)(*(int *)subImage + 0x74))(subImage,local_14);
  local_c = (int *)0x0;
  (**(code **)(*(int *)subImage + 0x5c))(subImage,&local_c);
  FUN_42812970((uint *)&local_28,0,0x10);
  VariantInit(&local_28);
  (**(code **)(*local_c + 0x28))(local_c,0,0,1,0,&local_28);
  CComQIPtr<>(&self,(undefined4 *)local_28.n1._8_4_);
  (**(code **)(*(int *)self + 0x54))(self,0);
  pvVar1 = self;
  UVar4 = SysStringLen((BSTR)0x0);
  (**(code **)(*(int *)pvVar1 + 0x98))(pvVar1,UVar4);
  (**(code **)(*(int *)self + 0x5c))(self,0);
  fieldName = (wchar_t *)0x0;
  outField = (VARIANTARG *)0x0;
  HVar5 = CoCreateInstance((IID *)&DAT_4282c8b8,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_4282d2e0,&outField);
  pVVar3 = outField;
  if (-1 < HVar5) {
    if (outField == (VARIANTARG *)0x0) goto LAB_4280dc92;
    local_48.n2.vt = 9;
    local_48._8_4_ = local_8;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
    iVar6 = (**(code **)(*(int *)&pVVar3->n1 + 200))(pVVar3,&local_48,&fieldName);
    VariantClear((VARIANTARG *)&local_48.n2);
    if (-1 < iVar6) {
      CComQIPtr<>(&local_10,(undefined4 *)subImage);
      pwVar2 = fieldName;
      if (local_10 != (int *)0x0) {
        fieldName = (wchar_t *)0x0;
        (**(code **)(*local_10 + 0x20))(local_10,pwVar2);
        pVVar3 = outField;
        local_48.n2.vt = 9;
        local_48._8_4_ = local_8;
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 4))(local_8);
        }
        (**(code **)(*(int *)&pVVar3->n1 + 0xc4))(pVVar3,&local_48);
        VariantClear((VARIANTARG *)&local_48.n2);
        if (local_10 != (int *)0x0) {
          (**(code **)(*local_10 + 8))(local_10);
        }
      }
    }
  }
  if (outField != (VARIANTARG *)0x0) {
    (**(code **)(*(int *)&outField->n1 + 8))(outField);
  }
LAB_4280dc92:
  SysFreeString(fieldName);
  SysFreeString((BSTR)0x0);
  if (self != (void *)0x0) {
    (**(code **)(*(int *)self + 8))(self);
  }
  VariantClear(&local_28);
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  SysFreeString(local_14);
  if (subImage != (wchar_t *)0x0) {
    (**(code **)(*(int *)subImage + 8))(subImage);
  }
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  VariantClear(&local_38);
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return 0;
}



// Source: CLCSRichTextBlockField.dll @ 41817419; FUN_41817419

int FUN_41817419(void *self,int fieldType,wchar_t *fontName,int fontPitch,VARIANTARG ciffFile,
                wchar_t *subImage,wchar_t *fieldName,VARIANTARG coderCapabilities,
                VARIANTARG *outField)

{
  VARIANTARG *pVVar1;
  wchar_t *pwVar2;
  undefined4 *puVar3;
  wchar_t **ppwVar4;
  VARIANTARG **ppVVar5;
  wchar_t **ppwVar6;
  VARIANTARG local_2c;
  wchar_t *local_1c;
  BSTR local_18;
  wchar_t *local_14;
  int *local_10;
  VARIANTARG *local_c;
  wchar_t *local_8;
  
  CComQIPtr<>(&local_c,(undefined4 *)ciffFile.n1._8_4_);
  CComQIPtr<>(&local_14,(undefined4 *)coderCapabilities.n1._8_4_);
  FUN_41824ee0((uint *)&local_2c,0,0x10);
  VariantInit(&local_2c);
  (**(code **)(*(int *)&local_c->n1 + 0x30))(local_c,subImage,&local_2c);
  CComQIPtr<>(&local_10,(undefined4 *)local_2c.n1._8_4_);
  pVVar1 = outField;
  (**(code **)(*local_10 + 0x28))(local_10,0,fieldName,1,outField);
  CComQIPtr<>(&local_8,*(undefined4 **)((int)&pVVar1->n1 + 8));
  local_1c = local_14;
  subImage = local_14;
  if (local_14 != (wchar_t *)0x0) {
    (**(code **)(*(int *)local_14 + 4))(local_14);
  }
  pVVar1 = local_c;
  outField = local_c;
  if (local_c != (VARIANTARG *)0x0) {
    (**(code **)(*(int *)&local_c->n1 + 4))(local_c);
  }
  pwVar2 = local_8;
  fieldName = local_8;
  if (local_8 != (wchar_t *)0x0) {
    (**(code **)(*(int *)local_8 + 4))(local_8);
  }
  ppwVar6 = &subImage;
  ppVVar5 = &outField;
  ppwVar4 = &fieldName;
  puVar3 = FUN_41801397(&local_18,fontName);
  FUN_418175bc(puVar3,fontPitch,ppwVar4,ppVVar5,(int *)ppwVar6);
  SysFreeString(local_18);
  if (pwVar2 != (wchar_t *)0x0) {
    (**(code **)(*(int *)pwVar2 + 8))(pwVar2);
  }
  if (pVVar1 != (VARIANTARG *)0x0) {
    (**(code **)(*(int *)&pVVar1->n1 + 8))(pVVar1);
  }
  if (local_1c != (wchar_t *)0x0) {
    (**(code **)(*(int *)local_1c + 8))(local_1c);
  }
  (**(code **)(*(int *)local_8 + 0xc4))(local_8,0);
  (**(code **)(*(int *)local_8 + 0x110))(local_8,0);
  (**(code **)(*(int *)local_8 + 0x28))(local_8,1);
  (**(code **)(*(int *)local_8 + 0x48))(local_8,0);
  (**(code **)(*(int *)local_8 + 0x50))(local_8,0);
  (**(code **)(*(int *)local_8 + 0x40))(local_8,0);
  (**(code **)(*(int *)local_8 + 0x58))(local_8,0);
  (**(code **)(*(int *)local_8 + 0x94))(local_8,0);
  (**(code **)(*(int *)local_8 + 0xcc))(local_8,0);
  if (local_8 != (wchar_t *)0x0) {
    (**(code **)(*(int *)local_8 + 8))(local_8);
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  VariantClear(&local_2c);
  if (local_14 != (wchar_t *)0x0) {
    (**(code **)(*(int *)local_14 + 8))(local_14);
  }
  if (local_c != (VARIANTARG *)0x0) {
    (**(code **)(*(int *)&local_c->n1 + 8))(local_c);
  }
  return 0;
}



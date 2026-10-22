// Source: CLCSGraphicBasedField.dll @ 41c0a8f0; FUN_41c0a8f0

int FUN_41c0a8f0(void *self,void *outSize,VARIANTARG field,VARIANTARG coderCapabilities,
                VARIANTARG ciffFile)

{
  int *piVar1;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  CComQIPtr<>(&local_14,(undefined4 *)field.n1._8_4_);
  (**(code **)(*local_14 + 0x78))(local_14,&local_c);
  (**(code **)(*local_14 + 0x80))(local_14,&local_10);
  CComQIPtr<>(&local_18,(undefined4 *)ciffFile.n1._8_4_);
  (**(code **)(*local_18 + 0x54))(local_18,&local_1c);
  if (local_1c == 0) {
    CComQIPtr<>(&local_8,(undefined4 *)coderCapabilities.n1._8_4_);
    FUN_41c11a03(&local_20);
    piVar1 = local_8;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
    local_c = FUN_41c11b58(local_c,1.4013e-45,piVar1);
    piVar1 = local_8;
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 4))(local_8);
    }
    local_10 = FUN_41c11b58(local_10,0.0,piVar1);
    FUN_41c11a0c(&local_20);
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
    }
  }
  *(int *)outSize = local_c;
  *(int *)((int)outSize + 4) = local_10;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
  return 0;
}



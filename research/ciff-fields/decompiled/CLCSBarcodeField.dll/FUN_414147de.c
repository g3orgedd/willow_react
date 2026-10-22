// Source: CLCSBarcodeField.dll @ 414147de; FUN_414147de

int FUN_414147de(void *self,void *outSize,VARIANTARG field,VARIANTARG coderCapabilities,
                VARIANTARG ciffFile)

{
  int *piVar1;
  int iVar2;
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  CComQIPtr<>(&local_10,(undefined4 *)ciffFile.n1._8_4_);
  CComQIPtr<>(&local_8,(undefined4 *)field.n1._8_4_);
  CComQIPtr<>(&local_c,(undefined4 *)coderCapabilities.n1._8_4_);
  (**(code **)(*local_8 + 0xa8))(local_8,&local_14);
  piVar1 = (int *)FUN_414158db((void *)((int)self + -4),local_14);
  if (piVar1 == (int *)0x0) {
    iVar2 = -0x7fffbffb;
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 0xc))(outSize,&local_10,&local_c,&local_8);
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  return iVar2;
}



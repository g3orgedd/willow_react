// Source: CLCSBarcodeField.dll @ 41415a0a; FUN_41415a0a

int FUN_41415a0a(void *self,wchar_t *fieldTypeName,void *outFieldType)

{
  bool bVar1;
  int iVar2;
  undefined *this;
  
  if (outFieldType == (void *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    iVar2 = 0;
    this = &DAT_414b0010;
    do {
      bVar1 = FUN_41403356(this,fieldTypeName);
      if (bVar1) {
        *(int *)outFieldType = iVar2;
        break;
      }
      this = this + 4;
      iVar2 = iVar2 + 1;
    } while ((int)this < 0x414b0014);
    if (iVar2 == 1) {
      *(undefined4 *)outFieldType = 0xffffffff;
    }
    iVar2 = 0;
  }
  return iVar2;
}



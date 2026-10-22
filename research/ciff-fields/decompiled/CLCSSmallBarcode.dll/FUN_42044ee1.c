// Source: CLCSSmallBarcode.dll @ 42044ee1; FUN_42044ee1

int FUN_42044ee1(void *self,wchar_t *fieldTypeName,void *outFieldType)

{
  bool bVar1;
  int iVar2;
  undefined *this;
  
  if (outFieldType == (void *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    *(undefined4 *)outFieldType = 0xffffffff;
    iVar2 = 0;
    this = &DAT_420c64cc;
    do {
      bVar1 = FUN_42003230(this,fieldTypeName);
      if (bVar1) {
        *(int *)outFieldType = iVar2;
        break;
      }
      this = this + 4;
      iVar2 = iVar2 + 1;
    } while ((int)this < 0x420c64d0);
    iVar2 = 0;
  }
  return iVar2;
}



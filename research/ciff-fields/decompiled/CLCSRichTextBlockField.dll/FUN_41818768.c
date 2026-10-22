// Source: CLCSRichTextBlockField.dll @ 41818768; FUN_41818768

int FUN_41818768(void *self,wchar_t *fieldTypeName,void *outFieldType)

{
  bool bVar1;
  int iVar2;
  undefined *this;
  
  iVar2 = 0;
  this = &DAT_41852098;
  do {
    bVar1 = FUN_418016de(this,fieldTypeName);
    if (bVar1) {
      *(int *)outFieldType = iVar2;
      break;
    }
    this = this + 4;
    iVar2 = iVar2 + 1;
  } while ((int)this < 0x4185209c);
  if (iVar2 == 1) {
    *(undefined4 *)outFieldType = 0xffffffff;
  }
  return 0;
}



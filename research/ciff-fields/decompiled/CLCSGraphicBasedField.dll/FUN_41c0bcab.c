// Source: CLCSGraphicBasedField.dll @ 41c0bcab; FUN_41c0bcab

int FUN_41c0bcab(void *self,wchar_t *fieldTypeName,void *outFieldType)

{
  bool bVar1;
  undefined *this;
  int iVar2;
  
  *(undefined4 *)outFieldType = 0xffffffff;
  iVar2 = 0;
  this = &DAT_41c43660;
  do {
    bVar1 = FUN_41c01781(this,fieldTypeName);
    if (bVar1) {
      *(int *)outFieldType = iVar2;
      return 0;
    }
    this = this + 4;
    iVar2 = iVar2 + 1;
  } while ((int)this < 0x41c43664);
  return -0x7fffbffb;
}



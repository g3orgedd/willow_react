// Source: CLCSBlockTextField.dll @ 4181254f; FUN_4181254f

int FUN_4181254f(void *self,wchar_t *fieldTypeName,void *outFieldType)

{
  bool bVar1;
  int iVar2;
  undefined *this;
  
  iVar2 = 0;
  this = &DAT_4184840c;
  do {
    bVar1 = FUN_418016e4(this,fieldTypeName);
    if (bVar1) {
      *(int *)outFieldType = iVar2;
      break;
    }
    this = this + 4;
    iVar2 = iVar2 + 1;
  } while ((int)this < 0x41848410);
  if (iVar2 == 1) {
    *(undefined4 *)outFieldType = 0xffffffff;
  }
  return 0;
}



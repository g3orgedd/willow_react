// Source: CLCSGraphicPrimitive.dll @ 4280eb39; FUN_4280eb39

int FUN_4280eb39(void *self,wchar_t *fieldTypeName,void *outFieldType)

{
  bool bVar1;
  int iVar2;
  undefined *this;
  
  iVar2 = 0;
  this = &DAT_42840aec;
  do {
    bVar1 = FUN_42802149(this,fieldTypeName);
    if (bVar1) {
      *(int *)outFieldType = iVar2;
      break;
    }
    this = this + 4;
    iVar2 = iVar2 + 1;
  } while ((int)this < 0x42840af0);
  if (iVar2 == 1) {
    *(undefined4 *)outFieldType = 0xffffffff;
  }
  return 0;
}



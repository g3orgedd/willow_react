// Source: CLCSTextBasedField.dll @ 4242591f; FUN_4242591f

int FUN_4242591f(void *self,wchar_t *fieldTypeName,void *outFieldType)

{
  bool bVar1;
  int iVar2;
  undefined *this;
  
  iVar2 = 0;
  this = &DAT_424bfb00;
  do {
    bVar1 = FUN_42403bfa(this,fieldTypeName);
    if (bVar1) {
      *(int *)outFieldType = iVar2;
      break;
    }
    this = this + 4;
    iVar2 = iVar2 + 1;
  } while ((int)this < 0x424bfb20);
  if (iVar2 == 8) {
    *(undefined4 *)outFieldType = 0xffffffff;
  }
  return 0;
}



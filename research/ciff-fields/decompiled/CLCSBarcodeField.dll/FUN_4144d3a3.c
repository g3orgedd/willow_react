// Source: CLCSBarcodeField.dll @ 4144d3a3; FUN_4144d3a3

int FUN_4144d3a3(ushort *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (*param_1 == 0) {
      return -1;
    }
    cVar1 = FUN_4144d378(*param_1);
    if (cVar1 != '\0') break;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
  }
  return iVar2;
}



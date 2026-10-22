// Source: CLCSBarcodeField.dll @ 4144d3d8; FUN_4144d3d8

int FUN_4144d3d8(ushort *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (*param_1 == 0) {
      return -1;
    }
    uVar1 = FUN_4144d38b((uint)*param_1);
    if ((char)uVar1 != '\0') break;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
  }
  return iVar2;
}



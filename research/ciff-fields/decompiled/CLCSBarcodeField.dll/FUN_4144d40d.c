// Source: CLCSBarcodeField.dll @ 4144d40d; FUN_4144d40d

int __cdecl FUN_4144d40d(WCHAR *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (*param_1 == L'\0') {
      return iVar2;
    }
    iVar1 = FUN_414604ef(*param_1);
    if (iVar1 == 0) break;
    param_1 = param_1 + 1;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



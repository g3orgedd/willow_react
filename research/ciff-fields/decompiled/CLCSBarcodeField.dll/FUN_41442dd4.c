// Source: CLCSBarcodeField.dll @ 41442dd4; FUN_41442dd4

int __fastcall FUN_41442dd4(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 8) == '\0') {
    iVar1 = (*(int *)(param_1 + 0xc) + 2) * 0x11;
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar1 = iVar1 + 0x23;
    }
    else {
      iVar1 = iVar1 + 1;
    }
    if (*(char *)(param_1 + 9) != '\0') {
      iVar1 = iVar1 + 4;
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) * 0x11;
    iVar1 = iVar2 + 0x15;
    if (2 < *(int *)(param_1 + 0xc)) {
      iVar1 = iVar2 + 0x1f;
    }
    if (*(char *)(param_1 + 9) != '\0') {
      iVar1 = iVar1 + 2;
    }
  }
  return iVar1;
}



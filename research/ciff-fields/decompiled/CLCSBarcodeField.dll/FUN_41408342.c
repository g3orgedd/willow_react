// Source: CLCSBarcodeField.dll @ 41408342; FUN_41408342

int __cdecl FUN_41408342(int *param_1)

{
  UINT UVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  UVar1 = SysStringLen((BSTR)*param_1);
  if (UVar1 != 0) {
    do {
      iVar3 = iVar3 + -0x30 + (uint)*(ushort *)(*param_1 + (UVar1 - 1) * 2);
      if (UVar1 - 1 == 0) break;
      UVar1 = UVar1 - 2;
      iVar2 = iVar2 + -0x30 + (uint)*(ushort *)(*param_1 + UVar1 * 2);
    } while (UVar1 != 0);
  }
  return (10 - (uint)(iVar3 * 3 + iVar2) % 10) % 10 + 0x30;
}



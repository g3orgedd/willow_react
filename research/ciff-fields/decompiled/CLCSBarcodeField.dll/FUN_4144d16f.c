// Source: CLCSBarcodeField.dll @ 4144d16f; FUN_4144d16f

undefined4 __cdecl FUN_4144d16f(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      in_EAX = FUN_414604ef(*(WCHAR *)(param_1 + iVar1 * 2));
      if (in_EAX == 0) {
        return 0;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return CONCAT31((int3)((uint)in_EAX >> 8),1);
}



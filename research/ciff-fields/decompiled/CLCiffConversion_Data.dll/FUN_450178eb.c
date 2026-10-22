// Source: CLCiffConversion_Data.dll @ 450178eb; FUN_450178eb

void FUN_450178eb(void)

{
  int iVar1;
  int iVar2;
  DWORD unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  HMODULE unaff_EDI;
  
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (*(int *)(unaff_EBP + -0x418) != 0) {
    iVar2 = MultiByteToWideChar(3,unaff_EBX,*(LPCSTR *)(unaff_EBP + -0x420),unaff_ESI,
                                *(LPWSTR *)(unaff_EBP + -0x418),unaff_ESI);
    if (iVar2 == 0) {
      FUN_450155e4();
    }
    else {
      iVar1 = *(int *)(unaff_EBP + 0x14);
      *(undefined2 *)(*(int *)(unaff_EBP + -0x418) + iVar2 * 2) = 0;
      FUN_450176ba((void *)(unaff_EBP + -0x42c),*(wchar_t **)(unaff_EBP + -0x418),iVar1);
    }
  }
  if (unaff_EDI != (HMODULE)0x0) {
    FreeLibrary(unaff_EDI);
  }
  if (*(int *)(unaff_EBP + -0x418) != unaff_EBP + -0x414) {
    FUN_45016630((undefined4 *)(unaff_EBP + -0x418));
  }
  FUN_45022ec7();
  return;
}



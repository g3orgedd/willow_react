// Source: CLCiffConversion_Data.dll @ 45014f6a; FUN_45014f6a

void FUN_45014f6a(void)

{
  void *this;
  LPWSTR lpsz;
  LPCWSTR lpsz_00;
  uint uVar1;
  WCHAR unaff_BX;
  uint unaff_EBP;
  WCHAR *pWVar2;
  int iVar3;
  undefined4 uStack0000000c;
  
  pWVar2 = *(WCHAR **)(unaff_EBP - 0x2118);
  if (pWVar2 == (WCHAR *)0x0) {
    uVar1 = 0xe;
    iVar3 = 0;
  }
  else {
    lpsz_00 = (LPCWSTR)(unaff_EBP - 0x2014);
    if (*(short *)(unaff_EBP - 0x2014) != 0) {
      do {
        lpsz = CharNextW(lpsz_00);
        if ((*lpsz_00 == L'\\') && (*lpsz == L'0')) {
          *pWVar2 = L'\0';
          lpsz_00 = CharNextW(lpsz);
        }
        else {
          *pWVar2 = *lpsz_00;
          lpsz_00 = lpsz_00 + 1;
        }
        pWVar2 = pWVar2 + 1;
      } while (*lpsz_00 != unaff_BX);
    }
    this = *(void **)(unaff_EBP - 0x2130);
    pWVar2[0] = L'\0';
    pWVar2[1] = L'\0';
    uVar1 = FUN_45018251(this,*(LPCWSTR *)(unaff_EBP - 0x212c),*(wchar_t **)(unaff_EBP - 0x2118));
    iVar3 = *(int *)(unaff_EBP - 0x2118);
  }
  if (iVar3 != unaff_EBP - 0x2114) {
    FUN_45016630((undefined4 *)(unaff_EBP - 0x2118));
  }
  if (uVar1 == 0) {
    FUN_4501703e(*(void **)(unaff_EBP - 0x2120),*(undefined2 **)(unaff_EBP - 0x2138));
  }
  else {
    FUN_450155fb(uVar1);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uStack0000000c = 0x450151cc;
  FUN_45022e32(*(uint *)(unaff_EBP - 0x14) ^ unaff_EBP);
  return;
}



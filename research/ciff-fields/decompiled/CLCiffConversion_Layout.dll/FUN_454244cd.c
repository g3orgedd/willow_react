// Source: CLCiffConversion_Layout.dll @ 454244cd; FUN_454244cd

/* WARNING: Unable to track spacebase fully for stack */

void FUN_454244cd(void)

{
  BYTE BVar1;
  void *this;
  LPSTR lpsz;
  BYTE *lpsz_00;
  BOOL BVar2;
  uint uVar3;
  BYTE unaff_BL;
  uint unaff_EBP;
  BYTE *pBVar4;
  int iVar5;
  
  pBVar4 = *(BYTE **)(unaff_EBP - 0x1118);
  if (pBVar4 == (BYTE *)0x0) {
    uVar3 = 0xe;
    iVar5 = 0;
  }
  else {
    lpsz_00 = (BYTE *)(unaff_EBP - 0x1014);
    BVar1 = *(BYTE *)(unaff_EBP - 0x1014);
    while (BVar1 != '\0') {
      lpsz = CharNextA((LPCSTR)lpsz_00);
      if ((*lpsz_00 == '\\') && (*lpsz == '0')) {
        *pBVar4 = unaff_BL;
        lpsz_00 = (BYTE *)CharNextA(lpsz);
      }
      else {
        *pBVar4 = *lpsz_00;
        BVar2 = IsDBCSLeadByte(*lpsz_00);
        if (BVar2 != 0) {
          pBVar4 = pBVar4 + 1;
          lpsz_00 = lpsz_00 + 1;
          if (*lpsz_00 == '\0') break;
          *pBVar4 = *lpsz_00;
        }
        lpsz_00 = lpsz_00 + 1;
      }
      pBVar4 = pBVar4 + 1;
      BVar1 = *lpsz_00;
    }
    this = *(void **)(unaff_EBP - 0x1128);
    pBVar4[0] = '\0';
    pBVar4[1] = '\0';
    uVar3 = FUN_45427b1b(this,*(LPCSTR *)(unaff_EBP - 0x1124),*(BYTE **)(unaff_EBP - 0x1118));
    iVar5 = *(int *)(unaff_EBP - 0x1118);
  }
  if (iVar5 != unaff_EBP - 0x1114) {
    FUN_454037d2((undefined4 *)(unaff_EBP - 0x1118));
  }
  if (uVar3 == 0) {
    FUN_45426781(*(void **)(unaff_EBP - 0x112c),*(undefined1 **)(unaff_EBP - 0x1138));
  }
  else {
    FUN_45424c03(uVar3);
  }
  ExceptionList = *(void **)(unaff_EBP - 0xc);
  uVar3 = *(uint *)(unaff_EBP - 0x14);
  *(undefined4 *)(unaff_EBP - 0x113c) = 0x4542480b;
  FUN_4542a8d1(uVar3 ^ unaff_EBP);
  return;
}



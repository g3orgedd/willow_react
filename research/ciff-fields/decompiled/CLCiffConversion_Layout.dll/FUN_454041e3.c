// Source: CLCiffConversion_Layout.dll @ 454041e3; FUN_454041e3

void FUN_454041e3(void)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  BSTR pOVar4;
  int unaff_EBX;
  int unaff_EBP;
  DWORD unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (*(int *)(unaff_EBP + -0x11c) == 0) {
    iVar1 = unaff_EBP + -0x118;
LAB_454041f4:
    if (iVar1 != 0) {
      FUN_454037d2((undefined4 *)(unaff_EBP + -0x11c));
    }
    if (*(int *)(unaff_EBP + -0x98) != unaff_EBP + -0x94) {
      FUN_454037d2((undefined4 *)(unaff_EBP + -0x98));
    }
  }
  else {
    uVar2 = MultiByteToWideChar(3,unaff_ESI,*(LPCSTR *)(unaff_EBP + -0x98),unaff_EBX,
                                *(LPWSTR *)(unaff_EBP + -0x11c),*(int *)(unaff_EBP + -0x128));
    if ((int)uVar2 < 1) {
      FUN_45402fed();
    }
    else {
      *(DWORD *)(unaff_EBP + -0x120) = unaff_ESI;
      lVar3 = ATL::AtlMultiply<unsigned_long>((ulong *)(unaff_EBP + -0x120),uVar2,2);
      if (-1 < lVar3) {
        pOVar4 = SysAllocStringByteLen
                           (*(LPCSTR *)(unaff_EBP + -0x11c),*(UINT *)(unaff_EBP + -0x120));
        if (pOVar4 != (BSTR)0x0) {
          SysFreeString((BSTR)*unaff_EDI);
          *unaff_EDI = pOVar4;
          if (*(int *)(unaff_EBP + -0x11c) != unaff_EBP + -0x118) {
            FUN_454037d2((undefined4 *)(unaff_EBP + -0x11c));
          }
          if (*(int *)(unaff_EBP + -0x98) != unaff_EBP + -0x94) {
            FUN_454037d2((undefined4 *)(unaff_EBP + -0x98));
          }
          goto LAB_454042e0;
        }
        iVar1 = *(int *)(unaff_EBP + -0x11c) - (unaff_EBP + -0x118);
        goto LAB_454041f4;
      }
    }
    if (*(int *)(unaff_EBP + -0x11c) != unaff_EBP + -0x118) {
      FUN_454037d2((undefined4 *)(unaff_EBP + -0x11c));
    }
    if (*(int *)(unaff_EBP + -0x98) != unaff_EBP + -0x94) {
      FUN_454037d2((undefined4 *)(unaff_EBP + -0x98));
    }
  }
LAB_454042e0:
  FUN_4542a966();
  return;
}



// Source: CLCiffConversion_Layout.dll @ 4540410f; FUN_4540410f

void FUN_4540410f(void)

{
  int cchWideChar;
  DWORD cchLength;
  uint uVar1;
  code *unaff_EBX;
  int unaff_EBP;
  DWORD unaff_ESI;
  undefined4 *unaff_EDI;
  
  *(DWORD *)(unaff_EBP + -4) = unaff_ESI;
  *(int *)(unaff_EBP + -0x124) = *(int *)(unaff_EBP + -0x98);
  if (*(int *)(unaff_EBP + -0x98) == 0) {
    if (unaff_EBP != 0x94) {
      FUN_454037d2((undefined4 *)(unaff_EBP + -0x98));
    }
  }
  else {
    cchWideChar = (*unaff_EBX)(*unaff_EDI);
    cchLength = WideCharToMultiByte(3,unaff_ESI,(LPCWSTR)*unaff_EDI,cchWideChar,
                                    *(LPSTR *)(unaff_EBP + -0x124),*(int *)(unaff_EBP + -0x128),
                                    (LPCSTR)unaff_ESI,(LPBOOL)unaff_ESI);
    *(DWORD *)(unaff_EBP + -0x124) = cchLength;
    if (cchLength != 0) {
      CharUpperBuffA(*(LPSTR *)(unaff_EBP + -0x98),cchLength);
      uVar1 = MultiByteToWideChar(3,unaff_ESI,*(LPCSTR *)(unaff_EBP + -0x98),cchLength,
                                  (LPWSTR)unaff_ESI,unaff_ESI);
      *(uint *)(unaff_EBP + -0x128) = uVar1;
      *(DWORD *)(unaff_EBP + -0x11c) = unaff_ESI;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      ATL::CTempBuffer<wchar_t,128,ATL::CCRTAllocator>::Allocate
                ((CTempBuffer<wchar_t,128,ATL::CCRTAllocator> *)(unaff_EBP + -0x11c),uVar1);
      FUN_454041e3();
      return;
    }
    FUN_45402fed();
    if (*(int *)(unaff_EBP + -0x98) != unaff_EBP + -0x94) {
      FUN_454037d2((undefined4 *)(unaff_EBP + -0x98));
    }
  }
  FUN_4542a966();
  return;
}



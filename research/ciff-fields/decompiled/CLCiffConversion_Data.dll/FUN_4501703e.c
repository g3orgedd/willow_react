// Source: CLCiffConversion_Data.dll @ 4501703e; FUN_4501703e

undefined4 __thiscall FUN_4501703e(void *this,undefined2 *param_1)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  undefined4 uVar3;
  LPWSTR pWVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_4501834e(this);
  WVar1 = **(LPCWSTR *)this;
  if (WVar1 == L'\0') {
    uVar3 = 0x80020009;
  }
  else {
    puVar7 = param_1;
    if (WVar1 == L'\'') {
      pWVar4 = CharNextW(*(LPCWSTR *)this);
      *(LPWSTR *)this = pWVar4;
      while ((*pWVar4 != L'\0' && (iVar5 = FUN_4501638e(this), iVar5 == 0))) {
        if (**(LPCWSTR *)this == L'\'') {
          pWVar4 = CharNextW(*(LPCWSTR *)this);
          *(LPWSTR *)this = pWVar4;
        }
        pWVar2 = *(LPCWSTR *)this;
        pWVar4 = CharNextW(pWVar2);
        *(LPWSTR *)this = pWVar4;
        iVar5 = (int)pWVar4 - (int)pWVar2 >> 1;
        if (param_1 + 0x1000 <= puVar7 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar6 = (int)pWVar2 - (int)puVar7;
          do {
            *puVar7 = *(undefined2 *)(iVar6 + (int)puVar7);
            puVar7 = puVar7 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        pWVar4 = *(LPWSTR *)this;
      }
      if (**(short **)this == 0) {
        return 0x80020009;
      }
      *puVar7 = 0;
      pWVar4 = CharNextW(*(LPCWSTR *)this);
      *(LPWSTR *)this = pWVar4;
    }
    else {
      do {
        pWVar2 = *(LPCWSTR *)this;
        iVar5 = FUN_45016d8d(*pWVar2);
        if (iVar5 != 0) break;
        pWVar4 = CharNextW(pWVar2);
        *(LPWSTR *)this = pWVar4;
        iVar5 = (int)pWVar4 - (int)pWVar2 >> 1;
        if (param_1 + 0x1000 <= puVar7 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar6 = (int)pWVar2 - (int)puVar7;
          do {
            *puVar7 = *(undefined2 *)(iVar6 + (int)puVar7);
            puVar7 = puVar7 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      } while (**(short **)this != 0);
      *puVar7 = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



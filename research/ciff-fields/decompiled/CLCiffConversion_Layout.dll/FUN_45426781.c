// Source: CLCiffConversion_Layout.dll @ 45426781; FUN_45426781

undefined4 __thiscall FUN_45426781(void *this,undefined1 *param_1)

{
  char cVar1;
  LPCSTR pCVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  LPSTR pCVar6;
  int iVar7;
  undefined1 *puVar8;
  
  FUN_45427bf6(this);
  cVar1 = **(LPCSTR *)this;
  if (cVar1 == '\0') {
    uVar3 = 0x80020009;
  }
  else {
    puVar8 = param_1;
    if (cVar1 == '\'') {
      pcVar4 = CharNextA(*(LPCSTR *)this);
      *(char **)this = pcVar4;
      while ((*pcVar4 != '\0' && (iVar5 = FUN_45425a3e(this), iVar5 == 0))) {
        if (**(LPCSTR *)this == '\'') {
          pCVar6 = CharNextA(*(LPCSTR *)this);
          *(LPSTR *)this = pCVar6;
        }
        pCVar2 = *(LPCSTR *)this;
        pCVar6 = CharNextA(pCVar2);
        *(LPSTR *)this = pCVar6;
        iVar5 = (int)pCVar6 - (int)pCVar2;
        if (param_1 + 0x1000 <= puVar8 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar7 = (int)pCVar2 - (int)puVar8;
          do {
            *puVar8 = puVar8[iVar7];
            puVar8 = puVar8 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        pcVar4 = *(char **)this;
      }
      if (**(char **)this == '\0') {
        return 0x80020009;
      }
      *puVar8 = 0;
      pCVar6 = CharNextA(*(LPCSTR *)this);
      *(LPSTR *)this = pCVar6;
    }
    else {
      do {
        pCVar2 = *(LPCSTR *)this;
        iVar5 = FUN_454264d7(*pCVar2);
        if (iVar5 != 0) break;
        pCVar6 = CharNextA(pCVar2);
        *(LPSTR *)this = pCVar6;
        iVar5 = (int)pCVar6 - (int)pCVar2;
        if (param_1 + 0x1000 <= puVar8 + iVar5 + 1) {
          return 0x80020009;
        }
        if (0 < iVar5) {
          iVar7 = (int)pCVar2 - (int)puVar8;
          do {
            *puVar8 = puVar8[iVar7];
            puVar8 = puVar8 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      } while (**(char **)this != '\0');
      *puVar8 = 0;
    }
    uVar3 = 0;
  }
  return uVar3;
}



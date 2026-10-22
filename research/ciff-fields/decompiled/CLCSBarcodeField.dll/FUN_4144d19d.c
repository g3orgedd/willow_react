// Source: CLCSBarcodeField.dll @ 4144d19d; FUN_4144d19d

uint FUN_4144d19d(BSTR param_1)

{
  WCHAR WVar1;
  char cVar2;
  UINT UVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  WCHAR *pWVar9;
  WCHAR *pWVar10;
  bool bVar11;
  int iVar12;
  int local_8;
  
  uVar8 = (uint)(*param_1 == L'æ');
  UVar3 = SysStringLen(param_1);
  if ((UVar3 < uVar8 + 4) || (uVar4 = FUN_4144d16f((int)(param_1 + uVar8),4), (char)uVar4 == '\0'))
  {
    iVar12 = FUN_4144d3a3((ushort *)(param_1 + uVar8));
    if ((iVar12 == -1) || (iVar5 = FUN_4144d3d8((ushort *)(param_1 + uVar8)), iVar5 <= iVar12)) {
      iVar12 = 2;
    }
    else {
      iVar12 = 1;
    }
  }
  else {
    iVar12 = 3;
  }
  pWVar10 = param_1 + uVar8;
  WVar1 = *pWVar10;
  if (WVar1 != L'\0') {
    pWVar9 = pWVar10 + 1;
    uVar7 = uVar8;
    local_8 = iVar12;
    do {
      if (iVar12 == 1) {
        uVar4 = FUN_4144d38b((uint)(ushort)WVar1);
        if ((char)uVar4 != '\0') {
          iVar12 = FUN_4144d3d8((ushort *)pWVar9);
          if (iVar12 != -1) {
            iVar5 = FUN_4144d3a3((ushort *)pWVar9);
            if (iVar12 < iVar5) {
              local_8 = 2;
            }
          }
          goto LAB_4144d30f;
        }
LAB_4144d318:
        uVar4 = FUN_4144d16f((int)pWVar10,4);
        if ((char)uVar4 == '\0') {
LAB_4144d34c:
          pWVar10 = pWVar10 + 1;
          pWVar9 = pWVar9 + 1;
          goto LAB_4144d353;
        }
        uVar8 = uVar7 + 1;
        uVar6 = FUN_4144d40d(pWVar10);
        uVar6 = uVar6 & 0x80000001;
        bVar11 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar11 = (uVar6 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar11) {
          pWVar10 = pWVar10 + 1;
          pWVar9 = pWVar9 + 1;
          uVar8 = uVar7 + 2;
        }
        iVar12 = 3;
        local_8 = 3;
      }
      else if (iVar12 == 2) {
        cVar2 = FUN_4144d378(WVar1);
        if (cVar2 == '\0') goto LAB_4144d318;
        iVar12 = FUN_4144d3a3((ushort *)pWVar9);
        if (iVar12 != -1) {
          iVar5 = FUN_4144d3d8((ushort *)pWVar9);
          if (iVar12 < iVar5) {
            local_8 = 1;
          }
        }
LAB_4144d30f:
        pWVar10 = pWVar10 + 1;
        pWVar9 = pWVar9 + 1;
        uVar8 = uVar7 + 2;
        iVar12 = local_8;
      }
      else {
        uVar8 = uVar7;
        if (iVar12 == 3) {
          uVar4 = FUN_4144d16f((int)pWVar10,2);
          if ((char)uVar4 == '\0') {
            if (*pWVar10 != L'æ') {
              iVar12 = FUN_4144d3a3((ushort *)pWVar10);
              iVar5 = FUN_4144d3d8((ushort *)pWVar10);
              if (((iVar12 == -1) || (iVar5 != -1)) || (iVar12 < 0)) {
                local_8 = 2;
              }
              else {
                local_8 = 1;
              }
              goto LAB_4144d30f;
            }
            goto LAB_4144d34c;
          }
          pWVar10 = pWVar10 + 2;
          pWVar9 = pWVar9 + 2;
LAB_4144d353:
          uVar8 = uVar7 + 1;
          iVar12 = local_8;
        }
      }
      WVar1 = *pWVar10;
      uVar7 = uVar8;
    } while (WVar1 != L'\0');
  }
  SysFreeString(param_1);
  return uVar8;
}



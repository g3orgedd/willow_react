// Source: CLCiffConversion_Data.dll @ 45023e76; FUN_45023e76

uint __cdecl FUN_45023e76(WCHAR *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  WCHAR WVar1;
  WCHAR *pWVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  WCHAR *pWVar9;
  ushort uVar10;
  uint local_8;
  
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = param_1;
  }
  if ((param_1 == (WCHAR *)0x0) || ((param_3 != 0 && (((int)param_3 < 2 || (0x24 < (int)param_3)))))
     ) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    FUN_45027e29();
    return 0;
  }
  WVar1 = *param_1;
  uVar8 = 0;
  pWVar2 = param_1;
  while( true ) {
    pWVar9 = pWVar2 + 1;
    uVar4 = FUN_45027796(WVar1,8);
    if (uVar4 == 0) break;
    WVar1 = *pWVar9;
    pWVar2 = pWVar9;
  }
  if (WVar1 == L'-') {
    param_4 = param_4 | 2;
LAB_45023ee9:
    WVar1 = *pWVar9;
    pWVar9 = pWVar2 + 2;
  }
  else if (WVar1 == L'+') goto LAB_45023ee9;
  uVar4 = (uint)(ushort)WVar1;
  if (param_3 == 0) {
    iVar5 = FID_conflict_wide_character_to_digit(WVar1);
    if (iVar5 != 0) {
      param_3 = 10;
      goto LAB_45023f59;
    }
    if ((*pWVar9 != L'x') && (*pWVar9 != L'X')) {
      param_3 = 8;
      goto LAB_45023f59;
    }
    param_3 = 0x10;
  }
  if (((param_3 == 0x10) && (iVar5 = FID_conflict_wide_character_to_digit(WVar1), iVar5 == 0)) &&
     ((*pWVar9 == L'x' || (*pWVar9 == L'X')))) {
    uVar4 = (uint)(ushort)pWVar9[1];
    pWVar9 = pWVar9 + 2;
  }
LAB_45023f59:
  uVar6 = (uint)(0xffffffff / (ulonglong)param_3);
  local_8 = param_4;
  do {
    uVar10 = (ushort)uVar4;
    uVar7 = FID_conflict_wide_character_to_digit(uVar10);
    if (uVar7 == 0xffffffff) {
      if (((uVar10 < 0x41) || (0x5a < uVar10)) && (0x19 < (ushort)(uVar10 - 0x61))) {
LAB_45023f94:
        pWVar9 = pWVar9 + -1;
        if ((local_8 & 8) == 0) {
          if (param_2 != (undefined4 *)0x0) {
            pWVar9 = param_1;
          }
          uVar8 = 0;
        }
        else if (((local_8 & 4) != 0) ||
                (((local_8 & 1) == 0 &&
                 ((((local_8 & 2) != 0 && (0x80000000 < uVar8)) ||
                  (((local_8 & 2) == 0 && (0x7fffffff < uVar8)))))))) {
          piVar3 = __errno();
          *piVar3 = 0x22;
          if ((local_8 & 1) == 0) {
            uVar8 = ((local_8 & 2) != 0) + 0x7fffffff;
          }
          else {
            uVar8 = 0xffffffff;
          }
        }
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = pWVar9;
        }
        if ((local_8 & 2) != 0) {
          uVar8 = -uVar8;
        }
        return uVar8;
      }
      if ((ushort)(uVar10 - 0x61) < 0x1a) {
        uVar4 = uVar4 - 0x20;
      }
      uVar7 = uVar4 - 0x37;
    }
    if (param_3 <= uVar7) goto LAB_45023f94;
    if ((uVar8 < uVar6) || ((uVar8 == uVar6 && (uVar7 <= (uint)(0xffffffff % (ulonglong)param_3)))))
    {
      uVar8 = uVar8 * param_3 + uVar7;
      local_8 = local_8 | 8;
    }
    else {
      local_8 = local_8 | 0xc;
      if (param_2 == (undefined4 *)0x0) goto LAB_45023f94;
    }
    uVar4 = (uint)(ushort)*pWVar9;
    pWVar9 = pWVar9 + 1;
  } while( true );
}



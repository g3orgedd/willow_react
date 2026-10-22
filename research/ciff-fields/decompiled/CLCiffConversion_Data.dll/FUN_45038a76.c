// Source: CLCiffConversion_Data.dll @ 45038a76; FUN_45038a76

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __cdecl
FUN_45038a76(int *param_1,wchar_t *param_2,DWORD param_3,byte *param_4,int param_5,byte *param_6,
            int param_7,UINT param_8)

{
  uint _Size;
  BOOL BVar1;
  BYTE *pBVar2;
  uint cchWideChar;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  PCNZWCH lpWideCharStr;
  LPWSTR lpWideCharStr_00;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  if (param_5 < 1) {
    if (param_5 < -1) goto LAB_45038ce6;
  }
  else {
    param_5 = ___strncnt((char *)param_4,param_5);
  }
  if (param_7 < 1) {
    if (param_7 < -1) goto LAB_45038ce6;
  }
  else {
    param_7 = ___strncnt((char *)param_6,param_7);
  }
  lpWideCharStr = (PCNZWCH)0x0;
  if (param_8 == 0) {
    param_8 = *(UINT *)(*param_1 + 4);
  }
  if ((param_5 == 0) || (param_7 == 0)) {
    if ((param_5 == param_7) ||
       (((1 < param_7 || (1 < param_5)) || (BVar1 = GetCPInfo(param_8,&local_1c), BVar1 == 0))))
    goto LAB_45038ce6;
    if (0 < param_5) {
      if (1 < local_1c.MaxCharSize) {
        pBVar2 = local_1c.LeadByte;
        while (((local_1c.LeadByte[0] != 0 && (pBVar2[1] != 0)) &&
               ((*param_4 < *pBVar2 || (pBVar2[1] < *param_4))))) {
          pBVar2 = pBVar2 + 2;
          local_1c.LeadByte[0] = *pBVar2;
        }
      }
      goto LAB_45038ce6;
    }
    if (0 < param_7) {
      if (1 < local_1c.MaxCharSize) {
        pBVar2 = local_1c.LeadByte;
        while (((local_1c.LeadByte[0] != 0 && (pBVar2[1] != 0)) &&
               ((*param_6 < *pBVar2 || (pBVar2[1] < *param_6))))) {
          pBVar2 = pBVar2 + 2;
          local_1c.LeadByte[0] = *pBVar2;
        }
      }
      goto LAB_45038ce6;
    }
  }
  cchWideChar = MultiByteToWideChar(param_8,9,(LPCSTR)param_4,param_5,(LPWSTR)0x0,0);
  if (cchWideChar == 0) goto LAB_45038ce6;
  if (((0 < (int)cchWideChar) && (1 < 0xffffffe0 / cchWideChar)) &&
     (cchWideChar * 2 < cchWideChar * 2 + 8)) {
    uVar4 = cchWideChar * 2 + 8;
    if (uVar4 < 0x401) {
      puVar5 = (undefined4 *)&stack0xffffffc4;
      lpWideCharStr = (PCNZWCH)&stack0xffffffc4;
      if (&stack0x00000000 != (undefined1 *)0x3c) {
LAB_45038c00:
        lpWideCharStr = (PCNZWCH)(puVar5 + 2);
      }
    }
    else {
      puVar5 = _malloc(uVar4);
      lpWideCharStr = (PCNZWCH)0x0;
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = 0xdddd;
        goto LAB_45038c00;
      }
    }
  }
  if (lpWideCharStr == (PCNZWCH)0x0) goto LAB_45038ce6;
  iVar3 = MultiByteToWideChar(param_8,1,(LPCSTR)param_4,param_5,lpWideCharStr,cchWideChar);
  if ((iVar3 != 0) &&
     (uVar4 = MultiByteToWideChar(param_8,9,(LPCSTR)param_6,param_7,(LPWSTR)0x0,0), uVar4 != 0)) {
    if (((int)uVar4 < 1) || ((0xffffffe0 / uVar4 < 2 || (uVar4 * 2 + 8 <= uVar4 * 2)))) {
      lpWideCharStr_00 = (LPWSTR)0x0;
    }
    else {
      _Size = uVar4 * 2 + 8;
      if (_Size < 0x401) {
        puVar5 = (undefined4 *)&stack0xffffffc4;
        lpWideCharStr_00 = (LPWSTR)&stack0xffffffc4;
        if (&stack0x00000000 != (undefined1 *)0x3c) {
LAB_45038c94:
          lpWideCharStr_00 = (LPWSTR)(puVar5 + 2);
        }
      }
      else {
        puVar5 = _malloc(_Size);
        lpWideCharStr_00 = (LPWSTR)0x0;
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = 0xdddd;
          goto LAB_45038c94;
        }
      }
    }
    if (lpWideCharStr_00 != (LPWSTR)0x0) {
      iVar3 = MultiByteToWideChar(param_8,1,(LPCSTR)param_6,param_7,lpWideCharStr_00,uVar4);
      if (iVar3 != 0) {
        FUN_450325bf(param_2,param_3,lpWideCharStr,cchWideChar,lpWideCharStr_00,uVar4);
      }
      FUN_45023e0f((int)lpWideCharStr_00);
    }
  }
  FUN_45023e0f((int)lpWideCharStr);
LAB_45038ce6:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



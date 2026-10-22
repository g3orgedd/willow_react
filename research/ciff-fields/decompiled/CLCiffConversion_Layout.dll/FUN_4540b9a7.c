// Source: CLCiffConversion_Layout.dll @ 4540b9a7; FUN_4540b9a7

undefined4 __cdecl FUN_4540b9a7(LCID param_1)

{
  longlong lVar1;
  LPWSTR lpLCData;
  int iVar2;
  LPCWSTR lpSrcStr;
  BOOL BVar3;
  undefined4 uVar4;
  int iVar5;
  int local_8;
  
  iVar5 = 0;
  uVar4 = 0x80004005;
  local_8 = GetLocaleInfoW(param_1,0x2a,(LPWSTR)0x0,0);
  if (0 < local_8) {
    lVar1 = (ulonglong)(local_8 + 1) * 2;
    lpLCData = (LPWSTR)FUN_454294e2(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    iVar2 = GetLocaleInfoW(param_1,0x2a,lpLCData,local_8);
    if ((iVar2 == local_8) && (uVar4 = 0, lpSrcStr = lpLCData, 0 < iVar2)) {
      do {
        BVar3 = GetStringTypeW(2,lpSrcStr,1,(LPWORD)&local_8);
        if (BVar3 == 0) {
          uVar4 = 0x80004005;
          break;
        }
        if ((WORD)local_8 == 2) {
          uVar4 = 1;
          break;
        }
        iVar5 = iVar5 + 1;
        lpSrcStr = lpSrcStr + 1;
      } while (iVar5 < iVar2);
    }
    FID_conflict__free(lpLCData);
  }
  return uVar4;
}



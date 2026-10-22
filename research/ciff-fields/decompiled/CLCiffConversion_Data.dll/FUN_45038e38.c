// Source: CLCiffConversion_Data.dll @ 45038e38; FUN_45038e38

undefined4 __cdecl FUN_45038e38(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_450364a4(param_1);
  if (iVar1 != -1) {
    if (((param_1 == 1) && ((*(byte *)(DAT_45055ae0 + 0x84) & 1) != 0)) ||
       ((param_1 == 2 && ((*(byte *)(DAT_45055ae0 + 0x44) & 1) != 0)))) {
      iVar1 = FUN_450364a4(2);
      iVar2 = FUN_450364a4(1);
      if (iVar2 == iVar1) goto LAB_45038e9c;
    }
    hObject = (HANDLE)FUN_450364a4(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_45038e9e;
    }
  }
LAB_45038e9c:
  DVar4 = 0;
LAB_45038e9e:
  FUN_4503641e(param_1);
  *(undefined1 *)((&DAT_45055ae0)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x40) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FID_conflict___dosmaperr(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}



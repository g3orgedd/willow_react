// Source: CLCiffConversion_Layout.dll @ 4543cd54; FUN_4543cd54

undefined8 __cdecl
FUN_4543cd54(uint param_1,undefined4 param_2,undefined4 param_3,PLARGE_INTEGER param_4)

{
  byte *pbVar1;
  LARGE_INTEGER liDistanceToMove;
  HANDLE hFile;
  int *piVar2;
  BOOL BVar3;
  DWORD DVar4;
  DWORD unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  hFile = (HANDLE)FUN_4543ff68(param_1);
  if (hFile == (HANDLE)0xffffffff) {
    piVar2 = __errno();
    *piVar2 = 9;
  }
  else {
    liDistanceToMove.s.HighPart = (LONG)&local_c;
    liDistanceToMove.s.LowPart = param_3;
    BVar3 = SetFilePointerEx(hFile,liDistanceToMove,param_4,unaff_EDI);
    if (BVar3 != 0) {
      pbVar1 = (byte *)((&DAT_454612f8)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x40);
      *pbVar1 = *pbVar1 & 0xfd;
      goto LAB_4543cdc1;
    }
    DVar4 = GetLastError();
    FID_conflict___dosmaperr(DVar4);
  }
  local_c = 0xffffffff;
  local_8 = 0xffffffff;
LAB_4543cdc1:
  return CONCAT44(local_8,local_c);
}



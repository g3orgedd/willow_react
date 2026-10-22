// Source: CLCiffConversion_Layout.dll @ 4543321d; FUN_4543321d

uint __cdecl FUN_4543321d(uint param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int local_18 [2];
  int local_10;
  char local_c;
  WCHAR local_8 [2];
  
  if ((WCHAR)param_1 == -1) {
    return 0xffff;
  }
  FUN_4542c8eb(local_18,param_2);
  if (*(LPCWSTR *)(local_18[0] + 0xa8) == (LPCWSTR)0x0) {
    if ((ushort)((WCHAR)param_1 + L'﾿') < 0x1a) {
      param_1 = (uint)(ushort)((WCHAR)param_1 + L' ');
    }
    param_1 = param_1 & 0xffff;
LAB_4543327e:
    param_1 = param_1 & 0xffff;
  }
  else if ((ushort)(WCHAR)param_1 < 0x100) {
    uVar2 = FUN_45434159((WCHAR)param_1,1);
    if (uVar2 == 0) goto LAB_4543327e;
    param_1 = (uint)*(byte *)(*(int *)(local_18[0] + 0x94) + (param_1 & 0xffff));
  }
  else {
    iVar1 = ___crtLCMapStringW(*(LPCWSTR *)(local_18[0] + 0xa8),0x100,(LPCWSTR)&param_1,1,local_8,1)
    ;
    if (iVar1 != 0) {
      uVar2 = (uint)(ushort)local_8[0];
      goto LAB_454332bc;
    }
  }
  uVar2 = param_1 & 0xffff;
LAB_454332bc:
  if (local_c != '\0') {
    *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
  }
  return uVar2;
}



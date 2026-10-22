// Source: CiffHelper.dll @ 4082dca5; FUN_4082dca5

uint __cdecl FUN_4082dca5(uint param_1,int *param_2)

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
  FUN_4082d077(local_18,param_2);
  if (*(LPCWSTR *)(local_18[0] + 0xa8) == (LPCWSTR)0x0) {
    if ((ushort)((WCHAR)param_1 + L'ﾟ') < 0x1a) {
      param_1 = (uint)(ushort)((WCHAR)param_1 + L'￠');
    }
    param_1 = param_1 & 0xffff;
LAB_4082dd06:
    param_1 = param_1 & 0xffff;
  }
  else if ((ushort)(WCHAR)param_1 < 0x100) {
    uVar2 = FUN_40836510((WCHAR)param_1,2);
    if (uVar2 == 0) goto LAB_4082dd06;
    param_1 = (uint)*(byte *)(*(int *)(local_18[0] + 0x98) + (param_1 & 0xffff));
  }
  else {
    iVar1 = ___crtLCMapStringW(*(LPCWSTR *)(local_18[0] + 0xa8),0x200,(LPCWSTR)&param_1,1,local_8,1)
    ;
    if (iVar1 != 0) {
      uVar2 = (uint)(ushort)local_8[0];
      goto LAB_4082dd4a;
    }
  }
  uVar2 = param_1 & 0xffff;
LAB_4082dd4a:
  if (local_c != '\0') {
    *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
  }
  return uVar2;
}



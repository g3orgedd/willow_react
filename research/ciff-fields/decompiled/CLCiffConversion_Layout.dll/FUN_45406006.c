// Source: CLCiffConversion_Layout.dll @ 45406006; FUN_45406006

void __cdecl FUN_45406006(int *param_1,int *param_2)

{
  BSTR pOVar1;
  ulong uVar2;
  uint uVar3;
  HANDLE hFindFile;
  int iVar4;
  _WIN32_FIND_DATAW local_264;
  wchar_t local_14 [6];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  SysFreeString((BSTR)*param_1);
  *param_1 = 0;
  pOVar1 = SysAllocStringLen((OLECHAR *)0x0,0xc);
  if ((BSTR)*param_1 != pOVar1) {
    SysFreeString((BSTR)*param_1);
    *param_1 = (int)pOVar1;
  }
  uVar2 = FUN_4542d4aa((longlong *)0x0);
  FUN_4542d00b(uVar2);
  iVar4 = 0;
  do {
    uVar3 = FUN_4542cfea();
    *(short *)(iVar4 + *param_1) = (short)((int)uVar3 % 0x1a) + 0x61;
    iVar4 = iVar4 + 2;
  } while (iVar4 < 8);
  _wcscpy_s((wchar_t *)(*param_1 + 0x10),5,L".bmp");
  do {
    _swprintf_s(local_14,5,L"%04d",*param_2);
    FUN_45429920((undefined8 *)(*param_1 + 8),(undefined8 *)local_14,8);
    hFindFile = FindFirstFileW((LPCWSTR)*param_1,&local_264);
    FindClose(hFindFile);
    if (*param_2 < 9999) {
      *param_2 = *param_2 + 1;
    }
    else {
      *param_2 = 0;
    }
  } while (hFindFile != (HANDLE)0xffffffff);
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



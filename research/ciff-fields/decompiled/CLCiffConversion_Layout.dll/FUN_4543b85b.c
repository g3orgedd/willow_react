// Source: CLCiffConversion_Layout.dll @ 4543b85b; FUN_4543b85b

void __cdecl FUN_4543b85b(LPCWSTR param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  code *pcVar2;
  undefined3 extraout_var;
  HMODULE hModule;
  DWORD DVar3;
  FARPROC pFVar4;
  BOOL BVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  undefined1 local_28 [4];
  undefined4 local_24;
  LPCWSTR local_20;
  code *local_1c;
  code *local_18;
  undefined1 local_14 [8];
  byte local_c;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_20 = param_1;
  iVar8 = 0;
  local_24 = param_2;
  pcVar2 = EncodePointer((PVOID)0x0);
  local_1c = pcVar2;
  bVar1 = FUN_4543970c();
  local_18 = (code *)CONCAT31(extraout_var,bVar1);
  if (DAT_454616b4 == (PVOID)0x0) {
    hModule = LoadLibraryExW(L"USER32.DLL",(HANDLE)0x0,0x800);
    if (((hModule == (HMODULE)0x0) &&
        ((DVar3 = GetLastError(), DVar3 != 0x57 ||
         (hModule = LoadLibraryExW(L"USER32.DLL",(HANDLE)0x0,0), hModule == (HMODULE)0x0)))) ||
       (pFVar4 = GetProcAddress(hModule,"MessageBoxW"), pFVar4 == (FARPROC)0x0)) goto LAB_4543ba30;
    DAT_454616b4 = EncodePointer(pFVar4);
    pFVar4 = GetProcAddress(hModule,"GetActiveWindow");
    DAT_454616b8 = EncodePointer(pFVar4);
    pFVar4 = GetProcAddress(hModule,"GetLastActivePopup");
    DAT_454616bc = EncodePointer(pFVar4);
    pFVar4 = GetProcAddress(hModule,"GetUserObjectInformationW");
    DAT_454616c4 = EncodePointer(pFVar4);
    pcVar2 = local_1c;
    if (DAT_454616c4 != (code *)0x0) {
      pFVar4 = GetProcAddress(hModule,"GetProcessWindowStation");
      DAT_454616c0 = EncodePointer(pFVar4);
      pcVar2 = local_1c;
    }
  }
  BVar5 = IsDebuggerPresent();
  if (BVar5 == 0) {
    if (local_18 != (code *)0x0) {
      DecodePointer(DAT_454616b4);
      goto LAB_4543ba30;
    }
  }
  else {
    if (local_20 != (LPCWSTR)0x0) {
      OutputDebugStringW(local_20);
    }
    if (local_18 != (code *)0x0) goto LAB_4543ba30;
  }
  if ((DAT_454616c0 == pcVar2) || (DAT_454616c4 == pcVar2)) {
LAB_4543b9e6:
    if ((((DAT_454616b8 != pcVar2) && (pcVar7 = DecodePointer(DAT_454616b8), pcVar7 != (code *)0x0))
        && (iVar8 = (*pcVar7)(), iVar8 != 0)) &&
       ((DAT_454616bc != pcVar2 && (pcVar2 = DecodePointer(DAT_454616bc), pcVar2 != (code *)0x0))))
    {
      iVar8 = (*pcVar2)(iVar8);
    }
  }
  else {
    local_18 = DecodePointer(DAT_454616c0);
    local_1c = DecodePointer(DAT_454616c4);
    if (((local_18 == (code *)0x0) || (local_1c == (code *)0x0)) ||
       (((iVar6 = (*local_18)(), iVar6 != 0 &&
         (iVar6 = (*local_1c)(iVar6,1,local_14,0xc,local_28), iVar6 != 0)) && ((local_c & 1) != 0)))
       ) goto LAB_4543b9e6;
    param_3 = param_3 | 0x200000;
  }
  pcVar2 = DecodePointer(DAT_454616b4);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(iVar8,local_20,local_24,param_3);
  }
LAB_4543ba30:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



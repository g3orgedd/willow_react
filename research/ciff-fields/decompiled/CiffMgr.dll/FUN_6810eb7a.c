// Source: CiffMgr.dll @ 6810eb7a; FUN_6810eb7a

void FUN_6810eb7a(int *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  HMODULE pHVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  HMODULE pHVar5;
  size_t sVar6;
  wchar_t *pwVar7;
  undefined **local_a4c;
  undefined4 local_a48;
  undefined4 local_a44;
  undefined4 local_a40;
  wchar_t local_a38 [520];
  wchar_t local_628;
  undefined2 local_626 [523];
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  local_a4c = ATL::CRegObject::vftable;
  local_a48 = 0;
  local_a44 = 0;
  local_a40 = 0;
  if (param_4 != (undefined4 *)0x0) {
    for (; (wchar_t *)*param_4 != (wchar_t *)0x0; param_4 = param_4 + 2) {
      FUN_6810c0b5((int)&local_a4c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a4c);
  pHVar1 = DAT_68167140;
  if (-1 < iVar3) {
    DVar4 = GetModuleFileNameW(DAT_68167140,local_210,0x104);
    if (DVar4 == 0) {
      FUN_6810c923();
    }
    else if (DVar4 != 0x104) {
      FUN_6810d3ab(local_a38,0x208,local_210);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_628 = L'\"';
        bVar2 = FUN_6810efb4(local_626,0x20b,local_a38);
        if (!bVar2) goto LAB_6810ecee;
        sVar6 = _wcslen(&local_628);
        local_626[sVar6 - 1] = 0x22;
        if (0x417 < sVar6 * 2 + 2) {
                    /* WARNING: Subroutine does not return */
          ___report_rangecheckfailure();
        }
        local_626[sVar6] = 0;
        pwVar7 = &local_628;
      }
      else {
        pwVar7 = local_a38;
      }
      iVar3 = FUN_6810c0b5((int)&local_a4c,L"Module",pwVar7);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_6810c0b5((int)&local_a4c,L"Module_Raw",local_a38), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_6810e850(&local_a4c,local_210,param_2,L"REGISTRY");
        }
        else {
          FUN_6810e7db(&local_a4c,local_210,param_2,L"REGISTRY");
        }
      }
    }
  }
LAB_6810ecee:
  FUN_6810be22(&local_a4c);
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



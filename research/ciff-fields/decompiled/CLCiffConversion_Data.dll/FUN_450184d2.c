// Source: CLCiffConversion_Data.dll @ 450184d2; FUN_450184d2

void FUN_450184d2(int *param_1,uint param_2,int param_3,undefined4 *param_4)

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
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_a4c = ATL::CRegObject::vftable;
  local_a48 = 0;
  local_a44 = 0;
  local_a40 = 0;
  if (param_4 != (undefined4 *)0x0) {
    for (; (wchar_t *)*param_4 != (wchar_t *)0x0; param_4 = param_4 + 2) {
      FUN_45014db4((int)&local_a4c,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
    }
  }
  iVar3 = (**(code **)(*param_1 + 0x14))(&local_a4c);
  pHVar1 = DAT_45054fec;
  if (-1 < iVar3) {
    DVar4 = GetModuleFileNameW(DAT_45054fec,local_210,0x104);
    if (DVar4 == 0) {
      FUN_450155e4();
    }
    else if (DVar4 != 0x104) {
      FUN_45016505(local_a38,0x208,local_210);
      if ((pHVar1 == (HMODULE)0x0) || (pHVar5 = GetModuleHandleW((LPCWSTR)0x0), pHVar1 == pHVar5)) {
        local_628 = L'\"';
        bVar2 = FUN_450189d0(local_626,0x20b,local_a38);
        if (!bVar2) goto LAB_45018646;
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
      iVar3 = FUN_45014db4((int)&local_a4c,L"Module",pwVar7);
      if ((-1 < iVar3) &&
         (iVar3 = FUN_45014db4((int)&local_a4c,L"Module_Raw",local_a38), -1 < iVar3)) {
        if (param_3 == 0) {
          FUN_450181e0(&local_a4c,local_210,param_2,L"REGISTRY");
        }
        else {
          FUN_4501816b(&local_a4c,local_210,param_2,L"REGISTRY");
        }
      }
    }
  }
LAB_45018646:
  FUN_45014a5d(&local_a4c);
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



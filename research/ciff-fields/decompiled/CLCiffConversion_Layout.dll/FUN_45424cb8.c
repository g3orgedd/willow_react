// Source: CLCiffConversion_Layout.dll @ 45424cb8; FUN_45424cb8

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_45424cb8(HMODULE param_1,wchar_t *param_2,undefined4 *param_3,ITypeLib **param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  ulong uVar3;
  bool bVar4;
  DWORD DVar5;
  LPCSTR lpsz;
  size_t sVar6;
  long lVar7;
  char *pcVar8;
  wchar_t *pwVar9;
  HRESULT HVar10;
  errno_t eVar11;
  BSTR pOVar12;
  undefined4 *_Memory;
  LPCSTR pCVar13;
  LPCSTR _Dst;
  undefined4 *local_128;
  ulong local_124;
  char local_120 [270];
  char local_12 [2];
  wchar_t *local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_10 = param_2;
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (ITypeLib **)0x0)) goto LAB_45424fe4;
  *param_3 = 0;
  *param_4 = (ITypeLib *)0x0;
  _Memory = (undefined4 *)0x0;
  local_128 = (undefined4 *)0x0;
  DVar5 = GetModuleFileNameA(param_1,local_120,0x104);
  if (DVar5 == 0) {
    FUN_45402fed();
  }
  else if (DVar5 != 0x104) {
    lpsz = local_120;
    _Dst = (LPCSTR)0x0;
    while (local_120[0] != '\0') {
      pCVar13 = lpsz;
      if ((local_120[0] != '.') && (pCVar13 = _Dst, local_120[0] == '\\')) {
        pCVar13 = (LPCSTR)0x0;
      }
      lpsz = CharNextA(lpsz);
      _Dst = pCVar13;
      local_120[0] = *lpsz;
    }
    if (_Dst == (LPCSTR)0x0) {
      _Dst = lpsz;
    }
    if (local_10 == (wchar_t *)0x0) {
LAB_45424e2e:
      sVar6 = _strlen(local_120);
      local_124 = sVar6 + 1;
      lVar7 = ATL::AtlMultiply<int>((int *)&local_124,local_124,2);
      uVar3 = local_124;
      if (-1 < lVar7) {
        if (((int)local_124 < 0x401) &&
           (bVar4 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_124), bVar4)) {
          pwVar9 = (wchar_t *)&stack0xfffffec0;
        }
        else {
          pwVar9 = (wchar_t *)FUN_454145c6(&local_128,uVar3);
          _Memory = local_128;
        }
        pwVar9 = AtlA2WHelper(pwVar9,local_120,uVar3 >> 1,3);
        if (pwVar9 != (wchar_t *)0x0) {
          HVar10 = LoadTypeLib(pwVar9,param_4);
          if (HVar10 < 0) {
            local_10 = DAT_4544aa28;
            local_c = DAT_4544aa2c;
            if (_Dst + (5 - (int)local_120) < (char *)0x105) {
              eVar11 = _strcpy_s(_Dst,(rsize_t)(local_12 + -(int)_Dst),(char *)&local_10);
              FUN_45402fb2(eVar11);
              sVar6 = _strlen(local_120);
              local_124 = sVar6 + 1;
              lVar7 = ATL::AtlMultiply<int>((int *)&local_124,local_124,2);
              uVar3 = local_124;
              if (-1 < lVar7) {
                if (((int)local_124 < 0x401) &&
                   (bVar4 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_124), bVar4))
                {
                  pwVar9 = (wchar_t *)&stack0xfffffec0;
                }
                else {
                  pwVar9 = (wchar_t *)FUN_454145c6(&local_128,uVar3);
                  _Memory = local_128;
                }
                pwVar9 = AtlA2WHelper(pwVar9,local_120,uVar3 >> 1,3);
                if ((pwVar9 != (wchar_t *)0x0) &&
                   (HVar10 = LoadTypeLib(pwVar9,param_4), -1 < HVar10)) goto LAB_45424f9c;
              }
            }
          }
          else {
LAB_45424f9c:
            pOVar12 = SysAllocString(pwVar9);
            *param_3 = pOVar12;
            if (pOVar12 == (BSTR)0x0) {
              (*(*param_4)->lpVtbl->Release)(*param_4);
              *param_4 = (ITypeLib *)0x0;
            }
          }
        }
      }
    }
    else {
      sVar6 = _wcslen(local_10);
      local_124 = sVar6 + 1;
      lVar7 = ATL::AtlMultiply<int>((int *)&local_124,local_124,2);
      uVar3 = local_124;
      if (-1 < lVar7) {
        if (((int)local_124 < 0x401) &&
           (bVar4 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_124), bVar4)) {
          pcVar8 = &stack0xfffffec0;
        }
        else {
          pcVar8 = (char *)FUN_454145c6(&local_128,uVar3);
          _Memory = local_128;
        }
        pcVar8 = AtlW2AHelper(pcVar8,local_10,uVar3,3);
        if (pcVar8 != (char *)0x0) {
          sVar6 = _strlen(pcVar8);
          uVar1 = sVar6 + DVar5;
          if (((DVar5 <= uVar1) && (sVar6 <= uVar1)) && (uVar1 < 0x10e)) {
            FID_conflict_tcscpy_s(local_120 + DVar5,0x10e - DVar5,pcVar8);
            goto LAB_45424e2e;
          }
        }
      }
    }
  }
  while (_Memory != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*_Memory;
    FID_conflict__free(_Memory);
    _Memory = puVar2;
  }
LAB_45424fe4:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



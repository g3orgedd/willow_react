// Source: CLCiffConversion_Data.dll @ 450156b2; FUN_450156b2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_450156b2(HMODULE param_1,wchar_t *param_2,undefined4 *param_3,ITypeLib **param_4)

{
  uint uVar1;
  DWORD DVar2;
  LPCWSTR lpsz;
  size_t sVar3;
  HRESULT HVar4;
  errno_t eVar5;
  BSTR pOVar6;
  int iVar7;
  LPCWSTR pWVar8;
  LPCWSTR _Dst;
  WCHAR local_230 [270];
  undefined4 local_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  *param_3 = 0;
  *param_4 = (ITypeLib *)0x0;
  DVar2 = GetModuleFileNameW(param_1,local_230,0x104);
  if (DVar2 == 0) {
    FUN_450155e4();
  }
  else if (DVar2 != 0x104) {
    lpsz = local_230;
    _Dst = (LPCWSTR)0x0;
    while (local_230[0] != L'\0') {
      pWVar8 = lpsz;
      if ((local_230[0] != L'.') && (pWVar8 = _Dst, local_230[0] == L'\\')) {
        pWVar8 = (LPCWSTR)0x0;
      }
      lpsz = CharNextW(lpsz);
      _Dst = pWVar8;
      local_230[0] = *lpsz;
    }
    if (_Dst == (LPCWSTR)0x0) {
      _Dst = lpsz;
    }
    if (param_2 != (wchar_t *)0x0) {
      sVar3 = _wcslen(param_2);
      uVar1 = sVar3 + DVar2;
      if (((uVar1 < DVar2) || (uVar1 < sVar3)) || (0x10d < uVar1)) goto LAB_4501583a;
      FUN_45018a09(local_230 + DVar2,0x10e - DVar2,param_2);
    }
    HVar4 = LoadTypeLib(local_230,param_4);
    if (HVar4 < 0) {
      iVar7 = (int)_Dst - (int)local_230 >> 1;
      local_14 = _DAT_4503fc70;
      uStack_10 = DAT_4503fc74;
      uStack_c = DAT_4503fc78;
      if (0x104 < iVar7 + 5U) goto LAB_4501583a;
      eVar5 = _wcscpy_s(_Dst,0x10e - iVar7,(wchar_t *)&local_14);
      FUN_450026fa(eVar5);
      HVar4 = LoadTypeLib(local_230,param_4);
      if (HVar4 < 0) goto LAB_4501583a;
    }
    pOVar6 = SysAllocString(local_230);
    *param_3 = pOVar6;
    if (pOVar6 == (BSTR)0x0) {
      (*(*param_4)->lpVtbl->Release)(*param_4);
      *param_4 = (ITypeLib *)0x0;
    }
  }
LAB_4501583a:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



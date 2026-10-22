// Source: CiffMgr.dll @ 6812f9cf; FUN_6812f9cf

uint FUN_6812f9cf(wchar_t *param_1)

{
  wchar_t *_Str1;
  uint uVar1;
  int iVar2;
  size_t sVar3;
  UINT UVar4;
  uint uVar5;
  uint uVar6;
  uint local_8;
  
  _Str1 = param_1;
  uVar6 = 0;
  local_8 = 0;
  if (param_1 != (wchar_t *)0x0) {
    uVar5 = 0;
    do {
      iVar2 = _wcscmp(_Str1,(wchar_t *)(&PTR_u_10X10_68160128)[uVar5]);
      uVar1 = uVar5;
      if (iVar2 == 0) break;
      uVar5 = uVar5 + 1;
      uVar1 = local_8;
    } while (uVar5 < 0x20);
    local_8 = uVar1;
    if (0x1f < uVar5) {
      sVar3 = _wcslen(L"Auto;");
      iVar2 = _wcsncmp(_Str1,L"Auto;",sVar3);
      if (iVar2 == 0) {
        UVar4 = SysStringLen(_Str1);
        sVar3 = _wcslen(L"Auto;");
        FUN_68118181(&param_1,UVar4 - sVar3,_Str1 + sVar3);
        do {
          iVar2 = _wcscmp(param_1,(wchar_t *)(&PTR_u_10X10_68160128)[uVar6]);
          uVar5 = uVar6;
          if (iVar2 == 0) break;
          uVar6 = uVar6 + 1;
          uVar5 = local_8;
        } while (uVar6 < 0x20);
        local_8 = uVar5;
        SysFreeString(param_1);
      }
    }
  }
  return local_8;
}



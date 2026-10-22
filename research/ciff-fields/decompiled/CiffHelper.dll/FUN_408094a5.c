// Source: CiffHelper.dll @ 408094a5; FUN_408094a5

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __cdecl FUN_408094a5(LPCWSTR param_1,LPCWSTR param_2)

{
  uint uVar1;
  undefined1 uVar2;
  LPCWSTR pWVar3;
  size_t sVar4;
  int iVar5;
  wchar_t ****ppppwVar6;
  undefined1 **ppuVar7;
  wchar_t *_Str;
  undefined4 *puVar8;
  undefined4 auStack_106c [58];
  undefined4 uStack_f84;
  undefined1 *_Memory;
  DWORD local_f58;
  DWORD local_f54;
  undefined1 *local_f50;
  undefined1 local_f4c [124];
  undefined1 *local_ed0;
  undefined1 local_ecc [128];
  undefined2 local_e4c [8];
  undefined4 local_e3c;
  undefined4 local_e38;
  wchar_t ***local_e34 [4];
  int local_e24;
  uint local_e20;
  WCHAR local_e1c;
  uint local_e1a [255];
  wchar_t local_a1c;
  uint local_a1a [511];
  undefined1 local_21c [532];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0xf48;
  local_e38 = 7;
  local_e3c = 0;
  local_e4c[0] = 0;
  uVar1 = *(uint *)(param_1 + 8);
  local_8 = 0;
  uStack_7 = 0;
  if ((uVar1 == 0) || (0x103 < uVar1)) goto LAB_40809818;
  if (1 < uVar1) {
    pWVar3 = param_1;
    if (7 < *(uint *)(param_1 + 10)) {
      pWVar3 = *(LPCWSTR *)param_1;
    }
    if (*pWVar3 == L'\\') {
      pWVar3 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        pWVar3 = *(LPCWSTR *)param_1;
      }
      if (*pWVar3 == L'\\') {
        if (param_2 != param_1) {
          FUN_40806812(param_2,(undefined8 *)param_1,0,0xffffffff);
        }
        goto LAB_40809818;
      }
    }
  }
  local_21c._0_4_ = local_21c._0_4_ & 0xffff0000;
  FUN_4082cef0((uint *)(local_21c + 2),0,0x206);
  local_f58 = 0x104;
  pWVar3 = param_1;
  if (7 < *(uint *)(param_1 + 10)) {
    pWVar3 = *(LPCWSTR *)param_1;
  }
  local_f54 = WNetGetUniversalNameW(pWVar3,1,local_21c,&local_f58);
  if (local_f54 == 0) {
    FID_conflict_assign(param_2,(wchar_t *)local_21c._0_4_);
    goto LAB_40809818;
  }
  local_e20 = 7;
  local_e24 = 0;
  local_e34[0] = (wchar_t ***)((uint)local_e34[0] & 0xffff0000);
  local_8 = 1;
  if (local_f54 < 0x4b4) {
    if (local_f54 == 0x4b3) {
      _Str = L"ERROR_NO_NET_OR_BAD_PATH";
    }
    else if (local_f54 == 0x32) {
      _Str = L"ERROR_NOT_SUPPORTED";
    }
    else if (local_f54 == 0xea) {
      _Str = L"ERROR_MORE_DATA";
    }
    else if (local_f54 == 0x4b0) {
      _Str = L"ERROR_BAD_DEVICE";
    }
    else {
      uVar2 = 1;
      if (local_f54 != 0x4b1) goto LAB_40809790;
      _Str = L"ERROR_CONNECTION_UNAVAIL";
    }
LAB_40809678:
    sVar4 = _wcslen(_Str);
    FID_conflict_assign(local_e34,(undefined8 *)_Str,sVar4);
    uVar2 = local_8;
    if (local_e24 != 0) {
      if (*(int *)(param_1 + 8) == 0) {
        local_f50 = local_f4c;
        ppppwVar6 = local_e34;
        if (7 < local_e20) {
          ppppwVar6 = (wchar_t ****)local_e34[0];
        }
        ATL::CW2WEX<128>::Init((CW2WEX<128> *)&local_f50,(wchar_t *)ppppwVar6);
        local_8 = 3;
        ppuVar7 = &local_f50;
        puVar8 = auStack_106c;
        for (iVar5 = 0x41; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *ppuVar7;
          ppuVar7 = ppuVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        FUN_40804125(0x4084b940);
        _Memory = local_f50;
        uVar2 = local_8;
        if (local_f50 != local_f4c) {
LAB_4080978a:
          FID_conflict__free(_Memory);
          uVar2 = local_8;
        }
      }
      else {
        iVar5 = FUN_4080937c(&local_a1c,L"DecodeMappedDriverToUNC - Error[%ls] - Folder[%ls]");
        uVar2 = local_8;
        if (0 < iVar5) {
          local_ed0 = local_ecc;
          FUN_40809831(&local_ed0,&local_a1c,3);
          local_8 = 2;
          FUN_40804125((int)local_ed0);
          _Memory = local_ed0;
          uVar2 = local_8;
          if (local_ed0 != local_ecc) goto LAB_4080978a;
        }
      }
    }
  }
  else {
    if (local_f54 == 0x4b8) {
      _Str = L"ERROR_EXTENDED_ERROR";
      goto LAB_40809678;
    }
    if (local_f54 == 0x4c6) {
      _Str = L"ERROR_NO_NETWORK";
      goto LAB_40809678;
    }
    uVar2 = local_8;
    if (local_f54 == 0x8ca) {
      sVar4 = _wcslen(L"ERROR_NOT_CONNECTED");
      FID_conflict_assign(local_e34,(undefined8 *)L"ERROR_NOT_CONNECTED",sVar4);
      if (param_2 != param_1) {
        FUN_40806812(param_2,(undefined8 *)param_1,0,0xffffffff);
      }
      FUN_4080653d(local_e34,'\x01',0);
      goto LAB_40809818;
    }
  }
LAB_40809790:
  local_8 = uVar2;
  if (local_f54 == 0x4b8) {
    local_e1c = L'\0';
    FUN_4082cef0(local_e1a,0,0x3fe);
    local_a1c = L'\0';
    uStack_f84 = 0x408097d2;
    FUN_4082cef0(local_a1a,0,0x7fe);
    local_f54 = 0;
    WNetGetLastErrorW(&local_f54,&local_a1c,0x800,&local_e1c,0x400);
  }
  FUN_4080653d(local_e34,'\x01',0);
LAB_40809818:
  FUN_4080653d(local_e4c,'\x01',0);
  FUN_4082d4c6();
  return;
}



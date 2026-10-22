// Source: CLCiffConversion_Data.dll @ 4501ff9e; FUN_4501ff9e

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __fastcall FUN_4501ff9e(int *param_1)

{
  ushort uVar1;
  LPCWSTR pWVar2;
  uint uVar3;
  size_t sVar4;
  int *piVar5;
  LPCWSTR ***ppppWVar6;
  int iVar7;
  OLECHAR *pOVar8;
  LPCWSTR local_2dc;
  LPCWSTR local_2d8;
  LPCWSTR local_2d4;
  undefined2 local_2d0 [8];
  undefined4 local_2c0;
  undefined4 local_2bc;
  LPCWSTR **local_2b8 [4];
  undefined4 local_2a8;
  uint local_2a4;
  LPCWSTR **local_2a0 [4];
  undefined4 local_290;
  uint local_28c;
  WCHAR local_288 [100];
  WCHAR local_1c0 [100];
  WCHAR local_f8 [100];
  wchar_t local_30 [4];
  wchar_t local_28 [6];
  uint local_1c [5];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2cc;
  local_8 = 0x4501ffad;
  if ((param_1[1] - *param_1 & 0xfffffff8U) != 0) {
    FUN_45014013(*param_1,param_1[1]);
    param_1[1] = *param_1;
  }
  pWVar2 = FUN_4501ca38();
  GetPrivateProfileStringW(L"shiftcodes",L"activeshifts",L" ",local_1c0,100,pWVar2);
  uVar3 = __wtol(local_1c0);
  local_1c[0] = uVar3;
  FUN_45020a4d(param_1,uVar3);
  local_2d4 = (LPCWSTR)0x0;
  if (0 < (int)uVar3) {
    do {
      uVar3 = 0;
      local_2d8 = (LPCWSTR)((int)local_2d4 + 1);
      _swprintf_s(local_28,6,L"%02d",local_2d8);
      local_2a4 = 7;
      local_2a8 = 0;
      local_2b8[0] = (LPCWSTR **)((uint)local_2b8[0] & 0xffff0000);
      sVar4 = _wcslen(L"start");
      FID_conflict_assign(local_2b8,(undefined8 *)L"start",sVar4);
      local_8 = 0;
      sVar4 = uVar3;
      if (local_28[0] != L'\0') {
        sVar4 = _wcslen(local_28);
      }
      FUN_45014125(local_2b8,(undefined8 *)local_28,sVar4);
      local_28c = 7;
      local_290 = 0;
      local_2a0[0] = (LPCWSTR **)((uint)local_2a0[0] & 0xffff0000);
      sVar4 = _wcslen(L"code");
      FID_conflict_assign(local_2a0,(undefined8 *)L"code",sVar4);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_28[0] != L'\0') {
        uVar3 = _wcslen(local_28);
      }
      FUN_45014125(local_2a0,(undefined8 *)local_28,uVar3);
      ppppWVar6 = local_2b8;
      if (7 < local_2a4) {
        ppppWVar6 = (LPCWSTR ***)local_2b8[0];
      }
      pWVar2 = FUN_4501ca38();
      GetPrivateProfileStringW(L"shiftcodes",(LPCWSTR)ppppWVar6,L" ",local_1c0,100,pWVar2);
      local_2dc = (LPCWSTR)__wtol(local_1c0);
      ppppWVar6 = local_2a0;
      if (7 < local_28c) {
        ppppWVar6 = (LPCWSTR ***)local_2a0[0];
      }
      pWVar2 = FUN_4501ca38();
      GetPrivateProfileStringW(L"shiftcodes",(LPCWSTR)ppppWVar6,L" ",local_1c0,100,pWVar2);
      uVar3 = 0;
      local_2bc = 7;
      local_2d0[0] = 0;
      local_2c0 = 0;
      if (local_1c0[0] != L'\0') {
        uVar3 = _wcslen(local_1c0);
      }
      FID_conflict_assign(local_2d0,(undefined8 *)local_1c0,uVar3);
      local_8 = CONCAT31(local_8._1_3_,2);
      *(LPCWSTR *)(*param_1 + (int)local_2d4 * 8) = local_2dc;
      FUN_45002326((void *)((int)local_2d4 * 8 + 4 + *param_1),local_1c0);
      FUN_450046d9(local_2d0,'\x01',0);
      FUN_450046d9(local_2a0,'\x01',0);
      local_8 = 0xffffffff;
      FUN_450046d9(local_2b8,'\x01',0);
      local_2d4 = local_2d8;
    } while ((int)local_2d8 < (int)local_1c[0]);
  }
  iVar7 = 0;
  do {
    local_2d4 = (LPCWSTR)0x0;
    local_2d8 = (LPCWSTR)0x0;
    local_8 = 4;
    switch(iVar7) {
    case 0:
      FUN_45002326(&local_2d4,L"Jan");
      pOVar8 = L"JA";
      break;
    case 1:
      FUN_45002326(&local_2d4,L"Feb");
      pOVar8 = L"FE";
      break;
    case 2:
      FUN_45002326(&local_2d4,L"Mar");
      pOVar8 = L"MR";
      break;
    case 3:
      FUN_45002326(&local_2d4,L"Apr");
      pOVar8 = L"AL";
      break;
    case 4:
      FUN_45002326(&local_2d4,L"May");
      pOVar8 = L"MA";
      break;
    case 5:
      FUN_45002326(&local_2d4,L"Jun");
      pOVar8 = L"JN";
      break;
    case 6:
      FUN_45002326(&local_2d4,L"Jul");
      pOVar8 = L"JL";
      break;
    case 7:
      FUN_45002326(&local_2d4,L"Aug");
      pOVar8 = L"AU";
      break;
    case 8:
      FUN_45002326(&local_2d4,L"Sep");
      pOVar8 = L"SE";
      break;
    case 9:
      FUN_45002326(&local_2d4,L"Oct");
      pOVar8 = L"OC";
      break;
    case 10:
      FUN_45002326(&local_2d4,L"Nov");
      pOVar8 = L"NO";
      break;
    default:
      FUN_45002326(&local_2d4,L"Dec");
      pOVar8 = L"DE";
    }
    FUN_45002326(&local_2d8,pOVar8);
    pWVar2 = FUN_4501ca38();
    GetPrivateProfileStringW(L"monthcodes",local_2d4,local_2d8,local_f8,100,pWVar2);
    if (local_f8[0] == L'\0') {
      uVar3 = 0;
    }
    else {
      uVar3 = _wcslen(local_f8);
    }
    FID_conflict_assign(param_1 + iVar7 * 6 + 0x57,(undefined8 *)local_f8,uVar3);
    SysFreeString(local_2d8);
    local_8 = 0xffffffff;
    SysFreeString(local_2d4);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xc);
  iVar7 = 0;
  piVar5 = param_1 + 0x9f;
  do {
    _swprintf_s((wchar_t *)local_1c,3,L"%02d",iVar7);
    FUN_45001f5d(&local_2dc,(OLECHAR *)local_1c);
    uVar1 = (short)iVar7 + 0x41;
    local_8 = 5;
    if (0x48 < uVar1) {
      uVar1 = (short)iVar7 + 0x42;
    }
    if (0x4e < uVar1) {
      uVar1 = uVar1 + 1;
    }
    local_2d4 = (LPCWSTR)(uint)uVar1;
    FUN_45001f5d(&local_2d8,(OLECHAR *)&local_2d4);
    local_8 = CONCAT31(local_8._1_3_,6);
    pWVar2 = FUN_4501ca38();
    GetPrivateProfileStringW(L"hourcodes",local_2dc,local_2d8,local_f8,100,pWVar2);
    if (local_f8[0] == L'\0') {
      uVar3 = 0;
    }
    else {
      uVar3 = _wcslen(local_f8);
    }
    FID_conflict_assign(piVar5,(undefined8 *)local_f8,uVar3);
    SysFreeString(local_2d8);
    local_8 = 0xffffffff;
    SysFreeString(local_2dc);
    iVar7 = iVar7 + 1;
    piVar5 = piVar5 + 6;
  } while (iVar7 < 0x18);
  iVar7 = 0;
  do {
    local_2d8 = (LPCWSTR)0x0;
    local_2d4 = (LPCWSTR)0x0;
    local_8 = 8;
    if (iVar7 == 0) {
      FUN_45002326(&local_2d8,L"Mon");
      pOVar8 = L"MO";
LAB_450205c8:
      FUN_45002326(&local_2d4,pOVar8);
    }
    else {
      if (iVar7 == 1) {
        FUN_45002326(&local_2d8,L"Tue");
        pOVar8 = L"TU";
        goto LAB_450205c8;
      }
      if (iVar7 == 2) {
        FUN_45002326(&local_2d8,L"Wed");
        pOVar8 = L"WE";
        goto LAB_450205c8;
      }
      if (iVar7 == 3) {
        FUN_45002326(&local_2d8,L"Thu");
        pOVar8 = L"TH";
        goto LAB_450205c8;
      }
      if (iVar7 == 4) {
        FUN_45002326(&local_2d8,L"Fri");
        pOVar8 = L"FR";
        goto LAB_450205c8;
      }
      if (iVar7 == 5) {
        FUN_45002326(&local_2d8,L"Sat");
        pOVar8 = L"SA";
        goto LAB_450205c8;
      }
      if (iVar7 == 6) {
        FUN_45002326(&local_2d8,L"Sun");
        pOVar8 = L"SU";
        goto LAB_450205c8;
      }
    }
    pWVar2 = FUN_4501ca38();
    GetPrivateProfileStringW(L"dayofweekcodes",local_2d8,local_2d4,local_f8,100,pWVar2);
    if (local_f8[0] == L'\0') {
      uVar3 = 0;
    }
    else {
      uVar3 = _wcslen(local_f8);
    }
    FID_conflict_assign(param_1 + iVar7 * 6 + 0x12f,(undefined8 *)local_f8,uVar3);
    SysFreeString(local_2d4);
    SysFreeString(local_2d8);
    iVar7 = iVar7 + 1;
    if (6 < iVar7) {
      iVar7 = 0;
      piVar5 = param_1 + 0x38d;
      do {
        local_2d4 = (LPCWSTR)PTR_DAT_4505101c;
        local_8 = 9;
        FUN_450037ea(&local_2d4,L"%02d");
        pWVar2 = FUN_4501ca38();
        GetPrivateProfileStringW(L"minutecodes",local_2d4,L"  ",local_f8,100,pWVar2);
        if (local_f8[0] == L'\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = _wcslen(local_f8);
        }
        FID_conflict_assign(piVar5,(undefined8 *)local_f8,uVar3);
        local_8 = 0xffffffff;
        FUN_45002256((int *)&local_2d4);
        iVar7 = iVar7 + 1;
        piVar5 = piVar5 + 6;
      } while (iVar7 < 0x3c);
      iVar7 = 0;
      piVar5 = param_1 + 0x213;
      do {
        iVar7 = iVar7 + 1;
        _swprintf_s((wchar_t *)local_1c,3,L"%02d",iVar7);
        pWVar2 = FUN_4501ca38();
        GetPrivateProfileStringW(L"weekofyearcodes",(LPCWSTR)local_1c,L"  ",local_f8,100,pWVar2);
        if (local_f8[0] == L'\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = _wcslen(local_f8);
        }
        FID_conflict_assign(piVar5,(undefined8 *)local_f8,uVar3);
        piVar5 = piVar5 + 6;
      } while (iVar7 < 0x35);
      iVar7 = 0;
      piVar5 = param_1 + 0x351;
      do {
        _swprintf_s((wchar_t *)local_1c,3,L"%02d",iVar7);
        pWVar2 = FUN_4501ca38();
        GetPrivateProfileStringW(L"yearofdecadecodes",(LPCWSTR)local_1c,L"  ",local_f8,100,pWVar2);
        if (local_f8[0] == L'\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = _wcslen(local_f8);
        }
        FID_conflict_assign(piVar5,(undefined8 *)local_f8,uVar3);
        iVar7 = iVar7 + 1;
        piVar5 = piVar5 + 6;
      } while (iVar7 < 10);
      iVar7 = 0;
      piVar5 = param_1 + 0x159;
      do {
        iVar7 = iVar7 + 1;
        _swprintf_s(local_30,3,L"%02d",iVar7);
        pWVar2 = FUN_4501ca38();
        GetPrivateProfileStringW(L"dayofmonthcodes",local_30,L"  ",local_288,100,pWVar2);
        if (local_288[0] == L'\0') {
          uVar3 = 0;
        }
        else {
          uVar3 = _wcslen(local_288);
        }
        FID_conflict_assign(piVar5,(undefined8 *)local_288,uVar3);
        piVar5 = piVar5 + 6;
      } while (iVar7 < 0x1f);
      FUN_45022eb8();
      return;
    }
  } while( true );
}



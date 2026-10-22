// Source: CLCiffConversion_Data.dll @ 450158ac; FUN_450158ac

void FUN_450158ac(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  HRESULT HVar2;
  int iVar3;
  errno_t eVar4;
  LSTATUS LVar5;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  HKEY local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  int *local_1a0;
  GUID *local_19c;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  OLECHAR local_188 [64];
  wchar_t local_108 [128];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_19c = param_1;
  local_1a0 = (int *)0x0;
  if (param_2 != (int *)0x0) {
    HVar2 = CoCreateInstance((IID *)&DAT_45041794,(LPUNKNOWN)0x0,1,(IID *)&DAT_4503fc7c,&local_1a0);
    if (-1 < HVar2) {
      iVar3 = *param_2;
      while (iVar3 != 0) {
        puVar1 = (undefined4 *)param_2[1];
        local_198 = *puVar1;
        uStack_194 = puVar1[1];
        uStack_190 = puVar1[2];
        uStack_18c = puVar1[3];
        iVar3 = *local_1a0;
        if (param_3 == 0) {
          param_1 = local_19c;
          if (*param_2 == 1) {
            (**(code **)(iVar3 + 0x18))();
          }
          else {
            (**(code **)(iVar3 + 0x20))(local_1a0,local_19c,1,&local_198);
          }
        }
        else {
          if (*param_2 == 1) {
            iVar3 = (**(code **)(iVar3 + 0x14))();
          }
          else {
            iVar3 = (**(code **)(iVar3 + 0x1c))(local_1a0,local_19c);
          }
          param_1 = local_19c;
          if (iVar3 < 0) {
            if (local_1a0 != (int *)0x0) {
              (**(code **)(*local_1a0 + 8))(local_1a0);
            }
            goto LAB_45015b4c;
          }
        }
        param_2 = param_2 + 2;
        iVar3 = *param_2;
      }
      if (param_3 == 0) {
        StringFromGUID2(param_1,local_188,0x40);
        eVar4 = _wcscpy_s(local_108,0x80,L"CLSID\\");
        FUN_450026fa(eVar4);
        eVar4 = _wcscat_s(local_108,0x80,local_188);
        FUN_450026fa(eVar4);
        eVar4 = _wcscat_s(local_108,0x80,L"\\Required Categories");
        FUN_450026fa(eVar4);
        local_1b8 = 0x80000000;
        local_1b4 = 0;
        local_1b0 = 0;
        local_1ac = (HKEY)0x0;
        local_1a8 = 0;
        local_1a4 = 0;
        local_19c = (GUID *)0x0;
        iVar3 = Open(&local_1ac,(HKEY)0x80000000,local_108,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1ac,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)&local_19c,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
          ATL::CRegKey::Close((CRegKey *)&local_1ac);
          if ((LVar5 == 0) && (local_19c == (GUID *)0x0)) {
            DeleteSubKey(&local_1b8,local_108);
          }
        }
        eVar4 = _wcscpy_s(local_108,0x80,L"CLSID\\");
        FUN_450026fa(eVar4);
        eVar4 = _wcscat_s(local_108,0x80,local_188);
        FUN_450026fa(eVar4);
        eVar4 = _wcscat_s(local_108,0x80,L"\\Implemented Categories");
        FUN_450026fa(eVar4);
        iVar3 = Open(&local_1ac,(HKEY)0x80000000,local_108,0x20019);
        if (iVar3 == 0) {
          LVar5 = RegQueryInfoKeyW(local_1ac,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)&local_19c,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
          ATL::CRegKey::Close((CRegKey *)&local_1ac);
          if ((LVar5 == 0) && (local_19c == (GUID *)0x0)) {
            DeleteSubKey(&local_1b8,local_108);
          }
        }
        ATL::CRegKey::Close((CRegKey *)&local_1ac);
        ATL::CRegKey::Close((CRegKey *)&local_1b8);
      }
    }
    if (local_1a0 != (int *)0x0) {
      (**(code **)(*local_1a0 + 8))(local_1a0);
    }
  }
LAB_45015b4c:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Source: CiffMgr.dll @ 6810cb05; FUN_6810cb05

void FUN_6810cb05(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  HRESULT HVar3;
  errno_t eVar4;
  LSTATUS LVar5;
  int *piVar6;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  HKEY local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  int *local_1a4;
  int *local_1a0;
  GUID *local_19c;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  OLECHAR local_188 [64];
  wchar_t local_108 [128];
  uint local_8;
  
  local_8 = DAT_68160490 ^ (uint)&stack0xfffffffc;
  local_1a4 = param_2;
  local_1a0 = (int *)0x0;
  local_19c = param_1;
  piVar6 = (int *)0x0;
  if (((param_2 != (int *)0x0) &&
      (iVar2 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_6814e1ac), iVar2 == 0)) &&
     (HVar3 = CoCreateInstance((IID *)&DAT_6814e1cc,(LPUNKNOWN)0x0,1,(IID *)&DAT_68149990,&local_1a0
                              ), piVar6 = local_1a0, -1 < HVar3)) {
    for (; *local_1a4 != 0; local_1a4 = local_1a4 + 2) {
      puVar1 = (undefined4 *)local_1a4[1];
      local_198 = *puVar1;
      uStack_194 = puVar1[1];
      uStack_190 = puVar1[2];
      uStack_18c = puVar1[3];
      if (param_3 == 0) {
        param_1 = local_19c;
        if (*local_1a4 == 1) {
          (**(code **)(*local_1a0 + 0x18))();
        }
        else {
          (**(code **)(*local_1a0 + 0x20))(local_1a0,local_19c,1,&local_198);
        }
      }
      else {
        if (*local_1a4 == 1) {
          iVar2 = (**(code **)(*local_1a0 + 0x14))();
        }
        else {
          iVar2 = (**(code **)(*local_1a0 + 0x1c))(local_1a0,local_19c);
        }
        piVar6 = local_1a0;
        param_1 = local_19c;
        if (iVar2 < 0) goto LAB_6810cddb;
      }
    }
    piVar6 = local_1a0;
    if (param_3 == 0) {
      StringFromGUID2(param_1,local_188,0x40);
      eVar4 = _wcscpy_s(local_108,0x80,L"CLSID\\");
      FUN_68103e74(eVar4);
      eVar4 = _wcscat_s(local_108,0x80,local_188);
      FUN_68103e74(eVar4);
      eVar4 = _wcscat_s(local_108,0x80,L"\\Required Categories");
      FUN_68103e74(eVar4);
      local_1b8 = 0;
      local_1b4 = 0;
      local_1b0 = (HKEY)0x0;
      local_1bc = 0x80000000;
      local_1ac = 0;
      local_1a8 = 0;
      local_19c = (GUID *)0x0;
      iVar2 = Open(&local_1b0,(HKEY)0x80000000,local_108,0x20019);
      if (iVar2 == 0) {
        LVar5 = RegQueryInfoKeyW(local_1b0,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)&local_19c
                                 ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)0x0,(PFILETIME)0x0);
        ATL::CRegKey::Close((CRegKey *)&local_1b0);
        if ((LVar5 == 0) && (local_19c == (GUID *)0x0)) {
          DeleteSubKey(&local_1bc,local_108);
        }
      }
      eVar4 = _wcscpy_s(local_108,0x80,L"CLSID\\");
      FUN_68103e74(eVar4);
      eVar4 = _wcscat_s(local_108,0x80,local_188);
      FUN_68103e74(eVar4);
      eVar4 = _wcscat_s(local_108,0x80,L"\\Implemented Categories");
      FUN_68103e74(eVar4);
      iVar2 = Open(&local_1b0,(HKEY)0x80000000,local_108,0x20019);
      if (iVar2 == 0) {
        LVar5 = RegQueryInfoKeyW(local_1b0,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)&local_19c
                                 ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                 (LPDWORD)0x0,(PFILETIME)0x0);
        ATL::CRegKey::Close((CRegKey *)&local_1b0);
        if ((LVar5 == 0) && (local_19c == (GUID *)0x0)) {
          DeleteSubKey(&local_1bc,local_108);
        }
      }
      ATL::CRegKey::Close((CRegKey *)&local_1b0);
      ATL::CRegKey::Close((CRegKey *)&local_1bc);
      piVar6 = local_1a0;
    }
  }
LAB_6810cddb:
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 8))(piVar6);
  }
  FUN_68132051(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



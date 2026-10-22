// Source: CLCiffConversion_Layout.dll @ 4542505a; FUN_4542505a

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_4542505a(GUID *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  GUID *pGVar2;
  int *piVar3;
  bool bVar4;
  int iVar5;
  HRESULT HVar6;
  size_t sVar7;
  long lVar8;
  char *pcVar9;
  errno_t eVar10;
  LSTATUS LVar11;
  GUID *_Memory;
  int *piVar12;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  HKEY local_130;
  undefined4 local_12c;
  undefined4 local_128;
  int *local_124;
  int *local_120;
  GUID *local_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  OLECHAR local_108 [64];
  char local_88 [128];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_120 = param_2;
  local_124 = (int *)0x0;
  local_11c = param_1;
  piVar12 = (int *)0x0;
  if (((param_2 != (int *)0x0) &&
      (iVar5 = _InlineIsEqualGUID((int *)param_1,(int *)&DAT_4544b0a4), iVar5 == 0)) &&
     (HVar6 = CoCreateInstance((IID *)&DAT_4544b0c4,(LPUNKNOWN)0x0,1,(IID *)&DAT_4544aa30,&local_124
                              ), piVar12 = local_124, -1 < HVar6)) {
    for (; *local_120 != 0; local_120 = local_120 + 2) {
      puVar1 = (undefined4 *)local_120[1];
      local_118 = *puVar1;
      uStack_114 = puVar1[1];
      uStack_110 = puVar1[2];
      uStack_10c = puVar1[3];
      if (param_3 == 0) {
        param_1 = local_11c;
        if (*local_120 == 1) {
          (**(code **)(*local_124 + 0x18))();
        }
        else {
          (**(code **)(*local_124 + 0x20))(local_124,local_11c,1,&local_118);
        }
      }
      else {
        if (*local_120 == 1) {
          iVar5 = (**(code **)(*local_124 + 0x14))();
        }
        else {
          iVar5 = (**(code **)(*local_124 + 0x1c))(local_124,local_11c);
        }
        piVar12 = local_124;
        param_1 = local_11c;
        if (iVar5 < 0) goto LAB_454253cb;
      }
    }
    piVar12 = local_124;
    if (param_3 == 0) {
      StringFromGUID2(param_1,local_108,0x40);
      local_11c = (GUID *)0x0;
      sVar7 = _wcslen(local_108);
      local_120 = (int *)(sVar7 + 1);
      lVar8 = ATL::AtlMultiply<int>((int *)&local_120,(int)local_120,2);
      piVar3 = local_120;
      piVar12 = local_124;
      if (-1 < lVar8) {
        if (((int)local_120 < 0x401) &&
           (bVar4 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_120), bVar4))
        {
          pcVar9 = &stack0xfffffeb8;
          _Memory = (GUID *)0x0;
        }
        else {
          pcVar9 = (char *)FUN_454145c6(&local_11c,(int)piVar3);
          _Memory = local_11c;
        }
        local_120 = (int *)AtlW2AHelper(pcVar9,local_108,(int)piVar3,3);
        if (local_120 != (int *)0x0) {
          eVar10 = _strcpy_s(local_88,0x80,"CLSID\\");
          FUN_45402fb2(eVar10);
          eVar10 = _strcat_s(local_88,0x80,(char *)local_120);
          FUN_45402fb2(eVar10);
          eVar10 = _strcat_s(local_88,0x80,"\\Required Categories");
          FUN_45402fb2(eVar10);
          local_138 = 0;
          local_134 = 0;
          local_130 = (HKEY)0x0;
          local_13c = 0x80000000;
          local_12c = 0;
          local_128 = 0;
          local_11c = (GUID *)0x0;
          iVar5 = Open(&local_130,(HKEY)0x80000000,local_88,0x20019);
          if (iVar5 == 0) {
            LVar11 = RegQueryInfoKeyA(local_130,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)&local_11c,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
            ATL::CRegKey::Close((CRegKey *)&local_130);
            if ((LVar11 == 0) && (local_11c == (GUID *)0x0)) {
              DeleteSubKey(&local_13c,local_88);
            }
          }
          eVar10 = _strcpy_s(local_88,0x80,"CLSID\\");
          FUN_45402fb2(eVar10);
          eVar10 = _strcat_s(local_88,0x80,(char *)local_120);
          FUN_45402fb2(eVar10);
          eVar10 = _strcat_s(local_88,0x80,"\\Implemented Categories");
          FUN_45402fb2(eVar10);
          iVar5 = Open(&local_130,(HKEY)0x80000000,local_88,0x20019);
          if (iVar5 == 0) {
            LVar11 = RegQueryInfoKeyA(local_130,(LPSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)&local_11c,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                      (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
            ATL::CRegKey::Close((CRegKey *)&local_130);
            if ((LVar11 == 0) && (local_11c == (GUID *)0x0)) {
              DeleteSubKey(&local_13c,local_88);
            }
          }
          ATL::CRegKey::Close((CRegKey *)&local_130);
          ATL::CRegKey::Close((CRegKey *)&local_13c);
        }
        while (piVar12 = local_124, _Memory != (GUID *)0x0) {
          pGVar2 = (GUID *)_Memory->Data1;
          FID_conflict__free(_Memory);
          _Memory = pGVar2;
        }
      }
    }
  }
LAB_454253cb:
  if (piVar12 != (int *)0x0) {
    (**(code **)(*piVar12 + 8))(piVar12);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



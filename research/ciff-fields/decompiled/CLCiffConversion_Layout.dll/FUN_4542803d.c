// Source: CLCiffConversion_Layout.dll @ 4542803d; FUN_4542803d

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_4542803d(int *param_1,char *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  HMODULE pHVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  DWORD DVar6;
  size_t sVar7;
  long lVar8;
  HMODULE pHVar9;
  wchar_t *pwVar10;
  undefined4 *_Memory;
  undefined **local_954;
  undefined4 local_950;
  undefined4 local_94c;
  undefined4 local_948;
  wchar_t *local_940;
  undefined4 *local_93c;
  uint local_938;
  wchar_t local_934 [520];
  wchar_t local_524;
  undefined2 local_522 [523];
  CHAR local_10c [260];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  local_954 = ATL::CRegObject::vftable;
  local_950 = 0;
  local_94c = 0;
  local_948 = 0;
  if (param_4 != (undefined4 *)0x0) {
    for (; (wchar_t *)*param_4 != (wchar_t *)0x0; param_4 = param_4 + 2) {
      FUN_4542421b((int)&local_954,(wchar_t *)*param_4,(wchar_t *)param_4[1]);
    }
  }
  iVar5 = (**(code **)(*param_1 + 0x14))();
  pHVar2 = DAT_45460800;
  if (-1 < iVar5) {
    local_93c = (undefined4 *)0x0;
    DVar6 = GetModuleFileNameA(DAT_45460800,local_10c,0x104);
    if (DVar6 == 0) {
      FUN_45402fed();
    }
    else if (DVar6 != 0x104) {
      sVar7 = _strlen(local_10c);
      local_938 = sVar7 + 1;
      lVar8 = ATL::AtlMultiply<int>((int *)&local_938,local_938,2);
      uVar3 = local_938;
      if (-1 < lVar8) {
        if (((int)local_938 < 0x401) &&
           (bVar4 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_938), bVar4)) {
          pwVar10 = (wchar_t *)&stack0xfffff698;
          _Memory = (undefined4 *)0x0;
        }
        else {
          pwVar10 = (wchar_t *)FUN_454145c6(&local_93c,uVar3);
          _Memory = local_93c;
        }
        local_940 = AtlA2WHelper(pwVar10,local_10c,uVar3 >> 1,3);
        if (local_940 == (wchar_t *)0x0) {
          while (_Memory != (undefined4 *)0x0) {
            puVar1 = (undefined4 *)*_Memory;
            FID_conflict__free(_Memory);
            _Memory = puVar1;
          }
        }
        else {
          FUN_45425baf(local_934,0x208,local_940);
          if ((pHVar2 == (HMODULE)0x0) || (pHVar9 = GetModuleHandleA((LPCSTR)0x0), pHVar2 == pHVar9)
             ) {
            local_524 = L'\"';
            bVar4 = FUN_454284b7(local_522,0x20b,local_934);
            if (!bVar4) {
              while (_Memory != (undefined4 *)0x0) {
                puVar1 = (undefined4 *)*_Memory;
                FID_conflict__free(_Memory);
                _Memory = puVar1;
              }
              goto LAB_454281b8;
            }
            sVar7 = _wcslen(&local_524);
            local_522[sVar7 - 1] = 0x22;
            if (0x417 < sVar7 * 2 + 2) {
                    /* WARNING: Subroutine does not return */
              ___report_rangecheckfailure();
            }
            local_522[sVar7] = 0;
            pwVar10 = &local_524;
          }
          else {
            pwVar10 = local_934;
          }
          iVar5 = FUN_4542421b((int)&local_954,L"Module",pwVar10);
          if (iVar5 < 0) {
            while (_Memory != (undefined4 *)0x0) {
              puVar1 = (undefined4 *)*_Memory;
              FID_conflict__free(_Memory);
              _Memory = puVar1;
            }
          }
          else {
            iVar5 = FUN_4542421b((int)&local_954,L"Module_Raw",local_934);
            if (iVar5 < 0) {
              while (_Memory != (undefined4 *)0x0) {
                puVar1 = (undefined4 *)*_Memory;
                FID_conflict__free(_Memory);
                _Memory = puVar1;
              }
            }
            else {
              if (param_2 != (char *)0x0) {
                sVar7 = _strlen(param_2);
                local_938 = sVar7 + 1;
                lVar8 = ATL::AtlMultiply<int>((int *)&local_938,local_938,2);
                uVar3 = local_938;
                if (-1 < lVar8) {
                  if (((int)local_938 < 0x401) &&
                     (bVar4 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_938), bVar4
                     )) {
                    pwVar10 = (wchar_t *)&stack0xfffff698;
                  }
                  else {
                    pwVar10 = (wchar_t *)FUN_454145c6(&local_93c,uVar3);
                    _Memory = local_93c;
                  }
                  pwVar10 = AtlA2WHelper(pwVar10,param_2,uVar3 >> 1,3);
                  if (pwVar10 != (wchar_t *)0x0) {
                    if (param_3 == 0) {
                      FUN_454279fa(&local_954,local_940,pwVar10,L"REGISTRY");
                    }
                    else {
                      FUN_45427828(&local_954,local_940,pwVar10,L"REGISTRY");
                    }
                    while (_Memory != (undefined4 *)0x0) {
                      puVar1 = (undefined4 *)*_Memory;
                      FID_conflict__free(_Memory);
                      _Memory = puVar1;
                    }
                    FUN_45423f17(&local_954);
                    goto LAB_454281c5;
                  }
                }
              }
              while (_Memory != (undefined4 *)0x0) {
                puVar1 = (undefined4 *)*_Memory;
                FID_conflict__free(_Memory);
                _Memory = puVar1;
              }
            }
          }
        }
      }
    }
  }
LAB_454281b8:
  FUN_45423f17(&local_954);
LAB_454281c5:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Source: CLCiffConversion_Layout.dll @ 454279fa; FUN_454279fa

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_454279fa(void *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4)

{
  undefined4 *puVar1;
  ulong uVar2;
  bool bVar3;
  size_t sVar4;
  long lVar5;
  LPCSTR pCVar6;
  char *pcVar7;
  HRSRC pHVar8;
  undefined4 *_Memory;
  char local_2c [16];
  undefined4 *local_1c;
  ulong local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  _Memory = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  if ((param_3 != (wchar_t *)0x0) && (param_4 != (wchar_t *)0x0)) {
    sVar4 = _wcslen(param_3);
    local_18[0] = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar2 = local_18[0];
    if (lVar5 < 0) {
      pHVar8 = (HRSRC)0x0;
    }
    else {
      if (((int)local_18[0] < 0x401) &&
         (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar3)) {
        pcVar7 = local_2c;
      }
      else {
        pcVar7 = (char *)FUN_454145c6(&local_1c,uVar2);
        _Memory = local_1c;
      }
      pHVar8 = (HRSRC)AtlW2AHelper(pcVar7,param_3,uVar2,3);
    }
    sVar4 = _wcslen(param_4);
    local_18[0] = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar2 = local_18[0];
    if (lVar5 < 0) {
      pCVar6 = (LPCSTR)0x0;
    }
    else {
      if (((int)local_18[0] < 0x401) &&
         (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar3)) {
        pcVar7 = local_2c;
      }
      else {
        pcVar7 = (char *)FUN_454145c6(&local_1c,uVar2);
        _Memory = local_1c;
      }
      pCVar6 = AtlW2AHelper(pcVar7,param_4,uVar2,3);
    }
    if ((pHVar8 != (HRSRC)0x0) && (pCVar6 != (LPCSTR)0x0)) {
      FUN_45426d30(param_1,param_2,pHVar8,pCVar6);
    }
  }
  while (_Memory != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*_Memory;
    FID_conflict__free(_Memory);
    _Memory = puVar1;
  }
  FUN_4542a957();
  return;
}



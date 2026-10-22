// Source: CLCiffConversion_Layout.dll @ 45414a58; FUN_45414a58

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_45414a58(IID *param_1,char *param_2,DWORD param_3,char *param_4,GUID *param_5,
                 undefined4 param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  size_t sVar4;
  long lVar5;
  LPOLESTR pOVar6;
  wchar_t *pwVar7;
  undefined4 *_Memory;
  wchar_t local_30 [8];
  wchar_t *local_20;
  undefined4 *local_1c;
  uint local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x45414a64;
  if (param_2 == (char *)0x0) goto LAB_45414b72;
  _Memory = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  local_8 = 0;
  sVar4 = _strlen(param_2);
  local_18[0] = sVar4 + 1;
  lVar5 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
  uVar2 = local_18[0];
  if (-1 < lVar5) {
    if (((int)local_18[0] < 0x401) &&
       (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar3)) {
      pwVar7 = local_30;
    }
    else {
      pwVar7 = (wchar_t *)FUN_454145c6(&local_1c,uVar2);
      _Memory = local_1c;
    }
    local_20 = AtlA2WHelper(pwVar7,param_2,uVar2 >> 1,3);
    if (local_20 != (wchar_t *)0x0) {
      pOVar6 = (LPOLESTR)0x0;
      if (param_4 == (char *)0x0) {
LAB_45414b41:
        FUN_45414b7d(param_1,local_20,param_3,pOVar6,param_5,param_6,(HINSTANCE)0x0);
      }
      else {
        sVar4 = _strlen(param_4);
        local_18[0] = sVar4 + 1;
        lVar5 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
        uVar2 = local_18[0];
        if (-1 < lVar5) {
          if (((int)local_18[0] < 0x401) &&
             (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar3)) {
            pwVar7 = local_30;
          }
          else {
            pwVar7 = (wchar_t *)FUN_454145c6(&local_1c,uVar2);
            _Memory = local_1c;
          }
          pOVar6 = AtlA2WHelper(pwVar7,param_4,uVar2 >> 1,3);
          if (pOVar6 != (wchar_t *)0x0) goto LAB_45414b41;
        }
      }
    }
  }
  while (_Memory != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*_Memory;
    FID_conflict__free(_Memory);
    _Memory = puVar1;
  }
LAB_45414b72:
  FUN_4542a957();
  return;
}



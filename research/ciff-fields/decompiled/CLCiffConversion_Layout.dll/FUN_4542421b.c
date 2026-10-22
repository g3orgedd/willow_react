// Source: CLCiffConversion_Layout.dll @ 4542421b; FUN_4542421b

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_4542421b(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  undefined4 *puVar1;
  ulong uVar2;
  bool bVar3;
  size_t sVar4;
  long lVar5;
  char *pcVar6;
  undefined4 *_Memory;
  char local_2c [16];
  undefined4 *local_1c;
  ulong local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x45424227;
  if ((param_2 != (wchar_t *)0x0) && (param_3 != (wchar_t *)0x0)) {
    _Memory = (undefined4 *)0x0;
    local_1c = (undefined4 *)0x0;
    local_8 = 0;
    sVar4 = _wcslen(param_2);
    local_18[0] = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)local_18,local_18[0],2);
    uVar2 = local_18[0];
    if (-1 < lVar5) {
      if (((int)local_18[0] < 0x401) &&
         (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_18[0]), bVar3)) {
        pcVar6 = local_2c;
      }
      else {
        pcVar6 = (char *)FUN_454145c6(&local_1c,uVar2);
        _Memory = local_1c;
      }
      pcVar6 = AtlW2AHelper(pcVar6,param_2,uVar2,3);
      if (pcVar6 != (char *)0x0) {
        FUN_45424074((void *)(param_1 + 4),pcVar6,param_3);
      }
    }
    while (_Memory != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*_Memory;
      FID_conflict__free(_Memory);
      _Memory = puVar1;
    }
  }
  FUN_4542a957();
  return;
}



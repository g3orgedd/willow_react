// Source: CLCiffConversion_Layout.dll @ 454242ea; FUN_454242ea

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_454242ea(void *this,wchar_t *param_1)

{
  undefined4 *puVar1;
  ulong uVar2;
  bool bVar3;
  size_t sVar4;
  long lVar5;
  char *pcVar6;
  undefined4 *_Memory;
  char local_30 [16];
  void *local_20;
  ulong local_1c;
  undefined4 *local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x454242f6;
  local_20 = this;
  if (param_1 != (wchar_t *)0x0) {
    local_18[0] = (undefined4 *)0x0;
    local_8 = 0;
    sVar4 = _wcslen(param_1);
    local_1c = sVar4 + 1;
    lVar5 = ATL::AtlMultiply<int>((int *)&local_1c,local_1c,2);
    uVar2 = local_1c;
    _Memory = (undefined4 *)0x0;
    if (-1 < lVar5) {
      if (((int)local_1c < 0x401) &&
         (bVar3 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(local_1c), bVar3)) {
        pcVar6 = local_30;
      }
      else {
        pcVar6 = (char *)FUN_454145c6(local_18,uVar2);
        _Memory = local_18[0];
      }
      pcVar6 = AtlW2AHelper(pcVar6,param_1,uVar2,3);
      if (pcVar6 != (char *)0x0) {
        sVar4 = _strlen(pcVar6);
        FUN_4542486f(local_20,pcVar6,sVar4);
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



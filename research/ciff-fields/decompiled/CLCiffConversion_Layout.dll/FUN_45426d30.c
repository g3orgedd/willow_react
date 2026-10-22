// Source: CLCiffConversion_Layout.dll @ 45426d30; FUN_45426d30

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_45426d30(void *this,wchar_t *param_1,HRSRC param_2,LPCSTR param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  size_t sVar3;
  long lVar4;
  char *pcVar5;
  HMODULE pHVar6;
  undefined4 *_Memory;
  char acStack_448 [16];
  undefined4 local_438;
  void *local_434;
  HRSRC local_430;
  undefined4 *local_42c;
  LPCSTR local_428;
  HMODULE local_424;
  wchar_t *local_420;
  undefined1 *local_41c;
  undefined1 auStack_418 [1028];
  undefined1 *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x428;
  _Memory = (undefined4 *)0x0;
  local_430 = param_2;
  local_420 = param_1;
  local_428 = param_3;
  local_42c = (undefined4 *)0x0;
  local_438 = 0;
  local_41c = (undefined1 *)0x0;
  local_8 = 1;
  local_434 = this;
  if (param_1 != (wchar_t *)0x0) {
    sVar3 = _wcslen(param_1);
    local_424 = (HMODULE)(sVar3 + 1);
    lVar4 = ATL::AtlMultiply<int>((int *)&local_424,(int)local_424,2);
    pHVar6 = local_424;
    if (-1 < lVar4) {
      if (((int)local_424 < 0x401) &&
         (bVar2 = ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable((ulong)local_424), bVar2)) {
        local_14 = acStack_448;
        pcVar5 = acStack_448;
      }
      else {
        pcVar5 = (char *)FUN_454145c6(&local_42c,(int)pHVar6);
        _Memory = local_42c;
      }
      local_420 = (wchar_t *)AtlW2AHelper(pcVar5,local_420,(int)pHVar6,3);
      if (local_420 != (wchar_t *)0x0) {
        pHVar6 = LoadLibraryExA((LPCSTR)local_420,(HANDLE)0x0,0x60);
        if ((pHVar6 == (HMODULE)0x0) &&
           (local_424 = pHVar6, pHVar6 = LoadLibraryExA((LPCSTR)local_420,(HANDLE)0x0,2),
           pHVar6 == (HMODULE)0x0)) {
          local_424 = pHVar6;
          FUN_45402fed();
        }
        else {
          local_424 = pHVar6;
          local_430 = FindResourceA(pHVar6,(LPCSTR)local_430,local_428);
          if ((local_430 == (HRSRC)0x0) ||
             (local_428 = LoadResource(pHVar6,local_430), local_428 == (LPCSTR)0x0)) {
            FUN_45402fed();
          }
          else {
            local_420 = (wchar_t *)SizeofResource(pHVar6,local_430);
            if (local_420 <= (wchar_t *)((int)local_420 + 1U)) {
              local_8 = CONCAT31(local_8._1_3_,2);
              Allocate(&local_41c,(ulong)((int)local_420 + 1U));
              FUN_45426ebf();
              return;
            }
          }
          if (pHVar6 != (HMODULE)0x0) {
            FreeLibrary(pHVar6);
          }
        }
        if (local_41c != auStack_418) {
          FUN_454037d2(&local_41c);
        }
        while (_Memory != (undefined4 *)0x0) {
          puVar1 = (undefined4 *)*_Memory;
          FID_conflict__free(_Memory);
          _Memory = puVar1;
        }
        goto LAB_45426f76;
      }
    }
  }
  if (local_41c != auStack_418) {
    FUN_454037d2(&local_41c);
  }
  while (_Memory != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*_Memory;
    FID_conflict__free(_Memory);
    _Memory = puVar1;
  }
LAB_45426f76:
  FUN_4542a966();
  return;
}



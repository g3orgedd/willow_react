// Source: CLARiSOFT.exe @ 00e495c4; FUN_00e495c4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HDC __thiscall FUN_00e495c4(void *this,DEVMODEW *param_1)

{
  undefined4 *_Memory;
  char cVar1;
  LPCWSTR pwszDevice;
  HDC pHVar2;
  void *_Memory_00;
  undefined4 *local_18;
  void *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  pHVar2 = (HDC)0x0;
  local_18 = (undefined4 *)0x0;
  local_14[0] = (void *)0x0;
  local_8 = 1;
  cVar1 = FUN_00e496a7(&local_18,*(HANDLE *)this);
  _Memory = local_18;
  if (cVar1 == '\0') {
    cVar1 = FUN_00e49684(local_14,*(HANDLE *)this);
    _Memory_00 = local_14[0];
    if (cVar1 == '\0') goto LAB_00e49624;
    pwszDevice = *(LPCWSTR *)((int)local_14[0] + 4);
  }
  else {
    pwszDevice = (LPCWSTR)*local_18;
    _Memory_00 = (void *)0x0;
  }
  if (pwszDevice != (LPCWSTR)0x0) {
    pHVar2 = CreateDCW((LPCWSTR)0x0,pwszDevice,(LPCWSTR)0x0,param_1);
  }
LAB_00e49624:
  FID_conflict__free(_Memory_00);
  FID_conflict__free(_Memory);
  return pHVar2;
}



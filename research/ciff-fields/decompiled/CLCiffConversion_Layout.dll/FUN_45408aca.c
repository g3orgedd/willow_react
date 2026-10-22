// Source: CLCiffConversion_Layout.dll @ 45408aca; FUN_45408aca

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_45408aca(void *this,undefined4 *param_1)

{
  BOOL BVar1;
  char *pcVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  DWORD DVar5;
  _WIN32_FIND_DATAA local_148;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  SysFreeString((BSTR)*param_1);
  *param_1 = 0;
  if (*(int *)((int)this + 4) != -1) {
    BVar1 = FindNextFileA(*(HANDLE *)((int)this + 4),&local_148);
    if (BVar1 == 0) {
      DVar5 = GetLastError();
      if (DVar5 == 0x12) {
        FUN_454089b0((int)this);
      }
    }
    else {
      pcVar2 = FUN_454085e3();
      FUN_45402c99(param_1,pcVar2);
      sVar3 = _strlen(local_148.cFileName);
      if ((int)(sVar3 + 1) < 0x40000000) {
        pwVar4 = AtlA2WHelper((wchar_t *)&stack0xfffffeac,local_148.cFileName,sVar3 + 1,3);
      }
      else {
        pwVar4 = (wchar_t *)0x0;
      }
      FUN_45404d92(param_1,pwVar4);
    }
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



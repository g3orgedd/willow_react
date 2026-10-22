// Source: CLCiffConversion_Layout.dll @ 454089e8; FUN_454089e8

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void __thiscall FUN_454089e8(void *this,undefined4 *param_1)

{
  char *pcVar1;
  HANDLE pvVar2;
  size_t sVar3;
  wchar_t *pwVar4;
  _WIN32_FIND_DATAA local_24c;
  char local_10c [260];
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  FUN_454089b0((int)this);
  SysFreeString((BSTR)*param_1);
  *param_1 = 0;
  pcVar1 = FUN_454085e3();
  _strcpy_s(local_10c,0x104,pcVar1);
  _strcat_s(local_10c,0x104,"*.cpx");
  pvVar2 = FindFirstFileA(local_10c,&local_24c);
  *(HANDLE *)((int)this + 4) = pvVar2;
  if (pvVar2 != (HANDLE)0xffffffff) {
    pcVar1 = FUN_454085e3();
    FUN_45402c99(param_1,pcVar1);
    sVar3 = _strlen(local_24c.cFileName);
    if ((int)(sVar3 + 1) < 0x40000000) {
      pwVar4 = AtlA2WHelper((wchar_t *)&stack0xfffffda8,local_24c.cFileName,sVar3 + 1,3);
    }
    else {
      pwVar4 = (wchar_t *)0x0;
    }
    FUN_45404d92(param_1,pwVar4);
  }
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



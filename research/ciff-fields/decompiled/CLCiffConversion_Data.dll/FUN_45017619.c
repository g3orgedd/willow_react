// Source: CLCiffConversion_Data.dll @ 45017619; FUN_45017619

LSTATUS __thiscall FUN_45017619(void *this,HKEY param_1,LPCWSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
  if (*(int *)this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x45017658. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegDeleteKeyW(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleW(L"Advapi32.dll");
    pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedW");
    if (pFVar1 != (FARPROC)0x0) {
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*(undefined4 *)this,0);
      return iVar2;
    }
  }
  return 1;
}



// Source: CLCiffConversion_Layout.dll @ 4540a1ba; FUN_4540a1ba

LSTATUS __thiscall FUN_4540a1ba(void *this,HKEY param_1,LPCSTR param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  LSTATUS LVar3;
  
  if (*(int *)this == 0) {
    if (*(int *)((int)this + 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x4540a1fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      LVar3 = RegDeleteKeyA(param_1,param_2);
      return LVar3;
    }
  }
  else {
    hModule = GetModuleHandleA("Advapi32.dll");
    if ((hModule != (HMODULE)0x0) &&
       (pFVar1 = GetProcAddress(hModule,"RegDeleteKeyTransactedA"), pFVar1 != (FARPROC)0x0)) {
      iVar2 = (*pFVar1)(param_1,param_2,0,0,*(undefined4 *)this,0);
      return iVar2;
    }
  }
  return 1;
}



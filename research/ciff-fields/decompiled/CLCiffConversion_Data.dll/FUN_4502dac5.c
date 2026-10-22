// Source: CLCiffConversion_Data.dll @ 4502dac5; FUN_4502dac5

void __cdecl FUN_4502dac5(undefined4 param_1)

{
  BOOL BVar1;
  FARPROC pFVar2;
  HMODULE local_8;
  
  BVar1 = GetModuleHandleExW(0,L"mscoree.dll",&local_8);
  if (BVar1 != 0) {
    pFVar2 = GetProcAddress(local_8,"CorExitProcess");
    if (pFVar2 != (FARPROC)0x0) {
      (*pFVar2)(param_1);
    }
  }
  return;
}



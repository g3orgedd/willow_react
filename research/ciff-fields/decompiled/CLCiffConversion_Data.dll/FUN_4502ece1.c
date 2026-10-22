// Source: CLCiffConversion_Data.dll @ 4502ece1; FUN_4502ece1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4502ece1(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleW(L"kernel32.dll");
  pFVar1 = GetProcAddress(hModule,"FlsAlloc");
  DAT_45056f00 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"FlsFree");
  DAT_45056f04 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"FlsGetValue");
  DAT_45056f08 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"FlsSetValue");
  DAT_45056f0c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"InitializeCriticalSectionEx");
  DAT_45056f10 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CreateEventExW");
  _DAT_45056f14 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CreateSemaphoreExW");
  _DAT_45056f18 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"SetThreadStackGuarantee");
  DAT_45056f1c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CreateThreadpoolTimer");
  _DAT_45056f20 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"SetThreadpoolTimer");
  _DAT_45056f24 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"WaitForThreadpoolTimerCallbacks");
  _DAT_45056f28 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CloseThreadpoolTimer");
  _DAT_45056f2c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CreateThreadpoolWait");
  _DAT_45056f30 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"SetThreadpoolWait");
  _DAT_45056f34 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CloseThreadpoolWait");
  _DAT_45056f38 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"FlushProcessWriteBuffers");
  _DAT_45056f3c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"FreeLibraryWhenCallbackReturns");
  _DAT_45056f40 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetCurrentProcessorNumber");
  _DAT_45056f44 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetLogicalProcessorInformation");
  _DAT_45056f48 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CreateSymbolicLinkW");
  _DAT_45056f4c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"SetDefaultDllDirectories");
  _DAT_45056f50 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"EnumSystemLocalesEx");
  _DAT_45056f58 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"CompareStringEx");
  DAT_45056f54 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetDateFormatEx");
  _DAT_45056f5c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetLocaleInfoEx");
  _DAT_45056f60 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetTimeFormatEx");
  _DAT_45056f64 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetUserDefaultLocaleName");
  _DAT_45056f68 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"IsValidLocaleName");
  _DAT_45056f6c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"LCMapStringEx");
  DAT_45056f70 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetCurrentPackageId");
  DAT_45056f74 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetTickCount64");
  _DAT_45056f78 = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"GetFileInformationByHandleExW");
  _DAT_45056f7c = (uint)pFVar1 ^ DAT_450518d0;
  pFVar1 = GetProcAddress(hModule,"SetFileInformationByHandleW");
  _DAT_45056f80 = (uint)pFVar1 ^ DAT_450518d0;
  return;
}



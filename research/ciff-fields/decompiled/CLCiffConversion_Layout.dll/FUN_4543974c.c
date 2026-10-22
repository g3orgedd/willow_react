// Source: CLCiffConversion_Layout.dll @ 4543974c; FUN_4543974c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4543974c(void)

{
  HMODULE hModule;
  FARPROC pFVar1;
  
  hModule = GetModuleHandleW(L"kernel32.dll");
  pFVar1 = GetProcAddress(hModule,"FlsAlloc");
  DAT_45462700 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"FlsFree");
  DAT_45462704 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"FlsGetValue");
  DAT_45462708 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"FlsSetValue");
  DAT_4546270c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"InitializeCriticalSectionEx");
  DAT_45462710 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CreateEventExW");
  _DAT_45462714 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CreateSemaphoreExW");
  _DAT_45462718 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"SetThreadStackGuarantee");
  DAT_4546271c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CreateThreadpoolTimer");
  _DAT_45462720 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"SetThreadpoolTimer");
  _DAT_45462724 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"WaitForThreadpoolTimerCallbacks");
  _DAT_45462728 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CloseThreadpoolTimer");
  _DAT_4546272c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CreateThreadpoolWait");
  _DAT_45462730 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"SetThreadpoolWait");
  _DAT_45462734 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CloseThreadpoolWait");
  _DAT_45462738 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"FlushProcessWriteBuffers");
  _DAT_4546273c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"FreeLibraryWhenCallbackReturns");
  _DAT_45462740 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetCurrentProcessorNumber");
  _DAT_45462744 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetLogicalProcessorInformation");
  _DAT_45462748 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CreateSymbolicLinkW");
  _DAT_4546274c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"SetDefaultDllDirectories");
  _DAT_45462750 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"EnumSystemLocalesEx");
  _DAT_45462758 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"CompareStringEx");
  DAT_45462754 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetDateFormatEx");
  _DAT_4546275c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetLocaleInfoEx");
  _DAT_45462760 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetTimeFormatEx");
  _DAT_45462764 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetUserDefaultLocaleName");
  _DAT_45462768 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"IsValidLocaleName");
  _DAT_4546276c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"LCMapStringEx");
  DAT_45462770 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetCurrentPackageId");
  DAT_45462774 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetTickCount64");
  _DAT_45462778 = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"GetFileInformationByHandleExW");
  _DAT_4546277c = (uint)pFVar1 ^ DAT_4545d9f0;
  pFVar1 = GetProcAddress(hModule,"SetFileInformationByHandleW");
  _DAT_45462780 = (uint)pFVar1 ^ DAT_4545d9f0;
  return;
}



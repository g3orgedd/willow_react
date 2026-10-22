// Source: CLCiffConversion_Layout.dll @ 4540d932; FUN_4540d932

void __fastcall FUN_4540d932(undefined4 *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  *param_1 = CZFBFFontUtilities::vftable;
  EnterCriticalSection(lpCriticalSection);
  while (param_1[0xb] != 0) {
    FUN_4540dbfa(param_1,param_1[1]);
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  return;
}



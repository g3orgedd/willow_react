// Source: CLCSTextBasedField.dll @ 42467276; FUN_42467276

void __fastcall FUN_42467276(undefined4 *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xc);
  *param_1 = CZFBFFontUtilities::vftable;
  EnterCriticalSection(lpCriticalSection);
  while (param_1[0xb] != 0) {
    FUN_4246753e(param_1,param_1[1]);
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  return;
}



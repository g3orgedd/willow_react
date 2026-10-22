// Source: CiffMgr.dll @ 68103d03; FUN_68103d03

void __fastcall FUN_68103d03(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



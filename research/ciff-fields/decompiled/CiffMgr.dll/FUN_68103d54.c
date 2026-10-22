// Source: CiffMgr.dll @ 68103d54; FUN_68103d54

void __fastcall FUN_68103d54(int param_1)

{
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



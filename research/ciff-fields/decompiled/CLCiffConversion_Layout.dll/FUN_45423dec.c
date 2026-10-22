// Source: CLCiffConversion_Layout.dll @ 45423dec; FUN_45423dec

void __fastcall FUN_45423dec(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



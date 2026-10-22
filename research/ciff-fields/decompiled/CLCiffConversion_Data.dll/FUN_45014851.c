// Source: CLCiffConversion_Data.dll @ 45014851; FUN_45014851

void __fastcall FUN_45014851(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)*param_1);
    *(undefined1 *)(param_1 + 1) = 0;
  }
  return;
}



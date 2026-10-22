// Source: CLCiffConversion_Data.dll @ 45014972; FUN_45014972

void __fastcall FUN_45014972(int param_1)

{
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



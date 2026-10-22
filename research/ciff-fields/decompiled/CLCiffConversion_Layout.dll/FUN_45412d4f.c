// Source: CLCiffConversion_Layout.dll @ 45412d4f; FUN_45412d4f

void __fastcall FUN_45412d4f(int param_1)

{
  if (*(char *)(param_1 + 0x1c) != '\0') {
    *(undefined1 *)(param_1 + 0x1c) = 0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  }
  return;
}



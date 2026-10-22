// Source: CLCiffConversion_Layout.dll @ 4543ffcf; FUN_4543ffcf

void __cdecl FUN_4543ffcf(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_454612f8)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x40 + 0xc));
  return;
}



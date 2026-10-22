// Source: CLCiffConversion_Data.dll @ 4503650b; FUN_4503650b

void __cdecl FUN_4503650b(uint param_1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&DAT_45055ae0)[(int)param_1 >> 5] + (param_1 & 0x1f) * 0x40 + 0xc));
  return;
}



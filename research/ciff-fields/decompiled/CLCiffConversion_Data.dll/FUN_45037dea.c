// Source: CLCiffConversion_Data.dll @ 45037dea; ___dcrt_lowio_initialize_console_output

/* Library Function - Single Match
    ___dcrt_lowio_initialize_console_output
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2015 Release */

void ___dcrt_lowio_initialize_console_output(void)

{
  DAT_45052be4 = CreateFileW(L"CONOUT$",0x40000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
  return;
}



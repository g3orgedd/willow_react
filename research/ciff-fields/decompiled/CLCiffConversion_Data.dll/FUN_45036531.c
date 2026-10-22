// Source: CLCiffConversion_Data.dll @ 45036531; __putwch_nolock

/* Library Function - Single Match
    __putwch_nolock
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2015 Release */

wint_t __cdecl __putwch_nolock(wchar_t _WCh)

{
  BOOL BVar1;
  DWORD local_8;
  
  if (DAT_45052be4 == (HANDLE)0xfffffffe) {
    ___dcrt_lowio_initialize_console_output();
  }
  if ((DAT_45052be4 == (HANDLE)0xffffffff) ||
     (BVar1 = WriteConsoleW(DAT_45052be4,&_WCh,1,&local_8,(LPVOID)0x0), BVar1 == 0)) {
    _WCh = L'\xffff';
  }
  return _WCh;
}



// Source: CLCiffConversion_Layout.dll @ 45439a15; ___crtUnhandledException

/* Library Function - Single Match
    ___crtUnhandledException
   
   Library: Visual Studio 2012 Release */

LONG __cdecl ___crtUnhandledException(EXCEPTION_POINTERS *exceptionInfo)

{
  LONG LVar1;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);
  LVar1 = UnhandledExceptionFilter(exceptionInfo);
  return LVar1;
}



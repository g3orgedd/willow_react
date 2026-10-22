// Source: CLCiffConversion_Data.dll @ 45023985; ___raise_securityfailure

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_4505534c = IsDebuggerPresent();
  FUN_4502ebed();
  ___crtUnhandledException(param_1);
  if (DAT_4505534c == 0) {
    FUN_4502ebed();
  }
  ___crtTerminateProcess(0xc0000409);
  return;
}



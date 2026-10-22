// Source: CLCiffConversion_Layout.dll @ 4542ebd4; ___raise_securityfailure

/* Library Function - Single Match
    ___raise_securityfailure
   
   Library: Visual Studio 2012 Release */

void __cdecl ___raise_securityfailure(EXCEPTION_POINTERS *param_1)

{
  DAT_45460b6c = IsDebuggerPresent();
  FUN_45439cd2();
  ___crtUnhandledException(param_1);
  if (DAT_45460b6c == 0) {
    FUN_45439cd2();
  }
  ___crtTerminateProcess(0xc0000409);
  return;
}



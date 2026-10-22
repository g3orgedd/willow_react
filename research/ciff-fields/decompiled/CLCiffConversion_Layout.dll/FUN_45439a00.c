// Source: CLCiffConversion_Layout.dll @ 45439a00; ___crtTerminateProcess

/* Library Function - Single Match
    ___crtTerminateProcess
   
   Library: Visual Studio 2012 Release */

void __cdecl ___crtTerminateProcess(UINT uExitCode)

{
  HANDLE hProcess;
  
  hProcess = GetCurrentProcess();
  TerminateProcess(hProcess,uExitCode);
  return;
}



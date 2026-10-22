// Source: CLCiffConversion_Data.dll @ 4502ef95; ___crtTerminateProcess

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



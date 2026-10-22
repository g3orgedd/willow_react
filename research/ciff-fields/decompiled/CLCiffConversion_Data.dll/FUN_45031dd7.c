// Source: CLCiffConversion_Data.dll @ 45031dd7; __lock

/* Library Function - Single Match
    __lock
   
   Library: Visual Studio 2012 Release */

void __cdecl __lock(int _File)

{
  int iVar1;
  
  if ((&DAT_45052460)[_File * 2] == 0) {
    iVar1 = FUN_45031e5f(_File);
    if (iVar1 == 0) {
      __amsg_exit(0x11);
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_45052460)[_File * 2]);
  return;
}



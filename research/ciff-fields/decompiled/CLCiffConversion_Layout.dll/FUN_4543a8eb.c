// Source: CLCiffConversion_Layout.dll @ 4543a8eb; __lock

/* Library Function - Single Match
    __lock
   
   Library: Visual Studio 2012 Release */

void __cdecl __lock(int _File)

{
  int iVar1;
  
  if ((&DAT_4545e580)[_File * 2] == 0) {
    iVar1 = FUN_4543a973(_File);
    if (iVar1 == 0) {
      __amsg_exit(0x11);
    }
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_4545e580)[_File * 2]);
  return;
}



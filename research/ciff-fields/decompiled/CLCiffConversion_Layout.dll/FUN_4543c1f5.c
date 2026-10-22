// Source: CLCiffConversion_Layout.dll @ 4543c1f5; __lock_file2

/* Library Function - Single Match
    __lock_file2
   
   Library: Visual Studio 2012 Release */

void __cdecl __lock_file2(int _Index,void *_File)

{
  if (_Index < 0x14) {
    __lock(_Index + 0x10);
    *(uint *)((int)_File + 0xc) = *(uint *)((int)_File + 0xc) | 0x8000;
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((int)_File + 0x20));
  return;
}



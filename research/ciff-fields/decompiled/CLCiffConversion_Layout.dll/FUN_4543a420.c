// Source: CLCiffConversion_Layout.dll @ 4543a420; __ioterm

/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio 2012 Release */

void __cdecl __ioterm(void)

{
  uint uVar1;
  LPCRITICAL_SECTION p_Var2;
  uint *puVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  puVar3 = &DAT_454612f8;
  do {
    uVar1 = *puVar3;
    if (uVar1 != 0) {
      if (uVar1 < uVar1 + 0x800) {
        lpCriticalSection = (LPCRITICAL_SECTION)(uVar1 + 0xc);
        do {
          if (lpCriticalSection[-1].SpinCount != 0) {
            DeleteCriticalSection(lpCriticalSection);
          }
          p_Var2 = lpCriticalSection + 2;
          lpCriticalSection = (LPCRITICAL_SECTION)&lpCriticalSection[2].LockSemaphore;
        } while (&p_Var2->LockCount < (undefined1 *)(*puVar3 + 0x800));
      }
      FID_conflict__free((void *)*puVar3);
      *puVar3 = 0;
    }
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < 0x454613f8);
  return;
}



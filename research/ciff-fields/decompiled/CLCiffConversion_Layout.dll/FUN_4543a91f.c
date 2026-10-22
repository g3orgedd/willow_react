// Source: CLCiffConversion_Layout.dll @ 4543a91f; __mtdeletelocks

/* Library Function - Single Match
    __mtdeletelocks
   
   Library: Visual Studio 2012 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = &DAT_4545e580;
  puVar2 = &DAT_4545e580;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)*puVar2;
    if ((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (puVar2[1] != 1)) {
      DeleteCriticalSection(lpCriticalSection);
      FID_conflict__free(lpCriticalSection);
      *puVar2 = 0;
    }
    puVar2 = puVar2 + 2;
  } while ((int)puVar2 < 0x4545e6a0);
  do {
    if ((*piVar1 != 0) && (piVar1[1] == 1)) {
      DeleteCriticalSection((LPCRITICAL_SECTION)*piVar1);
    }
    piVar1 = piVar1 + 2;
  } while ((int)piVar1 < 0x4545e6a0);
  return;
}



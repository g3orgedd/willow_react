// Source: CLCiffConversion_Data.dll @ 45027e39; __invoke_watson

/* Library Function - Single Match
    __invoke_watson
   
   Library: Visual Studio 2012 Release */

void __cdecl
__invoke_watson(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,uint param_4,uintptr_t param_5)

{
  code *pcVar1;
  BOOL BVar2;
  
  BVar2 = IsProcessorFeaturePresent(0x17);
  if (BVar2 != 0) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  FUN_45027ccc(2,0xc0000417,1);
  ___crtTerminateProcess(0xc0000417);
  return;
}



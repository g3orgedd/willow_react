// Source: CLCiffConversion_Data.dll @ 4502f1b7; __GET_RTERRMSG

/* Library Function - Single Match
    __GET_RTERRMSG
   
   Library: Visual Studio 2012 Release */

wchar_t * __cdecl __GET_RTERRMSG(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == (&DAT_45042fb0)[uVar1 * 2]) {
      return *(wchar_t **)(&UNK_45042fb4 + uVar1 * 8);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x17);
  return (wchar_t *)0x0;
}



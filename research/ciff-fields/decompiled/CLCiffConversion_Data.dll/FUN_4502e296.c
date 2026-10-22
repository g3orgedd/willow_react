// Source: CLCiffConversion_Data.dll @ 4502e296; __errcode

/* Library Function - Single Match
    __errcode
   
   Library: Visual Studio 2019 Release */

int __cdecl __errcode(uint param_1)

{
  undefined4 uStack_8;
  
  if ((param_1 & 0x20) == 0) {
    if ((param_1 & 8) != 0) {
      return 1;
    }
    if ((param_1 & 4) == 0) {
      if ((param_1 & 1) == 0) {
        return (param_1 & 2) * 2;
      }
      uStack_8 = 3;
    }
    else {
      uStack_8 = 2;
    }
  }
  else {
    uStack_8 = 5;
  }
  return uStack_8;
}



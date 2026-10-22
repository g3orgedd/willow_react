// Source: CLCiffConversion_Data.dll @ 4502d6a9; __positive

/* Library Function - Single Match
    __positive
   
   Library: Visual Studio 2012 Release */

int __cdecl __positive(double *arg)

{
  double dVar1;
  
  dVar1 = *arg;
  if (!NAN(dVar1) && 0.0 < dVar1 != (dVar1 == 0.0)) {
    return 1;
  }
  return 0;
}



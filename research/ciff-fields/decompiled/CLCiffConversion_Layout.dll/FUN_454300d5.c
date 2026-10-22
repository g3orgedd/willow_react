// Source: CLCiffConversion_Layout.dll @ 454300d5; __getptd

/* Library Function - Single Match
    __getptd
   
   Library: Visual Studio 2012 Release */

_ptiddata __cdecl __getptd(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    __amsg_exit(0x10);
  }
  return p_Var1;
}



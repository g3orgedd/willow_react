// Source: CLCiffConversion_Data.dll @ 45027e98; __errno

/* Library Function - Single Match
    __errno
   
   Library: Visual Studio 2012 Release */

int * __cdecl __errno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (int *)&DAT_450521c8;
  }
  return &p_Var1->_terrno;
}



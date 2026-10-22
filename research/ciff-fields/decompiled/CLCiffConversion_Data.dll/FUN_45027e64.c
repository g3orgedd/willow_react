// Source: CLCiffConversion_Data.dll @ 45027e64; ___doserrno

/* Library Function - Single Match
    ___doserrno
   
   Library: Visual Studio 2012 Release */

ulong * __cdecl ___doserrno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (ulong *)&DAT_450521cc;
  }
  return &p_Var1->_tdoserrno;
}



// Source: CLCiffConversion_Layout.dll @ 45431fc5; __errno

/* Library Function - Single Match
    __errno
   
   Library: Visual Studio 2012 Release */

int * __cdecl __errno(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd_noexit();
  if (p_Var1 == (_ptiddata)0x0) {
    return (int *)&DAT_4545dbd0;
  }
  return &p_Var1->_terrno;
}



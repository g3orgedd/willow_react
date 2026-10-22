// Source: CLCiffConversion_Data.dll @ 45026cf5; FUN_45026cf5

void FUN_45026cf5(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (p_Var1->_unexpected != (code *)0x0) {
    (*p_Var1->_unexpected)();
  }
  terminate();
  return;
}



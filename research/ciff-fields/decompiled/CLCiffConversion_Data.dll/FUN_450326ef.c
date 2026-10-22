// Source: CLCiffConversion_Data.dll @ 450326ef; FUN_450326ef

uint FUN_450326ef(void)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  
  p_Var1 = __getptd();
  ptVar2 = p_Var1->ptlocinfo;
  if ((ptVar2 != (pthreadlocinfo)PTR_DAT_45051f94) && ((p_Var1->_ownlocale & DAT_45052058) == 0)) {
    ptVar2 = FUN_45026fdb();
  }
  return ptVar2->lc_codepage;
}



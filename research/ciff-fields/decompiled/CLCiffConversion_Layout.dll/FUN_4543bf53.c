// Source: CLCiffConversion_Layout.dll @ 4543bf53; FUN_4543bf53

uint FUN_4543bf53(void)

{
  _ptiddata p_Var1;
  pthreadlocinfo ptVar2;
  
  p_Var1 = __getptd();
  ptVar2 = p_Var1->ptlocinfo;
  if ((ptVar2 != (pthreadlocinfo)PTR_DAT_4545e264) && ((p_Var1->_ownlocale & DAT_4545e328) == 0)) {
    ptVar2 = FUN_45432a62();
  }
  return ptVar2->lc_codepage;
}



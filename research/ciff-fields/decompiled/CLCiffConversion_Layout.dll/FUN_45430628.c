// Source: CLCiffConversion_Layout.dll @ 45430628; FUN_45430628

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_45430628(void *param_1)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (p_Var1->_curexcspec != (void *)0x0) {
    _inconsistency();
  }
  FUN_45430368();
  p_Var1 = __getptd();
  p_Var1->_curexcspec = param_1;
                    /* WARNING: Subroutine does not return */
  FUN_4542a8e0((int *)0x0,(byte *)0x0);
}



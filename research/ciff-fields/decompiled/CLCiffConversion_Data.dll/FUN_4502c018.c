// Source: CLCiffConversion_Data.dll @ 4502c018; FUN_4502c018

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_4502c018(void *param_1)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (p_Var1->_curexcspec != (void *)0x0) {
    _inconsistency();
  }
  FUN_45026cf5();
  p_Var1 = __getptd();
  p_Var1->_curexcspec = param_1;
                    /* WARNING: Subroutine does not return */
  FUN_45022e41((int *)0x0,(byte *)0x0);
}



// Source: CLCiffConversion_Data.dll @ 45001ef3; FUN_45001ef3

undefined4 * __thiscall FUN_45001ef3(void *this,int *param_1)

{
  BSTR pOVar1;
  
  pOVar1 = FUN_4500361d(param_1);
  *(BSTR *)this = pOVar1;
  if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_45002735(-0x7ff8fff2);
  }
  return this;
}



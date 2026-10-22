// Source: CLCiffConversion_Data.dll @ 4500ae72; FUN_4500ae72

undefined4 * __thiscall FUN_4500ae72(void *this,LPCSTR param_1)

{
  BSTR pOVar1;
  
  SysFreeString(*(BSTR *)this);
  pOVar1 = FUN_4500b034(param_1,-1);
  *(BSTR *)this = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (param_1 != (LPCSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
    FUN_45002735(-0x7ff8fff2);
  }
  return this;
}



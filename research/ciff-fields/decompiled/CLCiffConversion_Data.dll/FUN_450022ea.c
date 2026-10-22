// Source: CLCiffConversion_Data.dll @ 450022ea; FUN_450022ea

undefined4 * __thiscall FUN_450022ea(void *this,int *param_1)

{
  BSTR pOVar1;
  
  if (*(BSTR *)this != (BSTR)*param_1) {
    SysFreeString(*(BSTR *)this);
    pOVar1 = FUN_4500361d(param_1);
    *(BSTR *)this = pOVar1;
    if ((*param_1 != 0) && (pOVar1 == (BSTR)0x0)) {
                    /* WARNING: Subroutine does not return */
      FUN_45002735(-0x7ff8fff2);
    }
  }
  return this;
}



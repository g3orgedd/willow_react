// Source: CiffHelper.dll @ 40803e97; FUN_40803e97

int * __thiscall FUN_40803e97(void *this,OLECHAR *param_1)

{
  BSTR pOVar1;
  
  if (param_1 != *(OLECHAR **)this) {
    SysFreeString(*(BSTR *)this);
    if (param_1 == (OLECHAR *)0x0) {
      *(undefined4 *)this = 0;
    }
    else {
      pOVar1 = SysAllocString(param_1);
      *(BSTR *)this = pOVar1;
      if (pOVar1 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_40802f26(-0x7ff8fff2);
      }
    }
  }
  return this;
}



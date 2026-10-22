// Source: CLCSTextBasedField.dll @ 42403b70; FUN_42403b70

int * __thiscall FUN_42403b70(void *this,OLECHAR *param_1)

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
        FUN_42403fdf(-0x7ff8fff2);
      }
    }
  }
  return this;
}



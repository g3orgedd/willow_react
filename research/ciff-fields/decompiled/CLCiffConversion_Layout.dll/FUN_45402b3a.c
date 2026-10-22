// Source: CLCiffConversion_Layout.dll @ 45402b3a; FUN_45402b3a

undefined4 * __thiscall FUN_45402b3a(void *this,OLECHAR *param_1)

{
  BSTR pOVar1;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  pOVar1 = SysAllocString(param_1);
  *(BSTR *)this = pOVar1;
  if ((pOVar1 == (BSTR)0x0) && (param_1 != (OLECHAR *)0x0)) {
                    /* WARNING: Subroutine does not return */
    _com_issue_error(-0x7ff8fff2);
  }
  return this;
}



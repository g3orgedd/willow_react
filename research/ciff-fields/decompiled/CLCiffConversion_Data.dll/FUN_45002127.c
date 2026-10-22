// Source: CLCiffConversion_Data.dll @ 45002127; FUN_45002127

undefined4 * __thiscall FUN_45002127(void *this,OLECHAR *param_1)

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



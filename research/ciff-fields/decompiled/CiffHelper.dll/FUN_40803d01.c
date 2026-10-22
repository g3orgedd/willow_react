// Source: CiffHelper.dll @ 40803d01; FUN_40803d01

undefined4 * __thiscall FUN_40803d01(void *this,OLECHAR *param_1)

{
  code *pcVar1;
  BSTR pOVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 1;
  pOVar2 = SysAllocString(param_1);
  *(BSTR *)this = pOVar2;
  if ((pOVar2 == (BSTR)0x0) && (param_1 != (OLECHAR *)0x0)) {
    _com_issue_error(-0x7ff8fff2);
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  return this;
}



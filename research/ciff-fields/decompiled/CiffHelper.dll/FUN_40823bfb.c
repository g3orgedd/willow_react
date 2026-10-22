// Source: CiffHelper.dll @ 40823bfb; FUN_40823bfb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_40823bfb(void *this,BSTR param_1,void *param_2)

{
  OLECHAR *pOVar1;
  
  if (*(int *)((int)this + 8) < 7) {
    pOVar1 = (OLECHAR *)FUN_40823639(0x4084d390,param_1,0,0x11);
    if (pOVar1 != (OLECHAR *)0x0) {
      FUN_40803e97(param_2,pOVar1);
    }
  }
  SysFreeString(param_1);
  return 0;
}



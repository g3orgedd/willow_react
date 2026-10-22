// Source: CiffHelper.dll @ 40803d82; FUN_40803d82

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_40803d82(void *this,OLECHAR *param_1)

{
  void *this_00;
  undefined4 *puVar1;
  
  this_00 = (void *)FUN_4082d9f3(0xc);
  puVar1 = (undefined4 *)0x0;
  if (this_00 != (void *)0x0) {
    puVar1 = FUN_40803d01(this_00,param_1);
  }
  *(undefined4 **)this = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    _com_issue_error(-0x7ff8fff2);
  }
  return this;
}



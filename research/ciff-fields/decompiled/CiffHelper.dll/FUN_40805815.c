// Source: CiffHelper.dll @ 40805815; FUN_40805815

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_40805815(void *this,undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  iVar1 = 0;
  local_8 = 0;
  local_14[0] = 0;
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
  }
  iVar1 = (**(code **)(*(int *)this + 0x50))(this,iVar1,local_14);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,this,(_GUID *)&DAT_4084a7f0);
  }
  *param_1 = local_14[0];
  if (param_2 != (int *)0x0) {
    FUN_40806039(param_2);
  }
  return param_1;
}



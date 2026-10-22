// Source: CLCiffConversion_Layout.dll @ 4540371c; FUN_4540371c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_4540371c(void *this,undefined4 *param_1,int *param_2,void **param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
  }
  iVar1 = (**(code **)(*(int *)this + 0x78))(this,iVar1,param_3);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,this,(_GUID *)&DAT_454476b0);
  }
  *param_1 = 0;
  if (param_2 != (int *)0x0) {
    FUN_45404021(param_2);
  }
  return param_1;
}



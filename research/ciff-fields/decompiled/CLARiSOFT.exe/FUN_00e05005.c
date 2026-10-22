// Source: CLARiSOFT.exe @ 00e05005; FUN_00e05005

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_00e05005(void *this,undefined4 *param_1,int *param_2,void **param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
  }
  iVar1 = (**(code **)(*(int *)this + 0x78))(this,iVar1,param_3);
  if (iVar1 < 0) {
    _com_issue_errorex(iVar1,this,(_GUID *)&DAT_00efcb68);
  }
  *param_1 = 0;
  if (param_2 != (int *)0x0) {
    FUN_00e06166(param_2);
  }
  return param_1;
}



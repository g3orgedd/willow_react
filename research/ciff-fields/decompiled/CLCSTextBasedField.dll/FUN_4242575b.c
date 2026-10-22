// Source: CLCSTextBasedField.dll @ 4242575b; FUN_4242575b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_4242575b(void *this,BSTR param_1,int param_2)

{
  UINT UVar1;
  int iVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_14[0] = 0;
  local_8 = 0;
  (**(code **)(**(int **)this + 0x44))(*(int **)this,local_14);
  UVar1 = SysStringLen(param_1);
  iVar2 = UVar1 * local_14[0];
  if (param_2 != 0) {
    iVar2 = iVar2 * 2;
  }
  SysFreeString(param_1);
  return iVar2;
}



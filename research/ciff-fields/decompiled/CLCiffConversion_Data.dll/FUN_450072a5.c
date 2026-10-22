// Source: CLCiffConversion_Data.dll @ 450072a5; FUN_450072a5

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_450072a5(void *this,int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_30;
  void *pvStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  iStack_28 = 0;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    iStack_28 = *param_1;
  }
  uStack_24 = param_2;
  puVar2 = &uStack_30;
  uStack_30 = 0x450072cb;
  pvStack_2c = this;
  iVar1 = (**(code **)(*(int *)this + 0x5c))();
  if (iVar1 < 0) {
    puVar2[-1] = &DAT_4503d540;
    puVar2[-2] = this;
    puVar2[-3] = iVar1;
    puVar2[-4] = 0x450072dd;
    _com_issue_errorex(puVar2[-3],(IUnknown *)puVar2[-2],(_GUID *)puVar2[-1]);
  }
  if (param_1 != (int *)0x0) {
    puVar2[-1] = 0x450072e9;
    FUN_4500419b(param_1);
  }
  puVar2[-1] = 0x450072f0;
  return iVar1;
}



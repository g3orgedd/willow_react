// Source: CLARiSOFT.exe @ 00e061dd; FUN_00e061dd

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_00e061dd(void *this,int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_2c;
  void *pvStack_28;
  int iStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  iStack_24 = 0;
  local_8 = 0;
  if (param_1 != (int *)0x0) {
    iStack_24 = *param_1;
  }
  puVar2 = &uStack_2c;
  uStack_2c = 0xe06200;
  pvStack_28 = this;
  iVar1 = (**(code **)(*(int *)this + 0x3c))();
  if (iVar1 < 0) {
    puVar2[-1] = &DAT_00efcb58;
    puVar2[-2] = this;
    puVar2[-3] = iVar1;
    puVar2[-4] = 0xe06212;
    _com_issue_errorex(puVar2[-3],(IUnknown *)puVar2[-2],(_GUID *)puVar2[-1]);
  }
  if (param_1 != (int *)0x0) {
    puVar2[-1] = 0xe0621e;
    FUN_00e06166(param_1);
  }
  puVar2[-1] = 0xe06225;
  return iVar1;
}



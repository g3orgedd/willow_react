// Source: CLCiffConversion_Data.dll @ 45007233; FUN_45007233

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Unable to track spacebase fully for stack */

int __thiscall FUN_45007233(void *this,int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uStack_34;
  void *pvStack_30;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0;
  local_8 = 1;
  if (param_2 == (int *)0x0) {
    iStack_28 = 0;
  }
  else {
    iStack_28 = *param_2;
  }
  if (param_1 == (int *)0x0) {
    iStack_2c = 0;
  }
  else {
    iStack_2c = *param_1;
  }
  uStack_24 = param_3;
  puVar2 = &uStack_34;
  uStack_34 = 0x4500726d;
  pvStack_30 = this;
  iVar1 = (**(code **)(*(int *)this + 0x6c))();
  if (iVar1 < 0) {
    puVar2[-1] = &DAT_4503d540;
    puVar2[-2] = this;
    puVar2[-3] = iVar1;
    puVar2[-4] = 0x4500727f;
    _com_issue_errorex(puVar2[-3],(IUnknown *)puVar2[-2],(_GUID *)puVar2[-1]);
  }
  if (param_1 != (int *)0x0) {
    puVar2[-1] = 0x4500728b;
    FUN_4500419b(param_1);
  }
  if (param_2 != (int *)0x0) {
    puVar2[-1] = 0x4500729b;
    FUN_4500419b(param_2);
  }
  puVar2[-1] = 0x450072a2;
  return iVar1;
}



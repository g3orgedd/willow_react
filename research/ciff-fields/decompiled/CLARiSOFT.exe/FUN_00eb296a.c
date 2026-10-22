// Source: CLARiSOFT.exe @ 00eb296a; FUN_00eb296a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_00eb296a(void *this,int *param_1,int *param_2,BSTR param_3,BSTR param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  BSTR pOVar4;
  BSTR pOVar5;
  
  pOVar5 = this;
  FUN_00e03ab8(&stack0xffffffd8,(int *)&param_4);
  pOVar4 = param_3;
  if (param_3 != (BSTR)0x0) {
    (**(code **)(*(int *)param_3 + 4))();
  }
  piVar2 = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 4))(param_2);
  }
  piVar3 = param_1;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  iVar1 = FUN_00eb4698(piVar3,piVar2,pOVar4,pOVar5);
  if (iVar1 == 2) {
    iVar1 = 0x92;
  }
  else {
    if (iVar1 != 3) goto LAB_00eb29f0;
    iVar1 = 0x93;
  }
  piVar2 = FUN_00e4cac1(*(void **)((int)this + 0xc),iVar1);
  FUN_00eafbc7(*(void **)((int)this + 0x10),(CComBSTR *)&param_4,piVar2);
LAB_00eb29f0:
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  if (param_3 != (BSTR)0x0) {
    (**(code **)(*(int *)param_3 + 8))();
  }
  SysFreeString(param_4);
  return 0;
}



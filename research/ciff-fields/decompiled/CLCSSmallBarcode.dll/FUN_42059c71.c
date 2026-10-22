// Source: CLCSSmallBarcode.dll @ 42059c71; FUN_42059c71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_42059c71(void *this,undefined4 param_1,int *param_2,BSTR param_3,undefined4 *param_4)

{
  BSTR pOVar1;
  int iVar2;
  UINT UVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x42059c7d;
  FUN_42002e41(local_14);
  pOVar1 = param_3;
  local_8 = 0;
  (**(code **)(*(int *)this + 0x18))(param_3);
  piVar5 = (int *)*param_2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))(piVar5);
  }
  iVar2 = FUN_42003ac3((int)*(double *)((int)this + 0x30),1.4013e-45,piVar5);
  (**(code **)(**(int **)pOVar1 + 0x84))(*(int **)pOVar1,iVar2);
  piVar5 = (int *)*param_2;
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 4))(piVar5);
  }
  iVar2 = FUN_42003ac3((int)*(double *)((int)this + 0x38),1.4013e-45,piVar5);
  (**(code **)(**(int **)pOVar1 + 0x84))(*(int **)pOVar1,iVar2);
  puVar4 = param_4;
  (**(code **)(*(int *)*param_4 + 0x54))((int *)*param_4,*(undefined4 *)((int)this + 0x1c));
  (**(code **)(*(int *)*puVar4 + 0x5c))((int *)*puVar4,*(undefined4 *)((int)this + 0x20));
  (**(code **)(*(int *)*puVar4 + 100))((int *)*puVar4,*(undefined4 *)((int)this + 0x20));
  piVar5 = (int *)*puVar4;
  UVar3 = SysStringLen(*(BSTR *)((int)this + 0x20));
  (**(code **)(*piVar5 + 0x98))(piVar5,UVar3);
  (**(code **)(**(int **)pOVar1 + 0x9c))(*(int **)pOVar1,*(undefined4 *)((int)this + 0x20));
  piVar5 = *(int **)pOVar1;
  puVar4 = FUN_42002eae(&param_3,L"OCRB");
  local_8._0_1_ = 1;
  (**(code **)(*piVar5 + 0xd4))(piVar5,*puVar4);
  local_8 = (uint)local_8._1_3_ << 8;
  SysFreeString(param_3);
  (**(code **)(**(int **)pOVar1 + 0xdc))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0xe4))(*(int **)pOVar1,10);
  (**(code **)(**(int **)pOVar1 + 0x28))(*(int **)pOVar1,1);
  (**(code **)(**(int **)pOVar1 + 0x48))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0x50))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0x40))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0x58))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0x94))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0xb4))(*(int **)pOVar1,1000);
  (**(code **)(**(int **)pOVar1 + 0xc4))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0xcc))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0x104))(*(int **)pOVar1,0);
  (**(code **)(**(int **)pOVar1 + 0x10c))(*(int **)pOVar1,1);
  local_8 = 0xffffffff;
  FUN_420030e8(local_14);
  return 0;
}



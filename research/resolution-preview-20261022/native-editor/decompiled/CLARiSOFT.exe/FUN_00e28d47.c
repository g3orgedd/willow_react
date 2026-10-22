// Source: CLARiSOFT.exe @ 00e28d47; FUN_00e28d47

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e28d47(void *this,int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  BSTR extraout_ECX;
  BSTR pOVar4;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0xe28d53;
  piVar3 = FUN_00e2f82e((int)this);
  local_14[0] = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 4))();
  }
  local_8 = 0;
  if (piVar3 != (int *)0x0) {
    piVar1 = (int *)((int)this + 0x15c);
    piVar2 = (int *)*piVar1;
    if (piVar2 != (int *)0x0) {
      *piVar1 = 0;
      (**(code **)(*piVar2 + 8))();
    }
    FUN_00e2f762((int *)local_14,param_1,piVar1);
  }
  FUN_00e3532f((int)this);
  (**(code **)(**(int **)((int)this + 0x15c) + 0x1c))();
  pOVar4 = extraout_ECX;
  FUN_00e03ab8(&stack0xffffffcc,param_1);
  FUN_00e350dc(pOVar4);
  local_8 = 0xffffffff;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))();
  }
  return;
}



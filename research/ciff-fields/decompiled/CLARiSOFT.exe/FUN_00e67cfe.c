// Source: CLARiSOFT.exe @ 00e67cfe; FUN_00e67cfe

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void __thiscall FUN_00e67cfe(void *this,int param_1,int *param_2,undefined4 param_3)

{
  void *this_00;
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)((int)this + 0x14);
  if (0 < iVar2) {
    puVar1 = (undefined4 *)**(undefined4 **)((int)this + 0x10);
    do {
      this_00 = (void *)puVar1[2];
      puVar1 = (undefined4 *)*puVar1;
      piVar3 = param_2;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 4))(param_2,param_2,param_3);
      }
      FUN_00e62c90(this_00,param_1,piVar3);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return;
}



// Source: CLARiSOFT.exe @ 00e09d71; FUN_00e09d71

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 * __thiscall FUN_00e09d71(void *this,int *param_1,int *param_2)

{
  int *this_00;
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piStack_38;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  this_00 = (int *)((int)this + 8);
  *this_00 = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  uVar1 = FUN_00e0d1d2();
  *(undefined4 *)((int)this + 0x10) = uVar1;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  uVar1 = FUN_00e0d154();
  *(undefined4 *)((int)this + 0x18) = uVar1;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  uVar1 = FUN_00e0d17e();
  *(undefined4 *)((int)this + 0x20) = uVar1;
  *(undefined4 *)((int)this + 0x28) = 0;
  piStack_38 = (int *)0xe09dea;
  FUN_00e11de5(this_00,(int *)&param_2);
  piStack_38 = (int *)0xe09df6;
  FUN_00e11de5((void *)((int)this + 0xc),(int *)&param_1);
  if (*this_00 != 0) {
    FUN_00e09bd0(&piStack_38,(int *)((int)this + 0x20));
    FUN_00e09b75(&stack0xffffffc0,(int *)((int)this + 0x18));
    piVar3 = (int *)((int)this + 0x10);
    piVar2 = (int *)*this_00;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))(piVar2);
    }
    FUN_00e0ab01(this,piVar2,piVar3);
    piStack_38 = (int *)*this_00;
    (**(code **)(*piStack_38 + 0x5c))();
    (**(code **)(*(int *)*this_00 + 0x44))();
  }
  if (param_1 != (int *)0x0) {
    piStack_38 = (int *)0xe09e6a;
    (**(code **)(*param_1 + 8))();
  }
  if (param_2 != (int *)0x0) {
    piStack_38 = (int *)0xe09e7b;
    (**(code **)(*param_2 + 8))();
  }
  return this;
}



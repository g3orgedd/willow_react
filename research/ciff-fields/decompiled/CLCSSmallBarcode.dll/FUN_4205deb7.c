// Source: CLCSSmallBarcode.dll @ 4205deb7; FUN_4205deb7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall
FUN_4205deb7(void *this,int *param_1,undefined4 *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x4205dec3;
  FUN_42002e41(&local_20);
  piVar2 = param_4;
  local_8 = 0;
  local_18 = 0x32;
  local_14[0] = 0x15;
  if (*(int *)((int)this + 0x40) != 0) {
    CComQIPtr<>(&param_4,(undefined4 *)*param_4);
    local_8._0_1_ = 1;
    (**(code **)(**(int **)((int)this + 0x40) + 4))(*piVar2,*param_2,*param_3);
    FUN_4203407d(*(void **)((int)this + 0x40),(int *)&param_4,local_14);
    (**(code **)(**(int **)((int)this + 0x40) + 8))();
    (**(code **)(*param_4 + 0x15c))(param_4,&local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    if (param_4 != (int *)0x0) {
      (**(code **)(*param_4 + 8))(param_4);
    }
  }
  piVar2 = (int *)*piVar2;
  local_1c = 0;
  (**(code **)(*piVar2 + 0x108))(piVar2,&local_1c);
  if (local_1c == 1) {
    local_14[0] = local_14[0] + 8;
  }
  piVar2 = (int *)*param_3;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  iVar1 = FUN_42003ac3(local_14[0] * local_18,1.4013e-45,piVar2);
  *param_1 = iVar1;
  piVar2 = (int *)*param_3;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  iVar1 = FUN_42003ac3(local_14[0] * local_18,0.0,piVar2);
  local_8 = 0xffffffff;
  param_1[1] = iVar1;
  FUN_420030e8(&local_20);
  return 0;
}



// Source: CLCSTextBasedField.dll @ 42421180; FUN_42421180

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_42421180(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x4242118c;
  piVar1 = (int *)*param_1;
  local_14[0] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  local_8 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xdc))(piVar1,local_14);
  }
  uVar2 = local_14[0];
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



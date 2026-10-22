// Source: CLCSBarcodeField.dll @ 4144a1c7; FUN_4144a1c7

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_4144a1c7(void *this,HDC param_1)

{
  int *piVar1;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x4144a1d3;
  piVar1 = *(int **)((int)this + 0xf4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  local_8 = 0;
  local_14[0] = 1;
  (**(code **)(**(int **)((int)this + 0xf8) + 0x54))(*(int **)((int)this + 0xf8),local_14);
  FUN_4144ae9a(this,param_1,*(undefined4 **)((int)this + 0xf8),piVar1,local_14[0]);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



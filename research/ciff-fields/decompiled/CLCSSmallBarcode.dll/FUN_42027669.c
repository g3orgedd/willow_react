// Source: CLCSSmallBarcode.dll @ 42027669; FUN_42027669

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __thiscall FUN_42027669(void *this,undefined4 param_1)

{
  int *piVar1;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x42027675;
  piVar1 = *(int **)((int)this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  local_8 = 0;
  local_14[0] = 1;
  (**(code **)(**(int **)((int)this + 8) + 0x54))(*(int **)((int)this + 8),local_14);
  (**(code **)(*(int *)this + 0x14))(param_1,*(undefined4 *)((int)this + 8),piVar1,0,local_14[0]);
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



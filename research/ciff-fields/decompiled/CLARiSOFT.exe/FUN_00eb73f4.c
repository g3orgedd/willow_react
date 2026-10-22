// Source: CLARiSOFT.exe @ 00eb73f4; FUN_00eb73f4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 __fastcall FUN_00eb73f4(int param_1)

{
  int *piVar1;
  undefined1 uVar2;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0xeb7400;
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  uVar2 = 0;
  local_8 = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x294))(piVar1,local_14);
    if ((local_14[0] == -1) || (0 < local_14[0])) {
      uVar2 = 1;
    }
  }
  local_8 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return uVar2;
}



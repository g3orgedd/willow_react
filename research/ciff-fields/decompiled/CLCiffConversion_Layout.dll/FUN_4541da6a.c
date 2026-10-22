// Source: CLCiffConversion_Layout.dll @ 4541da6a; FUN_4541da6a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_4541da6a(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x4541da76;
  CComQIPtr<>(local_14,*(undefined4 **)(param_1 + 4));
  local_8 = 0;
  local_18 = 0;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 0x134))(local_14[0],&local_18);
  }
  uVar1 = local_18;
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return uVar1;
}



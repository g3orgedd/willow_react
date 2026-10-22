// Source: CLCiffConversion_Layout.dll @ 4541ce0c; FUN_4541ce0c

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 __fastcall FUN_4541ce0c(int param_1)

{
  undefined4 uVar1;
  int *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x4541ce18;
  CComQIPtr<>(&local_18,*(undefined4 **)(param_1 + 4));
  local_14[0] = 0;
  local_8 = 0;
  (**(code **)(*local_18 + 0x168))(local_18,local_14);
  uVar1 = local_14[0];
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  return uVar1;
}



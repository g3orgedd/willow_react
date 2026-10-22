// Source: CiffMgr.dll @ 68116a45; FUN_68116a45

undefined4 FUN_68116a45(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x28);
    uVar1 = 0;
  }
  return uVar1;
}



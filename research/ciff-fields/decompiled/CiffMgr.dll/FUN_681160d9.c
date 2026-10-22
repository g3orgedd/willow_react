// Source: CiffMgr.dll @ 681160d9; FUN_681160d9

undefined4 FUN_681160d9(int param_1)

{
  undefined4 uVar1;
  
  if (*(undefined4 **)(param_1 + 8) == (undefined4 *)0x0) {
    uVar1 = 0x80004005;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = **(undefined4 **)(param_1 + 8);
    uVar1 = 0;
  }
  return uVar1;
}



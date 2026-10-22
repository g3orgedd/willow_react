// Source: CiffMgr.dll @ 6810a1cb; FUN_6810a1cb

undefined4 FUN_6810a1cb(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 2;
    uVar1 = 0;
  }
  return uVar1;
}



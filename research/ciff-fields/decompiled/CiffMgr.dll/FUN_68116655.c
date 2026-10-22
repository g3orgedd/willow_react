// Source: CiffMgr.dll @ 68116655; FUN_68116655

undefined4 FUN_68116655(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x2c);
    uVar1 = 0;
  }
  return uVar1;
}



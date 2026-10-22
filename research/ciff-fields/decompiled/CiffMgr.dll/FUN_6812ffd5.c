// Source: CiffMgr.dll @ 6812ffd5; FUN_6812ffd5

undefined4 FUN_6812ffd5(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x3c);
    uVar1 = 0;
  }
  return uVar1;
}



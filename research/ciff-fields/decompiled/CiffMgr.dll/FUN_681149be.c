// Source: CiffMgr.dll @ 681149be; FUN_681149be

undefined4 FUN_681149be(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = FUN_681026d0((void *)(param_1 + 0x28),param_2);
  }
  return uVar1;
}



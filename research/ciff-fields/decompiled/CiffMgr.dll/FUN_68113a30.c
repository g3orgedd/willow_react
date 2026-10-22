// Source: CiffMgr.dll @ 68113a30; FUN_68113a30

undefined4 FUN_68113a30(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_2 = 0;
    uVar1 = 0;
  }
  return uVar1;
}



// Source: CiffMgr.dll @ 6810c905; FUN_6810c905

undefined4 FUN_6810c905(undefined1 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_1 = DAT_68167068;
    uVar1 = 0;
  }
  return uVar1;
}



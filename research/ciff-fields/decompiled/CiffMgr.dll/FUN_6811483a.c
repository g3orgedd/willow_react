// Source: CiffMgr.dll @ 6811483a; FUN_6811483a

void FUN_6811483a(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = FUN_6811493c(*(byte *)(uVar2 + param_1),(uint *)&DAT_6814b0d0,5);
      *(short *)(param_3 + uVar2 * 2) = (short)uVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  *(undefined2 *)(param_3 + uVar2 * 2) = 0;
  return;
}



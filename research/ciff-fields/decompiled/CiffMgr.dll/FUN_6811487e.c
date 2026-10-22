// Source: CiffMgr.dll @ 6811487e; FUN_6811487e

void FUN_6811487e(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = FUN_6811493c(*(byte *)(uVar2 + param_1) >> 4,(uint *)&PTR_6814b0b8,2);
      *(short *)(param_3 + iVar3 * 2) = (short)uVar1;
      uVar1 = FUN_6811493c(*(byte *)(uVar2 + param_1) & 0xf,(uint *)&PTR_6814b0b8,2);
      *(short *)(param_3 + 2 + iVar3 * 2) = (short)uVar1;
      iVar3 = iVar3 + 2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  *(undefined2 *)(param_3 + iVar3 * 2) = 0;
  return;
}



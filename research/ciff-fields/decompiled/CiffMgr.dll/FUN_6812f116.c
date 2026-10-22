// Source: CiffMgr.dll @ 6812f116; FUN_6812f116

int FUN_6812f116(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  
  if (param_1 == (ushort *)0x0) {
    iVar2 = 0;
  }
  else {
    uVar3 = (uint)*param_1;
    puVar5 = param_1 + 1;
    if ((*param_1 == 0x2d) || (uVar4 = uVar3, uVar3 == 0x2b)) {
      uVar4 = (uint)*puVar5;
      puVar5 = param_1 + 2;
    }
    iVar2 = 0;
    while ((0x2f < (ushort)uVar4 && ((ushort)uVar4 < 0x3a))) {
      iVar2 = iVar2 * 10 + (uVar4 - 0x30);
      uVar1 = *puVar5;
      puVar5 = puVar5 + 1;
      uVar4 = (uint)uVar1;
    }
    if (uVar3 == 0x2d) {
      iVar2 = -iVar2;
    }
  }
  return iVar2;
}



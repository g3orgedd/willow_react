// Source: CLCSSmallBarcode.dll @ 4200b153; FUN_4200b153

void FUN_4200b153(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  
  iVar4 = param_3 + -1 + param_2;
  bVar2 = (byte)param_2 & 0x1f;
  bVar3 = (byte)iVar4 & 0x1f;
  iVar5 = (int)((param_2 >> 0x1f & 0x1fU) + param_2) >> 5;
  iVar4 = (int)((iVar4 >> 0x1f & 0x1fU) + iVar4) >> 5;
  if (iVar5 == iVar4) {
    puVar6 = (uint *)(param_1 + iVar5 * 4);
    *puVar6 = *puVar6 & (~((0x80000000U >> bVar2) * 2 - 1) | 0x7fffffff >> bVar3);
  }
  else {
    puVar6 = (uint *)(param_1 + iVar5 * 4);
    *puVar6 = *puVar6 & ~((0x80000000U >> bVar2) * 2 - 1);
    puVar1 = (uint *)(param_1 + iVar4 * 4);
    *puVar1 = *puVar1 & 0x7fffffff >> bVar3;
    iVar4 = iVar4 - iVar5;
    while (iVar4 = iVar4 + -1, iVar4 != 0) {
      puVar6 = puVar6 + 1;
      *puVar6 = 0;
    }
  }
  return;
}



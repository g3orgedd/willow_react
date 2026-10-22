// Source: CLCSSmallBarcode.dll @ 4200b4a1; FUN_4200b4a1

void __thiscall FUN_4200b4a1(void *this,uint *param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint local_18;
  uint local_14;
  int local_10;
  void *local_c;
  int *local_8;
  
  iVar7 = (int)param_4 + param_3;
  local_c = this;
  uVar5 = (0x80000000U >> ((byte)param_3 & 0x1f)) * 2 - 1;
  param_3 = 0xffffffff >> ((byte)iVar7 & 0x1f);
  iVar9 = *(int *)((int)this + 0x94);
  iVar1 = *(int *)((int)this + 0x88);
  local_18 = param_3;
  local_14 = ~uVar5;
  iVar2 = *(int *)((int)this + 0x78);
  iVar8 = (int)((iVar7 >> 0x1f & 0x1fU) + iVar7) >> 5;
  local_10 = iVar8 + -1;
  local_8 = (int *)((int)this + 4);
  iVar7 = *(int *)((int)this + 4);
  iVar3 = *(int *)((int)this + 0xa0);
  *param_1 = *param_1 & uVar5;
  puVar6 = (uint *)(iVar3 + (((iVar9 - iVar1) + -1) * iVar7 + param_2) * 4);
  if (~param_3 != 0) {
    param_1[iVar8] = param_1[iVar8] & ~param_3;
    iVar8 = iVar8 + 1;
  }
  iVar8 = iVar8 + -1;
  param_4 = puVar6;
  if (-1 < iVar8) {
    puVar10 = param_1 + iVar8;
    do {
      FUN_4200bd86((int)puVar10,(int)&param_3);
      *puVar10 = param_3;
      puVar10 = puVar10 + -1;
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
  }
  uVar5 = 0;
  uVar11 = 0;
  do {
    *(undefined1 *)((int)&param_3 + uVar11) = *(undefined1 *)((int)&local_14 + (~uVar11 & 3));
    uVar4 = param_3;
    uVar11 = uVar11 + 1;
  } while ((int)uVar11 < 4);
  do {
    *(undefined1 *)((int)&param_3 + uVar5) = *(undefined1 *)((int)&local_18 + (~uVar5 & 3));
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 4);
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    *puVar6 = *puVar6 & uVar4;
    *puVar6 = *puVar6 | *param_1;
    puVar6 = puVar6 + -*local_8;
  }
  while (local_10 = local_10 + -1, -1 < local_10) {
    iVar9 = *(int *)((int)local_c + 0x78);
    param_4 = param_4 + 1;
    param_1 = param_1 + 1;
    puVar6 = param_4;
    while (iVar9 = iVar9 + -1, -1 < iVar9) {
      *puVar6 = *param_1;
      puVar6 = puVar6 + -*local_8;
    }
  }
  if (param_3 != 0xffffffff) {
    puVar6 = param_4 + 1;
    iVar9 = *(int *)((int)local_c + 0x78);
    while (iVar9 = iVar9 + -1, -1 < iVar9) {
      *puVar6 = *puVar6 & param_3;
      *puVar6 = *puVar6 | param_1[1];
      puVar6 = puVar6 + -*local_8;
    }
  }
  return;
}



// Source: CLCSSmallBarcode.dll @ 42030ed2; FUN_42030ed2

void __thiscall
FUN_42030ed2(void *this,uint *param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint local_20;
  uint *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  uint *local_c;
  int local_8;
  
  local_10 = this;
  iVar3 = FUN_4202c062(this,param_6);
  puVar10 = param_1;
  iVar4 = param_4 + param_3;
  uVar6 = (0x80000000U >> ((byte)param_3 & 0x1f)) * 2 - 1;
  local_18 = 0xffffffff >> ((byte)iVar4 & 0x1f);
  local_20 = local_18;
  local_14 = param_6 - iVar3;
  local_1c = (uint *)~uVar6;
  iVar5 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
  local_8 = iVar5 + -1;
  iVar4 = *(int *)((int)local_10 + 0x20);
  iVar1 = *(int *)((int)local_10 + 0x14);
  iVar2 = *(int *)((int)local_10 + 0x2c);
  *param_1 = *param_1 & uVar6;
  puVar7 = (uint *)(iVar2 + (((iVar4 - param_5) + -1) * iVar1 + param_2) * 4);
  local_c = puVar7;
  if (~local_18 != 0) {
    param_1[iVar5] = param_1[iVar5] & ~local_18;
    iVar5 = iVar5 + 1;
  }
  iVar5 = iVar5 + -1;
  if (-1 < iVar5) {
    puVar9 = param_1 + iVar5;
    do {
      FUN_4200bd86((int)puVar9,(int)&param_1);
      *puVar9 = (uint)param_1;
      puVar9 = puVar9 + -1;
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  uVar6 = 0;
  uVar8 = 0;
  do {
    *(undefined1 *)((int)&param_1 + uVar8) = *(undefined1 *)((int)&local_1c + (~uVar8 & 3));
    puVar9 = param_1;
    uVar8 = uVar8 + 1;
  } while ((int)uVar8 < 4);
  local_1c = param_1;
  do {
    *(undefined1 *)((int)&param_1 + uVar6) = *(undefined1 *)((int)&local_20 + (~uVar6 & 3));
    uVar6 = uVar6 + 1;
    iVar4 = local_14;
  } while ((int)uVar6 < 4);
  while (iVar1 = local_8, -1 < iVar4 + -1) {
    *puVar7 = *puVar7 & (uint)puVar9;
    *puVar7 = *puVar7 | *puVar10;
    puVar7 = puVar7 + -*(int *)((int)local_10 + 0x14);
    iVar4 = iVar4 + -1;
  }
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    local_c = local_c + 1;
    puVar10 = puVar10 + 1;
    puVar7 = local_c;
    iVar4 = local_14;
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      *puVar7 = *puVar10;
      puVar7 = puVar7 + -*(int *)((int)local_10 + 0x14);
    }
  }
  if (param_1 != (uint *)0xffffffff) {
    puVar7 = local_c + 1;
    iVar4 = local_14;
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      *puVar7 = *puVar7 & (uint)param_1;
      *puVar7 = *puVar7 | puVar10[1];
      puVar7 = puVar7 + -*(int *)((int)local_10 + 0x14);
    }
  }
  if (iVar3 != 0) {
    FUN_42027a20(local_10,(uint *)(*(int *)((int)local_10 + 0x2c) +
                                  ((iVar3 + -1 +
                                   ((*(int *)((int)local_10 + 0x20) - param_5) - param_6)) *
                                   *(int *)((int)local_10 + 0x14) + param_2) * 4),param_3,param_4,
                 iVar3);
  }
  return;
}



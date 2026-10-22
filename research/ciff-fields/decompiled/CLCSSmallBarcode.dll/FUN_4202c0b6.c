// Source: CLCSSmallBarcode.dll @ 4202c0b6; FUN_4202c0b6

void __thiscall
FUN_4202c0b6(void *this,uint *param_1,int param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint *local_c;
  void *local_8;
  
  local_8 = this;
  iVar4 = FUN_4202c062(this,param_6);
  puVar8 = param_1;
  iVar5 = param_4 + param_3;
  local_1c = 0xffffffff >> ((byte)iVar5 & 0x1f);
  local_20 = local_1c;
  iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
  local_14 = ~((0x80000000U >> ((byte)param_3 & 0x1f)) * 2 - 1);
  local_18 = iVar5 + -1;
  local_10 = param_6 - iVar4;
  if ((int)(param_3 + param_4) < 0x20) {
    local_14 = local_14 | local_1c;
  }
  iVar1 = *(int *)((int)local_8 + 0x20);
  iVar2 = *(int *)((int)local_8 + 0x2c);
  iVar3 = *(int *)((int)local_8 + 0x14);
  *param_1 = *param_1 & ~local_14;
  puVar7 = (uint *)(iVar2 + (((iVar1 - param_5) + -1) * iVar3 + param_2) * 4);
  local_c = puVar7;
  if (~local_1c != 0) {
    param_1[iVar5] = param_1[iVar5] & ~local_1c;
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
  uVar10 = 0;
  do {
    *(undefined1 *)((int)&param_1 + uVar10) = *(undefined1 *)((int)&local_14 + (~uVar10 & 3));
    puVar9 = param_1;
    uVar10 = uVar10 + 1;
  } while ((int)uVar10 < 4);
  do {
    *(undefined1 *)((int)&param_1 + uVar6) = *(undefined1 *)((int)&local_20 + (~uVar6 & 3));
    uVar6 = uVar6 + 1;
    iVar5 = local_10;
  } while ((int)uVar6 < 4);
  while (-1 < iVar5 + -1) {
    *puVar7 = *puVar7 & (uint)puVar9;
    *puVar7 = *puVar7 | *puVar8;
    puVar7 = puVar7 + -*(int *)((int)local_8 + 0x14);
    iVar5 = iVar5 + -1;
  }
  iVar5 = local_18;
  if (0x20 < (int)(param_4 + param_3)) {
    while (iVar5 = iVar5 + -1, -1 < iVar5) {
      local_c = local_c + 1;
      puVar8 = puVar8 + 1;
      puVar7 = local_c;
      iVar1 = local_10;
      while (iVar1 = iVar1 + -1, -1 < iVar1) {
        *puVar7 = *puVar8;
        puVar7 = puVar7 + -*(int *)((int)local_8 + 0x14);
      }
    }
    if (param_1 != (uint *)0xffffffff) {
      puVar7 = local_c + 1;
      iVar5 = local_10;
      while (iVar5 = iVar5 + -1, -1 < iVar5) {
        *puVar7 = *puVar7 & (uint)param_1;
        *puVar7 = *puVar7 | puVar8[1];
        puVar7 = puVar7 + -*(int *)((int)local_8 + 0x14);
      }
    }
  }
  if (iVar4 != 0) {
    FUN_42027a20(local_8,(uint *)(*(int *)((int)local_8 + 0x2c) +
                                 ((iVar4 + -1 +
                                  ((*(int *)((int)local_8 + 0x20) - param_5) - param_6)) *
                                  *(int *)((int)local_8 + 0x14) + param_2) * 4),param_3,param_4,
                 iVar4);
  }
  return;
}



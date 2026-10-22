// Source: CLCSSmallBarcode.dll @ 42031df0; FUN_42031df0

int __fastcall FUN_42031df0(void *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint local_10;
  
  iVar9 = 0;
  bVar1 = false;
  bVar2 = false;
  if (*(char *)((int)param_1 + 8) == '\0') {
    if (*(int *)((int)param_1 + 0x14) == 9) {
      iVar7 = *(int *)((int)param_1 + 0x1214);
      iVar3 = FUN_420332b9(param_1,iVar7 + 8);
      if ((uint)(iVar3 + iVar7) < 0x29) {
        *(undefined4 *)((int)param_1 + 0x14) = 2;
      }
      else {
        iVar3 = FUN_420332b9(param_1,iVar7 + 0x10);
        if ((uint)(iVar3 + iVar7) < 0xa1) {
          *(undefined4 *)((int)param_1 + 0x14) = 3;
        }
        else {
          iVar3 = FUN_420332b9(param_1,iVar7 + 0x20);
          *(uint *)((int)param_1 + 0x14) = (0x140 < (uint)(iVar3 + iVar7)) + 4;
        }
      }
    }
    iVar7 = 2 << ((byte)*(undefined4 *)((int)param_1 + 0x14) & 0x1f);
    uVar4 = *(int *)((int)param_1 + 0x1214) + iVar7;
    *(int *)((int)param_1 + 0x28) = iVar7;
    *(undefined4 *)((int)param_1 + 0x2c) = *(undefined4 *)((int)param_1 + 0x14);
    uVar5 = uVar4 / *(uint *)((int)param_1 + 0xc);
    uVar4 = uVar4 % *(uint *)((int)param_1 + 0xc);
    if (uVar4 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)((int)param_1 + 0xc) - uVar4;
      uVar5 = uVar5 + 1;
    }
    *(uint *)((int)param_1 + 0x24) = uVar5;
    if ((*(char *)((int)param_1 + 10) != '\0') &&
       (uVar4 = *(uint *)((int)param_1 + 0x10), uVar5 < uVar4)) {
      iVar3 = *(int *)((int)param_1 + 0x24);
      *(uint *)((int)param_1 + 0x24) = uVar4;
      iVar7 = iVar7 + (uVar4 - iVar3) * *(int *)((int)param_1 + 0xc);
    }
    if (iVar7 != 0) {
      do {
        iVar7 = iVar7 + -1;
        if (iVar9 != 0) {
          return iVar9;
        }
        iVar9 = FUN_42031972(param_1,900);
      } while (iVar7 != 0);
      if (iVar9 != 0) {
        return iVar9;
      }
    }
    iVar9 = FUN_42033388((int)param_1);
  }
  else {
    iVar7 = *(int *)((int)param_1 + 0xc) * 0x10c;
    local_10 = 0;
    piVar6 = (int *)(&DAT_42096328 + iVar7);
    uVar4 = *(uint *)(&DAT_42096324 + iVar7);
    if (*(char *)((int)param_1 + 10) == '\0') {
      if (uVar4 == 0) {
        return 0;
      }
      iVar3 = 0;
      puVar8 = (uint *)(&DAT_4209632c + iVar7);
      do {
        if (bVar2) goto LAB_42031fbc;
        if (*(uint *)((int)param_1 + 0x1214) <= *puVar8) {
          *(uint *)((int)param_1 + 0x28) = puVar8[1];
          *(uint *)((int)param_1 + 0x24) = puVar8[-1];
          iVar3 = *puVar8 - *(int *)((int)param_1 + 0x1214);
          *(uint **)((int)param_1 + 0x30) = puVar8 + -1;
          bVar2 = true;
        }
        local_10 = local_10 + 1;
        puVar8 = puVar8 + 6;
      } while (local_10 < uVar4);
    }
    else {
      if (uVar4 == 0) {
        return 0;
      }
      iVar3 = 0;
      bVar2 = false;
      do {
        if (bVar1) goto LAB_42031fbc;
        if ((*piVar6 == *(int *)((int)param_1 + 0x10)) &&
           (*(uint *)((int)param_1 + 0x1214) <= (uint)piVar6[1])) {
          *(int *)((int)param_1 + 0x28) = piVar6[2];
          *(int *)((int)param_1 + 0x24) = *piVar6;
          iVar3 = piVar6[1] - *(int *)((int)param_1 + 0x1214);
          bVar1 = true;
          *(int **)((int)param_1 + 0x30) = piVar6;
          bVar2 = true;
        }
        piVar6 = piVar6 + 6;
        local_10 = local_10 + 1;
      } while (local_10 < uVar4);
    }
    if (bVar2) {
LAB_42031fbc:
      while ((iVar3 != 0 && (iVar3 = iVar3 + -1, iVar9 == 0))) {
        iVar9 = FUN_42031972(param_1,900);
      }
    }
  }
  return iVar9;
}



// Source: CLCiffConversion_Layout.dll @ 4543e0ed; FUN_4543e0ed

void __cdecl FUN_4543e0ed(ushort *param_1,uint *param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int local_38;
  uint local_24;
  uint local_14 [4];
  
  local_14[3] = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  uVar1 = param_1[5];
  iVar14 = 0;
  uVar10 = uVar1 & 0x7fff;
  uVar16 = *(uint *)(param_1 + 3);
  iVar11 = uVar10 - 0x3fff;
  local_14[0] = uVar16;
  uVar17 = *(uint *)(param_1 + 1);
  local_14[1] = uVar17;
  uVar2 = *param_1;
  local_14[2] = (uint)uVar2 << 0x10;
  bVar3 = (byte)DAT_4545ea34;
  if (iVar11 == -0x3fff) {
    iVar15 = 0;
    iVar11 = 0;
    do {
      if (local_14[iVar11] != 0) {
        local_14[0] = 0;
        local_14[1] = 0;
        local_14[2] = 0;
        goto LAB_4543e162;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 3);
  }
  else {
    iVar6 = DAT_4545ea30 + -1;
    bVar5 = false;
    iVar15 = (int)((DAT_4545ea30 >> 0x1f & 0x1fU) + DAT_4545ea30) >> 5;
    bVar8 = 0x1f - ((byte)DAT_4545ea30 & 0x1f);
    if ((local_14[iVar15] & 1 << (bVar8 & 0x1f)) != 0) {
      uVar7 = local_14[iVar15] & ~(-1 << (bVar8 & 0x1f));
      iVar12 = iVar15;
      while (uVar7 == 0) {
        iVar12 = iVar12 + 1;
        if (2 < iVar12) goto LAB_4543e262;
        uVar7 = local_14[iVar12];
      }
      iVar12 = (int)((iVar6 >> 0x1f & 0x1fU) + iVar6) >> 5;
      bVar5 = false;
      uVar7 = 1 << (0x1f - ((byte)iVar6 & 0x1f) & 0x1f);
      uVar9 = uVar7 + local_14[iVar12];
      bVar4 = false;
      if ((uVar9 < local_14[iVar12]) || (uVar9 < uVar7)) {
        bVar4 = true;
        bVar5 = true;
      }
      local_14[iVar12] = uVar9;
      while ((iVar12 = iVar12 + -1, -1 < iVar12 && (bVar4))) {
        bVar4 = false;
        bVar5 = false;
        uVar7 = local_14[iVar12] + 1;
        if ((uVar7 < local_14[iVar12]) || (uVar7 == 0)) {
          bVar4 = true;
          bVar5 = true;
        }
        local_14[iVar12] = uVar7;
      }
    }
LAB_4543e262:
    local_14[iVar15] = local_14[iVar15] & -1 << (bVar8 & 0x1f);
    iVar15 = iVar15 + 1;
    if (iVar15 < 3) {
      puVar13 = local_14 + iVar15;
      for (iVar12 = 3 - iVar15; iVar12 != 0; iVar12 = iVar12 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
    }
    iVar15 = iVar11;
    if (bVar5) {
      iVar15 = uVar10 - 0x3ffe;
    }
    if (iVar15 < DAT_4545ea2c - DAT_4545ea30) {
      local_14[0] = 0;
      local_14[1] = 0;
      local_14[2] = 0;
    }
    else {
      if (DAT_4545ea2c < iVar15) {
        if (iVar15 < DAT_4545ea28) {
          local_14[0] = local_14[0] & 0x7fffffff;
          iVar15 = DAT_4545ea3c + iVar15;
          iVar11 = (int)(DAT_4545ea34 + (DAT_4545ea34 >> 0x1f & 0x1fU)) >> 5;
          bVar8 = bVar3 & 0x1f;
          local_24 = 0;
          iVar14 = 0;
          do {
            uVar16 = local_14[iVar14] >> bVar8 | local_24;
            local_24 = (local_14[iVar14] & ~(-1 << bVar8)) << (0x20 - bVar8 & 0x1f);
            local_14[iVar14] = uVar16;
            iVar14 = iVar14 + 1;
          } while (iVar14 < 3);
          puVar13 = local_14 + (2 - iVar11);
          iVar14 = 2;
          do {
            if (iVar14 < iVar11) {
              local_14[iVar14] = 0;
            }
            else {
              local_14[iVar14] = *puVar13;
            }
            puVar13 = puVar13 + -1;
            iVar14 = iVar14 + -1;
          } while (-1 < iVar14);
        }
        else {
          local_14[1] = 0;
          local_14[2] = 0;
          local_14[0] = 0x80000000;
          iVar11 = (int)(DAT_4545ea34 + (DAT_4545ea34 >> 0x1f & 0x1fU)) >> 5;
          bVar8 = bVar3 & 0x1f;
          local_24 = 0;
          do {
            uVar16 = local_14[iVar14] >> bVar8 | local_24;
            local_24 = (local_14[iVar14] & ~(-1 << bVar8)) << (0x20 - bVar8 & 0x1f);
            local_14[iVar14] = uVar16;
            iVar14 = iVar14 + 1;
          } while (iVar14 < 3);
          puVar13 = local_14 + (2 - iVar11);
          iVar14 = 2;
          do {
            if (iVar14 < iVar11) {
              local_14[iVar14] = 0;
            }
            else {
              local_14[iVar14] = *puVar13;
            }
            puVar13 = puVar13 + -1;
            iVar14 = iVar14 + -1;
          } while (-1 < iVar14);
          iVar15 = DAT_4545ea3c + DAT_4545ea28;
        }
        goto LAB_4543e613;
      }
      iVar11 = DAT_4545ea2c - iVar11;
      local_14[0] = uVar16;
      iVar15 = (int)(iVar11 + (iVar11 >> 0x1f & 0x1fU)) >> 5;
      local_14[1] = uVar17;
      local_14[2] = (uint)uVar2 << 0x10;
      bVar8 = (byte)iVar11 & 0x1f;
      local_24 = 0;
      do {
        uVar16 = local_14[iVar14] >> bVar8 | local_24;
        local_24 = (local_14[iVar14] & ~(-1 << bVar8)) << (0x20 - bVar8 & 0x1f);
        local_14[iVar14] = uVar16;
        iVar14 = iVar14 + 1;
      } while (iVar14 < 3);
      puVar13 = local_14 + (2 - iVar15);
      iVar11 = 2;
      do {
        if (iVar11 < iVar15) {
          local_14[iVar11] = 0;
        }
        else {
          local_14[iVar11] = *puVar13;
        }
        puVar13 = puVar13 + -1;
        iVar11 = iVar11 + -1;
      } while (-1 < iVar11);
      iVar11 = (int)((DAT_4545ea30 >> 0x1f & 0x1fU) + DAT_4545ea30) >> 5;
      bVar8 = 0x1f - ((byte)DAT_4545ea30 & 0x1f);
      if ((local_14[iVar11] & 1 << (bVar8 & 0x1f)) != 0) {
        uVar16 = local_14[iVar11] & ~(-1 << (bVar8 & 0x1f));
        iVar14 = iVar11;
        while (uVar16 == 0) {
          iVar14 = iVar14 + 1;
          if (2 < iVar14) goto LAB_4543e41d;
          uVar16 = local_14[iVar14];
        }
        iVar14 = (int)((iVar6 >> 0x1f & 0x1fU) + iVar6) >> 5;
        uVar16 = 1 << (0x1f - ((byte)iVar6 & 0x1f) & 0x1f);
        bVar5 = false;
        uVar17 = uVar16 + local_14[iVar14];
        if ((uVar17 < local_14[iVar14]) || (uVar17 < uVar16)) {
          bVar5 = true;
        }
        local_14[iVar14] = uVar17;
        while ((iVar14 = iVar14 + -1, -1 < iVar14 && (bVar5))) {
          bVar5 = false;
          uVar16 = local_14[iVar14] + 1;
          if ((uVar16 < local_14[iVar14]) || (uVar16 == 0)) {
            bVar5 = true;
          }
          local_14[iVar14] = uVar16;
        }
      }
LAB_4543e41d:
      local_14[iVar11] = local_14[iVar11] & -1 << (bVar8 & 0x1f);
      iVar11 = iVar11 + 1;
      if (iVar11 < 3) {
        puVar13 = local_14 + iVar11;
        for (iVar14 = 3 - iVar11; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar13 = 0;
          puVar13 = puVar13 + 1;
        }
      }
      iVar14 = DAT_4545ea34 + 1;
      iVar11 = (int)(iVar14 + (iVar14 >> 0x1f & 0x1fU)) >> 5;
      bVar8 = (byte)iVar14 & 0x1f;
      local_24 = 0;
      local_38 = 0;
      do {
        uVar16 = local_14[local_38];
        local_14[local_38] = uVar16 >> bVar8 | local_24;
        local_24 = (uVar16 & ~(-1 << bVar8)) << (0x20 - bVar8 & 0x1f);
        local_38 = local_38 + 1;
      } while (local_38 < 3);
      puVar13 = local_14 + (2 - iVar11);
      iVar14 = 2;
      do {
        if (iVar14 < iVar11) {
          local_14[iVar14] = 0;
        }
        else {
          local_14[iVar14] = *puVar13;
        }
        puVar13 = puVar13 + -1;
        iVar14 = iVar14 + -1;
      } while (-1 < iVar14);
    }
LAB_4543e162:
    iVar15 = 0;
  }
LAB_4543e613:
  uVar16 = iVar15 << (0x1f - bVar3 & 0x1f) | -(uint)((uVar1 & 0x8000) != 0) & 0x80000000 |
           local_14[0];
  if (DAT_4545ea38 == 0x40) {
    param_2[1] = uVar16;
    *param_2 = local_14[1];
  }
  else if (DAT_4545ea38 == 0x20) {
    *param_2 = uVar16;
  }
  FUN_4542a8d1(local_14[3] ^ (uint)&stack0xfffffffc);
  return;
}



// Source: CLCiffConversion_Data.dll @ 45036ab4; FUN_45036ab4

/* WARNING: Removing unreachable block (ram,0x45037031) */
/* WARNING: Removing unreachable block (ram,0x4503703e) */
/* WARNING: Removing unreachable block (ram,0x45037044) */

void __cdecl
FUN_45036ab4(int param_1,uint param_2,ushort param_3,int param_4,byte param_5,short *param_6)

{
  int iVar1;
  bool bVar2;
  ushort uVar3;
  errno_t eVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  char cVar12;
  ushort uVar13;
  ushort *puVar14;
  int iVar15;
  uint uVar16;
  short *psVar17;
  short *psVar18;
  ushort uVar19;
  uint uVar20;
  ushort uVar21;
  ushort uVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  char *pcVar26;
  int local_7c;
  short *local_5c;
  int local_58;
  uint local_54;
  int local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  ushort local_40;
  undefined4 uStack_3e;
  undefined2 uStack_3a;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  ushort local_2c [4];
  undefined1 local_24 [4];
  undefined2 uStack_20;
  undefined4 uStack_1e;
  undefined1 local_1a;
  byte bStack_19;
  byte local_14;
  undefined1 uStack_13;
  undefined4 uStack_12;
  undefined4 uStack_e;
  ushort uStack_a;
  uint local_8;
  
  uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
  iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e);
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  uVar19 = param_3 & 0x8000;
  local_34 = 0xcccccccc;
  uVar22 = param_3 & 0x7fff;
  local_30 = 0xcccccccc;
  local_2c[0] = 0xcccc;
  local_2c[1] = 0x3ffb;
  if (uVar19 == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if (uVar22 == 0) {
    if ((param_2 == 0) && (param_1 == 0)) {
      *(undefined1 *)((int)param_6 + 3) = 1;
      *param_6 = 0;
      *(byte *)(param_6 + 1) = ((uVar19 != 0x8000) - 1U & 0xd) + 0x20;
      param_6[2] = 0x30;
      param_1 = CONCAT22(uStack_20,local_24._2_2_);
      param_2 = CONCAT22(uStack_1e._2_2_,(undefined2)uStack_1e);
      goto LAB_45037431;
    }
  }
  else if (uVar22 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
      if ((uVar19 == 0) || (param_2 != 0xc0000000)) {
        if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_45036bc4;
        pcVar26 = "1#INF";
      }
      else {
        if (param_1 != 0) {
LAB_45036bc4:
          pcVar26 = "1#QNAN";
          goto LAB_45036bc9;
        }
        pcVar26 = "1#IND";
      }
      eVar4 = _strcpy_s((char *)(param_6 + 2),0x16,pcVar26);
      if (eVar4 != 0) goto LAB_4503747b;
      *(undefined1 *)((int)param_6 + 3) = 5;
    }
    else {
      pcVar26 = "1#SNAN";
LAB_45036bc9:
      eVar4 = _strcpy_s((char *)(param_6 + 2),0x16,pcVar26);
      if (eVar4 != 0) {
LAB_4503747b:
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      *(undefined1 *)((int)param_6 + 3) = 6;
    }
    iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e);
    param_2 = CONCAT22(uStack_1e._2_2_,(undefined2)uStack_1e);
    param_1 = CONCAT22(uStack_20,local_24._2_2_);
    uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
    goto LAB_45037431;
  }
  uStack_1e._0_2_ = (undefined2)param_2;
  uStack_1e._2_2_ = (ushort)(param_2 >> 0x10);
  iVar23 = 0x450528c8;
  local_1a = (undefined1)uVar22;
  bStack_19 = (byte)(uVar22 >> 8);
  local_5c = (short *)0x5;
  local_4c._0_2_ =
       (short)((uint)uVar22 * 0x4d10 + -0x134312f4 +
               ((uint)(uVar22 >> 8) + (param_2 >> 0x18) * 2) * 0x4d >> 0x10);
  local_24._2_2_ = (undefined2)param_1;
  uStack_20 = (undefined2)((uint)param_1 >> 0x10);
  local_24._0_2_ = 0;
  uVar5 = (uint)(short)local_4c;
  uVar6 = -uVar5;
  if (uVar6 == 0) {
LAB_45036f84:
    uVar6 = CONCAT22((undefined2)uStack_1e,uStack_20);
    uVar5 = param_1 << 0x10;
  }
  else {
    local_48 = uVar6;
    if ((int)uVar6 < 0) {
      iVar23 = 0x45052a28;
      local_48 = uVar5;
    }
    if ((int)uVar6 < 0 && uVar5 == 0) goto LAB_45036f84;
    uVar5 = param_1 << 0x10;
    uVar6 = CONCAT22((undefined2)uStack_1e,uStack_20);
    local_44 = uVar5;
    do {
      uStack_1e._2_2_ = (ushort)(param_2 >> 0x10);
      iVar24 = 0;
      uVar20 = (int)local_48 >> 3;
      iVar23 = iVar23 + 0x54;
      if ((local_48 & 7) != 0) {
        puVar14 = (ushort *)((local_48 & 7) * 0xc + iVar23);
        puVar9 = puVar14;
        if (0x7fff < *puVar14) {
          puVar9 = &local_40;
          local_40 = (ushort)*(undefined4 *)puVar14;
          uStack_3e._0_2_ = (undefined2)((uint)*(undefined4 *)puVar14 >> 0x10);
          uStack_3e._2_2_ = (undefined2)*(undefined4 *)(puVar14 + 2);
          uStack_3a = (undefined2)((uint)*(undefined4 *)(puVar14 + 2) >> 0x10);
          local_38 = *(int *)(puVar14 + 4);
          iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e) + -1;
          uStack_3e._0_2_ = (undefined2)iVar1;
          uStack_3e._2_2_ = (undefined2)((uint)iVar1 >> 0x10);
        }
        uVar21 = puVar9[5] & 0x7fff;
        uVar3 = CONCAT11(bStack_19,local_1a) & 0x7fff;
        uVar22 = (puVar9[5] ^ CONCAT11(bStack_19,local_1a)) & 0x8000;
        uVar13 = uVar3 + uVar21;
        local_14 = 0;
        uStack_13 = 0;
        uStack_12._0_2_ = 0;
        uStack_12._2_2_ = 0;
        uVar10 = 0;
        uStack_a = (ushort)uStack_12;
        uVar5 = 0;
        if (((uVar3 < 0x7fff) && (uVar5 = 0, uVar21 < 0x7fff)) && (uVar5 = uVar10, uVar13 < 0xbffe))
        {
          uStack_12 = uVar10;
          if (uVar13 < 0x3fc0) {
LAB_45036d17:
            local_1a = 0;
            bStack_19 = 0;
            uStack_1e._2_2_ = uStack_12._2_2_;
            goto LAB_45036f64;
          }
          if (((uVar3 == 0) &&
              (uVar13 = uVar13 + 1,
              (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1e._2_2_)) & 0x7fffffff) == 0)) &&
             ((uVar6 == 0 && (local_44 == 0)))) {
            local_1a = 0;
            bStack_19 = 0;
            uVar5 = 0;
            goto LAB_45036f74;
          }
          if (((uVar21 == 0) && (uVar13 = uVar13 + 1, (*(uint *)(puVar9 + 4) & 0x7fffffff) == 0)) &&
             ((*(int *)(puVar9 + 2) == 0 && (*(int *)puVar9 == 0)))) goto LAB_45036d17;
          psVar17 = (short *)((int)&uStack_12 + 2);
          local_54 = 5;
          iVar8 = iVar24;
          uStack_e._0_2_ = (ushort)uStack_12;
          uStack_e._2_2_ = uStack_12._2_2_;
          do {
            if (0 < (int)local_54) {
              puVar7 = (ushort *)(local_24 + iVar8 * 2);
              puVar14 = puVar9 + 4;
              uVar10 = local_54;
              do {
                uVar5 = *(uint *)(psVar17 + -2) + (uint)*puVar7 * (uint)*puVar14;
                if ((uVar5 < *(uint *)(psVar17 + -2)) ||
                   (iVar15 = iVar24, uVar5 < (uint)*puVar7 * (uint)*puVar14)) {
                  iVar15 = 1;
                }
                *(uint *)(psVar17 + -2) = uVar5;
                if (iVar15 != 0) {
                  *psVar17 = *psVar17 + 1;
                }
                puVar7 = puVar7 + 1;
                puVar14 = puVar14 + -1;
                uVar10 = uVar10 + -1;
              } while (0 < (int)uVar10);
            }
            psVar17 = psVar17 + 1;
            iVar8 = iVar8 + 1;
            local_54 = local_54 + -1;
          } while (0 < (int)local_54);
          local_44 = CONCAT22(uStack_a,uStack_e._2_2_);
          uVar13 = uVar13 + 0xc002;
          uVar6 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14));
          if ((short)uVar13 < 1) {
LAB_45036e53:
            uVar13 = uVar13 - 1;
            if (-1 < (short)uVar13) goto LAB_45036ec4;
            local_54 = (uint)(ushort)-uVar13;
            uVar13 = 0;
            uVar10 = local_44;
            do {
              if ((local_14 & 1) != 0) {
                iVar24 = iVar24 + 1;
              }
              uVar5 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
              uStack_e._0_2_ = (ushort)uStack_e >> 1 | (ushort)((uVar10 << 0x1f) >> 0x10);
              uVar25 = uVar6 >> 1;
              local_44 = uVar10 >> 1;
              uVar6 = uVar25 | uVar5 << 0x1f;
              local_54 = local_54 - 1;
              uStack_e._2_2_ = (ushort)local_44;
              uStack_a = (ushort)(uVar10 >> 0x11);
              uStack_12._2_2_ = (ushort)(uVar5 >> 1);
              local_14 = (byte)uVar25;
              uStack_13 = (undefined1)(uVar25 >> 8);
              uStack_12._0_2_ = (ushort)(uVar6 >> 0x10);
              uVar10 = local_44;
            } while (local_54 != 0);
            if (iVar24 == 0) goto LAB_45036ec4;
            uVar3 = (ushort)uVar25 | 1;
            local_14 = (byte)uVar3;
            uVar6 = CONCAT22((ushort)uStack_12,(ushort)uVar25) | 1;
          }
          else {
            do {
              if ((int)local_44 < 0) break;
              iVar8 = CONCAT22((ushort)uStack_e,uStack_12._2_2_) * 2;
              uVar3 = (ushort)uStack_e >> 0xf;
              uStack_12._2_2_ = (ushort)iVar8 | (ushort)(uVar6 >> 0x1f);
              uVar6 = uVar6 * 2;
              uStack_e._0_2_ = (ushort)((uint)iVar8 >> 0x10);
              uVar10 = local_44 * 2;
              local_14 = (byte)uVar6;
              uStack_13 = (undefined1)(uVar6 >> 8);
              uStack_12._0_2_ = (ushort)(uVar6 >> 0x10);
              local_44 = uVar10 | uVar3;
              uVar13 = uVar13 - 1;
              uStack_e._2_2_ = (ushort)local_44;
              uStack_a = (ushort)(uVar10 >> 0x10);
            } while (0 < (short)uVar13);
            if ((short)uVar13 < 1) goto LAB_45036e53;
LAB_45036ec4:
            uVar3 = CONCAT11(uStack_13,local_14);
          }
          uVar5 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12);
          uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
          if ((0x8000 < uVar3) || ((uVar6 & 0x1ffff) == 0x18000)) {
            if (CONCAT22(uStack_12._2_2_,(ushort)uStack_12) == -1) {
              uStack_12._0_2_ = 0;
              uStack_12._2_2_ = 0;
              uVar5 = 0;
              if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
                uStack_e._0_2_ = 0;
                uStack_e._2_2_ = 0;
                uVar10 = 0;
                if (uStack_a == 0xffff) {
                  uStack_a = 0x8000;
                  uVar13 = uVar13 + 1;
                  uVar10 = 0;
                }
                else {
                  uStack_a = uStack_a + 1;
                }
              }
              else {
                uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
                uStack_e._0_2_ = (ushort)uVar10;
                uStack_e._2_2_ = (ushort)(uVar10 >> 0x10);
              }
              uStack_e._2_2_ = (ushort)(uVar10 >> 0x10);
              local_44 = CONCAT22(uStack_a,uStack_e._2_2_);
            }
            else {
              uVar5 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12) + 1;
              uStack_12._0_2_ = (ushort)uVar5;
              uStack_12._2_2_ = (ushort)(uVar5 >> 0x10);
            }
          }
          uStack_e._0_2_ = (ushort)uVar10;
          if (0x7ffe < uVar13) goto LAB_45036f4d;
          bStack_19 = (byte)(uVar13 >> 8) | (byte)(uVar22 >> 8);
          local_24 = (undefined1  [4])uVar5;
          uStack_20 = (ushort)uStack_e;
          uStack_1e._0_2_ = (undefined2)local_44;
          uStack_1e._2_2_ = (ushort)(local_44 >> 0x10);
          uVar6 = CONCAT22((undefined2)uStack_1e,(ushort)uStack_e);
          local_1a = (undefined1)uVar13;
          uStack_12 = uVar5;
        }
        else {
LAB_45036f4d:
          iVar24 = ((uVar22 == 0) - 1 & 0x80000000) + 0x7fff8000;
          uStack_1e._2_2_ = (ushort)iVar24;
          local_1a = (undefined1)((uint)iVar24 >> 0x10);
          bStack_19 = (byte)((uint)iVar24 >> 0x18);
          uStack_12 = uVar5;
LAB_45036f64:
          uVar6 = 0;
          local_24._0_2_ = 0;
          local_24._2_2_ = 0;
          uStack_20 = 0;
          uStack_1e._0_2_ = 0;
          uVar5 = uVar6;
        }
        local_24._2_2_ = (undefined2)(uVar5 >> 0x10);
        local_24._0_2_ = (undefined2)uVar5;
        param_2 = CONCAT22(uStack_1e._2_2_,(undefined2)uStack_1e);
        param_1 = CONCAT22(uStack_20,local_24._2_2_);
        local_44 = uVar5;
      }
LAB_45036f74:
      local_48 = uVar20;
    } while (uVar20 != 0);
  }
  uStack_1e._2_2_ = (ushort)(param_2 >> 0x10);
  uStack_1e._0_2_ = (undefined2)param_2;
  uVar20 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1e._2_2_));
  if (0x3ffe < (ushort)(uVar20 >> 0x10)) {
    local_4c._0_2_ = (short)local_4c + 1;
    local_7c = 0;
    local_14 = 0;
    uStack_13 = 0;
    uStack_12._0_2_ = 0;
    uStack_12._2_2_ = 0;
    uStack_12 = 0;
    uStack_e._0_2_ = 0;
    uStack_e._2_2_ = 0;
    uVar25 = 0;
    uStack_a = 0;
    uVar16 = uVar20 >> 0x10 & 0x7fff;
    local_50 = uVar16 + 0x3ffb;
    uVar20 = 0;
    uVar10 = 0;
    if (((ushort)uVar16 < 0x7fff) &&
       (uVar20 = uStack_12, uVar10 = uVar25, (ushort)local_50 < 0xbffe)) {
      if (0x3fbf < (ushort)local_50) {
        if (((((ushort)uVar16 == 0) &&
             (local_50 = uVar16 + 0x3ffc,
             (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1e._2_2_)) & 0x7fffffff) == 0)) &&
            (uVar6 == 0)) && (uVar5 == 0)) {
          local_1a = 0;
          bStack_19 = 0;
          goto LAB_4503723d;
        }
        psVar17 = (short *)((int)&uStack_12 + 2);
        local_54 = 0;
        do {
          if (0 < (int)local_5c) {
            puVar9 = local_2c;
            puVar14 = (ushort *)(local_24 + local_54 * 2);
            psVar18 = local_5c;
            do {
              uVar10 = *(uint *)(psVar17 + -2) + (uint)*puVar9 * (uint)*puVar14;
              if ((uVar10 < *(uint *)(psVar17 + -2)) || (uVar10 < (uint)*puVar9 * (uint)*puVar14)) {
                bVar2 = true;
              }
              else {
                bVar2 = false;
              }
              *(uint *)(psVar17 + -2) = uVar10;
              if (bVar2) {
                *psVar17 = *psVar17 + 1;
              }
              puVar14 = puVar14 + 1;
              puVar9 = puVar9 + -1;
              psVar18 = (short *)((int)psVar18 + -1);
            } while (0 < (int)psVar18);
          }
          psVar17 = psVar17 + 1;
          local_54 = local_54 + 1;
          local_5c = (short *)((int)local_5c + -1);
        } while (0 < (int)local_5c);
        param_2 = CONCAT22(uStack_a,uStack_e._2_2_);
        local_50 = local_50 + 0xc002;
        if ((short)local_50 < 1) {
          uVar6 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14));
LAB_45037176:
          uVar22 = (ushort)(local_50 + 0xffff);
          if (-1 < (short)uVar22) goto LAB_4503711b;
          uVar10 = -(local_50 + 0xffff);
          local_5c = (short *)(uVar10 & 0xffff);
          uVar22 = uVar22 + (short)uVar10;
          do {
            uVar10 = param_2;
            if ((local_14 & 1) != 0) {
              local_7c = local_7c + 1;
            }
            uVar5 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
            uVar20 = uVar6 >> 1;
            uStack_e._0_2_ = (ushort)uStack_e >> 1 | (ushort)((uVar10 << 0x1f) >> 0x10);
            uVar6 = uVar20 | uVar5 << 0x1f;
            param_2 = uVar10 >> 1;
            local_5c = (short *)((int)local_5c - 1);
            uStack_12._2_2_ = (ushort)(uVar5 >> 1);
            local_14 = (byte)uVar20;
            uStack_13 = (undefined1)(uVar20 >> 8);
            uStack_12._0_2_ = (ushort)(uVar6 >> 0x10);
          } while (local_5c != (short *)0x0);
          uStack_e._2_2_ = (ushort)param_2;
          uStack_a = (ushort)(uVar10 >> 0x11);
          if (local_7c == 0) goto LAB_4503711b;
          uVar13 = (ushort)uVar20 | 1;
          local_14 = (byte)uVar13;
          uVar6 = CONCAT22((ushort)uStack_12,(ushort)uVar20) | 1;
        }
        else {
          uVar6 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14));
          do {
            if ((int)param_2 < 0) break;
            iVar23 = CONCAT22((ushort)uStack_e,uStack_12._2_2_) * 2;
            uVar22 = (ushort)uStack_e >> 0xf;
            uStack_12._2_2_ = (ushort)iVar23 | (ushort)(uVar6 >> 0x1f);
            uVar10 = param_2 * 2;
            uStack_e._0_2_ = (ushort)((uint)iVar23 >> 0x10);
            uVar6 = uVar6 * 2;
            local_14 = (byte)uVar6;
            uStack_13 = (undefined1)(uVar6 >> 8);
            uStack_12._0_2_ = (ushort)(uVar6 >> 0x10);
            param_2 = uVar10 | uVar22;
            local_50 = local_50 + 0xffff;
            uStack_e._2_2_ = (ushort)param_2;
            uStack_a = (ushort)(uVar10 >> 0x10);
          } while (0 < (short)local_50);
          uVar22 = (ushort)local_50;
          if ((short)uVar22 < 1) goto LAB_45037176;
LAB_4503711b:
          uVar13 = CONCAT11(uStack_13,local_14);
        }
        uVar5 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12);
        if ((0x8000 < uVar13) ||
           (uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e), (uVar6 & 0x1ffff) == 0x18000)) {
          if (CONCAT22(uStack_12._2_2_,(ushort)uStack_12) == -1) {
            uVar5 = 0;
            if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
              if (uStack_a == 0xffff) {
                uVar22 = uVar22 + 1;
                uStack_a = 0x8000;
                uVar10 = 0;
              }
              else {
                uStack_a = uStack_a + 1;
                uVar10 = uVar5;
              }
            }
            else {
              uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
            }
            uStack_e._2_2_ = (ushort)(uVar10 >> 0x10);
            param_2 = CONCAT22(uStack_a,uStack_e._2_2_);
          }
          else {
            uVar5 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12) + 1;
            uVar10 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
          }
        }
        uStack_12._2_2_ = (ushort)(uVar5 >> 0x10);
        uStack_12._0_2_ = (ushort)uVar5;
        uStack_e._0_2_ = (ushort)uVar10;
        uVar20 = uVar5;
        if (uVar22 < 0x7fff) {
          bStack_19 = (byte)(uVar22 >> 8) | bStack_19 & 0x80;
          local_24._0_2_ = (ushort)uStack_12;
          param_1 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
          uStack_1e._0_2_ = (undefined2)param_2;
          uVar6 = CONCAT22((undefined2)uStack_1e,(ushort)uStack_e);
          local_1a = (undefined1)uVar22;
          uStack_12 = uVar5;
          goto LAB_4503723d;
        }
        goto LAB_45037222;
      }
      uStack_1e._2_2_ = 0;
      local_1a = 0;
      bStack_19 = 0;
    }
    else {
LAB_45037222:
      iVar23 = (((bStack_19 & 0x80) == 0) - 1 & 0x80000000) + 0x7fff8000;
      uStack_1e._2_2_ = (ushort)iVar23;
      local_1a = (undefined1)((uint)iVar23 >> 0x10);
      bStack_19 = (byte)((uint)iVar23 >> 0x18);
    }
    param_2 = CONCAT22(uStack_1e._2_2_,(undefined2)uStack_1e);
    uVar6 = 0;
    uVar5 = uVar6;
    uStack_12 = uVar20;
  }
LAB_4503723d:
  uStack_1e._2_2_ = (ushort)(param_2 >> 0x10);
  *param_6 = (short)local_4c;
  if (((param_5 & 1) == 0) || (param_4 = param_4 + (short)local_4c, 0 < param_4)) {
    local_4c = param_4;
    if (0x15 < param_4) {
      local_4c = 0x15;
    }
    iVar24 = (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1e._2_2_)) >> 0x10) - 0x3ffe;
    uVar20 = (uint)uStack_1e._2_2_;
    iVar23 = 8;
    do {
      uVar11 = uVar5 >> 0x1f;
      uVar25 = uVar6 * 2;
      uVar16 = uVar20 * 2;
      uVar5 = uVar5 * 2;
      uVar20 = uVar16 | uVar6 >> 0x1f;
      uVar6 = uVar25 | uVar11;
      uStack_1e._2_2_ = (ushort)uVar20;
      local_1a = (undefined1)(uVar16 >> 0x10);
      bStack_19 = (byte)(uVar16 >> 0x18);
      iVar23 = iVar23 + -1;
    } while (iVar23 != 0);
    uStack_20 = (undefined2)uVar6;
    uStack_1e._0_2_ = (undefined2)(uVar25 >> 0x10);
    local_48 = uVar20;
    local_44 = uVar5;
    if ((iVar24 < 0) && (uVar25 = -iVar24 & 0xff, uVar25 != 0)) {
      do {
        uVar5 = uVar5 >> 1 | uVar6 << 0x1f;
        uVar16 = uVar6 >> 1;
        local_48 = uVar20 >> 1;
        uVar6 = uVar16 | uVar20 << 0x1f;
        uVar25 = uVar25 - 1;
        uStack_1e._2_2_ = (ushort)local_48;
        local_1a = (undefined1)(local_48 >> 0x10);
        bStack_19 = (byte)(uVar20 >> 0x19);
        uVar20 = local_48;
      } while (0 < (int)uVar25);
      uStack_20 = (undefined2)uVar16;
      uStack_1e._0_2_ = (undefined2)(uVar6 >> 0x10);
      local_44 = uVar5;
    }
    local_58 = local_4c + 1;
    psVar17 = param_6 + 2;
    local_5c = psVar17;
    if (0 < local_58) {
      while( true ) {
        local_24._2_2_ = (undefined2)(local_44 >> 0x10);
        local_24._0_2_ = (undefined2)local_44;
        local_40 = local_24._0_2_;
        iVar1 = CONCAT22(uStack_20,local_24._2_2_);
        uStack_3a = (undefined2)uStack_1e;
        local_38 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1e._2_2_));
        uVar20 = (uVar6 * 2 | local_44 >> 0x1f) * 2 | (local_44 & 0x7fffffff) >> 0x1e;
        uVar25 = (local_48 * 2 | uVar6 >> 0x1f) * 2 | (uVar6 & 0x7fffffff) >> 0x1e;
        uVar5 = local_44 * 5;
        if ((uVar5 < local_44 * 4) || (uVar6 = uVar20, uVar5 < local_44)) {
          uVar6 = uVar20 + 1;
          if ((uVar6 < uVar20) || (bVar2 = false, uVar6 == 0)) {
            bVar2 = true;
          }
          if (bVar2) {
            uVar25 = uVar25 + 1;
          }
        }
        uVar20 = CONCAT22((undefined2)uStack_1e,uStack_20) + uVar6;
        if ((uVar20 < uVar6) || (uVar20 < CONCAT22((undefined2)uStack_1e,uStack_20))) {
          uVar25 = uVar25 + 1;
        }
        local_44 = local_44 * 10;
        uVar6 = uVar20 * 2 | uVar5 >> 0x1f;
        uVar5 = (uVar25 + local_38) * 2;
        uStack_20 = (undefined2)uVar6;
        uStack_1e._0_2_ = (undefined2)(uVar20 * 2 >> 0x10);
        uStack_1e._2_2_ = (ushort)uVar5 | (ushort)(uVar20 >> 0x1f);
        local_1a = (undefined1)(uVar5 >> 0x10);
        *(char *)local_5c = (char)(uVar5 >> 0x18) + '0';
        local_5c = (short *)((int)local_5c + 1);
        local_58 = local_58 + -1;
        bStack_19 = 0;
        if (local_58 < 1) break;
        local_48 = uVar5 & 0xffffff | uVar20 >> 0x1f;
      }
    }
    local_24._2_2_ = (undefined2)(local_44 >> 0x10);
    local_24._0_2_ = (undefined2)local_44;
    param_2 = CONCAT22(uStack_1e._2_2_,(undefined2)uStack_1e);
    param_1 = CONCAT22(uStack_20,local_24._2_2_);
    psVar18 = local_5c + -1;
    if (*(char *)((int)local_5c + -1) < '5') {
      for (; (psVar17 <= psVar18 && ((char)*psVar18 == '0')); psVar18 = (short *)((int)psVar18 + -1)
          ) {
      }
      if (psVar18 < psVar17) {
        *param_6 = 0;
        *(byte *)(param_6 + 1) = ((uVar19 != 0x8000) - 1U & 0xd) + 0x20;
        *(undefined1 *)((int)param_6 + 3) = 1;
        *(char *)psVar17 = '0';
        goto LAB_4503727d;
      }
    }
    else {
      for (; (psVar17 <= psVar18 && ((char)*psVar18 == '9')); psVar18 = (short *)((int)psVar18 + -1)
          ) {
        *(char *)psVar18 = '0';
      }
      if (psVar18 < psVar17) {
        psVar18 = (short *)((int)psVar18 + 1);
        *param_6 = *param_6 + 1;
      }
      *(char *)psVar18 = (char)*psVar18 + '\x01';
    }
    cVar12 = ((char)psVar18 - (char)param_6) + -3;
    *(char *)((int)param_6 + 3) = cVar12;
    *(undefined1 *)(cVar12 + 4 + (int)param_6) = 0;
  }
  else {
    *param_6 = 0;
    *(byte *)(param_6 + 1) = ((uVar19 != 0x8000) - 1U & 0xd) + 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)(param_6 + 2) = 0x30;
LAB_4503727d:
    *(undefined1 *)((int)param_6 + 5) = 0;
  }
LAB_45037431:
  unique0x100008f9 = param_1;
  uStack_1e = param_2;
  uStack_e = uVar10;
  uStack_3e = iVar1;
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



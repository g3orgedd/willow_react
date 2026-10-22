// Source: CLCiffConversion_Layout.dll @ 45438659; FUN_45438659

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_45438659(double param_1,int param_2,uint param_3)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ushort uVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined1 auVar15 [16];
  ulonglong uVar14;
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  longlong lVar20;
  ulonglong in_XMM2_Qb;
  undefined1 auVar21 [16];
  longlong lVar24;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  ulonglong in_XMM3_Qb;
  undefined1 auVar25 [16];
  ulonglong uVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  
  dVar11 = (double)((ulonglong)param_1 >> 0x2c);
  uVar10 = (ushort)((ulonglong)param_1 >> 0x30);
  uVar3 = (SUB82(dVar11,0) & 0xff) + 1 & 0x1fe;
  dVar32 = (double)((ulonglong)DAT_45450a30 & (ulonglong)param_1 | (ulonglong)DAT_45450a40) *
           *(double *)((int)&DAT_4544d1a0 + uVar3 * 4);
  dVar29 = *(double *)((int)&DAT_4544d1a0 + uVar3 * 4);
  dVar12 = *(double *)(&DAT_4544d5b0 + uVar3 * 8);
  dVar31 = *(double *)(&UNK_4544d5b8 + uVar3 * 8);
  uVar3 = 0x7fef - uVar10;
  iVar6 = SUB84(param_1,0);
  uVar7 = (uint)((ulonglong)param_1 >> 0x20);
  dVar30 = param_1;
  if (0x7fffffff < (uVar10 - 0x10 | uVar3)) {
    auVar21._4_4_ = param_3;
    auVar21._0_4_ = param_2;
    auVar21._8_8_ = in_XMM2_Qb;
    uVar8 = param_3 & DAT_45450a50._4_4_;
    if (uVar8 < 0x7ff00000) {
      if (param_2 == 0 && uVar8 == 0) {
        iVar9 = 0x1a;
        dVar29 = DAT_45450a40;
        if (iVar6 != 0 || ((ulonglong)param_1 & 0x7fffffff00000000) != 0) {
          iVar9 = 0x1d;
          if (((uVar7 & 0x7fffffff) < 0x7ff00001) &&
             (((uVar7 & 0x7fffffff) < 0x7ff00000 || (iVar6 == 0)))) {
            return (float10)DAT_45450a40;
          }
        }
        goto LAB_45438e60;
      }
      if ((int)uVar3 < 0) {
        auVar25._0_8_ = CONCAT44(DAT_45450a50._4_4_,(undefined4)DAT_45450a50) << 0x34;
        auVar25._8_8_ = in_XMM3_Qb << 0x34;
        iVar9 = (uVar8 >> 0x14) - 0x3f3;
        in_XMM3_Qb = 0;
        uVar26 = (ulonglong)
                 CONCAT22((ushort)(-1 < iVar9) * (short)((uint)iVar9 >> 0x10),
                          (ushort)(-1 < (short)iVar9) * (short)iVar9);
        lVar20 = SUB168(auVar21 | auVar25,0) << uVar26;
        lVar24 = SUB168(auVar21 | auVar25,8) << uVar26;
        auVar22._0_4_ = -(uint)((int)lVar20 == 0);
        auVar22._4_4_ = -(uint)((int)((ulonglong)lVar20 >> 0x20) == 0);
        auVar22._8_4_ = -(uint)((int)lVar24 == 0);
        auVar22._12_4_ = -(uint)((int)((ulonglong)lVar24 >> 0x20) == 0);
        bVar1 = SUB161(auVar22 >> 7,0) & 1 | (SUB161(auVar22 >> 0xf,0) & 1) << 1 |
                (SUB161(auVar22 >> 0x17,0) & 1) << 2 | (SUB161(auVar22 >> 0x1f,0) & 1) << 3 |
                (SUB161(auVar22 >> 0x27,0) & 1) << 4 | (SUB161(auVar22 >> 0x2f,0) & 1) << 5 |
                (SUB161(auVar22 >> 0x37,0) & 1) << 6 | SUB161(auVar22 >> 0x3f,0) << 7;
        uVar8 = 0x7fef - uVar3 & 0x7fff;
        uVar26 = auVar22._8_8_;
        if (0x7fef < uVar8) {
          auVar16._0_4_ = -(uint)((int)((ulonglong)DAT_45450a30 & (ulonglong)param_1) == 0);
          auVar16._4_4_ =
               -(uint)((int)(((ulonglong)DAT_45450a30 & (ulonglong)param_1) >> 0x20) == 0);
          auVar16._8_4_ = 0xffffffff;
          auVar16._12_4_ = 0xffffffff;
          if ((byte)(SUB161(auVar16 >> 7,0) & 1 | (SUB161(auVar16 >> 0xf,0) & 1) << 1 |
                     (SUB161(auVar16 >> 0x17,0) & 1) << 2 | (SUB161(auVar16 >> 0x1f,0) & 1) << 3 |
                     (SUB161(auVar16 >> 0x27,0) & 1) << 4 | (SUB161(auVar16 >> 0x2f,0) & 1) << 5 |
                     (SUB161(auVar16 >> 0x37,0) & 1) << 6 | SUB161(auVar16 >> 0x3f,0) << 7) == 0xff)
          {
            if (((ulonglong)param_1 & 0x8000000000000000) != 0) {
              if ((bVar1 != 0xff) ||
                 (uVar14 = (ulonglong)(((param_3 & DAT_45450a50._4_4_) >> 0x14) - 0x3f4),
                 lVar20 = CONCAT44(param_3,param_2) << uVar14, lVar24 = uVar26 << uVar14,
                 auVar23._0_4_ = -(uint)((int)lVar20 == 0),
                 auVar23._4_4_ = -(uint)((int)((ulonglong)lVar20 >> 0x20) == 0),
                 auVar23._8_4_ = -(uint)((int)lVar24 == 0),
                 auVar23._12_4_ = -(uint)((int)((ulonglong)lVar24 >> 0x20) == 0),
                 (byte)(SUB161(auVar23 >> 7,0) & 1 | (SUB161(auVar23 >> 0xf,0) & 1) << 1 |
                        (SUB161(auVar23 >> 0x17,0) & 1) << 2 | (SUB161(auVar23 >> 0x1f,0) & 1) << 3
                        | (SUB161(auVar23 >> 0x27,0) & 1) << 4 |
                        (SUB161(auVar23 >> 0x2f,0) & 1) << 5 | (SUB161(auVar23 >> 0x37,0) & 1) << 6
                       | SUB161(auVar23 >> 0x3f,0) << 7) == 0xff)) {
                if ((param_3 & 0x80000000) != 0) {
                  return (float10)0;
                }
                goto LAB_45438de7;
              }
              if ((param_3 & 0x80000000) == 0) {
                return (float10)_DAT_45450aa8;
              }
              goto LAB_45438c79;
            }
            if ((param_3 & 0x80000000) != 0) {
              return (float10)0;
            }
            goto LAB_45438de7;
          }
          goto LAB_45438cbf;
        }
        if (bVar1 == 0xff) {
          uVar14 = (ulonglong)(((param_3 & DAT_45450a50._4_4_) >> 0x14) - 0x3f4);
          in_XMM3_Qb = 0;
          lVar20 = CONCAT44(param_3,param_2) << uVar14;
          lVar24 = uVar26 << uVar14;
          auVar21._0_4_ = -(uint)((int)lVar20 == SUB84(DAT_45450ab0,0));
          auVar21._4_4_ =
               -(uint)((int)((ulonglong)lVar20 >> 0x20) == (int)((ulonglong)DAT_45450ab0 >> 0x20));
          auVar21._8_4_ = -(uint)((int)lVar24 == 0);
          auVar21._12_4_ = -(uint)((int)((ulonglong)lVar24 >> 0x20) == 0);
          uVar3 = (ushort)((ushort)(SUB161(auVar21 >> 7,0) & 1) |
                           (ushort)(SUB161(auVar21 >> 0xf,0) & 1) << 1 |
                           (ushort)(SUB161(auVar21 >> 0x17,0) & 1) << 2 |
                           (ushort)(SUB161(auVar21 >> 0x1f,0) & 1) << 3 |
                           (ushort)(SUB161(auVar21 >> 0x27,0) & 1) << 4 |
                           (ushort)(SUB161(auVar21 >> 0x2f,0) & 1) << 5 |
                           (ushort)(SUB161(auVar21 >> 0x37,0) & 1) << 6 |
                          (ushort)(SUB161(auVar21 >> 0x3f,0) & 1) << 7) + 0x3ff01 & 0x40000;
          if (0xf < uVar8) {
            uVar8 = 0xbfe7f;
            in_XMM3_Qb = 0;
            in_XMM2_Qb = auVar21._8_8_;
            goto LAB_454386d6;
          }
          goto LAB_45438af4;
        }
        dVar29 = (double)((ulonglong)param_1 >> 0x20);
        in_XMM2_Qb = uVar26 >> 0x20;
        uVar3 = 0;
        uVar8 = 0;
        if (iVar6 != 0 || ((ulonglong)param_1 & 0x7fffffff00000000) != 0) {
          iVar9 = 0x1c;
          dVar29 = DAT_45450ad0;
          goto LAB_45438e60;
        }
LAB_45438b7a:
        dVar30 = dVar11;
        if ((uVar8 & 0x7fffffff) == 0) {
          if ((param_3 & 0x80000000) == 0) {
            if ((uVar8 & uVar3 << 0xd) == 0) {
              return (float10)0;
            }
LAB_45438c79:
            return (float10)DAT_45450ab0;
          }
          dVar29 = (double)((ulonglong)(uVar8 & uVar3 << 0xd | 0x7ff00000) << 0x20);
          iVar9 = 0x1b;
          goto LAB_45438e60;
        }
      }
      else {
        uVar3 = 0;
LAB_45438af4:
        in_XMM2_Qb = auVar21._8_8_;
        dVar11 = param_1 * 1.8446744073709552e+19;
        uVar8 = uVar7;
        dVar30 = dVar11;
        dVar32 = DAT_45450a30;
        dVar29 = DAT_45450a40;
        if (iVar6 == 0) goto LAB_45438b7a;
      }
      dVar11 = (double)(((ulonglong)dVar30 & CONCAT44(DAT_45450a50._4_4_,(undefined4)DAT_45450a50))
                       >> 0x2c);
      uVar8 = (SUB82(dVar11,0) & 0xff) + 1 & 0x1fe;
      dVar32 = (double)((ulonglong)dVar32 & (ulonglong)dVar30 | (ulonglong)dVar29) *
               *(double *)((int)&DAT_4544d1a0 + uVar8 * 4);
      dVar29 = *(double *)((int)&DAT_4544d1a0 + uVar8 * 4);
      dVar12 = *(double *)(&DAT_4544d5b0 + uVar8 * 8);
      dVar31 = *(double *)(&UNK_4544d5b8 + uVar8 * 8);
      uVar8 = 0x43e7f;
      goto LAB_454386d6;
    }
    dVar12 = param_1;
    if ((0x7fefffff < (uVar7 & 0x7fffffff)) && ((0x7ff00000 < (uVar7 & 0x7fffffff) || (iVar6 != 0)))
       ) {
LAB_45438cbf:
      dVar29 = param_1 + param_1;
      iVar9 = 0x3ee;
      goto LAB_45438e60;
    }
    goto LAB_45438d75;
  }
  uVar3 = 0;
  uVar8 = 0x3fe7f;
LAB_454386d6:
  uVar4 = ((ushort)((ulonglong)dVar32 >> 0x26) & 0xff) + 1 & 0x1fe;
  dVar27 = (double)((ulonglong)dVar30 & (ulonglong)DAT_45450a30 | (ulonglong)DAT_45450a40);
  dVar13 = (double)(DAT_45450a88 & (ulonglong)dVar27);
  dVar27 = dVar27 - dVar13;
  uVar5 = ((ushort)((ulonglong)(dVar32 * *(double *)(&DAT_4544ddc0 + uVar4 * 4)) >> 0x1f) & 0x1ff) +
          1 & 0x3fe;
  dVar28 = dVar29 * *(double *)(&DAT_4544ddc0 + uVar4 * 4) * *(double *)(&DAT_4544e9e0 + uVar5 * 4);
  dVar32 = dVar32 * *(double *)(&DAT_4544ddc0 + uVar4 * 4) * *(double *)(&DAT_4544e9e0 + uVar5 * 4);
  dVar30 = dVar12 + *(double *)(&DAT_4544e1d0 + uVar4 * 8) +
           (double)(int)((longlong)dVar11 - (ulonglong)uVar8 >> 8) +
           *(double *)(&DAT_4544f1f0 + uVar5 * 8);
  dVar11 = dVar31 + *(double *)(&DAT_4544e1d8 + uVar4 * 8) + *(double *)(&DAT_4544f1f8 + uVar5 * 8);
  dVar12 = (double)(DAT_45450a88 & (ulonglong)dVar28);
  dVar28 = dVar28 - dVar12;
  dVar33 = DAT_45450a90 + dVar32;
  dVar31 = dVar30 + dVar33;
  dVar29 = (double)CONCAT44(param_3,param_2);
  uVar2 = (ushort)(param_3 >> 0x10);
  dVar30 = dVar30 - dVar31;
  uVar4 = (uint)(ushort)((ulonglong)dVar31 >> 0x30);
  dVar12 = (((dVar32 - dVar12 * dVar13) - dVar13 * dVar28) - dVar12 * dVar27) - dVar27 * dVar28;
  dVar13 = dVar33 - dVar12;
  dVar32 = dVar31 - dVar12;
  uVar8 = uVar2 & 0x7ff0;
  if (0x7fef < uVar8) {
    dVar29 = (double)CONCAT44(param_3,param_2);
    auVar21._8_8_ = in_XMM2_Qb;
    auVar21._0_8_ = dVar29;
    in_XMM3_Qb = in_XMM3_Qb >> 0x1f & in_XMM2_Qb;
    auVar17._0_4_ = -(uint)((int)((ulonglong)DAT_45450a30 & (ulonglong)dVar29) == 0);
    auVar17._4_4_ = -(uint)((int)(((ulonglong)DAT_45450a30 & (ulonglong)dVar29) >> 0x20) == 0);
    auVar17._8_4_ = -(uint)((int)in_XMM3_Qb == 0);
    auVar17._12_4_ = -(uint)((int)(in_XMM3_Qb >> 0x20) == 0);
    if ((byte)(SUB161(auVar17 >> 7,0) & 1 | (SUB161(auVar17 >> 0xf,0) & 1) << 1 |
               (SUB161(auVar17 >> 0x17,0) & 1) << 2 | (SUB161(auVar17 >> 0x1f,0) & 1) << 3 |
               (SUB161(auVar17 >> 0x27,0) & 1) << 4 | (SUB161(auVar17 >> 0x2f,0) & 1) << 5 |
               (SUB161(auVar17 >> 0x37,0) & 1) << 6 | SUB161(auVar17 >> 0x3f,0) << 7) == 0xff) {
      dVar12 = (double)CONCAT44(uVar3,uVar4);
      if (iVar6 == 0) {
        if (uVar7 != 0x3ff00000) {
          dVar12 = (double)CONCAT44(uVar3,uVar7);
          if (uVar7 == 0xbff00000) {
            return (float10)1;
          }
          goto LAB_45438d75;
        }
      }
      else {
LAB_45438d75:
        dVar29 = auVar21._0_8_;
        uVar26 = in_XMM3_Qb & auVar21._8_8_;
        auVar18._0_4_ = -(uint)((int)((ulonglong)DAT_45450a30 & (ulonglong)dVar29) == 0);
        auVar18._4_4_ = -(uint)((int)(((ulonglong)DAT_45450a30 & (ulonglong)dVar29) >> 0x20) == 0);
        auVar18._8_4_ = -(uint)((int)uVar26 == 0);
        auVar18._12_4_ = -(uint)((int)(uVar26 >> 0x20) == 0);
        if ((byte)(SUB161(auVar18 >> 7,0) & 1 | (SUB161(auVar18 >> 0xf,0) & 1) << 1 |
                   (SUB161(auVar18 >> 0x17,0) & 1) << 2 | (SUB161(auVar18 >> 0x1f,0) & 1) << 3 |
                   (SUB161(auVar18 >> 0x27,0) & 1) << 4 | (SUB161(auVar18 >> 0x2f,0) & 1) << 5 |
                   (SUB161(auVar18 >> 0x37,0) & 1) << 6 | SUB161(auVar18 >> 0x3f,0) << 7) != 0xff)
        goto LAB_45438dee;
        if (dVar12 != -1.0) {
          if ((auVar21._6_2_ & 0x8000) == 0) {
            if ((uVar10 & 0x7ff0) < 0x3ff0) {
              return (float10)0;
            }
          }
          else if (0x3fef < (uVar10 & 0x7ff0)) {
            return (float10)0;
          }
LAB_45438de7:
          return (float10)_DAT_45450aa0;
        }
      }
      iVar9 = 0x1c;
      dVar29 = DAT_4544d1a0;
    }
    else {
LAB_45438dee:
      dVar29 = dVar29 + dVar29;
      iVar9 = 0x3ee;
    }
    goto LAB_45438e60;
  }
  iVar6 = (uVar8 - 0x3ff0) + (uVar4 & 0x7ff0);
  if ((0x40a0U - iVar6 | iVar6 - 0x3c70U) < 0x80000000) {
LAB_45438828:
    dVar27 = (double)(DAT_45450a88 & (ulonglong)dVar29);
    dVar28 = (double)(DAT_45450a88 & (ulonglong)dVar32);
    dVar12 = (dVar30 + dVar33) - (dVar12 - (dVar31 - dVar32));
    dVar31 = dVar27 * dVar28 * 128.0;
    uVar7 = (uint)ROUND(dVar31);
    dVar29 = dVar27 * (dVar32 - dVar28) + dVar28 * (dVar29 - dVar27) +
             (dVar32 - dVar28) * (dVar29 - dVar27);
    if (0 < (int)(0x1ff7f - uVar7 | uVar7 + 0x1e1ff)) {
      iVar6 = (uVar7 & 0x7f) * 0x10;
      auVar15._0_8_ = (double)((ulonglong)((uVar3 + uVar7 & 0xffffff80) + 0x1ff80) << 0x2d);
      auVar15._8_4_ = 0;
      auVar15._12_4_ = (int)((ulonglong)auVar15._0_8_ >> 0x20);
      dVar30 = *(double *)(&DAT_45450220 + iVar6) * auVar15._0_8_;
      dVar29 = (dVar31 - ((dVar31 + _DAT_45450a20) - _DAT_45450a20)) * 0.0078125 +
               dVar29 + ((_DAT_45450200 * dVar13 + _DAT_45450210 * dVar13 * dVar13) *
                         dVar13 * dVar13 + _UNK_45450208 * dVar13 + _UNK_45450218 * dVar13 * dVar13
                        + dVar11 + dVar12) * (double)CONCAT44(param_3,param_2);
      return (float10)(dVar29 * dVar29 * dVar30 *
                       (_DAT_45450a70 + _DAT_45450a60 * dVar29) * dVar29 * dVar29 +
                       *(double *)(&UNK_45450228 + iVar6) * auVar15._8_8_ +
                       (_UNK_45450a78 + _UNK_45450a68 * dVar29) * dVar29 * dVar29 * dVar30 +
                       DAT_45450a80 * dVar29 * dVar30 + dVar30);
    }
    if ((int)uVar7 < 1) {
      if ((int)uVar7 < -0x3fdff) {
LAB_454390b9:
        iVar9 = 0x19;
        dVar29 = (double)((ulonglong)(DAT_45450ac8 * DAT_45450ac8) | (ulonglong)uVar3 << 0x2d);
        goto LAB_45438e60;
      }
      uVar3 = uVar3 + 0x80;
      uVar8 = (uVar7 & 0xffffff80) + 0x3fe80;
      uVar10 = 0;
    }
    else {
      if (0x3ffff < uVar7) goto LAB_454390dc;
      uVar3 = uVar3 + 0x3ff00;
      uVar8 = uVar7 - 0x80 & 0xffffff80;
      uVar10 = 0x3ff0;
    }
    iVar6 = (uVar7 & 0x7f) * 0x10;
    uVar7 = ((int)-(uVar8 - 0x1ff80) >> 7) + 2;
    auVar19._0_8_ = (double)((ulonglong)uVar8 << 0x2d);
    auVar19._8_4_ = 0;
    auVar19._12_4_ = (int)((ulonglong)auVar19._0_8_ >> 0x20);
    dVar32 = *(double *)(&DAT_45450220 + iVar6) * auVar19._0_8_;
    dVar12 = (dVar31 - ((dVar31 + _DAT_45450a20) - _DAT_45450a20)) * 0.0078125 +
             dVar29 + ((_DAT_45450200 * dVar13 + _DAT_45450210 * dVar13 * dVar13) * dVar13 * dVar13
                       + _UNK_45450208 * dVar13 + _UNK_45450218 * dVar13 * dVar13 + dVar11 + dVar12)
                      * (double)CONCAT44(param_3,param_2);
    dVar29 = (double)((ulonglong)uVar3 << 0x2d);
    uVar26 = (ulonglong)(uVar7 + (uVar7 & 0x20));
    dVar31 = (double)(-1L << uVar26 & (ulonglong)dVar32);
    dVar12 = dVar12 * dVar12 * dVar32 * (_DAT_45450a70 + _DAT_45450a60 * dVar12) * dVar12 * dVar12 +
             *(double *)(&UNK_45450228 + iVar6) * auVar19._8_8_ +
             (_UNK_45450a78 + _UNK_45450a68 * dVar12) * dVar12 * dVar12 * dVar32 +
             DAT_45450a80 * dVar12 * dVar32;
    dVar30 = (double)((ulonglong)(dVar31 + dVar12) & -1L << uVar26);
    dVar12 = dVar12 + (dVar31 - dVar30) + (dVar32 - dVar31);
    if ((int)(uVar8 - 0x1ff80) < 1) {
      dVar29 = dVar12 * dVar29 + dVar30 * dVar29;
      dVar29 = dVar29 + (double)((ulonglong)uVar10 << 0x30) * dVar29;
      iVar9 = 0x18;
      if ((((ushort)((ulonglong)dVar29 >> 0x30) & 0x7ff0) != 0x7ff0) &&
         (iVar9 = 0x19, ((ulonglong)dVar29 & 0x7ff0000000000000) != 0)) {
        return (float10)dVar29;
      }
    }
    else {
      dVar29 = (dVar12 + dVar30) * dVar29;
      dVar29 = dVar29 + (double)((ulonglong)uVar10 << 0x30) * dVar29;
      iVar9 = 0x18;
      if ((((ushort)((ulonglong)dVar29 >> 0x30) & 0x7ff0) != 0x7ff0) &&
         (iVar9 = 0x19, ((ulonglong)dVar29 & 0x7ff0000000000000) != 0)) {
        return (float10)dVar29;
      }
    }
  }
  else {
    dVar31 = dVar29 * dVar32;
    uVar7 = (ushort)((ulonglong)dVar31 >> 0x30) & 0x7ff0;
    uVar8 = uVar7 - 0x3c70;
    if ((0x40a0 - uVar7 | uVar8) < 0x80000000) goto LAB_45438828;
    if (0x7fffffff < uVar8) {
      return (float10)(double)((ulonglong)(uVar3 | 0x1ff80) << 0x2d);
    }
    if (((uVar2 ^ (uVar10 & 0x7ff0) + 0xc010) & 0x8000) != 0) goto LAB_454390b9;
LAB_454390dc:
    iVar9 = 0x18;
    if (uVar3 == 0) {
      dVar29 = DAT_45450ac0 * DAT_45450ac0;
    }
    else {
      dVar29 = DAT_45450ab8 * DAT_45450ac0;
    }
  }
LAB_45438e60:
  FUN_4542fb9c(&param_1,(undefined8 *)&param_2,(double *)&stack0xfffffff4,iVar9);
  return (float10)dVar29;
}



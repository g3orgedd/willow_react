// Source: CLCiffConversion_Data.dll @ 450359b4; FUN_450359b4

void __cdecl
FUN_450359b4(undefined2 *param_1,int *param_2,char *param_3,int param_4,int param_5,int param_6,
            int param_7,int *param_8)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  ushort *puVar14;
  ushort *puVar15;
  uint uVar16;
  char *pcVar17;
  short *psVar18;
  undefined4 uVar19;
  int iVar20;
  ushort uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  undefined4 uVar25;
  char *pcVar26;
  uint uVar27;
  uint uVar28;
  int local_70;
  uint local_6c;
  ushort *local_68;
  char local_59;
  int local_58;
  char *local_54;
  uint local_50;
  ushort local_4c;
  undefined4 uStack_4a;
  undefined2 uStack_46;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  byte local_30;
  undefined1 uStack_2f;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  ushort uStack_26;
  char local_24 [23];
  char local_d;
  uint local_8;
  
  uVar27 = CONCAT22(local_40._2_2_,(undefined2)local_40);
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_70 = 1;
  iVar8 = 0;
  uVar5 = 0;
  pcVar26 = local_24;
  local_50 = 0;
  bVar2 = false;
  bVar4 = false;
  bVar3 = false;
  local_58 = 0;
  if (param_8 != (int *)0x0) {
    local_54 = param_3;
    for (; (((cVar1 = *param_3, cVar1 == ' ' || (cVar1 == '\t')) || (cVar1 == '\n')) ||
           (cVar1 == '\r')); param_3 = param_3 + 1) {
    }
LAB_45035a34:
    pcVar17 = param_3;
    iVar22 = 0;
    local_59 = *pcVar17;
    param_3 = pcVar17 + 1;
    switch(iVar8) {
    case 0:
      if (8 < (byte)(local_59 - 0x31U)) {
        if (local_59 == *(char *)**(undefined4 **)(*param_8 + 0x84)) {
LAB_45035a68:
          iVar8 = 5;
        }
        else if (local_59 == '+') {
          iVar8 = 2;
          uVar5 = 0;
        }
        else if (local_59 == '-') {
          iVar8 = 2;
          uVar5 = 0x8000;
        }
        else {
          if (local_59 != '0') goto LAB_45035d10;
LAB_45035a82:
          iVar8 = 1;
        }
        goto LAB_45035a34;
      }
      break;
    case 1:
      bVar2 = true;
      if (8 < (byte)(local_59 - 0x31U)) {
        if (local_59 == *(char *)**(undefined4 **)(*param_8 + 0x84)) goto LAB_45035aba;
        if ((local_59 != '+') && (local_59 != '-')) {
          if (local_59 != '0') goto LAB_45035acd;
          goto LAB_45035a82;
        }
        goto LAB_45035aee;
      }
      break;
    case 2:
      if (8 < (byte)(local_59 - 0x31U)) {
        if (local_59 == *(char *)**(undefined4 **)(*param_8 + 0x84)) goto LAB_45035a68;
        pcVar17 = local_54;
        if (local_59 == '0') goto LAB_45035a82;
        goto LAB_45035d14;
      }
      break;
    case 3:
      while (('/' < local_59 && (local_59 < ':'))) {
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar26 = local_59 + -0x30;
          pcVar26 = pcVar26 + 1;
        }
        else {
          local_58 = local_58 + 1;
        }
        local_59 = *param_3;
        param_3 = param_3 + 1;
      }
      if (local_59 != *(char *)**(undefined4 **)(*param_8 + 0x84)) {
        if ((local_59 == '+') || (local_59 == '-')) goto LAB_45035aee;
LAB_45035acd:
        bVar2 = true;
        iVar22 = 0;
        if (('C' < local_59) && ((local_59 < 'F' || ((byte)(local_59 + 0x9cU) < 2))))
        goto LAB_45035ae7;
        goto LAB_45035d10;
      }
LAB_45035aba:
      bVar2 = true;
      iVar8 = 4;
      goto LAB_45035a34;
    case 4:
      bVar2 = true;
      bVar4 = true;
      if (local_50 == 0) {
        while (local_59 == '0') {
          local_58 = local_58 + -1;
          local_59 = *param_3;
          param_3 = param_3 + 1;
        }
      }
      while (('/' < local_59 && (local_59 < ':'))) {
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar26 = local_59 + -0x30;
          pcVar26 = pcVar26 + 1;
          local_58 = local_58 + -1;
        }
        local_59 = *param_3;
        param_3 = param_3 + 1;
      }
      iVar22 = 0;
      if ((local_59 == '+') || (local_59 == '-')) {
LAB_45035aee:
        bVar2 = true;
        iVar8 = 0xb;
        param_3 = param_3 + -1;
      }
      else {
        if ((local_59 < 'D') || (('E' < local_59 && (1 < (byte)(local_59 + 0x9cU))))) {
          pcVar17 = param_3 + -1;
          goto LAB_45035d14;
        }
LAB_45035ae7:
        bVar2 = true;
        iVar8 = 6;
      }
      goto LAB_45035a34;
    case 5:
      bVar4 = true;
      pcVar17 = local_54;
      if ((byte)(local_59 - 0x30U) < 10) {
        iVar8 = 4;
        goto LAB_45035a53;
      }
      goto LAB_45035d14;
    case 6:
      local_54 = pcVar17 + -1;
      if ((byte)(local_59 - 0x31U) < 9) goto LAB_45035c31;
      if (local_59 == '+') goto LAB_45035c62;
      if (local_59 == '-') {
        iVar8 = 7;
        local_70 = -1;
      }
      else {
LAB_45035c47:
        pcVar17 = local_54;
        if (local_59 != '0') goto LAB_45035d14;
        iVar8 = 8;
      }
      goto LAB_45035a34;
    case 7:
      if (8 < (byte)(local_59 - 0x31U)) goto LAB_45035c47;
      goto LAB_45035c31;
    case 8:
      bVar3 = true;
      while (local_59 == '0') {
        local_59 = *param_3;
        param_3 = param_3 + 1;
      }
      if ((byte)(local_59 - 0x31U) < 9) {
LAB_45035c31:
        iVar8 = 9;
        goto LAB_45035a53;
      }
      goto LAB_45035d10;
    case 9:
      iVar22 = 0;
      bVar3 = true;
      goto LAB_45035cf2;
    default:
      goto switchD_45035a43_caseD_a;
    case 0xb:
      if (param_7 != 0) {
        local_54 = pcVar17;
        if (local_59 == '+') {
LAB_45035c62:
          iVar8 = 7;
        }
        else {
          if (local_59 != '-') goto LAB_45035d14;
          local_70 = -1;
          iVar8 = 7;
        }
        goto LAB_45035a34;
      }
      iVar8 = 10;
      param_3 = pcVar17;
switchD_45035a43_caseD_a:
      pcVar17 = param_3;
      if (iVar8 != 10) goto LAB_45035a34;
      goto LAB_45035d14;
    }
    iVar8 = 3;
LAB_45035a53:
    param_3 = param_3 + -1;
    goto LAB_45035a34;
  }
  piVar9 = __errno();
  *piVar9 = 0x16;
  FUN_45027e29();
  uVar27 = CONCAT22(local_40._2_2_,(undefined2)local_40);
  goto LAB_4503611b;
LAB_45035cf2:
  if ((local_59 < '0') || ('9' < local_59)) goto LAB_45035d0b;
  iVar22 = local_59 + -0x30 + iVar22 * 10;
  if (iVar22 < 0x1451) {
    local_59 = *param_3;
    param_3 = param_3 + 1;
    goto LAB_45035cf2;
  }
  iVar22 = 0x1451;
LAB_45035d0b:
  while (('/' < local_59 && (local_59 < ':'))) {
    local_59 = *param_3;
    param_3 = param_3 + 1;
  }
LAB_45035d10:
  pcVar17 = param_3 + -1;
LAB_45035d14:
  *param_2 = (int)pcVar17;
  if (bVar2) {
    if (0x18 < local_50) {
      if ('\x04' < local_d) {
        local_d = local_d + '\x01';
      }
      pcVar26 = pcVar26 + -1;
      local_58 = local_58 + 1;
      local_50 = 0x18;
    }
    if (local_50 == 0) {
      local_40._0_2_ = 0;
      uVar21 = 0;
      uVar25 = 0;
      uVar19 = 0;
    }
    else {
      pcVar26 = pcVar26 + -1;
      cVar1 = *pcVar26;
      while (cVar1 == '\0') {
        local_50 = local_50 - 1;
        local_58 = local_58 + 1;
        pcVar26 = pcVar26 + -1;
        cVar1 = *pcVar26;
      }
      FUN_45037a27(local_24,local_50,&local_40);
      uVar27 = CONCAT22(local_40._2_2_,(undefined2)local_40);
      if (local_70 < 0) {
        iVar22 = -iVar22;
      }
      uVar23 = iVar22 + local_58;
      if (!bVar3) {
        uVar23 = uVar23 + param_5;
      }
      if (!bVar4) {
        uVar23 = uVar23 - param_6;
      }
      if (0x1450 < (int)uVar23) {
        uVar21 = 0x7fff;
        uVar25 = 0x80000000;
        goto LAB_45036101;
      }
      if ((int)uVar23 < -0x1450) {
        local_40._0_2_ = 0;
        uVar21 = 0;
        uVar25 = 0;
        uVar19 = 0;
      }
      else {
        iVar22 = 0x450528c8;
        iVar8 = uStack_4a;
        uVar13 = uStack_38;
        uVar28 = uStack_2e;
        uVar16 = uStack_2a;
        if (uVar23 != 0) {
          if ((int)uVar23 < 0) {
            uVar23 = -uVar23;
            iVar22 = 0x45052a28;
          }
          iVar8 = CONCAT22(uStack_4a._2_2_,(undefined2)uStack_4a);
          uVar13 = CONCAT22(uStack_38._2_2_,(undefined2)uStack_38);
          uVar28 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e);
          uVar16 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a);
          if (param_4 == 0) {
            local_40._0_2_ = 0;
            iVar8 = uStack_4a;
            uVar13 = uStack_38;
            uVar28 = uStack_2e;
            uVar16 = uStack_2a;
            uVar27 = (uint)local_40._2_2_ << 0x10;
          }
LAB_450360ba:
          do {
            uStack_38._2_2_ = (ushort)(uVar13 >> 0x10);
            iVar20 = 0;
            if (uVar23 == 0) break;
            iVar22 = iVar22 + 0x54;
            uVar24 = (int)uVar23 >> 3;
            uVar10 = uVar23 & 7;
            uVar23 = uVar24;
            if (uVar10 != 0) {
              puVar14 = (ushort *)(uVar10 * 0xc + iVar22);
              puVar15 = puVar14;
              if (0x7fff < *puVar14) {
                puVar15 = &local_4c;
                local_4c = (ushort)*(undefined4 *)puVar14;
                uStack_4a._0_2_ = (undefined2)((uint)*(undefined4 *)puVar14 >> 0x10);
                uStack_4a._2_2_ = (undefined2)*(undefined4 *)(puVar14 + 2);
                uStack_46 = (undefined2)((uint)*(undefined4 *)(puVar14 + 2) >> 0x10);
                local_44 = *(undefined4 *)(puVar14 + 4);
                iVar8 = CONCAT22(uStack_4a._2_2_,(undefined2)uStack_4a) + -1;
                uStack_4a._0_2_ = (undefined2)iVar8;
                uStack_4a._2_2_ = (undefined2)((uint)iVar8 >> 0x10);
              }
              uVar6 = (puVar15[5] ^ uStack_38._2_2_) & 0x8000;
              local_30 = 0;
              uStack_2f = 0;
              uStack_2e._0_2_ = 0;
              uStack_2e._2_2_ = 0;
              uVar10 = 0;
              uVar28 = 0;
              uVar7 = puVar15[5] & 0x7fff;
              uVar21 = uVar7 + (uStack_38._2_2_ & 0x7fff);
              uStack_26 = (ushort)uStack_2e;
              uVar16 = uVar28;
              if ((((uStack_38._2_2_ & 0x7fff) < 0x7fff) && (uVar7 < 0x7fff)) && (uVar21 < 0xbffe))
              {
                if (0x3fbf < uVar21) {
                  if ((((uVar13 & 0x7fff0000) == 0) &&
                      (uVar21 = uVar21 + 1, (uVar13 & 0x7fffffff) == 0)) &&
                     ((CONCAT22(uStack_3a,uStack_3c) == 0 && (uVar27 == 0)))) {
                    uStack_38._2_2_ = 0;
                    uVar13 = uVar13 & 0xffff;
                    goto LAB_450360ba;
                  }
                  if (((uVar7 != 0) ||
                      (uVar21 = uVar21 + 1, (*(uint *)(puVar15 + 4) & 0x7fffffff) != 0)) ||
                     ((*(int *)(puVar15 + 2) != 0 || (*(int *)puVar15 != 0)))) {
                    psVar18 = (short *)((int)&uStack_2e + 2);
                    local_6c = 5;
                    iVar12 = iVar20;
                    uStack_2a._0_2_ = (ushort)uStack_2e;
                    uStack_2a._2_2_ = uStack_2e._2_2_;
                    do {
                      if (0 < (int)local_6c) {
                        puVar14 = (ushort *)((int)&local_40 + iVar12 * 2);
                        local_68 = puVar15 + 4;
                        uVar27 = local_6c;
                        do {
                          uVar16 = (uint)*puVar14 * (uint)*local_68 + *(int *)(psVar18 + -2);
                          if ((uVar16 < *(uint *)(psVar18 + -2)) ||
                             (iVar11 = iVar20, uVar16 < (uint)*puVar14 * (uint)*local_68)) {
                            iVar11 = 1;
                          }
                          *(uint *)(psVar18 + -2) = uVar16;
                          if (iVar11 != 0) {
                            *psVar18 = *psVar18 + 1;
                          }
                          local_68 = local_68 + -1;
                          puVar14 = puVar14 + 1;
                          uVar27 = uVar27 + -1;
                        } while (0 < (int)uVar27);
                      }
                      psVar18 = psVar18 + 1;
                      iVar12 = iVar12 + 1;
                      local_6c = local_6c + -1;
                    } while (0 < (int)local_6c);
                    local_54 = (char *)CONCAT22(uStack_26,uStack_2a._2_2_);
                    uVar21 = uVar21 + 0xc002;
                    uVar27 = CONCAT22((ushort)uStack_2e,CONCAT11(uStack_2f,local_30));
                    if ((short)uVar21 < 1) {
LAB_45035f89:
                      uVar21 = uVar21 - 1;
                      if (-1 < (short)uVar21) goto LAB_45035ff2;
                      local_6c = (uint)(ushort)-uVar21;
                      uVar21 = 0;
                      pcVar26 = local_54;
                      do {
                        if ((local_30 & 1) != 0) {
                          iVar20 = iVar20 + 1;
                        }
                        uVar16 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_);
                        uStack_2a._0_2_ =
                             (ushort)uStack_2a >> 1 | (ushort)((uint)((int)pcVar26 << 0x1f) >> 0x10)
                        ;
                        uVar28 = uVar27 >> 1;
                        local_54 = (char *)((uint)pcVar26 >> 1);
                        uVar27 = uVar28 | uVar16 << 0x1f;
                        local_6c = local_6c - 1;
                        uStack_2a._2_2_ = (ushort)local_54;
                        uStack_26 = (ushort)((uint)pcVar26 >> 0x11);
                        uStack_2e._2_2_ = (ushort)(uVar16 >> 1);
                        local_30 = (byte)uVar28;
                        uStack_2f = (undefined1)(uVar28 >> 8);
                        uStack_2e._0_2_ = (ushort)(uVar27 >> 0x10);
                        pcVar26 = local_54;
                      } while (local_6c != 0);
                      if (iVar20 == 0) goto LAB_45035ff2;
                      uVar7 = (ushort)uVar28 | 1;
                      local_30 = (byte)uVar7;
                      uVar27 = CONCAT22((ushort)uStack_2e,(ushort)uVar28) | 1;
                    }
                    else {
                      do {
                        if ((int)local_54 < 0) break;
                        iVar12 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_) * 2;
                        uVar7 = (ushort)uStack_2a >> 0xf;
                        uStack_2e._2_2_ = (ushort)iVar12 | (ushort)(uVar27 >> 0x1f);
                        uVar27 = uVar27 * 2;
                        uStack_2a._0_2_ = (ushort)((uint)iVar12 >> 0x10);
                        uVar16 = (int)local_54 * 2;
                        local_30 = (byte)uVar27;
                        uStack_2f = (undefined1)(uVar27 >> 8);
                        uStack_2e._0_2_ = (ushort)(uVar27 >> 0x10);
                        local_54 = (char *)(uVar16 | uVar7);
                        uVar21 = uVar21 - 1;
                        uStack_2a._2_2_ = (ushort)local_54;
                        uStack_26 = (ushort)(uVar16 >> 0x10);
                      } while (0 < (short)uVar21);
                      if ((short)uVar21 < 1) goto LAB_45035f89;
LAB_45035ff2:
                      uVar7 = CONCAT11(uStack_2f,local_30);
                    }
                    uVar28 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e);
                    uVar16 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a);
                    if ((0x8000 < uVar7) || ((uVar27 & 0x1ffff) == 0x18000)) {
                      if (CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e) == -1) {
                        uStack_2e._0_2_ = 0;
                        uStack_2e._2_2_ = 0;
                        uVar28 = 0;
                        if (CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a) == -1) {
                          uStack_2a._0_2_ = 0;
                          uStack_2a._2_2_ = 0;
                          uVar16 = 0;
                          if (uStack_26 == 0xffff) {
                            uStack_26 = 0x8000;
                            uVar21 = uVar21 + 1;
                            uVar16 = 0;
                          }
                          else {
                            uStack_26 = uStack_26 + 1;
                          }
                        }
                        else {
                          uVar16 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a) + 1;
                          uStack_2a._0_2_ = (ushort)uVar16;
                          uStack_2a._2_2_ = (ushort)(uVar16 >> 0x10);
                        }
                        uStack_2a._2_2_ = (ushort)(uVar16 >> 0x10);
                        local_54 = (char *)CONCAT22(uStack_26,uStack_2a._2_2_);
                      }
                      else {
                        uVar28 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e) + 1;
                        uStack_2e._0_2_ = (ushort)uVar28;
                        uStack_2e._2_2_ = (ushort)(uVar28 >> 0x10);
                      }
                    }
                    uStack_2a._0_2_ = (ushort)uVar16;
                    if (uVar21 < 0x7fff) {
                      local_40 = uVar28;
                      uStack_3c = (ushort)uStack_2a;
                      uStack_3a = SUB42(local_54,0);
                      uStack_38._0_2_ = (undefined2)((uint)local_54 >> 0x10);
                      uStack_38._2_2_ = uVar21 | uVar6;
                      uVar13 = CONCAT22(uVar21 | uVar6,(undefined2)uStack_38);
                      uVar27 = uVar28;
                    }
                    else {
                      uStack_3c = 0;
                      uStack_3a = 0;
                      local_40._0_2_ = 0;
                      local_40._2_2_ = 0;
                      uVar13 = ((uVar6 == 0) - 1 & 0x80000000) + 0x7fff8000;
                      uStack_38._0_2_ = (undefined2)uVar13;
                      uStack_38._2_2_ = (ushort)(uVar13 >> 0x10);
                      uVar27 = 0;
                    }
                    goto LAB_450360ba;
                  }
                }
              }
              else {
                uVar10 = ((uVar6 == 0) - 1 & 0x80000000) + 0x7fff8000;
                uStack_38._0_2_ = (undefined2)uVar10;
                uStack_38._2_2_ = (ushort)(uVar10 >> 0x10);
              }
              uStack_3c = 0;
              uStack_3a = 0;
              local_40._0_2_ = 0;
              local_40._2_2_ = 0;
              uVar27 = 0;
              uVar13 = uVar10;
            }
          } while( true );
        }
        local_40._2_2_ = (ushort)(uVar27 >> 0x10);
        local_40._0_2_ = (undefined2)uVar27;
        uStack_38._2_2_ = (ushort)(uVar13 >> 0x10);
        uStack_38._0_2_ = (undefined2)uVar13;
        uVar19 = CONCAT22(uStack_3c,local_40._2_2_);
        uVar25 = CONCAT22((undefined2)uStack_38,uStack_3a);
        uVar21 = uStack_38._2_2_;
        uStack_4a = iVar8;
        uStack_38 = uVar13;
        uStack_2e = uVar28;
        uStack_2a = uVar16;
      }
    }
  }
  else {
    uVar21 = 0;
    uVar25 = 0;
LAB_45036101:
    uVar27 = CONCAT22(local_40._2_2_,(undefined2)local_40);
    local_40._0_2_ = 0;
    uVar19 = 0;
  }
  param_1[5] = uVar21 | uVar5;
  *param_1 = (undefined2)local_40;
  *(undefined4 *)(param_1 + 1) = uVar19;
  *(undefined4 *)(param_1 + 3) = uVar25;
LAB_4503611b:
  local_40 = uVar27;
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



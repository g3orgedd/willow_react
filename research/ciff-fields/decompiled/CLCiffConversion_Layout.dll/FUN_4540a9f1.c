// Source: CLCiffConversion_Layout.dll @ 4540a9f1; FUN_4540a9f1

int __thiscall FUN_4540a9f1(void *this,undefined4 param_1,uint param_2)

{
  int *piVar1;
  int *this_00;
  int *piVar2;
  byte bVar3;
  bool bVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined8 *puVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  bool bVar19;
  uint local_40;
  int local_3c;
  uint local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  uint local_10;
  uint local_c;
  
  if ((*(int *)((int)this + 0x104) == 0) || (*(int *)this == 0)) {
    iVar18 = -0x7fff0001;
  }
  else {
    local_28 = 0;
    local_30 = 0;
    if (*(int *)this != 0) {
      do {
        local_10 = 0;
        local_20 = 0;
        local_18 = -1;
        uVar15 = 0xffffffff;
        local_c = 0xffffffff;
        local_24 = 0xffffffff;
        bVar4 = false;
        local_2c = 0;
        iVar18 = local_30 * 0x18 + *(int *)((int)this + 0xc);
        uVar16 = 0xffffffff;
        if (*(int *)(iVar18 + 0xc) != 0) {
          piVar1 = (int *)((int)this + 0x24);
          do {
            local_1c = (*(int *)(iVar18 + 8) + local_2c) * 0x20 + *(int *)((int)this + 0x24);
            iVar12 = *(int *)(local_1c + 8) - *(int *)((int)this + 0x100) >> 1;
            iVar6 = ScriptBreak(*(undefined4 *)(local_1c + 8),*(undefined4 *)(local_1c + 0xc),
                                (ushort *)(local_1c + 4),*(int *)((int)this + 0x6c) + iVar12);
            if (iVar6 < 0) {
              return iVar6;
            }
            if (local_10 != 0) {
              if ((*(ushort *)(local_1c + 4) & 0x400) == 0) {
                iVar6 = 0;
              }
              else {
                iVar6 = *(int *)(local_1c + 0x10) + -1;
              }
              if ((*(byte *)((uint)*(ushort *)(*(int *)((int)this + 0x90) + (iVar6 + iVar12) * 2) +
                             *(int *)((int)this + 0x6c) + iVar12) & 1) != 0) {
                iVar6 = (*(int *)(iVar18 + 8) + local_2c) * 0x20;
                local_c = local_2c - 1;
                if ((*(ushort *)(iVar6 + -0x1c + *(int *)((int)this + 0x24)) & 0x400) == 0) {
                  uVar15 = *(int *)(iVar6 + -0x10 + *(int *)((int)this + 0x24)) - 1;
                }
                else {
                  uVar15 = 0;
                }
                local_18 = *(int *)(*(int *)((int)this + 0x84) + uVar15 * 4);
                local_20 = local_20 + local_10;
                local_10 = 0;
                local_24 = uVar15;
              }
            }
            this_00 = (int *)((int)this + 0x84);
            if ((uint)(*(int *)((int)this + 0x88) - *this_00 >> 2) < *(uint *)(local_1c + 0x10)) {
              FUN_4540d58f(this_00,*(uint *)(local_1c + 0x10));
            }
            if ((uint)(*(int *)((int)this + 0x7c) - *(int *)((int)this + 0x78)) <
                *(uint *)(local_1c + 0x10)) {
              FUN_4540d67a((void *)((int)this + 0x78),*(uint *)(local_1c + 0x10));
            }
            FUN_45429f70(*(uint **)((int)this + 0x84),0xff,*(int *)(local_1c + 0x10) << 2);
            FUN_45429f70(*(uint **)((int)this + 0x78),0,*(uint *)(local_1c + 0x10));
            local_40 = 0xffffffff;
            if (*(int *)(local_1c + 0xc) != 0) {
              uVar16 = 0;
              local_3c = iVar12 * 2;
              do {
                uVar13 = (uint)*(ushort *)(local_3c + *(int *)((int)this + 0x90));
                if (uVar13 != local_40) {
                  *(uint *)(*(int *)((int)this + 0x84) + uVar13 * 4) = uVar16;
                  FUN_45429920((undefined8 *)(*(int *)((int)this + 0x78) + uVar13),
                               (undefined8 *)(*(int *)((int)this + 0x6c) + uVar16 + iVar12),1);
                }
                local_3c = local_3c + 2;
                uVar16 = uVar16 + 1;
                uVar15 = local_24;
                local_40 = uVar13;
              } while (uVar16 < *(uint *)(local_1c + 0xc));
            }
            uVar16 = *(uint *)(local_1c + 0x10);
            local_34 = 0;
            if (uVar16 != 0) {
              do {
                uVar5 = *(ushort *)(local_1c + 4) >> 10 & 1;
                uVar13 = local_34;
                if (uVar5 != 0) {
                  uVar13 = (uVar16 - local_34) - 1;
                }
                iVar6 = *(int *)(*(int *)((int)this + 0x48) +
                                (*(int *)(local_1c + 0x14) + uVar13) * 4);
                uVar7 = local_20 + iVar6 + local_10;
                if ((param_2 < uVar7) && ((*(byte *)(uVar13 + *(int *)((int)this + 0x78)) & 2) == 0)
                   ) {
                  if ((((int)local_c < 0) || ((int)uVar15 < 0)) || (local_18 < 0)) {
                    local_c = 0xffffffff;
                  }
                  else {
                    iVar14 = *(int *)(iVar18 + 0x10);
                    iVar12 = iVar14 + 1;
                    *(int *)(iVar18 + 0x10) = iVar12;
                    if (iVar14 == 0) {
                      *(int *)(iVar18 + 0x14) = local_28;
                    }
                    uVar16 = iVar12 + local_28;
                    if ((uint)(*(int *)((int)this + 0xdc) - *(int *)((int)this + 0xd8) >> 2) <
                        uVar16) {
                      FUN_4540d58f((void *)((int)this + 0xd8),uVar16);
                    }
                    if ((local_18 == 0) ||
                       (local_18 ==
                        *(int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0xc +
                                *(int *)((int)this + 0x24)) + -1)) {
                      *(uint *)(*(int *)((int)this + 0xd8) + local_28 * 4) = local_c;
                      local_10 = local_10 + iVar6;
                      FUN_4540ccfc(this,*(int *)(iVar18 + 8),local_c,uVar15);
                    }
                    else {
                      puVar10 = (undefined1 *)(*(int *)((int)this + 8) + 1);
                      if ((undefined1 *)
                          (*(int *)((int)this + 0x28) - *(int *)((int)this + 0x24) >> 5) < puVar10)
                      {
                        FUN_4540d7f6((void *)((int)this + 0x24),puVar10);
                      }
                      uVar16 = *(int *)((int)this + 8) + 1;
                      if ((uint)(*(int *)((int)this + 0xa0) - *(int *)((int)this + 0x9c)) < uVar16)
                      {
                        FUN_4540d4e9((int *)((int)this + 0x9c),uVar16);
                      }
                      uVar16 = *(int *)((int)this + 8) + 1;
                      if ((uint)(*(int *)((int)this + 0xac) - *(int *)((int)this + 0xa8) >> 2) <
                          uVar16) {
                        FUN_4540d58f((int *)((int)this + 0xa8),uVar16);
                      }
                      puVar11 = (undefined8 *)
                                ((*(int *)(iVar18 + 8) + local_c) * 0x20 +
                                *(int *)((int)this + 0x24));
                      FUN_4542a090(puVar11 + 4,puVar11,
                                   ((*(int *)((int)this + 8) - *(int *)(iVar18 + 8)) - local_c) *
                                   0x20);
                      puVar11 = (undefined8 *)
                                (*(int *)((int)this + 0x9c) + *(int *)(iVar18 + 8) + local_c);
                      FUN_4542a090((undefined8 *)((int)puVar11 + 1),puVar11,
                                   (*(int *)((int)this + 8) - *(int *)(iVar18 + 8)) - local_c);
                      puVar11 = (undefined8 *)
                                (*(int *)((int)this + 0xa8) + (local_c + *(int *)(iVar18 + 8)) * 4);
                      FUN_4542a090((undefined8 *)((int)puVar11 + 4),puVar11,
                                   ((*(int *)((int)this + 8) - *(int *)(iVar18 + 8)) - local_c) * 4)
                      ;
                      iVar14 = 0;
                      *(int *)(iVar18 + 0xc) = *(int *)(iVar18 + 0xc) + 1;
                      iVar12 = (*(int *)(iVar18 + 8) + local_c) * 0x20;
                      iVar6 = *piVar1;
                      local_3c = 0;
                      if ((*(ushort *)(iVar12 + 4 + iVar6) & 0x400) == 0) {
                        if (0 < (int)uVar15) {
                          pbVar8 = (byte *)(*(int *)((int)this + 0x78) + -1 + uVar15);
                          do {
                            if ((*pbVar8 & 2) == 0) break;
                            iVar14 = iVar14 + 1;
                            pbVar8 = pbVar8 + -1;
                          } while (iVar14 < (int)uVar15);
                        }
                        *(uint *)(iVar12 + 0x10 + iVar6) = uVar15 - iVar14;
                        piVar2 = (int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x34 +
                                        *(int *)((int)this + 0x24));
                        *piVar2 = *piVar2 + uVar15;
                        piVar2 = (int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x30 +
                                        *(int *)((int)this + 0x24));
                        *piVar2 = *piVar2 - uVar15;
                        *(undefined4 *)
                         ((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0xc + *(int *)((int)this + 0x24)
                         ) = *(undefined4 *)(*(int *)((int)this + 0x84) + (uVar15 - iVar14) * 4);
                        piVar2 = (int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x28 +
                                        *(int *)((int)this + 0x24));
                        *piVar2 = *piVar2 + local_18 * 2;
                        piVar2 = (int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x2c +
                                        *(int *)((int)this + 0x24));
                        *piVar2 = *piVar2 - local_18;
                        iVar6 = (*(int *)(iVar18 + 8) + 1 + local_c) * 0x20 +
                                *(int *)((int)this + 0x24);
                        local_10 = uVar15;
                      }
                      else {
                        local_10 = uVar15 + 1;
                        if (local_10 < *(uint *)(iVar12 + 0x10 + iVar6)) {
                          uVar16 = local_10;
                          do {
                            uVar15 = local_24;
                            local_3c = iVar14;
                            if ((*(byte *)(*(int *)((int)this + 0x78) + uVar16) & 2) == 0) break;
                            iVar14 = iVar14 + 1;
                            uVar16 = uVar16 + 1;
                            local_3c = iVar14;
                          } while (uVar16 < *(uint *)(iVar12 + 0x10 + iVar6));
                        }
                        piVar2 = (int *)(iVar12 + 0x14 + iVar6);
                        *piVar2 = *piVar2 + local_3c + 1 + uVar15;
                        piVar2 = (int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x10 + *piVar1);
                        *piVar2 = *piVar2 + ((-1 - local_3c) - uVar15);
                        *(uint *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x30 + *piVar1) =
                             local_10;
                        *(undefined4 *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0xc + *piVar1) =
                             *(undefined4 *)(*this_00 + (local_3c + uVar15) * 4);
                        piVar2 = (int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x28 + *piVar1);
                        *piVar2 = *piVar2 + local_18 * 2;
                        piVar2 = (int *)((*(int *)(iVar18 + 8) + local_c) * 0x20 + 0x2c + *piVar1);
                        *piVar2 = *piVar2 - local_18;
                        iVar6 = (*(int *)(iVar18 + 8) + local_c) * 0x20 + *piVar1;
                      }
                      *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
                      uVar16 = local_30 + 1;
                      if (uVar16 < *(uint *)this) {
                        iVar12 = uVar16 * 0x18;
                        do {
                          piVar2 = (int *)(iVar12 + 8 + *(int *)((int)this + 0xc));
                          *piVar2 = *piVar2 + 1;
                          uVar16 = uVar16 + 1;
                          iVar12 = iVar12 + 0x18;
                        } while (uVar16 < *(uint *)this);
                      }
                      if (0 < *(int *)(iVar6 + 0xc)) {
                        iVar14 = (*(int *)(iVar6 + 8) - *(int *)((int)this + 0x100) >> 1) * 2;
                        iVar12 = 0;
                        do {
                          uVar5 = *(ushort *)(iVar14 + *(int *)((int)this + 0x90));
                          if ((int)local_10 <= (int)(uint)uVar5) {
                            *(ushort *)(iVar14 + *(int *)((int)this + 0x90)) =
                                 uVar5 - (short)local_10;
                          }
                          iVar12 = iVar12 + 1;
                          iVar14 = iVar14 + 2;
                        } while (iVar12 < *(int *)(iVar6 + 0xc));
                      }
                      local_1c = (*(int *)(iVar18 + 8) + local_2c) * 0x20 +
                                 *(int *)((int)this + 0x24);
                      local_40 = 0;
                      do {
                        iVar6 = (*(int *)(iVar18 + 8) + local_40 + local_c) * 0x20 +
                                *(int *)((int)this + 0x24);
                        *(undefined4 *)(iVar6 + 0x18) = 0;
                        if (0 < *(int *)(iVar6 + 0x10)) {
                          iVar14 = 0;
                          iVar17 = *(int *)(iVar6 + 0x10);
                          iVar12 = *(int *)(iVar6 + 0x14) << 2;
                          do {
                            iVar14 = iVar14 + *(int *)(*(int *)((int)this + 0x48) + iVar12);
                            iVar12 = iVar12 + 4;
                            *(int *)(iVar6 + 0x18) = iVar14;
                            iVar17 = iVar17 + -1;
                          } while (iVar17 != 0);
                        }
                        local_40 = local_40 + 1;
                      } while ((int)local_40 < 2);
                      local_10 = 0;
                      *(uint *)(*(int *)((int)this + 0xd8) + local_28 * 4) = local_c;
                    }
                    if (local_28 == *(int *)(iVar18 + 0x14)) {
                      uVar16 = 0;
                    }
                    else {
                      uVar16 = *(int *)(*(int *)((int)this + 0xd8) + -4 + local_28 * 4) + 1;
                    }
                    if (uVar16 < *(uint *)(iVar18 + 0xc)) {
                      ScriptLayout((local_c - uVar16) + 1,
                                   *(int *)((int)this + 0x9c) + *(int *)(iVar18 + 8) + uVar16,
                                   *(int *)((int)this + 0xa8) + (*(int *)(iVar18 + 8) + uVar16) * 4,
                                   0);
                      iVar6 = uVar16 - local_c;
                      uVar15 = uVar16;
                      while (uVar15 == local_c || SBORROW4(uVar15,local_c) != iVar6 < 0) {
                        piVar2 = (int *)(*(int *)((int)this + 0xa8) +
                                        (*(int *)(iVar18 + 8) + uVar15) * 4);
                        *piVar2 = *piVar2 + uVar16;
                        uVar15 = uVar15 + 1;
                        iVar6 = uVar15 - local_c;
                      }
                    }
                    local_28 = local_28 + 1;
                    uVar15 = 0xffffffff;
                    *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
                    local_c = 0xffffffff;
                    local_20 = 0;
                    local_24 = 0xffffffff;
                    bVar4 = false;
                  }
                }
                else {
                  uVar9 = uVar16 - 1;
                  if (local_34 < uVar9) {
                    if (uVar5 == 0) {
                      if (uVar13 < uVar9) {
                        bVar3 = *(byte *)(uVar13 + 1 + *(int *)((int)this + 0x78));
                        goto LAB_4540b0dc;
                      }
LAB_4540b0e3:
                      bVar19 = false;
                    }
                    else {
                      if (uVar13 == 0) goto LAB_4540b0e3;
                      bVar3 = *(byte *)((uVar13 - 1) + *(int *)((int)this + 0x78));
LAB_4540b0dc:
                      if ((bVar3 & 1) == 0) goto LAB_4540b0e3;
                      bVar19 = true;
                    }
                    bVar4 = (bool)(bVar4 | bVar19);
                    if (bVar4) {
LAB_4540b17c:
                      bVar19 = !bVar19;
joined_r0x4540b17e:
                      if (bVar19) goto LAB_4540b109;
                    }
                    else if (!bVar19) {
                      if (uVar5 != 0) {
                        if (uVar13 == 0) goto LAB_4540b109;
                        bVar19 = (*(byte *)((uVar13 - 1) + *(int *)((int)this + 0x78)) & 4) == 0;
                        goto joined_r0x4540b17e;
                      }
                      if ((uVar9 <= uVar13) ||
                         ((*(byte *)(uVar13 + 1 + *(int *)((int)this + 0x78)) & 4) == 0)) {
                        bVar19 = false;
                        goto LAB_4540b17c;
                      }
                    }
                    local_c = local_2c;
                    uVar15 = uVar13 + 1;
                    if (uVar5 != 0) {
                      uVar15 = uVar13 - 1;
                    }
                    if (((int)uVar15 < 0) || ((int)uVar16 <= (int)uVar15)) {
                      local_18 = -1;
                    }
                    else {
                      local_18 = *(int *)(*(int *)((int)this + 0x84) + uVar15 * 4);
                    }
                    local_10 = 0;
                    local_24 = uVar15;
                    local_20 = uVar7;
                  }
                  else {
                    if ((*(byte *)(uVar13 + *(int *)((int)this + 0x78)) & 2) != 0) {
                      local_c = local_2c;
                      if (uVar5 == 0) {
                        uVar15 = uVar16 - 1;
                      }
                      else {
                        uVar15 = 0;
                      }
                      local_10 = 0;
                      local_18 = *(int *)(*(int *)((int)this + 0x84) + uVar15 * 4);
                      bVar4 = true;
                      local_24 = uVar15;
                      local_20 = uVar7;
                      goto LAB_4540b10f;
                    }
LAB_4540b109:
                    local_10 = local_10 + iVar6;
                  }
                }
LAB_4540b10f:
                local_34 = local_34 + 1;
                uVar16 = *(uint *)(local_1c + 0x10);
              } while (local_34 < uVar16);
            }
            local_2c = local_2c + 1;
          } while (local_2c < *(uint *)(iVar18 + 0xc));
          uVar16 = local_c;
          if (local_10 != 0) {
            iVar6 = (*(int *)(iVar18 + 8) + *(int *)(iVar18 + 0xc)) * 0x20;
            if ((*(ushort *)(iVar6 + -0x1c + *(int *)((int)this + 0x24)) & 0x400) == 0) {
              uVar15 = *(int *)(iVar6 + -0x10 + *(int *)((int)this + 0x24)) - 1;
            }
            else {
              uVar15 = 0;
            }
            local_20 = local_20 + local_10;
            uVar16 = *(int *)(iVar18 + 0xc) - 1;
          }
        }
        if ((*(int *)(iVar18 + 0x10) != 0) && (-1 < (int)uVar16)) {
          FUN_4540ccfc(this,*(int *)(iVar18 + 8),uVar16,uVar15);
          if (local_28 == *(int *)(iVar18 + 0x14)) {
            uVar16 = 0;
          }
          else {
            uVar16 = *(int *)(*(int *)((int)this + 0xd8) + -4 + local_28 * 4) + 1;
          }
          iVar6 = *(uint *)(iVar18 + 0xc) - 1;
          if (uVar16 < *(uint *)(iVar18 + 0xc)) {
            ScriptLayout((iVar6 - uVar16) + 1,
                         *(int *)((int)this + 0x9c) + *(int *)(iVar18 + 8) + uVar16,
                         *(int *)((int)this + 0xa8) + (*(int *)(iVar18 + 8) + uVar16) * 4,0);
            for (uVar15 = uVar16; (int)uVar15 <= iVar6; uVar15 = uVar15 + 1) {
              piVar1 = (int *)(*(int *)((int)this + 0xa8) + (*(int *)(iVar18 + 8) + uVar15) * 4);
              *piVar1 = *piVar1 + uVar16;
            }
          }
        }
        local_30 = local_30 + 1;
        *(uint *)((int)this + 0xfc) = local_20;
      } while (local_30 < *(uint *)this);
    }
    iVar18 = 0;
  }
  return iVar18;
}



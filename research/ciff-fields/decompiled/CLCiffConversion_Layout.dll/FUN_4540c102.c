// Source: CLCiffConversion_Layout.dll @ 4540c102; FUN_4540c102

void __thiscall
FUN_4540c102(void *this,HDC param_1,int param_2,int param_3,undefined4 param_4,int param_5,
            int param_6,char param_7,int *param_8,int *param_9,undefined4 param_10)

{
  int *this_00;
  HGDIOBJ h;
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  int local_70;
  uint local_68;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int local_50;
  uint local_4c;
  uint local_44;
  int local_40;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  int local_20;
  int local_1c;
  undefined4 local_18 [2];
  short local_e;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_4545d9f0 ^ (uint)&stack0xfffffffc;
  if ((*(int *)((int)this + 0x104) == 0) || (*(int *)this == 0)) goto LAB_4540c751;
  local_58 = 0;
  local_50 = 0;
  if (param_8 != (int *)0x0) {
    if (param_6 == 0) {
LAB_4540c168:
      local_50 = param_8[2] - *param_8;
      local_58 = param_8[3] - param_8[1];
    }
    else {
      if (param_6 != 1) {
        if (param_6 == 2) goto LAB_4540c168;
        if (param_6 != 3) goto LAB_4540c179;
      }
      local_50 = param_8[3] - param_8[1];
      local_58 = param_8[2] - *param_8;
    }
  }
LAB_4540c179:
  if ((uint)(*(int *)((int)this + 0xe8) - *(int *)((int)this + 0xe4) >> 2) <
      *(uint *)((int)this + 4)) {
    FUN_4540d58f((int *)((int)this + 0xe4),*(uint *)((int)this + 4));
  }
  if ((param_5 == 3) &&
     (this_00 = (int *)((int)this + 0xf0),
     (uint)(*(int *)((int)this + 0xf4) - *this_00 >> 2) < *(uint *)((int)this + 4))) {
    FUN_4540d58f(this_00,*(uint *)((int)this + 4));
    FUN_45429f70((uint *)*this_00,0,*(int *)((int)this + 4) << 2);
  }
  local_4c = 0;
  uVar10 = 10;
  local_54 = 10;
  bVar1 = false;
  local_40 = 0;
  do {
    local_60 = 0;
    if (local_40 == 0) {
      if (param_5 != 0) goto LAB_4540c1f5;
    }
    else {
      if (local_40 == 1) {
        if (param_5 != 3) goto LAB_4540c737;
        local_18[0] = 0x10;
        iVar7 = ScriptGetFontProperties(param_1,param_10,local_18);
        if (iVar7 < 0) break;
        local_54 = uVar10;
        if (local_e != 1) {
          local_54 = local_c;
        }
        if ((uint)(*(int *)((int)this + 0xb8) - *(int *)((int)this + 0xb4) >> 1) < local_4c) {
          FUN_4540d6eb((int *)((int)this + 0xb4),local_4c);
        }
        if ((uint)(*(int *)((int)this + 0xc4) - *(int *)((int)this + 0xc0) >> 2) < local_4c) {
          FUN_4540d58f((int *)((int)this + 0xc0),local_4c);
        }
        if ((uint)(*(int *)((int)this + 0xd0) - *(int *)((int)this + 0xcc) >> 2) < local_4c) {
          FUN_4540d58f((int *)((int)this + 0xcc),local_4c);
        }
LAB_4540c1f5:
        local_1c = 0;
        iVar7 = 0;
        iVar9 = local_1c;
      }
      else {
        local_60 = param_6;
        if (local_40 != 2) goto LAB_4540c1f5;
        FUN_4540c76f(this,0,&local_20,&local_1c,param_2,param_3,local_50,param_5,param_6);
        iVar7 = local_20;
        iVar9 = param_3;
        if ((param_6 != 0) && (iVar7 = param_2, iVar9 = local_1c, param_6 != 1)) {
          if (param_6 == 2) {
            iVar7 = local_20;
            iVar9 = local_58 + param_3;
          }
          else {
            iVar7 = local_20;
            if (param_6 == 3) {
              iVar7 = local_58 + param_2;
            }
          }
        }
      }
      local_1c = iVar9;
      local_20 = iVar7;
      local_2c = 0;
      local_68 = 0;
      uVar10 = local_54;
      if (*(int *)this != 0) {
        local_70 = 0;
        iVar7 = local_20;
        iVar9 = local_1c;
        do {
          iVar5 = *(int *)((int)this + 0xc) + local_70;
          local_44 = 0;
          do {
            if (local_44 == 0) {
              uVar8 = 0;
            }
            else {
              uVar8 = *(int *)(*(int *)((int)this + 0xd8) + -4 +
                              (*(int *)(iVar5 + 0x14) + local_44) * 4) + 1;
            }
            if (local_44 == *(uint *)(iVar5 + 0x10)) {
              uVar4 = *(uint *)(iVar5 + 0xc);
            }
            else {
              uVar4 = *(int *)(*(int *)((int)this + 0xd8) + (*(int *)(iVar5 + 0x14) + local_44) * 4)
                      + 1;
            }
            local_30 = 0;
            local_34 = 0;
            for (; uVar8 < uVar4; uVar8 = uVar8 + 1) {
              iVar6 = (*(int *)(*(int *)((int)this + 0xa8) + (*(int *)(iVar5 + 8) + uVar8) * 4) +
                      *(int *)(iVar5 + 8)) * 0x20 + *(int *)((int)this + 0x24);
              if (*(int *)(iVar6 + 0x10) != 0) {
                if (local_40 == 2) {
                  if (*(char *)((int)this + 0x128) != '\0') {
                    h = *(HGDIOBJ *)(iVar6 + 0x1c);
                    uVar2 = FUN_4540ba4b(this,(int)h);
                    if ((char)uVar2 != '\0') {
                      SelectObject(param_1,h);
                    }
                  }
                  iVar9 = local_1c;
                  if ((bVar1) && (local_2c < *(uint *)(iVar5 + 0x10))) {
                    local_5c = *(int *)((int)this + 0x54) + *(int *)(iVar6 + 0x14) * 4;
                  }
                  else {
                    local_5c = 0;
                  }
                  iVar3 = *(int *)(iVar6 + 0x14);
                  iVar3 = ScriptTextOut(param_1,param_10,iVar7,local_1c,param_4,param_8,iVar6 + 4,0,
                                        0,*(int *)((int)this + 0x30) + iVar3 * 2,
                                        *(undefined4 *)(iVar6 + 0x10),
                                        *(int *)((int)this + 0x48) + iVar3 * 4,local_5c,
                                        *(int *)((int)this + 0x60) + iVar3 * 8);
                  if (iVar3 < 0) goto LAB_4540c751;
                }
                else if (local_40 == 1) {
                  FUN_45429920((undefined8 *)(*(int *)((int)this + 0xc0) + local_34 * 4),
                               (undefined8 *)
                               (*(int *)((int)this + 0x48) + *(int *)(iVar6 + 0x14) * 4),
                               *(int *)(iVar6 + 0x10) << 2);
                  FUN_45429920((undefined8 *)(*(int *)((int)this + 0xb4) + local_34 * 2),
                               (undefined8 *)
                               (*(int *)((int)this + 0x3c) + *(int *)(iVar6 + 0x14) * 2),
                               *(int *)(iVar6 + 0x10) * 2);
                  local_34 = local_34 + *(int *)(iVar6 + 0x10);
                }
                local_30 = local_30 + *(int *)(iVar6 + 0x10);
                if (local_60 == 0) {
                  iVar6 = *(int *)(iVar6 + 0x18);
LAB_4540c4d1:
                  iVar7 = iVar7 + iVar6;
                  local_20 = iVar7;
                }
                else {
                  if (local_60 == 1) {
                    iVar6 = -*(int *)(iVar6 + 0x18);
                  }
                  else {
                    if (local_60 == 2) {
                      iVar6 = -*(int *)(iVar6 + 0x18);
                      goto LAB_4540c4d1;
                    }
                    if (local_60 != 3) goto LAB_4540c4d4;
                    iVar6 = *(int *)(iVar6 + 0x18);
                  }
                  iVar9 = iVar9 + iVar6;
                  local_1c = iVar9;
                }
              }
LAB_4540c4d4:
            }
            if (local_40 == 0) {
              *(int *)(*(int *)((int)this + 0xe4) + local_2c * 4) = iVar7;
              local_20 = 0;
            }
            else {
              FUN_4540c76f(this,local_2c + 1,&local_20,&local_1c,param_2,param_3,local_50,param_5,
                           local_60);
            }
            if (local_60 == 0) {
              if (param_7 == '\0') {
                iVar7 = 0;
              }
              else {
                iVar7 = param_9[4];
              }
              iVar7 = *param_9 + iVar7;
LAB_4540c5e1:
              local_1c = local_1c + iVar7;
            }
            else if (local_60 == 1) {
              if (param_7 == '\0') {
                iVar7 = 0;
              }
              else {
                iVar7 = param_9[4];
              }
              iVar7 = *param_9 + iVar7;
LAB_4540c559:
              local_20 = local_20 + iVar7;
            }
            else {
              if (local_60 == 2) {
                if (param_7 == '\0') {
                  iVar7 = 0;
                }
                else {
                  iVar7 = param_9[4];
                }
                iVar7 = -(*param_9 + iVar7);
                goto LAB_4540c5e1;
              }
              if (local_60 == 3) {
                if (param_7 == '\0') {
                  iVar7 = 0;
                }
                else {
                  iVar7 = param_9[4];
                }
                iVar7 = -(*param_9 + iVar7);
                goto LAB_4540c559;
              }
            }
            iVar9 = local_1c;
            iVar7 = local_20;
            if ((int)local_4c < (int)local_30) {
              local_4c = local_30;
            }
            if ((local_40 == 1) && (local_2c < *(uint *)(iVar5 + 0x10))) {
              iVar6 = ScriptJustify(*(undefined4 *)((int)this + 0xb4),
                                    *(undefined4 *)((int)this + 0xc0),local_30,
                                    local_50 - *(int *)(*(int *)((int)this + 0xe4) + local_2c * 4),
                                    local_54,*(undefined4 *)((int)this + 0xcc));
              if (iVar6 < 0) goto LAB_4540c751;
              local_38 = 0;
              if (local_44 == 0) {
                uVar8 = 0;
              }
              else {
                uVar8 = *(int *)(*(int *)((int)this + 0xd8) + -4 +
                                (*(int *)(iVar5 + 0x14) + local_44) * 4) + 1;
              }
              if (local_44 == *(uint *)(iVar5 + 0x10)) {
                uVar4 = *(uint *)(iVar5 + 0xc);
              }
              else {
                uVar4 = *(int *)(*(int *)((int)this + 0xd8) +
                                (*(int *)(iVar5 + 0x14) + local_44) * 4) + 1;
              }
              for (; uVar8 < uVar4; uVar8 = uVar8 + 1) {
                iVar7 = (*(int *)(*(int *)((int)this + 0xa8) + (uVar8 + *(int *)(iVar5 + 8)) * 4) +
                        *(int *)(iVar5 + 8)) * 0x20 + *(int *)((int)this + 0x24);
                if (*(int *)(iVar7 + 0x10) != 0) {
                  FUN_45429920((undefined8 *)
                               (*(int *)((int)this + 0x54) + *(int *)(iVar7 + 0x14) * 4),
                               (undefined8 *)(*(int *)((int)this + 0xcc) + local_38 * 4),
                               *(int *)(iVar7 + 0x10) << 2);
                  iVar9 = *(int *)(iVar7 + 0x10);
                  local_38 = local_38 + iVar9;
                  *(undefined4 *)(iVar7 + 0x18) = 0;
                  if (iVar9 != 0) {
                    iVar3 = 0;
                    iVar6 = *(int *)(iVar7 + 0x14) << 2;
                    do {
                      iVar3 = iVar3 + *(int *)(iVar6 + *(int *)((int)this + 0x54));
                      iVar6 = iVar6 + 4;
                      *(int *)(iVar7 + 0x18) = iVar3;
                      iVar9 = iVar9 + -1;
                    } while (iVar9 != 0);
                  }
                }
                iVar7 = local_20;
                iVar9 = local_1c;
              }
              bVar1 = true;
            }
            local_2c = local_2c + 1;
            local_44 = local_44 + 1;
          } while (local_44 <= *(uint *)(iVar5 + 0x10));
          local_68 = local_68 + 1;
          local_70 = local_70 + 0x18;
        } while (local_68 < *(uint *)this);
      }
    }
LAB_4540c737:
    local_40 = local_40 + 1;
  } while (local_40 < 3);
LAB_4540c751:
  FUN_4542a8d1(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



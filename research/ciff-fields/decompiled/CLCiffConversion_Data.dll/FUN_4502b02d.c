// Source: CLCiffConversion_Data.dll @ 4502b02d; FUN_4502b02d

void __cdecl FUN_4502b02d(FILE *param_1,byte *param_2,int *param_3,WCHAR *param_4)

{
  byte bVar1;
  WCHAR WVar2;
  short *psVar3;
  ushort uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined2 extraout_var_00;
  undefined3 extraout_var;
  int iVar7;
  code *pcVar8;
  undefined1 *puVar9;
  byte *pbVar10;
  int *piVar11;
  int iVar12;
  int extraout_ECX;
  undefined *puVar13;
  WCHAR *pWVar14;
  WCHAR *pWVar15;
  WCHAR *pWVar16;
  WCHAR *pWVar17;
  bool bVar18;
  longlong lVar19;
  undefined4 *puVar20;
  undefined4 uVar21;
  undefined4 local_284;
  undefined4 local_280;
  WCHAR *local_278;
  int local_274 [2];
  int local_26c;
  char local_268;
  int local_264;
  int *local_260;
  WCHAR *local_25c;
  int local_258;
  undefined4 local_254;
  byte local_250;
  undefined3 uStack_24f;
  int local_24c;
  int local_248;
  int local_244;
  undefined1 *local_240;
  uint local_23c;
  int local_238;
  FILE *local_234;
  byte local_230;
  char local_22f;
  undefined1 *local_22c;
  int local_228;
  int local_224;
  WCHAR *local_220;
  WCHAR *local_21c;
  byte local_215;
  byte *local_214;
  uint local_210 [127];
  undefined1 local_11 [9];
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_234 = param_1;
  local_214 = param_2;
  pWVar14 = (WCHAR *)0x0;
  local_220 = param_4;
  local_258 = 0;
  pWVar16 = (WCHAR *)0x0;
  local_21c = (WCHAR *)0x0;
  local_244 = 0;
  local_228 = 0;
  local_238 = 0;
  local_254 = 0;
  local_24c = 0;
  local_248 = 0;
  FUN_45021444(local_274,param_3);
  local_260 = __errno();
  if (local_234 != (FILE *)0x0) {
    if ((local_234->_flag & 0x40) == 0) {
      uVar5 = __fileno(local_234);
      if ((uVar5 == 0xffffffff) || (uVar5 == 0xfffffffe)) {
        puVar13 = &DAT_45052420;
      }
      else {
        puVar13 = (undefined *)((uVar5 & 0x1f) * 0x40 + (&DAT_45055ae0)[(int)uVar5 >> 5]);
      }
      if ((puVar13[0x24] & 0x7f) == 0) {
        if ((uVar5 == 0xffffffff) || (uVar5 == 0xfffffffe)) {
          puVar13 = &DAT_45052420;
        }
        else {
          puVar13 = (undefined *)((uVar5 & 0x1f) * 0x40 + (&DAT_45055ae0)[(int)uVar5 >> 5]);
        }
        if ((puVar13[0x24] & 0x80) == 0) goto LAB_4502b124;
      }
    }
    else {
LAB_4502b124:
      if (local_214 != (byte *)0x0) {
        local_215 = *local_214;
        local_22c = (undefined1 *)0x0;
        iVar12 = 0;
        local_224 = 0;
        local_23c = 0;
        local_25c = (WCHAR *)0x0;
        _local_250 = CONCAT31(uStack_24f,local_215);
        pbVar6 = local_214;
        if (local_215 == 0) goto LAB_4502bb84;
        do {
          local_214 = pbVar6 + 1;
          if (iVar12 < 0) break;
          if ((byte)(local_215 - 0x20) < 0x59) {
            uVar5 = (byte)(&DAT_45042b38)[(char)local_215] & 0xf;
          }
          else {
            uVar5 = 0;
          }
          local_23c = (uint)((byte)(&DAT_45042b58)[local_23c + uVar5 * 9] >> 4);
          if (local_23c == 8) goto LAB_4502bb6d;
          pbVar10 = local_214;
          switch(local_23c) {
          case 0:
LAB_4502b3cc:
            local_248 = 0;
            uVar4 = FUN_450214cc((uint)local_215,local_274);
            if (CONCAT22(extraout_var_00,uVar4) != 0) {
              write_char((byte)_local_250,local_234,&local_224);
              bVar1 = *local_214;
              local_214 = local_214 + 1;
              _local_250 = CONCAT31(uStack_24f,bVar1);
              if (bVar1 == 0) goto LAB_4502bb6d;
            }
            write_char((byte)_local_250,local_234,&local_224);
            pbVar10 = local_214;
            iVar12 = local_224;
            break;
          case 1:
            local_228 = -1;
            pWVar14 = (WCHAR *)0x0;
            local_254 = 0;
            local_24c = 0;
            local_244 = 0;
            local_238 = 0;
            local_21c = (WCHAR *)0x0;
            local_248 = 0;
            break;
          case 2:
            if (local_215 == 0x20) {
              pWVar14 = (WCHAR *)((uint)pWVar14 | 2);
              local_21c = pWVar14;
            }
            else if (local_215 == 0x23) {
              pWVar14 = (WCHAR *)((uint)pWVar14 | 0x80);
              local_21c = pWVar14;
            }
            else if (local_215 == 0x2b) {
              pWVar14 = (WCHAR *)((uint)pWVar14 | 1);
              local_21c = pWVar14;
            }
            else if (local_215 == 0x2d) {
              pWVar14 = (WCHAR *)((uint)pWVar14 | 4);
              local_21c = pWVar14;
            }
            else if (local_215 == 0x30) {
              pWVar14 = (WCHAR *)((uint)pWVar14 | 8);
              local_21c = pWVar14;
            }
            break;
          case 3:
            if (local_215 == 0x2a) {
              local_244 = *(int *)local_220;
              local_220 = local_220 + 2;
              if (local_244 < 0) {
                pWVar14 = (WCHAR *)((uint)pWVar14 | 4);
                local_244 = -local_244;
                local_21c = pWVar14;
              }
            }
            else {
              local_244 = (int)(char)local_215 + local_244 * 10 + -0x30;
              iVar12 = local_224;
            }
            break;
          case 4:
            local_228 = 0;
            break;
          case 5:
            if (local_215 == 0x2a) {
              local_228 = *(int *)local_220;
              local_220 = local_220 + 2;
              if (local_228 < 0) {
                local_228 = -1;
              }
            }
            else {
              local_228 = (int)(char)local_215 + local_228 * 10 + -0x30;
              iVar12 = local_224;
            }
            break;
          case 6:
            if (local_215 == 0x49) {
              bVar1 = *local_214;
              if ((bVar1 == 0x36) && (pbVar6[2] == 0x34)) {
                pWVar14 = (WCHAR *)((uint)pWVar14 | 0x8000);
                pbVar10 = pbVar6 + 3;
                local_21c = pWVar14;
              }
              else if ((bVar1 == 0x33) && (pbVar6[2] == 0x32)) {
                pWVar14 = (WCHAR *)((uint)pWVar14 & 0xffff7fff);
                pbVar10 = pbVar6 + 3;
                local_21c = pWVar14;
              }
              else if (((((bVar1 != 100) && (bVar1 != 0x69)) && (bVar1 != 0x6f)) &&
                       ((bVar1 != 0x75 && (bVar1 != 0x78)))) && (bVar1 != 0x58)) {
                local_23c = 0;
                goto LAB_4502b3cc;
              }
            }
            else if (local_215 == 0x68) {
              pWVar14 = (WCHAR *)((uint)pWVar14 | 0x20);
              local_21c = pWVar14;
            }
            else if (local_215 == 0x6c) {
              if (*local_214 == 0x6c) {
                pWVar14 = (WCHAR *)((uint)pWVar14 | 0x1000);
                pbVar10 = pbVar6 + 2;
                local_21c = pWVar14;
              }
              else {
                pWVar14 = (WCHAR *)((uint)pWVar14 | 0x10);
                local_21c = pWVar14;
              }
            }
            else if (local_215 == 0x77) {
              pWVar14 = (WCHAR *)((uint)pWVar14 | 0x800);
              local_21c = pWVar14;
            }
            break;
          case 7:
            if ((char)local_215 < 'e') {
              if (local_215 == 100) {
LAB_4502b6a3:
                pWVar14 = (WCHAR *)((uint)pWVar14 | 0x40);
                local_21c = pWVar14;
LAB_4502b6ac:
                local_22c = (undefined1 *)0xa;
LAB_4502b6b6:
                if ((((uint)pWVar14 & 0x8000) == 0) && (((uint)pWVar14 & 0x1000) == 0)) {
                  if (((uint)pWVar14 & 0x20) == 0) {
                    if (((uint)pWVar14 & 0x40) == 0) {
                      uVar5 = *(uint *)local_220;
                      iVar12 = 0;
                      local_220 = local_220 + 2;
                      goto LAB_4502b88d;
                    }
                    uVar5 = *(uint *)local_220;
                  }
                  else if (((uint)pWVar14 & 0x40) == 0) {
                    uVar5 = (uint)(ushort)*local_220;
                  }
                  else {
                    uVar5 = (uint)*local_220;
                  }
                  iVar12 = (int)uVar5 >> 0x1f;
                  local_220 = local_220 + 2;
                }
                else {
                  uVar5 = *(uint *)local_220;
                  iVar12 = *(int *)(local_220 + 2);
                  local_220 = local_220 + 4;
                }
LAB_4502b88d:
                if (((((uint)pWVar14 & 0x40) != 0) && (iVar12 < 1)) && (iVar12 < 0)) {
                  bVar18 = uVar5 != 0;
                  uVar5 = -uVar5;
                  iVar12 = -(iVar12 + (uint)bVar18);
                  pWVar14 = (WCHAR *)((uint)pWVar14 | 0x100);
                  local_21c = pWVar14;
                }
                if (((uint)pWVar14 & 0x9000) == 0) {
                  iVar12 = 0;
                }
                lVar19 = CONCAT44(iVar12,uVar5);
                if (local_228 < 0) {
                  local_228 = 1;
                }
                else {
                  pWVar14 = (WCHAR *)((uint)pWVar14 & 0xfffffff7);
                  local_21c = pWVar14;
                  if (0x200 < local_228) {
                    local_228 = 0x200;
                  }
                }
                if (uVar5 == 0 && iVar12 == 0) {
                  local_238 = 0;
                }
                pWVar15 = (WCHAR *)local_11;
                while( true ) {
                  iVar12 = local_228 + -1;
                  if ((local_228 < 1) && (lVar19 == 0)) break;
                  local_228 = iVar12;
                  lVar19 = __aulldvrm((uint)lVar19,(uint)((ulonglong)lVar19 >> 0x20),(uint)local_22c
                                      ,(int)local_22c >> 0x1f);
                  local_240 = (undefined1 *)lVar19;
                  iVar12 = extraout_ECX + 0x30;
                  if (0x39 < iVar12) {
                    iVar12 = iVar12 + local_258;
                  }
                  *(char *)pWVar15 = (char)iVar12;
                  pWVar15 = (WCHAR *)((int)pWVar15 + -1);
                  local_278 = pWVar14;
                }
                local_22c = local_11 + -(int)pWVar15;
                pWVar16 = (WCHAR *)((int)pWVar15 + 1);
                pWVar14 = local_21c;
                local_228 = iVar12;
                if ((((uint)local_21c & 0x200) != 0) &&
                   ((local_22c == (undefined1 *)0x0 || (*(char *)pWVar16 != '0')))) {
                  local_22c = local_11 + -(int)pWVar15 + 1;
                  *(undefined1 *)pWVar15 = 0x30;
                  pWVar16 = pWVar15;
                }
              }
              else if ((char)local_215 < 'T') {
                if (local_215 == 0x53) {
                  if (((uint)pWVar14 & 0x830) == 0) {
                    pWVar14 = (WCHAR *)((uint)pWVar14 | 0x800);
                    local_21c = pWVar14;
                  }
                  goto LAB_4502b4ed;
                }
                if (local_215 == 0x41) {
LAB_4502b472:
                  local_215 = local_215 + 0x20;
                  local_254 = 1;
LAB_4502b485:
                  pWVar15 = (WCHAR *)((uint)pWVar14 | 0x40);
                  local_240 = (undefined1 *)0x200;
                  pWVar17 = (WCHAR *)local_210;
                  puVar9 = local_240;
                  local_21c = pWVar15;
                  if (local_228 < 0) {
                    local_228 = 6;
                  }
                  else if (local_228 == 0) {
                    if (local_215 == 0x67) {
                      local_228 = 1;
                    }
                  }
                  else {
                    if (0x200 < local_228) {
                      local_228 = 0x200;
                    }
                    if (0xa3 < local_228) {
                      puVar9 = (undefined1 *)(local_228 + 0x15d);
                      local_25c = FUN_4502df29((size_t)puVar9);
                      pWVar17 = local_25c;
                      if (local_25c == (WCHAR *)0x0) {
                        local_228 = 0xa3;
                        pWVar17 = (WCHAR *)local_210;
                        puVar9 = local_240;
                      }
                    }
                  }
                  local_240 = puVar9;
                  local_284 = *(undefined4 *)local_220;
                  local_280 = *(undefined4 *)(local_220 + 2);
                  piVar11 = local_274;
                  iVar7 = (int)(char)local_215;
                  puVar20 = &local_284;
                  pWVar16 = pWVar17;
                  puVar9 = local_240;
                  iVar12 = local_228;
                  uVar21 = local_254;
                  local_220 = local_220 + 4;
                  pcVar8 = DecodePointer(PTR_LAB_450521f8);
                  (*pcVar8)(puVar20,pWVar16,puVar9,iVar7,iVar12,uVar21,piVar11);
                  if ((((uint)pWVar14 & 0x80) != 0) && (local_228 == 0)) {
                    piVar11 = local_274;
                    pWVar16 = pWVar17;
                    pcVar8 = DecodePointer(PTR_LAB_45052204);
                    (*pcVar8)(pWVar16,piVar11);
                  }
                  if ((local_215 == 0x67) && (((uint)pWVar14 & 0x80) == 0)) {
                    piVar11 = local_274;
                    pWVar16 = pWVar17;
                    pcVar8 = DecodePointer(PTR_LAB_45052200);
                    (*pcVar8)(pWVar16,piVar11);
                  }
                  if ((char)*pWVar17 == '-') {
                    local_21c = (WCHAR *)((uint)pWVar14 | 0x140);
                    pWVar15 = local_21c;
                    pWVar17 = (WCHAR *)((int)pWVar17 + 1);
                  }
LAB_4502b60d:
                  pWVar16 = pWVar17;
                  pWVar14 = pWVar15;
                  local_22c = (undefined1 *)_strlen((char *)pWVar16);
                }
                else if (local_215 == 0x43) {
                  if (((uint)pWVar14 & 0x830) == 0) {
                    pWVar14 = (WCHAR *)((uint)pWVar14 | 0x800);
                    local_21c = pWVar14;
                  }
LAB_4502b566:
                  if (((uint)pWVar14 & 0x810) == 0) {
                    local_210[0]._0_1_ = (char)*local_220;
                    local_22c = (undefined1 *)0x1;
                    local_220 = local_220 + 2;
                  }
                  else {
                    WVar2 = *local_220;
                    local_220 = local_220 + 2;
                    iVar12 = FUN_45033dc3((int *)&local_22c,local_210,0x200,WVar2);
                    if (iVar12 != 0) {
                      local_24c = 1;
                    }
                  }
                  pWVar16 = (WCHAR *)local_210;
                }
                else if ((local_215 == 0x45) || (local_215 == 0x47)) goto LAB_4502b472;
              }
              else {
                if (local_215 == 0x58) goto LAB_4502b801;
                if (local_215 == 0x5a) {
                  psVar3 = *(short **)local_220;
                  local_220 = local_220 + 2;
                  pWVar15 = pWVar14;
                  pWVar17 = (WCHAR *)PTR_DAT_450521d4;
                  if ((psVar3 == (short *)0x0) ||
                     (pWVar16 = *(WCHAR **)(psVar3 + 2), pWVar16 == (WCHAR *)0x0))
                  goto LAB_4502b60d;
                  local_22c = (undefined1 *)(int)*psVar3;
                  if (((uint)pWVar14 & 0x800) == 0) {
                    local_248 = 0;
                  }
                  else {
                    local_248 = 1;
                    local_22c = (undefined1 *)((int)local_22c / 2);
                  }
                }
                else {
                  if (local_215 == 0x61) goto LAB_4502b485;
                  if (local_215 == 99) goto LAB_4502b566;
                }
              }
LAB_4502b98a:
              if (local_24c == 0) {
                if (((uint)pWVar14 & 0x40) != 0) {
                  if (((uint)pWVar14 & 0x100) == 0) {
                    if (((uint)pWVar14 & 1) == 0) {
                      if (((uint)pWVar14 & 2) == 0) goto LAB_4502b9d1;
                      local_230 = 0x20;
                    }
                    else {
                      local_230 = 0x2b;
                    }
                  }
                  else {
                    local_230 = 0x2d;
                  }
                  local_238 = 1;
                }
LAB_4502b9d1:
                iVar12 = (local_244 - (int)local_22c) - local_238;
                if (((uint)pWVar14 & 0xc) == 0) {
                  write_multi_char(0x20,iVar12,local_234,&local_224);
                }
                FUN_4502bc3d(&local_230,local_238,local_234,&local_224,local_260);
                if ((((uint)pWVar14 & 8) != 0) && (((uint)pWVar14 & 4) == 0)) {
                  write_multi_char(0x30,iVar12,local_234,&local_224);
                }
                if ((local_248 == 0) || (puVar9 = local_22c, pWVar15 = pWVar16, (int)local_22c < 1))
                {
                  FUN_4502bc3d((byte *)pWVar16,(int)local_22c,local_234,&local_224,local_260);
                }
                else {
                  do {
                    local_240 = puVar9 + -1;
                    local_278 = pWVar15 + 1;
                    iVar7 = FUN_45033dc3(&local_264,(uint *)(local_11 + 1),6,*pWVar15);
                    if ((iVar7 != 0) || (local_264 == 0)) {
                      local_224 = -1;
                      break;
                    }
                    FUN_4502bc3d(local_11 + 1,local_264,local_234,&local_224,local_260);
                    puVar9 = local_240;
                    pWVar15 = local_278;
                  } while (local_240 != (undefined1 *)0x0);
                }
                if ((-1 < local_224) && (((uint)pWVar14 & 4) != 0)) {
                  write_multi_char(0x20,iVar12,local_234,&local_224);
                }
              }
            }
            else {
              if ('p' < (char)local_215) {
                if (local_215 == 0x73) {
LAB_4502b4ed:
                  iVar12 = 0x7fffffff;
                  if (local_228 != -1) {
                    iVar12 = local_228;
                  }
                  pWVar15 = *(WCHAR **)local_220;
                  local_220 = local_220 + 2;
                  pWVar16 = pWVar15;
                  if (((uint)pWVar14 & 0x810) == 0) {
                    if (pWVar15 == (WCHAR *)0x0) {
                      pWVar15 = (WCHAR *)PTR_DAT_450521d4;
                      pWVar16 = (WCHAR *)PTR_DAT_450521d4;
                    }
                    for (; (iVar12 != 0 && (iVar12 = iVar12 + -1, (char)*pWVar15 != '\0'));
                        pWVar15 = (WCHAR *)((int)pWVar15 + 1)) {
                    }
                    local_22c = (undefined1 *)((int)pWVar15 - (int)pWVar16);
                  }
                  else {
                    if (pWVar15 == (WCHAR *)0x0) {
                      pWVar16 = (WCHAR *)PTR_DAT_450521d8;
                    }
                    local_248 = 1;
                    for (pWVar15 = pWVar16;
                        (iVar12 != 0 && (iVar12 = iVar12 + -1, *pWVar15 != L'\0'));
                        pWVar15 = pWVar15 + 1) {
                    }
                    local_22c = (undefined1 *)((int)pWVar15 - (int)pWVar16 >> 1);
                  }
                  goto LAB_4502b98a;
                }
                if (local_215 == 0x75) goto LAB_4502b6ac;
                if (local_215 != 0x78) goto LAB_4502b98a;
                local_258 = 0x27;
LAB_4502b821:
                local_22c = (undefined1 *)0x10;
                if ((char)pWVar14 < '\0') {
                  local_22f = (char)local_258 + 'Q';
                  local_230 = 0x30;
                  local_238 = 2;
                }
                goto LAB_4502b6b6;
              }
              if (local_215 == 0x70) {
                local_228 = 8;
LAB_4502b801:
                local_258 = 7;
                goto LAB_4502b821;
              }
              if ((char)local_215 < 'e') goto LAB_4502b98a;
              if ((char)local_215 < 'h') goto LAB_4502b485;
              if (local_215 == 0x69) goto LAB_4502b6a3;
              if (local_215 != 0x6e) {
                if (local_215 != 0x6f) goto LAB_4502b98a;
                local_22c = (undefined1 *)0x8;
                if ((char)pWVar14 < '\0') {
                  pWVar14 = (WCHAR *)((uint)pWVar14 | 0x200);
                  local_21c = pWVar14;
                }
                goto LAB_4502b6b6;
              }
              piVar11 = *(int **)local_220;
              local_220 = local_220 + 2;
              bVar18 = FUN_4503358b();
              if (CONCAT31(extraout_var,bVar18) == 0) goto LAB_4502bb6d;
              if (((uint)pWVar14 & 0x20) == 0) {
                *piVar11 = local_224;
              }
              else {
                *(short *)piVar11 = (short)local_224;
              }
              local_24c = 1;
            }
            pbVar10 = local_214;
            iVar12 = local_224;
            if (local_25c != (WCHAR *)0x0) {
              FID_conflict__free(local_25c);
              local_25c = (WCHAR *)0x0;
              pbVar10 = local_214;
              iVar12 = local_224;
            }
          }
          local_215 = *pbVar10;
          _local_250 = CONCAT31(uStack_24f,local_215);
          pbVar6 = pbVar10;
        } while (local_215 != 0);
        if ((local_23c == 0) || (local_23c == 7)) goto LAB_4502bb84;
      }
    }
  }
LAB_4502bb6d:
  piVar11 = __errno();
  *piVar11 = 0x16;
  FUN_45027e29();
LAB_4502bb84:
  if (local_268 != '\0') {
    *(uint *)(local_26c + 0x70) = *(uint *)(local_26c + 0x70) & 0xfffffffd;
  }
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



// Source: CLCiffConversion_Data.dll @ 45028e83; FUN_45028e83

void __cdecl FUN_45028e83(FILE *param_1,ushort *param_2,int *param_3,WCHAR *param_4)

{
  WCHAR WVar1;
  short *psVar2;
  ushort *puVar3;
  ushort uVar4;
  int *piVar5;
  uint uVar6;
  undefined2 extraout_var_00;
  undefined3 extraout_var;
  int iVar7;
  code *pcVar8;
  byte *pbVar9;
  uint uVar10;
  int extraout_ECX;
  WCHAR *pWVar11;
  byte *pbVar12;
  byte *pbVar13;
  WCHAR *pWVar14;
  WCHAR *pWVar15;
  WCHAR *pWVar16;
  bool bVar17;
  longlong lVar18;
  uint *puVar19;
  undefined4 uVar20;
  uint local_48c;
  uint local_488;
  byte *local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined4 local_474;
  int local_470;
  undefined4 local_46c;
  uint local_468;
  int *local_464;
  WCHAR *local_460;
  undefined4 local_45c;
  int local_458;
  int local_454;
  int local_450 [2];
  int local_448;
  char local_444;
  byte local_440 [4];
  WCHAR local_43c;
  short local_43a;
  uint local_438;
  WCHAR *local_434;
  int local_430;
  FILE *local_42c;
  int local_428;
  int local_424;
  WCHAR *local_420;
  WCHAR *local_41c;
  byte *local_418;
  WCHAR *local_414;
  byte *local_410;
  ushort *local_40c;
  WCHAR local_408 [255];
  undefined2 local_209;
  uint local_8;
  
  local_8 = DAT_450518d0 ^ (uint)&stack0xfffffffc;
  local_42c = param_1;
  local_40c = param_2;
  pbVar12 = (byte *)0x0;
  local_414 = param_4;
  local_458 = 0;
  pWVar14 = (WCHAR *)0x0;
  local_418 = (byte *)0x0;
  local_434 = (WCHAR *)0x0;
  local_41c = (WCHAR *)0x0;
  local_428 = 0;
  local_45c = 0;
  local_454 = 0;
  local_430 = 0;
  FUN_45021444(local_450,param_3);
  local_464 = __errno();
  if ((local_42c == (FILE *)0x0) || (local_40c == (ushort *)0x0)) {
    piVar5 = __errno();
    *piVar5 = 0x16;
    FUN_45027e29();
LAB_45028f21:
    if (local_444 != '\0') {
      *(uint *)(local_448 + 0x70) = *(uint *)(local_448 + 0x70) & 0xfffffffd;
    }
  }
  else {
    local_420 = (WCHAR *)(uint)*local_40c;
    pbVar9 = (byte *)0x0;
    local_410 = (byte *)0x0;
    local_424 = 0;
    local_438 = 0;
    local_460 = (WCHAR *)0x0;
    if (*local_40c != 0) {
      local_474 = 0x58;
      local_478 = 100;
      local_47c = 0x69;
      local_46c = 0x6f;
      do {
        puVar3 = local_40c + 1;
        if (local_424 < 0) break;
        WVar1 = (WCHAR)local_420;
        if ((ushort)(WVar1 + L'￠') < 0x59) {
          uVar6 = (byte)local_420[0x2282159c] & 0xf;
        }
        else {
          uVar6 = 0;
        }
        local_438 = (uint)((byte)(&DAT_45042b58)[local_438 + uVar6 * 9] >> 4);
        if (local_438 == 8) goto LAB_45029a82;
        switch(local_438) {
        case 0:
switchD_45028ffa_caseD_0:
          local_430 = 1;
          local_40c = puVar3;
          write_char(WVar1,local_42c,&local_424);
          pbVar9 = local_410;
          puVar3 = local_40c;
          break;
        case 1:
          local_41c = (WCHAR *)0xffffffff;
          pbVar12 = (byte *)0x0;
          local_45c = 0;
          local_454 = 0;
          local_434 = (WCHAR *)0x0;
          local_428 = 0;
          local_418 = (byte *)0x0;
          local_430 = 0;
          break;
        case 2:
          if (local_420 == (WCHAR *)0x20) {
            pbVar12 = (byte *)((uint)pbVar12 | 2);
            local_418 = pbVar12;
          }
          else if (local_420 == (WCHAR *)0x23) {
            pbVar12 = (byte *)((uint)pbVar12 | 0x80);
            local_418 = pbVar12;
          }
          else if (local_420 == (WCHAR *)0x2b) {
            pbVar12 = (byte *)((uint)pbVar12 | 1);
            local_418 = pbVar12;
          }
          else if (local_420 == (WCHAR *)0x2d) {
            pbVar12 = (byte *)((uint)pbVar12 | 4);
            local_418 = pbVar12;
          }
          else if (local_420 == (WCHAR *)0x30) {
            pbVar12 = (byte *)((uint)pbVar12 | 8);
            local_418 = pbVar12;
          }
          break;
        case 3:
          if (WVar1 == L'*') {
            local_434 = *(WCHAR **)local_414;
            local_414 = local_414 + 2;
            if ((int)local_434 < 0) {
              pbVar12 = (byte *)((uint)pbVar12 | 4);
              local_434 = (WCHAR *)-(int)local_434;
              local_418 = pbVar12;
            }
          }
          else {
            local_434 = local_420 + (int)local_434 * 5 + -0x18;
            pbVar9 = local_410;
          }
          break;
        case 4:
          local_41c = (WCHAR *)0x0;
          break;
        case 5:
          if (WVar1 == L'*') {
            local_41c = *(WCHAR **)local_414;
            local_414 = local_414 + 2;
            if ((int)local_41c < 0) {
              local_41c = (WCHAR *)0xffffffff;
            }
          }
          else {
            local_41c = local_420 + (int)local_41c * 5 + -0x18;
            pbVar9 = local_410;
          }
          break;
        case 6:
          if (local_420 == (WCHAR *)0x49) {
            uVar4 = *puVar3;
            if ((uVar4 == 0x36) && (local_40c[2] == 0x34)) {
              pbVar12 = (byte *)((uint)pbVar12 | 0x8000);
              local_418 = pbVar12;
              puVar3 = local_40c + 3;
            }
            else if ((uVar4 == 0x33) && (local_40c[2] == 0x32)) {
              pbVar12 = (byte *)((uint)pbVar12 & 0xffff7fff);
              local_418 = pbVar12;
              puVar3 = local_40c + 3;
            }
            else if (((((uVar4 != (ushort)local_478) && (uVar4 != (ushort)local_47c)) &&
                      (uVar4 != (ushort)local_46c)) && ((uVar4 != 0x75 && (uVar4 != 0x78)))) &&
                    (uVar4 != (ushort)local_474)) {
              local_438 = 0;
              goto switchD_45028ffa_caseD_0;
            }
          }
          else if (local_420 == (WCHAR *)0x68) {
            pbVar12 = (byte *)((uint)pbVar12 | 0x20);
            local_418 = pbVar12;
          }
          else if (local_420 == (WCHAR *)0x6c) {
            if (*puVar3 == 0x6c) {
              pbVar12 = (byte *)((uint)pbVar12 | 0x1000);
              local_418 = pbVar12;
              puVar3 = local_40c + 2;
            }
            else {
              pbVar12 = (byte *)((uint)pbVar12 | 0x10);
              local_418 = pbVar12;
            }
          }
          else if (local_420 == (WCHAR *)0x77) {
            pbVar12 = (byte *)((uint)pbVar12 | 0x800);
            local_418 = pbVar12;
          }
          break;
        case 7:
          if (local_420 < (WCHAR *)0x65) {
            if (local_420 == (WCHAR *)0x64) {
LAB_45029523:
              pbVar12 = (byte *)((uint)pbVar12 | 0x40);
              local_418 = pbVar12;
LAB_4502952c:
              local_420 = (WCHAR *)0xa;
LAB_45029536:
              if ((((uint)pbVar12 & 0x8000) == 0) && (((uint)pbVar12 & 0x1000) == 0)) {
                if (((uint)pbVar12 & 0x20) == 0) {
                  if (((uint)pbVar12 & 0x40) == 0) {
                    uVar10 = *(uint *)local_414;
                    uVar6 = 0;
                    local_414 = local_414 + 2;
                    goto LAB_45029718;
                  }
                  uVar10 = *(uint *)local_414;
                }
                else if (((uint)pbVar12 & 0x40) == 0) {
                  uVar10 = (uint)(ushort)*local_414;
                }
                else {
                  uVar10 = (uint)*local_414;
                }
                uVar6 = (int)uVar10 >> 0x1f;
                local_414 = local_414 + 2;
              }
              else {
                uVar10 = *(uint *)local_414;
                uVar6 = *(uint *)(local_414 + 2);
                local_414 = local_414 + 4;
              }
LAB_45029718:
              if (((((uint)pbVar12 & 0x40) != 0) && ((int)uVar6 < 1)) && ((int)uVar6 < 0)) {
                bVar17 = uVar10 != 0;
                uVar10 = -uVar10;
                uVar6 = -(uVar6 + bVar17);
                pbVar12 = (byte *)((uint)pbVar12 | 0x100);
                local_418 = pbVar12;
              }
              if (((uint)pbVar12 & 0x9000) == 0) {
                uVar6 = 0;
              }
              lVar18 = CONCAT44(uVar6,uVar10);
              if ((int)local_41c < 0) {
                local_41c = (WCHAR *)0x1;
              }
              else {
                pbVar12 = (byte *)((uint)pbVar12 & 0xfffffff7);
                local_418 = pbVar12;
                if (0x200 < (int)local_41c) {
                  local_41c = (WCHAR *)0x200;
                }
              }
              if (uVar10 == 0 && uVar6 == 0) {
                local_428 = 0;
              }
              pWVar16 = &local_209;
              local_40c = puVar3;
              while( true ) {
                pWVar11 = (WCHAR *)((int)local_41c + -1);
                if (((int)local_41c < 1) && (lVar18 == 0)) break;
                local_41c = pWVar11;
                lVar18 = __aulldvrm((uint)lVar18,(uint)((ulonglong)lVar18 >> 0x20),(uint)local_420,
                                    (int)local_420 >> 0x1f);
                local_410 = (byte *)lVar18;
                iVar7 = extraout_ECX + 0x30;
                if (0x39 < iVar7) {
                  iVar7 = iVar7 + local_458;
                }
                *(char *)pWVar16 = (char)iVar7;
                pWVar16 = (WCHAR *)((int)pWVar16 + -1);
                local_480 = pbVar12;
              }
              pbVar9 = (byte *)((int)&local_209 + -(int)pWVar16);
              pWVar14 = (WCHAR *)((int)pWVar16 + 1);
              pbVar12 = local_418;
              local_41c = pWVar11;
              local_410 = pbVar9;
              if ((((uint)local_418 & 0x200) != 0) &&
                 ((pbVar9 == (byte *)0x0 || (*(char *)pWVar14 != '0')))) {
                pbVar9 = (byte *)((int)&local_209 + -(int)pWVar16 + 1);
                *(undefined1 *)pWVar16 = 0x30;
                pWVar14 = pWVar16;
                local_410 = pbVar9;
              }
            }
            else if (local_420 < (WCHAR *)0x54) {
              if (local_420 == (WCHAR *)0x53) {
                if (((uint)pbVar12 & 0x830) == 0) {
                  pbVar12 = (byte *)((uint)pbVar12 | 0x20);
                  local_418 = pbVar12;
                }
                goto LAB_4502930d;
              }
              if (local_420 != (WCHAR *)0x41) {
                if (local_420 == (WCHAR *)0x43) {
                  if (((uint)pbVar12 & 0x830) == 0) {
                    pbVar12 = (byte *)((uint)pbVar12 | 0x20);
                    local_418 = pbVar12;
                  }
LAB_450293c2:
                  WVar1 = *local_414;
                  local_468 = (uint)(ushort)WVar1;
                  local_414 = local_414 + 2;
                  local_430 = 1;
                  if (((uint)pbVar12 & 0x20) == 0) {
                    local_408[0] = WVar1;
                    local_40c = puVar3;
                  }
                  else {
                    local_440[0] = (byte)WVar1;
                    local_440[1] = 0;
                    local_40c = puVar3;
                    iVar7 = FUN_45033726(local_408,local_440,*(uint *)(local_450[0] + 0x74),
                                         local_450);
                    if (iVar7 < 0) {
                      local_454 = 1;
                    }
                  }
                  pbVar9 = (byte *)0x1;
                  pWVar14 = local_408;
                  local_410 = pbVar9;
                  goto LAB_4502982c;
                }
                if ((local_420 != (WCHAR *)0x45) && (local_40c = puVar3, local_420 != (WCHAR *)0x47)
                   ) goto LAB_4502982c;
              }
              local_420 = local_420 + 0x10;
              local_45c = 1;
LAB_450292a7:
              pbVar13 = (byte *)((uint)pbVar12 | 0x40);
              local_410 = (byte *)0x200;
              pWVar16 = local_408;
              local_418 = pbVar13;
              pbVar9 = local_410;
              if ((int)local_41c < 0) {
                local_41c = (WCHAR *)0x6;
                local_40c = puVar3;
              }
              else if (local_41c == (WCHAR *)0x0) {
                local_40c = puVar3;
                if ((short)local_420 == 0x67) {
                  local_41c = (WCHAR *)0x1;
                }
              }
              else {
                if (0x200 < (int)local_41c) {
                  local_41c = (WCHAR *)0x200;
                }
                local_40c = puVar3;
                if (0xa3 < (int)local_41c) {
                  pbVar9 = (byte *)((int)local_41c + 0x15d);
                  local_460 = FUN_4502df29((size_t)pbVar9);
                  pWVar16 = local_460;
                  if (local_460 == (WCHAR *)0x0) {
                    local_41c = (WCHAR *)0xa3;
                    pWVar16 = local_408;
                    pbVar9 = local_410;
                  }
                }
              }
              local_410 = pbVar9;
              local_48c = *(uint *)local_414;
              local_488 = *(uint *)(local_414 + 2);
              piVar5 = local_450;
              iVar7 = (int)(char)local_420;
              puVar19 = &local_48c;
              pWVar14 = pWVar16;
              pbVar9 = local_410;
              pWVar11 = local_41c;
              uVar20 = local_45c;
              local_414 = local_414 + 4;
              pcVar8 = DecodePointer(PTR_LAB_450521f8);
              (*pcVar8)(puVar19,pWVar14,pbVar9,iVar7,pWVar11,uVar20,piVar5);
              if ((((uint)pbVar12 & 0x80) != 0) && (local_41c == (WCHAR *)0x0)) {
                piVar5 = local_450;
                pWVar14 = pWVar16;
                pcVar8 = DecodePointer(PTR_LAB_45052204);
                (*pcVar8)(pWVar14,piVar5);
              }
              if (((short)local_420 == 0x67) && (((uint)pbVar12 & 0x80) == 0)) {
                piVar5 = local_450;
                pWVar14 = pWVar16;
                pcVar8 = DecodePointer(PTR_LAB_45052200);
                (*pcVar8)(pWVar14,piVar5);
              }
              pWVar11 = local_414;
              if ((char)*pWVar16 == '-') {
                local_418 = (byte *)((uint)pbVar12 | 0x140);
                pbVar13 = local_418;
                pWVar16 = (WCHAR *)((int)pWVar16 + 1);
              }
LAB_45029487:
              local_414 = pWVar11;
              pbVar9 = (byte *)_strlen((char *)pWVar16);
              pbVar12 = pbVar13;
              pWVar14 = pWVar16;
              local_410 = pbVar9;
            }
            else {
              if (local_420 == (WCHAR *)0x58) goto LAB_45029685;
              if (local_420 == (WCHAR *)0x5a) {
                psVar2 = *(short **)local_414;
                pWVar11 = local_414 + 2;
                pbVar13 = pbVar12;
                pWVar16 = (WCHAR *)PTR_DAT_450521d4;
                local_40c = puVar3;
                if ((psVar2 == (short *)0x0) ||
                   (pWVar14 = *(WCHAR **)(psVar2 + 2), pWVar14 == (WCHAR *)0x0)) goto LAB_45029487;
                if (((uint)pbVar12 & 0x800) != 0) {
                  iVar7 = (int)*psVar2 - ((int)*psVar2 >> 0x1f);
                  goto LAB_45029824;
                }
                local_430 = 0;
                pbVar9 = (byte *)(int)*psVar2;
                local_414 = pWVar11;
                local_410 = pbVar9;
              }
              else {
                if (local_420 == (WCHAR *)0x61) goto LAB_450292a7;
                local_40c = puVar3;
                if (local_420 == (WCHAR *)0x63) goto LAB_450293c2;
              }
            }
LAB_4502982c:
            if (local_454 == 0) {
              if (((uint)pbVar12 & 0x40) != 0) {
                if (((uint)pbVar12 & 0x100) == 0) {
                  if (((uint)pbVar12 & 1) == 0) {
                    if (((uint)pbVar12 & 2) != 0) {
                      local_43c = L' ';
                      local_428 = 1;
                    }
                    goto LAB_45029861;
                  }
                  local_43c = L'+';
                }
                else {
                  local_43c = L'-';
                }
                local_428 = 1;
              }
LAB_45029861:
              pbVar9 = (byte *)((int)local_434 + (-local_428 - (int)pbVar9));
              if (((uint)pbVar12 & 0xc) == 0) {
                write_multi_char(L' ',(int)pbVar9,local_42c,&local_424);
              }
              FUN_45028e0a(&local_43c,local_428,local_42c,&local_424,local_464);
              if ((((uint)pbVar12 & 8) != 0) && (((uint)pbVar12 & 4) == 0)) {
                write_multi_char(L'0',(int)pbVar9,local_42c,&local_424);
              }
              if ((local_430 == 0) && (pbVar13 = local_410, pWVar16 = pWVar14, 0 < (int)local_410))
              {
                do {
                  local_480 = pbVar13 + -1;
                  local_420 = pWVar16;
                  local_470 = FUN_45033726((LPWSTR)&local_468,(byte *)pWVar16,
                                           *(uint *)(local_450[0] + 0x74),local_450);
                  if (local_470 < 1) {
                    local_424 = -1;
                    break;
                  }
                  write_char((WCHAR)local_468,local_42c,&local_424);
                  local_420 = (WCHAR *)((int)local_420 + local_470);
                  pbVar13 = local_480;
                  pWVar16 = local_420;
                } while (0 < (int)local_480);
              }
              else {
                FUN_45028e0a(pWVar14,(int)local_410,local_42c,&local_424,local_464);
              }
              if ((-1 < local_424) && (((uint)pbVar12 & 4) != 0)) {
                write_multi_char(L' ',(int)pbVar9,local_42c,&local_424);
              }
            }
          }
          else {
            if ((WCHAR *)0x70 < local_420) {
              if (local_420 == (WCHAR *)0x73) {
LAB_4502930d:
                pWVar16 = (WCHAR *)0x7fffffff;
                if (local_41c != (WCHAR *)0xffffffff) {
                  pWVar16 = local_41c;
                }
                pWVar15 = local_414 + 2;
                pWVar11 = *(WCHAR **)local_414;
                if (((uint)pbVar12 & 0x20) == 0) {
                  pWVar14 = pWVar11;
                  if (pWVar11 == (WCHAR *)0x0) {
                    pWVar11 = (WCHAR *)PTR_DAT_450521d8;
                    pWVar14 = (WCHAR *)PTR_DAT_450521d8;
                  }
                  for (; (pWVar16 != (WCHAR *)0x0 &&
                         (pWVar16 = (WCHAR *)((int)pWVar16 + -1), *pWVar11 != L'\0'));
                      pWVar11 = pWVar11 + 1) {
                  }
                  iVar7 = (int)pWVar11 - (int)pWVar14;
LAB_45029824:
                  local_414 = local_414 + 2;
                  local_430 = 1;
                  pbVar9 = (byte *)(iVar7 >> 1);
                  local_410 = pbVar9;
                  local_40c = puVar3;
                }
                else {
                  if (pWVar11 == (WCHAR *)0x0) {
                    pWVar11 = (WCHAR *)PTR_DAT_450521d4;
                  }
                  local_410 = (byte *)0x0;
                  local_420 = pWVar11;
                  pbVar9 = (byte *)0x0;
                  pWVar14 = pWVar11;
                  local_414 = pWVar15;
                  local_40c = puVar3;
                  if (0 < (int)pWVar16) {
                    do {
                      pbVar9 = local_410;
                      if ((byte)*local_420 == 0) break;
                      uVar4 = FUN_450214cc((uint)(byte)*local_420,local_450);
                      if (CONCAT22(extraout_var_00,uVar4) != 0) {
                        local_420 = (WCHAR *)((int)local_420 + 1);
                      }
                      local_420 = (WCHAR *)((int)local_420 + 1);
                      pbVar9 = local_410 + 1;
                      local_410 = pbVar9;
                    } while ((int)pbVar9 < (int)pWVar16);
                  }
                }
                goto LAB_4502982c;
              }
              if (local_420 == (WCHAR *)0x75) goto LAB_4502952c;
              local_40c = puVar3;
              if (local_420 != (WCHAR *)0x78) goto LAB_4502982c;
              local_458 = 0x27;
LAB_450296a5:
              local_420 = (WCHAR *)0x10;
              if ((char)pbVar12 < '\0') {
                local_43a = (short)local_458 + 0x51;
                local_43c = L'0';
                local_428 = 2;
              }
              goto LAB_45029536;
            }
            if (local_420 == (WCHAR *)0x70) {
              local_41c = (WCHAR *)0x8;
LAB_45029685:
              local_458 = 7;
              goto LAB_450296a5;
            }
            local_40c = puVar3;
            if (local_420 < (WCHAR *)0x65) goto LAB_4502982c;
            if (local_420 < (WCHAR *)0x68) goto LAB_450292a7;
            if (local_420 == (WCHAR *)0x69) goto LAB_45029523;
            if (local_420 != (WCHAR *)0x6e) {
              if (local_420 != (WCHAR *)0x6f) goto LAB_4502982c;
              local_420 = (WCHAR *)0x8;
              if ((char)pbVar12 < '\0') {
                pbVar12 = (byte *)((uint)pbVar12 | 0x200);
                local_418 = pbVar12;
              }
              goto LAB_45029536;
            }
            piVar5 = *(int **)local_414;
            local_414 = local_414 + 2;
            bVar17 = FUN_4503358b();
            if (CONCAT31(extraout_var,bVar17) == 0) {
              piVar5 = __errno();
              *piVar5 = 0x16;
              FUN_45027e29();
              if (local_444 != '\0') {
                *(uint *)(local_448 + 0x70) = *(uint *)(local_448 + 0x70) & 0xfffffffd;
              }
              goto LAB_45029a45;
            }
            if (((uint)pbVar12 & 0x20) == 0) {
              *piVar5 = local_424;
            }
            else {
              *(short *)piVar5 = (short)local_424;
            }
            local_454 = 1;
          }
          pbVar9 = local_410;
          puVar3 = local_40c;
          if (local_460 != (WCHAR *)0x0) {
            FID_conflict__free(local_460);
            local_460 = (WCHAR *)0x0;
            pbVar9 = local_410;
            puVar3 = local_40c;
          }
        }
        local_40c = puVar3;
        local_420 = (WCHAR *)(uint)*local_40c;
        puVar3 = local_40c;
      } while (*local_40c != 0);
      local_40c = puVar3;
      if ((local_438 != 0) && (puVar3 = local_40c, local_438 != 7)) {
LAB_45029a82:
        local_40c = puVar3;
        piVar5 = __errno();
        *piVar5 = 0x16;
        FUN_45027e29();
        goto LAB_45028f21;
      }
    }
    if (local_444 != '\0') {
      *(uint *)(local_448 + 0x70) = *(uint *)(local_448 + 0x70) & 0xfffffffd;
    }
  }
LAB_45029a45:
  FUN_45022e32(local_8 ^ (uint)&stack0xfffffffc);
  return;
}



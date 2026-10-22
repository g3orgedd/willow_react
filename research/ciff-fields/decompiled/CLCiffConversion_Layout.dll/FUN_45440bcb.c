// Source: CLCiffConversion_Layout.dll @ 45440bcb; FUN_45440bcb

uint __cdecl FUN_45440bcb(uint param_1,LPWSTR param_2,uint param_3)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  WCHAR WVar4;
  ulong *puVar5;
  int *piVar6;
  undefined3 extraout_var;
  BOOL BVar7;
  ulong uVar8;
  DWORD DVar9;
  int iVar10;
  int iVar11;
  size_t sVar12;
  uint uVar13;
  LPWSTR pWVar14;
  LPWSTR pWVar15;
  int cbMultiByte;
  uint uVar16;
  LPWSTR pWVar17;
  WCHAR *pWVar18;
  undefined8 uVar19;
  WCHAR *local_24;
  LPWSTR local_20;
  uint local_1c;
  uint local_18;
  LPWSTR local_14;
  int local_10;
  undefined2 local_c;
  char local_5;
  
  uVar16 = 0;
  local_1c = 0xfffffffe;
  local_24 = (WCHAR *)0x0;
  if (param_1 == 0xfffffffe) {
    puVar5 = ___doserrno();
    *puVar5 = 0;
    piVar6 = __errno();
    *piVar6 = 9;
    return 0xffffffff;
  }
  if ((-1 < (int)param_1) && (param_1 < DAT_454626e8)) {
    local_10 = (int)param_1 >> 5;
    iVar11 = (param_1 & 0x1f) * 0x40;
    bVar3 = *(byte *)((&DAT_454612f8)[local_10] + 4 + iVar11);
    if ((bVar3 & 1) != 0) {
      if (param_3 < 0x80000000) {
        if ((param_3 == 0) || ((bVar3 & 2) != 0)) {
          return 0;
        }
        if (param_2 != (LPWSTR)0x0) {
          cVar2 = (char)(*(char *)((&DAT_454612f8)[local_10] + 0x24 + iVar11) * '\x02') >> 1;
          if (cVar2 == '\x01') {
            if ((~param_3 & 1) == 0) goto LAB_45440c71;
            sVar12 = param_3 >> 1;
            if (sVar12 < 4) {
              sVar12 = 4;
            }
            local_14 = FUN_4543760c(sVar12);
            if (local_14 == (LPWSTR)0x0) {
              piVar6 = __errno();
              *piVar6 = 0xc;
              puVar5 = ___doserrno();
              *puVar5 = 8;
              return 0xffffffff;
            }
            uVar19 = FUN_4543cd54(param_1,0,0,(PLARGE_INTEGER)0x1);
            iVar10 = (&DAT_454612f8)[local_10];
            *(int *)(iVar10 + 0x28 + iVar11) = (int)uVar19;
            *(int *)(iVar10 + 0x2c + iVar11) = (int)((ulonglong)uVar19 >> 0x20);
          }
          else {
            sVar12 = param_3;
            if (cVar2 == '\x02') {
              if ((~param_3 & 1) == 0) goto LAB_45440c71;
              sVar12 = param_3 & 0xfffffffe;
            }
            local_14 = param_2;
          }
          uVar13 = sVar12;
          local_20 = local_14;
          if ((((*(byte *)((&DAT_454612f8)[local_10] + 4 + iVar11) & 0x48) != 0) &&
              (bVar3 = *(byte *)((&DAT_454612f8)[local_10] + 5 + iVar11), bVar3 != 10)) &&
             (sVar12 != 0)) {
            *(byte *)local_14 = bVar3;
            local_20 = (LPWSTR)((int)local_14 + 1);
            uVar16 = 1;
            uVar13 = sVar12 - 1;
            *(undefined1 *)((&DAT_454612f8)[local_10] + 5 + iVar11) = 10;
            if (((cVar2 != '\0') &&
                (bVar3 = *(byte *)((&DAT_454612f8)[local_10] + 0x25 + iVar11), bVar3 != 10)) &&
               (uVar13 != 0)) {
              *(byte *)local_20 = bVar3;
              local_20 = local_14 + 1;
              uVar13 = sVar12 - 2;
              uVar16 = 2;
              *(undefined1 *)((&DAT_454612f8)[local_10] + 0x25 + iVar11) = 10;
              if (((cVar2 == '\x01') &&
                  (bVar3 = *(byte *)((&DAT_454612f8)[local_10] + 0x26 + iVar11), bVar3 != 10)) &&
                 (uVar13 != 0)) {
                *(byte *)local_20 = bVar3;
                local_20 = (LPWSTR)((int)local_14 + 3);
                uVar13 = sVar12 - 3;
                uVar16 = 3;
                *(undefined1 *)((&DAT_454612f8)[local_10] + 0x26 + iVar11) = 10;
              }
            }
          }
          bVar3 = FUN_4543c2b0(param_1);
          if ((((CONCAT31(extraout_var,bVar3) == 0) ||
               ((*(byte *)((&DAT_454612f8)[local_10] + 4 + iVar11) & 0x80) == 0)) ||
              (local_24 = (WCHAR *)GetConsoleMode(*(HANDLE *)((&DAT_454612f8)[local_10] + iVar11),
                                                  (LPDWORD)&local_24), local_24 == (WCHAR *)0x0)) ||
             (cVar2 != '\x02')) {
            BVar7 = ReadFile(*(HANDLE *)((&DAT_454612f8)[local_10] + iVar11),local_20,uVar13,
                             &local_18,(LPOVERLAPPED)0x0);
            if (((BVar7 != 0) && (-1 < (int)local_18)) && (local_18 <= uVar13)) goto LAB_45440e58;
            uVar8 = GetLastError();
            if (uVar8 != 5) {
              if (uVar8 == 0x6d) {
                uVar13 = 0;
                goto LAB_454410cd;
              }
              goto LAB_45440e03;
            }
            piVar6 = __errno();
            *piVar6 = 9;
            puVar5 = ___doserrno();
            *puVar5 = 5;
          }
          else {
            BVar7 = ReadConsoleW(*(HANDLE *)((&DAT_454612f8)[local_10] + iVar11),local_20,
                                 uVar13 >> 1,&local_18,(PCONSOLE_READCONSOLE_CONTROL)0x0);
            if (BVar7 != 0) {
              local_18 = local_18 * 2;
LAB_45440e58:
              uVar16 = uVar16 + local_18;
              iVar10 = (&DAT_454612f8)[local_10];
              bVar3 = *(byte *)(iVar10 + 4 + iVar11);
              uVar13 = local_1c;
              if (-1 < (char)bVar3) goto LAB_454410cd;
              if (cVar2 == '\x02') {
                if (local_24 == (WCHAR *)0x0) {
                  if ((local_18 == 0) || (*local_14 != L'\n')) {
                    bVar3 = bVar3 & 0xfb;
                  }
                  else {
                    bVar3 = bVar3 | 4;
                  }
                  *(byte *)(iVar10 + 4 + iVar11) = bVar3;
                  local_24 = (WCHAR *)((int)local_14 + uVar16);
                  iVar10 = local_10;
                  pWVar14 = local_14;
                  pWVar18 = local_14;
                  if (local_14 < local_24) {
                    do {
                      WVar4 = *pWVar18;
                      if (WVar4 == L'\x1a') {
                        bVar3 = *(byte *)((&DAT_454612f8)[iVar10] + 4 + iVar11);
                        if ((bVar3 & 0x40) == 0) {
                          *(byte *)((&DAT_454612f8)[iVar10] + 4 + iVar11) = bVar3 | 2;
                        }
                        else {
                          *pWVar14 = *pWVar18;
                          pWVar14 = pWVar14 + 1;
                        }
                        break;
                      }
                      if (WVar4 == L'\r') {
                        if (pWVar18 < local_24 + -1) {
                          if (pWVar18[1] != L'\n') {
                            *pWVar14 = L'\r';
                            iVar10 = local_10;
                            goto LAB_454411e2;
                          }
                          pWVar18 = pWVar18 + 2;
                          *pWVar14 = L'\n';
LAB_454412c4:
                          pWVar14 = pWVar14 + 1;
                          iVar10 = local_10;
                        }
                        else {
                          pWVar18 = pWVar18 + 1;
                          BVar7 = ReadFile(*(HANDLE *)((&DAT_454612f8)[iVar10] + iVar11),&local_c,2,
                                           &local_18,(LPOVERLAPPED)0x0);
                          if (((BVar7 == 0) && (DVar9 = GetLastError(), DVar9 != 0)) ||
                             (local_18 == 0)) {
                            *pWVar14 = L'\r';
                            pWVar14 = pWVar14 + 1;
                            iVar10 = local_10;
                          }
                          else {
                            iVar10 = local_10;
                            if ((*(byte *)((&DAT_454612f8)[local_10] + 4 + iVar11) & 0x48) == 0) {
                              if ((pWVar14 == local_14) && (local_c == 10)) {
                                *pWVar14 = L'\n';
                                pWVar14 = pWVar14 + 1;
                              }
                              else {
                                FUN_4543cd54(param_1,0xfffffffe,0xffffffff,(PLARGE_INTEGER)0x1);
                                iVar10 = local_10;
                                if (local_c != 10) {
                                  *pWVar14 = L'\r';
                                  goto LAB_454412c4;
                                }
                              }
                            }
                            else if (local_c == 10) {
                              *pWVar14 = L'\n';
                              pWVar14 = pWVar14 + 1;
                            }
                            else {
                              *pWVar14 = L'\r';
                              pWVar14 = pWVar14 + 1;
                              *(undefined1 *)((&DAT_454612f8)[local_10] + 5 + iVar11) =
                                   (undefined1)local_c;
                              *(undefined1 *)((&DAT_454612f8)[local_10] + 0x25 + iVar11) =
                                   local_c._1_1_;
                              *(undefined1 *)((&DAT_454612f8)[local_10] + 0x26 + iVar11) = 10;
                            }
                          }
                        }
                      }
                      else {
                        *pWVar14 = WVar4;
LAB_454411e2:
                        pWVar14 = pWVar14 + 1;
                        pWVar18 = pWVar18 + 1;
                      }
                    } while (pWVar18 < local_24);
                  }
                  uVar16 = (int)pWVar14 - (int)local_14;
                  uVar13 = local_1c;
                }
                else {
                  pWVar14 = local_14;
                  pWVar18 = local_14;
                  while (pWVar14 < local_14 + (int)uVar16 / 2) {
                    WVar4 = *pWVar14;
                    if (WVar4 == L'\x1a') {
                      pbVar1 = (byte *)((&DAT_454612f8)[local_10] + 4 + iVar11);
                      *pbVar1 = *pbVar1 | 2;
                      break;
                    }
                    if (WVar4 == L'\r') {
                      if (pWVar14 < local_14 + (int)uVar16 / 2 + -1) {
                        pWVar14 = pWVar14 + 1;
                        WVar4 = L'\n';
                        if (*pWVar14 != L'\n') {
                          WVar4 = L'\r';
                        }
                        *pWVar18 = WVar4;
                        pWVar18 = pWVar18 + 1;
                      }
                    }
                    else {
                      *pWVar18 = WVar4;
                      pWVar18 = pWVar18 + 1;
                      pWVar14 = pWVar14 + 1;
                    }
                  }
                  uVar16 = (int)pWVar18 - (int)local_14 & 0xfffffffe;
                }
                goto LAB_454410cd;
              }
              if ((local_18 == 0) || ((byte)*local_14 != 10)) {
                bVar3 = bVar3 & 0xfb;
              }
              else {
                bVar3 = bVar3 | 4;
              }
              *(byte *)(iVar10 + 4 + iVar11) = bVar3;
              local_24 = local_14;
              local_20 = (LPWSTR)((int)local_14 + uVar16);
              iVar10 = local_10;
              pWVar14 = local_14;
              pWVar15 = local_14;
              if (local_14 < local_20) {
                do {
                  bVar3 = (byte)*pWVar15;
                  if (bVar3 == 0x1a) {
                    bVar3 = *(byte *)((&DAT_454612f8)[iVar10] + 4 + iVar11);
                    if ((bVar3 & 0x40) == 0) {
                      *(byte *)((&DAT_454612f8)[iVar10] + 4 + iVar11) = bVar3 | 2;
                    }
                    else {
                      *(byte *)pWVar14 = (byte)*pWVar15;
                      pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                    }
                    break;
                  }
                  if (bVar3 == 0xd) {
                    if (pWVar15 < (LPWSTR)((int)local_20 + -1)) {
                      pWVar17 = (LPWSTR)((int)pWVar15 + 1);
                      if (*(byte *)pWVar17 == 10) {
                        pWVar17 = pWVar15 + 1;
                        *(byte *)pWVar14 = 10;
LAB_45440f8a:
                        pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                      }
                      else {
                        *(byte *)pWVar14 = 0xd;
                        pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                      }
                    }
                    else {
                      pWVar17 = (LPWSTR)((int)pWVar15 + 1);
                      BVar7 = ReadFile(*(HANDLE *)((&DAT_454612f8)[iVar10] + iVar11),&local_5,1,
                                       &local_18,(LPOVERLAPPED)0x0);
                      if (((BVar7 == 0) && (DVar9 = GetLastError(), DVar9 != 0)) || (local_18 == 0))
                      {
                        *(byte *)pWVar14 = 0xd;
                        pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                        iVar10 = local_10;
                      }
                      else {
                        iVar10 = local_10;
                        if ((*(byte *)((&DAT_454612f8)[local_10] + 4 + iVar11) & 0x48) == 0) {
                          if ((pWVar14 == local_14) && (local_5 == '\n')) {
                            *(byte *)pWVar14 = 10;
                            pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                          }
                          else {
                            FUN_4543cd54(param_1,0xffffffff,0xffffffff,(PLARGE_INTEGER)0x1);
                            iVar10 = local_10;
                            if (local_5 != '\n') {
                              *(byte *)pWVar14 = 0xd;
                              goto LAB_45440f8a;
                            }
                          }
                        }
                        else if (local_5 == '\n') {
                          *(byte *)pWVar14 = 10;
                          pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                        }
                        else {
                          *(byte *)pWVar14 = 0xd;
                          pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                          *(char *)((&DAT_454612f8)[local_10] + 5 + iVar11) = local_5;
                        }
                      }
                    }
                  }
                  else {
                    *(byte *)pWVar14 = bVar3;
                    pWVar14 = (LPWSTR)((int)pWVar14 + 1);
                    pWVar17 = (LPWSTR)((int)pWVar15 + 1);
                  }
                  pWVar15 = pWVar17;
                } while (pWVar17 < local_20);
              }
              uVar16 = (int)pWVar14 - (int)local_14;
              uVar13 = local_1c;
              if ((cVar2 != '\x01') || (uVar16 == 0)) goto LAB_454410cd;
              bVar3 = *(byte *)((int)pWVar14 + -1);
              if ((char)bVar3 < '\0') {
                iVar10 = 1;
                cVar2 = (&DAT_4545ed08)[bVar3];
                pWVar14 = (LPWSTR)((int)pWVar14 + -1);
                while (((cVar2 == '\0' && (iVar10 < 5)) && (local_14 <= pWVar14))) {
                  pWVar14 = (LPWSTR)((int)pWVar14 + -1);
                  iVar10 = iVar10 + 1;
                  cVar2 = (&DAT_4545ed08)[*(byte *)pWVar14];
                }
                if ((char)(&DAT_4545ed08)[(byte)*pWVar14] == 0) {
                  piVar6 = __errno();
                  *piVar6 = 0x2a;
                  goto LAB_45440e0a;
                }
                if ((char)(&DAT_4545ed08)[(byte)*pWVar14] + 1 == iVar10) {
                  pWVar14 = (LPWSTR)((int)pWVar14 + iVar10);
                }
                else if ((*(byte *)((&DAT_454612f8)[local_10] + 4 + iVar11) & 0x48) == 0) {
                  FUN_4543cd54(param_1,-iVar10,-iVar10 >> 0x1f,(PLARGE_INTEGER)0x1);
                }
                else {
                  pWVar15 = (LPWSTR)((int)pWVar14 + 1);
                  *(byte *)((&DAT_454612f8)[local_10] + 5 + iVar11) = (byte)*pWVar14;
                  if (1 < iVar10) {
                    bVar3 = *(byte *)pWVar15;
                    pWVar15 = pWVar14 + 1;
                    *(byte *)((&DAT_454612f8)[local_10] + 0x25 + iVar11) = bVar3;
                  }
                  if (iVar10 == 3) {
                    WVar4 = *pWVar15;
                    pWVar15 = (LPWSTR)((int)pWVar15 + 1);
                    *(byte *)((&DAT_454612f8)[local_10] + 0x26 + iVar11) = (byte)WVar4;
                  }
                  pWVar14 = (LPWSTR)((int)pWVar15 - iVar10);
                }
              }
              cbMultiByte = (int)pWVar14 - (int)local_14;
              iVar10 = MultiByteToWideChar(0xfde9,0,(LPCSTR)local_14,cbMultiByte,param_2,
                                           param_3 >> 1);
              uVar16 = 0;
              if (iVar10 != 0) {
                uVar16 = iVar10 * 2;
                *(uint *)((&DAT_454612f8)[local_10] + 0x30 + iVar11) = (uint)(iVar10 != cbMultiByte)
                ;
                uVar13 = local_1c;
                goto LAB_454410cd;
              }
            }
            uVar8 = GetLastError();
LAB_45440e03:
            FID_conflict___dosmaperr(uVar8);
          }
LAB_45440e0a:
          uVar13 = 0xffffffff;
LAB_454410cd:
          if (local_14 != param_2) {
            FID_conflict__free(local_14);
          }
          if (uVar13 != 0xfffffffe) {
            return uVar13;
          }
          return uVar16;
        }
LAB_45440c71:
        puVar5 = ___doserrno();
        *puVar5 = 0;
      }
      else {
        puVar5 = ___doserrno();
        *puVar5 = 0;
      }
      piVar6 = __errno();
      *piVar6 = 0x16;
      goto LAB_4544134d;
    }
  }
  puVar5 = ___doserrno();
  *puVar5 = 0;
  piVar6 = __errno();
  *piVar6 = 9;
LAB_4544134d:
  FUN_45432798();
  return 0xffffffff;
}



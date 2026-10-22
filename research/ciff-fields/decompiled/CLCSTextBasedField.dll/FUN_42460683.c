// Source: CLCSTextBasedField.dll @ 42460683; FUN_42460683

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_42460683(void *this,HDC param_1,HFONT param_2,wchar_t *param_3,LPRECT param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  HGDIOBJ h;
  undefined4 *this_00;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  LOGFONTW *pv;
  int local_108;
  HGDIOBJ local_104;
  char local_fd;
  int *local_fc;
  int local_f8;
  HDC local_f4;
  HFONT local_f0;
  int local_ec;
  tagTEXTMETRICW local_e8;
  LOGFONTW local_ac;
  tagTEXTMETRICW local_50;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x104;
  local_8 = 0x42460692;
  local_f4 = param_1;
  local_f0 = param_2;
  local_fc = this;
  if ((param_4 == (LPRECT)0x0) ||
     (iVar3 = FUN_42460e87(this,(undefined8 *)param_2,param_3,~(byte)(param_5 >> 5) & 1,&local_fd),
     iVar3 < 0)) goto LAB_4246091f;
  pv = &local_ac;
  iVar3 = 0x5c;
  h = GetCurrentObject(param_1,6);
  GetObjectW(h,iVar3,pv);
  if ((local_fd == '\0') && (((param_5 & 0x1400000) == 0 && (local_ac.lfOrientation == 0)))) {
    iVar3 = DrawTextW(param_1,(LPCWSTR)local_f0,(int)param_3,param_4,param_5);
    if ((param_5 & 0x400) != 0) {
      GetTextMetricsW(param_1,&local_e8);
      local_fc[1] = iVar3 / local_e8.tmHeight;
    }
    goto LAB_4246091f;
  }
  iVar3 = 0;
  local_104 = (HGDIOBJ)0x0;
  local_f0 = (HFONT)0x0;
  local_f8 = 0;
  local_108 = 2;
  if ((local_ac.lfOrientation != 0) || (local_ac.lfEscapement != 0)) {
    if (local_ac.lfOrientation == 900) {
      local_f8 = 1;
    }
    else if (local_ac.lfOrientation == 0x708) {
      local_f8 = 2;
    }
    else if (local_ac.lfOrientation == 0xa8c) {
      local_f8 = 3;
    }
    local_ac.lfEscapement = 0;
    local_ac.lfOrientation = 0;
    local_f0 = CreateFontIndirectW(&local_ac);
    local_104 = SelectObject(param_1,local_f0);
  }
  this_00 = FUN_42460ba7();
  local_8 = 0;
  if (this_00 == (undefined4 *)0x0) goto LAB_4246091f;
  local_ec = FUN_42461ca6(local_fc,local_f4,this_00);
  if (-1 < local_ec) {
    if ((local_f8 == 0) || (local_f8 == 2)) {
      uVar4 = param_4->right - param_4->left;
    }
    else {
      uVar4 = param_4->bottom - param_4->top;
    }
    if (((param_5 & 0x10) == 0) || (local_ec = FUN_4245fdb6(local_fc,local_f4,uVar4), -1 < local_ec)
       ) {
      GetTextMetricsW(local_f4,&local_50);
      if (local_104 != (HGDIOBJ)0x0) {
        SelectObject(local_f4,local_104);
        DeleteObject(local_f0);
      }
      uVar4 = param_5 >> 9;
      if ((param_5 & 0x400) == 0) {
        if ((param_5 & 2) == 0) {
          if ((param_5 & 1) == 0) {
            local_108 = 0;
            if ((param_5 & 0x400000) != 0) {
              local_108 = 3;
            }
          }
        }
        else {
          local_108 = 1;
        }
        if ((param_5 & 0xc) != 0) {
          uVar2 = local_fc[1];
          local_ec = uVar2 * local_50.tmHeight;
          if ((1 < uVar2) && ((uVar4 & 1) != 0)) {
            local_ec = local_ec + (uVar2 - 1) * local_50.tmExternalLeading;
          }
          if ((param_5 & 8) == 0) {
            if (local_f8 == 0) {
              param_4->top = param_4->top + ((param_4->bottom - param_4->top) - local_ec) / 2;
            }
            else if (local_f8 == 1) {
              param_4->left = param_4->left + ((param_4->right - param_4->left) - local_ec) / 2;
            }
            else {
              if (local_f8 == 2) {
                iVar3 = ((param_4->bottom - param_4->top) - local_ec) / 2 + param_4->top;
                goto LAB_42460b42;
              }
              if (local_f8 == 3) {
                iVar3 = ((param_4->right - param_4->left) - local_ec) / 2 + param_4->left;
                goto LAB_42460b27;
              }
            }
          }
          else if (local_f8 == 0) {
            param_4->top = param_4->bottom - local_ec;
          }
          else if (local_f8 == 1) {
            param_4->left = param_4->right - local_ec;
          }
          else if (local_f8 == 2) {
            iVar3 = param_4->top;
LAB_42460b42:
            param_4->bottom = iVar3 + local_ec;
          }
          else if (local_f8 == 3) {
            iVar3 = param_4->left;
LAB_42460b27:
            param_4->right = iVar3 + local_ec;
          }
        }
        FUN_424614d3(local_fc,local_f4,param_4->left,param_4->top,param_5 >> 10 & 0x80,local_108,
                     local_f8,(byte)uVar4 & 1,&param_4->left,&local_50.tmHeight,this_00);
      }
      else {
        local_f0 = (HFONT)local_fc[1];
        if (local_f0 < (HFONT)0x2) {
          if (*local_fc != 0) {
            iVar5 = GetTextCharacterExtra(local_f4);
            if (iVar5 == 0x8000000) {
              iVar5 = 0;
            }
            iVar9 = local_fc[3];
            local_f4 = *(HDC *)(iVar9 + 0xc);
            if (local_f4 != (HDC)0x0) {
              iVar8 = *(int *)(iVar9 + 4) + -1;
              local_f0 = (HFONT)(local_fc[9] + 0x18 + *(int *)(iVar9 + 8) * 0x20);
              do {
                iVar3 = iVar3 + local_f0->unused;
                if (iVar8 != 0) {
                  pbVar7 = (byte *)(local_fc[0xf] + *(int *)(local_fc[3] + 8) * 2);
                  iVar9 = iVar8;
                  do {
                    bVar1 = *pbVar7;
                    pbVar7 = pbVar7 + 2;
                    iVar6 = 0;
                    if ((bVar1 & 0x10) != 0) {
                      iVar6 = iVar5;
                    }
                    iVar3 = iVar3 + iVar6;
                    iVar9 = iVar9 + -1;
                  } while (iVar9 != 0);
                }
                local_f0 = local_f0 + 8;
                local_f4 = (HDC)((int)&local_f4[-1].unused + 3);
              } while (local_f4 != (HDC)0x0);
              local_f4 = (HDC)0x0;
            }
          }
          if ((local_f8 == 0) || (local_f8 == 2)) {
            iVar3 = param_4->left + iVar3;
            if (((param_5 & 0x20) != 0) || (iVar3 < param_4->right)) {
              param_4->right = iVar3;
            }
            iVar3 = 0;
            if ((uVar4 & 1) != 0) {
              iVar3 = local_50.tmExternalLeading;
            }
            iVar3 = iVar3 + param_4->top + local_50.tmHeight;
          }
          else {
            iVar5 = 0;
            if ((uVar4 & 1) != 0) {
              iVar5 = local_50.tmExternalLeading;
            }
            param_4->right = iVar5 + param_4->left + local_50.tmHeight;
            iVar3 = param_4->top + iVar3;
            if (param_4->bottom <= iVar3) goto LAB_42460910;
          }
        }
        else {
          if ((local_f8 != 0) && (local_f8 != 2)) {
            iVar3 = 0;
            if ((uVar4 & 1) != 0) {
              iVar3 = local_50.tmExternalLeading;
            }
            param_4->right = (iVar3 + local_50.tmHeight) * (int)local_f0 + param_4->left;
            goto LAB_42460910;
          }
          iVar3 = 0;
          if ((uVar4 & 1) != 0) {
            iVar3 = local_50.tmExternalLeading;
          }
          iVar3 = (iVar3 + local_50.tmHeight) * (int)local_f0 + param_4->top;
        }
        param_4->bottom = iVar3;
      }
    }
  }
LAB_42460910:
  if (this_00 != (undefined4 *)0x0) {
    FUN_4245fd8e(this_00,1);
  }
LAB_4246091f:
  FUN_4246ecf6();
  return;
}



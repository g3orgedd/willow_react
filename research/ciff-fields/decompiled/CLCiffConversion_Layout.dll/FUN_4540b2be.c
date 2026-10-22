// Source: CLCiffConversion_Layout.dll @ 4540b2be; FUN_4540b2be

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall
FUN_4540b2be(void *this,HDC param_1,HFONT param_2,wchar_t *param_3,LPRECT param_4,uint param_5)

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
  LOGFONTA *pv;
  int local_e0;
  HGDIOBJ local_dc;
  char local_d5;
  int *local_d4;
  int local_d0;
  HDC local_cc;
  HFONT local_c8;
  int local_c4;
  tagTEXTMETRICA local_c0;
  LOGFONTA local_88;
  tagTEXTMETRICA local_4c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xdc;
  local_8 = 0x4540b2cd;
  local_cc = param_1;
  local_c8 = param_2;
  local_d4 = this;
  if ((param_4 == (LPRECT)0x0) ||
     (iVar3 = FUN_4540bab6(this,(undefined8 *)param_2,param_3,~(byte)(param_5 >> 5) & 1,&local_d5),
     iVar3 < 0)) goto LAB_4540b54e;
  pv = &local_88;
  iVar3 = 0x3c;
  h = GetCurrentObject(param_1,6);
  GetObjectA(h,iVar3,pv);
  if ((local_d5 == '\0') && (((param_5 & 0x1400000) == 0 && (local_88.lfOrientation == 0)))) {
    iVar3 = DrawTextW(param_1,(LPCWSTR)local_c8,(int)param_3,param_4,param_5);
    if ((param_5 & 0x400) != 0) {
      GetTextMetricsA(param_1,&local_c0);
      local_d4[1] = iVar3 / local_c0.tmHeight;
    }
    goto LAB_4540b54e;
  }
  iVar3 = 0;
  local_dc = (HGDIOBJ)0x0;
  local_c8 = (HFONT)0x0;
  local_d0 = 0;
  local_e0 = 2;
  if ((local_88.lfOrientation != 0) || (local_88.lfEscapement != 0)) {
    if (local_88.lfOrientation == 900) {
      local_d0 = 1;
    }
    else if (local_88.lfOrientation == 0x708) {
      local_d0 = 2;
    }
    else if (local_88.lfOrientation == 0xa8c) {
      local_d0 = 3;
    }
    local_88.lfEscapement = 0;
    local_88.lfOrientation = 0;
    local_c8 = CreateFontIndirectA(&local_88);
    local_dc = SelectObject(param_1,local_c8);
  }
  this_00 = FUN_4540b7d6();
  local_8 = 0;
  if (this_00 == (undefined4 *)0x0) goto LAB_4540b54e;
  local_c4 = FUN_4540c8d5(local_d4,local_cc,this_00);
  if (-1 < local_c4) {
    if ((local_d0 == 0) || (local_d0 == 2)) {
      uVar4 = param_4->right - param_4->left;
    }
    else {
      uVar4 = param_4->bottom - param_4->top;
    }
    if (((param_5 & 0x10) == 0) || (local_c4 = FUN_4540a9f1(local_d4,local_cc,uVar4), -1 < local_c4)
       ) {
      GetTextMetricsA(local_cc,&local_4c);
      if (local_dc != (HGDIOBJ)0x0) {
        SelectObject(local_cc,local_dc);
        DeleteObject(local_c8);
      }
      uVar4 = param_5 >> 9;
      if ((param_5 & 0x400) == 0) {
        if ((param_5 & 2) == 0) {
          if ((param_5 & 1) == 0) {
            local_e0 = 0;
            if ((param_5 & 0x400000) != 0) {
              local_e0 = 3;
            }
          }
        }
        else {
          local_e0 = 1;
        }
        if ((param_5 & 0xc) != 0) {
          uVar2 = local_d4[1];
          local_c4 = uVar2 * local_4c.tmHeight;
          if ((1 < uVar2) && ((uVar4 & 1) != 0)) {
            local_c4 = local_c4 + (uVar2 - 1) * local_4c.tmExternalLeading;
          }
          if ((param_5 & 8) == 0) {
            if (local_d0 == 0) {
              param_4->top = param_4->top + ((param_4->bottom - param_4->top) - local_c4) / 2;
            }
            else if (local_d0 == 1) {
              param_4->left = param_4->left + ((param_4->right - param_4->left) - local_c4) / 2;
            }
            else {
              if (local_d0 == 2) {
                iVar3 = ((param_4->bottom - param_4->top) - local_c4) / 2 + param_4->top;
                goto LAB_4540b771;
              }
              if (local_d0 == 3) {
                iVar3 = ((param_4->right - param_4->left) - local_c4) / 2 + param_4->left;
                goto LAB_4540b756;
              }
            }
          }
          else if (local_d0 == 0) {
            param_4->top = param_4->bottom - local_c4;
          }
          else if (local_d0 == 1) {
            param_4->left = param_4->right - local_c4;
          }
          else if (local_d0 == 2) {
            iVar3 = param_4->top;
LAB_4540b771:
            param_4->bottom = iVar3 + local_c4;
          }
          else if (local_d0 == 3) {
            iVar3 = param_4->left;
LAB_4540b756:
            param_4->right = iVar3 + local_c4;
          }
        }
        FUN_4540c102(local_d4,local_cc,param_4->left,param_4->top,param_5 >> 10 & 0x80,local_e0,
                     local_d0,(byte)uVar4 & 1,&param_4->left,&local_4c.tmHeight,this_00);
      }
      else {
        local_c8 = (HFONT)local_d4[1];
        if (local_c8 < (HFONT)0x2) {
          if (*local_d4 != 0) {
            iVar5 = GetTextCharacterExtra(local_cc);
            if (iVar5 == 0x8000000) {
              iVar5 = 0;
            }
            iVar9 = local_d4[3];
            local_cc = *(HDC *)(iVar9 + 0xc);
            if (local_cc != (HDC)0x0) {
              iVar8 = *(int *)(iVar9 + 4) + -1;
              local_c8 = (HFONT)(local_d4[9] + 0x18 + *(int *)(iVar9 + 8) * 0x20);
              do {
                iVar3 = iVar3 + local_c8->unused;
                if (iVar8 != 0) {
                  pbVar7 = (byte *)(local_d4[0xf] + *(int *)(local_d4[3] + 8) * 2);
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
                local_c8 = local_c8 + 8;
                local_cc = (HDC)((int)&local_cc[-1].unused + 3);
              } while (local_cc != (HDC)0x0);
              local_cc = (HDC)0x0;
            }
          }
          if ((local_d0 == 0) || (local_d0 == 2)) {
            iVar3 = param_4->left + iVar3;
            if (((param_5 & 0x20) != 0) || (iVar3 < param_4->right)) {
              param_4->right = iVar3;
            }
            iVar3 = 0;
            if ((uVar4 & 1) != 0) {
              iVar3 = local_4c.tmExternalLeading;
            }
            iVar3 = iVar3 + param_4->top + local_4c.tmHeight;
          }
          else {
            iVar5 = 0;
            if ((uVar4 & 1) != 0) {
              iVar5 = local_4c.tmExternalLeading;
            }
            param_4->right = iVar5 + param_4->left + local_4c.tmHeight;
            iVar3 = param_4->top + iVar3;
            if (param_4->bottom <= iVar3) goto LAB_4540b53f;
          }
        }
        else {
          if ((local_d0 != 0) && (local_d0 != 2)) {
            iVar3 = 0;
            if ((uVar4 & 1) != 0) {
              iVar3 = local_4c.tmExternalLeading;
            }
            param_4->right = (iVar3 + local_4c.tmHeight) * (int)local_c8 + param_4->left;
            goto LAB_4540b53f;
          }
          iVar3 = 0;
          if ((uVar4 & 1) != 0) {
            iVar3 = local_4c.tmExternalLeading;
          }
          iVar3 = (iVar3 + local_4c.tmHeight) * (int)local_c8 + param_4->top;
        }
        param_4->bottom = iVar3;
      }
    }
  }
LAB_4540b53f:
  if (this_00 != (undefined4 *)0x0) {
    FUN_4540a9c9(this_00,1);
  }
LAB_4540b54e:
  FUN_4542a957();
  return;
}



// Source: CLCSTextBasedField.dll @ 42460e87; FUN_42460e87

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall
FUN_42460e87(void *this,undefined8 *param_1,wchar_t *param_2,char param_3,char *param_4)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  wchar_t *pwVar5;
  wchar_t *pwVar6;
  BSTR pOVar7;
  size_t sVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  undefined8 *puVar13;
  uint uVar14;
  undefined1 *puVar15;
  uint *local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  size_t local_38;
  uint local_34;
  uint *local_30;
  uint local_2c;
  uint local_28;
  uint *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pwVar5 = param_2;
  uStack_4 = 0x50;
  local_8 = 0x42460e93;
  *param_4 = '\0';
  if ((param_1 == (undefined8 *)0x0) || (param_2 == (wchar_t *)0x0)) {
    iVar9 = -0x7ff8ffa9;
  }
  else {
    pwVar6 = (wchar_t *)SysStringLen(*(BSTR *)((int)this + 0x100));
    if (pwVar6 < param_2) {
      SysFreeString(*(BSTR *)((int)this + 0x100));
      *(undefined4 *)((int)this + 0x100) = 0;
      pwVar6 = param_2;
      if (param_2 < (wchar_t *)0x80) {
        pwVar6 = (wchar_t *)0x80;
      }
      pOVar7 = SysAllocStringLen((OLECHAR *)0x0,(UINT)pwVar6);
      if (*(BSTR *)((int)this + 0x100) != pOVar7) {
        SysFreeString(*(BSTR *)((int)this + 0x100));
        *(BSTR *)((int)this + 0x100) = pOVar7;
      }
    }
    if ((wchar_t *)(*(int *)((int)this + 0x70) - *(int *)((int)this + 0x6c)) < param_2) {
      FUN_424629e1((int *)((int)this + 0x6c),(uint)param_2);
    }
    if ((wchar_t *)(*(int *)((int)this + 0x94) - *(int *)((int)this + 0x90) >> 1) < param_2) {
      FUN_4246291e((int *)((int)this + 0x90),(uint)param_2);
    }
    FUN_4246d2c0(*(undefined8 **)((int)this + 0x100),param_1,(int)param_2 * 2);
    bVar4 = true;
    local_3c = 0x18;
    *(undefined2 *)((int)param_2 * 2 + *(int *)((int)this + 0x100)) = 0;
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 8) = 0;
    pwVar6 = *(wchar_t **)((int)this + 0x100);
    *(wchar_t **)((int)this + 0x104) = param_2;
    do {
      *(int *)this = *(int *)this + 1;
      if ((uint)((*(int *)((int)this + 0x10) - *(int *)((int)this + 0xc)) / local_3c) <
          *(uint *)this) {
        FUN_42462ad7((int *)((int)this + 0xc),*(uint *)this);
      }
      param_2 = (wchar_t *)0x0;
      *(undefined4 *)(*(int *)this * 0x18 + -4 + *(int *)((int)this + 0xc)) = 0;
      *(undefined4 *)(*(int *)this * 0x18 + -8 + *(int *)((int)this + 0xc)) = 0;
      if (param_3 != '\0') {
        local_38 = _wcscspn(pwVar6,L"\r\n");
        sVar8 = _wcslen(pwVar6);
        if (local_38 != sVar8) {
          param_2 = pwVar6 + local_38;
        }
      }
      *(wchar_t **)(*(int *)this * 0x18 + -0x18 + *(int *)((int)this + 0xc)) = pwVar6;
      if (param_2 == (wchar_t *)0x0) {
        *(int *)(*(int *)this * 0x18 + -0x14 + *(int *)((int)this + 0xc)) =
             (int)pwVar5 - ((int)pwVar6 - *(int *)((int)this + 0x100) >> 1);
        bVar4 = false;
      }
      else {
        *(int *)(*(int *)this * 0x18 + -0x14 + *(int *)((int)this + 0xc)) =
             (int)param_2 - (int)pwVar6 >> 1;
        if (*(int *)(*(int *)this * 0x18 + -0x14 + *(int *)((int)this + 0xc)) == 0) {
          *(undefined4 *)(*(int *)this * 0x18 + -0x14 + *(int *)((int)this + 0xc)) = 1;
        }
        pwVar6 = param_2 + 1;
        if ((*param_2 == L'\r') && (*pwVar6 == L'\n')) {
          pwVar6 = param_2 + 2;
        }
      }
    } while (bVar4);
    if (1 < *(uint *)this) {
      do {
        if (*(int *)(*(int *)this * 0x18 + -0x14 + *(int *)((int)this + 0xc)) != 0) break;
        uVar14 = *(int *)this - 1;
        *(uint *)this = uVar14;
      } while (1 < uVar14);
    }
    *(undefined4 *)((int)this + 4) = *(undefined4 *)this;
    iVar9 = ScriptGetProperties(&local_54,&local_50);
    if (-1 < iVar9) {
      puVar13 = (undefined8 *)0x0;
      param_1 = (undefined8 *)0x0;
      local_34 = 0;
      if (*(int *)this != 0) {
        local_38 = 0;
        do {
          piVar12 = (int *)(*(int *)((int)this + 0xc) + local_38);
          piVar12[2] = (int)puVar13;
          if (piVar12[1] == 0) {
            piVar12[3] = 0;
          }
          else {
            local_18 = piVar12;
            local_3c = FUN_42460c41(*(LCID *)((int)this + 0x11c),*(char *)((int)this + 0x10c),
                                    (undefined1 *)((int)this + 0x110),(char *)((int)this + 0x120),
                                    &local_40,(uint *)&param_3);
            uVar14 = (uint)piVar12[1] / 3;
            if ((uint)piVar12[1] / 3 < 5) {
              uVar14 = 5;
            }
            uVar11 = (int)param_1 + uVar14;
            local_28 = uVar14;
            if ((uint)(*(int *)((int)this + 0x1c) - *(int *)((int)this + 0x18) >> 3) < uVar11) {
              FUN_42462b5d((void *)((int)this + 0x18),uVar11);
            }
            else if (uVar11 < (uint)(*(int *)((int)this + 0x1c) - *(int *)((int)this + 0x18) >> 3))
            {
              uVar14 = (*(int *)((int)this + 0x1c) - *(int *)((int)this + 0x18) >> 3) - (int)param_1
              ;
              local_28 = uVar14;
            }
            param_2 = (wchar_t *)0x0;
            local_60 = (uint *)0x0;
            local_5c = 0;
            local_58 = 0;
            local_8 = 0;
            local_30 = (uint *)0x0;
            FUN_42461f58(this,piVar12,(int *)&local_60,(uint *)&local_30);
            local_20 = 0;
            local_14 = 0;
            local_2c = 0;
            local_4c = local_5c - (int)local_60 >> 3;
            local_30 = local_60;
            if (local_4c != 0) {
              do {
                local_44 = *local_30;
                local_24 = (uint *)local_30[1];
                local_48 = 0;
                local_1c = 0;
                while( true ) {
                  local_48 = local_48 + 1;
                  iVar9 = local_3c;
                  if (10 < local_48) goto LAB_424614ba;
                  local_3c = ScriptItemize(local_44,local_24,(uVar14 - local_14) - (int)param_1,
                                           &local_40,&param_3,
                                           *(int *)((int)this + 0x18) +
                                           (local_14 + (int)param_1) * 8,&local_1c);
                  if (-1 < local_3c) break;
                  if (local_3c == -0x7fffbfff) {
                    iVar9 = -0x7fffbfff;
                    goto LAB_424614ba;
                  }
                  uVar14 = uVar14 + piVar12[1];
                  local_28 = uVar14;
                  FUN_42462b5d((void *)((int)this + 0x18),(int)param_1 + uVar14);
                }
                if ((local_20 != 0) && (iVar9 = 0, 0 < local_1c)) {
                  iVar10 = (local_14 + (int)param_1) * 8;
                  do {
                    piVar12 = (int *)(iVar10 + *(int *)((int)this + 0x18));
                    *piVar12 = *piVar12 + local_20;
                    iVar9 = iVar9 + 1;
                    iVar10 = iVar10 + 8;
                    piVar12 = local_18;
                    uVar14 = local_28;
                  } while (iVar9 < local_1c);
                }
                local_20 = local_20 + (int)local_24;
                param_2 = (wchar_t *)((int)param_2 + local_1c);
                local_14 = local_14 + local_1c;
                local_2c = local_2c + 1;
                local_30 = local_30 + 2;
              } while (local_2c < local_4c);
            }
            puVar15 = (undefined1 *)((int)param_2 + (int)param_1);
            if ((undefined1 *)(*(int *)((int)this + 0x28) - *(int *)((int)this + 0x24) >> 5) <
                puVar15) {
              FUN_42462be5((void *)((int)this + 0x24),puVar15);
            }
            if ((undefined1 *)(*(int *)((int)this + 0xa0) - *(int *)((int)this + 0x9c)) < puVar15) {
              FUN_424628d8((int *)((int)this + 0x9c),(uint)puVar15);
            }
            if ((undefined1 *)(*(int *)((int)this + 0xac) - *(int *)((int)this + 0xa8) >> 2) <
                puVar15) {
              FUN_4246297e((int *)((int)this + 0xa8),(uint)puVar15);
            }
            local_30 = (uint *)0x0;
            local_14 = 0;
            if (0 < (int)param_2) {
              local_20 = (int)param_2 + -1;
              iVar9 = (int)param_1 << 3;
              local_28 = (int)param_1 << 5;
              do {
                local_24 = (uint *)0x0;
                uVar2 = *(ushort *)(iVar9 + 4 + *(int *)((int)this + 0x18));
                uVar14 = uVar2 & 0x3ff;
                if ((int)uVar14 < local_50) {
                  local_24 = *(uint **)(local_54 + uVar14 * 4);
                }
                if (*param_4 == '\0') {
                  if (local_24 != (uint *)0x0) {
                    if (((*local_24 & 0x20000) != 0) || ((uVar2 & 0x400) != 0)) {
                      *param_4 = '\x01';
                    }
                    goto LAB_424612fe;
                  }
LAB_424613b5:
                  piVar12 = (int *)(*(int *)((int)this + 0x24) + local_28);
                  FUN_4246d2c0((undefined8 *)piVar12,
                               (undefined8 *)(*(int *)((int)this + 0x18) + iVar9),8);
                  piVar12[2] = *local_18 + *piVar12 * 2;
                  if (local_14 == local_20) {
                    iVar10 = local_18[1];
                  }
                  else {
                    iVar10 = *(int *)(iVar9 + 8 + *(int *)((int)this + 0x18));
                  }
                  piVar12[4] = 0;
                  piVar12[3] = iVar10 - *piVar12;
                  if (*(char *)((int)this + 0x128) == '\0') {
                    piVar12[7] = 0;
                  }
                  else {
                    iVar10 = FUN_42460bbd(this,*local_18,
                                          *(int *)(iVar9 + *(int *)((int)this + 0x18)));
                    piVar12[7] = iVar10;
                  }
                  *(byte *)(*(int *)((int)this + 0x9c) + local_14 + (int)param_1) =
                       *(byte *)((int)piVar12 + 6) & 0x1f;
                  local_30 = local_24;
                }
                else {
LAB_424612fe:
                  if ((local_24 == (uint *)0x0) || (local_30 == (uint *)0x0)) goto LAB_424613b5;
                  if ((((*local_24 & 0xffff) != (*local_30 & 0xffff)) && ((*local_24 & 0xffff) != 0)
                      ) || (((((*local_24 & 0x20000) != 0 || ((*local_30 & 0x20000) != 0)) ||
                             (iVar10 = *(int *)((int)this + 0x18),
                             ((*(ushort *)(iVar9 + -4 + iVar10) ^ *(ushort *)(iVar9 + 4 + iVar10)) &
                             0x400) != 0)) ||
                            ((((*(byte *)(iVar9 + 6 + iVar10) ^ *(byte *)(iVar9 + -2 + iVar10)) &
                              0x1f) != 0 ||
                             (uVar14 = FUN_42460cfc(this,*local_18,*(int *)(iVar9 + iVar10)),
                             (char)uVar14 != '\0')))))) goto LAB_424613b5;
                  iVar3 = *(int *)((int)this + 0x24);
                  if (local_14 == local_20) {
                    iVar10 = local_18[1];
                  }
                  else {
                    iVar10 = *(int *)(iVar9 + 8 + iVar10);
                  }
                  *(int *)((local_28 - 0x14) + iVar3) = iVar10 - *(int *)((local_28 - 0x20) + iVar3)
                  ;
                  puVar1 = (ushort *)((local_28 - 0x1c) + iVar3);
                  *puVar1 = *puVar1 & 0xfc00;
                  local_28 = local_28 - 0x20;
                  local_14 = local_14 + -1;
                  param_2 = (wchar_t *)((int)param_2 + -1);
                  local_20 = local_20 + -1;
                }
                local_14 = local_14 + 1;
                local_28 = local_28 + 0x20;
                iVar9 = iVar9 + 8;
                piVar12 = local_18;
              } while (local_14 < (int)param_2);
            }
            piVar12[3] = (int)param_2;
            *(int *)((int)this + 8) = *(int *)((int)this + 8) + (int)param_2;
            iVar9 = ScriptLayout(param_2,*(int *)((int)this + 0x9c) + (int)param_1,
                                 *(int *)((int)this + 0xa8) + (int)param_1 * 4,0);
            if (iVar9 < 0) {
LAB_424614ba:
              FUN_42430baf((int *)&local_60);
              return iVar9;
            }
            local_8 = 0xffffffff;
            puVar13 = (undefined8 *)((int)param_1 + (int)param_2);
            FUN_42430baf((int *)&local_60);
            param_1 = puVar13;
          }
          local_34 = local_34 + 1;
          local_38 = local_38 + 0x18;
        } while (local_34 < *(uint *)this);
      }
      iVar9 = 0;
    }
  }
  return iVar9;
}



// Source: CiffHelper.dll @ 4080f9ba; FUN_4080f9ba

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4080f9ba(void *this,int *param_1)

{
  wchar_t *pwVar1;
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  UINT UVar5;
  int *extraout_EAX;
  int *piVar6;
  undefined4 ****ppppuVar7;
  undefined1 **ppuVar8;
  long lVar9;
  long lVar10;
  wchar_t ****ppppwVar11;
  uint uVar12;
  code *pcVar13;
  int *piStack_160;
  long lStack_15c;
  int *piStack_158;
  long lStack_154;
  int *piStack_150;
  int *piStack_148;
  VARIANTARG local_110;
  undefined2 local_fc;
  undefined2 uStack_fa;
  undefined4 local_f4;
  undefined **local_ec;
  int local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  _union_2683 local_dc;
  void *local_cc;
  int *local_c8;
  void *local_c4;
  WCHAR local_c0 [2];
  BSTR local_bc;
  OLECHAR *local_b8;
  int local_b4;
  int local_b0;
  int *local_ac;
  BSTR local_a8;
  BSTR local_a4;
  int *local_a0;
  undefined1 *local_9c;
  BSTR local_98;
  BSTR local_94;
  wchar_t *local_90;
  uint local_8c;
  undefined8 local_88;
  char local_7d;
  undefined1 *local_7c;
  wchar_t ***local_78 [5];
  uint local_64;
  wchar_t ***local_60 [5];
  uint local_4c;
  wchar_t ***local_48 [5];
  uint local_34;
  undefined4 ***local_30 [4];
  uint local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x100;
  local_88._4_4_ = (int **)0xffffffff;
  pwVar1 = *(wchar_t **)((int)this + 0x70);
  local_8 = 0;
  local_cc = this;
  local_c4 = this;
  if (pwVar1 == (wchar_t *)0x0) {
    FUN_4080be87((undefined4 *)((int)this + 0x70),"");
  }
  else {
    local_88._4_4_ = (int **)FUN_408116ec((void *)((int)this + 0x54),pwVar1,0);
  }
  local_a8 = (BSTR)0x0;
  local_8._0_1_ = 2;
  iVar4 = (**(code **)(*param_1 + 100))();
  local_90 = (wchar_t *)0x0;
  local_8._0_1_ = 3;
  if (((iVar4 < 0) || (iVar4 = (**(code **)(*param_1 + 0x6c))(), iVar4 < 0)) ||
     (UVar5 = SysStringLen(local_a8), UVar5 == 0)) goto LAB_408102d5;
  FUN_408030e3(&local_b4,*(LPCWSTR *)((int)this + 0x74));
  local_8._0_1_ = 4;
  FUN_408030e3(local_c0,local_a8);
  local_8._0_1_ = 5;
  FUN_4080aa73((void *)((int)this + 0x8c),&local_b8,local_c0,&local_b4);
  local_8._0_1_ = 6;
  FUN_40802e40(&local_bc,local_b8);
  FUN_40802e76((uint *)&local_110);
  local_a0 = (int *)0x0;
  local_8._0_1_ = 9;
  iVar4 = FUN_4080f725((void *)((int)this + 0x28),(BSTR)&local_bc,(int)&local_a0);
  if ((iVar4 < 0) || (local_a0 == (int *)0x0)) {
    local_8 = CONCAT31(local_8._1_3_,8);
    if (local_a0 != (int *)0x0) {
      (**(code **)(*local_a0 + 8))();
    }
    VariantClear(&local_110);
    SysFreeString(local_bc);
    FUN_40803143((int *)&local_b8);
    FUN_40803143((int *)local_c0);
    FUN_40803143(&local_b4);
    SysFreeString(local_90);
    SysFreeString(local_a8);
    local_8 = 0xffffffff;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))();
    }
    FUN_408103e7();
    return;
  }
  local_c8 = (int *)0x0;
  local_8._0_1_ = 10;
  iVar4 = (**(code **)(*local_a0 + 0x54))();
  _local_fc = CONCAT22(uStack_fa,3);
  local_f4 = 0;
  local_ac = (int *)0x0;
  local_8._0_1_ = 0xc;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 0xc;
  pcVar13 = VariantClear_exref;
  if (-1 < iVar4) {
    if (local_c8 != (int *)0x0) {
      local_ac = (int *)0x0;
      piStack_148 = local_c8;
      iVar4 = (**(code **)(*local_c8 + 0x28))();
    }
    pcVar13 = VariantClear_exref;
    uVar2 = (undefined1)local_8;
    if ((-1 < iVar4) && (local_ac != (int *)0x0)) {
      FUN_40802e76((uint *)&local_dc);
      local_8._0_1_ = 0xd;
      piVar6 = local_ac;
      if (local_ac == (int *)0x0) {
        _com_issue_error(-0x7fffbffd);
        piVar6 = extraout_EAX;
      }
      local_e8 = (**(code **)(*piVar6 + 0x34))();
      if (local_e8 < 0) {
        local_ec = _com_error::vftable;
        local_e4 = 0;
        local_e0 = 0;
                    /* WARNING: Subroutine does not return */
        FUN_4082d44f((int *)&local_ec,&DAT_4085b6ac);
      }
      local_b0 = 0;
      (**(code **)(*param_1 + 0x24))();
      if ((local_dc.n2.vt == 7) || (local_dc.n2.vt == 5)) {
        FUN_40829343(&local_88,(VARIANTARG *)&local_dc.n2);
        FUN_40829763((double *)&local_88);
        iVar4 = (**(code **)(*param_1 + 0xa8))();
        if (-1 < iVar4) {
          FUN_40829cd3((double *)&local_88);
          iVar4 = (**(code **)(*param_1 + 0xb0))();
          if (-1 < iVar4) {
            FUN_4082a025((double *)&local_88);
            iVar4 = (**(code **)(*param_1 + 0xb8))();
            if (((-1 < iVar4) && (iVar4 = (**(code **)(*param_1 + 0x48))(), -1 < iVar4)) &&
               (local_b0 != 0)) {
              FUN_40829763((double *)&local_88);
              (**(code **)(*param_1 + 0x30))();
              FUN_40829cd3((double *)&local_88);
              (**(code **)(*param_1 + 0x38))();
              FUN_4082a025((double *)&local_88);
              piStack_148 = param_1;
              (**(code **)(*param_1 + 0x40))();
            }
          }
        }
      }
      else if (local_dc.n2.vt == 3) {
        if (local_b0 == 0) {
          basic_string<>(local_30,local_90);
          local_8._0_1_ = 0xe;
          for (uVar12 = 0; uVar12 < local_20; uVar12 = uVar12 + 1) {
            ppppuVar7 = local_30;
            if (7 < local_1c) {
              ppppuVar7 = (undefined4 ****)local_30[0];
            }
            sVar3 = FUN_4082dd5c((uint)*(ushort *)((int)ppppuVar7 + uVar12 * 2));
            if (sVar3 == 0x44) {
              (**(code **)(*param_1 + 0x30))();
            }
            else if (sVar3 == 0x4d) {
              (**(code **)(*param_1 + 0x38))();
            }
            else if (sVar3 == 0x57) {
              (**(code **)(*param_1 + 0x30))();
            }
            else if (sVar3 == 0x59) {
              (**(code **)(*param_1 + 0x40))();
            }
          }
          FUN_4080653d(local_30,'\x01',0);
        }
      }
      else if (local_dc.n2.vt == 8) {
        FUN_40802e40(&local_98,(OLECHAR *)local_dc._8_4_);
        local_a4 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x10);
        local_94 = local_98;
        local_7d = '\x01';
        local_8c = 0;
        UVar5 = SysStringLen(local_98);
        if (UVar5 != 0) {
          do {
            if (local_7d == '\0') {
              local_7c = (undefined1 *)(uint)(ushort)local_94[local_8c];
              ppuVar8 = &local_7c;
LAB_4080fd5c:
              FUN_40803f8b(&local_a4,(wchar_t *)ppuVar8);
            }
            else if (local_94[local_8c] != L' ') {
              local_7d = '\0';
              ppuVar8 = &local_9c;
              local_9c = (undefined1 *)(uint)(ushort)local_94[local_8c];
              goto LAB_4080fd5c;
            }
            local_8c = local_8c + 1;
            UVar5 = SysStringLen(local_98);
          } while (local_8c < UVar5);
        }
        FUN_4081d4fb((int *)&local_a4);
        FUN_40802ec0(&local_dc,(int *)&local_a4);
        if (local_b0 == 0) {
          basic_string<>(local_30,(wchar_t *)local_dc._8_4_);
          local_8._0_1_ = 0x11;
          UVar5 = SysStringLen(local_90);
          if (UVar5 == 0) {
            local_88._4_4_ = (int **)(undefined1 *)0x2f;
            local_7c = (undefined1 *)FUN_40811716(local_30,(wchar_t *)((int)&local_88 + 4),0,1);
            local_88._4_4_ = (int **)(undefined1 *)0x2f;
            uVar12 = FUN_40811c50(local_30,(wchar_t *)((int)&local_88 + 4),0xffffffff,1);
            FUN_40811cd5(local_30,local_48,0,(uint)local_7c);
            local_8._0_1_ = 0x12;
            FUN_40811cd5(local_30,local_60,(uint)(local_7c + 1),(uVar12 - (int)local_7c) - 1);
            local_8._0_1_ = 0x13;
            FUN_40811cd5(local_30,local_78,uVar12 + 1,local_20 - uVar12);
            local_8._0_1_ = 0x14;
            ppppwVar11 = local_48;
            if (7 < local_34) {
              ppppwVar11 = (wchar_t ****)local_48[0];
            }
            local_7c = (undefined1 *)__wtol((wchar_t *)ppppwVar11);
            ppppwVar11 = local_60;
            if (7 < local_4c) {
              ppppwVar11 = (wchar_t ****)local_60[0];
            }
            lVar9 = __wtol((wchar_t *)ppppwVar11);
            ppppwVar11 = local_78;
            if (7 < local_64) {
              ppppwVar11 = (wchar_t ****)local_78[0];
            }
            lVar10 = __wtol((wchar_t *)ppppwVar11);
            (**(code **)(*param_1 + 0x30))();
            (**(code **)(*param_1 + 0x38))();
            piStack_148 = param_1;
            (**(code **)(*param_1 + 0x40))();
            piStack_150 = param_1;
            lStack_154 = 0x4080fec1;
            (**(code **)(*param_1 + 0xa8))();
            piStack_158 = param_1;
            lStack_15c = 0x4080fece;
            lStack_154 = lVar9;
            (**(code **)(*param_1 + 0xb0))();
            piStack_160 = param_1;
            lStack_15c = lVar10;
            (**(code **)(*param_1 + 0xb8))();
            FUN_4080653d(local_78,'\x01',0);
            FUN_4080653d(local_60,'\x01',0);
          }
          else {
            basic_string<>(local_48,local_90);
            local_88._4_4_ = &piStack_148;
            local_8._0_1_ = 0x15;
            local_7c = (undefined1 *)0x0;
            local_94 = (BSTR)0x0;
            local_9c = (undefined1 *)0x0;
            piStack_150 = (int *)0x4080ff2a;
            basic_string<>(&piStack_148,(undefined8 *)local_48);
            local_8._0_1_ = 0x16;
            basic_string<>(&piStack_160,(undefined8 *)local_30);
            local_8._0_1_ = 0x15;
            FUN_408103ef((int *)&local_7c,(int *)&local_94,(int *)&local_9c);
            (**(code **)(*param_1 + 0x30))();
            (**(code **)(*param_1 + 0x38))();
LAB_40810115:
            piStack_148 = param_1;
            (**(code **)(*param_1 + 0x40))();
          }
          ppppwVar11 = local_48;
LAB_40810123:
          FUN_4080653d(ppppwVar11,'\x01',0);
        }
        else {
          basic_string<>(local_30,(wchar_t *)local_dc._8_4_);
          local_8._0_1_ = 0x17;
          if (-1 < (int)local_88._4_4_) {
            local_88._4_4_ = (int **)(undefined1 *)0x2f;
            local_88._4_4_ = (int **)FUN_40811716(local_30,(wchar_t *)((int)&local_88 + 4),0,1);
            local_7c = (undefined1 *)0x2f;
            uVar12 = FUN_40811c50(local_30,(wchar_t *)&local_7c,0xffffffff,1);
            FUN_40811cd5(local_30,local_78,0,(uint)local_88._4_4_);
            local_8._0_1_ = 0x18;
            FUN_40811cd5(local_30,local_60,(uint)((int)local_88._4_4_ + 1),
                         (uVar12 - (int)local_88._4_4_) - 1);
            local_8._0_1_ = 0x19;
            FUN_40811cd5(local_30,local_48,uVar12 + 1,local_20 - uVar12);
            ppppwVar11 = local_78;
            if (7 < local_64) {
              ppppwVar11 = (wchar_t ****)local_78[0];
            }
            local_8._0_1_ = 0x1a;
            iVar4 = *param_1;
            __wtol((wchar_t *)ppppwVar11);
            (**(code **)(iVar4 + 0x30))();
            ppppwVar11 = local_60;
            if (7 < local_4c) {
              ppppwVar11 = (wchar_t ****)local_60[0];
            }
            iVar4 = *param_1;
            __wtol((wchar_t *)ppppwVar11);
            (**(code **)(iVar4 + 0x38))();
            ppppwVar11 = local_48;
            if (7 < local_34) {
              ppppwVar11 = (wchar_t ****)local_48[0];
            }
            iVar4 = *param_1;
            piStack_148 = (int *)0x4081005b;
            __wtol((wchar_t *)ppppwVar11);
            piStack_148 = param_1;
            (**(code **)(iVar4 + 0x40))();
            FUN_4080653d(local_48,'\x01',0);
            FUN_4080653d(local_60,'\x01',0);
            ppppwVar11 = local_78;
            goto LAB_40810123;
          }
          UVar5 = SysStringLen(local_90);
          if (UVar5 != 0) {
            basic_string<>(local_48,local_90);
            local_9c = (undefined1 *)&piStack_148;
            local_8._0_1_ = 0x1b;
            local_88._4_4_ = (int **)0x0;
            local_7c = (undefined1 *)0x0;
            local_94 = (BSTR)0x0;
            piStack_150 = (int *)0x408100c7;
            basic_string<>(&piStack_148,(undefined8 *)local_48);
            local_8._0_1_ = 0x1c;
            basic_string<>(&piStack_160,(undefined8 *)local_30);
            local_8._0_1_ = 0x1b;
            FUN_408103ef((int *)((int)&local_88 + 4),(int *)&local_7c,(int *)&local_94);
            (**(code **)(*param_1 + 0x30))();
            (**(code **)(*param_1 + 0x38))();
            goto LAB_40810115;
          }
        }
        FUN_4080653d(local_30,'\x01',0);
        SysFreeString(local_a4);
        SysFreeString(local_98);
      }
      pcVar13 = VariantClear_exref;
      local_8._0_1_ = 0xc;
      VariantClear((VARIANTARG *)&local_dc.n2);
      uVar2 = (undefined1)local_8;
    }
  }
  local_8._0_1_ = uVar2;
  (**(code **)(*local_a0 + 0x80))();
  local_8._0_1_ = 0xb;
  if (local_ac != (int *)0x0) {
    (**(code **)(*local_ac + 8))();
  }
  (*pcVar13)();
  local_8._0_1_ = 9;
  if (local_c8 != (int *)0x0) {
    (**(code **)(*local_c8 + 8))();
  }
  local_8._0_1_ = 8;
  if (local_a0 != (int *)0x0) {
    (**(code **)(*local_a0 + 8))();
  }
  (*pcVar13)();
  SysFreeString(local_bc);
  FUN_40803143((int *)&local_b8);
  FUN_40803143((int *)local_c0);
  FUN_40803143(&local_b4);
LAB_408102d5:
  SysFreeString(local_90);
  SysFreeString(local_a8);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  FUN_408103e7();
  return;
}



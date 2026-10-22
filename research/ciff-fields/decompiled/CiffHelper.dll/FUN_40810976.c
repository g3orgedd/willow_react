// Source: CiffHelper.dll @ 40810976; FUN_40810976

/* WARNING: Function: __EH_prolog3_catch_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_40810976(void *this,int *param_1)

{
  longlong lVar1;
  BSTR bstrString;
  undefined1 uVar2;
  UINT UVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *****_Memory;
  wchar_t *_Dst;
  uint uVar6;
  undefined4 *****pppppuVar7;
  undefined4 *****pppppuVar8;
  undefined4 *****pppppuVar9;
  code *pcVar10;
  undefined4 uVar11;
  int iVar12;
  code *pcVar13;
  code *pcVar14;
  bool bVar15;
  int local_c4;
  _union_2683 local_c0;
  OLECHAR *local_b0;
  int *local_ac;
  BSTR local_a8;
  int local_a4;
  int *local_a0;
  size_t local_9c;
  int local_98 [3];
  void *local_8c;
  BSTR local_88;
  undefined4 local_84;
  size_t local_80;
  BSTR local_7c;
  uint local_78;
  BSTR local_74;
  BSTR local_70;
  undefined1 local_6c [12];
  undefined4 ****local_60 [5];
  uint local_4c;
  undefined4 ****local_48 [2];
  _union_2683 local_40;
  undefined4 ****local_30 [2];
  undefined4 local_28;
  undefined4 uStack_24;
  int local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  pcVar13 = SysStringLen_exref;
  uStack_4 = 0xb8;
  local_8 = 0;
  local_7c = (BSTR)0x0;
  local_98[1] = 0;
  bVar15 = false;
  local_8c = this;
  if (*(int *)((int)this + 0x74) != 0) {
    UVar3 = SysStringLen(*(BSTR *)((int)this + 0x74));
    bVar15 = UVar3 != 0;
  }
  if (bVar15) {
    local_88 = (BSTR)0x0;
    local_8._0_1_ = 3;
    (**(code **)(*param_1 + 0x68))(param_1,&local_88);
    UVar3 = SysStringLen(local_88);
    if (UVar3 == 0) {
      SysFreeString(local_88);
LAB_408109f7:
      FUN_40802ea3(local_98 + 1);
      local_8 = 0xffffffff;
      if (param_1 != (int *)0x0) {
        (**(code **)(*param_1 + 8))(param_1);
      }
      FUN_4081102f();
      return;
    }
    FUN_408030e3(&local_70,*(LPCWSTR *)((int)this + 0x74));
    local_8._0_1_ = 4;
    FUN_408030e3(&local_80,local_88);
    local_8._0_1_ = 5;
    FUN_4080aa73((void *)((int)this + 0x8c),&local_b0,(LPCWSTR)&local_80,&local_70);
    local_8._0_1_ = 6;
    FUN_40802e40(&local_a8,local_b0);
    local_74 = (BSTR)0x0;
    local_8._0_1_ = 8;
    iVar4 = FUN_4080f725((void *)((int)this + 0x28),(BSTR)&local_a8,(int)&local_74);
    if ((iVar4 < 0) || (local_74 == (BSTR)0x0)) {
      local_8._0_1_ = 7;
      if (local_74 != (BSTR)0x0) {
        (**(code **)(*(int *)local_74 + 8))(local_74);
      }
      SysFreeString(local_a8);
      FUN_40803143((int *)&local_b0);
      FUN_40803143((int *)&local_80);
      FUN_40803143((int *)&local_70);
      SysFreeString(local_88);
      goto LAB_408109f7;
    }
    local_8._0_1_ = 9;
    local_a0 = (int *)0x0;
    iVar4 = (**(code **)(*(int *)local_74 + 0x54))(local_74,&local_a0);
    local_28 = CONCAT22(local_28._2_2_,3);
    local_20 = 0;
    local_8._0_1_ = 10;
    uVar2 = (undefined1)local_8;
    local_8._0_1_ = 10;
    local_ac = (int *)0x0;
    pcVar10 = VariantClear_exref;
    pcVar14 = SysFreeString_exref;
    if (-1 < iVar4) {
      if (local_a0 != (int *)0x0) {
        iVar4 = (**(code **)(*local_a0 + 0x28))(local_a0,local_28,uStack_24,0,local_1c,&local_ac);
        pcVar13 = SysStringLen_exref;
      }
      pcVar10 = VariantClear_exref;
      pcVar14 = SysFreeString_exref;
      uVar2 = (undefined1)local_8;
      if ((-1 < iVar4) && (local_ac != (int *)0x0)) {
        FUN_40802e76((uint *)&local_c0);
        local_9c = 0;
        local_8._0_1_ = 0xc;
        (**(code **)(*local_ac + 0x34))(local_ac,&local_c0);
        FUN_4080ebb9((int)local_6c);
        local_a4 = 0;
        local_8._0_1_ = 0xe;
        FUN_40811358((VARIANTARG *)&local_c0.n2,&local_a4);
        local_40.n2.vt = 0;
        FUN_40802ec0(&local_40,&local_a4);
        local_8._0_1_ = 0xf;
        FUN_4080f8db(&local_c0,(VARIANTARG *)&local_40.n2);
        pcVar10 = VariantClear_exref;
        VariantClear((VARIANTARG *)&local_40.n2);
        local_84 = 0;
        local_78 = 0;
        local_8 = CONCAT31(local_8._1_3_,0x10);
        (**(code **)(*param_1 + 0xec))(param_1,&local_78);
        local_98[2] = 0;
        (**(code **)(*param_1 + 0xf4))(param_1,local_98 + 2);
        if ((local_78 == 0) && (local_98[2] == 0)) {
          if (local_c0.n2.vt == 1) {
            FUN_40803e5b(&local_84,(int *)&local_9c);
          }
          else {
            FUN_40803e97(&local_84,(OLECHAR *)local_c0._8_4_);
          }
          local_98[0] = 0;
          (**(code **)(*param_1 + 0x9c))(param_1,local_98);
          uVar11 = local_84;
          pcVar14 = SysFreeString_exref;
          if (local_98[0] == 1) {
            uVar5 = (*pcVar13)(local_84);
            local_7c = (BSTR)0x0;
            (**(code **)(*param_1 + 0x94))(param_1,&local_7c);
            pcVar14 = SysFreeString_exref;
            if (local_7c == (BSTR)0x0) {
              (**(code **)(*param_1 + 0x98))(param_1,uVar5);
              pcVar14 = SysFreeString_exref;
            }
          }
        }
        else {
          FUN_40802e40(&local_7c,(OLECHAR *)local_c0._8_4_);
          bstrString = local_7c;
          if (local_98[2] == 0) {
            iVar4 = (*pcVar13)(local_7c);
            local_98[2] = iVar4 - local_78;
          }
          FUN_40803fb4(&local_84,bstrString + local_78,local_98[2]);
          pcVar14 = SysFreeString_exref;
          SysFreeString(bstrString);
          uVar11 = local_84;
        }
        (**(code **)(*param_1 + 0x5c))(param_1,uVar11);
        (**(code **)(*param_1 + 100))(param_1,uVar11);
        (*pcVar14)(uVar11);
        (*pcVar14)(local_a4);
        local_8._0_1_ = 0xc;
        FUN_4080ed48((int)local_6c);
        (*pcVar14)(0);
        local_8._0_1_ = 10;
        VariantClear((VARIANTARG *)&local_c0.n2);
        uVar2 = (undefined1)local_8;
      }
    }
    local_8._0_1_ = uVar2;
    local_7c = (BSTR)(**(code **)(*(int *)local_74 + 0x80))(local_74);
    (*pcVar10)(&local_28);
    local_8._0_1_ = 8;
    if (local_a0 != (int *)0x0) {
      (**(code **)(*local_a0 + 8))(local_a0);
    }
    local_8._0_1_ = 7;
    if (local_74 != (BSTR)0x0) {
      (**(code **)(*(int *)local_74 + 8))(local_74);
    }
    (*pcVar14)(local_a8);
    FUN_40803143((int *)&local_b0);
    FUN_40803143((int *)&local_80);
    FUN_40803143((int *)&local_70);
    local_8._0_1_ = 2;
    (*pcVar14)(local_88);
  }
  else {
    local_70 = (BSTR)0x0;
    local_8._0_1_ = 0x11;
    (**(code **)(*param_1 + 0x58))(param_1,&local_70);
    (**(code **)(*param_1 + 100))(param_1,local_70);
    pcVar14 = SysFreeString_exref;
    local_8._0_1_ = 2;
    SysFreeString(local_70);
  }
  (**(code **)(*param_1 + 0x9c))(param_1,&local_c4);
  if (local_c4 != 1) goto LAB_40810fd7;
  (**(code **)(*param_1 + 0x94))(param_1,&local_78);
  local_74 = (BSTR)0x0;
  local_8._0_1_ = 0x12;
  (**(code **)(*param_1 + 0x60))(param_1,&local_74);
  UVar3 = SysStringLen(local_74);
  if (UVar3 < local_78) {
    (**(code **)(*param_1 + 0xa4))(param_1,&local_70);
    UVar3 = SysStringLen(local_74);
    iVar12 = local_78 - UVar3;
    basic_string<>(local_30,local_74);
    local_8._0_1_ = 0x13;
    lVar1 = (ulonglong)(iVar12 + 1) * 2;
    _Memory = (undefined4 *****)
              FUN_4082c99b(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    iVar4 = 0;
    if (0 < iVar12) {
      do {
        *(undefined2 *)((int)_Memory + iVar4 * 2) = local_70._0_2_;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar12);
    }
    *(undefined2 *)((int)_Memory + iVar4 * 2) = 0;
    (**(code **)(*param_1 + 0xac))(param_1,local_98);
    local_80 = local_78 + 1;
    _Dst = (wchar_t *)
           FUN_4082c99b(-(uint)((int)((ulonglong)local_80 * 2 >> 0x20) != 0) |
                        (uint)((ulonglong)local_80 * 2));
    if (*(int *)((int)local_8c + 0x84) == 0) {
      if (local_98[0] != 0) goto LAB_40810f86;
      pppppuVar9 = local_30;
      pppppuVar8 = _Memory;
      if (7 < local_1c) {
        pppppuVar9 = (undefined4 *****)local_30[0];
      }
LAB_40810f93:
      _swprintf_s(_Dst,local_80,L"%s%s",pppppuVar9,pppppuVar8);
    }
    else {
      if (*(int *)((int)local_8c + 0x84) == 1) {
LAB_40810f86:
        pppppuVar9 = _Memory;
        pppppuVar8 = local_30;
        if (7 < local_1c) {
          pppppuVar8 = (undefined4 *****)local_30[0];
        }
        goto LAB_40810f93;
      }
      local_9c = local_78 + 1;
      uVar6 = (int)(local_78 - local_20) / 2;
      local_8c = (void *)(((local_78 - local_20) - uVar6) + -1);
      basic_string<>(local_60,uVar6,(wchar_t)local_70);
      local_8._0_1_ = 0x14;
      basic_string<>(local_48,(uint)local_8c,(wchar_t)local_70);
      pppppuVar9 = local_48;
      if (7 < (uint)local_40._12_4_) {
        pppppuVar9 = (undefined4 *****)local_48[0];
      }
      pppppuVar8 = local_30;
      if (7 < local_1c) {
        pppppuVar8 = (undefined4 *****)local_30[0];
      }
      pppppuVar7 = local_60;
      if (7 < local_4c) {
        pppppuVar7 = (undefined4 *****)local_60[0];
      }
      _swprintf_s(_Dst,local_9c,L"%s%s%s",pppppuVar7,pppppuVar8,pppppuVar9);
      FUN_4080653d(local_48,'\x01',0);
      local_8._0_1_ = 0x13;
      FUN_4080653d(local_60,'\x01',0);
    }
    (**(code **)(*param_1 + 0x5c))(param_1,_Dst);
    (**(code **)(*param_1 + 100))(param_1,_Dst);
    FID_conflict__free(_Dst);
    FID_conflict__free(_Memory);
    FUN_4080653d(local_30,'\x01',0);
  }
  (*pcVar14)(local_74);
LAB_40810fd7:
  FUN_40802ea3(local_98 + 1);
  local_8 = 0xffffffff;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  FUN_4081102f();
  return;
}



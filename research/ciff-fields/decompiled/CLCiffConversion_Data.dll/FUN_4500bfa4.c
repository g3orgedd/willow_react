// Source: CLCiffConversion_Data.dll @ 4500bfa4; FUN_4500bfa4

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_4500bfa4(void *this,int *param_1,int param_2)

{
  int iVar1;
  BSTR pOVar2;
  bool bVar3;
  UINT UVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  wchar_t *pwVar8;
  wchar_t *pwVar9;
  OLECHAR *pOVar10;
  HRESULT HVar11;
  code *pcVar12;
  _union_2683 *p_Var13;
  uint local_1a8 [2];
  undefined4 *local_1a0;
  int local_198;
  int local_194;
  int local_190;
  int *local_18c;
  int *local_188;
  int local_184;
  int local_180;
  OLECHAR *local_17c;
  BSTR local_178;
  _union_2683 *local_174;
  LPCWSTR local_170;
  LPCWSTR local_16c;
  LPCWSTR local_168;
  BSTR local_164;
  wchar_t *local_160;
  wchar_t local_15c [128];
  WCHAR local_5c [4];
  _union_2683 local_54;
  wchar_t local_44 [4];
  _union_2683 local_3c;
  undefined4 local_2c;
  _union_2683 local_24;
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x198;
  local_8 = 0xb3;
  uStack_7 = 0x4500bf;
  local_190 = param_2;
  local_18c = param_1;
  local_17c = (OLECHAR *)0x0;
  local_178 = this;
  (**(code **)(**(int **)(param_2 + 4) + 100))(*(int **)(param_2 + 4),&local_194);
  (**(code **)(*(int *)*param_1 + 0x28))((int *)*param_1,&local_198);
  if (local_198 == 2) {
    local_174 = (_union_2683 *)0x0;
    local_16c = (LPCWSTR)0x0;
    local_164 = (BSTR)0x0;
    local_8 = 2;
    uStack_7 = 0;
    (**(code **)(*(int *)*param_1 + 0x70))((int *)*param_1,&local_174);
    (**(code **)(*(int *)*param_1 + 0x68))((int *)*param_1,&local_16c);
    local_17c = (OLECHAR *)FUN_45010317(this,(BSTR)&local_174);
    pcVar12 = SysFreeString_exref;
    if (-1 < (int)local_17c) {
      (**(code **)(*(int *)*param_1 + 0x74))((int *)*param_1,local_174);
      FUN_450020a5(&local_180,local_16c);
      local_8 = 3;
      UVar4 = SysStringLen(local_16c);
      if (UVar4 != 0) {
        FUN_450020a5(&local_17c,local_16c);
        local_8 = 4;
        FUN_45002050(&local_168,"\'");
        local_8 = 5;
        puVar5 = FUN_450020a5(&local_178,*(LPCWSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this)
                             );
        local_8 = 6;
        FUN_450035a3(&local_168,*(int *)((int)*puVar5 + -8),(void *)*puVar5);
        local_8 = 5;
        FUN_45002256((int *)&local_178);
        FUN_4500af7f(&local_168,L"\'");
        if ((DAT_450538fc & 1) == 0) {
          DAT_450538fc = DAT_450538fc | 1;
          local_8 = 7;
          FUN_45002050(&DAT_450538f8,"##PRODUCTCODE##");
          FUN_4502386d(&LAB_4503ca40);
          local_8 = 5;
        }
        FUN_45011476(&local_17c,DAT_450538f8,local_168);
        FUN_4500af7f(&local_17c,L";");
        piVar6 = FUN_45001f5d(&local_178,local_17c);
        FUN_450058c3(&local_16c,piVar6);
        SysFreeString(local_178);
        FUN_45002256((int *)&local_168);
        local_8 = 3;
        FUN_45002256((int *)&local_17c);
      }
      local_17c = (OLECHAR *)
                  FUN_4500b5ff((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),&local_174,0);
      if (-1 < (int)local_17c) {
        local_17c = (OLECHAR *)
                    FUN_4500ef54((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),
                                 (BSTR)&local_16c,&local_164);
        if ((local_17c == (OLECHAR *)0x0) || (*(int *)(local_180 + -8) == 0)) {
LAB_4500c348:
          FUN_45013800(&local_164);
          UVar4 = SysStringLen(local_164);
          if (UVar4 == 0) {
            bVar3 = FUN_450023b0((void *)((int)this + *(int *)(*(int *)this + 4) + 0xe0),
                                 L"Print Preview");
            if (bVar3) {
              piVar6 = FUN_4500fe88(param_1,&local_190);
              FUN_450058c3(&local_164,piVar6);
              iVar7 = local_190;
              goto LAB_4500c6f4;
            }
          }
          else {
            local_168 = (LPCWSTR)0x0;
            local_188 = (int *)0x0;
            (**(code **)(*(int *)*param_1 + 0x9c))((int *)*param_1,&local_188);
            if (local_194 == 2) {
              local_168 = (LPCWSTR)SysStringLen(local_164);
              (**(code **)(*(int *)*param_1 + 0x98))((int *)*param_1,local_168);
              if ((local_164 != (BSTR)0x0) && (UVar4 = SysStringLen(local_164), UVar4 != 0)) {
                local_160 = local_15c;
                ATL::CW2WEX<128>::Init((CW2WEX<128> *)&local_160,local_164);
                _local_8 = CONCAT31(uStack_7,0xc);
                basic_string<>(local_5c,local_160);
                if (local_160 != local_15c) {
                  FID_conflict__free(local_160);
                }
                local_24._8_4_ = (int *)0x0;
                local_24._12_4_ = 7;
                local_2c = (wchar_t *)((uint)local_2c._2_2_ << 0x10);
                local_8 = 0xf;
                iVar7 = FUN_45009d9a(local_5c,(LPCWSTR)&local_2c);
                if (-1 < iVar7) {
                  basic_string<>(local_44,local_164);
                  piVar6 = (int *)((int)this + *(int *)(*(int *)this + 4) + 0xd4);
                  iVar7 = *piVar6;
                  piVar6 = (int *)FUN_45007e32(piVar6,&local_194,local_44);
                  iVar1 = *piVar6;
                  FUN_450046d9(local_44,'\x01',0);
                  param_1 = local_18c;
                  pcVar12 = SysFreeString_exref;
                  if (iVar1 == iVar7) {
                    basic_string<>(local_44,local_164);
                    local_160 = local_15c;
                    local_8 = 0x10;
                    pwVar8 = (wchar_t *)&local_2c;
                    if (7 < (uint)local_24._12_4_) {
                      pwVar8 = local_2c;
                    }
                    ATL::CW2WEX<128>::Init((CW2WEX<128> *)&local_160,pwVar8);
                    pwVar8 = local_160;
                    local_8 = 0x11;
                    pwVar9 = FUN_45008a59((void *)((int)this + *(int *)(*(int *)this + 4) + 0xd4),
                                          local_44);
                    FID_conflict_assign(pwVar9,pwVar8);
                    if (local_160 != local_15c) {
                      FID_conflict__free(local_160);
                    }
                    FUN_450046d9(local_44,'\x01',0);
                    param_1 = local_18c;
                    pcVar12 = SysFreeString_exref;
                  }
                }
                FUN_450046d9(&local_2c,'\x01',0);
                FUN_450046d9(local_5c,'\x01',0);
              }
            }
            else {
              (**(code **)(*(int *)*param_1 + 0x94))((int *)*param_1,&local_168);
            }
            local_184 = 0;
            local_8 = 0x12;
            iVar7 = FUN_45003d41(param_1,(int *)&local_164,&local_184);
            if (-1 < iVar7) {
              FUN_450022ea(&local_164,&local_184);
            }
            if ((local_168 != (LPCWSTR)0x0) && (UVar4 = SysStringLen(local_164), UVar4 != 0)) {
              basic_string<>(&local_2c,local_164);
              local_8 = 0x13;
              pOVar10 = FUN_45014419(&local_2c,local_44,0,(uint)local_168);
              local_8 = 0x14;
              if (7 < *(uint *)(pOVar10 + 10)) {
                pOVar10 = *(OLECHAR **)pOVar10;
              }
              FUN_45002326(&local_164,pOVar10);
              FUN_450046d9(local_44,'\x01',0);
              if (local_188 == (int *)0x1) {
                CComQIPtr<>(&local_170,*(undefined4 **)(local_190 + 4));
                local_18c = (int *)0x0;
                _local_8 = CONCAT31(uStack_7,0x15);
                (**(code **)(*(int *)local_170 + 0x124))(local_170,&local_18c);
                if (local_18c == (int *)0x2) {
                  local_178 = (BSTR)0x0;
                  if (local_170 != (LPCWSTR)0x0) {
                    (**(code **)(*(int *)local_170 + 0x140))(local_170,&local_178);
                    FUN_450106d9(param_1,(int)local_178,(int)local_168,(int *)&local_164);
                  }
                }
                else {
                  FUN_4501056d(param_1,(int)local_168,&local_164);
                }
                local_8 = 0x13;
                if (local_170 != (LPCWSTR)0x0) {
                  (**(code **)(*(int *)local_170 + 8))(local_170);
                }
              }
              FUN_450046d9(&local_2c,'\x01',0);
            }
            local_8 = 3;
            iVar7 = local_184;
LAB_4500c6f4:
            (*pcVar12)(iVar7);
          }
          FUN_4500e3e3(param_1,&local_164);
          *(undefined1 *)((int)this + 4) = 1;
        }
        else {
          FUN_4500201a(&local_168,&local_180);
          local_8 = 8;
          FUN_450020a5(&local_170,L"");
          local_8 = 9;
          puVar5 = FUN_450020a5(&local_178,
                                *(LPCWSTR *)(*(int *)(*(int *)this + 4) + 0x58 + (int)this));
          local_8 = 10;
          FUN_450035a3(&local_170,*(int *)((int)*puVar5 + -8),(void *)*puVar5);
          local_8 = 9;
          FUN_45002256((int *)&local_178);
          if ((DAT_450538fc & 2) == 0) {
            DAT_450538fc = DAT_450538fc | 2;
            local_8 = 0xb;
            FUN_45002050(&DAT_45053900,"##PRODUCTCODE##");
            FUN_4502386d(&LAB_4503ca18);
            local_8 = 9;
          }
          FUN_45011476(&local_168,DAT_45053900,local_170);
          FUN_4500af7f(&local_168,L";");
          piVar6 = FUN_45001f5d(&local_178,local_168);
          FUN_450058c3(&local_16c,piVar6);
          SysFreeString(local_178);
          local_17c = (OLECHAR *)
                      FUN_4500ef54((void *)((int)this + *(int *)(*(int *)this + 4) + 0xc),
                                   (BSTR)&local_16c,&local_164);
          if (-1 < (int)local_17c) {
            if (local_17c != (OLECHAR *)0x1) {
              FUN_45002256((int *)&local_170);
              local_8 = 3;
              FUN_45002256((int *)&local_168);
              goto LAB_4500c348;
            }
            local_17c = (OLECHAR *)0x80004005;
          }
          FUN_45002256((int *)&local_170);
          FUN_45002256((int *)&local_168);
        }
      }
      FUN_45002256(&local_180);
    }
    (*pcVar12)(local_164);
    (*pcVar12)(local_16c);
    p_Var13 = local_174;
LAB_4500c965:
    (*pcVar12)(p_Var13);
  }
  else {
    if (local_198 == 1) {
      *(undefined1 *)((int)this + 4) = 1;
      goto LAB_4500cb5a;
    }
    iVar7 = FUN_4500fc6d(param_1);
    if (iVar7 != 9) {
      if ((local_194 == 2) && ((iVar7 == 0 || (iVar7 == 8)))) {
        local_16c = (BSTR)0x0;
        local_8 = 0x1e;
        uStack_7 = 0;
        local_17c = (OLECHAR *)(**(code **)(*(int *)*param_1 + 0x58))((int *)*param_1,&local_16c);
        if ((-1 < (int)local_17c) &&
           ((local_16c != (BSTR)0x0 && (UVar4 = SysStringLen(local_16c), UVar4 != 0)))) {
          local_160 = local_15c;
          ATL::CW2WEX<128>::Init((CW2WEX<128> *)&local_160,local_16c);
          _local_8 = CONCAT31(uStack_7,0x1f);
          basic_string<>(local_5c,local_160);
          if (local_160 != local_15c) {
            FID_conflict__free(local_160);
          }
          local_24._12_4_ = 7;
          local_24._8_4_ = (int *)0x0;
          local_2c = (wchar_t *)((uint)local_2c._2_2_ << 0x10);
          local_8 = 0x22;
          iVar7 = FUN_45009d9a(local_5c,(LPCWSTR)&local_2c);
          if (-1 < iVar7) {
            basic_string<>(local_44,local_16c);
            piVar6 = (int *)((int)this + *(int *)(*(int *)this + 4) + 0xd4);
            iVar7 = *piVar6;
            piVar6 = (int *)FUN_45007e32(piVar6,&local_190,local_44);
            iVar1 = *piVar6;
            FUN_450046d9(local_44,'\x01',0);
            if (iVar1 == iVar7) {
              basic_string<>(local_44,local_16c);
              local_160 = local_15c;
              local_8 = 0x23;
              pwVar8 = (wchar_t *)&local_2c;
              if (7 < (uint)local_24._12_4_) {
                pwVar8 = local_2c;
              }
              ATL::CW2WEX<128>::Init((CW2WEX<128> *)&local_160,pwVar8);
              pwVar8 = local_160;
              local_8 = 0x24;
              pwVar9 = FUN_45008a59((void *)((int)this + *(int *)(*(int *)this + 4) + 0xd4),local_44
                                   );
              FID_conflict_assign(pwVar9,pwVar8);
              if (local_160 != local_15c) {
                FID_conflict__free(local_160);
              }
              FUN_450046d9(local_44,'\x01',0);
            }
          }
          FUN_450046d9(&local_2c,'\x01',0);
          FUN_450046d9(local_5c,'\x01',0);
        }
        SysFreeString(local_16c);
      }
      goto LAB_4500cb5a;
    }
    FUN_45001f8d((uint *)&local_54);
    local_8 = 0x16;
    uStack_7 = 0;
    puVar5 = *(undefined4 **)(*(int *)(*(int *)this + 4) + 0x34 + (int)this);
    if (puVar5 != (undefined4 *)0x0) {
      CComQIPtr<>(&local_168,puVar5);
      local_8 = 0x17;
      if ((local_168 != (LPCWSTR)0x0) &&
         ((**(code **)(*(int *)local_168 + 0xb4))(local_168,&local_54), local_54.n2.vt != 0)) {
        CComQIPtr<>(&local_170,(undefined4 *)local_54._8_4_);
        local_8 = 0x18;
        if (local_170 == (LPCWSTR)0x0) goto LAB_4500c972;
        local_180 = 0;
        (**(code **)(*(int *)local_170 + 0x1c))(local_170,&local_180);
        local_184 = 0;
        pcVar12 = VariantClear_exref;
        if (0 < local_180) {
          do {
            FUN_45001f8d(local_1a8);
            local_184 = local_184 + 1;
            local_8 = 0x19;
            (**(code **)(*(int *)local_170 + 0x30))(local_170,local_184,local_1a8);
            pOVar2 = local_178;
            if (((short)local_1a8[0] != 0) &&
               (CComQIPtr<>(&local_188,local_1a0), local_188 != (int *)0x0)) {
              local_174 = (_union_2683 *)0x0;
              _local_8 = CONCAT31(uStack_7,0x1b);
              HVar11 = CoCreateInstance((IID *)&DAT_4503d9d0,(LPUNKNOWN)0x0,0x17,
                                        (IID *)&DAT_4503eaec,&local_174);
              if ((-1 < HVar11) && (local_174 != (_union_2683 *)0x0)) {
                local_24._8_4_ = *param_1;
                local_24.n2.vt = 9;
                if ((int *)local_24._8_4_ != (int *)0x0) {
                  (**(code **)(*(int *)local_24._8_4_ + 4))(local_24._8_4_);
                }
                local_8 = 0x1c;
                local_3c._8_4_ = *(int *)(*(int *)(*(int *)pOVar2 + 4) + 0x34 + (int)pOVar2);
                local_3c.n2.vt = 9;
                if ((int *)local_3c._8_4_ != (int *)0x0) {
                  (**(code **)(*(int *)local_3c._8_4_ + 4))(local_3c._8_4_);
                }
                _local_8 = CONCAT31(uStack_7,0x1d);
                (**(code **)(*(int *)local_174 + 0x1c))
                          (local_174,&local_24,local_3c._0_4_,local_3c.decVal.Hi32,local_3c._8_4_,
                           local_3c._12_4_);
                pcVar12 = VariantClear_exref;
                VariantClear((VARIANTARG *)&local_3c.n2);
                VariantClear((VARIANTARG *)&local_24.n2);
              }
              local_8 = 0x1a;
              if (local_174 != (_union_2683 *)0x0) {
                (**(code **)(*(int *)local_174 + 8))(local_174);
              }
              local_8 = 0x19;
              if (local_188 != (int *)0x0) {
                (**(code **)(*local_188 + 8))(local_188);
              }
            }
            (*pcVar12)(local_1a8);
          } while (local_184 < local_180);
        }
        local_8 = 0x17;
        if (local_170 != (LPCWSTR)0x0) {
          (**(code **)(*(int *)local_170 + 8))(local_170);
        }
        local_8 = 0x16;
        if (local_168 != (LPCWSTR)0x0) {
          (**(code **)(*(int *)local_168 + 8))(local_168);
        }
        p_Var13 = &local_54;
        goto LAB_4500c965;
      }
LAB_4500c972:
      local_8 = 0x16;
      if (local_168 != (LPCWSTR)0x0) {
        (**(code **)(*(int *)local_168 + 8))(local_168);
      }
    }
    VariantClear((VARIANTARG *)&local_54.n2);
  }
LAB_4500cb5a:
  FUN_45022eb8();
  return;
}



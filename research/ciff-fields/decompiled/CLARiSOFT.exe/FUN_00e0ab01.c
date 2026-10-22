// Source: CLARiSOFT.exe @ 00e0ab01; FUN_00e0ab01

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void __thiscall FUN_00e0ab01(void *this,int *param_1,int *param_2)

{
  BSTR pOVar1;
  int iVar2;
  int iVar3;
  ULONG UVar4;
  UINT UVar5;
  uint uVar6;
  wchar_t *pwVar7;
  int extraout_ECX;
  IID *riid;
  int *piVar8;
  int **ppiVar9;
  wchar_t *pwVar10;
  void **in_stack_fffffd7c;
  void **ppvObject;
  _union_2683 local_274;
  _union_2683 local_264;
  int *local_250;
  void *local_24c;
  void *local_248 [2];
  int local_240;
  BSTR local_23c;
  int *local_238;
  int local_234;
  int *local_230;
  IUnknown *local_22c;
  BSTR local_228;
  int *local_224;
  wchar_t local_220 [12];
  undefined1 local_208 [24];
  undefined1 local_1f0 [32];
  undefined1 local_1d0 [4];
  undefined1 local_1cc [4];
  undefined1 local_1c8 [4];
  undefined1 local_1c4 [8];
  undefined1 local_1bc [4];
  undefined1 local_1b8 [4];
  undefined1 local_1b4 [264];
  undefined1 local_ac [76];
  wchar_t local_60 [8];
  int local_50;
  undefined1 local_40 [8];
  IID local_38;
  undefined1 local_28 [8];
  undefined1 local_20 [24];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x264;
  local_250 = param_2;
  local_8 = 0;
  uStack_7 = 0;
  local_24c = this;
  FUN_00e0d744(param_2);
  if (param_1 != (int *)0x0) {
    local_238 = (int *)0x0;
    local_8 = 3;
    iVar2 = extraout_ECX;
    FUN_00e09bd0(&stack0xfffffd74,(int *)((int)this + 0x20));
    ppiVar9 = &local_238;
    piVar8 = param_1;
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
    }
    iVar2 = FUN_00e0b12b(this,piVar8,(int *)ppiVar9,iVar2);
    if (-1 < iVar2) {
      local_234 = 0;
      iVar2 = (**(code **)(*param_1 + 0x1c))();
      if (-1 < iVar2) {
        local_22c = (IUnknown *)0x0;
        iVar2 = 0;
        if (0 < local_234) {
          do {
            FUN_00e03b51((uint *)&local_264);
            iVar2 = iVar2 + 1;
            local_8 = 5;
            local_240 = iVar2;
            iVar3 = (**(code **)(*param_1 + 0x24))(param_1);
            if ((-1 < iVar3) && (local_264.n2.vt == 9)) {
              if (local_22c != (IUnknown *)local_264._8_4_) {
                ATL::AtlComQIPtrAssign
                          (&local_22c,(IUnknown *)local_264._8_4_,(_GUID *)&DAT_00efcfe8);
              }
              if (local_22c != (IUnknown *)0x0) {
                FUN_00e0a2c1(local_60);
                local_8 = 6;
                (*local_22c->lpVtbl[7].QueryInterface)(local_22c,(IID *)local_40,in_stack_fffffd7c);
                ppvObject = (void **)(local_40 + 4);
                (*local_22c->lpVtbl[5].Release)(local_22c);
                (*local_22c->lpVtbl[5].QueryInterface)(local_22c,&local_38,ppvObject);
                CComQIPtr<>(&local_230,local_22c);
                local_8 = 7;
                if (local_230 != (int *)0x0) {
                  (**(code **)(*local_230 + 0xac))();
                  (**(code **)(*local_230 + 0xb4))(local_230);
                }
                (**(code **)(*param_1 + 0x68))();
                (*local_22c->lpVtbl[7].Release)(local_22c);
                (*local_22c->lpVtbl[8].AddRef)(local_22c);
                local_23c = (BSTR)0x0;
                _local_8 = CONCAT31(uStack_7,8);
                UVar4 = (*local_22c->lpVtbl[4].AddRef)(local_22c);
                if ((-1 < (int)UVar4) &&
                   (UVar5 = SysStringLen(local_23c), pOVar1 = local_23c, UVar5 != 0)) {
                  if (*local_23c == L'\0') {
                    uVar6 = 0;
                  }
                  else {
                    uVar6 = _wcslen(local_23c);
                  }
                  FID_conflict_assign(local_60,(undefined8 *)pOVar1,uVar6);
                }
                in_stack_fffffd7c = local_248;
                local_248[0] = (void *)0x0;
                UVar4 = (*local_22c->lpVtbl[2].AddRef)(local_22c);
                if (-1 < (int)UVar4) {
                  riid = (IID *)0x0;
                  if (0 < (int)local_248[0]) {
                    do {
                      FUN_00e03b51((uint *)&local_274);
                      local_8 = 9;
                      riid = (IID *)((int)&riid->Data1 + 1);
                      UVar4 = (*local_22c->lpVtbl[3].QueryInterface)
                                        (local_22c,riid,(void **)&local_274);
                      if ((-1 < (int)UVar4) && (local_274.n2.vt == 9)) {
                        CComQIPtr<>(&local_224,(undefined4 *)local_274._8_4_);
                        local_8 = 10;
                        if (local_224 != (int *)0x0) {
                          FUN_00e0a076(local_220);
                          local_8 = 0xb;
                          (**(code **)(*local_224 + 0x2c))();
                          (**(code **)(*local_224 + 0x34))(local_224,local_1bc);
                          (**(code **)(*local_224 + 0x80))(local_224,local_1b4);
                          (**(code **)(*local_224 + 0x78))(local_224,local_1b8);
                          (**(code **)(*local_224 + 0x24))(local_224,local_1cc);
                          local_228 = (BSTR)0x0;
                          local_8 = 0xc;
                          iVar2 = (**(code **)(*local_224 + 0x1c))(local_224,&local_228);
                          if ((-1 < iVar2) &&
                             (UVar5 = SysStringLen(local_228), pOVar1 = local_228, UVar5 != 0)) {
                            if (*local_228 == L'\0') {
                              uVar6 = 0;
                            }
                            else {
                              uVar6 = _wcslen(local_228);
                            }
                            FID_conflict_assign(local_220,(undefined8 *)pOVar1,uVar6);
                            FUN_00e0e492(local_20,(undefined8 *)local_220);
                            SysFreeString(local_228);
                            local_228 = (BSTR)0x0;
                          }
                          iVar2 = (**(code **)(*local_224 + 0x68))(local_224,&local_228);
                          if ((-1 < iVar2) &&
                             (UVar5 = SysStringLen(local_228), pOVar1 = local_228, UVar5 != 0)) {
                            if (*local_228 == L'\0') {
                              uVar6 = 0;
                            }
                            else {
                              uVar6 = _wcslen(local_228);
                            }
                            FID_conflict_assign(local_1f0,(undefined8 *)pOVar1,uVar6);
                            SysFreeString(local_228);
                            local_228 = (BSTR)0x0;
                          }
                          iVar2 = (**(code **)(*local_224 + 0xa0))(local_224,&local_228);
                          if ((-1 < iVar2) &&
                             (UVar5 = SysStringLen(local_228), pOVar1 = local_228, UVar5 != 0)) {
                            if (*local_228 == L'\0') {
                              uVar6 = 0;
                            }
                            else {
                              uVar6 = _wcslen(local_228);
                            }
                            FID_conflict_assign(local_208,(undefined8 *)pOVar1,uVar6);
                            SysFreeString(local_228);
                            local_228 = (BSTR)0x0;
                          }
                          (**(code **)(*local_224 + 0x3c))(local_224,local_1d0);
                          (**(code **)(*local_224 + 0x44))(local_224,local_1c8);
                          (**(code **)(*local_224 + 0x4c))(local_224,local_1c4);
                          UVar4 = (**(code **)(*local_224 + 100))(local_224,local_ac);
                          iVar2 = FUN_00e06bea(local_1f0,L"Price");
                          if (iVar2 == 0) {
                            pwVar10 = local_220;
                            piVar8 = param_1;
                            if (param_1 != (int *)0x0) {
                              (**(code **)(*param_1 + 4))(param_1);
                            }
                            UVar4 = FUN_00e0b72f(piVar8,pwVar10);
                          }
                          if (-1 < (int)UVar4) {
                            pwVar10 = local_220;
                            piVar8 = local_224;
                            if (local_224 != (int *)0x0) {
                              (**(code **)(*local_224 + 4))(local_224);
                            }
                            FUN_00e0ba0c(piVar8,(int)pwVar10);
                            pwVar10 = local_220;
                            pwVar7 = FUN_00e0aa0a(local_28,pwVar10);
                            FUN_00e0a8bc(pwVar7,(undefined8 *)pwVar10);
                          }
                          SysFreeString(local_228);
                          FUN_00e0a516(local_220);
                        }
                        local_8 = 9;
                        if (local_224 != (int *)0x0) {
                          (**(code **)(*local_224 + 8))();
                        }
                      }
                      _local_8 = CONCAT31(uStack_7,8);
                      VariantClear((VARIANTARG *)&local_274.n2);
                    } while ((int)riid < (int)local_248[0]);
                  }
                  iVar2 = local_240;
                  if ((-1 < (int)UVar4) && (local_50 != 0)) {
                    pwVar10 = local_60;
                    pwVar7 = FUN_00e0aa68(local_250,pwVar10);
                    FUN_00e0a8d6(pwVar7,(undefined8 *)pwVar10);
                    iVar2 = local_240;
                  }
                }
                SysFreeString(local_23c);
                local_8 = 6;
                if (local_230 != (int *)0x0) {
                  (**(code **)(*local_230 + 8))();
                }
                FUN_00e0a5e8(local_60);
              }
            }
            VariantClear((VARIANTARG *)&local_264.n2);
          } while (iVar2 < local_234);
        }
        local_8 = 3;
        if (local_22c != (IUnknown *)0x0) {
          (*local_22c->lpVtbl->Release)(local_22c);
        }
      }
    }
    local_8 = 2;
    if (local_238 != (int *)0x0) {
      (**(code **)(*local_238 + 8))();
    }
  }
  _local_8 = CONCAT31(uStack_7,1);
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  FUN_00e0a34f((undefined4 *)&stack0x0000000c);
  FUN_00e0a371((undefined4 *)&stack0x00000014);
  FUN_00ec9e3c();
  return;
}



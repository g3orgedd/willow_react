// Source: CiffHelper.dll @ 40825e11; FUN_40825e11

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_40825e11(void *this,undefined4 *param_1)

{
  undefined4 *this_00;
  void *this_01;
  bool bVar1;
  int iVar2;
  UINT UVar3;
  OLECHAR *pOVar4;
  uint uVar5;
  uint uVar6;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR extraout_ECX_01;
  BSTR extraout_ECX_02;
  BSTR pOVar7;
  BSTR extraout_ECX_03;
  int iVar8;
  int **ppiVar9;
  BSTR *ppOVar10;
  _union_2683 local_40;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  BSTR local_1c;
  BSTR local_18;
  int *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x40825e1d;
  local_28 = 0;
  iVar2 = (**(code **)(*(int *)*param_1 + 0x1c))();
  iVar8 = 0;
  if (0 < local_28) {
    do {
      FUN_40802e76((uint *)&local_40);
      local_8 = 0;
      iVar8 = iVar8 + 1;
      local_2c = iVar8;
      iVar2 = (**(code **)(*(int *)*param_1 + 0x24))((int *)*param_1);
      if ((-1 < iVar2) && (local_40.n2.vt == 9)) {
        CComQIPtr<>(local_14,(undefined4 *)local_40._8_4_);
        local_8._0_1_ = 1;
        if (local_14[0] == (int *)0x0) {
          iVar2 = -0x7fffbffb;
        }
        else {
          this_00 = (undefined4 *)((int)this + 0x10);
          SysFreeString((BSTR)*this_00);
          *this_00 = 0;
          iVar2 = (**(code **)(*local_14[0] + 0x4c))();
          if (-1 < iVar2) {
            pOVar7 = extraout_ECX;
            if (((*(int *)((int)this + 8) < 5) &&
                (UVar3 = SysStringLen((BSTR)*this_00), pOVar7 = extraout_ECX_00, UVar3 != 0)) &&
               (pOVar4 = (OLECHAR *)FUN_40823639(0x4084d630,(wchar_t *)*this_00,0,2),
               pOVar7 = extraout_ECX_01, pOVar4 != (OLECHAR *)0x0)) {
              FUN_40803e97(this_00,pOVar4);
              iVar2 = (**(code **)(*local_14[0] + 0x50))();
              pOVar7 = extraout_ECX_02;
            }
            if (*(int *)((int)this + 8) < 7) {
              ppiVar9 = local_14;
              FUN_40803baf(&stack0xffffffa0,(int *)((int)this + 0xc));
              iVar2 = FUN_40825d35(pOVar7,ppiVar9);
            }
            if (*(int *)((int)this + 8) < 0x14) {
              if (-1 < iVar2) {
                UVar3 = SysStringLen((BSTR)*this_00);
                if ((UVar3 != 0) &&
                   (pOVar4 = (OLECHAR *)FUN_40823639(0x4084d648,(wchar_t *)*this_00,0,3),
                   pOVar4 != (OLECHAR *)0x0)) {
                  FUN_40803e97(this_00,pOVar4);
                  iVar2 = (**(code **)(*local_14[0] + 0x50))();
                  CComQIPtr<>(&local_20,local_14[0]);
                  local_8._0_1_ = 2;
                  if ((-1 < iVar2) && (local_20 != (int *)0x0)) {
                    iVar2 = (**(code **)(*local_20 + 0xd0))();
                  }
                  local_8._0_1_ = 1;
                  if (local_20 != (int *)0x0) {
                    (**(code **)(*local_20 + 8))();
                  }
                }
                goto LAB_40825f89;
              }
            }
            else {
LAB_40825f89:
              if ((-1 < iVar2) && (*(int *)((int)this + 8) < 0x15)) {
                local_1c = (BSTR)0x0;
                local_18 = (BSTR)0x0;
                uVar5 = (**(code **)(*local_14[0] + 100))();
                uVar6 = (**(code **)(*local_14[0] + 0x5c))(local_14[0],&local_18);
                if ((-1 < (int)(uVar5 | uVar6)) &&
                   (bVar1 = FUN_40803ed6((void *)((int)this + 0xc),L"Laser - 7510"), bVar1)) {
                  bVar1 = FUN_40803ed6(this_00,L"CP-10 YbY F163 D46a");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x46fe) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x3783) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"CP-10 YbY F254 D52a");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x6894) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x5692) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"CP-10 YbY F420 D60");
                  if (bVar1) {
                    if (local_1c == (BSTR)0xc2ab) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x8f20) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                }
                this_01 = (void *)((int)this + 0xc);
                bVar1 = FUN_40803ed6(this_01,L"Laser - 3020");
                if ((((bVar1) || (bVar1 = FUN_40803ed6(this_01,L"Laser - 3030"), bVar1)) ||
                    (bVar1 = FUN_40803ed6(this_01,L"Laser - SL1"), bVar1)) &&
                   ((bVar1 = FUN_40803ed6(this_00,L"ICE-H10 CO2 F200 D36"), bVar1 &&
                    (local_1c == (BSTR)0x3150)))) {
                  (**(code **)(*local_14[0] + 0x68))();
                }
                bVar1 = FUN_40803ed6(this_01,L"Laser - 3120");
                if (((bVar1) || (bVar1 = FUN_40803ed6(this_01,L"Laser - 3130"), bVar1)) ||
                   ((bVar1 = FUN_40803ed6(this_01,L"Laser - 3320"), bVar1 ||
                    (((bVar1 = FUN_40803ed6(this_01,L"Laser - 3330"), bVar1 ||
                      (bVar1 = FUN_40803ed6(this_01,L"Laser - SL102"), bVar1)) ||
                     (bVar1 = FUN_40803ed6(this_01,L"Laser - SL302"), bVar1)))))) {
                  bVar1 = FUN_40803ed6(this_00,L"SHC 60 CO2 F64 D36");
                  if ((bVar1) && (local_1c == (BSTR)0x172b)) {
                    (**(code **)(*local_14[0] + 0x68))();
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 60 CO2 F127 D36");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x2dfd) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x2352) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 60 CO2 F190 D36");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x44cf) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x34d6) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 60 CO2 F254 D36");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x5bfa) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x4698) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 100 CO2 F63.5 D50");
                  if (bVar1) {
                    if (local_1c == (BSTR)0xefb) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0xc0e) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 100 CO2 F85 D50");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x1875) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x1268) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 100 CO2 F100 D48");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x2cf2) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x1f4e) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 100 CO2 F200 D48");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x4ee1) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x390d) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 100 CO2 F300 D48");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x86ca) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x5de9) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 100 CO2 F351 D48");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x9db5) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x6de3) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 100 CO2 F400 D48");
                  if (bVar1) {
                    if (local_1c == (BSTR)0xb4a1) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x7ddc) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 120 CO2 F100 D48");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x2add) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x1dab) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 120 CO2 F150 D48");
                  if ((bVar1) && (local_18 == (BSTR)0x2c8d)) {
                    (**(code **)(*local_14[0] + 0x60))();
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 120 CO2 F200 D48");
                  if (bVar1) {
                    if (local_1c == (BSTR)0x55ba) {
                      (**(code **)(*local_14[0] + 0x68))();
                    }
                    if (local_18 == (BSTR)0x3b62) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 120 CO2 F351 D48");
                  if ((bVar1) && (local_18 == (BSTR)0x683b)) {
                    (**(code **)(*local_14[0] + 0x60))();
                  }
                  bVar1 = FUN_40803ed6(this_00,L"SHC 120 CO2 F400 D48");
                  if ((bVar1) && (local_18 == (BSTR)0x775c)) {
                    (**(code **)(*local_14[0] + 0x60))();
                  }
                  bVar1 = FUN_40803ed6(this_01,L"Laser - 7210");
                  if ((bVar1) || (bVar1 = FUN_40803ed6(this_01,L"Laser - 7310"), bVar1)) {
                    bVar1 = FUN_40803ed6(this_00,L"SHF60A Yb F50 D36");
                    if (bVar1) {
                      if (local_1c == (BSTR)0xa2c) {
                        (**(code **)(*local_14[0] + 0x68))();
                      }
                      if (local_18 == (BSTR)0x7a4) {
                        (**(code **)(*local_14[0] + 0x60))();
                      }
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SHF60A Yb F100 D36");
                    if (bVar1) {
                      if (local_1c == (BSTR)0x246a) {
                        (**(code **)(*local_14[0] + 0x68))();
                      }
                      if (local_18 == (BSTR)0x1bfb) {
                        (**(code **)(*local_14[0] + 0x60))();
                      }
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SHF100A Yb F100 D29");
                    if ((bVar1) && (local_18 == (BSTR)0x1d9e)) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SHF100A Yb F163 D46");
                    if (bVar1) {
                      if (local_1c == (BSTR)0x59f1) {
                        (**(code **)(*local_14[0] + 0x68))();
                      }
                      if (local_18 == (BSTR)0x3b3c) {
                        (**(code **)(*local_14[0] + 0x60))();
                      }
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SHF100A Yb F254 D52");
                    if ((bVar1) && (local_18 == (BSTR)0x543d)) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SHF100A Yb F420 D60");
                    if (bVar1) {
                      if (local_1c == (BSTR)0xfb92) {
                        (**(code **)(*local_14[0] + 0x68))();
                      }
                      if (local_18 == (BSTR)0x8d30) {
                        (**(code **)(*local_14[0] + 0x60))();
                      }
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SS-10 YbR F160 D35");
                    if (bVar1) {
                      if (local_1c == (BSTR)0x6f79) {
                        (**(code **)(*local_14[0] + 0x68))();
                      }
                      if (local_18 == (BSTR)0x3d38) {
                        (**(code **)(*local_14[0] + 0x60))();
                      }
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SS-10 YbR F163 D46");
                    if (bVar1) {
                      if (local_1c == (BSTR)0x5692) {
                        (**(code **)(*local_14[0] + 0x68))();
                      }
                      if (local_18 == (BSTR)0x37e9) {
                        (**(code **)(*local_14[0] + 0x60))();
                      }
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SS-10 YbR F254 D51");
                    if ((bVar1) && (local_18 == (BSTR)0x5828)) {
                      (**(code **)(*local_14[0] + 0x60))();
                    }
                    bVar1 = FUN_40803ed6(this_00,L"SS-10 YbR F420 D60");
                    if (bVar1) {
                      if (local_1c == (BSTR)0xc572) {
                        (**(code **)(*local_14[0] + 0x68))();
                      }
                      if (local_18 == (BSTR)0x8a9c) {
                        (**(code **)(*local_14[0] + 0x60))();
                      }
                    }
                  }
                }
              }
            }
            iVar2 = FUN_408253b1(this,(int *)local_14);
          }
          CComQIPtr<>(&local_24,local_14[0]);
          if (local_24 != (int *)0x0) {
            local_18 = (BSTR)0x0;
            local_8._0_1_ = 4;
            iVar2 = (**(code **)(*local_24 + 0x9c))();
            if ((-1 < iVar2) && (UVar3 = SysStringLen(local_18), UVar3 != 0)) {
              local_1c = (BSTR)0x0;
              ppOVar10 = &local_1c;
              local_8._0_1_ = 5;
              pOVar7 = extraout_ECX_03;
              FUN_40803baf(&stack0xffffffa0,(int *)&local_18);
              iVar2 = FUN_40823bfb(this,pOVar7,ppOVar10);
              if ((-1 < iVar2) && (UVar3 = SysStringLen(local_1c), UVar3 != 0)) {
                iVar2 = (**(code **)(*local_24 + 0xa0))();
              }
              SysFreeString(local_1c);
            }
            SysFreeString(local_18);
          }
          local_8._0_1_ = 1;
          iVar8 = local_2c;
          if (local_24 != (int *)0x0) {
            (**(code **)(*local_24 + 8))();
            iVar8 = local_2c;
          }
        }
        local_8 = (uint)local_8._1_3_ << 8;
        if (local_14[0] != (int *)0x0) {
          (**(code **)(*local_14[0] + 8))();
        }
      }
      local_8 = 0xffffffff;
      VariantClear((VARIANTARG *)&local_40.n2);
    } while (iVar8 < local_28);
  }
  return iVar2;
}



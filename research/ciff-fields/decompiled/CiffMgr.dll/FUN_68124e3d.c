// Source: CiffMgr.dll @ 68124e3d; FUN_68124e3d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_68124e3d(void *this,int *param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  short *psVar4;
  OLECHAR *psz;
  wchar_t *pwVar5;
  char cVar6;
  int iVar7;
  _union_2683 local_34;
  float local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar2 = param_4;
  piVar1 = param_2;
  uStack_4 = 0x24;
  local_8 = 0x68124e49;
  iVar7 = 0;
  cVar6 = (char)param_4;
  local_14 = this;
  if (((uint)param_4 & 1) != 0) {
    param_4 = (int *)0x0;
    local_8 = 0;
    iVar7 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3);
    if ((-1 < iVar7) && (param_4 != (int *)0x0)) {
      FUN_68132710((uint *)&local_34,0,0x10);
      VariantInit((VARIANTARG *)&local_34.n2);
      local_34._8_4_ = (BSTR)0x0;
      local_34.n2.vt = 8;
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar7 = (**(code **)(*(int *)*piVar1 + 0xf8))((int *)*piVar1);
      if (-1 < iVar7) {
        iVar7 = FUN_681021f5(param_1,&param_4,PTR_u_ParentField_68160088,(undefined4 *)&local_34);
      }
      VariantClear((VARIANTARG *)&local_34.n2);
    }
    local_8 = 0xffffffff;
    if (param_4 != (int *)0x0) {
      (**(code **)(*param_4 + 8))();
    }
    if (iVar7 < 0) {
      return iVar7;
    }
  }
  if (((uint)piVar2 & 2) != 0) {
    iVar7 = (**(code **)(*(int *)*piVar1 + 0x110))((int *)*piVar1);
    if (iVar7 < 0) {
      return iVar7;
    }
    if (param_4 != (int *)0x0) {
      puVar3 = FUN_6812e9d1((int)param_4);
      iVar7 = FUN_6810248f(param_1,param_3,PTR_u_GuardBars_6815fe5c,puVar3);
    }
  }
  if (-1 < iVar7) {
    if (((uint)piVar2 & 4) != 0) {
      iVar7 = (**(code **)(*(int *)*piVar1 + 0x118))((int *)*piVar1);
      if (iVar7 < 0) {
        return iVar7;
      }
      if (param_4 != (int *)0x0) {
        puVar3 = FUN_6812e9d1((int)param_4);
        iVar7 = FUN_6810248f(param_1,param_3,PTR_u_BearerBars_6815fe60,puVar3);
      }
    }
    if (-1 < iVar7) {
      if (((uint)piVar2 & 8) != 0) {
        iVar7 = (**(code **)(*(int *)*piVar1 + 0x120))((int *)*piVar1);
        if (iVar7 < 0) {
          return iVar7;
        }
        if (param_4 != (int *)0x0) {
          puVar3 = FUN_6812e9d1((int)param_4);
          iVar7 = FUN_6810248f(param_1,param_3,PTR_u_BearerBox_6815fe64,puVar3);
        }
      }
      if (-1 < iVar7) {
        if (((uint)piVar2 & 0x10) != 0) {
          iVar7 = (**(code **)(*(int *)*piVar1 + 0x128))((int *)*piVar1);
          if (iVar7 < 0) {
            return iVar7;
          }
          if (param_4 != (int *)0x0) {
            puVar3 = FUN_6812e9d1((int)param_4);
            iVar7 = FUN_6810248f(param_1,param_3,PTR_u_HGauge_6815fe68,puVar3);
          }
        }
        if (-1 < iVar7) {
          if (((uint)piVar2 & 0x20) != 0) {
            iVar7 = (**(code **)(*(int *)*piVar1 + 0xf0))((int *)*piVar1);
            if (iVar7 < 0) {
              return iVar7;
            }
            if (param_4 != (int *)0x205) {
              psVar4 = FUN_6812f174(local_14,(int)param_4);
              iVar7 = FUN_6810248f(param_1,param_3,PTR_u_ThickThinRatio_6815fe6c,psVar4);
            }
          }
          if (-1 < iVar7) {
            if (((uint)piVar2 & 0x40) != 0) {
              iVar7 = (**(code **)(*(int *)*piVar1 + 0x130))((int *)*piVar1);
              if (iVar7 < 0) {
                return iVar7;
              }
              if (param_4 != (int *)0x0) {
                puVar3 = FUN_6812e9d1((int)param_4);
                iVar7 = FUN_6810248f(param_1,param_3,PTR_u_IntelligentEan128_6815fe70,puVar3);
              }
            }
            if (-1 < iVar7) {
              if (cVar6 < '\0') {
                CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                local_8 = 2;
                if (((param_4 != (int *)0x0) &&
                    (iVar7 = (**(code **)(*param_4 + 0x154))(param_4), -1 < iVar7)) &&
                   (param_2 != (int *)0x5)) {
                  psVar4 = FUN_6812f174(local_14,(int)param_2);
                  iVar7 = FUN_6810248f(param_1,param_3,PTR_u_ECCType_6815ff0c,psVar4);
                }
                local_8 = 0xffffffff;
                if (param_4 != (int *)0x0) {
                  (**(code **)(*param_4 + 8))();
                }
              }
              if (-1 < iVar7) {
                if (((uint)piVar2 & 0x100) != 0) {
                  CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                  local_8 = 3;
                  if (((param_4 != (int *)0x0) &&
                      (iVar7 = (**(code **)(*param_4 + 0x15c))(param_4), -1 < iVar7)) &&
                     (param_2 != (int *)0x64)) {
                    psVar4 = FUN_6812f174(local_14,(int)param_2);
                    iVar7 = FUN_6810248f(param_1,param_3,PTR_u_ModuleSize_6815ff10,psVar4);
                  }
                  local_8 = 0xffffffff;
                  if (param_4 != (int *)0x0) {
                    (**(code **)(*param_4 + 8))();
                  }
                }
                if (-1 < iVar7) {
                  if (((uint)piVar2 & 0x200) != 0) {
                    CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                    local_8 = 4;
                    if (((param_4 != (int *)0x0) &&
                        (iVar7 = (**(code **)(*param_4 + 0x164))(param_4), -1 < iVar7)) &&
                       (param_2 != (int *)0x0)) {
                      puVar3 = FUN_6812fa7f((int)param_2);
                      iVar7 = FUN_6810248f(param_1,param_3,PTR_u_SymbolSize_6815ff14,puVar3);
                    }
                    local_8 = 0xffffffff;
                    if (param_4 != (int *)0x0) {
                      (**(code **)(*param_4 + 8))();
                    }
                  }
                  if (-1 < iVar7) {
                    if (((uint)piVar2 & 0x400) != 0) {
                      CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                      local_8 = 5;
                      if (((param_4 != (int *)0x0) &&
                          (iVar7 = (**(code **)(*param_4 + 0x16c))(param_4), -1 < iVar7)) &&
                         (param_2 != (int *)0x3)) {
                        psVar4 = FUN_6812f174(local_14,(int)param_2);
                        iVar7 = FUN_6810248f(param_1,param_3,PTR_u_RowHeight_6815ff20,psVar4);
                      }
                      local_8 = 0xffffffff;
                      if (param_4 != (int *)0x0) {
                        (**(code **)(*param_4 + 8))();
                      }
                    }
                    if (-1 < iVar7) {
                      if (((uint)piVar2 & 0x800) != 0) {
                        CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                        local_8 = 6;
                        if ((param_4 != (int *)0x0) &&
                           (iVar7 = (**(code **)(*param_4 + 0x174))(param_4), -1 < iVar7)) {
                          psVar4 = FUN_6812f174(local_14,(int)param_2);
                          iVar7 = FUN_6810248f(param_1,param_3,PTR_u_Columns_6815ff24,psVar4);
                        }
                        local_8 = 0xffffffff;
                        if (param_4 != (int *)0x0) {
                          (**(code **)(*param_4 + 8))();
                        }
                      }
                      if (-1 < iVar7) {
                        if (((uint)piVar2 & 0x4000) != 0) {
                          CComQIPtr<>(&local_20,(undefined4 *)*piVar1);
                          local_8 = 7;
                          if ((local_20 != (int *)0x0) &&
                             (iVar7 = (**(code **)(*local_20 + 0x17c))(local_20), -1 < iVar7)) {
                            psVar4 = FUN_6812f174(local_14,(int)local_24);
                            iVar7 = FUN_6810248f(param_1,param_3,PTR_u_Rows_6815ff28,psVar4);
                            if (-1 < iVar7) {
                              param_2 = (int *)0x0;
                              local_8._0_1_ = 8;
                              iVar7 = (**(code **)(*(int *)*param_3 + 0x94))
                                                ((int *)*param_3,PTR_u_Rows_6815ff28);
                              if ((iVar7 == 0) && (param_2 != (int *)0x0)) {
                                param_4 = (int *)0x0;
                                local_8._0_1_ = 9;
                                iVar7 = (**(code **)(*param_2 + 0x44))(param_2);
                                if ((-1 < iVar7) && (param_4 != (int *)0x0)) {
                                  CComQIPtr<>(&local_1c,(undefined4 *)*piVar1);
                                  local_8._0_1_ = 10;
                                  if (local_1c != (int *)0x0) {
                                    local_18 = (int *)0x0;
                                    iVar7 = (**(code **)(*local_1c + 0x234))(local_1c);
                                    if (local_18 != (int *)0x0) {
                                      FUN_68132710((uint *)&local_34,0,0x10);
                                      VariantInit((VARIANTARG *)&local_34.n2);
                                      local_8._0_1_ = 0xb;
                                      local_34.n2.vt = 8;
                                      psz = (OLECHAR *)FUN_6812e9d1((int)local_18);
                                      local_34._8_4_ = SysAllocString(psz);
                                      iVar7 = FUN_681021f5(param_1,&param_4,PTR_DAT_681600f0,
                                                           (undefined4 *)&local_34);
                                      VariantClear((VARIANTARG *)&local_34.n2);
                                    }
                                  }
                                  local_8._0_1_ = 9;
                                  if (local_1c != (int *)0x0) {
                                    (**(code **)(*local_1c + 8))();
                                  }
                                }
                                local_8._0_1_ = 8;
                                if (param_4 != (int *)0x0) {
                                  (**(code **)(*param_4 + 8))();
                                }
                              }
                              local_8 = CONCAT31(local_8._1_3_,7);
                              if (param_2 != (int *)0x0) {
                                (**(code **)(*param_2 + 8))();
                              }
                            }
                          }
                          local_8 = 0xffffffff;
                          if (local_20 != (int *)0x0) {
                            (**(code **)(*local_20 + 8))();
                          }
                        }
                        if (-1 < iVar7) {
                          if (((uint)piVar2 & 0x1000) != 0) {
                            CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                            local_8 = 0xc;
                            if (((param_4 != (int *)0x0) &&
                                (iVar7 = (**(code **)(*param_4 + 0x184))(param_4), -1 < iVar7)) &&
                               (param_2 != (int *)0x9)) {
                              puVar3 = FUN_6812edb2((int)param_2);
                              iVar7 = FUN_6810248f(param_1,param_3,PTR_u_ErrorCorrection_6815ff2c,
                                                   puVar3);
                            }
                            local_8 = 0xffffffff;
                            if (param_4 != (int *)0x0) {
                              (**(code **)(*param_4 + 8))();
                            }
                          }
                          if (-1 < iVar7) {
                            if (((uint)piVar2 & 0x2000) != 0) {
                              CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                              local_8 = 0xd;
                              if (((param_4 != (int *)0x0) &&
                                  (iVar7 = (**(code **)(*param_4 + 0x18c))(param_4), -1 < iVar7)) &&
                                 (param_2 != (int *)0x0)) {
                                puVar3 = FUN_6812f412((int)param_2);
                                iVar7 = FUN_6810248f(param_1,param_3,PTR_u_Type_6815ff30,puVar3);
                              }
                              local_8 = 0xffffffff;
                              if (param_4 != (int *)0x0) {
                                (**(code **)(*param_4 + 8))();
                              }
                            }
                            if (-1 < iVar7) {
                              if (((uint)piVar2 & 0x8000) != 0) {
                                CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                local_8 = 0xe;
                                if (((param_4 != (int *)0x0) &&
                                    (iVar7 = (**(code **)(*param_4 + 0x194))(param_4), -1 < iVar7))
                                   && (param_2 != (int *)0x0)) {
                                  puVar3 = FUN_6812f3b8((int)param_2);
                                  iVar7 = FUN_6810248f(param_1,param_3,PTR_u_Encoding_6815ff34,
                                                       puVar3);
                                }
                                local_8 = 0xffffffff;
                                if (param_4 != (int *)0x0) {
                                  (**(code **)(*param_4 + 8))();
                                }
                              }
                              if (-1 < iVar7) {
                                if (((uint)piVar2 & 0x10000) != 0) {
                                  CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                  local_8 = 0xf;
                                  if (((param_4 != (int *)0x0) &&
                                      (iVar7 = (**(code **)(*param_4 + 0x19c))(param_4), -1 < iVar7)
                                      ) && (param_2 != (int *)0x0)) {
                                    puVar3 = FUN_6812f105((int)param_2);
                                    iVar7 = FUN_6810248f(param_1,param_3,PTR_u_HRStyle_6815ff40,
                                                         puVar3);
                                  }
                                  local_8 = 0xffffffff;
                                  if (param_4 != (int *)0x0) {
                                    (**(code **)(*param_4 + 8))();
                                  }
                                }
                                if (-1 < iVar7) {
                                  if (((uint)piVar2 & 0x20000) != 0) {
                                    CComQIPtr<>(&param_2,(undefined4 *)*piVar1);
                                    local_8 = 0x10;
                                    if (param_2 != (int *)0x0) {
                                      param_4 = (int *)0x0;
                                      iVar7 = (**(code **)(*param_2 + 0x1ac))(param_2);
                                      if ((-1 < iVar7) && (param_4 != (int *)0x0)) {
                                        puVar3 = FUN_6812f765((int)param_4);
                                        iVar7 = FUN_6810248f(param_1,param_3,
                                                             PTR_u_QRVersion_6815ff64,puVar3);
                                      }
                                    }
                                    local_8 = 0xffffffff;
                                    if (param_2 != (int *)0x0) {
                                      (**(code **)(*param_2 + 8))();
                                    }
                                  }
                                  if (-1 < iVar7) {
                                    if (((uint)piVar2 & 0x40000) != 0) {
                                      CComQIPtr<>(&param_2,(undefined4 *)*piVar1);
                                      local_8 = 0x11;
                                      if (param_2 != (int *)0x0) {
                                        param_4 = (int *)0x1;
                                        iVar7 = (**(code **)(*param_2 + 0x1b4))(param_2);
                                        if ((-1 < iVar7) && (param_4 != (int *)0x1)) {
                                          puVar3 = FUN_6812f664((int)param_4);
                                          iVar7 = FUN_6810248f(param_1,param_3,
                                                               PTR_u_QRErrorLevel_6815ff68,puVar3);
                                        }
                                      }
                                      local_8 = 0xffffffff;
                                      if (param_2 != (int *)0x0) {
                                        (**(code **)(*param_2 + 8))();
                                      }
                                    }
                                    if (-1 < iVar7) {
                                      if (((uint)piVar2 & 0x80000) != 0) {
                                        CComQIPtr<>(&param_2,(undefined4 *)*piVar1);
                                        local_8 = 0x12;
                                        if (param_2 != (int *)0x0) {
                                          param_4 = (int *)0x0;
                                          iVar7 = (**(code **)(*param_2 + 0x1bc))(param_2);
                                          if ((-1 < iVar7) && (param_4 != (int *)0x0)) {
                                            puVar3 = FUN_6812e9d1((int)param_4);
                                            iVar7 = FUN_6810248f(param_1,param_3,
                                                                 PTR_u_QRMirror_6815ff6c,puVar3);
                                          }
                                        }
                                        local_8 = 0xffffffff;
                                        if (param_2 != (int *)0x0) {
                                          (**(code **)(*param_2 + 8))();
                                        }
                                      }
                                      if (-1 < iVar7) {
                                        if (((uint)piVar2 & 0x100000) != 0) {
                                          CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                          local_8 = 0x13;
                                          if (param_4 != (int *)0x0) {
                                            param_2 = (int *)0x0;
                                            iVar7 = (**(code **)(*param_4 + 0x1c4))(param_4);
                                            if (((-1 < iVar7) && (param_2 != (int *)0x0)) &&
                                               (iVar7 = (**(code **)(*param_4 + 0x1cc))(param_4),
                                               -1 < iVar7)) {
                                              psVar4 = FUN_6812f174(local_14,(int)local_24);
                                              iVar7 = FUN_6810248f(param_1,param_3,
                                                                   PTR_u_BearerSize_6815ff88,psVar4)
                                              ;
                                            }
                                          }
                                          local_8 = 0xffffffff;
                                          if (param_4 != (int *)0x0) {
                                            (**(code **)(*param_4 + 8))();
                                          }
                                        }
                                        if (-1 < iVar7) {
                                          if (((uint)piVar2 & 0x200000) != 0) {
                                            CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                            local_8 = 0x14;
                                            if (param_4 != (int *)0x0) {
                                              param_2 = (int *)0x0;
                                              iVar7 = (**(code **)(*param_4 + 0x1d4))(param_4);
                                              if (((-1 < iVar7) && (param_2 != (int *)0x0)) &&
                                                 (iVar7 = (**(code **)(*param_4 + 0x1dc))(param_4),
                                                 -1 < iVar7)) {
                                                pwVar5 = FUN_6812eef6(local_14,(double)local_24);
                                                iVar7 = FUN_6810248f(param_1,param_3,
                                                                     PTR_u_QMSize_6815ff8c,pwVar5);
                                              }
                                            }
                                            local_8 = 0xffffffff;
                                            if (param_4 != (int *)0x0) {
                                              (**(code **)(*param_4 + 8))();
                                            }
                                          }
                                          if (-1 < iVar7) {
                                            if (((uint)piVar2 & 0x400000) != 0) {
                                              CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                              local_8 = 0x15;
                                              if (((param_4 != (int *)0x0) &&
                                                  (iVar7 = (**(code **)(*param_4 + 0x1e4))(param_4),
                                                  -1 < iVar7)) && (param_2 != (int *)0x1)) {
                                                puVar3 = FUN_6812e9d1((int)param_2);
                                                iVar7 = FUN_6810248f(param_1,param_3,
                                                                     PTR_u_LegacyC128Enc_6815ffa8,
                                                                     puVar3);
                                              }
                                              local_8 = 0xffffffff;
                                              if (param_4 != (int *)0x0) {
                                                (**(code **)(*param_4 + 8))();
                                              }
                                            }
                                            if (-1 < iVar7) {
                                              if (((uint)piVar2 & 0x8000000) != 0) {
                                                CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                                local_8 = 0x16;
                                                if (((param_4 != (int *)0x0) &&
                                                    (iVar7 = (**(code **)(*param_4 + 0x21c))
                                                                       (param_4), -1 < iVar7)) &&
                                                   (param_2 != (int *)0x0)) {
                                                  puVar3 = FUN_6812e9d1((int)param_2);
                                                  iVar7 = FUN_6810248f(param_1,param_3,
                                                                                                                                              
                                                  PTR_u_ManualCode128Encoding_6815ffdc,puVar3);
                                                }
                                                local_8 = 0xffffffff;
                                                if (param_4 != (int *)0x0) {
                                                  (**(code **)(*param_4 + 8))();
                                                }
                                              }
                                              if (-1 < iVar7) {
                                                if (((uint)piVar2 & 0x10000000) != 0) {
                                                  CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                                  local_8 = 0x17;
                                                  if (((param_4 != (int *)0x0) &&
                                                      (iVar7 = (**(code **)(*param_4 + 0x224))
                                                                         (param_4), -1 < iVar7)) &&
                                                     (param_2 != (int *)0x0)) {
                                                    puVar3 = FUN_6812e9d1((int)param_2);
                                                    iVar7 = FUN_6810248f(param_1,param_3,
                                                                                                                                                  
                                                  PTR_u_CorrectCheckDigit_6815ffe0,puVar3);
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (param_4 != (int *)0x0) {
                                                    (**(code **)(*param_4 + 8))();
                                                  }
                                                }
                                                if (-1 < iVar7) {
                                                  if (((uint)piVar2 & 0x1000000) != 0) {
                                                    CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                                    local_8 = 0x18;
                                                    if (((param_4 != (int *)0x0) &&
                                                        (iVar7 = (**(code **)(*param_4 + 500))
                                                                           (param_4), -1 < iVar7))
                                                       && (param_2 != (int *)0x2)) {
                                                      psVar4 = FUN_6812f174(local_14,(int)param_2);
                                                      iVar7 = FUN_6810248f(param_1,param_3,
                                                                           PTR_u_Mode_6815ffb4,
                                                                           psVar4);
                                                    }
                                                    local_8 = 0xffffffff;
                                                    if (param_4 != (int *)0x0) {
                                                      (**(code **)(*param_4 + 8))();
                                                    }
                                                  }
                                                  if (-1 < iVar7) {
                                                    if (((uint)piVar2 & 0x2000000) != 0) {
                                                      CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                                      local_8 = 0x19;
                                                      if (((param_4 != (int *)0x0) &&
                                                          (iVar7 = (**(code **)(*param_4 + 0x1fc))
                                                                             (param_4), -1 < iVar7))
                                                         && (param_2 != (int *)0x1)) {
                                                        psVar4 = FUN_6812f174(local_14,(int)param_2)
                                                        ;
                                                        iVar7 = FUN_6810248f(param_1,param_3,
                                                                             PTR_u_Symbol_6815ffb8,
                                                                             psVar4);
                                                      }
                                                      local_8 = 0xffffffff;
                                                      if (param_4 != (int *)0x0) {
                                                        (**(code **)(*param_4 + 8))();
                                                      }
                                                    }
                                                    if (-1 < iVar7) {
                                                      if (((uint)piVar2 & 0x4000000) != 0) {
                                                        CComQIPtr<>(&param_4,(undefined4 *)*piVar1);
                                                        local_8 = 0x1a;
                                                        if (((param_4 != (int *)0x0) &&
                                                            (iVar7 = (**(code **)(*param_4 + 0x204))
                                                                               (param_4), -1 < iVar7
                                                            )) && (param_2 != (int *)0x1)) {
                                                          psVar4 = FUN_6812f174(local_14,(int)
                                                  param_2);
                                                  iVar7 = FUN_6810248f(param_1,param_3,
                                                                       PTR_u_SymbolCount_6815ffbc,
                                                                       psVar4);
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (param_4 != (int *)0x0) {
                                                    (**(code **)(*param_4 + 8))();
                                                  }
                                                  }
                                                  if ((-1 < iVar7) &&
                                                     (((uint)piVar2 & 0x20000000) != 0)) {
                                                    CComQIPtr<>(&local_18,(undefined4 *)*piVar1);
                                                    local_8 = 0x1b;
                                                    if (local_18 != (int *)0x0) {
                                                      local_1c = (int *)0x0;
                                                      iVar7 = (**(code **)(*local_18 + 0x22c))
                                                                        (local_18);
                                                      if ((-1 < iVar7) && (local_1c != (int *)0x0))
                                                      {
                                                        puVar3 = FUN_6812e8a9((int)local_1c);
                                                        iVar7 = FUN_6810248f(param_1,param_3,
                                                                                                                                                          
                                                  PTR_u_BarcodeDataFormat_6815ffe8,puVar3);
                                                  }
                                                  }
                                                  local_8 = 0xffffffff;
                                                  if (local_18 != (int *)0x0) {
                                                    (**(code **)(*local_18 + 8))();
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar7;
}



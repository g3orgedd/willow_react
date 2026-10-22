// Source: CiffMgr.dll @ 68127601; FUN_68127601

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68127601(BSTR param_1,BSTR param_2,int *param_3)

{
  BSTR pOVar1;
  bool bVar2;
  int iVar3;
  OLECHAR *pOVar4;
  BSTR pOVar5;
  BSTR pOVar6;
  short *psVar7;
  undefined *puVar8;
  UINT UVar9;
  wchar_t *pwVar10;
  _union_2683 local_50;
  int local_40;
  undefined1 local_3c [8];
  undefined8 local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_1c = 1;
  local_20 = 0;
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar3 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_18);
  pOVar1 = param_1;
  if ((-1 < iVar3) && (local_18 != (int *)0x0)) {
    FUN_68132710((uint *)local_3c,0,0x10);
    VariantInit((VARIANTARG *)local_3c);
    pOVar6 = param_2;
    local_34 = (ulonglong)(uint)local_34._4_4_ << 0x20;
    local_3c._0_2_ = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = (**(code **)(**(int **)param_2 + 0x1c))(*(int **)param_2);
    if ((-1 < iVar3) &&
       ((iVar3 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Name_68160030,
                              (undefined4 *)local_3c), -1 < iVar3 &&
        (iVar3 = (**(code **)(**(int **)pOVar6 + 0x24))(*(int **)pOVar6), -1 < iVar3)))) {
      if (local_20 != 0) {
        SysFreeString((BSTR)local_34);
        pOVar4 = (OLECHAR *)FUN_6812e9d1(local_20);
        pOVar5 = SysAllocString(pOVar4);
        local_34._0_4_ = pOVar5;
        iVar3 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_StaticDate_68160034,
                             (undefined4 *)local_3c);
      }
      if ((-1 < iVar3) &&
         (iVar3 = (**(code **)(**(int **)pOVar6 + 0x74))(*(int **)pOVar6), -1 < iVar3)) {
        if (local_1c != 1) {
          SysFreeString((BSTR)local_34);
          pOVar4 = (OLECHAR *)FUN_6812e9d1(local_1c);
          pOVar5 = SysAllocString(pOVar4);
          local_34._0_4_ = pOVar5;
          iVar3 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_AutoUpdate_68160038,
                               (undefined4 *)local_3c);
        }
        if (((-1 < iVar3) &&
            (iVar3 = (**(code **)(**(int **)pOVar6 + 0x4c))(*(int **)pOVar6), -1 < iVar3)) &&
           (param_1 != (BSTR)0x0)) {
          SysFreeString((BSTR)local_34);
          pOVar4 = (OLECHAR *)FUN_6812f2b6((int)param_1);
          pOVar6 = SysAllocString(pOVar4);
          local_34._0_4_ = pOVar6;
          iVar3 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Type_6816003c,
                               (undefined4 *)local_3c);
        }
      }
    }
    VariantClear((VARIANTARG *)local_3c);
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  pOVar6 = param_2;
  if (iVar3 < 0) {
    return iVar3;
  }
  iVar3 = (**(code **)(**(int **)param_2 + 0x54))(*(int **)param_2);
  if (iVar3 < 0) goto LAB_68127d23;
  if (local_40 == 0) {
    iVar3 = (**(code **)(**(int **)pOVar6 + 0x114))(*(int **)pOVar6);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(**(int **)pOVar6 + 0x2c))(*(int **)pOVar6);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(**(int **)pOVar6 + 0x34))(*(int **)pOVar6);
    if (iVar3 < 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(**(int **)pOVar6 + 0x3c))(*(int **)pOVar6);
    if (iVar3 < 0) {
      return iVar3;
    }
    if (((param_1 != (BSTR)0x0) || (local_18 != (int *)0x0)) || ((local_24 != 0 || (local_28 != 0)))
       ) {
      param_2 = (BSTR)0x0;
      local_8 = 2;
      iVar3 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_DefaultOffset_6815fc64,(int *)&param_2
                          );
      pOVar5 = param_2;
      if (-1 < iVar3) {
        if (param_1 != (BSTR)0x0) {
          psVar7 = FUN_6812f174(local_14,(int)param_1);
          iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Seconds_6815fc98,psVar7);
        }
        pOVar5 = param_2;
        if (-1 < iVar3) {
          if (local_18 != (int *)0x0) {
            psVar7 = FUN_6812f174(local_14,(int)local_18);
            iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_DAT_6815fc9c,psVar7);
          }
          pOVar5 = param_2;
          if (-1 < iVar3) {
            if (local_24 != 0) {
              psVar7 = FUN_6812f174(local_14,local_24);
              iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Month_6815fca0,psVar7);
            }
            pOVar5 = param_2;
            if ((-1 < iVar3) && (local_28 != 0)) {
              psVar7 = FUN_6812f174(local_14,local_28);
              iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Year_6815fca4,psVar7);
              pOVar5 = param_2;
            }
          }
        }
      }
      goto LAB_68127a3d;
    }
  }
  else {
    param_1 = (BSTR)0x0;
    local_8 = 3;
    iVar3 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_SourceOffset_6815fc68,(int *)&param_1);
    pOVar5 = param_1;
    if (-1 < iVar3) {
      param_2 = (BSTR)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar3 = (**(code **)(**(int **)pOVar6 + 0x5c))(*(int **)pOVar6);
      if (-1 < iVar3) {
        UVar9 = SysStringLen(param_2);
        if (UVar9 != 0) {
          iVar3 = FUN_6810226e((int *)pOVar1,&param_1,PTR_u_ConnStr_6815fca8,param_2);
        }
        if (-1 < iVar3) {
          SysFreeString(param_2);
          param_2 = (BSTR)0x0;
          iVar3 = (**(code **)(**(int **)pOVar6 + 100))(*(int **)pOVar6);
          if ((-1 < iVar3) &&
             (iVar3 = FUN_6810226e((int *)pOVar1,&param_1,PTR_u_DateSQL_6815fcac,param_2),
             -1 < iVar3)) {
            SysFreeString(param_2);
            param_2 = (BSTR)0x0;
            iVar3 = (**(code **)(**(int **)pOVar6 + 0x6c))(*(int **)pOVar6);
            if ((-1 < iVar3) && (UVar9 = SysStringLen(param_2), UVar9 != 0)) {
              iVar3 = FUN_6810226e((int *)pOVar1,&param_1,PTR_u_DateMask_6815fcb0,param_2);
            }
          }
        }
      }
      SysFreeString(param_2);
      pOVar5 = param_1;
    }
LAB_68127a3d:
    local_8 = 0xffffffff;
    if (pOVar5 != (BSTR)0x0) {
      (**(code **)(*(int *)pOVar5 + 8))();
    }
  }
  if ((-1 < iVar3) && (iVar3 = (**(code **)(**(int **)pOVar6 + 0x7c))(*(int **)pOVar6), -1 < iVar3))
  {
    if (param_2 != (BSTR)0x0) {
      puVar8 = FUN_6812f8c5((int)param_2);
      iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_RndMode_6815fc6c,puVar8);
    }
    if ((-1 < iVar3) &&
       (iVar3 = (**(code **)(**(int **)pOVar6 + 0x84))(*(int **)pOVar6), -1 < iVar3)) {
      if (param_2 != (BSTR)0x0) {
        puVar8 = FUN_6812f93d((int)param_2);
        iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_RndType_6815fc70,puVar8);
      }
      if ((-1 < iVar3) &&
         (iVar3 = (**(code **)(**(int **)pOVar6 + 0x8c))(*(int **)pOVar6), -1 < iVar3)) {
        if (param_2 != (BSTR)0x1) {
          psVar7 = FUN_6812f174(local_14,(int)param_2);
          iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_RndDay_6815fc74,psVar7);
        }
        if (-1 < iVar3) {
          param_2 = (BSTR)0x0;
          local_8 = 5;
          iVar3 = (**(code **)(**(int **)pOVar6 + 0x94))(*(int **)pOVar6);
          if ((-1 < iVar3) && (UVar9 = SysStringLen(param_2), UVar9 != 0)) {
            iVar3 = FUN_6810226e((int *)pOVar1,param_3,PTR_u_Prompt_6815fc78,param_2);
          }
          local_8 = 0xffffffff;
          SysFreeString(param_2);
          if ((-1 < iVar3) &&
             (iVar3 = (**(code **)(**(int **)pOVar6 + 0x9c))(*(int **)pOVar6), -1 < iVar3)) {
            if (param_2 != (BSTR)0x0) {
              puVar8 = FUN_6812f23b((int)param_2);
              iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_ResetOnSel_6815fc7c,puVar8);
            }
            if (-1 < iVar3) {
              iVar3 = (**(code **)(**(int **)pOVar6 + 0x11c))(*(int **)pOVar6);
              if (iVar3 < 0) {
                return iVar3;
              }
              iVar3 = (**(code **)(**(int **)pOVar6 + 0xa4))(*(int **)pOVar6);
              if (iVar3 < 0) {
                return iVar3;
              }
              iVar3 = (**(code **)(**(int **)pOVar6 + 0xac))(*(int **)pOVar6);
              if (iVar3 < 0) {
                return iVar3;
              }
              iVar3 = (**(code **)(**(int **)pOVar6 + 0xb4))(*(int **)pOVar6);
              if (iVar3 < 0) {
                return iVar3;
              }
              if ((((param_1 != (BSTR)0x0) || (local_28 != 0)) || (local_24 != 0)) ||
                 (local_18 != (int *)0x0)) {
                param_2 = (BSTR)0x0;
                local_8 = 6;
                iVar3 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_CurrentOffset_6815fc80,
                                     (int *)&param_2);
                if (-1 < iVar3) {
                  if (param_1 != (BSTR)0x0) {
                    psVar7 = FUN_6812f174(local_14,(int)param_1);
                    iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Seconds_6815fc98,psVar7);
                  }
                  if (-1 < iVar3) {
                    if (local_28 != 0) {
                      psVar7 = FUN_6812f174(local_14,local_28);
                      iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_DAT_6815fc9c,psVar7);
                    }
                    if (-1 < iVar3) {
                      if (local_24 != 0) {
                        psVar7 = FUN_6812f174(local_14,local_24);
                        iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Month_6815fca0,psVar7);
                      }
                      if ((-1 < iVar3) && (local_18 != (int *)0x0)) {
                        psVar7 = FUN_6812f174(local_14,(int)local_18);
                        iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Year_6815fca4,psVar7);
                      }
                    }
                  }
                }
                local_8 = 0xffffffff;
                if (param_2 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_2 + 8))();
                }
              }
            }
          }
        }
      }
    }
  }
LAB_68127d23:
  if ((local_1c == 0) && (local_20 == 0)) {
    local_34 = (_union_2685)0x0;
    iVar3 = (**(code **)(**(int **)pOVar6 + 0x44))(*(int **)pOVar6,&local_34);
    if (iVar3 < 0) {
      return iVar3;
    }
    pwVar10 = FUN_6812eef6(local_14,local_34);
    iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_CurrentDate_6815fc84,pwVar10);
  }
  if (-1 < iVar3) {
    param_2 = (BSTR)0x0;
    local_8 = 7;
    iVar3 = (**(code **)(**(int **)pOVar6 + 0xbc))(*(int **)pOVar6);
    if ((-1 < iVar3) && (bVar2 = FUN_68119d18(&param_2,L"CurrentDate"), !bVar2)) {
      iVar3 = FUN_6810226e((int *)pOVar1,param_3,PTR_u_RefDate_6815fc90,param_2);
    }
    local_8 = 0xffffffff;
    SysFreeString(param_2);
    if ((-1 < iVar3) &&
       (iVar3 = (**(code **)(**(int **)pOVar6 + 0xc4))(*(int **)pOVar6), -1 < iVar3)) {
      if (param_2 != (BSTR)0x1) {
        puVar8 = FUN_6812e9d1((int)param_2);
        iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_CalcAtCoder_6815fc94,puVar8);
      }
      if ((((-1 < iVar3) &&
           (iVar3 = (**(code **)(**(int **)pOVar6 + 0xcc))(*(int **)pOVar6), -1 < iVar3)) &&
          (iVar3 = (**(code **)(**(int **)pOVar6 + 0x124))(*(int **)pOVar6), -1 < iVar3)) &&
         (((iVar3 = (**(code **)(**(int **)pOVar6 + 0xd4))(*(int **)pOVar6), -1 < iVar3 &&
           (iVar3 = (**(code **)(**(int **)pOVar6 + 0xdc))(*(int **)pOVar6), -1 < iVar3)) &&
          (iVar3 = (**(code **)(**(int **)pOVar6 + 0xe4))(*(int **)pOVar6), -1 < iVar3)))) {
        if (((local_28 != 0) || (local_24 != 0)) ||
           ((local_18 != (int *)0x0 ||
            ((local_2c != 0 || ((IRecordInfo *)local_34._4_4_ != (IRecordInfo *)0x0)))))) {
          param_2 = (BSTR)0x0;
          local_8 = 8;
          iVar3 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_MinOffset_6815fc88,(int *)&param_2
                              );
          if (-1 < iVar3) {
            if (local_28 != 0) {
              param_1 = (BSTR)0x0;
              local_8._0_1_ = 9;
              iVar3 = (**(code **)(*(int *)param_2 + 0x44))(param_2);
              if ((-1 < iVar3) && (param_1 != (BSTR)0x0)) {
                FUN_68132710((uint *)&local_50,0,0x10);
                VariantInit((VARIANTARG *)&local_50.n2);
                local_8._0_1_ = 10;
                local_50.n2.vt = 8;
                pOVar4 = (OLECHAR *)FUN_6812e9d1(local_28);
                local_50._8_4_ = SysAllocString(pOVar4);
                iVar3 = FUN_681021f5((undefined4 *)pOVar1,&param_1,PTR_u_Used_68160040,
                                     (undefined4 *)&local_50);
                VariantClear((VARIANTARG *)&local_50.n2);
              }
              local_8 = CONCAT31(local_8._1_3_,8);
              if (param_1 != (BSTR)0x0) {
                (**(code **)(*(int *)param_1 + 8))();
              }
            }
            if (-1 < iVar3) {
              if (local_24 != 0) {
                psVar7 = FUN_6812f174(local_14,local_24);
                iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Seconds_6815fc98,psVar7);
              }
              if (-1 < iVar3) {
                if (local_18 != (int *)0x0) {
                  psVar7 = FUN_6812f174(local_14,(int)local_18);
                  iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_DAT_6815fc9c,psVar7);
                }
                if (-1 < iVar3) {
                  if (local_2c != 0) {
                    psVar7 = FUN_6812f174(local_14,local_2c);
                    iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Month_6815fca0,psVar7);
                  }
                  if ((-1 < iVar3) && ((IRecordInfo *)local_34._4_4_ != (IRecordInfo *)0x0)) {
                    psVar7 = FUN_6812f174(local_14,local_34._4_4_);
                    iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Year_6815fca4,psVar7);
                  }
                }
              }
            }
          }
          local_8 = 0xffffffff;
          if (param_2 != (BSTR)0x0) {
            (**(code **)(*(int *)param_2 + 8))();
          }
        }
        if ((((-1 < iVar3) &&
             (iVar3 = (**(code **)(**(int **)pOVar6 + 0xec))(*(int **)pOVar6), -1 < iVar3)) &&
            (iVar3 = (**(code **)(**(int **)pOVar6 + 300))(*(int **)pOVar6), -1 < iVar3)) &&
           (((iVar3 = (**(code **)(**(int **)pOVar6 + 0xf4))(*(int **)pOVar6), -1 < iVar3 &&
             (iVar3 = (**(code **)(**(int **)pOVar6 + 0xfc))(*(int **)pOVar6), -1 < iVar3)) &&
            (iVar3 = (**(code **)(**(int **)pOVar6 + 0x104))(*(int **)pOVar6), -1 < iVar3)))) {
          if ((((IRecordInfo *)local_34._4_4_ != (IRecordInfo *)0x0) || (local_2c != 0)) ||
             ((local_28 != 0 || ((local_24 != 0 || (local_18 != (int *)0x0)))))) {
            param_2 = (BSTR)0x0;
            local_8 = 0xb;
            iVar3 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_MaxOffset_6815fc8c,
                                 (int *)&param_2);
            if (-1 < iVar3) {
              if ((IRecordInfo *)local_34._4_4_ != (IRecordInfo *)0x0) {
                param_1 = (BSTR)0x0;
                local_8._0_1_ = 0xc;
                iVar3 = (**(code **)(*(int *)param_2 + 0x44))(param_2);
                if ((-1 < iVar3) && (param_1 != (BSTR)0x0)) {
                  FUN_68132710((uint *)&local_50,0,0x10);
                  VariantInit((VARIANTARG *)&local_50.n2);
                  local_8._0_1_ = 0xd;
                  local_50.n2.vt = 8;
                  pOVar4 = (OLECHAR *)FUN_6812e9d1((int)SUB84(local_34,4));
                  local_50._8_4_ = SysAllocString(pOVar4);
                  iVar3 = FUN_681021f5((undefined4 *)pOVar1,&param_1,PTR_u_Used_68160040,
                                       (undefined4 *)&local_50);
                  VariantClear((VARIANTARG *)&local_50.n2);
                }
                local_8 = CONCAT31(local_8._1_3_,0xb);
                if (param_1 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_1 + 8))();
                }
              }
              if (-1 < iVar3) {
                if (local_2c != 0) {
                  psVar7 = FUN_6812f174(local_14,local_2c);
                  iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Seconds_6815fc98,psVar7);
                }
                if (-1 < iVar3) {
                  if (local_28 != 0) {
                    psVar7 = FUN_6812f174(local_14,local_28);
                    iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_DAT_6815fc9c,psVar7);
                  }
                  if (-1 < iVar3) {
                    if (local_24 != 0) {
                      psVar7 = FUN_6812f174(local_14,local_24);
                      iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Month_6815fca0,psVar7);
                    }
                    if ((-1 < iVar3) && (local_18 != (int *)0x0)) {
                      psVar7 = FUN_6812f174(local_14,(int)local_18);
                      iVar3 = FUN_6810248f((int *)pOVar1,&param_2,PTR_u_Year_6815fca4,psVar7);
                    }
                  }
                }
              }
            }
            local_8 = 0xffffffff;
            if (param_2 != (BSTR)0x0) {
              (**(code **)(*(int *)param_2 + 8))();
            }
          }
          if (-1 < iVar3) {
            pOVar6 = *(BSTR *)pOVar6;
            param_2 = pOVar6;
            if (pOVar6 != (BSTR)0x0) {
              (**(code **)(*(int *)pOVar6 + 4))();
            }
            local_8 = 0xe;
            if ((pOVar6 != (BSTR)0x0) &&
               (iVar3 = FUN_681247de((int *)pOVar1,(int *)&param_2,param_3), -1 < iVar3)) {
              iVar3 = FUN_68124548((int *)pOVar1,(int *)&param_2,param_3);
            }
            local_8 = 0xffffffff;
            if (pOVar6 != (BSTR)0x0) {
              (**(code **)(*(int *)pOVar6 + 8))();
            }
          }
        }
      }
    }
  }
  return iVar3;
}



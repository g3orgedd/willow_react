// Source: CiffMgr.dll @ 68128924; FUN_68128924

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int FUN_68128924(BSTR param_1,BSTR param_2,undefined4 *param_3)

{
  BSTR pOVar1;
  BSTR pOVar2;
  bool bVar3;
  int iVar4;
  OLECHAR *psz;
  UINT UVar5;
  undefined *puVar6;
  short *psVar7;
  int iVar8;
  BSTR pOVar9;
  _union_2683 local_40;
  undefined1 local_30 [16];
  undefined1 local_20 [4];
  int local_1c;
  BSTR local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_18 = (BSTR)0x0;
  local_8 = 0;
  iVar4 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_18);
  pOVar2 = param_2;
  pOVar1 = param_1;
  if ((-1 < iVar4) && (local_18 != (BSTR)0x0)) {
    FUN_68132710((uint *)local_30,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_30)->n2);
    local_30._8_4_ = 0;
    local_30._0_2_ = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar4 = (**(code **)(**(int **)pOVar2 + 0x1c))
                      (*(int **)pOVar2,&(((_union_2683 *)local_30)->n2).n3);
    if (-1 < iVar4) {
      iVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Name_68160030,(undefined4 *)local_30
                          );
    }
    param_2 = (BSTR)0x0;
    CComQIPtr<>(&param_1,*(undefined4 **)pOVar2);
    local_8._0_1_ = 2;
    if (((param_1 != (BSTR)0x0) &&
        (iVar4 = (**(code **)(*(int *)param_1 + 0x14))(param_1,&param_2), -1 < iVar4)) &&
       (param_2 != (BSTR)0x0)) {
      FUN_68132710((uint *)&local_40,0,0x10);
      VariantInit((VARIANTARG *)&local_40.n2);
      local_8._0_1_ = 3;
      local_40.n2.vt = 8;
      psz = (OLECHAR *)FUN_6812e9d1((int)param_2);
      local_40._8_4_ = SysAllocString(psz);
      iVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_TXField_681600d0,
                           (undefined4 *)&local_40);
      VariantClear((VARIANTARG *)&local_40.n2);
    }
    local_8 = CONCAT31(local_8._1_3_,1);
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_30)->n2);
  }
  local_8 = 0xffffffff;
  if (local_18 != (BSTR)0x0) {
    (**(code **)(*(int *)local_18 + 8))(local_18);
  }
  if (-1 < iVar4) {
    param_2 = (BSTR)0x0;
    local_8 = 4;
    iVar4 = (**(code **)(**(int **)pOVar2 + 0x68))(*(int **)pOVar2,&param_2);
    if ((-1 < iVar4) && (UVar5 = SysStringLen(param_2), UVar5 != 0)) {
      iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_FldType_6815fcdc,param_2);
    }
    local_8 = 0xffffffff;
    SysFreeString(param_2);
    if (-1 < iVar4) {
      param_2 = (BSTR)0x0;
      local_8 = 5;
      iVar4 = (**(code **)(**(int **)pOVar2 + 0x70))(*(int **)pOVar2,&param_2);
      if ((-1 < iVar4) &&
         (bVar3 = FUN_68119d18(&param_2,L"{BB0561B2-C54F-11D4-A995-00010212D541}"), !bVar3)) {
        iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_CLSID_6815fce0,param_2);
      }
      local_8 = 0xffffffff;
      SysFreeString(param_2);
      if ((-1 < iVar4) &&
         (iVar4 = (**(code **)(**(int **)pOVar2 + 0x24))(*(int **)pOVar2,&param_2), -1 < iVar4)) {
        if (param_2 != (BSTR)0x1) {
          puVar6 = FUN_6812e9d1((int)param_2);
          iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Displayed_6815fce4,puVar6);
        }
        if ((-1 < iVar4) &&
           (iVar4 = (**(code **)(**(int **)pOVar2 + 0x2c))(*(int **)pOVar2,&param_2), -1 < iVar4)) {
          psVar7 = FUN_6812f174(local_14,(int)param_2);
          iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_DAT_6815fce8,psVar7);
          if ((-1 < iVar4) &&
             (iVar4 = (**(code **)(**(int **)pOVar2 + 0x34))(*(int **)pOVar2,&param_2), -1 < iVar4))
          {
            psVar7 = FUN_6812f174(local_14,(int)param_2);
            iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_DAT_6815fcec,psVar7);
            if ((-1 < iVar4) &&
               (iVar4 = (**(code **)(**(int **)pOVar2 + 0x78))(*(int **)pOVar2,&param_2), -1 < iVar4
               )) {
              psVar7 = FUN_6812f174(local_14,(int)param_2);
              iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_DAT_6815fcf0,psVar7);
              if ((-1 < iVar4) &&
                 (iVar4 = (**(code **)(**(int **)pOVar2 + 0x80))(*(int **)pOVar2,&param_2),
                 -1 < iVar4)) {
                psVar7 = FUN_6812f174(local_14,(int)param_2);
                iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_DAT_6815fcf4,psVar7);
                if ((-1 < iVar4) &&
                   (iVar4 = (**(code **)(**(int **)pOVar2 + 0x88))(*(int **)pOVar2,&param_2),
                   -1 < iVar4)) {
                  if (param_2 != (BSTR)0x0) {
                    psVar7 = FUN_6812f174(local_14,(int)param_2);
                    iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_DAT_6815fcf8,psVar7);
                  }
                  if ((-1 < iVar4) &&
                     (iVar4 = (**(code **)(**(int **)pOVar2 + 0x3c))(*(int **)pOVar2,&param_2),
                     -1 < iVar4)) {
                    if (param_2 != (BSTR)0x0) {
                      psVar7 = FUN_6812f174(local_14,(int)param_2);
                      iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Orientation_6815fcfc,psVar7);
                    }
                    if ((-1 < iVar4) &&
                       (iVar4 = (**(code **)(**(int **)pOVar2 + 0x90))(*(int **)pOVar2,&param_2),
                       -1 < iVar4)) {
                      if (param_2 != (BSTR)0x0) {
                        puVar6 = FUN_6812e9d1((int)param_2);
                        iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_OverrideThis_6815fd00,
                                             puVar6);
                      }
                      if ((-1 < iVar4) &&
                         (iVar4 = (**(code **)(**(int **)pOVar2 + 0x44))(*(int **)pOVar2,&param_2),
                         -1 < iVar4)) {
                        if (param_2 != (BSTR)0x0) {
                          puVar6 = FUN_6812e9d1((int)param_2);
                          iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Inverse_6815fd04,puVar6);
                        }
                        if ((-1 < iVar4) &&
                           (iVar4 = (**(code **)(**(int **)pOVar2 + 0x4c))(*(int **)pOVar2,&param_2)
                           , -1 < iVar4)) {
                          if (param_2 != (BSTR)0x0) {
                            puVar6 = FUN_6812e9d1((int)param_2);
                            iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Mirror_6815fd08,puVar6)
                            ;
                          }
                          if ((-1 < iVar4) &&
                             (iVar4 = (**(code **)(**(int **)pOVar2 + 0x54))
                                                (*(int **)pOVar2,&param_2), -1 < iVar4)) {
                            if (param_2 != (BSTR)0x0) {
                              puVar6 = FUN_6812f7d9((int)param_2);
                              iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_RenderMode_6815fd0c,
                                                   puVar6);
                            }
                            if (-1 < iVar4) {
                              param_2 = (BSTR)0x0;
                              local_8 = 6;
                              iVar4 = (**(code **)(**(int **)pOVar2 + 0x98))
                                                (*(int **)pOVar2,&param_2);
                              if ((-1 < iVar4) && (UVar5 = SysStringLen(param_2), UVar5 != 0)) {
                                FUN_68124340((int *)&param_2);
                                UVar5 = SysStringLen(param_2);
                                if (UVar5 != 0) {
                                  iVar4 = FUN_6810226e((int *)pOVar1,param_3,PTR_u_CalcData_6815fd10
                                                       ,param_2);
                                }
                              }
                              local_8 = 0xffffffff;
                              SysFreeString(param_2);
                              if (-1 < iVar4) {
                                param_2 = (BSTR)0x0;
                                local_8 = 7;
                                iVar4 = (**(code **)(**(int **)pOVar2 + 0xa0))
                                                  (*(int **)pOVar2,&param_2);
                                if ((-1 < iVar4) &&
                                   ((param_2 == (BSTR)0x0 ||
                                    (iVar8 = _wcscmp(param_2,L"Not Logged"), iVar8 != 0)))) {
                                  iVar4 = FUN_6810248f((int *)pOVar1,param_3,
                                                       PTR_u_LoggedField_6815fd14,param_2);
                                }
                                local_8 = 0xffffffff;
                                SysFreeString(param_2);
                                if (-1 < iVar4) {
                                  CComQIPtr<>(&param_2,*(undefined4 **)pOVar2);
                                  local_8 = 8;
                                  if (((param_2 != (BSTR)0x0) &&
                                      (iVar4 = (**(code **)(*(int *)param_2 + 0xc))
                                                         (param_2,&param_1), -1 < iVar4)) &&
                                     (param_1 != (BSTR)0x0)) {
                                    puVar6 = FUN_6812f344((int)param_1);
                                    iVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Origin_6815fd18
                                                         ,puVar6);
                                  }
                                  local_8 = 0xffffffff;
                                  if (param_2 != (BSTR)0x0) {
                                    (**(code **)(*(int *)param_2 + 8))(param_2);
                                  }
                                  if (-1 < iVar4) {
                                    CComQIPtr<>(&local_18,*(undefined4 **)pOVar2);
                                    if (local_18 != (BSTR)0x0) {
                                      param_2 = (BSTR)0x0;
                                      local_8 = 10;
                                      iVar4 = (**(code **)(*(int *)local_18 + 0x1c))
                                                        (local_18,&param_2);
                                      if ((-1 < iVar4) &&
                                         (UVar5 = SysStringLen(param_2), UVar5 != 0)) {
                                        iVar4 = FUN_6810248f((int *)pOVar1,param_3,
                                                             PTR_u_MarkSet_6815ffd0,param_2);
                                      }
                                      SysFreeString(param_2);
                                    }
                                    local_8 = 0xffffffff;
                                    if (local_18 != (BSTR)0x0) {
                                      (**(code **)(*(int *)local_18 + 8))(local_18);
                                    }
                                    if (-1 < iVar4) {
                                      param_2 = (BSTR)0x0;
                                      local_8 = 0xb;
                                      iVar4 = (**(code **)(**(int **)pOVar2 + 0x5c))
                                                        (*(int **)pOVar2,&param_2);
                                      if ((-1 < iVar4) && (param_2 != (BSTR)0x0)) {
                                        param_1 = (BSTR)0x0;
                                        local_8 = CONCAT31(local_8._1_3_,0xc);
                                        iVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,
                                                             PTR_u_Data_6815fd1c,(int *)&param_1);
                                        if (-1 < iVar4) {
                                          iVar4 = FUN_6812708a(pOVar1,&param_2,&param_1);
                                        }
                                        local_8 = CONCAT31(local_8._1_3_,0xb);
                                        if (param_1 != (BSTR)0x0) {
                                          (**(code **)(*(int *)param_1 + 8))(param_1);
                                        }
                                      }
                                      local_8 = 0xffffffff;
                                      if (param_2 != (BSTR)0x0) {
                                        (**(code **)(*(int *)param_2 + 8))(param_2);
                                      }
                                      if (-1 < iVar4) {
                                        param_2 = (BSTR)0x0;
                                        local_8 = 0xd;
                                        iVar4 = (**(code **)(**(int **)pOVar2 + 0x60))
                                                          (*(int **)pOVar2,&param_2);
                                        if ((((-1 < iVar4) && (param_2 != (BSTR)0x0)) &&
                                            (iVar4 = (**(code **)(*(int *)param_2 + 0x24))
                                                               (param_2,&local_18), -1 < iVar4)) &&
                                           (0 < (int)local_18)) {
                                          param_1 = (BSTR)0x0;
                                          local_8 = CONCAT31(local_8._1_3_,0xe);
                                          iVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,
                                                               PTR_u_Clip_6815fdb4,(int *)&param_1);
                                          if (-1 < iVar4) {
                                            iVar4 = FUN_68126015(local_14,(undefined4 *)pOVar1,
                                                                 &param_2,&param_1);
                                          }
                                          local_8 = CONCAT31(local_8._1_3_,0xd);
                                          if (param_1 != (BSTR)0x0) {
                                            (**(code **)(*(int *)param_1 + 8))(param_1);
                                          }
                                        }
                                        local_8 = 0xffffffff;
                                        if (param_2 != (BSTR)0x0) {
                                          (**(code **)(*(int *)param_2 + 8))(param_2);
                                        }
                                        if ((-1 < iVar4) &&
                                           (iVar4 = (**(code **)(**(int **)pOVar2 + 100))
                                                              (*(int **)pOVar2,&local_1c),
                                           -1 < iVar4)) {
                                          if (local_1c == 0) {
                                            param_2 = (BSTR)0x0;
                                            local_8 = 0xf;
                                            iVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,
                                                                 PTR_u_Text_6815fd20,(int *)&param_2
                                                                );
                                            pOVar9 = param_2;
                                            if (-1 < iVar4) {
                                              iVar4 = FUN_6812ccce(local_14,(int *)pOVar1,
                                                                   (int *)pOVar2,&param_2);
                                              pOVar9 = param_2;
                                            }
                                          }
                                          else if (local_1c == 1) {
                                            local_18 = (BSTR)0x0;
                                            local_8 = 0x10;
                                            (**(code **)**(undefined4 **)pOVar2)
                                                      (*(undefined4 **)pOVar2,&DAT_6814a7fc,
                                                       &local_18);
                                            iVar8 = (**(code **)(*(int *)local_18 + 0xa8))
                                                              (local_18,local_20);
                                            pOVar9 = local_18;
                                            if (-1 < iVar8) {
                                              param_2 = (BSTR)0x0;
                                              local_8 = CONCAT31(local_8._1_3_,0x11);
                                              iVar8 = FUN_68124179((undefined4 *)pOVar1,param_3,
                                                                   PTR_u_Barcode_6815fd24,
                                                                   (int *)&param_2);
                                              if (-1 < iVar8) {
                                                FUN_68124afe((int *)pOVar1,(int *)pOVar2,&param_2);
                                              }
                                              local_8 = CONCAT31(local_8._1_3_,0x10);
                                              pOVar9 = local_18;
                                              if (param_2 != (BSTR)0x0) {
                                                (**(code **)(*(int *)param_2 + 8))(param_2);
                                                pOVar9 = local_18;
                                              }
                                            }
                                          }
                                          else {
                                            if (local_1c != 2) {
                                              return iVar4;
                                            }
                                            param_1 = (BSTR)0x0;
                                            local_8 = 0x12;
                                            iVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,
                                                                 PTR_u_Graphic_6815fd28,
                                                                 (int *)&param_1);
                                            pOVar9 = param_1;
                                            if (-1 < iVar4) {
                                              iVar4 = FUN_68129475(local_14,(int *)pOVar1,
                                                                   (int *)pOVar2,(int *)&param_1);
                                              pOVar9 = param_1;
                                            }
                                          }
                                          local_8 = 0xffffffff;
                                          if (pOVar9 != (BSTR)0x0) {
                                            (**(code **)(*(int *)pOVar9 + 8))(pOVar9);
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
  return iVar4;
}



// Source: CiffMgr.dll @ 68126560; FUN_68126560

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

uint FUN_68126560(BSTR param_1,BSTR param_2,undefined4 *param_3)

{
  BSTR pOVar1;
  BSTR pOVar2;
  bool bVar3;
  uint uVar4;
  OLECHAR *pOVar5;
  short *psVar6;
  wchar_t *pwVar7;
  UINT UVar8;
  undefined *puVar9;
  int iVar10;
  BSTR pOVar11;
  undefined1 local_38 [16];
  BSTR local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  BSTR local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_18 = (BSTR)0x0;
  local_8 = 0;
  uVar4 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_18);
  pOVar2 = param_2;
  pOVar1 = param_1;
  if ((-1 < (int)uVar4) && (local_18 != (BSTR)0x0)) {
    FUN_68132710((uint *)local_38,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_38)->n2);
    local_38._8_4_ = (BSTR)0x0;
    local_38._0_2_ = 8;
    local_8._0_1_ = 1;
    uVar4 = (**(code **)(**(int **)pOVar2 + 0x30))(*(int **)pOVar2,&param_2);
    if (-1 < (int)uVar4) {
      if (param_2 != (BSTR)0x0) {
        pOVar5 = FUN_6812f174(local_14,(int)param_2);
        local_38._8_4_ = SysAllocString(pOVar5);
        uVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Index_68160050,
                             (undefined4 *)local_38);
      }
      if ((-1 < (int)uVar4) &&
         (uVar4 = (**(code **)(**(int **)pOVar2 + 0x38))(*(int **)pOVar2,&param_2), -1 < (int)uVar4)
         ) {
        if (param_2 != (BSTR)0x1) {
          SysFreeString((BSTR)local_38._8_4_);
          pOVar5 = (OLECHAR *)FUN_6812e9d1((int)param_2);
          local_38._8_4_ = SysAllocString(pOVar5);
          uVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Static_68160054,
                               (undefined4 *)local_38);
        }
        if ((-1 < (int)uVar4) &&
           (uVar4 = (**(code **)(**(int **)pOVar2 + 0x40))(*(int **)pOVar2,&param_2),
           -1 < (int)uVar4)) {
          if (param_2 != (BSTR)0x0) {
            SysFreeString((BSTR)local_38._8_4_);
            pOVar5 = (OLECHAR *)FUN_6812e9d1((int)param_2);
            local_38._8_4_ = SysAllocString(pOVar5);
            uVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Parse_68160058,
                                 (undefined4 *)local_38);
          }
          if ((-1 < (int)uVar4) &&
             (uVar4 = (**(code **)(**(int **)pOVar2 + 0x48))(*(int **)pOVar2,&param_2),
             -1 < (int)uVar4)) {
            if (param_2 != (BSTR)0x0) {
              SysFreeString((BSTR)local_38._8_4_);
              pOVar5 = (OLECHAR *)FUN_6812ed2a((int)param_2);
              local_38._8_4_ = SysAllocString(pOVar5);
              uVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_EqRef_681600a4,
                                   (undefined4 *)local_38);
            }
            if (-1 < (int)uVar4) {
              CComQIPtr<>(&param_2,*(undefined4 **)pOVar2);
              local_8._0_1_ = 2;
              if (((param_2 != (BSTR)0x0) &&
                  (uVar4 = (**(code **)(*(int *)param_2 + 0x188))(param_2,&param_1), -1 < (int)uVar4
                  )) && (param_1 != (BSTR)0x0)) {
                SysFreeString((BSTR)local_38._8_4_);
                pOVar5 = (OLECHAR *)FUN_6812e9d1((int)param_1);
                local_38._8_4_ = SysAllocString(pOVar5);
                uVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Param_681600ec,
                                     (undefined4 *)local_38);
              }
              local_8._0_1_ = 1;
              if (param_2 != (BSTR)0x0) {
                (**(code **)(*(int *)param_2 + 8))(param_2);
              }
              if (-1 < (int)uVar4) {
                CComQIPtr<>(&param_2,*(undefined4 **)pOVar2);
                local_8._0_1_ = 3;
                if (param_2 != (BSTR)0x0) {
                  SysFreeString((BSTR)local_38._8_4_);
                  uVar4 = (**(code **)(*(int *)param_2 + 0x1a8))
                                    (param_2,&(((_union_2683 *)local_38)->n2).n3);
                  if (-1 < (int)uVar4) {
                    uVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_18,PTR_u_Reference_68160108,
                                         (undefined4 *)local_38);
                  }
                }
                local_8._0_1_ = 1;
                if (param_2 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_2 + 8))(param_2);
                }
              }
            }
          }
        }
      }
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_38)->n2);
  }
  local_8 = 0xffffffff;
  if (local_18 != (BSTR)0x0) {
    (**(code **)(*(int *)local_18 + 8))(local_18);
  }
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar4 = (**(code **)(**(int **)pOVar2 + 0x50))(*(int **)pOVar2,&param_2);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  psVar6 = FUN_6812f174(local_14,(int)param_2);
  uVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_DataType_6815fd30,psVar6);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  param_2 = (BSTR)0x0;
  local_8 = 4;
  uVar4 = (**(code **)(**(int **)pOVar2 + 0x80))(*(int **)pOVar2,&param_2);
  if ((-1 < (int)uVar4) && (bVar3 = FUN_68119d18(&param_2,L"EN-GB"), !bVar3)) {
    uVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Locale_6815fd34,param_2);
  }
  local_8 = 0xffffffff;
  SysFreeString(param_2);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar4 = (**(code **)(**(int **)pOVar2 + 0x8c))(*(int **)pOVar2,&param_2);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  if (param_2 != (BSTR)0x1) {
    pwVar7 = FUN_6812ea38((int)param_2);
    uVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Calendar_6815fd38,pwVar7);
  }
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  param_2 = (BSTR)0x0;
  local_8 = 5;
  uVar4 = (**(code **)(**(int **)pOVar2 + 0x78))(*(int **)pOVar2,&param_2);
  if ((-1 < (int)uVar4) && (UVar8 = SysStringLen(param_2), UVar8 != 0)) {
    uVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Encryption_6815fd3c,param_2);
  }
  local_8 = 0xffffffff;
  SysFreeString(param_2);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar4 = (**(code **)(**(int **)pOVar2 + 0x94))(*(int **)pOVar2,&param_2);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  if (param_2 != (BSTR)0x0) {
    psVar6 = FUN_6812f174(local_14,(int)param_2);
    uVar4 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_MaxNoOfChars_6815fd40,psVar6);
  }
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  param_2 = (BSTR)0x0;
  local_8 = 6;
  uVar4 = (**(code **)(**(int **)pOVar2 + 0x58))(*(int **)pOVar2,&param_2);
  if ((-1 < (int)uVar4) && (UVar8 = SysStringLen(param_2), UVar8 != 0)) {
    uVar4 = FUN_6810226e((int *)pOVar1,param_3,PTR_u_Default_6815fd44,param_2);
  }
  local_8 = 0xffffffff;
  SysFreeString(param_2);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  uVar4 = (**(code **)(**(int **)pOVar2 + 0x9c))(*(int **)pOVar2,&local_24);
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  if (local_24 != (int *)0x0) {
    param_1 = (BSTR)0x0;
    local_8 = 7;
    uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_FixedLen_6815fd48,(int *)&param_1);
    if ((-1 < (int)uVar4) &&
       (uVar4 = (**(code **)(**(int **)pOVar2 + 0xa4))(*(int **)pOVar2,&param_2), -1 < (int)uVar4))
    {
      if ((short)param_2 != 0x20) {
        local_28 = (BSTR)((uint)param_2 & 0xffff);
        uVar4 = FUN_6810226e((int *)pOVar1,&param_1,PTR_u_PadChar_6815fd60,&local_28);
      }
      if (((-1 < (int)uVar4) &&
          (uVar4 = (**(code **)(**(int **)pOVar2 + 0xac))(*(int **)pOVar2,&param_2), -1 < (int)uVar4
          )) && (param_2 != (BSTR)0x0)) {
        puVar9 = FUN_6812ee0c((int)param_2);
        uVar4 = FUN_6810248f((int *)pOVar1,&param_1,PTR_u_PadMode_6815fd64,puVar9);
      }
    }
    local_8 = 0xffffffff;
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
  }
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  CComQIPtr<>(&local_20,*(undefined4 **)pOVar2);
  if (local_20 == (int *)0x0) goto LAB_68126d48;
  local_28 = (BSTR)0x0;
  local_8._0_1_ = 9;
  local_8._1_3_ = 0;
  uVar4 = (**(code **)(*local_20 + 0x140))(local_20,&local_28);
  if ((-1 < (int)uVar4) && (UVar8 = SysStringLen(local_28), UVar8 != 0)) {
    param_1 = (BSTR)0x0;
    local_24 = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,0xb);
    uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_PriceData_6815fee4,(int *)&param_1);
    if (-1 < (int)uVar4) {
      if (param_1 != (BSTR)0x0) {
        uVar4 = (**(code **)(*(int *)param_1 + 0x44))(param_1,&local_24);
      }
      if (-1 < (int)uVar4) {
        if (local_24 != (int *)0x0) {
          FUN_68132710((uint *)local_38,0,0x10);
          VariantInit((VARIANTARG *)&((_union_2683 *)local_38)->n2);
          local_38._8_4_ = 0;
          local_8 = CONCAT31(local_8._1_3_,0xc);
          local_38._0_2_ = 8;
          local_38._8_4_ = SysAllocString(local_28);
          uVar4 = FUN_681021f5((undefined4 *)pOVar1,&local_24,PTR_u_SrcPrice_681600c8,
                               (undefined4 *)local_38);
          VariantClear((VARIANTARG *)&((_union_2683 *)local_38)->n2);
        }
        if ((-1 < (int)uVar4) && (param_1 != (BSTR)0x0)) {
          local_18 = (BSTR)0x0;
          param_2 = (BSTR)0x0;
          local_8 = CONCAT31(local_8._1_3_,0xe);
          iVar10 = (**(code **)(*local_20 + 0x148))(local_20,&local_18);
          if (iVar10 < 0) {
            SysFreeString(local_18);
            local_18 = (BSTR)0x0;
          }
          iVar10 = (**(code **)(*local_20 + 0x150))(local_20,&param_2);
          if (iVar10 < 0) {
            SysFreeString(param_2);
            param_2 = (BSTR)0x0;
          }
          uVar4 = (**(code **)(*local_20 + 0x158))(local_20,&local_1c);
          if ((int)uVar4 < 0) {
            local_1c = 0;
          }
          if (local_1c < 1) {
LAB_68126c7b:
            SysFreeString(param_2);
            param_2 = (BSTR)0x0;
          }
          else {
            UVar8 = SysStringLen(local_18);
            if ((UVar8 == 0) || (UVar8 = SysStringLen(param_2), UVar8 == 0)) {
              local_1c = 0;
              goto LAB_68126c7b;
            }
          }
          if (-1 < (int)uVar4) {
            UVar8 = SysStringLen(local_18);
            if (UVar8 != 0) {
              uVar4 = FUN_6810226e((int *)pOVar1,&param_1,PTR_u_HigherFmt_6815feec,local_18);
            }
            if (-1 < (int)uVar4) {
              UVar8 = SysStringLen(param_2);
              if (UVar8 != 0) {
                uVar4 = FUN_6810226e((int *)pOVar1,&param_1,PTR_u_LowerFmt_6815fef0,param_2);
              }
              if ((-1 < (int)uVar4) && (0 < local_1c)) {
                psVar6 = FUN_6812f174(local_14,local_1c);
                uVar4 = FUN_6810248f((int *)pOVar1,&param_1,PTR_u_SwitchVal_6815fef4,psVar6);
              }
            }
          }
          SysFreeString(param_2);
          SysFreeString(local_18);
        }
      }
    }
    local_8._0_1_ = 10;
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))(local_24);
    }
    local_8._0_1_ = 9;
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
  }
  SysFreeString(local_28);
LAB_68126d48:
  local_8 = 0xffffffff;
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (-1 < (int)uVar4) {
    CComQIPtr<>(&local_24,*(undefined4 **)pOVar2);
    if (local_24 != (int *)0x0) {
      param_2 = (BSTR)0x0;
      local_8._0_1_ = 0x10;
      local_8._1_3_ = 0;
      uVar4 = (**(code **)(*local_24 + 0x168))(local_24,&param_2);
      if ((-1 < (int)uVar4) && (UVar8 = SysStringLen(param_2), UVar8 != 0)) {
        local_28 = (BSTR)0x0;
        param_1 = (BSTR)0x0;
        local_8 = CONCAT31(local_8._1_3_,0x12);
        uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_Checksum_6815fee8,(int *)&local_28);
        if (-1 < (int)uVar4) {
          if (local_28 != (BSTR)0x0) {
            uVar4 = (**(code **)(*(int *)local_28 + 0x44))(local_28,&param_1);
          }
          if (-1 < (int)uVar4) {
            if (param_1 != (BSTR)0x0) {
              FUN_68132710((uint *)local_38,0,0x10);
              VariantInit((VARIANTARG *)&((_union_2683 *)local_38)->n2);
              local_38._8_4_ = (BSTR)0x0;
              local_38._0_2_ = 8;
              local_8 = CONCAT31(local_8._1_3_,0x13);
              uVar4 = (**(code **)(*local_24 + 0x160))(local_24,&local_20);
              if (-1 < (int)uVar4) {
                pOVar5 = (OLECHAR *)FUN_6812eaa7((int)local_20);
                local_38._8_4_ = SysAllocString(pOVar5);
                uVar4 = FUN_681021f5((undefined4 *)pOVar1,&param_1,PTR_DAT_681600cc,
                                     (undefined4 *)local_38);
              }
              local_8 = CONCAT31(local_8._1_3_,0x12);
              VariantClear((VARIANTARG *)&((_union_2683 *)local_38)->n2);
            }
            if ((-1 < (int)uVar4) && (UVar8 = SysStringLen(param_2), UVar8 != 0)) {
              uVar4 = FUN_6810226e((int *)pOVar1,&local_28,PTR_u_Type_6815fef8,param_2);
            }
          }
        }
        local_8._0_1_ = 0x11;
        if (param_1 != (BSTR)0x0) {
          (**(code **)(*(int *)param_1 + 8))(param_1);
        }
        local_8._0_1_ = 0x10;
        if (local_28 != (BSTR)0x0) {
          (**(code **)(*(int *)local_28 + 8))(local_28);
        }
      }
      SysFreeString(param_2);
    }
    local_8 = 0xffffffff;
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))(local_24);
    }
    if (((-1 < (int)uVar4) &&
        (uVar4 = (**(code **)(**(int **)pOVar2 + 0x28))(*(int **)pOVar2,&local_1c), -1 < (int)uVar4)
        ) && (local_1c != 0)) {
      if (local_1c == 1) {
        param_2 = (BSTR)0x0;
        local_8 = 0x14;
        uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_SrcField_6815fd4c,(int *)&param_2);
        pOVar11 = param_2;
        if (-1 < (int)uVar4) {
          uVar4 = FUN_6812b98e((int *)pOVar1,(undefined4 *)pOVar2,&param_2);
          pOVar11 = param_2;
        }
      }
      else if (local_1c == 2) {
        param_2 = (BSTR)0x0;
        local_8 = 0x15;
        uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_SrcData_6815fd50,(int *)&param_2);
        pOVar11 = param_2;
        if (-1 < (int)uVar4) {
          uVar4 = FUN_6812b7e4(local_14,(int *)pOVar1,(int *)pOVar2,(BSTR)&param_2);
          pOVar11 = param_2;
        }
      }
      else if (local_1c == 3) {
        param_2 = (BSTR)0x0;
        local_8 = 0x16;
        uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_VarText_6815fd54,(int *)&param_2);
        pOVar11 = param_2;
        if (-1 < (int)uVar4) {
          uVar4 = FUN_6812d7a8((int *)pOVar1,pOVar2,&param_2);
          pOVar11 = param_2;
        }
      }
      else if (local_1c == 4) {
        param_2 = (BSTR)0x0;
        local_8 = 0x17;
        uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_OffsetDate_6815fd58,(int *)&param_2)
        ;
        pOVar11 = param_2;
        if (-1 < (int)uVar4) {
          uVar4 = FUN_6812a724((undefined4 *)pOVar1,(undefined4 *)pOVar2,&param_2);
          pOVar11 = param_2;
        }
      }
      else if (local_1c == 5) {
        param_2 = (BSTR)0x0;
        local_8 = 0x18;
        uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_CounterText_6815fd5c,(int *)&param_2
                            );
        pOVar11 = param_2;
        if (-1 < (int)uVar4) {
          uVar4 = FUN_681261df(pOVar1,(undefined4 *)pOVar2,&param_2);
          pOVar11 = param_2;
        }
      }
      else {
        if (local_1c != 8) {
          return uVar4;
        }
        local_28 = (BSTR)0x0;
        local_8 = 0x19;
        uVar4 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_CLARICOMSSCC_68160000,
                             (int *)&local_28);
        pOVar11 = local_28;
      }
      local_8 = 0xffffffff;
      if (pOVar11 != (BSTR)0x0) {
        (**(code **)(*(int *)pOVar11 + 8))(pOVar11);
      }
    }
  }
  return uVar4;
}



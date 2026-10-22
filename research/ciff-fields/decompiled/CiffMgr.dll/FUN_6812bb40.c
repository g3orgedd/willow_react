// Source: CiffMgr.dll @ 6812bb40; FUN_6812bb40

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_6812bb40(int *param_1,BSTR param_2,undefined4 *param_3)

{
  int *piVar1;
  BSTR pOVar2;
  bool bVar3;
  uint uVar4;
  OLECHAR *pOVar5;
  uint uVar6;
  short *psVar7;
  undefined *puVar8;
  UINT UVar9;
  _union_2683 local_2c;
  int local_1c;
  void *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  uVar4 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  pOVar2 = param_2;
  piVar1 = param_1;
  if ((-1 < (int)uVar4) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)&local_2c,0,0x10);
    VariantInit((VARIANTARG *)&local_2c.n2);
    local_2c._8_4_ = (BSTR)0x0;
    local_2c.n2.vt = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar4 = (**(code **)(**(int **)pOVar2 + 0x1c))(*(int **)pOVar2,&param_1);
    if (-1 < (int)uVar4) {
      pOVar5 = FUN_6812f174(local_18,(int)param_1);
      local_2c._8_4_ = SysAllocString(pOVar5);
      uVar4 = FUN_681021f5(piVar1,local_14,PTR_u_Significance_68160064,(undefined4 *)&local_2c);
      if (-1 < (int)uVar4) {
        uVar4 = (**(code **)(**(int **)pOVar2 + 0x24))(*(int **)pOVar2,&param_2);
        if (-1 < (int)uVar4) {
          if (param_2 != (BSTR)0x0) {
            SysFreeString((BSTR)local_2c._8_4_);
            pOVar5 = (OLECHAR *)FUN_6812e9d1((int)param_2);
            local_2c._8_4_ = SysAllocString(pOVar5);
            uVar4 = FUN_681021f5(piVar1,local_14,PTR_u_AlphaNum_68160068,(undefined4 *)&local_2c);
          }
          if (-1 < (int)uVar4) {
            uVar4 = (**(code **)(**(int **)pOVar2 + 0x2c))(*(int **)pOVar2,&param_2);
            if (-1 < (int)uVar4) {
              if ((short)param_2 != 0x30) {
                SysFreeString((BSTR)local_2c._8_4_);
                local_2c._8_4_ = SysAllocStringLen((OLECHAR *)&param_2,1);
                uVar4 = FUN_681021f5(piVar1,local_14,PTR_u_LeadChar_6816006c,(undefined4 *)&local_2c
                                    );
              }
              if (-1 < (int)uVar4) {
                uVar4 = (**(code **)(**(int **)pOVar2 + 0x90))(*(int **)pOVar2,&param_2);
                uVar6 = (**(code **)(**(int **)pOVar2 + 0x98))(*(int **)pOVar2,&local_1c);
                uVar4 = uVar4 | uVar6;
                if ((-1 < (int)uVar4) && (param_2 != (BSTR)0x0)) {
                  SysFreeString((BSTR)local_2c._8_4_);
                  pOVar5 = (OLECHAR *)FUN_6812f037(local_1c);
                  local_2c._8_4_ = SysAllocString(pOVar5);
                  uVar4 = FUN_681021f5(piVar1,local_14,PTR_u_Global_681600d4,(undefined4 *)&local_2c
                                      );
                }
              }
            }
          }
        }
      }
    }
    VariantClear((VARIANTARG *)&local_2c.n2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  if (-1 < (int)uVar4) {
    uVar4 = (**(code **)(**(int **)pOVar2 + 0x34))(*(int **)pOVar2,&param_1);
    if (-1 < (int)uVar4) {
      psVar7 = FUN_6812f174(local_18,(int)param_1);
      uVar4 = FUN_6810248f(piVar1,param_3,PTR_u_NoOfChars_6815fd6c,psVar7);
      if (-1 < (int)uVar4) {
        uVar4 = (**(code **)(**(int **)pOVar2 + 0x3c))(*(int **)pOVar2,&param_1);
        if (-1 < (int)uVar4) {
          if (param_1 != (int *)0x1) {
            puVar8 = FUN_6812e9d1((int)param_1);
            uVar4 = FUN_6810248f(piVar1,param_3,PTR_u_LeadingChars_6815fd98,puVar8);
          }
          if (-1 < (int)uVar4) {
            param_2 = (BSTR)0x0;
            local_8 = 2;
            uVar4 = (**(code **)(**(int **)pOVar2 + 0x44))(*(int **)pOVar2,&param_2);
            if (-1 < (int)uVar4) {
              bVar3 = FUN_68119d18(&param_2,L"0");
              if (!bVar3) {
                uVar4 = FUN_6810226e(piVar1,param_3,PTR_u_StartVal_6815fd9c,param_2);
              }
            }
            local_8 = 0xffffffff;
            SysFreeString(param_2);
            if (-1 < (int)uVar4) {
              param_2 = (BSTR)0x0;
              local_8 = 3;
              uVar4 = (**(code **)(**(int **)pOVar2 + 0x4c))(*(int **)pOVar2,&param_2);
              if (-1 < (int)uVar4) {
                bVar3 = FUN_68119d18(&param_2,L"9999");
                if (!bVar3) {
                  uVar4 = FUN_6810226e(piVar1,param_3,PTR_u_EndVal_6815fda0,param_2);
                }
              }
              local_8 = 0xffffffff;
              SysFreeString(param_2);
              if (-1 < (int)uVar4) {
                uVar4 = (**(code **)(**(int **)pOVar2 + 0x5c))(*(int **)pOVar2,&param_1);
                if (-1 < (int)uVar4) {
                  if (param_1 != (int *)0x1) {
                    psVar7 = FUN_6812f174(local_18,(int)param_1);
                    uVar4 = FUN_6810248f(piVar1,param_3,PTR_u_StepSize_6815fda4,psVar7);
                  }
                  if (-1 < (int)uVar4) {
                    param_2 = (BSTR)0x0;
                    local_8 = 4;
                    uVar4 = (**(code **)(**(int **)pOVar2 + 0x54))(*(int **)pOVar2,&param_2);
                    if (-1 < (int)uVar4) {
                      UVar9 = SysStringLen(param_2);
                      if (UVar9 != 0) {
                        uVar4 = FUN_6810226e(piVar1,param_3,PTR_u_CurrVal_6815fda8,param_2);
                      }
                    }
                    local_8 = 0xffffffff;
                    SysFreeString(param_2);
                    if (-1 < (int)uVar4) {
                      param_2 = (BSTR)0x0;
                      local_8 = 5;
                      uVar4 = (**(code **)(**(int **)pOVar2 + 100))(*(int **)pOVar2,&param_2);
                      if (-1 < (int)uVar4) {
                        bVar3 = FUN_68119d18(&param_2,L"0-9");
                        if (!bVar3) {
                          uVar4 = FUN_6810226e(piVar1,param_3,PTR_u_IncableChars_6815fdac,param_2);
                        }
                      }
                      local_8 = 0xffffffff;
                      SysFreeString(param_2);
                      if (-1 < (int)uVar4) {
                        param_2 = (BSTR)0x0;
                        local_8 = 6;
                        uVar4 = (**(code **)(**(int **)pOVar2 + 0x6c))(*(int **)pOVar2,&param_2);
                        if (-1 < (int)uVar4) {
                          UVar9 = SysStringLen(param_2);
                          if (UVar9 != 0) {
                            uVar4 = FUN_6810226e(piVar1,param_3,PTR_u_Prompt_6815fc78,param_2);
                          }
                        }
                        local_8 = 0xffffffff;
                        SysFreeString(param_2);
                        if (-1 < (int)uVar4) {
                          param_2 = (BSTR)0x0;
                          local_8 = 7;
                          uVar4 = (**(code **)(**(int **)pOVar2 + 0x74))(*(int **)pOVar2,&param_2);
                          if (-1 < (int)uVar4) {
                            uVar4 = FUN_6810248f(piVar1,param_3,PTR_u_ClrStCntType_6815fdb0,param_2)
                            ;
                          }
                          SysFreeString(param_2);
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
  return uVar4;
}



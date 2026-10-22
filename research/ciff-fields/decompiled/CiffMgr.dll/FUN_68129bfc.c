// Source: CiffMgr.dll @ 68129bfc; FUN_68129bfc

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68129bfc(BSTR param_1,BSTR param_2,undefined4 *param_3)

{
  BSTR pOVar1;
  BSTR pOVar2;
  int iVar3;
  int iVar4;
  OLECHAR *psz;
  undefined *puVar5;
  short *psVar6;
  UINT UVar7;
  wchar_t *pwVar8;
  _union_2683 local_34;
  int local_24;
  int *local_20;
  undefined4 local_1c;
  int *piStack_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  piStack_18 = (int *)0x0;
  local_8 = 0;
  iVar3 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&piStack_18);
  pOVar2 = param_2;
  pOVar1 = param_1;
  if ((-1 < iVar3) && (piStack_18 != (int *)0x0)) {
    FUN_68132710((uint *)&local_34,0,0x10);
    VariantInit((VARIANTARG *)&local_34.n2);
    local_34._8_4_ = (wchar_t *)0x0;
    local_34.n2.vt = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar3 = (**(code **)(**(int **)pOVar2 + 0x44))(*(int **)pOVar2);
    if (-1 < iVar3) {
      if (((wchar_t *)local_34._8_4_ == (wchar_t *)0x0) ||
         (iVar4 = _wcscmp((wchar_t *)local_34._8_4_,L"Generic"), iVar4 != 0)) {
        iVar3 = FUN_681021f5((undefined4 *)pOVar1,&piStack_18,PTR_u_DesignedFor_68160024,
                             (undefined4 *)&local_34);
      }
      if (-1 < iVar3) {
        SysFreeString((BSTR)local_34._8_4_);
        local_34._8_4_ = (wchar_t *)0x0;
        iVar3 = (**(code **)(**(int **)pOVar2 + 0x4c))(*(int **)pOVar2);
        if (-1 < iVar3) {
          if (((wchar_t *)local_34._8_4_ == (wchar_t *)0x0) ||
             (iVar4 = _wcscmp((wchar_t *)local_34._8_4_,L"CLARiSOFT"), iVar4 != 0)) {
            iVar3 = FUN_681021f5((undefined4 *)pOVar1,&piStack_18,PTR_u_DesignedWith_68160028,
                                 (undefined4 *)&local_34);
          }
          if (-1 < iVar3) {
            iVar3 = (**(code **)(**(int **)pOVar2 + 0x68))(*(int **)pOVar2);
            if ((-1 < iVar3) && (iVar3 != 0)) {
              SysFreeString((BSTR)local_34._8_4_);
              psz = (OLECHAR *)FUN_6812e9d1((int)param_2);
              local_34._8_4_ = SysAllocString(psz);
              iVar3 = FUN_681021f5((undefined4 *)pOVar1,&piStack_18,PTR_u_OverrideAll_6816002c,
                                   (undefined4 *)&local_34);
            }
          }
        }
      }
    }
    VariantClear((VARIANTARG *)&local_34.n2);
  }
  local_8 = 0xffffffff;
  if (piStack_18 != (int *)0x0) {
    (**(code **)(*piStack_18 + 8))();
  }
  if ((-1 < iVar3) && (iVar3 = (**(code **)(**(int **)pOVar2 + 0x54))(*(int **)pOVar2), -1 < iVar3))
  {
    if (param_2 != (BSTR)0x0) {
      puVar5 = FUN_6812fb33((int)param_2);
      iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Units_6815fc4c,puVar5);
    }
    if ((-1 < iVar3) &&
       (iVar3 = (**(code **)(**(int **)pOVar2 + 0x70))(*(int **)pOVar2), -1 < iVar3)) {
      if (param_2 != (BSTR)0x0) {
        psVar6 = FUN_6812f174(local_14,(int)param_2);
        iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_ErrorLeniency_6815fc50,psVar6);
      }
      if (-1 < iVar3) {
        param_2 = (BSTR)0x0;
        local_8 = 2;
        iVar3 = (**(code **)(**(int **)pOVar2 + 0x78))(*(int **)pOVar2);
        if ((-1 < iVar3) && (UVar7 = SysStringLen(param_2), UVar7 != 0)) {
          iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_ClStVersionInfo_6815fc54,param_2);
        }
        local_8 = 0xffffffff;
        SysFreeString(param_2);
        if ((-1 < iVar3) &&
           (iVar3 = (**(code **)(**(int **)pOVar2 + 0x90))(*(int **)pOVar2), -1 < iVar3)) {
          if ((double)CONCAT44(piStack_18,local_1c) != 0.0) {
            pwVar8 = FUN_6812eef6(local_14,CONCAT44(piStack_18,local_1c));
            iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_LastDownloaded_6815fc58,pwVar8);
          }
          if (-1 < iVar3) {
            CComQIPtr<>(&param_2,*(undefined4 **)pOVar2);
            local_8 = 3;
            if (((param_2 != (BSTR)0x0) &&
                (iVar3 = (**(code **)(*(int *)param_2 + 0xc0))(param_2), -1 < iVar3)) &&
               (param_1 != (BSTR)0xffffffff)) {
              psVar6 = FUN_6812f174(local_14,(int)param_1);
              iVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_LineID_6815ff44,psVar6);
            }
            local_8 = 0xffffffff;
            if (param_2 != (BSTR)0x0) {
              (**(code **)(*(int *)param_2 + 8))();
            }
            if (-1 < iVar3) {
              param_2 = (BSTR)0x0;
              local_8 = 4;
              FUN_68132710((uint *)&local_34,0,0x10);
              VariantInit((VARIANTARG *)&local_34.n2);
              local_8 = CONCAT31(local_8._1_3_,5);
              iVar3 = (**(code **)(**(int **)pOVar2 + 100))();
              if ((-1 < iVar3) && (local_34.n2.vt == 9)) {
                iVar3 = (*(code *)**(undefined4 **)local_34._8_4_)(local_34._8_4_,&DAT_681487b8);
              }
              local_8 = CONCAT31(local_8._1_3_,4);
              VariantClear((VARIANTARG *)&local_34.n2);
              if (((-1 < iVar3) && (param_2 != (BSTR)0x0)) &&
                 ((iVar3 = (**(code **)(*(int *)param_2 + 0x1c))(param_2), -1 < iVar3 &&
                  (0 < (int)param_1)))) {
                FUN_681282c3(pOVar1,&param_2,param_3);
              }
              local_8 = 0xffffffff;
              if (param_2 != (BSTR)0x0) {
                (**(code **)(*(int *)param_2 + 8))();
              }
              if (-1 < iVar3) {
                param_2 = (BSTR)0x0;
                local_8 = 6;
                FUN_68132710((uint *)&local_34,0,0x10);
                VariantInit((VARIANTARG *)&local_34.n2);
                CComQIPtr<>(&param_1,*(undefined4 **)pOVar2);
                local_8._0_1_ = 8;
                if (((param_1 != (BSTR)0x0) &&
                    (iVar3 = (**(code **)(*(int *)param_1 + 0xb4))(), -1 < iVar3)) &&
                   (local_34.n2.vt == 9)) {
                  iVar3 = (*(code *)**(undefined4 **)local_34._8_4_)(local_34._8_4_,&DAT_681489dc);
                }
                local_8._0_1_ = 7;
                if (param_1 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_1 + 8))();
                }
                local_8 = CONCAT31(local_8._1_3_,6);
                VariantClear((VARIANTARG *)&local_34.n2);
                if (((-1 < iVar3) && (param_2 != (BSTR)0x0)) &&
                   ((iVar3 = (**(code **)(*(int *)param_2 + 0x1c))(param_2), -1 < iVar3 &&
                    (0 < (int)param_1)))) {
                  FUN_6812b61a((int *)pOVar1,&param_2,param_3);
                }
                local_8 = 0xffffffff;
                if (param_2 != (BSTR)0x0) {
                  (**(code **)(*(int *)param_2 + 8))();
                }
                if (-1 < iVar3) {
                  CComQIPtr<>(&local_20,*(undefined4 **)pOVar2);
                  local_8 = 9;
                  FUN_68132710((uint *)&local_34,0,0x10);
                  VariantInit((VARIANTARG *)&local_34.n2);
                  local_8._0_1_ = 10;
                  iVar3 = (**(code **)(*local_20 + 0xcc))(local_20);
                  if (((-1 < iVar3) && (local_34.n2.vt == 9)) && ((BSTR)local_34._8_4_ != (BSTR)0x0)
                     ) {
                    CComQIPtr<>(&param_1,(undefined4 *)local_34._8_4_);
                    local_8._0_1_ = 0xb;
                    iVar3 = (**(code **)(*(int *)param_1 + 0x1c))(param_1);
                    if ((-1 < iVar3) && (0 < local_24)) {
                      param_2 = param_1;
                      if (param_1 != (BSTR)0x0) {
                        (**(code **)(*(int *)param_1 + 4))();
                      }
                      local_8._0_1_ = 0xc;
                      iVar3 = FUN_68127437((undefined4 *)pOVar1,&param_2,param_3);
                      local_8._0_1_ = 0xb;
                      if (param_2 != (BSTR)0x0) {
                        (**(code **)(*(int *)param_2 + 8))();
                      }
                    }
                    local_8._0_1_ = 10;
                    if (param_1 != (BSTR)0x0) {
                      (**(code **)(*(int *)param_1 + 8))();
                    }
                  }
                  VariantClear((VARIANTARG *)&local_34.n2);
                  local_8 = 0xffffffff;
                  if (local_20 != (int *)0x0) {
                    (**(code **)(*local_20 + 8))();
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return iVar3;
}



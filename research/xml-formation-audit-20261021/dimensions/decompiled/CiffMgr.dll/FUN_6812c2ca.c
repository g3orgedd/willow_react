// Source: CiffMgr.dll @ 6812c2ca; FUN_6812c2ca

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812c2ca(int *param_1,int *param_2,undefined4 *param_3,void *param_4)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  UINT UVar5;
  short *psVar6;
  OLECHAR *pOVar7;
  undefined *puVar8;
  wchar_t *pwVar9;
  int **ppiVar10;
  _union_2683 local_34;
  int local_24;
  int local_20;
  float local_1c;
  int *local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_18 = (int *)0x0;
  local_8 = 0;
  iVar4 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_18);
  piVar2 = param_2;
  piVar1 = param_1;
  if ((-1 < iVar4) && (local_18 != (int *)0x0)) {
    FUN_68132710((uint *)&local_34,0,0x10);
    VariantInit((VARIANTARG *)&local_34.n2);
    local_34._8_4_ = (BSTR)0x0;
    local_34.n2.vt = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar4 = (**(code **)(*(int *)*piVar2 + 0x4c))((int *)*piVar2);
    if ((-1 < iVar4) &&
       (((BSTR)local_34._8_4_ != (BSTR)0x0 &&
        (UVar5 = SysStringLen((BSTR)local_34._8_4_), UVar5 != 0)))) {
      iVar4 = FUN_681021f5(piVar1,&local_18,PTR_u_FormatName_68160048,(undefined4 *)&local_34);
    }
    VariantClear((VARIANTARG *)&local_34.n2);
    FUN_68132710((uint *)&local_34,0,0x10);
    VariantInit((VARIANTARG *)&local_34.n2);
    local_34._8_4_ = (BSTR)0x0;
    local_34.n2.vt = 8;
    CComQIPtr<>(&param_2,(undefined4 *)*piVar2);
    local_8._0_1_ = 3;
    if ((((param_2 != (int *)0x0) && (iVar4 = (**(code **)(*param_2 + 0x9c))(param_2), -1 < iVar4))
        && ((BSTR)local_34._8_4_ != (BSTR)0x0)) &&
       ((UVar5 = SysStringLen((BSTR)local_34._8_4_), UVar5 != 0 &&
        (bVar3 = FUN_68119d18(param_4,(OLECHAR *)local_34._8_4_), !bVar3)))) {
      iVar4 = FUN_681021f5(piVar1,&local_18,PTR_u_PrinterType_6816004c,(undefined4 *)&local_34);
    }
    local_8._0_1_ = 2;
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))();
    }
    VariantClear((VARIANTARG *)&local_34.n2);
    FUN_68132710((uint *)&local_34,0,0x10);
    VariantInit((VARIANTARG *)&local_34.n2);
    local_34._8_4_ = (BSTR)0x0;
    local_34.n2.vt = 8;
    CComQIPtr<>(&param_2,(undefined4 *)*piVar2);
    local_8._0_1_ = 5;
    if (((param_2 != (int *)0x0) && (iVar4 = (**(code **)(*param_2 + 0xcc))(param_2), -1 < iVar4))
       && (((BSTR)local_34._8_4_ != (BSTR)0x0 &&
           (UVar5 = SysStringLen((BSTR)local_34._8_4_), UVar5 != 0)))) {
      iVar4 = FUN_681021f5(piVar1,&local_18,PTR_u_PrinterFormatName_681600e8,(undefined4 *)&local_34
                          );
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (param_2 != (int *)0x0) {
      (**(code **)(*param_2 + 8))();
    }
    VariantClear((VARIANTARG *)&local_34.n2);
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))();
  }
  if ((-1 < iVar4) && (iVar4 = (**(code **)(*(int *)*piVar2 + 0x3c))((int *)*piVar2), -1 < iVar4)) {
    psVar6 = FUN_6812f174(local_14,(int)param_2);
    iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_ImageWidth_6815fcb8,psVar6);
    if ((-1 < iVar4) && (iVar4 = (**(code **)(*(int *)*piVar2 + 0x44))((int *)*piVar2), -1 < iVar4))
    {
      psVar6 = FUN_6812f174(local_14,(int)param_2);
      iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_ImageHeight_6815fcbc,psVar6);
      if (-1 < iVar4) {
        CComQIPtr<>(&param_1,(undefined4 *)*piVar2);
        local_8 = 6;
        if ((((param_1 != (int *)0x0) &&
             (iVar4 = (**(code **)(*param_1 + 0x54))(param_1), -1 < iVar4)) &&
            (iVar4 = (**(code **)(*param_1 + 0xe4))(param_1), -1 < iVar4)) &&
           ((iVar4 = (**(code **)(*param_1 + 0xc4))(param_1), -1 < iVar4 &&
            ((param_4 != (void *)0x0 || (local_20 != 0)))))) {
          local_18 = (int *)0x0;
          ppiVar10 = &local_18;
          local_8._0_1_ = 7;
          psVar6 = FUN_6812f174(local_14,local_24);
          iVar4 = FUN_681023dc(piVar1,param_3,PTR_u_ImageRotation_6815fcc0,psVar6,ppiVar10);
          if ((-1 < iVar4) && (param_4 != (void *)0x0)) {
            param_2 = (int *)0x0;
            local_8._0_1_ = 8;
            iVar4 = (**(code **)(*local_18 + 0x44))(local_18);
            if ((-1 < iVar4) && (param_2 != (int *)0x0)) {
              FUN_68132710((uint *)&local_34,0,0x10);
              VariantInit((VARIANTARG *)&local_34.n2);
              local_8._0_1_ = 9;
              local_34.n2.vt = 8;
              pOVar7 = (OLECHAR *)FUN_6812e9d1((int)param_4);
              local_34._8_4_ = SysAllocString(pOVar7);
              iVar4 = FUN_681021f5(piVar1,&param_2,PTR_u_Enabled_681600e4,(undefined4 *)&local_34);
              VariantClear((VARIANTARG *)&local_34.n2);
            }
            local_8._0_1_ = 7;
            if (param_2 != (int *)0x0) {
              (**(code **)(*param_2 + 8))();
            }
          }
          local_8 = CONCAT31(local_8._1_3_,6);
          if (local_18 != (int *)0x0) {
            (**(code **)(*local_18 + 8))();
          }
        }
        local_8 = 0xffffffff;
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))();
        }
        if ((-1 < iVar4) &&
           (iVar4 = (**(code **)(*(int *)*piVar2 + 0x5c))((int *)*piVar2), -1 < iVar4)) {
          psVar6 = FUN_6812f174(local_14,(int)param_2);
          iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_MaxImageWidth_6815fcc4,psVar6);
          if ((-1 < iVar4) &&
             (iVar4 = (**(code **)(*(int *)*piVar2 + 100))((int *)*piVar2), -1 < iVar4)) {
            psVar6 = FUN_6812f174(local_14,(int)param_2);
            iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_MaxImageHeight_6815fcc8,psVar6);
            if (-1 < iVar4) {
              CComQIPtr<>(&param_2,(undefined4 *)*piVar2);
              local_8 = 10;
              if (((param_2 != (int *)0x0) &&
                  (iVar4 = (**(code **)(*param_2 + 0xa4))(param_2), -1 < iVar4)) &&
                 (param_1 != (int *)0x0)) {
                puVar8 = FUN_6812e9d1((int)param_1);
                iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_AutoSize_6815ff94,puVar8);
              }
              local_8 = 0xffffffff;
              if (param_2 != (int *)0x0) {
                (**(code **)(*param_2 + 8))();
              }
              if (-1 < iVar4) {
                CComQIPtr<>(&param_1,(undefined4 *)*piVar2);
                local_8 = 0xb;
                if ((((param_1 != (int *)0x0) &&
                     (iVar4 = (**(code **)(*param_1 + 0xac))(param_1), -1 < iVar4)) &&
                    ((iVar4 = (**(code **)(*param_1 + 0xdc))(param_1), -1 < iVar4 &&
                     (iVar4 = (**(code **)(*param_1 + 0xbc))(param_1), -1 < iVar4)))) &&
                   ((param_4 != (void *)0x0 || (local_24 != 0)))) {
                  local_18 = (int *)0x0;
                  ppiVar10 = &local_18;
                  local_8._0_1_ = 0xc;
                  puVar8 = FUN_6812e9d1(local_20);
                  iVar4 = FUN_681023dc(piVar1,param_3,PTR_u_ImageMirror_6815ff98,puVar8,ppiVar10);
                  if ((-1 < iVar4) && (param_4 != (void *)0x0)) {
                    param_2 = (int *)0x0;
                    local_8._0_1_ = 0xd;
                    iVar4 = (**(code **)(*local_18 + 0x44))(local_18);
                    if ((-1 < iVar4) && (param_2 != (int *)0x0)) {
                      FUN_68132710((uint *)&local_34,0,0x10);
                      VariantInit((VARIANTARG *)&local_34.n2);
                      local_8._0_1_ = 0xe;
                      local_34.n2.vt = 8;
                      pOVar7 = (OLECHAR *)FUN_6812e9d1((int)param_4);
                      local_34._8_4_ = SysAllocString(pOVar7);
                      iVar4 = FUN_681021f5(piVar1,&param_2,PTR_u_Enabled_681600e4,
                                           (undefined4 *)&local_34);
                      VariantClear((VARIANTARG *)&local_34.n2);
                    }
                    local_8._0_1_ = 0xc;
                    if (param_2 != (int *)0x0) {
                      (**(code **)(*param_2 + 8))();
                    }
                  }
                  local_8 = CONCAT31(local_8._1_3_,0xb);
                  if (local_18 != (int *)0x0) {
                    (**(code **)(*local_18 + 8))();
                  }
                }
                local_8 = 0xffffffff;
                if (param_1 != (int *)0x0) {
                  (**(code **)(*param_1 + 8))();
                }
                if (-1 < iVar4) {
                  CComQIPtr<>(&param_2,(undefined4 *)*piVar2);
                  local_8 = 0xf;
                  if (((param_2 != (int *)0x0) &&
                      (iVar4 = (**(code **)(*param_2 + 0xb4))(param_2), -1 < iVar4)) &&
                     (param_1 != (int *)0x0)) {
                    puVar8 = FUN_6812e9d1((int)param_1);
                    iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_ImageInverse_6815ff9c,puVar8);
                  }
                  local_8 = 0xffffffff;
                  if (param_2 != (int *)0x0) {
                    (**(code **)(*param_2 + 8))();
                  }
                  if ((-1 < iVar4) &&
                     (iVar4 = (**(code **)(*(int *)*piVar2 + 0x6c))((int *)*piVar2,&local_1c),
                     -1 < iVar4)) {
                    pwVar9 = FUN_6812eef6(local_14,(double)local_1c);
                    iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_XRes_6815fccc,pwVar9);
                    if ((-1 < iVar4) &&
                       (iVar4 = (**(code **)(*(int *)*piVar2 + 0x74))((int *)*piVar2), -1 < iVar4))
                    {
                      if ((float)param_2 != local_1c) {
                        pwVar9 = FUN_6812eef6(local_14,(double)(float)param_2);
                        iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_YRes_6815fcd0,pwVar9);
                      }
                      if (-1 < iVar4) {
                        CComQIPtr<>(&param_2,(undefined4 *)*piVar2);
                        local_8 = 0x10;
                        if (((param_2 != (int *)0x0) &&
                            (iVar4 = (**(code **)(*param_2 + 0xd4))(param_2), -1 < iVar4)) &&
                           (param_1 != (int *)0x0)) {
                          puVar8 = FUN_6812ebf4((int)param_1);
                          iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_CurrentOrientation_6815ffe4,
                                               puVar8);
                        }
                        local_8 = 0xffffffff;
                        if (param_2 != (int *)0x0) {
                          (**(code **)(*param_2 + 8))();
                        }
                        if (((-1 < iVar4) &&
                            (iVar4 = (**(code **)(*(int *)*piVar2 + 0x84))((int *)*piVar2,&param_4),
                            -1 < iVar4)) && ((float)param_4 != 0.0)) {
                          pwVar9 = FUN_6812eef6(local_14,(double)(float)param_4);
                          iVar4 = FUN_6810248f(piVar1,param_3,PTR_u_LastUpdated_6815fcd4,pwVar9);
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



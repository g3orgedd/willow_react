// Source: CiffMgr.dll @ 68121a2a; FUN_68121a2a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_68121a2a(int *param_1,
                CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
                *param_2,BSTR param_3,int *param_4,BSTR param_5)

{
  int *piVar1;
  int iVar2;
  BSTR pOVar3;
  undefined4 uVar4;
  BSTR bstrString;
  CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
  *pCVar5;
  BSTR bstrString_00;
  bool bVar6;
  float10 fVar7;
  _union_2683 local_58;
  _union_2683 local_48;
  BSTR local_38;
  BSTR local_34;
  BSTR local_30;
  BSTR local_2c;
  int *local_28;
  BSTR local_24;
  int *local_20;
  int *local_1c;
  BSTR local_18 [4];
  undefined1 local_8;
  undefined3 uStack_7;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  bstrString = (BSTR)0x0;
  local_2c = (BSTR)0x0;
  bstrString_00 = (BSTR)0x0;
  local_30 = (BSTR)0x0;
  local_18[0] = (BSTR)0x0;
  local_28 = (int *)0x0;
  local_20 = (int *)0x0;
  local_8 = 3;
  uStack_7 = 0;
  iVar2 = (**(code **)(**(int **)param_3 + 0x44))(*(int **)param_3,&local_20);
  if ((-1 < iVar2) && (local_20 != (int *)0x0)) {
    local_1c = (int *)0x0;
    _local_8 = CONCAT31(uStack_7,4);
    iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_u_FormatName_68160048,&local_1c);
    if ((-1 < iVar2) && (local_1c != (int *)0x0)) {
      (**(code **)(*local_1c + 0x20))(local_1c,&local_48);
      if (local_48.n2.vt == 8) {
        SysFreeString((BSTR)0x0);
        local_2c = (BSTR)0x0;
        local_38 = (BSTR)local_48._8_4_;
        if ((BSTR)local_48._8_4_ != (BSTR)0x0) {
          SysFreeString((BSTR)0x0);
          local_2c = local_38;
          bstrString = local_38;
        }
      }
      else {
        VariantClear((VARIANTARG *)&local_48.n2);
      }
    }
    local_8 = 3;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 8))(local_1c);
    }
    local_24 = (BSTR)0x0;
    _local_8 = CONCAT31(uStack_7,5);
    iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_u_PrinterType_6816004c,&local_24);
    if ((iVar2 < 0) || (local_24 == (BSTR)0x0)) {
      (**(code **)(*(int *)*param_1 + 0x44))((int *)*param_1,local_18);
    }
    else {
      (**(code **)(*(int *)local_24 + 0x20))(local_24,&local_48);
      if (local_48.n2.vt == 8) {
        SysFreeString(local_18[0]);
        local_18[0] = (BSTR)0x0;
        local_38 = (BSTR)local_48._8_4_;
        if ((BSTR)local_48._8_4_ != (BSTR)0x0) {
          SysFreeString((BSTR)0x0);
          local_18[0] = local_38;
        }
      }
      else {
        VariantClear((VARIANTARG *)&local_48.n2);
      }
    }
    local_8 = 3;
    if (local_24 != (BSTR)0x0) {
      (**(code **)(*(int *)local_24 + 8))(local_24);
    }
  }
  local_1c = (int *)0x0;
  _local_8 = CONCAT31(uStack_7,6);
  iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                    (*(int **)param_3,PTR_u_ImageWidth_6815fcb8,&local_1c);
  if (iVar2 == 0) {
    bVar6 = local_1c == (int *)0x0;
    if (!bVar6) {
      local_24 = (BSTR)0x0;
      iVar2 = (**(code **)(*local_1c + 0x68))(local_1c,&local_24);
      pOVar3 = param_3;
      if (-1 < iVar2) {
        pOVar3 = (BSTR)FUN_6812f116((ushort *)local_24);
      }
      local_38 = pOVar3;
      SysFreeString(local_24);
      local_8 = 3;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      local_1c = (int *)0x0;
      _local_8 = CONCAT31(uStack_7,7);
      iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                        (*(int **)param_3,PTR_u_ImageHeight_6815fcbc,&local_1c);
      if (iVar2 != 0) goto LAB_68122502;
      bVar6 = true;
      if (local_1c != (int *)0x0) {
        local_24 = (BSTR)0x0;
        iVar2 = (**(code **)(*local_1c + 0x68))(local_1c,&local_24);
        local_34 = param_3;
        if (-1 < iVar2) {
          local_34 = (BSTR)FUN_6812f116((ushort *)local_24);
        }
        SysFreeString(local_24);
        local_8 = 3;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_1c = (int *)0x0;
        _local_8 = CONCAT31(uStack_7,8);
        iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                          (*(int **)param_3,PTR_u_ImageRotation_6815fcc0,&local_1c);
        if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
          local_24 = (BSTR)0x0;
          iVar2 = (**(code **)(*local_1c + 0x68))(local_1c,&local_24);
          if (-1 < iVar2) {
            local_28 = (int *)FUN_6812f116((ushort *)local_24);
          }
          SysFreeString(local_24);
        }
        local_8 = 3;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        local_1c = (int *)0x0;
        _local_8 = CONCAT31(uStack_7,9);
        iVar2 = (**(code **)(*local_20 + 0x1c))(local_20,PTR_u_PrinterFormatName_681600e8,&local_1c)
        ;
        if ((-1 < iVar2) && (local_1c != (int *)0x0)) {
          (**(code **)(*local_1c + 0x20))(local_1c,&local_48);
          if (local_48.n2.vt == 8) {
            SysFreeString((BSTR)0x0);
            local_30 = (BSTR)0x0;
            local_24 = (BSTR)local_48._8_4_;
            bstrString_00 = (BSTR)0x0;
            if ((BSTR)local_48._8_4_ != (BSTR)0x0) {
              SysFreeString((BSTR)0x0);
              local_30 = local_24;
              bstrString_00 = local_24;
            }
          }
          else {
            VariantClear((VARIANTARG *)&local_48.n2);
          }
        }
        local_8 = 3;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
        FUN_68132710((uint *)&local_58,0,0x10);
        VariantInit((VARIANTARG *)&local_58.n2);
        local_8 = 10;
        iVar2 = (**(code **)(*(int *)*param_1 + 200))
                          ((int *)*param_1,*param_4,bstrString,local_38,local_34,local_28,param_5,
                           &local_58);
        pCVar5 = param_2;
        if ((-1 < iVar2) && (local_58.n2.vt == 9)) {
          ATL::
          CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
          ::operator=(param_2,(IUnknown *)local_58._8_4_);
          if (local_18[0] != (BSTR)0x0) {
            CComQIPtr<>(&param_4,*(undefined4 **)pCVar5);
            local_8 = 0xb;
            if (param_4 != (int *)0x0) {
              (**(code **)(*param_4 + 0xa0))(param_4,local_18[0]);
            }
            local_8 = 10;
            if (param_4 != (int *)0x0) {
              (**(code **)(*param_4 + 8))(param_4);
            }
          }
          param_4 = (int *)0x0;
          _local_8 = CONCAT31(uStack_7,0xc);
          iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                            (*(int **)param_3,PTR_u_MaxImageWidth_6815fcc4,&param_4);
          if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
            param_5 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
            if (-1 < iVar2) {
              piVar1 = *(int **)pCVar5;
              local_38 = (BSTR)(*piVar1 + 0x60);
              iVar2 = FUN_6812f116((ushort *)param_5);
              (**(code **)local_38)(piVar1,iVar2);
              pCVar5 = param_2;
            }
            SysFreeString(param_5);
          }
          local_8 = 10;
          if (param_4 != (int *)0x0) {
            (**(code **)(*param_4 + 8))(param_4);
          }
          param_4 = (int *)0x0;
          _local_8 = CONCAT31(uStack_7,0xd);
          iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                            (*(int **)param_3,PTR_u_MaxImageHeight_6815fcc8,&param_4);
          if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
            param_5 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
            if (-1 < iVar2) {
              piVar1 = *(int **)pCVar5;
              local_38 = (BSTR)(*piVar1 + 0x68);
              iVar2 = FUN_6812f116((ushort *)param_5);
              (**(code **)local_38)(piVar1,iVar2);
            }
            SysFreeString(param_5);
          }
          local_8 = 10;
          if (param_4 != (int *)0x0) {
            (**(code **)(*param_4 + 8))(param_4);
          }
          pCVar5 = param_2;
          CComQIPtr<>(&local_28,*(undefined4 **)param_2);
          if (local_28 != (int *)0x0) {
            param_4 = (int *)0x0;
            _local_8 = CONCAT31(uStack_7,0xf);
            iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                              (*(int **)param_3,PTR_u_AutoSize_6815ff94,&param_4);
            if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
              param_5 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
              piVar1 = local_28;
              if (-1 < iVar2) {
                local_38 = (BSTR)(*local_28 + 0xa8);
                uVar4 = FUN_6812e988(param_5);
                (**(code **)local_38)(piVar1,uVar4);
                pCVar5 = param_2;
              }
              SysFreeString(param_5);
            }
            local_8 = 0xe;
            if (param_4 != (int *)0x0) {
              (**(code **)(*param_4 + 8))(param_4);
            }
          }
          CComQIPtr<>(&param_1,*(undefined4 **)pCVar5);
          pOVar3 = param_3;
          local_8 = 0x10;
          if (param_1 == (int *)0x0) {
            (**(code **)(_DAT_00000000 + 0xe0))(0,0);
          }
          else {
            local_24 = (BSTR)0x0;
            local_8 = 0x11;
            iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                              (*(int **)param_3,PTR_u_ImageRotation_6815fcc0,&local_24);
            if ((iVar2 == 0) && (local_24 != (BSTR)0x0)) {
              (**(code **)(*param_1 + 0xe8))(param_1,1);
              param_5 = (BSTR)0x0;
              local_8 = 0x12;
              iVar2 = (**(code **)(*(int *)local_24 + 0x44))(local_24,&param_5);
              if ((iVar2 == 0) && (param_5 != (BSTR)0x0)) {
                param_4 = (int *)0x0;
                local_8 = 0x13;
                iVar2 = (**(code **)(*(int *)param_5 + 0x1c))
                                  (param_5,PTR_u_Enabled_681600e4,&param_4);
                if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
                  FUN_68132710((uint *)&local_48,0,0x10);
                  VariantInit((VARIANTARG *)&local_48.n2);
                  local_8 = 0x14;
                  (**(code **)(*param_4 + 0x20))(param_4,&local_48);
                  piVar1 = param_1;
                  if (local_48.n2.vt == 8) {
                    local_38 = (BSTR)(*param_1 + 200);
                    uVar4 = FUN_6812e988((wchar_t *)local_48._8_4_);
                    (**(code **)local_38)(piVar1,uVar4);
                    pOVar3 = param_3;
                  }
                  VariantClear((VARIANTARG *)&local_48.n2);
                }
                local_8 = 0x12;
                if (param_4 != (int *)0x0) {
                  (**(code **)(*param_4 + 8))(param_4);
                }
              }
              local_8 = 0x11;
              if (param_5 != (BSTR)0x0) {
                (**(code **)(*(int *)param_5 + 8))(param_5);
              }
            }
            else {
              (**(code **)(*param_1 + 0xe8))(param_1,0);
            }
            param_4 = (int *)0x0;
            _local_8 = CONCAT31(uStack_7,0x15);
            iVar2 = (**(code **)(**(int **)pOVar3 + 0x94))
                              (*(int **)pOVar3,PTR_u_ImageMirror_6815ff98,&param_4);
            if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
              param_5 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
              piVar1 = param_1;
              if (-1 < iVar2) {
                local_38 = (BSTR)(*param_1 + 0xb0);
                uVar4 = FUN_6812e988(param_5);
                (**(code **)local_38)(piVar1,uVar4);
                pOVar3 = param_3;
              }
              SysFreeString(param_5);
            }
            local_8 = 0x11;
            if (param_4 != (int *)0x0) {
              (**(code **)(*param_4 + 8))(param_4);
            }
            local_1c = (int *)0x0;
            local_8 = 0x16;
            iVar2 = (**(code **)(**(int **)pOVar3 + 0x94))
                              (*(int **)pOVar3,PTR_u_ImageMirror_6815ff98,&local_1c);
            if ((iVar2 == 0) && (local_1c != (int *)0x0)) {
              (**(code **)(*param_1 + 0xe0))(param_1,1);
              param_5 = (BSTR)0x0;
              local_8 = 0x17;
              iVar2 = (**(code **)(*local_1c + 0x44))(local_1c,&param_5);
              if ((iVar2 == 0) && (param_5 != (BSTR)0x0)) {
                param_4 = (int *)0x0;
                local_8 = 0x18;
                iVar2 = (**(code **)(*(int *)param_5 + 0x1c))
                                  (param_5,PTR_u_Enabled_681600e4,&param_4);
                if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
                  FUN_68132710((uint *)&local_48,0,0x10);
                  VariantInit((VARIANTARG *)&local_48.n2);
                  local_8 = 0x19;
                  (**(code **)(*param_4 + 0x20))(param_4,&local_48);
                  piVar1 = param_1;
                  if (local_48.n2.vt == 8) {
                    local_38 = (BSTR)(*param_1 + 0xc0);
                    uVar4 = FUN_6812e988((wchar_t *)local_48._8_4_);
                    (**(code **)local_38)(piVar1,uVar4);
                    pOVar3 = param_3;
                  }
                  VariantClear((VARIANTARG *)&local_48.n2);
                }
                local_8 = 0x17;
                if (param_4 != (int *)0x0) {
                  (**(code **)(*param_4 + 8))(param_4);
                }
              }
              local_8 = 0x16;
              if (param_5 != (BSTR)0x0) {
                (**(code **)(*(int *)param_5 + 8))(param_5);
              }
            }
            param_4 = (int *)0x0;
            _local_8 = CONCAT31(uStack_7,0x1a);
            iVar2 = (**(code **)(**(int **)pOVar3 + 0x94))
                              (*(int **)pOVar3,PTR_u_ImageInverse_6815ff9c,&param_4);
            if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
              param_5 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
              piVar1 = param_1;
              if (-1 < iVar2) {
                local_38 = (BSTR)(*param_1 + 0xb8);
                uVar4 = FUN_6812e988(param_5);
                (**(code **)local_38)(piVar1,uVar4);
              }
              SysFreeString(param_5);
            }
            local_8 = 0x16;
            if (param_4 != (int *)0x0) {
              (**(code **)(*param_4 + 8))(param_4);
            }
            local_8 = 0x11;
            if (local_1c != (int *)0x0) {
              (**(code **)(*local_1c + 8))(local_1c);
            }
            local_8 = 0x10;
            pCVar5 = param_2;
            if (local_24 != (BSTR)0x0) {
              (**(code **)(*(int *)local_24 + 8))(local_24);
              pCVar5 = param_2;
            }
          }
          param_4 = (int *)0x0;
          _local_8 = CONCAT31(uStack_7,0x1b);
          iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                            (*(int **)param_3,PTR_u_XRes_6815fccc,&param_4);
          if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
            param_5 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
            if (-1 < iVar2) {
              piVar1 = *(int **)pCVar5;
              local_34 = (BSTR)(*piVar1 + 0x70);
              fVar7 = (float10)FUN_6812ee95(param_5);
              local_38 = (BSTR)(float)fVar7;
              (**(code **)local_34)(piVar1,local_38);
            }
            SysFreeString(param_5);
          }
          local_8 = 0x10;
          if (param_4 != (int *)0x0) {
            (**(code **)(*param_4 + 8))(param_4);
          }
          param_4 = (int *)0x0;
          _local_8 = CONCAT31(uStack_7,0x1c);
          iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                            (*(int **)param_3,PTR_u_YRes_6815fcd0,&param_4);
          pCVar5 = param_2;
          if (iVar2 == 0) {
            if (param_4 != (int *)0x0) {
              param_5 = (BSTR)0x0;
              iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
              if (-1 < iVar2) {
                piVar1 = *(int **)param_2;
                local_34 = (BSTR)(*piVar1 + 0x78);
                fVar7 = (float10)FUN_6812ee95(param_5);
                local_38 = (BSTR)(float)fVar7;
                (**(code **)local_34)(piVar1,local_38);
              }
              SysFreeString(param_5);
            }
          }
          else if ((iVar2 == 1) &&
                  (iVar2 = (**(code **)(**(int **)param_2 + 0x6c))(*(int **)param_2,&param_5),
                  -1 < iVar2)) {
            (**(code **)(**(int **)pCVar5 + 0x78))(*(int **)pCVar5,param_5);
          }
          local_8 = 0x10;
          if (param_4 != (int *)0x0) {
            (**(code **)(*param_4 + 8))(param_4);
          }
          pOVar3 = param_3;
          param_4 = (int *)0x0;
          _local_8 = CONCAT31(uStack_7,0x1d);
          iVar2 = (**(code **)(**(int **)param_3 + 0x94))
                            (*(int **)param_3,PTR_u_LastUpdated_6815fcd4,&param_4);
          if ((iVar2 == 0) && (param_4 != (int *)0x0)) {
            param_5 = (BSTR)0x0;
            iVar2 = (**(code **)(*param_4 + 0x68))(param_4,&param_5);
            if (-1 < iVar2) {
              piVar1 = *(int **)param_2;
              local_38 = (BSTR)(*piVar1 + 0x88);
              fVar7 = (float10)FUN_6812ee95(param_5);
              param_2 = (CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
                         *)(float)fVar7;
              (**(code **)local_38)(piVar1,param_2);
              pOVar3 = param_3;
            }
            SysFreeString(param_5);
          }
          local_8 = 0x10;
          if (param_4 != (int *)0x0) {
            (**(code **)(*param_4 + 8))(param_4);
          }
          param_3 = (BSTR)0x0;
          _local_8 = CONCAT31(uStack_7,0x1e);
          iVar2 = (**(code **)(**(int **)pOVar3 + 0x94))
                            (*(int **)pOVar3,PTR_u_CurrentOrientation_6815ffe4,&param_3);
          if ((iVar2 == 0) && (param_3 != (BSTR)0x0)) {
            param_2 = (CComQIPtr<IPersistStreamInit,&struct___s_GUID_const__GUID_7fd52380_4e07_101b_ae2d_08002b2ec713>
                       *)0x0;
            iVar2 = (**(code **)(*(int *)param_3 + 0x68))(param_3,&param_2);
            piVar1 = param_1;
            if (-1 < iVar2) {
              param_4 = (int *)(*param_1 + 0xd8);
              uVar4 = FUN_6812eb8a((wchar_t *)param_2);
              iVar2 = (*(code *)*param_4)(piVar1,uVar4);
            }
            SysFreeString((BSTR)param_2);
          }
          _local_8 = CONCAT31(uStack_7,0x10);
          if (param_3 != (BSTR)0x0) {
            (**(code **)(*(int *)param_3 + 8))(param_3);
          }
          if (bstrString_00 != (BSTR)0x0) {
            iVar2 = (**(code **)(*param_1 + 0xd0))(param_1,bstrString_00);
          }
          local_8 = 0xe;
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
          local_8 = 10;
          if (local_28 != (int *)0x0) {
            (**(code **)(*local_28 + 8))(local_28);
          }
        }
        if (iVar2 == 1) {
          iVar2 = 0;
        }
        VariantClear((VARIANTARG *)&local_58.n2);
        goto LAB_68122515;
      }
    }
  }
  else {
LAB_68122502:
    bVar6 = local_1c == (int *)0x0;
  }
  local_8 = 3;
  if (!bVar6) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  iVar2 = -0x7ffcfefc;
LAB_68122515:
  _local_8 = CONCAT31(uStack_7,2);
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  SysFreeString(local_18[0]);
  SysFreeString(bstrString_00);
  SysFreeString(bstrString);
  return iVar2;
}



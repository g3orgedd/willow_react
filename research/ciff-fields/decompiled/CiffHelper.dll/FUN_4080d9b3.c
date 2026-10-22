// Source: CiffHelper.dll @ 4080d9b3; FUN_4080d9b3

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_4080d9b3(int *param_1,int *param_2)

{
  OLECHAR *pOVar1;
  ULONG UVar2;
  HRESULT HVar3;
  HRESULT HVar4;
  int iVar5;
  BSTR pOVar6;
  wchar_t *_Dst;
  UINT UVar7;
  LPCWSTR *ppWVar8;
  ushort *extraout_ECX;
  OLECHAR *pOVar9;
  code *pcVar10;
  IID *riid;
  ushort *puVar11;
  char *pcVar12;
  _union_2683 local_14a4;
  _union_2683 local_1494;
  OLECHAR *local_1484;
  OLECHAR *local_1480;
  OLECHAR *local_147c;
  uint local_1478;
  OLECHAR *local_1474;
  undefined4 local_1470;
  int local_146c;
  undefined4 local_1468;
  int local_1464;
  int local_1460;
  int local_145c;
  int local_1458;
  int local_1454;
  int local_1450;
  int local_144c;
  BSTR local_1448;
  BSTR local_1444;
  BSTR local_1440;
  int local_143c;
  int *local_1438;
  BSTR local_1434;
  IUnknown *local_1430;
  LPCWSTR local_142c;
  LPCWSTR local_1428;
  BSTR local_1424;
  int *local_1420;
  BSTR local_141c;
  OLECHAR *local_1418;
  int local_1414 [1270];
  wchar_t local_3c [20];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_40845f97;
  local_10 = ExceptionList;
  local_14 = DAT_40862970 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if ((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) {
    CComQIPtr<>(&local_1420,param_2);
    if (param_2 != (int *)0x0) {
      local_1440 = (BSTR)0x0;
      local_1428 = (LPCWSTR)0x0;
      local_142c = (LPCWSTR)0x0;
      local_1450 = 0;
      local_8._0_1_ = 5;
      (**(code **)(*local_1420 + 0x140))();
      (**(code **)(*local_1420 + 0x148))();
      FUN_408030e3(&local_145c,local_1428);
      local_8._0_1_ = 6;
      (**(code **)(*local_1420 + 0x150))();
      FUN_408030e3(&local_1454,local_142c);
      local_8._0_1_ = 7;
      (**(code **)(*local_1420 + 0x158))();
      local_1480 = (OLECHAR *)0x0;
      CComQIPtr<>(&local_1438,param_1);
      pcVar10 = SysFreeString_exref;
      if (local_1438 != (int *)0x0) {
        FUN_40802e76((uint *)&local_1494);
        local_8._0_1_ = 10;
        UVar2 = (**(code **)(*local_1438 + 0xb4))();
        local_1430 = (IUnknown *)0x0;
        local_8._0_1_ = 0xb;
        if (((-1 < (int)UVar2) && (local_1494.n2.vt == 9)) &&
           ((IUnknown *)local_1494._8_4_ != (IUnknown *)0x0)) {
          ATL::AtlComQIPtrAssign(&local_1430,(IUnknown *)local_1494._8_4_,(_GUID *)&DAT_4084aaa4);
        }
        local_1464 = 0;
        if (local_1430 != (IUnknown *)0x0) {
          UVar2 = (*local_1430->lpVtbl[2].AddRef)(local_1430);
        }
        riid = (IID *)0x0;
        if (-1 < (int)UVar2) {
LAB_4080db6b:
          if ((int)riid < local_1464) {
            FUN_40802e76((uint *)&local_14a4);
            riid = (IID *)((int)&riid->Data1 + 1);
            local_8._0_1_ = 0xc;
            HVar3 = (*local_1430->lpVtbl[4].QueryInterface)(local_1430,riid,(void **)&local_14a4);
            if ((HVar3 < 0) || (local_14a4.n2.vt != 9)) goto LAB_4080dc27;
            CComQIPtr<>(&local_1418,(undefined4 *)local_14a4._8_4_);
            if (local_1418 == (OLECHAR *)0x0) {
LAB_4080dc19:
              local_8._0_1_ = 0xc;
              if (local_1418 != (OLECHAR *)0x0) {
                (**(code **)(*(int *)local_1418 + 8))();
              }
              goto LAB_4080dc27;
            }
            local_141c = (BSTR)0x0;
            local_8._0_1_ = 0xe;
            HVar3 = (**(code **)(*(int *)local_1418 + 0x1c))();
            if ((HVar3 < 0) ||
               (HVar4 = VarBstrCmp(local_141c,local_1440,0x400,0), pOVar1 = local_1418, HVar4 != 1))
            {
              SysFreeString(local_141c);
              goto LAB_4080dc19;
            }
            local_1480 = local_1418;
            if (local_1418 != (OLECHAR *)0x0) {
              (**(code **)(*(int *)local_1418 + 4))();
            }
            SysFreeString(local_141c);
            local_8._0_1_ = 0xc;
            if (local_1418 != (OLECHAR *)0x0) {
              (**(code **)(*(int *)local_1418 + 8))();
            }
            local_8._0_1_ = 0xb;
            VariantClear((VARIANTARG *)&local_14a4.n2);
            if (pOVar1 != (OLECHAR *)0x0) {
              (**(code **)(*(int *)pOVar1 + 0x24))();
              local_1474 = (OLECHAR *)0x0;
              local_1460 = 0;
              iVar5 = (**(code **)(*(int *)pOVar1 + 0x3c))();
              if ((-1 < iVar5) && (local_1460 != 0)) {
                (**(code **)(*(int *)pOVar1 + 0x34))();
              }
              local_147c = (OLECHAR *)0x0;
              local_146c = 0;
              iVar5 = (**(code **)(*(int *)pOVar1 + 0x3c))();
              if ((-1 < iVar5) && (local_146c != 0)) {
                (**(code **)(*(int *)pOVar1 + 0x44))();
              }
              local_1470 = 2;
              (**(code **)(*(int *)pOVar1 + 0x7c))();
              if ((local_1474 != (OLECHAR *)0x0) && ((int)local_1484 < (int)local_1474)) {
                local_1484 = local_1474;
              }
              local_1418 = local_1484;
              if ((local_147c != (OLECHAR *)0x0) && ((int)local_147c < (int)local_1484)) {
                local_1418 = local_147c;
              }
              pOVar9 = local_1418;
              local_1434 = (BSTR)0xffffffff;
              iVar5 = (**(code **)(*local_1420 + 0x94))();
              if ((iVar5 < 0) || ((int)local_1434 < 1)) {
                pOVar6 = (BSTR)0x0;
                local_141c = (BSTR)0x0;
                local_8._0_1_ = 0x18;
                FUN_4080cff3(local_1414,local_1418,local_1470);
                local_8 = CONCAT31(local_8._1_3_,0x19);
                if ((int)local_1418 < local_1450) {
                  UVar7 = SysStringLen(local_142c);
                  if (UVar7 != 0) {
LAB_4080e174:
                    ppWVar8 = &local_142c;
                    goto LAB_4080e17a;
                  }
                  UVar7 = SysStringLen(local_1428);
                  if (UVar7 != 0) goto LAB_4080e145;
                  pcVar12 = 
                  "CCiffDataHelper::FormatPrice lcurrentValue < switchVal. Could not set price value from price format"
                  ;
LAB_4080e1a9:
                  FUN_40804125((int)pcVar12);
                }
                else {
                  UVar7 = SysStringLen(local_1428);
                  if (UVar7 == 0) {
                    UVar7 = SysStringLen(local_142c);
                    if (UVar7 == 0) {
                      pcVar12 = 
                      "CCiffDataHelper::FormatPrice Could not set price value from price format";
                      goto LAB_4080e1a9;
                    }
                    goto LAB_4080e174;
                  }
LAB_4080e145:
                  ppWVar8 = &local_1428;
LAB_4080e17a:
                  local_1424 = FUN_4082bcaf(local_1414,(int *)ppWVar8,0);
                  if (local_1424 != (BSTR)0x0) {
                    SysFreeString((BSTR)0x0);
                    local_141c = local_1424;
                    pOVar6 = local_1424;
                  }
                }
                UVar7 = SysStringLen(pOVar6);
                if (UVar7 == 0) {
                  FUN_40804125(0x4084c160);
                }
                else {
                  (**(code **)(*param_2 + 100))();
                  (**(code **)(*param_2 + 0x5c))();
                }
                local_8._0_1_ = 0x18;
                FUN_4080d11c(local_1414);
              }
              else {
                local_1448 = (BSTR)0x0;
                local_8._0_1_ = 0xf;
                (**(code **)(*local_1420 + 0x168))();
                local_1468 = 0x20;
                (**(code **)(*local_1420 + 0xa4))();
                local_144c = 0;
                (**(code **)(*local_1420 + 0xac))(local_1420);
                _swprintf_s(local_3c,0x14,L"%d",pOVar9);
                local_1444 = (BSTR)_wcslen(local_3c);
                pOVar6 = local_1434;
                if ((int)local_1434 < (int)local_1444) {
                  pOVar6 = local_1444;
                }
                pOVar9 = (OLECHAR *)((int)pOVar6 + 1);
                local_1418 = pOVar9;
                pOVar6 = (BSTR)FUN_4082c99b(-(uint)((int)(ZEXT48(pOVar9) * 2 >> 0x20) != 0) |
                                            (uint)(ZEXT48(pOVar9) * 2));
                iVar5 = 0;
                local_8._0_1_ = 0x10;
                if (local_1434 != local_1444 && -1 < (int)local_1434 - (int)local_1444) {
                  do {
                    pOVar6[iVar5] = (OLECHAR)local_1468;
                    iVar5 = iVar5 + 1;
                  } while (iVar5 < (int)local_1434 - (int)local_1444);
                }
                pOVar6[iVar5] = L'\0';
                local_1424 = pOVar6;
                _Dst = (wchar_t *)
                       FUN_4082c99b(-(uint)((int)(ZEXT48(pOVar9) * 2 >> 0x20) != 0) |
                                    (uint)(ZEXT48(pOVar9) * 2));
                local_8._0_1_ = 0x11;
                if (local_144c == 0) {
                  pOVar6 = local_3c;
                }
                _swprintf_s(_Dst,(size_t)local_1418,L"%s%s",pOVar6);
                FUN_40802e40(&local_1444,_Dst);
                local_8._0_1_ = 0x12;
                FUN_40802e40(&local_141c,_Dst);
                local_8._0_1_ = 0x13;
                UVar7 = SysStringLen(local_1448);
                pOVar6 = local_141c;
                if (UVar7 != 0) {
                  puVar11 = extraout_ECX;
                  FUN_408030e3(&stack0xffffeaec,local_141c);
                  local_1478 = FUN_4080e83b(puVar11);
                  local_1458 = 0;
                  iVar5 = (**(code **)(*local_1420 + 0x160))(local_1420);
                  if (iVar5 < 0) {
                    FUN_40804125(0x4084c010);
                  }
                  else {
                    local_1418 = (OLECHAR *)PTR_DAT_40862014;
                    if (local_1458 == 0) {
                      local_8._0_1_ = 0x14;
                      FUN_408030e3(&local_143c,pOVar6);
                      local_8._0_1_ = 0x15;
                      FUN_408051a5(&local_1418,L"%01d%s");
                      local_8._0_1_ = 0x14;
                    }
                    else {
                      local_8._0_1_ = 0x16;
                      FUN_408030e3(&local_143c,pOVar6);
                      local_8._0_1_ = 0x17;
                      FUN_408051a5(&local_1418,L"%s%01d");
                      local_8._0_1_ = 0x16;
                    }
                    FUN_40803143(&local_143c);
                    FUN_40803e97(&local_141c,local_1418);
                    local_8._0_1_ = 0x13;
                    FUN_40803143((int *)&local_1418);
                    pOVar6 = local_141c;
                  }
                }
                (**(code **)(*param_2 + 100))(param_2);
                (**(code **)(*param_2 + 0x5c))(param_2,local_1444);
                UVar7 = SysStringLen(pOVar6);
                if (UVar7 == 0) {
                  FUN_40804125(0x4084c050);
                }
                pcVar10 = SysFreeString_exref;
                SysFreeString(pOVar6);
                SysFreeString(local_1444);
                FID_conflict__free(_Dst);
                FID_conflict__free(local_1424);
              }
              (*pcVar10)();
              local_8._0_1_ = 10;
              if (local_1430 != (IUnknown *)0x0) {
                (*local_1430->lpVtbl->Release)(local_1430);
              }
              VariantClear((VARIANTARG *)&local_1494.n2);
              local_8._0_1_ = 8;
              if (local_1438 != (int *)0x0) {
                (**(code **)(*local_1438 + 8))();
              }
              local_8._0_1_ = 7;
              (**(code **)(*(int *)pOVar1 + 8))();
              goto LAB_4080dc71;
            }
          }
        }
LAB_4080dc42:
        local_8._0_1_ = 10;
        if (local_1430 != (IUnknown *)0x0) {
          (*local_1430->lpVtbl->Release)(local_1430);
        }
        VariantClear((VARIANTARG *)&local_1494.n2);
      }
      local_8._0_1_ = 8;
      if (local_1438 != (int *)0x0) {
        (**(code **)(*local_1438 + 8))();
      }
LAB_4080dc71:
      FUN_40803143(&local_1454);
      FUN_40803143(&local_145c);
      (*pcVar10)();
      (*pcVar10)();
      (*pcVar10)();
    }
    local_8._0_1_ = 1;
    if (local_1420 != (int *)0x0) {
      (**(code **)(*local_1420 + 8))();
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))();
  }
  local_8 = 0xffffffff;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 8))();
  }
  ExceptionList = local_10;
  FUN_4082d440(local_14 ^ (uint)&stack0xfffffffc);
  return;
LAB_4080dc27:
  VariantClear((VARIANTARG *)&local_14a4.n2);
  if (HVar3 < 0) goto LAB_4080dc42;
  goto LAB_4080db6b;
}



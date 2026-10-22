// Source: CiffMgr.dll @ 6812282a; FUN_6812282a

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6812282a(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  void *this;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  BSTR pOVar5;
  wchar_t *bstrString;
  _union_2683 local_5c;
  _union_2683 local_4c;
  int local_3c;
  wchar_t *local_38;
  BSTR local_34;
  wchar_t *local_30;
  wchar_t *local_2c;
  int *local_28;
  BSTR local_24;
  BSTR local_20;
  int *local_1c;
  void *local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  piVar1 = param_1;
  uStack_4 = 0x4c;
  local_8 = 0x68122836;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    (**(code **)(*param_1 + 100))(param_1,&local_3c);
    if (local_3c == 0) {
      local_14[0] = (int *)0x0;
      local_8 = 0;
      iVar2 = (**(code **)*piVar1)(piVar1,&DAT_6814a2fc,local_14);
      CComQIPtr<>(&local_1c,local_14[0]);
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_1c != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x78))(piVar1,&param_1);
        if (-1 < iVar3) {
          (**(code **)(*local_1c + 0x14c))(local_1c,param_1);
        }
        iVar3 = (**(code **)(*piVar1 + 0x3c))(piVar1,&param_1);
        if (-1 < iVar3) {
          (**(code **)(*local_1c + 0x15c))(local_1c,param_1);
        }
      }
      if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
        do {
          param_1 = (int *)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&param_1);
          if ((iVar2 == 0) && (param_1 != (int *)0x0)) {
            local_38 = (wchar_t *)0x0;
            iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,&local_38);
            this = local_18;
            if (-1 < iVar2) {
              iVar3 = FUN_6812e15e(0x6815fa08,local_38,0,7);
              if (iVar3 < 0x66) {
                if (iVar3 == 0x65) {
                  local_2c = (BSTR)0x0;
                  local_8._0_1_ = 3;
                  iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&local_2c);
                  if ((-1 < iVar2) && (local_2c != (BSTR)0x0)) {
                    CComQIPtr<>(&local_28,local_14[0]);
                    if (local_28 != (int *)0x0) {
                      local_20 = (BSTR)0x0;
                      local_8._0_1_ = 5;
                      iVar2 = (**(code **)(*(int *)local_2c + 0x1c))
                                        (local_2c,PTR_u_Compatibility_68160084,&local_20);
                      if ((iVar2 == 0) && (local_20 != (BSTR)0x0)) {
                        FUN_68132710((uint *)&local_5c,0,0x10);
                        VariantInit((VARIANTARG *)&local_5c.n2);
                        local_8._0_1_ = 6;
                        (**(code **)(*(int *)local_20 + 0x20))(local_20,&local_5c);
                        piVar1 = local_28;
                        if (local_5c.n2.vt == 8) {
                          iVar2 = *local_28;
                          uVar4 = FUN_6812e988((wchar_t *)local_5c._8_4_);
                          (**(code **)(iVar2 + 0x130))(piVar1,uVar4);
                        }
                        VariantClear((VARIANTARG *)&local_5c.n2);
                      }
                      local_8._0_1_ = 4;
                      if (local_20 != (BSTR)0x0) {
                        (**(code **)(*(int *)local_20 + 8))(local_20);
                      }
                    }
                    local_8._0_1_ = 3;
                    if (local_28 != (int *)0x0) {
                      (**(code **)(*local_28 + 8))(local_28);
                    }
                  }
                  local_20 = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,7);
                  iVar2 = (**(code **)(*param_1 + 0x94))(param_1,PTR_u_BlkW_6815fde8,&local_20);
                  if ((iVar2 == 0) && (local_20 != (BSTR)0x0)) {
                    local_34 = (BSTR)0x0;
                    iVar2 = (**(code **)(*(int *)local_20 + 0x68))(local_20,&local_34);
                    piVar1 = local_14[0];
                    if (-1 < iVar2) {
                      iVar2 = *local_14[0];
                      iVar3 = FUN_6812f116((ushort *)local_34);
                      (**(code **)(iVar2 + 0xd8))(piVar1,iVar3);
                    }
                    SysFreeString(local_34);
                  }
                  local_8._0_1_ = 3;
                  if (local_20 != (BSTR)0x0) {
                    (**(code **)(*(int *)local_20 + 8))(local_20);
                  }
                  local_20 = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,8);
                  iVar2 = (**(code **)(*param_1 + 0x94))(param_1,PTR_u_BlkH_6815fdec,&local_20);
                  if ((iVar2 == 0) && (local_20 != (BSTR)0x0)) {
                    local_34 = (BSTR)0x0;
                    iVar2 = (**(code **)(*(int *)local_20 + 0x68))(local_20,&local_34);
                    piVar1 = local_14[0];
                    if (-1 < iVar2) {
                      iVar2 = *local_14[0];
                      iVar3 = FUN_6812f116((ushort *)local_34);
                      (**(code **)(iVar2 + 0xe0))(piVar1,iVar3);
                    }
                    SysFreeString(local_34);
                  }
                  local_8._0_1_ = 3;
                  if (local_20 != (BSTR)0x0) {
                    (**(code **)(*(int *)local_20 + 8))(local_20);
                  }
                  local_20 = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,9);
                  iVar2 = (**(code **)(*param_1 + 0x94))
                                    (param_1,PTR_u_MinFontSize_6815fdf0,&local_20);
                  if ((iVar2 == 0) && (local_20 != (BSTR)0x0)) {
                    local_34 = (BSTR)0x0;
                    iVar2 = (**(code **)(*(int *)local_20 + 0x68))(local_20,&local_34);
                    piVar1 = local_14[0];
                    if (-1 < iVar2) {
                      iVar2 = *local_14[0];
                      iVar3 = FUN_6812f116((ushort *)local_34);
                      (**(code **)(iVar2 + 0xf0))(piVar1,iVar3);
                    }
                    SysFreeString(local_34);
                  }
                  local_8._0_1_ = 3;
                  if (local_20 != (BSTR)0x0) {
                    (**(code **)(*(int *)local_20 + 8))(local_20);
                  }
                  local_20 = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,10);
                  iVar2 = (**(code **)(*param_1 + 0x94))
                                    (param_1,PTR_u_BlkJustify_6815fdf4,&local_20);
                  if ((iVar2 == 0) && (local_20 != (BSTR)0x0)) {
                    local_34 = (wchar_t *)0x0;
                    iVar2 = (**(code **)(*(int *)local_20 + 0x68))(local_20,&local_34);
                    piVar1 = local_14[0];
                    if (-1 < iVar2) {
                      iVar2 = *local_14[0];
                      uVar4 = FUN_6812e914(local_34);
                      (**(code **)(iVar2 + 0xf8))(piVar1,uVar4);
                    }
                    SysFreeString(local_34);
                  }
                  local_8._0_1_ = 3;
                  if (local_20 != (BSTR)0x0) {
                    (**(code **)(*(int *)local_20 + 8))(local_20);
                  }
                  local_20 = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,0xb);
                  iVar2 = (**(code **)(*param_1 + 0x94))
                                    (param_1,PTR_u_Hyphenation_6815fdf8,&local_20);
                  if ((iVar2 == 0) && (local_20 != (BSTR)0x0)) {
                    local_34 = (wchar_t *)0x0;
                    iVar2 = (**(code **)(*(int *)local_20 + 0x68))(local_20,&local_34);
                    piVar1 = local_14[0];
                    if (-1 < iVar2) {
                      iVar2 = *local_14[0];
                      uVar4 = FUN_6812e988(local_34);
                      iVar2 = (**(code **)(iVar2 + 0x118))(piVar1,uVar4);
                    }
                    SysFreeString(local_34);
                  }
                  local_8._0_1_ = 3;
                  if (local_20 != (BSTR)0x0) {
                    (**(code **)(*(int *)local_20 + 8))(local_20);
                  }
                  pOVar5 = local_2c;
                  if (iVar2 == 1) {
                    iVar2 = 0;
                    pOVar5 = local_2c;
                  }
                }
                else if (iVar3 == 0x61) {
                  local_20 = (BSTR)0x0;
                  local_8._0_1_ = 0x11;
                  iVar2 = (**(code **)(*param_1 + 0x30))(param_1,&local_20);
                  pOVar5 = local_20;
                  if ((iVar2 == 0) && (pOVar5 = local_20, local_20 != (BSTR)0x0)) {
                    iVar2 = FUN_68122ff7(this,local_14[0],&local_20);
                    pOVar5 = local_20;
                  }
                }
                else {
                  if (iVar3 != 0x62) {
                    if (iVar3 == 99) {
                      local_30 = (wchar_t *)0x0;
                      iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_30);
                      piVar1 = local_14[0];
                      bstrString = local_30;
                      if (-1 < iVar2) {
                        iVar2 = *local_14[0];
                        uVar4 = FUN_6812e988(local_30);
                        iVar2 = (**(code **)(iVar2 + 0xcc))(piVar1,uVar4);
                        bstrString = local_30;
                      }
                    }
                    else {
                      if (iVar3 != 100) goto LAB_68122fa2;
                      local_2c = (wchar_t *)0x0;
                      iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_2c);
                      piVar1 = local_14[0];
                      bstrString = local_2c;
                      if (-1 < iVar2) {
                        iVar2 = *local_14[0];
                        uVar4 = FUN_6812e988(local_2c);
                        iVar2 = (**(code **)(iVar2 + 0x110))(piVar1,uVar4);
                        bstrString = local_2c;
                      }
                    }
                    goto LAB_68122999;
                  }
                  local_2c = (wchar_t *)0x0;
                  iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_2c);
                  piVar1 = local_14[0];
                  if (-1 < iVar2) {
                    iVar2 = *local_14[0];
                    uVar4 = FUN_6812e988(local_2c);
                    (**(code **)(iVar2 + 0xc4))(piVar1,uVar4);
                  }
                  SysFreeString(local_2c);
                  local_24 = (BSTR)0x0;
                  local_8._0_1_ = 0xc;
                  iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&local_24);
                  pOVar5 = local_24;
                  if ((-1 < iVar2) && (local_24 != (BSTR)0x0)) {
                    local_20 = (BSTR)0x0;
                    local_8._0_1_ = 0xd;
                    iVar2 = (**(code **)(*(int *)local_24 + 0x1c))
                                      (local_24,PTR_u_Weight_68160080,&local_20);
                    if ((iVar2 == 0) && (local_20 != (BSTR)0x0)) {
                      FUN_68132710((uint *)&local_4c,0,0x10);
                      VariantInit((VARIANTARG *)&local_4c.n2);
                      local_8._0_1_ = 0xe;
                      iVar2 = (**(code **)(*(int *)local_20 + 0x20))(local_20,&local_4c);
                      piVar1 = local_14[0];
                      if (local_4c.n2.vt == 8) {
                        iVar2 = *local_14[0];
                        iVar3 = FUN_6812f116((ushort *)local_4c._8_4_);
                        iVar2 = (**(code **)(iVar2 + 0x108))(piVar1,iVar3);
                      }
                      VariantClear((VARIANTARG *)&local_4c.n2);
                    }
                    local_8._0_1_ = 0xc;
                    if (local_20 != (BSTR)0x0) {
                      (**(code **)(*(int *)local_20 + 8))(local_20);
                    }
                    pOVar5 = local_24;
                    if (iVar2 == 1) {
                      iVar2 = 0;
                    }
                  }
                }
                local_8._0_1_ = 2;
                if (pOVar5 != (BSTR)0x0) {
                  (**(code **)(*(int *)pOVar5 + 8))(pOVar5);
                }
              }
              else if (iVar3 == 0xc5) {
                if (local_1c != (int *)0x0) {
                  local_2c = (wchar_t *)0x0;
                  local_8 = CONCAT31(local_8._1_3_,0xf);
                  iVar2 = (**(code **)(*param_1 + 0x94))(param_1,PTR_u_Width_6815ff50,&local_2c);
                  if ((iVar2 == 0) && (local_2c != (wchar_t *)0x0)) {
                    local_34 = (BSTR)0x0;
                    iVar2 = (**(code **)(*(int *)local_2c + 0x68))(local_2c,&local_34);
                    piVar1 = local_1c;
                    if (-1 < iVar2) {
                      iVar2 = *local_1c;
                      iVar3 = FUN_6812f116((ushort *)local_34);
                      (**(code **)(iVar2 + 0x14c))(piVar1,iVar3);
                    }
                    SysFreeString(local_34);
                  }
                  local_8._0_1_ = 2;
                  if (local_2c != (wchar_t *)0x0) {
                    (**(code **)(*(int *)local_2c + 8))(local_2c);
                  }
                  local_2c = (BSTR)0x0;
                  local_8 = CONCAT31(local_8._1_3_,0x10);
                  iVar2 = (**(code **)(*param_1 + 0x94))(param_1,PTR_u_Align_6815ff54,&local_2c);
                  if ((iVar2 == 0) && (local_2c != (BSTR)0x0)) {
                    local_34 = (wchar_t *)0x0;
                    iVar2 = (**(code **)(*(int *)local_2c + 0x68))(local_2c,&local_34);
                    piVar1 = local_1c;
                    if (-1 < iVar2) {
                      iVar2 = *local_1c;
                      uVar4 = FUN_6812ee1d(local_34);
                      iVar2 = (**(code **)(iVar2 + 0x144))(piVar1,uVar4);
                    }
                    SysFreeString(local_34);
                  }
                  local_8._0_1_ = 2;
                  if (local_2c != (BSTR)0x0) {
                    (**(code **)(*(int *)local_2c + 8))(local_2c);
                  }
                  if (iVar2 == 1) {
                    iVar2 = 0;
                  }
                }
              }
              else if (iVar3 == 0xc9) {
                if (local_1c != (int *)0x0) {
                  local_34 = (BSTR)0x0;
                  iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_34);
                  piVar1 = local_1c;
                  bstrString = local_34;
                  if (-1 < iVar2) {
                    iVar2 = *local_1c;
                    iVar3 = FUN_6812f116((ushort *)local_34);
                    iVar2 = (**(code **)(iVar2 + 0x15c))(piVar1,iVar3);
                    bstrString = local_34;
                  }
                  goto LAB_68122999;
                }
              }
              else if ((iVar3 == 0xd6) && (local_1c != (int *)0x0)) {
                local_34 = (BSTR)0x0;
                iVar2 = (**(code **)(*param_1 + 0x68))(param_1,&local_34);
                piVar1 = local_1c;
                bstrString = local_34;
                if (-1 < iVar2) {
                  iVar2 = *local_1c;
                  iVar3 = FUN_6812f116((ushort *)local_34);
                  iVar2 = (**(code **)(iVar2 + 0x164))(piVar1,iVar3);
                  bstrString = local_34;
                }
LAB_68122999:
                SysFreeString(bstrString);
              }
            }
LAB_68122fa2:
            SysFreeString(local_38);
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          if (param_1 != (int *)0x0) {
            (**(code **)(*param_1 + 8))(param_1);
          }
        } while (iVar2 == 0);
        if (iVar2 == 1) {
          iVar2 = 0;
        }
      }
      local_8 = local_8 & 0xffffff00;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      local_8 = 0xffffffff;
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
    }
    else {
      iVar2 = -0x7ff8ffa9;
    }
  }
  return iVar2;
}



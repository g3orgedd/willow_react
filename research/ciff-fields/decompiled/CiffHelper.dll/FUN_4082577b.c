// Source: CiffHelper.dll @ 4082577b; FUN_4082577b

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_4082577b(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  BSTR extraout_ECX;
  BSTR extraout_ECX_00;
  BSTR pOVar5;
  BSTR bstrString;
  undefined4 local_a4 [6];
  _union_2683 local_8c;
  undefined4 local_7c;
  _union_2683 local_78;
  _union_2683 local_68;
  _union_2683 local_58;
  wchar_t *local_48;
  BSTR local_44;
  short local_40 [2];
  BSTR local_3c;
  BSTR local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar3 = FUN_40802f5d(local_14);
  if (-1 < iVar3) {
    bstrString = (BSTR)0x0;
    local_44 = (BSTR)0x0;
    local_8._0_1_ = 1;
    iVar3 = (**(code **)(*local_14[0] + 0xfc))(local_14[0]);
    if (-1 < iVar3) {
      local_3c = (BSTR)0x0;
      local_8._0_1_ = 2;
      (**(code **)(*(int *)*param_1 + 0x84))((int *)*param_1);
      local_8c._0_4_ = local_8c._0_4_ & 0xffff0000;
      FUN_40802ec0(&local_8c,(int *)&local_3c);
      local_8._0_1_ = 3;
      iVar3 = (**(code **)(*local_14[0] + 0xe8))
                        (local_14[0],local_8c._0_4_,local_8c.decVal.Hi32,local_8c._8_4_,
                         local_8c._12_4_,local_40);
      if ((-1 < iVar3) && (local_40[0] != 0)) {
        local_24 = (int *)0x0;
        local_8._0_1_ = 4;
        iVar3 = (**(code **)(*local_14[0] + 0xb4))(local_14[0]);
        if ((-1 < iVar3) && (local_24 != (int *)0x0)) {
          local_38 = (BSTR)0x0;
          local_8._0_1_ = 5;
          iVar3 = (**(code **)(*local_24 + 0x1c))(local_24);
          if ((-1 < iVar3) && (bVar2 = FUN_40803ed6(&local_38,L"ImageDesign"), bVar2)) {
            local_2c = (int *)0x0;
            local_8._0_1_ = 6;
            iVar3 = (**(code **)(*local_24 + 0x94))(local_24,L"GenericSettings");
            if ((iVar3 == 0) && (local_2c != (int *)0x0)) {
              local_20 = (int *)0x0;
              local_8 = CONCAT31(local_8._1_3_,7);
              iVar3 = (**(code **)(*local_2c + 0x30))(local_2c);
              if ((iVar3 == 0) && (local_20 != (int *)0x0)) {
                do {
                  local_1c = (int *)0x0;
                  local_8._0_1_ = 8;
                  iVar3 = (**(code **)(*local_20 + 0x24))(local_20);
                  if ((iVar3 == 0) && (local_1c != (int *)0x0)) {
                    local_48 = (wchar_t *)0x0;
                    iVar3 = (**(code **)(*local_1c + 0x1c))(local_1c);
                    if ((-1 < iVar3) && (iVar4 = _wcscmp(local_48,L"PreferredMarkSet"), iVar4 == 0))
                    {
                      local_30 = (int *)0x0;
                      local_8._0_1_ = 9;
                      iVar3 = (**(code **)(*local_1c + 0x44))(local_1c);
                      if ((iVar3 == 0) && (local_30 != (int *)0x0)) {
                        local_18 = (int *)0x0;
                        local_8._0_1_ = 10;
                        iVar3 = (**(code **)(*local_30 + 0x1c))(local_30,L"Name");
                        if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
                          FUN_40802e76((uint *)&local_58);
                          local_8._0_1_ = 0xb;
                          iVar3 = (**(code **)(*local_18 + 0x20))(local_18);
                          if (local_58.n2.vt == 8) {
                            FUN_40803e97(&local_44,(OLECHAR *)local_58._8_4_);
                            local_7c = 0;
                            FUN_40802e76((uint *)&local_78);
                            local_8._0_1_ = 0xd;
                            iVar4 = (**(code **)(*(int *)*param_2 + 0x4c))((int *)*param_2);
                            bstrString = local_44;
                            if (((-1 < iVar4) && (local_78.n2.vt == 9)) &&
                               ((undefined4 *)local_78._8_4_ != (undefined4 *)0x0)) {
                              local_28 = (int *)0x0;
                              local_8._0_1_ = 0xe;
                              iVar4 = (*(code *)**(undefined4 **)local_78._8_4_)
                                                (local_78._8_4_,&DAT_4084aae4);
                              if ((-1 < iVar4) && (local_28 != (int *)0x0)) {
                                FUN_40802e76((uint *)&local_68);
                                local_8._0_1_ = 0xf;
                                iVar4 = (**(code **)(*local_28 + 0x30))(local_28,bstrString);
                                if ((-1 < iVar4) && ((local_68.n2.vt == 9 && (local_68._8_4_ != 0)))
                                   ) {
                                  FUN_408212c8(local_a4);
                                  local_8._0_1_ = 0x10;
                                  local_34 = (int *)*param_1;
                                  pOVar5 = extraout_ECX;
                                  if (local_34 != (int *)0x0) {
                                    (**(code **)(*local_34 + 4))();
                                    pOVar5 = extraout_ECX_00;
                                  }
                                  local_8._0_1_ = 0x11;
                                  FUN_40803baf(&stack0xffffff48,(int *)&local_44);
                                  FUN_408213b8(local_a4,(int *)&local_34,pOVar5);
                                  FUN_408234bc(local_a4,(BSTR)&local_34);
                                  local_8._0_1_ = 0x10;
                                  if (local_34 != (int *)0x0) {
                                    (**(code **)(*local_34 + 8))();
                                  }
                                  local_8._0_1_ = 0xf;
                                  FUN_408212e6(local_a4);
                                }
                                VariantClear((VARIANTARG *)&local_68.n2);
                              }
                              local_8._0_1_ = 0xd;
                              if (local_28 != (int *)0x0) {
                                (**(code **)(*local_28 + 8))();
                              }
                            }
                            VariantClear((VARIANTARG *)&local_78.n2);
                          }
                          VariantClear((VARIANTARG *)&local_58.n2);
                        }
                        local_8._0_1_ = 9;
                        if (local_18 != (int *)0x0) {
                          (**(code **)(*local_18 + 8))();
                        }
                      }
                      local_8._0_1_ = 8;
                      if (local_30 != (int *)0x0) {
                        (**(code **)(*local_30 + 8))();
                      }
                    }
                    SysFreeString(local_48);
                  }
                  local_8 = CONCAT31(local_8._1_3_,7);
                  if (local_1c != (int *)0x0) {
                    (**(code **)(*local_1c + 8))();
                  }
                } while (iVar3 == 0);
                iVar3 = 0;
              }
              local_8._0_1_ = 6;
              if (local_20 != (int *)0x0) {
                (**(code **)(*local_20 + 8))();
              }
            }
            local_8._0_1_ = 5;
            if (local_2c != (int *)0x0) {
              (**(code **)(*local_2c + 8))();
            }
          }
          SysFreeString(local_38);
        }
        local_8._0_1_ = 3;
        if (local_24 != (int *)0x0) {
          (**(code **)(*local_24 + 8))();
        }
      }
      VariantClear((VARIANTARG *)&local_8c.n2);
      local_8._0_1_ = 1;
      SysFreeString(local_3c);
    }
    piVar1 = local_14[0];
    if (local_14[0] != (int *)0x0) {
      local_14[0] = (int *)0x0;
      (**(code **)(*piVar1 + 8))();
    }
    SysFreeString(bstrString);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))();
  }
  return iVar3;
}



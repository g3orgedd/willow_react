// Source: CiffMgr.dll @ 6811facb; FUN_6811facb

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811facb(void *this,int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  UINT UVar4;
  undefined4 uVar5;
  BSTR bstrString;
  BSTR pOVar6;
  float10 fVar7;
  VARIANTARG local_b0;
  _union_2683 local_a0;
  _union_2683 local_90;
  short local_80 [4];
  BSTR local_78;
  _union_2683 local_70;
  _union_2683 local_60;
  int local_50;
  BSTR local_4c;
  BSTR local_48;
  undefined1 local_44 [16];
  uint local_34;
  void *local_30;
  int *local_2c;
  int local_28;
  int *local_24;
  wchar_t *local_20;
  int *local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa0;
  local_30 = this;
  do {
    bstrString = (BSTR)0x0;
    local_24 = (int *)0x0;
    local_8 = 0;
    iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_24);
    local_50 = iVar2;
    if ((iVar2 == 0) && (local_24 != (int *)0x0)) {
      uVar5 = (BSTR)0x0;
      local_48 = (BSTR)0x0;
      local_28 = 1;
      local_34 = 0;
      local_18 = (BSTR)0x0;
      local_4c = (BSTR)0x0;
      local_1c = (int *)0x0;
      local_8._0_1_ = 3;
      iVar3 = (**(code **)(*local_24 + 0x44))(local_24,&local_1c);
      pOVar6 = local_18;
      if (iVar3 < 0) {
LAB_6811ff4a:
        iVar2 = iVar3;
      }
      else {
        if (local_1c != (int *)0x0) {
          local_14[0] = (int *)0x0;
          local_8 = CONCAT31(local_8._1_3_,4);
          iVar2 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_Name_68160030,local_14);
          if ((iVar2 < 0) || (local_14[0] == (int *)0x0)) {
            iVar3 = -0x7fffbffb;
            uVar5 = bstrString;
          }
          else {
            iVar3 = (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_70);
            uVar1 = local_70._8_4_;
            if (((local_70.n2.vt == 8) && ((BSTR)local_70._8_4_ != (BSTR)0x0)) &&
               (*(OLECHAR *)local_70._8_4_ != L'\0')) {
              SysFreeString((BSTR)0x0);
              local_48 = (BSTR)uVar1;
              local_70.n2.vt = 0;
              uVar5 = uVar1;
            }
            else {
              VariantClear((VARIANTARG *)&local_70.n2);
            }
          }
          if (local_14[0] != (int *)0x0) {
            local_8._0_1_ = 3;
            (**(code **)(*local_14[0] + 8))(local_14[0]);
          }
          bstrString = (BSTR)uVar5;
          pOVar6 = local_18;
          if (-1 < iVar3) {
            local_14[0] = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,5);
            iVar3 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_Type_6816003c,local_14);
            if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
              iVar3 = (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_90);
              if ((local_90.n2.vt == 8) &&
                 (((wchar_t *)local_90._8_4_ != (wchar_t *)0x0 &&
                  (*(wchar_t *)local_90._8_4_ != L'\0')))) {
                local_28 = FUN_6812f423((wchar_t *)local_90._8_4_);
              }
              VariantClear((VARIANTARG *)&local_90.n2);
            }
            if (local_14[0] != (int *)0x0) {
              local_8._0_1_ = 3;
              (**(code **)(*local_14[0] + 8))(local_14[0]);
            }
            pOVar6 = local_18;
            if (-1 < iVar3) {
              local_14[0] = (int *)0x0;
              local_8 = CONCAT31(local_8._1_3_,6);
              iVar3 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_Database_681600f8,local_14);
              if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
                iVar3 = (**(code **)(*local_14[0] + 0x20))(local_14[0],&local_a0);
                if ((local_a0.n2.vt == 8) &&
                   (((wchar_t *)local_a0._8_4_ != (wchar_t *)0x0 &&
                    (*(wchar_t *)local_a0._8_4_ != L'\0')))) {
                  iVar2 = _wcscmp((wchar_t *)local_a0._8_4_,L"1");
                  local_34 = (uint)(iVar2 == 0);
                }
                VariantClear((VARIANTARG *)&local_a0.n2);
              }
              if (local_14[0] != (int *)0x0) {
                local_8._0_1_ = 3;
                (**(code **)(*local_14[0] + 8))(local_14[0]);
              }
              pOVar6 = local_18;
              if (-1 < iVar3) {
                local_14[0] = (int *)0x0;
                local_8 = CONCAT31(local_8._1_3_,7);
                iVar3 = (**(code **)(*local_1c + 0x1c))(local_1c,PTR_u_DataSource_681600fc,local_14)
                ;
                if ((((-1 < iVar3) && (local_14[0] != (int *)0x0)) &&
                    (iVar3 = (**(code **)(*local_14[0] + 0x20))(local_14[0],local_80),
                    pOVar6 = local_78, local_80[0] == 8)) &&
                   ((local_78 != (BSTR)0x0 && (*local_78 != L'\0')))) {
                  local_18 = local_78;
                  SysFreeString((BSTR)0x0);
                  local_4c = pOVar6;
                  local_80[0] = 0;
                  local_78 = (BSTR)0x0;
                }
                local_8._0_1_ = 3;
                if (local_14[0] != (int *)0x0) {
                  (**(code **)(*local_14[0] + 8))(local_14[0]);
                }
                goto LAB_6811fd5f;
              }
            }
          }
          goto LAB_6811ff4a;
        }
LAB_6811fd5f:
        pOVar6 = local_18;
        iVar2 = iVar3;
        if (-1 < iVar3) {
          UVar4 = SysStringLen(bstrString);
          pOVar6 = local_18;
          if (UVar4 != 0) {
            FUN_68132710((uint *)local_44,0,0x10);
            VariantInit((VARIANTARG *)local_44);
            local_8._0_1_ = 8;
            local_20 = (wchar_t *)0x0;
            iVar3 = (**(code **)(*local_24 + 0x68))(local_24,&local_20);
            pOVar6 = local_18;
            if (-1 < iVar3) {
              if (local_28 < 0) {
LAB_6811fe0d:
                iVar3 = -0x7ff8ffa9;
              }
              else if (local_28 < 2) {
                local_44._0_2_ = 3;
                iVar2 = FUN_6812f116((ushort *)local_20);
                local_44._8_4_ = iVar2;
              }
              else if (local_28 == 2) {
                local_44._0_2_ = 8;
                local_44._8_4_ = local_20;
                local_20 = (wchar_t *)0x0;
              }
              else {
                if (local_28 != 3) goto LAB_6811fe0d;
                local_44._0_2_ = 5;
                fVar7 = (float10)FUN_6812ee95(local_20);
                local_44._8_8_ = (undefined8)fVar7;
              }
              pOVar6 = local_18;
              if (-1 < iVar3) {
                FUN_68132710((uint *)&local_b0,0,0x10);
                VariantInit(&local_b0);
                local_8._0_1_ = 9;
                iVar3 = (**(code **)(*param_1 + 0x28))
                                  (param_1,bstrString,local_28,local_44._0_4_,local_44._4_4_,
                                   local_44._8_4_,local_44._12_4_,&local_b0);
                VariantClear(&local_b0);
                pOVar6 = local_18;
                if (-1 < iVar3) {
                  FUN_68132710((uint *)&local_60,0,0x10);
                  VariantInit((VARIANTARG *)&local_60.n2);
                  local_8._0_1_ = 10;
                  iVar3 = (**(code **)(*param_1 + 0x28))
                                    (param_1,bstrString,local_28,local_44._0_4_,local_44._4_4_,
                                     local_44._8_4_,local_44._12_4_,&local_60);
                  pOVar6 = local_18;
                  if ((-1 < iVar3) && (local_60.n2.vt == 9)) {
                    CComQIPtr<>(&local_2c,(undefined4 *)local_60._8_4_);
                    local_8._0_1_ = 0xb;
                    pOVar6 = local_18;
                    if (local_2c != (int *)0x0) {
                      (**(code **)(*local_2c + 0x38))(local_2c,local_34 != 0);
                      pOVar6 = local_18;
                      iVar3 = (**(code **)(*local_2c + 0x40))(local_2c,local_18);
                    }
                    local_8._0_1_ = 10;
                    if (local_2c != (int *)0x0) {
                      (**(code **)(*local_2c + 8))(local_2c);
                    }
                  }
                  VariantClear((VARIANTARG *)&local_60.n2);
                }
              }
            }
            if (local_20 != (BSTR)0x0) {
              SysFreeString(local_20);
            }
            VariantClear((VARIANTARG *)local_44);
          }
          iVar2 = local_50;
          if (iVar3 < 0) goto LAB_6811ff4a;
        }
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
      SysFreeString(pOVar6);
      SysFreeString(bstrString);
    }
    local_8 = 0xffffffff;
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))(local_24);
    }
    if (iVar2 != 0) {
      if (iVar2 == 1) {
        iVar2 = 0;
      }
      return iVar2;
    }
  } while( true );
}



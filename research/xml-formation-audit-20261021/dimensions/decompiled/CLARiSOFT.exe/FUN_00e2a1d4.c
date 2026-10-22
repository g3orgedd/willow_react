// Source: CLARiSOFT.exe @ 00e2a1d4; FUN_00e2a1d4

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

BSTR __fastcall FUN_00e2a1d4(int param_1)

{
  BSTR bstrString;
  int *piVar1;
  HRESULT HVar2;
  int iVar3;
  int *piVar4;
  BSTR bstrRight;
  VARIANTARG local_88;
  _union_2683 local_78;
  _union_2683 local_68;
  _union_2683 local_58;
  undefined4 local_48;
  int *local_44;
  BSTR local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  BSTR local_24;
  int local_20;
  BSTR local_1c;
  BSTR local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x78;
  local_8 = 0xe2a1e0;
  local_18 = (BSTR)0x0;
  if (*(int *)(param_1 + 0x19c) != 0) {
    local_3c = 0;
    local_34 = param_1;
    local_18 = (BSTR)(**(code **)(**(int **)(param_1 + 0x19c) + 0x1c))
                               (*(int **)(param_1 + 0x19c),&local_3c);
    if (-1 < (int)local_18) {
      bstrRight = (BSTR)0x0;
      local_24 = (BSTR)0x0;
      local_8 = 0;
      local_40 = (BSTR)0x0;
      local_14[0] = (int *)0x0;
      local_20 = 0;
      if (0 < local_3c) {
        local_48 = 0;
        do {
          piVar4 = (int *)0x0;
          local_44 = (int *)0x0;
          FUN_00e03b51((uint *)&local_88);
          local_20 = local_20 + 1;
          local_8._0_1_ = 5;
          (**(code **)(**(int **)(local_34 + 0x19c) + 0x24))
                    (*(int **)(local_34 + 0x19c),local_20,&local_88);
          CComQIPtr<>(&local_38,(undefined4 *)local_88.n1._8_4_);
          local_1c = (BSTR)0x0;
          local_8._0_1_ = 7;
          if (local_38 != (int *)0x0) {
            local_18 = (BSTR)0x0;
            local_8._0_1_ = 8;
            (**(code **)(*local_38 + 0x9c))(local_38,&local_18);
            (**(code **)(*local_38 + 0x4c))(local_38,&local_1c);
            HVar2 = VarBstrCmp(local_18,bstrRight,0x400,0);
            if ((HVar2 != 1) || (HVar2 = VarBstrCmp(local_1c,local_40,0x400,0), HVar2 != 1)) {
              SysFreeString(bstrRight);
              piVar1 = local_14[0];
              bstrRight = (BSTR)0x0;
              local_24 = (BSTR)0x0;
              if (local_14[0] != (int *)0x0) {
                local_14[0] = (int *)0x0;
                (**(code **)(*piVar1 + 8))(piVar1);
              }
              FUN_00e03b51((uint *)&local_68);
              local_8._0_1_ = 9;
              iVar3 = (**(code **)(**(int **)(local_34 + 0x1e0) + 0x3c))
                                (*(int **)(local_34 + 0x1e0),&local_68);
              if (((-1 < iVar3) && (local_68.n2.vt == 9)) &&
                 ((undefined4 *)local_68._8_4_ != (undefined4 *)0x0)) {
                CComQIPtr<>(&local_2c,(undefined4 *)local_68._8_4_);
                if (local_2c != (int *)0x0) {
                  FUN_00e03b51((uint *)&local_58);
                  local_8._0_1_ = 0xb;
                  iVar3 = (**(code **)(*local_2c + 0x30))(local_2c,local_18,&local_58);
                  if (((-1 < iVar3) && (local_58.n2.vt == 9)) &&
                     ((undefined4 *)local_58._8_4_ != (undefined4 *)0x0)) {
                    CComQIPtr<>(&local_28,(undefined4 *)local_58._8_4_);
                    local_8._0_1_ = 0xc;
                    if (local_28 != (int *)0x0) {
                      FUN_00e11de5(&local_44,(int *)&local_28);
                      FUN_00e01fd0(&local_24,(int *)&local_18);
                      piVar4 = local_44;
                      bstrRight = local_24;
                    }
                    local_8._0_1_ = 0xb;
                    if (local_28 != (int *)0x0) {
                      (**(code **)(*local_28 + 8))(local_28);
                    }
                  }
                  VariantClear((VARIANTARG *)&local_58.n2);
                }
                local_8._0_1_ = 9;
                if (local_2c != (int *)0x0) {
                  (**(code **)(*local_2c + 8))(local_2c);
                }
              }
              VariantClear((VARIANTARG *)&local_68.n2);
            }
            local_8._0_1_ = 7;
            SysFreeString(local_18);
          }
          if (local_14[0] == (int *)0x0) {
            if (piVar4 == (int *)0x0) {
              local_18 = (BSTR)0x80004005;
            }
            else {
              FUN_00e03b51((uint *)&local_78);
              local_8._0_1_ = 0xd;
              local_18 = (BSTR)(**(code **)(*piVar4 + 0x4c0))(piVar4,local_1c,&local_78);
              if (((-1 < (int)local_18) && (local_78.n2.vt == 9)) &&
                 ((undefined4 *)local_78._8_4_ != (undefined4 *)0x0)) {
                CComQIPtr<>(&local_30,(undefined4 *)local_78._8_4_);
                local_8._0_1_ = 0xe;
                if (local_30 == (int *)0x0) {
                  local_18 = (BSTR)0x80004005;
                }
                else {
                  FUN_00e11de5(local_14,(int *)&local_30);
                  FUN_00e01fd0(&local_40,(int *)&local_1c);
                }
                local_8._0_1_ = 0xd;
                if (local_30 != (int *)0x0) {
                  (**(code **)(*local_30 + 8))(local_30);
                }
              }
              local_8._0_1_ = 7;
              VariantClear((VARIANTARG *)&local_78.n2);
            }
            if (local_14[0] != (int *)0x0) goto LAB_00e2a490;
          }
          else {
LAB_00e2a490:
            local_18 = (BSTR)FUN_00e462d1((int *)(local_34 + 0x19c),(int *)local_14);
          }
          SysFreeString(local_1c);
          local_8._0_1_ = 5;
          if (local_38 != (int *)0x0) {
            (**(code **)(*local_38 + 8))(local_38);
          }
          VariantClear(&local_88);
          local_8 = CONCAT31(local_8._1_3_,3);
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 8))(piVar4);
          }
        } while (local_20 < local_3c);
      }
      bstrString = local_40;
      local_8 = CONCAT31(local_8._1_3_,1);
      if (local_14[0] != (int *)0x0) {
        (**(code **)(*local_14[0] + 8))(local_14[0]);
      }
      SysFreeString(bstrString);
      SysFreeString(bstrRight);
    }
  }
  return local_18;
}



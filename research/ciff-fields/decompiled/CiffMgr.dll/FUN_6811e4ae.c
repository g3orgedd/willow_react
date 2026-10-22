// Source: CiffMgr.dll @ 6811e4ae; FUN_6811e4ae

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int __thiscall FUN_6811e4ae(void *this,undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  _union_2683 local_48;
  _union_2683 local_38;
  wchar_t *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  wchar_t *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar1 = param_2;
  uStack_4 = 0x38;
  if (param_2 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    do {
      param_2 = (int *)0x0;
      local_8._0_1_ = 0;
      local_8._1_3_ = 0;
      iVar2 = (**(code **)(*(int *)*param_3 + 0x24))((int *)*param_3,&param_2);
      if ((iVar2 == 0) && (param_2 != (int *)0x0)) {
        local_28 = (wchar_t *)0x0;
        iVar2 = (**(code **)(*param_2 + 0x1c))(param_2,&local_28);
        if (-1 < iVar2) {
          iVar3 = FUN_6812e15e(0x6815fba0,local_28,0,3);
          if (iVar3 == 0x9b) {
            local_24 = (int *)0x0;
            local_8._0_1_ = 1;
            iVar2 = (**(code **)(*param_2 + 0x44))(param_2,&local_24);
            if ((iVar2 == 0) && (local_24 != (int *)0x0)) {
              local_18 = (BSTR)0x0;
              local_8._0_1_ = 2;
              iVar2 = (**(code **)(*local_24 + 0x1c))
                                (local_24,PTR_u_PrintHeadDigits_68160098,&local_18);
              if ((iVar2 == 0) && (local_18 != (BSTR)0x0)) {
                FUN_68132710((uint *)&local_48,0,0x10);
                VariantInit((VARIANTARG *)&local_48.n2);
                local_8._0_1_ = 3;
                (**(code **)(*(int *)local_18 + 0x20))(local_18,&local_48);
                if (local_48.n2.vt == 8) {
                  iVar2 = *piVar1;
                  iVar3 = FUN_6812f116((ushort *)local_48._8_4_);
                  (**(code **)(iVar2 + 0x20))(piVar1,iVar3);
                }
                VariantClear((VARIANTARG *)&local_48.n2);
              }
              local_8._0_1_ = 1;
              if (local_18 != (BSTR)0x0) {
                (**(code **)(*(int *)local_18 + 8))(local_18);
              }
            }
            local_20 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,4);
            iVar2 = (**(code **)(*param_2 + 0x90))(param_2,PTR_DAT_6815fea8,&local_20);
            if (iVar2 == 0) {
              if (local_20 != (int *)0x0) {
                iVar2 = FUN_68123fae(piVar1,&local_20);
                goto LAB_6811e743;
              }
            }
            else {
LAB_6811e743:
              if (iVar2 == 1) {
                iVar2 = 0;
              }
            }
            local_8._0_1_ = 1;
            if (local_20 != (int *)0x0) {
              (**(code **)(*local_20 + 8))(local_20);
            }
            local_8._0_1_ = 0;
            if (local_24 != (int *)0x0) {
              (**(code **)(*local_24 + 8))(local_24);
            }
          }
          else {
            if (iVar3 == 0x9d) {
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_2 + 0x68))(param_2,&local_18);
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                uVar4 = FUN_6812f589(local_18);
                iVar2 = (**(code **)(iVar2 + 0x28))(piVar1,uVar4);
              }
            }
            else {
              if (iVar3 != 0x9e) {
                if (iVar3 == 0xb1) {
                  FUN_68132710((uint *)&local_38,0,0x10);
                  VariantInit((VARIANTARG *)&local_38.n2);
                  local_8._0_1_ = 5;
                  iVar2 = (**(code **)(*piVar1 + 0x4c))(piVar1,&local_38);
                  if ((-1 < iVar2) && (local_38.n2.vt == 9)) {
                    CComQIPtr<>(&local_1c,(undefined4 *)local_38._8_4_);
                    if (local_1c == (int *)0x0) {
                      iVar2 = -0x7fffbffb;
                    }
                    else {
                      local_14[0] = (int *)0x0;
                      local_8 = CONCAT31(local_8._1_3_,7);
                      iVar2 = (**(code **)(*param_2 + 0x90))
                                        (param_2,PTR_u_ParamSet_6815ff00,local_14);
                      if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
                        iVar2 = FUN_6811f8ca(this,local_1c,local_14);
                      }
                      local_8._0_1_ = 6;
                      if (local_14[0] != (int *)0x0) {
                        (**(code **)(*local_14[0] + 8))(local_14[0]);
                      }
                    }
                    local_8._0_1_ = 5;
                    if (local_1c != (int *)0x0) {
                      (**(code **)(*local_1c + 8))(local_1c);
                    }
                  }
                  VariantClear((VARIANTARG *)&local_38.n2);
                }
                goto LAB_6811e76d;
              }
              local_18 = (wchar_t *)0x0;
              iVar2 = (**(code **)(*param_2 + 0x68))(param_2,&local_18);
              if (-1 < iVar2) {
                iVar2 = *piVar1;
                uVar4 = FUN_6812e988(local_18);
                iVar2 = (**(code **)(iVar2 + 0x30))(piVar1,uVar4);
              }
            }
            SysFreeString(local_18);
          }
        }
LAB_6811e76d:
        SysFreeString(local_28);
      }
      local_8 = 0xffffffff;
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    } while (iVar2 == 0);
    if (iVar2 == 1) {
      iVar2 = 0;
    }
  }
  return iVar2;
}



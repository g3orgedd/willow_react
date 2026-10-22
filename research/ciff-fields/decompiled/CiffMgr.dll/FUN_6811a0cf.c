// Source: CiffMgr.dll @ 6811a0cf; FUN_6811a0cf

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_6811a0cf(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _union_2683 local_58;
  _union_2683 local_48;
  _union_2683 local_38;
  int *local_28 [2];
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x6811a0db;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    iVar2 = -0x7fffbffb;
    CComQIPtr<>(local_28,param_1);
    if (local_28[0] != (int *)0x0) {
      local_1c = (int *)0x0;
      local_8 = 1;
      iVar2 = (**(code **)(*local_28[0] + 0x10c))(local_28[0],&local_1c);
      if ((-1 < iVar2) && (local_1c != (int *)0x0)) {
        do {
          local_20 = (int *)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*(int *)*param_2 + 0x24))((int *)*param_2,&local_20);
          if ((iVar2 == 0) && (local_20 != (int *)0x0)) {
            param_1 = (int *)0x0;
            local_8._0_1_ = 3;
            iVar3 = (**(code **)(*local_20 + 0x44))(local_20,&param_1);
            if (iVar3 < 0) {
LAB_6811a36d:
              iVar2 = iVar3;
            }
            else {
              if (param_1 != (int *)0x0) {
                local_14[0] = (int *)0x0;
                local_8._0_1_ = 4;
                iVar3 = (**(code **)(*local_1c + 0x30))(local_1c,local_14);
                if ((-1 < iVar3) && (local_14[0] != (int *)0x0)) {
                  local_18 = (int *)0x0;
                  local_8._0_1_ = 5;
                  iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,PTR_DAT_681600d8,&local_18);
                  if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
                    FUN_68132710((uint *)&local_38,0,0x10);
                    VariantInit((VARIANTARG *)&local_38.n2);
                    local_8._0_1_ = 6;
                    (**(code **)(*local_18 + 0x20))(local_18,&local_38);
                    piVar1 = local_14[0];
                    if (local_38.n2.vt == 8) {
                      iVar3 = *local_14[0];
                      iVar4 = FUN_6812f116((ushort *)local_38._8_4_);
                      (**(code **)(iVar3 + 0x20))(piVar1,iVar4);
                    }
                    VariantClear((VARIANTARG *)&local_38.n2);
                  }
                  local_8._0_1_ = 4;
                  if (local_18 != (int *)0x0) {
                    (**(code **)(*local_18 + 8))(local_18);
                  }
                  local_18 = (int *)0x0;
                  local_8._0_1_ = 7;
                  iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,PTR_u_Month_681600dc,&local_18);
                  if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
                    FUN_68132710((uint *)&local_48,0,0x10);
                    VariantInit((VARIANTARG *)&local_48.n2);
                    local_8._0_1_ = 8;
                    (**(code **)(*local_18 + 0x20))(local_18,&local_48);
                    piVar1 = local_14[0];
                    if (local_48.n2.vt == 8) {
                      iVar3 = *local_14[0];
                      iVar4 = FUN_6812f116((ushort *)local_48._8_4_);
                      (**(code **)(iVar3 + 0x28))(piVar1,iVar4);
                    }
                    VariantClear((VARIANTARG *)&local_48.n2);
                  }
                  local_8._0_1_ = 4;
                  if (local_18 != (int *)0x0) {
                    (**(code **)(*local_18 + 8))(local_18);
                  }
                  local_18 = (int *)0x0;
                  local_8._0_1_ = 9;
                  iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,PTR_u_Offset_681600e0,&local_18);
                  if ((iVar3 == 0) && (local_18 != (int *)0x0)) {
                    FUN_68132710((uint *)&local_58,0,0x10);
                    VariantInit((VARIANTARG *)&local_58.n2);
                    local_8._0_1_ = 10;
                    (**(code **)(*local_18 + 0x20))(local_18,&local_58);
                    piVar1 = local_14[0];
                    if (local_58.n2.vt == 8) {
                      iVar3 = *local_14[0];
                      iVar4 = FUN_6812f116((ushort *)local_58._8_4_);
                      (**(code **)(iVar3 + 0x30))(piVar1,iVar4);
                    }
                    VariantClear((VARIANTARG *)&local_58.n2);
                  }
                  local_8._0_1_ = 4;
                  if (local_18 != (int *)0x0) {
                    (**(code **)(*local_18 + 8))(local_18);
                  }
                  iVar3 = 0;
                }
                local_8._0_1_ = 3;
                if (local_14[0] != (int *)0x0) {
                  (**(code **)(*local_14[0] + 8))(local_14[0]);
                }
              }
              if (iVar3 < 0) goto LAB_6811a36d;
            }
            local_8._0_1_ = 2;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 8))(param_1);
            }
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          if (local_20 != (int *)0x0) {
            (**(code **)(*local_20 + 8))(local_20);
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
    }
    local_8 = 0xffffffff;
    if (local_28[0] != (int *)0x0) {
      (**(code **)(*local_28[0] + 8))(local_28[0]);
    }
  }
  return iVar2;
}



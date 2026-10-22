// Source: CiffMgr.dll @ 68127254; FUN_68127254

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int FUN_68127254(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  _union_2683 local_34;
  undefined1 local_24 [16];
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar1 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  if ((-1 < iVar1) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)local_24,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_24)->n2);
    local_24._0_2_ = 8;
    local_24._8_4_ = (BSTR)0x0;
    local_8._0_1_ = 1;
    iVar1 = (**(code **)(*(int *)*param_2 + 0x1c))
                      ((int *)*param_2,&(((_union_2683 *)local_24)->n2).n3);
    if (-1 < iVar1) {
      if ((BSTR)local_24._8_4_ != (BSTR)0x0) {
        iVar1 = FUN_68134501((ushort *)local_24._8_4_,(ushort *)L"Table containing Index Fields");
        if (iVar1 == 0) {
          local_34.n2.vt = 0;
          FUN_681242f0(&local_34,L"Table containing Index Fields");
          local_8._0_1_ = 2;
          FUN_68104449((_union_2683 *)local_24,(VARIANTARG *)&local_34.n2);
          local_8._0_1_ = 1;
          VariantClear((VARIANTARG *)&local_34.n2);
        }
      }
      iVar1 = FUN_681021f5(param_1,local_14,PTR_u_DataSourceName_681600bc,(undefined4 *)local_24);
      if (-1 < iVar1) {
        SysFreeString((BSTR)local_24._8_4_);
        iVar1 = (**(code **)(*(int *)*param_2 + 0x24))
                          ((int *)*param_2,&(((_union_2683 *)local_24)->n2).n3);
        if (-1 < iVar1) {
          iVar1 = FUN_681021f5(param_1,local_14,PTR_u_DataSourceTable_681600c0,
                               (undefined4 *)local_24);
          if (-1 < iVar1) {
            SysFreeString((BSTR)local_24._8_4_);
            iVar1 = (**(code **)(*(int *)*param_2 + 0x2c))
                              ((int *)*param_2,&(((_union_2683 *)local_24)->n2).n3);
            if (-1 < iVar1) {
              iVar1 = FUN_681021f5(param_1,local_14,PTR_u_DataSourceIndex_681600c4,
                                   (undefined4 *)local_24);
              if (-1 < iVar1) {
                SysFreeString((BSTR)local_24._8_4_);
                iVar1 = (**(code **)(*(int *)*param_2 + 0x34))
                                  ((int *)*param_2,&(((_union_2683 *)local_24)->n2).n3);
                if (-1 < iVar1) {
                  param_2 = (int *)0x0;
                  local_8 = CONCAT31(local_8._1_3_,3);
                  iVar1 = (**(code **)(*(int *)*param_1 + 0xcc))
                                    ((int *)*param_1,local_24._8_4_,&param_2);
                  if ((-1 < iVar1) && (param_2 != (int *)0x0)) {
                    iVar1 = (**(code **)(*(int *)*param_3 + 0x54))((int *)*param_3,param_2,0);
                  }
                  local_8._0_1_ = 1;
                  if (param_2 != (int *)0x0) {
                    (**(code **)(*param_2 + 8))(param_2);
                  }
                }
              }
            }
          }
        }
      }
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_24)->n2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar1;
}



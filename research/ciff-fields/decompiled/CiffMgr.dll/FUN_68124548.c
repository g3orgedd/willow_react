// Source: CiffMgr.dll @ 68124548; FUN_68124548

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_68124548(int *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  OLECHAR *pOVar3;
  int iVar4;
  _union_2683 local_48;
  _union_2683 local_38;
  void *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_2 + 0x110))((int *)*param_2,local_14);
  if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
    local_18 = 0;
    iVar2 = (**(code **)(*local_14[0] + 0x24))(local_14[0],&local_18);
    piVar1 = param_1;
    if ((-1 < iVar2) && (0 < local_18)) {
      local_1c = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_68124179(param_1,param_3,PTR_u_AvoidanceDates_6815ff80,(int *)&local_1c);
      if (((-1 < iVar2) && (local_1c != (int *)0x0)) && (iVar4 = 1, 0 < local_18)) {
        do {
          if (iVar2 < 0) break;
          param_3 = (int *)0x0;
          local_8._0_1_ = 2;
          iVar2 = (**(code **)(*local_14[0] + 0x20))(local_14[0],iVar4,&param_3);
          if ((-1 < iVar2) && (param_3 != (int *)0x0)) {
            param_1 = (int *)0x0;
            local_8._0_1_ = 3;
            iVar2 = FUN_68124179(piVar1,&local_1c,PTR_u_AvoidanceDate_6815ff84,(int *)&param_1);
            if ((-1 < iVar2) && (param_1 != (int *)0x0)) {
              param_2 = (int *)0x0;
              local_8._0_1_ = 4;
              iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&param_2);
              if ((-1 < iVar2) && (param_2 != (int *)0x0)) {
                local_20 = 0;
                iVar2 = (**(code **)(*param_3 + 0x1c))(param_3,&local_20);
                if (-1 < iVar2) {
                  if (local_20 != 0x19) {
                    FUN_68132710((uint *)&local_38,0,0x10);
                    VariantInit((VARIANTARG *)&local_38.n2);
                    local_8._0_1_ = 5;
                    local_38.n2.vt = 8;
                    pOVar3 = FUN_6812f174(local_28,local_20);
                    local_38._8_4_ = SysAllocString(pOVar3);
                    iVar2 = FUN_681021f5(piVar1,&param_2,PTR_DAT_681600d8,(undefined4 *)&local_38);
                    local_8._0_1_ = 4;
                    VariantClear((VARIANTARG *)&local_38.n2);
                  }
                  if (-1 < iVar2) {
                    local_24 = 0;
                    iVar2 = (**(code **)(*param_3 + 0x24))(param_3,&local_24);
                    if ((-1 < iVar2) && (local_24 != 0xc)) {
                      FUN_68132710((uint *)&local_48,0,0x10);
                      VariantInit((VARIANTARG *)&local_48.n2);
                      local_8._0_1_ = 6;
                      local_48.n2.vt = 8;
                      pOVar3 = FUN_6812f174(local_28,local_24);
                      local_48._8_4_ = SysAllocString(pOVar3);
                      iVar2 = FUN_681021f5(piVar1,&param_2,PTR_u_Month_681600dc,
                                           (undefined4 *)&local_48);
                      VariantClear((VARIANTARG *)&local_48.n2);
                    }
                  }
                }
              }
              local_8._0_1_ = 3;
              if (param_2 != (int *)0x0) {
                (**(code **)(*param_2 + 8))(param_2);
              }
            }
            local_8._0_1_ = 2;
            if (param_1 != (int *)0x0) {
              (**(code **)(*param_1 + 8))(param_1);
            }
          }
          local_8 = CONCAT31(local_8._1_3_,1);
          if (param_3 != (int *)0x0) {
            (**(code **)(*param_3 + 8))(param_3);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 <= local_18);
      }
      local_8 = local_8 & 0xffffff00;
      if (local_1c != (int *)0x0) {
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar2;
}



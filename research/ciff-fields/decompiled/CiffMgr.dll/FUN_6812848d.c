// Source: CiffMgr.dll @ 6812848d; FUN_6812848d

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

HRESULT FUN_6812848d(SAFEARRAY *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  SAFEARRAY *pSVar1;
  undefined4 *puVar2;
  HRESULT HVar3;
  OLECHAR *pOVar4;
  int iVar5;
  int *piVar6;
  undefined1 local_30 [20];
  int local_1c;
  int *local_18;
  SAFEARRAY *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  piVar6 = param_3;
  uStack_4 = 0x20;
  local_14[0] = (SAFEARRAY *)0x0;
  local_18 = (int *)0x0;
  local_8 = 0;
  HVar3 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,&local_18);
  pSVar1 = param_1;
  if ((-1 < HVar3) && (local_18 != (int *)0x0)) {
    FUN_68132710((uint *)local_30,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_30)->n2);
    puVar2 = param_2;
    local_30._8_4_ = (BSTR)0x0;
    local_30._0_2_ = 8;
    local_8._0_1_ = 1;
    HVar3 = (**(code **)(*(int *)*param_2 + 0x1c))
                      ((int *)*param_2,&(((_union_2683 *)local_30)->n2).n3);
    if ((-1 < HVar3) &&
       (HVar3 = FUN_681021f5((undefined4 *)pSVar1,&local_18,PTR_u_Name_681600ac,
                             (undefined4 *)local_30), -1 < HVar3)) {
      SysFreeString((BSTR)local_30._8_4_);
      local_30._8_4_ = (BSTR)0x0;
      local_30._0_2_ = 3;
      HVar3 = (**(code **)(*(int *)*puVar2 + 0x2c))
                        ((int *)*puVar2,&(((_union_2683 *)local_30)->n2).n3);
      if (((-1 < HVar3) &&
          (HVar3 = FUN_681021f5((undefined4 *)pSVar1,&local_18,PTR_u_Size_681600b0,
                                (undefined4 *)local_30), -1 < HVar3)) &&
         (HVar3 = (**(code **)(*(int *)*puVar2 + 0x24))((int *)*puVar2,&param_1), -1 < HVar3)) {
        VariantClear((VARIANTARG *)&((_union_2683 *)local_30)->n2);
        local_30._0_2_ = 8;
        pOVar4 = (OLECHAR *)FUN_6812eca8((int)param_1);
        local_30._8_4_ = SysAllocString(pOVar4);
        HVar3 = FUN_681021f5((undefined4 *)pSVar1,&local_18,PTR_u_Type_681600b4,
                             (undefined4 *)local_30);
        if ((-1 < HVar3) &&
           (HVar3 = (**(code **)(*(int *)*puVar2 + 0x34))((int *)*puVar2,&local_1c), -1 < HVar3)) {
          iVar5 = (**(code **)(*(int *)*puVar2 + 0x3c))((int *)*puVar2,local_14);
          if ((-1 < iVar5) &&
             (((local_14[0] != (SAFEARRAY *)0x0 && (local_1c != 0)) && (local_1c == 1)))) {
            FUN_68130739(&param_2);
            param_1 = (SAFEARRAY *)0x0;
            local_8 = CONCAT31(local_8._1_3_,2);
            HVar3 = FUN_681308c4(local_14[0],&param_1);
            if (HVar3 == 0) {
              SafeArrayDestroy(local_14[0]);
              local_14[0] = param_1;
            }
            else {
              local_1c = 0;
            }
            local_8._0_1_ = 1;
            FUN_68130742(&param_2);
          }
          VariantClear((VARIANTARG *)&((_union_2683 *)local_30)->n2);
          local_30._0_2_ = 8;
          pOVar4 = (OLECHAR *)FUN_6812ec4e(local_1c);
          local_30._8_4_ = SysAllocString(pOVar4);
          HVar3 = FUN_681021f5((undefined4 *)pSVar1,&local_18,PTR_u_CompType_681600b8,
                               (undefined4 *)local_30);
        }
      }
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_30)->n2);
    piVar6 = param_3;
  }
  local_8 = 0xffffffff;
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  if (-1 < HVar3) {
    if (local_14[0] == (SAFEARRAY *)0x0) {
      return HVar3;
    }
    param_1 = (SAFEARRAY *)0x0;
    local_8 = 3;
    FUN_68114625(&param_2,param_4);
    HVar3 = FUN_6811476e(local_14[0],&param_1);
    if (-1 < HVar3) {
      param_3 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,4);
      HVar3 = (**(code **)(**(int **)pSVar1 + 0xc4))(*(int **)pSVar1,param_1,&param_3);
      if ((-1 < HVar3) && (param_3 != (int *)0x0)) {
        HVar3 = (**(code **)(*(int *)*piVar6 + 0x54))((int *)*piVar6,param_3,0);
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if (param_3 != (int *)0x0) {
        (**(code **)(*param_3 + 8))(param_3);
      }
    }
    SysFreeString((BSTR)param_1);
  }
  if (local_14[0] != (SAFEARRAY *)0x0) {
    SafeArrayDestroy(local_14[0]);
  }
  return HVar3;
}



// Source: CiffMgr.dll @ 681261df; FUN_681261df

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_681261df(BSTR param_1,undefined4 *param_2,undefined4 *param_3)

{
  BSTR pOVar1;
  BSTR pOVar2;
  uint uVar3;
  undefined *puVar4;
  short *psVar5;
  UINT UVar6;
  _union_2683 local_40;
  int local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  int *local_18;
  void *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x681261eb;
  uVar3 = (**(code **)(*(int *)*param_2 + 0xfc))((int *)*param_2,&local_2c);
  pOVar1 = param_1;
  if (-1 < (int)uVar3) {
    if (local_2c != 1) {
      puVar4 = FUN_6812e9d1(local_2c);
      uVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_Rollover_6815fd88,puVar4);
    }
    if ((-1 < (int)uVar3) &&
       (uVar3 = (**(code **)(*(int *)*param_2 + 0x104))((int *)*param_2,&local_20), -1 < (int)uVar3)
       ) {
      if (local_20 != 1) {
        psVar5 = FUN_6812f174(local_14,local_20);
        uVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_PrnPerCnt_6815fd8c,psVar5);
      }
      if ((-1 < (int)uVar3) &&
         (uVar3 = (**(code **)(*(int *)*param_2 + 0x10c))((int *)*param_2,&local_20),
         -1 < (int)uVar3)) {
        if (local_20 != 0) {
          puVar4 = FUN_6812f851(local_20);
          uVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_ResetOnSel_6815fc7c,puVar4);
        }
        if (-1 < (int)uVar3) {
          param_1 = (BSTR)0x0;
          local_8 = 0;
          uVar3 = (**(code **)(*(int *)*param_2 + 0x114))((int *)*param_2,&param_1);
          if ((-1 < (int)uVar3) && (UVar6 = SysStringLen(param_1), UVar6 != 0)) {
            uVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_ParentCounter_6815fd90,param_1);
          }
          SysFreeString(param_1);
        }
      }
    }
  }
  CComQIPtr<>(&local_28,(undefined4 *)*param_2);
  local_8 = 1;
  if (((local_28 != (int *)0x0) && (-1 < (int)uVar3)) &&
     (uVar3 = (**(code **)(*local_28 + 0x170))(local_28,&param_1), -1 < (int)uVar3)) {
    if (param_1 != (BSTR)0x1) {
      puVar4 = FUN_6812e9d1((int)param_1);
      uVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_RolloverError_6815ff38,puVar4);
    }
    if (((-1 < (int)uVar3) &&
        (uVar3 = (**(code **)(*local_28 + 0x178))(local_28,&local_24), -1 < (int)uVar3)) &&
       (local_24 != 0)) {
      puVar4 = FUN_6812eb1f(local_24);
      uVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_PromptWith_6815ff3c,puVar4);
    }
  }
  CComQIPtr<>(&local_18,(undefined4 *)*param_2);
  local_8._0_1_ = 2;
  if (local_18 != (int *)0x0) {
    if (((int)uVar3 < 0) ||
       (uVar3 = (**(code **)(*local_18 + 0x180))(local_18,&param_1), (int)uVar3 < 0))
    goto LAB_68126537;
    if (param_1 != (BSTR)0x0) {
      puVar4 = FUN_6812eb79((int)param_1);
      uVar3 = FUN_6810248f((int *)pOVar1,param_3,PTR_u_ResetSource_6815ffa4,puVar4);
    }
  }
  if (-1 < (int)uVar3) {
    local_24 = 0;
    uVar3 = (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,&local_24);
    param_1 = (BSTR)0x0;
    local_20 = 0;
    if (0 < local_24) {
      do {
        FUN_68132710((uint *)&local_40,0,0x10);
        VariantInit((VARIANTARG *)&local_40.n2);
        local_8._0_1_ = 4;
        uVar3 = (**(code **)(*(int *)*param_2 + 0x138))((int *)*param_2,local_20,&local_40);
        if ((-1 < (int)uVar3) && (local_40.n2.vt == 9)) {
          uVar3 = (*(code *)**(undefined4 **)local_40._8_4_)(local_40._8_4_,&DAT_681478f8,&param_1);
          if (-1 < (int)uVar3) {
            if (param_1 == (BSTR)0x0) goto LAB_68126509;
            uVar3 = (**(code **)(*(int *)param_1 + 0x7c))(param_1,&local_30);
            if ((-1 < (int)uVar3) && (local_30 != 0)) {
              local_1c = (int *)0x0;
              local_8 = CONCAT31(local_8._1_3_,5);
              uVar3 = FUN_68124179((undefined4 *)pOVar1,param_3,PTR_u_SubCnt_6815fd94,
                                   (int *)&local_1c);
              if (-1 < (int)uVar3) {
                uVar3 = FUN_6812bb40((int *)pOVar1,(BSTR)&param_1,&local_1c);
              }
              local_8._0_1_ = 4;
              if (local_1c != (int *)0x0) {
                (**(code **)(*local_1c + 8))(local_1c);
              }
            }
          }
          pOVar2 = param_1;
          if (param_1 != (BSTR)0x0) {
            param_1 = (BSTR)0x0;
            (**(code **)(*(int *)pOVar2 + 8))(pOVar2);
          }
        }
LAB_68126509:
        VariantClear((VARIANTARG *)&local_40.n2);
        local_20 = local_20 + 1;
      } while (local_20 < local_24);
    }
    local_8._0_1_ = 2;
    if (param_1 != (BSTR)0x0) {
      (**(code **)(*(int *)param_1 + 8))(param_1);
    }
  }
LAB_68126537:
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  local_8 = 0xffffffff;
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  return uVar3;
}



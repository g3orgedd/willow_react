// Source: CiffMgr.dll @ 6812a2da; FUN_6812a2da

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int FUN_6812a2da(BSTR param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  BSTR pOVar3;
  int iVar4;
  undefined1 local_24 [16];
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar4 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  piVar2 = param_2;
  pOVar3 = param_1;
  if ((-1 < iVar4) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)local_24,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_24)->n2);
    local_24._8_4_ = 0;
    local_24._0_2_ = 8;
    piVar1 = (int *)*piVar2;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar4 = (**(code **)(*piVar1 + 0x1c))(piVar1,&(((_union_2683 *)local_24)->n2).n3);
    if (-1 < iVar4) {
      iVar4 = FUN_681021f5((undefined4 *)pOVar3,local_14,PTR_u_SubIMageRef_6816009c,
                           (undefined4 *)local_24);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_24)->n2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  if (-1 < iVar4) {
    param_1 = (BSTR)0x0;
    piVar2 = (int *)*piVar2;
    local_8 = 2;
    iVar4 = (**(code **)(*piVar2 + 0x24))(piVar2,&param_1);
    if (-1 < iVar4) {
      param_2 = (int *)0x0;
      piVar2 = *(int **)pOVar3;
      local_8 = CONCAT31(local_8._1_3_,3);
      iVar4 = (**(code **)(*piVar2 + 0xc4))(piVar2,param_1,&param_2);
      if ((-1 < iVar4) && (param_2 != (int *)0x0)) {
        iVar4 = (**(code **)(*(int *)*param_3 + 0x54))((int *)*param_3,param_2,0);
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      if (param_2 != (int *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
    }
    SysFreeString(param_1);
  }
  return iVar4;
}



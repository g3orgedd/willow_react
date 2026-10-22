// Source: CiffMgr.dll @ 6812a724; FUN_6812a724

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int FUN_6812a724(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 local_24 [16];
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar1 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  if ((-1 < iVar1) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)local_24,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_24)->n2);
    local_24._0_2_ = 8;
    local_24._8_4_ = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar1 = (**(code **)(*(int *)*param_2 + 0xb4))
                      ((int *)*param_2,&(((_union_2683 *)local_24)->n2).n3);
    if (-1 < iVar1) {
      iVar1 = FUN_681021f5(param_1,local_14,PTR_u_SrcOffset_68160060,(undefined4 *)local_24);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_24)->n2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  return iVar1;
}



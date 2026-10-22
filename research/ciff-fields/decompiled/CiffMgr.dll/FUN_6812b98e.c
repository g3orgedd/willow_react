// Source: CiffMgr.dll @ 6812b98e; FUN_6812b98e

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Type propagation algorithm not settling */

int FUN_6812b98e(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  short *psVar3;
  undefined1 local_2c [16];
  int *local_1c;
  void *local_18;
  int *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_14[0] = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)*param_3 + 0x44))((int *)*param_3,local_14);
  puVar1 = param_2;
  if ((-1 < iVar2) && (local_14[0] != (int *)0x0)) {
    FUN_68132710((uint *)local_2c,0,0x10);
    VariantInit((VARIANTARG *)&((_union_2683 *)local_2c)->n2);
    local_2c._8_4_ = 0;
    local_2c._0_2_ = 8;
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar2 = (**(code **)(*(int *)*puVar1 + 0xe4))
                      ((int *)*puVar1,&(((_union_2683 *)local_2c)->n2).n3);
    if (-1 < iVar2) {
      iVar2 = FUN_681021f5(param_1,local_14,PTR_u_SrcFieldName_6816005c,(undefined4 *)local_2c);
    }
    VariantClear((VARIANTARG *)&((_union_2683 *)local_2c)->n2);
  }
  local_8 = 0xffffffff;
  if (local_14[0] != (int *)0x0) {
    (**(code **)(*local_14[0] + 8))(local_14[0]);
  }
  if ((-1 < iVar2) &&
     (iVar2 = (**(code **)(*(int *)*puVar1 + 0xec))((int *)*puVar1,local_14), -1 < iVar2)) {
    if (local_14[0] != (int *)0x0) {
      psVar3 = FUN_6812f174(local_18,(int)local_14[0]);
      iVar2 = FUN_6810248f(param_1,param_3,PTR_u_StartChar_6815fd68,psVar3);
    }
    if ((-1 < iVar2) &&
       (iVar2 = (**(code **)(*(int *)*puVar1 + 0xf4))((int *)*puVar1,local_14), -1 < iVar2)) {
      if (local_14[0] != (int *)0x0) {
        psVar3 = FUN_6812f174(local_18,(int)local_14[0]);
        iVar2 = FUN_6810248f(param_1,param_3,PTR_u_NoOfChars_6815fd6c,psVar3);
      }
      if (-1 < iVar2) {
        param_2 = (undefined4 *)0x0;
        CComQIPtr<>(&local_1c,(undefined4 *)*puVar1);
        local_8 = 2;
        if (((local_1c != (int *)0x0) &&
            (iVar2 = (**(code **)(*local_1c + 400))(local_1c,&param_2), -1 < iVar2)) &&
           (param_2 != (undefined4 *)0x0)) {
          psVar3 = FUN_6812f174(local_18,(int)param_2);
          iVar2 = FUN_6810248f(param_1,param_3,PTR_u_SelectMode_6815fff0,psVar3);
        }
        local_8 = 0xffffffff;
        if (local_1c != (int *)0x0) {
          (**(code **)(*local_1c + 8))(local_1c);
        }
      }
    }
  }
  return iVar2;
}


